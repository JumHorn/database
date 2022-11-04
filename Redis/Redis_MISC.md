# redis中文乱码
```shell
# redis 默认不转义中文,可以在client中设置转义
./redis-cli  --raw
```

# 登录时输入密码
```shell
./redis-cli -a passwd
```

# 查看数据库文件存储位置
```SQL
config get dbfilename
config get dir
```

# 修改数据库文件存储位置
> https://www.digitalocean.com/community/tutorials/how-to-change-a-mariadb-data-directory-to-a-new-location-on-centos-7

修改my.cnf中的datadir到newdir
```shell
# preserves the permissions and other directory properties
sudo rsync -av /var/lib/mysql /path/to/new/dir
```
```ini
datadir = /var/lib/mysql
```

# redis-cli连接集群服务器过程分析
1. 首先连接命令行指定的客户端
2. 发送命令后,由服务端返回move命令,并提供服务器地址
3. 关闭当前连接,开启新的连接到服务器(issueCommandRepeat函数)

# redis-cli重新连接
```shell
connect ip port
```

# 技巧
## 命令行长输入
```shell
# 从文件输入
redis-cli -x set key < filename
# 从stdin输入,ctr-d结束输入
redis-cli -x set key
```

## 数据复制

	由于redislabs提供的免费数据库不支持replica命令，
	所以使用代码方式将数据复制过去
	代码文件[copy redis](copyredis.py)


# 资源
1. [rediscli](https://redis.io/topics/rediscli)

	命令行知识

2. [redislabs](https://app.redislabs.com)

	免费redis 30M