/*
 * personnel mannagement/clint
 * hcl 2019/2/11
 * v 0.0
 */

#include "head.h"
#define BUFSIZE 64
struct sockaddr_in peer_addr;
socklen_t peer_addrlen = sizeof(peer_addr);

int main(int argc, char* argv[])
{
	int socketfd;
	socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == socketfd)
	{
		perror("sockt");
	}
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_port   = htons(8888);
	peer_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(-1 == connect(socketfd,(const struct sockaddr *)&peer_addr,peer_addrlen))
	{
		perror("connect");
		return -1;
	}
	char buf[BUFSIZE] = {};
	while(1)
	{
		memset(buf,0,sizeof(buf));
		gets(buf);
		send(socketfd,buf,sizeof(buf),0);
	}
	return 0;
}
