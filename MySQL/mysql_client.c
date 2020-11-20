#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

/*
compile command
gcc -o client mysql_client.c -lmysqlclient
*/

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char server[] = "192.168.10.155";
	char user[] = "jumhorn";
	char password[] = "hj";
	char database[] = "zabbix";

	conn = mysql_init(NULL);
	if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	{
		printf("%s\n", mysql_error(conn));
	}

	char sql[128] = {0};
	sprintf(sql, "select * from zabbix.users;");
	if (mysql_query(conn, sql))
	{
		printf("%s\n", mysql_error(conn));
	}

	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s\t", row[0]);
		printf("%s\t", row[1]);
		printf("%s\t", row[2]);
		printf("%s\n", row[3]);
	}

	//clean up
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}