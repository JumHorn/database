# sqlite in 5 minutes or less

> https://www.sqlite.org/quickstart.html
> https://www.sqlitetutorial.net

# connect to sqlite3
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

# add column(can not remove column)
```SQL
ALTER TABLE table_name
ADD COLUMN column_definition;
```

# new table to replace the old one
```SQL
insert into newtable(column1,column2) select column1,column2 from oldtable;
drop table if exists oldtable;
alter table newtable rename to oldtable;
```

# timestamp
```SQL
CREATE TABLE IF NOT EXISTS "cryptokeys"(private text,public text,time TIMESTAMP DEFAULT CURRENT_TIMESTAMP);

-- Sqlite: CURRENT_TIMESTAMP is in GMT, not the timezone of the machine
-- solution function
CREATE TABLE IF NOT EXISTS "cryptokeys"(private text,public text,time TIMESTAMP DEFAULT (datetime('now','localtime')));


-- solution triggers(not used)
--Create before update and after insert triggers:
CREATE TRIGGER UPDATE_cryptokeys BEFORE UPDATE ON cryptokeys
    BEGIN
       UPDATE cryptokeys SET time = datetime('now', 'localtime')
       WHERE rowid = new.rowid;
    END

CREATE TRIGGER INSERT_cryptokeys AFTER INSERT ON cryptokeys
    BEGIN
       UPDATE cryptokeys SET time = datetime('now', 'localtime')
       WHERE rowid = new.rowid;
    END
```