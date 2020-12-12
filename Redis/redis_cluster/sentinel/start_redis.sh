cd redis1
redis-server redis.conf &

cd ../redis2
redis-server redis.conf &

cd ../redis3
redis-server redis.conf &

cd ..


cd redis1
redis-sentinel sentinel.conf &

cd ../redis2
redis-sentinel sentinel.conf &

cd ../redis3
redis-sentinel sentinel.conf &

cd ..
