FROM alpine:latest
ARG IP

# ftps
RUN apk update && apk upgrade
RUN apk add pure-ftpd --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

# SSL
RUN apk add --no-cache openssl
RUN openssl req -x509 -nodes -days 365 -subj "/C=KR/ST=Korea/L=Seoul/O=innoaca/OU=42seoul/CN=hycho" -newkey rsa:2048 -keyout /etc/ssl/private/pure-ftpd.pem -out /etc/ssl/private/pure-ftpd.pem

RUN echo $IP > ip.txt

RUN mkdir -p ftps/user
RUN adduser --home=/ftps/user -D user
RUN chmod -R 777 /ftps/user
RUN echo "user:password" | chpasswd

EXPOSE 20 21 30020 30021

COPY ./start.sh ftps/user/start.sh
CMD ["sh", "/ftps/user/start.sh"]
