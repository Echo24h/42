FROM alpine:3.15
ARG REDIS_PASS
RUN apk update && \
	apk add --no-cache redis
COPY ./tools/config_redis.sh .
RUN sh config_redis.sh && rm -f config_redis.sh
EXPOSE 6379
CMD ["redis-server", "/etc/redis.conf"]
