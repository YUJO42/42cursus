FROM debian:buster
LABEL maintainer = "yujo(yujo@student.42seoul.kr)"

#################
# update debian #
#################
RUN apt-get update && apt-get -y upgrade

#################################
# intsall basic tools and NginX #
#################################
RUN apt-get install -y vim curl wget nginx

##############################################
# install PHP and OpenSSL and MariaDB(MySQL) #
##############################################
RUN apt-get install -y php php-fpm php-mysql openssl mariadb-server libnss3-tools

#####################
# install WordPress #
#####################
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress/ var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress

#######################
# get SSL Certificate #
#######################
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN	mv localhost.dev.crt etc/ssl/certs/
RUN	mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# ssl
# RUN mv mkcert-v1.1.2-linux-amd64 mkcert; \
# 	chmod +x mkcert; \
# 	./mkcert -install; \
# 	./mkcert localhost

##################
# NginX Setting  #
##################
ADD src/default /etc/nginx/sites-available/default

##################
# get phpMyAdmin #
##################
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html/
# ADD src/config.inc.php /var/www/html/phpmyadmin/config.inc.php
# RUN	chmod 644 /var/www/html/phpmyadmin/config.inc.php

##################
# set phpMyAdmin #
##################
# ADD src/config.inc.php /var/www/htmp/phpmyadmin/config.inc.php
ADD src/config.inc.php /usr/share/phpmyadmin/config.inc.php
RUN mkdir /usr/share/phpmyadmin/tmp; \
	chmod 777 /usr/share/phpmyadmin/tmp; \
	chmod 644 /usr/share/phpmyadmin/config.inc.php
RUN ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin

##########################
# WordPress Setting 	 #
##########################
ADD src/wp-config.php /var/www/html/wordpress/wp-config.php
RUN service mysql start; \
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password  \
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password \
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password \
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
	# echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql; \
	# echo "GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'password';" | mysql; \
	# echo "FLUSH PRIVILEGES;" | mysql


#############################
# Setting PORT & Run Server #
#############################
EXPOSE 80 443
CMD service mysql start; \
	service php7.3-fpm start; \
	service nginx start; \
	bash;
	# nginx -g 'daemon off;'
