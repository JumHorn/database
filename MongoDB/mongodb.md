# MongoDB
  document oriented database
  看到mongodb的用法很与众不同，也想体验一下，就建立了云数据库，开始体验
  > https://cloud.mongodb.com/
  
  注册即可获得免费使用的云数据库
  
# 基本概念对比
|RDBMS|MongoDB|
|:---:|:---:|
|Database|Database|
|Table|Collection|
|Tuple/Row|Document|
|column|Field|
|Table Join|Embedded Documents|
|Primary Key|Primary Key (Default key _id provided by MongoDB itself)|
  
# 数据库基本操作
1. 连接数据库
```shell
mongosh "mongodb+srv://cluster0.ucrfihm.mongodb.net/DatabaseName" --apiVersion 1 --username jumhorn
```
2. 数据库操作
```shell
# show database
show dbs
# use database 没有数据，数据库不会生成
# 删除数据库
db.dropDatabase()
```
3. 操作Collection(类似表)
```shell
show tables
# 创建collection
db.createCollection("user")
# 删除collection
db.user.drop
```

# 增删改查
1. insert
```shell
# insert and save is deprecated
db.user.insertOne({"name":"yasuo"})
db.user.insertMany([{"name":"jinx"},{"name":"jax"},{"name":"lux"}])
```
2. delete
```shell
# remove is deprecated
db.user.deleteOne({'name':'yasuo'})
db.user.deleteMany({'name':'yasuo'})
```
3. update
```shell
# insert is deprecated
# 只更新第一个
db.user.updateOne({"name":"yasuo"},{$set:{"name":"zed"}})
# 更新全部
db.user.updateOne({"name":"yasuo"},{$set:{"name":"zed"}},{multi:true})
```
4. find
```shell
db.collectionName.find()
# 正则表达式方式查找
db.collectionName.find({"text":{$regex:/dragon/}})
```

# 条件查找

# 索引
  
  创建索引，提高查找效率
```shell
# 1表示升序 -1表示降序
db.user.createIndex({"name":1})
# 后台创建索引
db.user.createIndex({open: 1, close: 1}, {background: true})
```
