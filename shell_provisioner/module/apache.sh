#!/bin/bash

# Apache

apt-get install -y apache2

a2enmod rewrite expires headers proxy proxy_http proxy_fcgi actions alias ssl

