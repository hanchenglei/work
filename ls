/*
 *personnel_mannagement/server
 *hcl 2019/2/12
 *v 0.0
 */

#include "head.h"

struct sockaddr_in local_addr;
socklen_t loacl_addrlen = sizeof(local_addr);
struct sockaddr_in perr_addr;
socklen_t perr_addrlen  = sizeof(perr_addr); 

sqlite3* db = NULL;

void * myfunc (void *arg)
{
	char buf[64] = {};
	struct message server_message = {0};
	while(1)
	{
	    memset(&server_message,0,sizeof(server_message));
		recv((int)arg,&server_message,sizeof(server_message),0);
		printf("cmd = %c\n",server_message.cmd);
		printf("name = %s\n",server_message.name);
		printf("password = %s\n",server_message.password);
		printf("newpassword = %s\n",server_message.newpassword);
		printf("message = %s\n",server_message.message);
		printf("sex = %s\n",server_message.sex);
		printf("age = %d\n",server_message.age);
		printf("phone = %s\n",server_message.phone);
		printf("addr = %s\n",server_message.addr);
	   	
		/*judge cmd and execute cmd method*/
		/*
		switch(server_message.cmd)
		{
			case 'R':
				break；
			case 'L':
				break；
			case 'U':
				break；
			case 'S'：
				break；
			case 'F'：
				break；
						
		}
		*/
		//send((int)arg,"#",2,0);
		
	}
}

int main(void)
{
	int acceptfd;
	int socketfd;
	int ret = 0;
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == socketfd)
	{
		perror("socket");
		return -1;
	}
    local_addr.sin_family = AF_INET;
	local_addr.sin_port     = htons(8888);
	local_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    ret = bind(socketfd,(const struct sockaddr *)&local_addr,loacl_addrlen);
	if(-1 == ret)
	{
		perror("bind");
		return -1;
	}
    ret = listen(socketfd,10);
	if(-1 == ret)
	{
		perror("listen");
		return -1;
	}
    
	printf("************************\n");
	printf("*listen.......\n");
	printf("************************\n");
	
    /*open datebase,not exist create database*/
	if(0 ==mysql_open("./mydb",&db))
	{
		printf("open success\n");
	}
	else
	{
		printf("open fialed\n");
	}

    /*create table*/
    if(0 == mysql_create(db,"users"))
	{
		printf("create success\n");
	}
	else
	{
		printf("create success\n");
	}
	
	while(1)
	{
		acceptfd = accept(socketfd,(struct sockaddr *)&perr_addr,&perr_addrlen);
		if(-1 == acceptfd)
		{
			perror("accept");
			return -1;
		}
		char *perr_ip = inet_ntoa(perr_addr.sin_addr);
    	printf("**********************************\n");
    	printf("*%s accept....\n",perr_ip);
    	printf("**********************************\n");
        pthread_t thread;
		if(0 != pthread_create(&thread,NULL,myfunc,(void*)acceptfd))
		{
			perror("pthread_create");
			return -1;
		}
	}
	return 0;
}
