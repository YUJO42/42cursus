FROM debian:buster
LABEL maintainer = "yujo(yujo@student.42seoul.kr"

# update debian
RUN apt-get update && apt-get -y upgrade

# intsall basic tools and NginX
RUN apt-get install -y git vim curl wget nginx

# install PHP and OpenSSL and MariaDB(mySQL)
RUN apt-get install -y php php-fpm php-mysql openssl mariadb-server

# get SSL Certificate
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN	mv localhost.dev.crt etc/ssl/certs/
RUN	mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# get phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html/

