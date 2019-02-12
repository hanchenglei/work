#ifndef __HEAD_H_
#define __HEAD_H_
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <sqlite3.h>

#define ERROR_EXIT(_err_msg_) do{ \
	perror(_err_msg_);\
	exit(EXIT_FAILURE);\
}while(0)


struct message{
    char cmd;
	char name[32];
	char password[32];
	char newpassword[32];
	char message[32];
	char sex[16];
	int  age;
	char phone[16];
	char addr[64];
};

#define REGISTER 'R'
#define LOGIN    'L'
#define FORGET   'F'
#define EXIT     'E'
#define UPDATE   'U'
#define SEARCH   'S'
#define LEXIT    'X'


#endif //__HEAD_H
