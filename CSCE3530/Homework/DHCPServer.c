#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
struct _ipaddress {
	char ip[16]; //xxx.xxx.xxx.xxx
	int free;//0 free 1 occupied

};
struct _dhcpmessage
{
	char ip[16]; //xxx.xxx.xxx.xxx
	int transid;
	int lifetime;
	int requesttype;//0 discovery 1 offer 2 request 3 ack
};
int main(int argc, char **argv) {
	struct _ipaddress iplist[255]; //maximum number of ip in the ip list is 255
	int r, line = 0;

	FILE *fp;
	fp = fopen("IPaddress.txt", "r");

	if (fp == NULL) {
		printf("Error opening the ipaddress list\r\n'");
		exit(EXIT_FAILURE);
	}
	else
	{
		memset((void*)(iplist[line].ip),0,16);
		r = fscanf(fp, "%s\n", iplist[line].ip);//ip in IPaddress.txt must have correct format xxx.xxx.xxx.xxx and length<=15

		while (r != EOF) {
			line++;
			r = fscanf(fp, "%s\n", iplist[line].ip);
		}
		if(line==0)//file has to contain IPs
		{
			printf("Error opening the ipaddress list\r\n'");
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	int sockfd; /* socket */
	int portno; /* port to listen on */
	int clientlen; /* byte size of client's address */
	struct sockaddr_in serveraddr; /* server's addr */
	struct sockaddr_in clientaddr; /* client addr */
	int n=sizeof(struct _dhcpmessage); /* message byte size */
	char* buf=malloc(n);
	if(buf==NULL)
	{
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

	/*
	 * socket: create the parent socket
	 */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		printf("ERROR opening socket\r\n");
		return EXIT_FAILURE;
	}

	struct timeval tv;
	tv.tv_sec = 30; /* 30 Secs timeout */
	tv.tv_usec = 0;
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*) &tv,sizeof(struct timeval));

	memset((void*) &serveraddr, 0, sizeof(serveraddr)); //int 0 for server_addr
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short) portno);

	/*
	 * bind: associate the parent socket with a port
	 */
	if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
	{
		printf("ERROR on binding socket\r\n");
		return EXIT_FAILURE;
	}

	/*
	 * main loop: wait for a datagram, then echo it
	 */
	clientlen = sizeof(clientaddr);
	struct _dhcpmessage* recvmessage=NULL;
	struct _dhcpmessage sendmessage;
	while (1) {

		/*
		 * recvfrom: receive a UDP datagram from a client
		 */
		memset((void*) buf, 0, n);
		int read = recvfrom(sockfd, buf, n, 0, (struct sockaddr *) &clientaddr,(socklen_t*)&clientlen);
		//if (read < 0)
		//{
		//	printf("ERROR on recvfrom\r\n");
		//}
		recvmessage=(struct _dhcpmessage*)buf;

		if(recvmessage->requesttype==0)//discover
		{
			memset((void*)(sendmessage.ip),0,16);
			int i=0;
			for(i=0;i<=line;i++)//find first free ip to offer
			{
				if(iplist[i].free==0)
				{
					break;
				}
			}
			if(i>line)
				continue;
			sendmessage.lifetime=3600;
			sendmessage.transid=recvmessage->transid;
			sendmessage.requesttype=1;//offer
			memcpy((void*)(sendmessage.ip),(void*)(iplist[i].ip),16);
		}
		if(recvmessage->requesttype==2)//request
		{
			memset((void*)(sendmessage.ip),0,16);
			int i=0;
			for(i=0;i<=line;i++)//find request  ip to ack
			{
				if((memcmp((void*)(recvmessage->ip),(void*)(iplist[i].ip),16)==0)&&(iplist[i].free==0))
				{
					iplist[i].free=1;
					break;
				}
			}
			if(i>line)
				continue;
			sendmessage.lifetime=3600;
			sendmessage.transid=recvmessage->transid;
			sendmessage.requesttype=3;//ack
			memcpy((void*)(sendmessage.ip),(void*)(iplist[i].ip),16);
		}
		memcpy((void*)buf,(void*)&sendmessage,n);
		int sent = sendto(sockfd, buf, n, 0, (struct sockaddr *) &clientaddr,clientlen);
		if (sent<0)
		{
			printf("ERROR on sendto\r\n");
		}
	}
	return EXIT_SUCCESS;

}

