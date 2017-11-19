# Overview

This document contains directories that are important to the kernel and the build process.  It is referenced from other documents in this repository.

# Important Directories

* **/boot** - where the boot loader (GRUB) and kernels reside, along with other boot related files and directories
* **/etc/default** - contains the **/etc/default/grub** config file, which is where you should make changes to grub.  Refer to the file section below for more information
* **/etc/grub.d/** - custom grub configuration files, these are in addition to the **/etc/default/grub**
* **/lib/modules/\<kernel ver\>** - where the kernel modules reside.  If you built your own kernel, they will be placed here once you run your install scripts after the build has complete, on Ubuntu this is from running the debian packages that you run and that are produced during the build process.
* **/usr/src/\<kernel specific\>** - contains header files for the kernel.  DO NOT place your kernel source tree here, but instead place it somewhere under your home directory, and build with your standard permissions
* **/home/user/linux** - a sub folder named linux or whatever else you chose to place the kernel source files for the various kernel versions you are building for.  You should use your own (non-sudo) permissions when building here.

# Important Files

## GRUB Related

* **/boot/grub/grub.cfg** - the grub menu and commands.  Do not change this, instead make changes in **/etc/default/grub**
* **/etc/default/grub** - this is where you should make changes to GRUB, such as menu timeout, NOT in the **/boot/grub/grub.cfg** file.  In order to apply the changes make here to the **/boot/grub/grub.cfg** file run **sudo update-grub**.  Additional custom menu changes to grub are found in the configurations files in **/etc/grub.d/**
**/etc/grub.d/\*** - files for making custom menu changes and additions.  Use **/etc/default/grub** to make changes such as timeout.
