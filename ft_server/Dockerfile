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
RUN apt-get install -y php php-fpm php-mysql openssl mariadb-server

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

##########################
# WordPress Setting 	 #
##########################
ADD src/wp-config.php /var/www/html/wordpress/wp-config.php
RUN service mysql start; \
	echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql; \
	echo "GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'password';" | mysql; \
	echo "FLUSH PRIVILEGES;" | mysql


#############################
# Setting PORT & Run Server #
#############################
# Setting PORT
EXPOSE 80
EXPOSE 443

# Run Server
CMD service mysql start; \
	service php7.3-fpm start; \
	nginx -g 'daemon off;'
