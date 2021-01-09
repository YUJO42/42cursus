FROM alpine:latest

RUN apk update
RUN apk add mysql

RUN mkdir -p /run/mysqld
COPY my.cnf /etc/mysql/
COPY mysql-init /tmp/
COPY start.sh /tmp/

EXPOSE 3306

ENTRYPOINT ["sh", "/tmp/start.sh"]
