# sqlite in 5 minutes or less

> https://www.sqlite.org/quickstart.html
> https://www.sqlitetutorial.net

# connect to mysql
```SQL
sqlite3 database_name;
```

# data import and export

1. import data
```shell
sqlite> .read file.sql
```

2. export data
```shell
sqlite> .output c:/sqlite/chinook.sql
sqlite> .dump
sqlite> .exit
```

# show columns from table

1.
```SQL
pragma table_info(tablename)
```

2.
```SQL
SELECT sql
FROM sqlite_master
WHERE name = 'tablename';
```

# show table schema
```SQL
.schema table_name
```