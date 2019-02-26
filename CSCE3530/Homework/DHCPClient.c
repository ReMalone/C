#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

//#define SERVER "127.0.0.1" //IP address of server
#define SERVER "129.120.151.94"

struct _ipaddress {
	char ip[16]; //xxx.xxx.xxx.xxx
	int free; //0 free 1 occupied

};
struct _dhcpmessage {
	char ip[16]; //xxx.xxx.xxx.xxx
	int transid;
	int lifetime;
	int requesttype; //0 discovery 1 offer 2 request 3 ack
};

int main(int argc, char **argv) {
	int sockfd; /* socket */
	int portno;
	int serverlen; /* byte size of server address */
	struct sockaddr_in serveraddr; /* server's addr */

	int n = sizeof(struct _dhcpmessage); /* message byte size */
	char* buf = malloc(n);
	if (buf == NULL) {
		printf("Memory error\r\n'");
		exit(EXIT_FAILURE);
	}

	/*
	 * check command line arguments
	 */
	if (argc != 2) {
		printf("Usage: %s <port>\r\n", argv[0]);
		exit(1);
	}
	portno = atoi(argv[1]);

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		printf("ERROR opening socket\r\n");
		return EXIT_FAILURE;
	}
	struct timeval tv;
	tv.tv_sec = 30; /* 30 Secs timeout */
	tv.tv_usec = 0;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv,sizeof(struct timeval));

	memset((char *) &serveraddr, 0, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(portno);

	if (inet_aton(SERVER, &serveraddr.sin_addr) == 0) {
		printf("inet_aton() failed\n");
		return EXIT_FAILURE;
	}
	struct _dhcpmessage* recvmessage;
	struct _dhcpmessage sendmessage;
	srand(time(NULL));
	serverlen = sizeof(serveraddr);
	while(1)
	{

		//discovery
		printf("DHCP Discovery\r\n");
		printf("---------------------------------\r\n");
		memset((void*)(sendmessage.ip),0,16);
		//send 0.0.0.0 to server;
		sendmessage.ip[0]='0';
		sendmessage.ip[1]='.';
		sendmessage.ip[2]='0';
		sendmessage.ip[3]='.';
		sendmessage.ip[4]='0';
		sendmessage.ip[5]='.';
		sendmessage.ip[6]='0';
		sendmessage.lifetime=-1;
		sendmessage.requesttype=0;
		sendmessage.transid=rand()+1;
		printf("yiaddr:%s\r\n",sendmessage.ip);
		printf("Transaction ID:%i\r\n",sendmessage.transid);
		memcpy((void*)buf,(void*)&sendmessage,n);
		int sent = sendto(sockfd, buf, n, 0, (struct sockaddr *) &serveraddr,serverlen);
		if (sent<0)
		{
			printf("ERROR on sendto\r\n");
		}
		memset((void*) buf, 0, n); //int 0 for server_addr
		int read = recvfrom(sockfd, buf, n, 0, (struct sockaddr *) &serveraddr,(socklen_t*)&serverlen);
		if (read < 0)
		{
			printf("ERROR on recvfrom\r\n");
			continue;
		}
		recvmessage=(struct _dhcpmessage*)buf;

		if(recvmessage->requesttype==1)//Offer
		{

			printf("DHCP Offer\r\n");
			printf("---------------------------------\r\n");
			printf("Life time:%i\r\n",recvmessage->lifetime);
			printf("yiaddr:%s\r\n",recvmessage->ip);
			printf("Transaction ID:%i\r\n",recvmessage->transid);



			sendmessage.lifetime=3600;
			sendmessage.transid=recvmessage->transid+1;
			sendmessage.requesttype=2;//request
			memcpy((void*)(sendmessage.ip),(void*)(recvmessage->ip),16);
			printf("DHCP Request\r\n");
			printf("---------------------------------\r\n");
			printf("Life time:%i\r\n",sendmessage.lifetime);
			printf("yiaddr:%s\r\n",sendmessage.ip);
			printf("Transaction ID:%i\r\n",sendmessage.transid);
			memset((void*) buf, 0, n);
			memcpy((void*)buf,(void*)&sendmessage,n);
			sent = sendto(sockfd, buf, n, 0, (struct sockaddr *) &serveraddr,serverlen);
			if (sent<0)
			{
				printf("ERROR on sendto\r\n");
				continue;
			}
			memset((void*) buf, 0, n);
			read = recvfrom(sockfd, buf, n, 0, (struct sockaddr *) &serveraddr,(socklen_t*)&serverlen);
			if (read < 0)
			{
				printf("ERROR on recvfrom\r\n");
				continue;
			}
			recvmessage=(struct _dhcpmessage*)buf;
			if(recvmessage->requesttype==3)//ack
			{
				printf("DHCP ACK\r\n");
				printf("---------------------------------\r\n");
				printf("Life time:%i\r\n",recvmessage->lifetime);
				printf("yiaddr:%s\r\n",recvmessage->ip);
				printf("Transaction ID:%i\r\n",recvmessage->transid);
				break;
			}
			else
				continue;
		}
		else
			continue;


	}
	free(buf);
	return EXIT_SUCCESS;
}
