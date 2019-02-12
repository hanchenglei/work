#ifndef _MYSQL_H_
#define _MYSQL_H_

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

int mysql_selcet(sqlite3 *db,const char *name,const char *passward);
int mysql_create(sqlite3 *pdb);
int mysql_open(char *filename,sqlite3 **ppdb);
#endif 
