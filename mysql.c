#include "mysql.h"



int mysql_selcet(sqlite3 *db,const char *name,const char *passward)
{
	//查询
	int nrow,ncolumn;
	char ** db_result;
	int ret = sqlite3_get_table(db,"select * from users",&db_result,&nrow,&ncolumn,NULL);
	if(ret != SQLITE_OK)
	{
		sqlite3_close(db);
		return -2;
	}
	int i,j;
	for(i=0;i<(nrow+1)*ncolumn;i+=ncolumn)
	{
		for(j=0;j<ncolumn;j++)
		{
			if(0 == strcmp(db_result[i+j],name))
			{
				if(0 == strcmp(db_result[i+j+1],passward))
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
    return -1;
}

int mysql_open(char *filename,sqlite3 **ppdb)
{
	//打开数据库，不存在，创建数据库db
    int ret = sqlite3_open(filename,ppdb);
    if(ret != SQLITE_OK)
    {
       return 1;
    }
       return 0;
	
}
int mysql_create(sqlite3 *pdb)
{
    /*create tale*/
    int ret = sqlite3_exec(pdb, \ 
    "create table if not exists users(name char(32),password char(32),message char(32),sex char(16),age int,phone char(16),addr char (64) ",\
	0,0,NULL);
    if(ret !=   SQLITE_OK)
    {
        sqlite3_close(pdb);
        return 1;
    }
       return 0;

}
