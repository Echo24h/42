FROM alpine:3.15
ARG PHP_VERSION=7 \
	DB_NAME \
	DB_USER \
	DB_PASS \
	REDIS_PASS
COPY ./tools/config_php-fpm.sh .
RUN apk update && \
	apk add --no-cache \
	php \
	php${PHP_VERSION}-fpm \
	php${PHP_VERSION}-json \
	php${PHP_VERSION}-mysqli \
	php${PHP_VERSION}-curl \
	php${PHP_VERSION}-dom \
	php${PHP_VERSION}-exif \
	php${PHP_VERSION}-fileinfo \
	php${PHP_VERSION}-imagick \
	php${PHP_VERSION}-mbstring \
	php${PHP_VERSION}-openssl \
	php${PHP_VERSION}-xml \
	php${PHP_VERSION}-zip && \
	sh config_php-fpm.sh && rm ./config_php-fpm.sh
WORKDIR /var/www/
COPY ./tools/install_wordpress.sh ./
RUN sh install_wordpress.sh && rm ./install_wordpress.sh && \
	chmod -R 0777 ./wp-content/
EXPOSE 9000
CMD ["php-fpm7", "-F"]
