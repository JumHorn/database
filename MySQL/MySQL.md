# create user

```SQL
CREATE user 'username'@'%' identified by 'passwd'; --create user

GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'%'; --grant privileges

grant select,delete,update,create,drop on databasename.* to 'username'@'%' identified by "passwd";
```

## localhost can not login %

the connection to localhost bypasses TCP using a UNIX socket file and therefore is not matching any TCP address (%)
1. so just use 127.0.0.1

2. delete user with ''@localhost
```SQL
delete from mysql.user where user='' and host='localhost'
```

# connect to mysql
```shell
mysql -u username -h host -p
```

# data import and export

1. import data
```shell
# method 1
mysql -u root -p database_name < file.sql --default-character-set=utf8
# method 2 针对乱码有效
mysql> set names utf8;
mysql> source file.sql
```

2. export data
```shell
# export whole database
mysqldump -u root -p database_name > database_name.sql
# export single table without data
mysqldump -u root -p --no-data database_name tablename > table.sql
```

# operation with table
1. show table schema
```SQL
show create table tablename
```
2. 修改表名
```SQL
rename table table_name to new_table_name;
```

# operation with columns

1. show column
```SQL
SHOW COLUMNS FROM tablename;
```
2. show column
```SQL
DESCRIBE tablename;
```
3. 修改字段
```SQL
alter table tablename change column_name new_column_name column_property
```
4. 插入字段
```SQL
alter table tablename add column column_name text after exist_column_name;
```
5. 删除字段
```SQL
ALTER TABLE table_name DROP COLUMN column_name;
```

# 创建临时表

```SQL
create temporary table tablename(......)
```

# 创建视图

视图不是真的表，并不保存数据，而临时表实际存在，且保存数据

```SQL
create view viewname as select ...
```

# 存储过程
```SQL
DELIMITER // --set different delimiter
create procedure in_param(IN p_in,int)
BEGIN
	select p_in;
	set p_in=2;
	select p_in;
END
//
DELIMITER ; --restore defualt delimiter
```

# 触发器
mysql中old表示执行前的数据,new表示执行后的数据
```SQL
create trigger triggername (before/after) delete on tablename
```
```SQL
-- example
CREATE TRIGGER `user_trigger` BEFORE UPDATE ON `user`
FOR EACH ROW SET NEW.`update_time` = NOW()
```
查看触发器
```SQL
show triggers in database_name;
```
查看触发器schema
```SQL
show create trigger triggername;
```

# 事务隔离级别设置

```SQL
-- 查看事务隔离级别
show variables like 'tx_isolation';
-- 查看全局事务隔离级别
show global variable like 'tx_isolation';
-- 查看
SELECT @@tx_isolation;
-- 设置
set session transaction isolation level read uncommitted;
```

# 设置索引
1. 普通索引(index)
```SQL
-- 创建索引
CREATE INDEX indexName ON mytable(username(length));
-- 修改表结构
ALTER mytable ADD INDEX [indexName] ON (username(length))
-- 创建表的时候直接指定
CREATE TABLE mytable( ID INT NOT NULL, username VARCHAR(16) NOT NULL, INDEX [indexName] (username(length)));
-- 删除索引
DROP INDEX [indexName] ON mytable;
```
2. 主键索引(primary key)
```SQL
-- 特殊的主键唯一性作为索引
CREATE TABLE mytable( ID INT NOT NULL, username VARCHAR(16) NOT NULL, PRIMARY KEY(ID));
```
3. 唯一索引(unique)
```SQL
CREATE UNIQUE INDEX indexName ON mytable(username(length))
ALTER mytable ADD UNIQUE [indexName] ON (username(length))
```
4. 组合索引
```SQL
ALTER TABLE mytable ADD INDEX name_city_age (name(10),city,age);
```

# 分片sharding

# 存储引擎

```SQL
show variables like '%storage_engine%'
```

# 锁

1. 表级锁定（table-level）
> https://www.mysqltutorial.org/mysql-table-locking/
```SQL
LOCK TABLES table_name [READ | WRITE]
...
...
UNLOCK TABLES;
```

2. 行级锁定（row-level)
```SQL
START TRANSACTION;
SELECT ledgerAmount FROM accDetails WHERE id = 1 FOR UPDATE;
```

3. 页级锁定（page-level）

# 查询死锁
```SQL
SHOW ENGINE INNODB STATUS
```

# 主从模式Replication
> https://dev.mysql.com/doc/refman/8.0/en/replication-configuration.html

2. 配置文件中指定
```ini
replicate-do-db=db_name
server-id=101
log-bin=mysql-bin
```

2. 主机查看bin-log
```SQL
show master status
```

3. 从机设置slave
```SQL
-- the last two was from server master status
change master to master_host='serverip',master_port=3306,master_user='username',master_password='password',master_log_file='mysql-bin.000001',master_log_pos=1336;
```
```SQL
start slave
show slave status
```

## The user specified as a definer
从机本地也要创建相同的用户名