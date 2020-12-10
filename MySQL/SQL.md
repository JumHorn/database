# SQL

# Every derived table must have its own alias

# 查询过程中不能删除

you can't modify the same table which you use in the SELECT part
```SQL
DELETE p
FROM Person AS p
WHERE p.Id NOT IN(SELECT MIN(p1.Id) FROM Person as p1 GROUP BY p1.email);
```
but you can nesting the subquery deeper \
However, beware that from MySQL 5.7.6 and onward, the optimiser may optimise out the subquery, and still give you the error
```SQL
DELETE p
FROM Person AS p
WHERE p.Id NOT IN(
	SELECT mid FROM(
		SELECT MIN(p1.Id) AS mid FROM Person as p1 GROUP BY p1.email) as Id
);
```

# timestamp
1. timestamp修改时间
2. CURRENT_TIMESTAMP创建时间

# 添加和查看字段描述
```SQL
alter table tablename change column column int COMMENT '0 not finished 1 finished';
```
```SQL
-- no ; at the end of \G
SHOW FULL COLUMNS FROM tablename \G
```