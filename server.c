#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
int main()
{
	int server,status;
	struct sockaddr_in sa;
	char buf[100],buf2[100];
	server=socket(AF_INET,SOCK_DGRAM,0);
	if(server==-1)
	{
		printf("socket not created\n");
		return 0;
	}
	printf("socket created\n");
	sa.sin_family=AF_INET;
	sa.sin_port=htons(6000);
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	status=bind(server,(struct sockaddr *)&sa,sizeof(sa));
	if(status==-1)
	{
		printf("bind failed\n");
		return 0;
	}
	printf("bind successfull\n");
	while(!(strcmp("exit",buf2))==0){
	int len=(sizeof(sa));
	int msg=recvfrom(server,buf,100,0,(struct sockaddr *)&sa,&len);
	buf[msg]='\0';
	printf("message from client-->%s\n",buf);
	gets(buf2);
	sendto(server,buf2,strlen(buf2),0,(struct sockaddr *)&sa,sizeof(sa));
	}
	close(server);
return 0;
}
