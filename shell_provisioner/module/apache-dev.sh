#!/bin/bash

# Apache development

apt-get install -y apache2-dev libcurl4-openssl-dev gdb

apt install -y libcmocka-dev

cd /home/vagrant
su - vagrant -c "apt source apache2"

