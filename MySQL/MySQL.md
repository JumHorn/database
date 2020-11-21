# create user

```SQL
CREATE user 'username'@'%' identified by 'passwd'; --create user

GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'localhost'; --grant privileges
```

# connect to mysql
```SQL
mysql -u username -h host -p;
```