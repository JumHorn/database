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
datadir = /var/lib/mysq
```