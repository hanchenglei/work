#ifndef _MYSQL_H_
#define _MYSQL_H_

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int mysql_insert(sqlite3 *pdb,struct message *p);
int mysql_create(sqlite3 *pdb);
int mysql_open(char *filename,sqlite3 **ppdb);
int mysql_insert(sqlite3 *pdb,struct message *p);

#endif 
