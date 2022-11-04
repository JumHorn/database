import redis

master = redis.Redis(host='masterhost', password='', port=6379)
slave = redis.Redis(host="slavehost", username="name", password="", port=18385)

for key in master.keys():  # traversal all keys
    keytype = master.type(key)

    if keytype == b'string':
        slave.set(key, master.get(key))
    elif keytype == b'hash':
        slave.hmset(key, master.hgetall(key))
    elif keytype == b'list':
        for k in master.lrange(key, 0, -1):
            slave.rpush(key, k)
    elif keytype == b'set':
        for k in master.smembers(key):
            slave.sadd(key, k)
    elif keytype == b'zset':
        for k, v in master.zrange(key, 0, -1, withscores=True):
            slave.zadd(key, k, v)
