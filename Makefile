all:clint server
.PHONY:all

CC=gcc
CFLAGS=-Wall -g -O2 -c

clint:clint.c 
	$(CC) -o $@ $< 
server:server.c mysql.c
	$(CC) -o $@ $^ -lpthread -lsqlite3

.PHONY:clean
clean:
	rm -rf clint server mydb

