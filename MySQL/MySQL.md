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