#include "head_files.h"
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>

using namespace std;

void process_pipe() {

	int fd[2];
	pipe(fd);

	pid_t pid = fork();

	if (pid == 0) {
		close(fd[1]);
		char buffer[100];
		ssize_t len = read(fd[0], buffer, sizeof(buffer) - 1); // 最多读 99 个字符，留一个位置给 \0
		if (len > 0) {
			buffer[len] = '\0';  // ⚠️ 这行是救命稻草：手动在末尾贴上结束符
		}
		cout << "子进程收到消息：" << buffer << endl;
		cout << "表达式计算结果为：" << caculate(buffer) << endl;
		close(fd[0]);
	}
	else {
		close(fd[0]);
		string expression;
		cout << "父进程正在输入数学表达式（例如：3+5）：";
		getline(cin, expression);
		write(fd[1], expression.c_str(), expression.size() + 1);
		close(fd[1]);
		wait(NULL);
		cout << "父进程发送完毕，等待子进程计算结果..." << endl;
		cout << "子进程计算完毕，父进程退出！" << endl;
	}
}