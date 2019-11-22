FROM ubuntu:18.04

RUN apt update -yq \
&&  apt upgrade -yq \
&&  apt install apt-utils -yq \
&&  apt install curl gnupg -yq \
&&  apt clean -y

ADD . /app/

WORKDIR /app

RUN curl https://www.mongodb.org/static/pgp/server-4.2.asc | apt-key add - \
&&  echo "deb [ arch=amd64 ] https://repo.mongodb.org/apt/ubuntu bionic/mongodb-org/4.2 multiverse" | tee /etc/apt/sources.list.d/mongodb-org-4.2.list \
&&  apt-get update -y \
&&  apt-get install -y mongodb-org \
&&  apt clean -y

EXPOSE 27017

CMD mongo
