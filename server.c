#include <asm-generic/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int serve_tcp(int port,int count) {
	int result = socket(AF_INET,SOCK_STREAM,0);
	int opt = 1;
	setsockopt(result,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT ,&opt,sizeof(opt));
	if (result < 0) {
		perror("serve_tcp:socket creation failed");
		return result;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(result,(struct sockaddr*)&addr,sizeof(struct sockaddr)) < 0) {
		perror("serve_tcp:bind failure");
		return -1;
	} 
	if (listen(result,count) < 0) {
		perror("serve_tcp:listen failure");
		return -1;
	}
	return result;
}
