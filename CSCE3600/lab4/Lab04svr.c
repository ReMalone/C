#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main()
{
	int listenfd = 0, connfd = 0, cli_size;

	struct sockaddr_in serv_addr, cli_addr;

	char sendBuff[1025];  
 
	if ((listenfd = socket(listenfd, connfd, 0 )) == -1) //question mark Realized the error of my parameters near the end
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	serv_addr.sin_port = htons(5000);    

	if (bind(listenfd, struct sockaddr_in* serv_addr ) == -1) //question mark
	
		printf("bind error\n");
		exit(EXIT_FAILURE);
	}


	if (listen(connfd, cli_size ) == -1)  //question mark
	{
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		cli_size = sizeof(cli_addr);
		if ((connfd = accept( listenfd, struct sockaddr_in* cli_addr  )) == -1)  //question mark
		{
			printf("accept error\n");
			exit(EXIT_FAILURE);
		}

		strcpy(sendBuff, "Server Message: SUCCESS\n");
		write(connfd, sendBuff, strlen(sendBuff));

		close(connfd);    
		sleep(1);
	} 
 
	return 0;
}
