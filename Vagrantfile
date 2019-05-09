# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
    config.vm.define :cmocka_apache_module do |cmocka_apache_module_config|
        cmocka_apache_module_config.vm.box = "Intracto/Debian9"

        cmocka_apache_module_config.vm.provider "virtualbox" do |v|
            # show a display for easy debugging
            v.gui = false

            # RAM size
            v.memory = 2048

            # Allow symlinks on the shared folder
            v.customize ["setextradata", :id, "VBoxInternal2/SharedFoldersEnableSymlinksCreate/v-root", "1"]
        end

        # allow external connections to the machine
        #cmocka_apache_module_config.vm.forward_port 80, 8080

        # Shared folder over NFS
        cmocka_apache_module_config.vm.synced_folder ".", "/vagrant", type: "nfs", mount_options: ['rw', 'vers=3', 'tcp', 'fsc', 'nolock', 'actimeo=2']

        cmocka_apache_module_config.vm.network "private_network", ip: "192.168.33.75"

        # Provice access to Intracto servers with the SSH key of your host machine
        cmocka_apache_module_config.ssh.forward_agent = true

        # Shell provisioning
        cmocka_apache_module_config.vm.provision :shell, :path => "shell_provisioner/run.sh"
    end
end
