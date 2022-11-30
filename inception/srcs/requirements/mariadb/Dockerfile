FROM alpine:3.15
ARG DB_NAME \
	DB_USER \
	DB_PASS \
	DB_ROOT
RUN apk update && \
	apk add --no-cache \
	mariadb \
	mariadb-client \
	openrc
RUN openrc && \
	touch /run/openrc/softlevel
EXPOSE 3306
COPY ./tools/init.sh .
RUN sh init.sh && rm -f init.sh
USER mysql
CMD ["mysqld_safe"]
