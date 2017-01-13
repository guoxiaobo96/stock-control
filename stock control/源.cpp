#include<Windows.h>
#include<winsock.h>
#include<iostream>
#include<string>
#include<mysql.h>
#include<stdlib.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"libmysql.lib")

int main()
{
	MYSQL mycont;
	MYSQL_RES *result=NULL;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	char column[32][32];
	int res;
	mysql_init(&mycont);
	if (mysql_real_connect(&mycont, "localhost", "root", "GuoXiaoBo960906", "data", 3306, NULL, 0))
	{
		cout << "connect success" << endl;
		mysql_query(&mycont, "SET NAMES GBK");
		res = mysql_query(&mycont, "select * from zg7hp order by ÈÕÆÚ desc limit 10");
		if (!res)
		{
			result = mysql_store_result(&mycont);
			if (result)
			{
				int i, j;
				cout << "number of result:" << (unsigned long)mysql_num_rows(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);
				for (i = 0; i < j; i++)
				{
					cout << column[i] << "  ";
				}
				cout << endl;
				while (sql_row = mysql_fetch_row(result))
				{
					for (i = 0; i < j; i++)
					{
						cout << sql_row[i] << endl;
					}
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);
	}
	mysql_close(&mycont);
	return 0;

}