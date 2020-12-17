# mysql字符集设置
## 查看字符集
```SQL
show variables like "%char%";
```
## mysql设置默认UTF8
**只对之后建立的数据库有效**
修改mysql配置文件 /etc/my.cnf
```ini
[client]
default-character-set=utf8

[mysqld]
collation-server = utf8_unicode_ci
init-connect='SET NAMES utf8'
character-set-server = utf8
```

## 修改数据库字符集
**只对之后建立的表有效**
```SQL
alter database databasename CHARACTER SET = 'utf8';
```

## 修改表字符集
**只对之后插入的数据有效**
```SQL
ALTER TABLE tbl_name CONVERT TO CHARACTER SET charset_name;
```

# 查看表占用空间大小
```SQL
SELECT TABLE_NAME,DATA_LENGTH+INDEX_LENGTH,TABLE_ROWS,concat(round((DATA_LENGTH+INDEX_LENGTH)/1024/1024,2), 'MB') as data
FROM information_schema.tables WHERE TABLE_SCHEMA='databasename' ORDER BY DATA_LENGTH+INDEX_LENGTH desc;
```

# 查看数据库文件存储位置
```SQL
select @@datadir;
```

# 重新连接服务器
```shell
# 断线重连，要等待一些时间
mysql -u user_name -h hostname -p --reconnect

# 命令直接指定重连
mysql> connect
```

# 资源
## mysql client commands
> https://dev.mysql.com/doc/refman/8.0/en/mysql-commands.html