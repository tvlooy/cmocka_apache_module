#!/bin/bash

# Shell provisioner

export MODULE_PATH='/vagrant/shell_provisioner/module'

# Adding an entry here executes the corresponding .sh file in MODULE_PATH
DEPENDENCIES=(
    debian
    tools
    vim
    apache
    apache-dev
)

for MODULE in ${DEPENDENCIES[@]}; do
    source ${MODULE_PATH}/${MODULE}.sh
done

echo "cd /vagrant" >> /home/vagrant/.profile
