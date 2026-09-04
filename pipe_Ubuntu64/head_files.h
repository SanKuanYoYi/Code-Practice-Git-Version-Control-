#ifndef HEAD_FILES_H   // 防止重复包含
#define HEAD_FILES_H

#include <string>
using namespace std;

int caculate(const string& expr);  // 声明计算函数
void process_pipe();               // 声明管道通信入口

#endif