#!/bin/sh

# create wp-config.php
sed -i "s/define( 'DB_NAME', 'database_name_here' );/define( 'DB_NAME', '' );/g" /wordpress/wp-config-sample.php && \
sed -i "s/define( 'DB_USER', 'username_here' );/define( 'DB_USER', '' );/g" /wordpress/wp-config-sample.php && \
sed -i "s/define( 'DB_PASSWORD', 'password_here' );/define( 'DB_PASSWORD', '' );/g" /wordpress/wp-config-sample.php && \
sed -i "s/define( 'DB_HOST', 'localhost' );/define( 'DB_HOST', '' );/g" /wordpress/wp-config-sample.php && \
mv /wordpress/wp-config-sample.php /wordpress/wp-config.php

php-fpm7 -F
