FROM ubuntu:18.04

RUN apt update -yq \
&&  apt upgrade -yq \
&&  apt install curl gnupg -yq \
&&  apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 7F0CEB10 \
&&  echo "deb http://repo.mongodb.org/apt/ubuntu xenial/mongodb-org/3.4 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-3.4.list \
&&  apt-get update -y \
&&  apt-get install -y mongodb-org
&&  apt clean -y
