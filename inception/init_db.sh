#!/bin/sh

/etc/init.d/mariadb setup

/etc/init.d/mariadb start

sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

# mysql_secure_installation
mysql -e "UPDATE mysql.global_priv SET priv=json_set(priv, '$.plugin', 'mysql_native_password', '$.authentication_string', PASSWORD('password')) WHERE User='root';"
mysql -e "DELETE FROM mysql.global_priv WHERE User='';"
mysql -e "DELETE FROM mysql.global_priv WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');"
mysql -e "DROP DATABASE IF EXISTS test;"
mysql -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';"
mysql -e "FLUSH PRIVILEGES;"

mysql -e "CREATE DATABASE wordpress_db"
mysql -e "CREATE USER 'wordpress_admin'@'localhost' IDENTIFIED BY 'password';"
mysql -e "GRANT ALL ON wordpress_db.* TO wordpress_admin@localhost;"
mysql -e "FLUSH PRIVILEGES;"

/etc/init.d/mariadb stop

/usr/bin/mysqld_safe