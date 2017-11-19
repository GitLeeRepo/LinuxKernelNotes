# Overview

This document contains directories that are important to the kernel and the build process.  It is referenced from other documents in this repository.

# Important Directories

* **/boot** - where the boot loader (GRUB) and kernels reside, along with other boot related files and directories
* **/lib/modules/\<kernel ver\>** - where the kernel modules reside.  If you built your own kernel, they will be placed here once you run your install scripts after the build has complete, on Ubuntu this is from running the debian packages that you run and that are produced during the build process.
* **/usr/src/\<kernel specific\>** - contains header files for the kernel.  DO NOT place your kernel source tree here, but instead place it somewhere under your home directory, and build with your standard permissions
* **/home/user/linux** - a sub folder named linux or whatever else you chose to place the kernel source files for the various kernel versions you are building for.  You should use your own (non-sudo) permissions when building here.
