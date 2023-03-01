# MongoDB
	postgreSQL是关系型数据库,同时支持SQL和JSON查询
	> https://elephantsql.com
	注册即可获得免费使用的云数据库

# 数据库基本操作
1. 连接数据库
```shell
psql postgres://username:passwd@tiny.db.elephantsql.com/databasename
```
2. 数据库操作
```shell
# show database
\l
# use database
\c database_name
# 删除数据库
DROP DATABASE <database_name>;
```
3. 表操作
```shell
# show tables
\dt
# 创建表
# 删除表
DROP TABLE <table_name>;
```

# 增删改查

	同为关系型数据库,CRUD操作是相同的