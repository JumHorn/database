# redis运行机制

从源码分析redis是怎样运行的

## 初始化全局变量
1. 初始化redisServer结构体
```C
main();
initServerConfig()
initServer();
```
2. 将redisCommandTable存入到redisServer->commands的字典中,方便client查找
```C
client->cmd->proc=lookupCommand()
```

## reactor事件驱动

1. aeMain进入事件主循环
* beforesleep处理流程在aeApiPoll进入阻塞前，将pending客户端的数据写出去

* 阻塞等待客户端请求

## client请求处理流程

client和connection一一对应，每进来一个conn就创建一个client

1. 先调用connection注册的connSocketEventHandler
2. 在这个handler中调用callhandler对读写事件分别处理
3. 处理请求调用processInputBuffer(这个过程中调用了looupCommand)
4. 调用processCommand处理请求

### server处理请求过程
1. 将返回结果写入client的outbuffer(addReply方法)
2. prepareClientToWrite将client加入到写队里中,等待beforesleep调用

# redis cluster

redis集群实现方式

## master-slave(主从复制)

1. 搭建方法
从机配置文件中添加
```
slaveof master_ip master_port
slaveof 81.69.226.177 6379
```

2. 实现原理


## sentinel(哨兵模式)

## cluster(集群模式)