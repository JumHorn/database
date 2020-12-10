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