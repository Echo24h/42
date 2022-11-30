#!/bin/sh
if [ ! -f ./wp-config.php ]
then
	wget https://wordpress.org/latest.tar.gz;
	tar -xzf latest.tar.gz
	mv wordpress/* .
	rm -rf wordpress latest.tar.gz
	mv wp-config-sample.php wp-config.php
	sed -i "s|define( 'DB_NAME', 'database_name_here' );|define( 'DB_NAME', '${DB_NAME}' );|g" wp-config.php
	sed -i "s|define( 'DB_USER', 'username_here' );|define( 'DB_USER', '${DB_USER}' );|g" wp-config.php
	sed -i "s|define( 'DB_PASSWORD', 'password_here' );|define( 'DB_PASSWORD', '${DB_PASS}' );|g" wp-config.php
	sed -i "s|define( 'DB_HOST', 'localhost' );|define( 'DB_HOST', 'mariadb' );|g" wp-config.php
	sed -i "s|define( 'AUTH_KEY',         'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'LOGGED_IN_KEY',    'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'NONCE_KEY',        'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'AUTH_SALT',        'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'LOGGED_IN_SALT',   'put your unique phrase here' );||g" wp-config.php
	sed -i "s|define( 'NONCE_SALT',       'put your unique phrase here' );||g" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_HOST', 'redis' );" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_PORT', 6379 );" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_TIMEOUT', 1 );" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_READ_TIMEOUT', 1 );" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_DATABASE', 0 );" wp-config.php
	sed -i "20 i\define( 'WP_REDIS_PASSWORD', '${REDIS_PASS}' );" wp-config.php
fi
