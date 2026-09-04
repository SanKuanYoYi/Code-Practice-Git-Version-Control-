#include "head_files.h"

void socket() {

	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);

	bind(server_fd, (sockaddr*)&address, sizeof(address));

	listen(server_fd, 3);
	cout << "Server is listening on port 8080..." << endl;

	int addrlen = sizeof(address);

	while (1) {
		int client_socket = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);
		cout << "Client connected." << endl;

		pid_t pid = fork();
		cout << "The fork was successful, the pid is: " << pid << endl;
		if (pid == 0) {
			sleep(1);
			cout << "I am the child process, my pid is: " << getpid() << endl;
			close(server_fd);  
			char* response = "HTTP/1.1 200 OK\nContent-Length: 20\n\nMulti-process concurrent server £¡";
			write(client_socket, response, strlen(response));
			close(client_socket);
			cout << "Child process finished." << endl;
			return;
		}
		cout << "I am the parent process, my pid is" << getpid() << endl;
		close(client_socket);
		waitpid(-1, NULL, WNOHANG); 
	}

	close(server_fd);

	return;
}