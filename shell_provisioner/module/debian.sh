#!/bin/bash

# Debian

# Locales
sed -i 's/# nl_BE.UTF-8 UTF-8/nl_BE.UTF-8 UTF-8/' /etc/locale.gen
locale-gen

# Timezone
cp /usr/share/zoneinfo/Europe/Brussels /etc/localtime

# Custom bash prompt
echo "PS1='[\[\033[00;34m\]\u@\h \e[1mDEV\[\033[00m\] \[\033[00;31m\]\w\[\033[00m\]]\n\\$ '" >> /etc/bash.bashrc
echo "PS1='[\[\033[00;34m\]\u@\h \e[1mDEV\[\033[00m\] \[\033[00;31m\]\w\[\033[00m\]]\n\\$ '" >> /home/vagrant/.bashrc

# Enable backports
echo -e "\ndeb http://ftp.de.debian.org/debian stretch-backports main" >> /etc/apt/sources.list

# Sync package index files
apt-get update
apt-get install -y apt-transport-https lsb-release ca-certificates

