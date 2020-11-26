# create user

```SQL
CREATE user 'username'@'%' identified by 'passwd'; --create user

GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'localhost'; --grant privileges
```

## localhost can not login %

the connection to localhost bypasses TCP using a UNIX socket file and therefore is not matching any TCP address (%)
1. so just use 127.0.0.1

2. delete user with ''@localhost
```SQL
delete from mysql.user where user='' and host='localhost'
```

# connect to mysql
```SQL
mysql -u username -h host -p;
```

# data import and export

1. import data

* mysql -u root -p < file.sql

* source file.sql

2. export data

mysqldump -u root -p database_name > database_name.sql

3.

# show columns from table

1.
```SQL
SHOW COLUMNS FROM tablename;
```
2.
```SQL
DESCRIBE tablename;
```

# show table schema
```SQL
show create table tablename
```

# alter

1. 修改字段
```SQL
alter table tablename change column_name new_column_name
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
```SQL
create trigger triggername (before/after) delete on tablename
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