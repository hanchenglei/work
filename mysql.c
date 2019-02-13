#include "mysql.h"



int mysql_selcet(sqlite3 *db,struct message *p)
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
			if(0 == strcmp(db_result[i+j],p->name))
			{
				if(0 == strcmp(db_result[i+j+1],p->password))
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
    int ret = sqlite3_exec(pdb,\
    "create table if not exists users(name char(32),password char(32),message char(32),sex char(16),age int,phone char(16),addr char(64))",\
   	0,0,NULL);
    if(ret !=   SQLITE_OK)
    {
        sqlite3_close(pdb);
        return 1;
    }
       return 0;

}

int mysql_insert(sqlite3 *pdb,struct message *p)
{
    //插入数据
    char buf[512] = {0};
	memset(buf,0,sizeof(buf));
	sprintf(buf,"insert into users values('%s','%s','%s','%s','%d','%s','%s')",\
		p->name,p->password,p->message,p->sex,p->age,p->phone,p->addr);
	int ret = sqlite3_exec(pdb,buf,0,0,NULL);
	if(ret !=   SQLITE_OK)
    {
        sqlite3_close(pdb);
        return 1;
    }
        return 0;
	
}
