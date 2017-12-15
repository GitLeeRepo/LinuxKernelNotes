# Overview

Notes on building a Linux Kernel on an Ubuntu System

# References

* [Linux Kernel Source](https://www.kernel.org/)
* [Ubuntu Kernel Build Info](https://wiki.ubuntu.com/KernelTeam/GitKernelBuild)
[Linux Kernel Newbies](https://kernelnewbies.org/)

## Books

* [Linux Kernel Development 3rd Ed](https://www.amazon.com/Linux-Kernel-Development-Robert-Love/dp/0672329468/ref=cm_cr_arp_d_product_top?ie=UTF8)

## YouTube

* [Building the Simplest Possible Linux System](https://www.youtube.com/watch?v=Sk9TatW9ino&t=6330s)

# My Other Notes

* [LinuxKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/LinuxKernelNotes.md#overview)
* [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes.md#overview)


## YouTube Videos

* [Linux From Scratch}(https://www.youtube.com/watch?v=8WsDcW5SQ9Y) - follows along with the online [Linux From Scratch](http://www.linuxfromscratch.org/lfs/view/stable/) instructions

# Terminology and Concepts

Refer to my [KernelGlosssaryConcept](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelGlosssaryConcepts.md#overview) document.

# Important Directories and Files

Refer to my separate [KernelDirectoriesAndFiles](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelDirectoriesAndFiles.md#overview) document

# Prerequisites

Download and install the toolchain needed to build the kernel{

```bash
sudo apt-get install git build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache
```

# Download Kernel

In general, it is preferable to download the kernel to a directory under your home directory, using your standard permissions.

## Using GIT

git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git

Gets the latest mainline kernel.

## Download Tarball from kernel.org

Download the desired version from [https://www.kernel.org/](https://www.kernel.org/) as a tarball

The kernel code is in a tarball compressed with xz compression.  To extract use the following command:

```bash
tar xf <kernel>.tar.xz
```

# Kernel Config File

Copy your existing kernel config file to the root of your source tree to be used as a template for the new build:

```bash
cp /boot/config-`uname -r` .config
```

Modify this configuration using make (note **oldconfig** is the actual name to use, don't replace this), by responding to the prompts (safe to take the defaults):

```bash
make oldconfig
```

or automatically accept all defaults:

```bash
yes '' | make oldconfig
```

To make any additional changes (optional) to the config run:

```bash
make menuconfig
```
Note: menuconfig is just one option, it is a curses full screen text version.  **make config** is a plain text version, **make xconfig** is a graphical Qt base version, and **make gconfig** is a graphical based GTK+ version.

# The Build

The build is a lengthy process, so dedicate as many processors to your machine as feasible (on a Hyper-V image you can have up to the total number of logical processors on your host (cores + hyper threads).  This total includes all virtual machines currently running, so if you have 16 logical host processors, you can have one virtual machine with 16 virtual processors, or two virtual machines with 8 virtual processors each, etc.

## Pre Check
To see the number of processors (including logical/virtual) the systems is running on:

```bash
nproc
```
For example, his would show 8, if this is running on a virtual machine with 8 virtual processors.

## Clean up

To ensure their are no other prior build files or dependencies

```bash
make clean

make mrproper
```
Note: **make clean** is per Ubuntu docs, and **make mrproper*** is per the kernel's README

## The Build itself

This will take a very long time (as long as an hour+)

```bash
make -j `getconf _NPROCESSORS_ONLN` deb-pkg LOCALVERSION=-custom
```
The **deg-pkg** tells what type of packages to use, and **LOCALVERSIN=custom** says to use the **custom** label as part of the package names (you can change this to whatever you want).

## Install the packages

Install the **\*.deb** packages, here is an example, but it needs to be changed for the specific versions involved

```bash
cd ..
sudo dpkg -i linux-image-4.14.0-tlk01a_4.14.0-tlk01a-1_amd64.deb
sudo dpkg -i linux-headers-4.14.0-tlk01a_4.14.0-tlk01a-1_amd64.deb
sudo dpkg -i linux-libc-dev_4.14.0-tlk01a-1_amd64.deb
```
Note the **cd ..**, this is because the **\*.db** packages were placed on directory up in the hierarchy from where you ran the build.

Optionally, install the debug kernel

```bash
sudo dpkg -i linux-image-4.14.0-tlk01a-dbg_4.14.0-tlk01a-1_amd64.deb
```
### Output from dpkg -i linux-image-4.14.0-tlk01a_4.14.0-tlk01a-1_amd64.deb

Note how this will put the new kernel in the /boot directory and update the GRUB menu:

```bash
Selecting previously unselected package linux-image-4.14.0-tlk01a.
(Reading database ... 123840 files and directories currently installed.)
Preparing to unpack linux-image-4.14.0-tlk01a_4.14.0-tlk01a-1_amd64.deb ...
Unpacking linux-image-4.14.0-tlk01a (4.14.0-tlk01a-1) ...
Setting up linux-image-4.14.0-tlk01a (4.14.0-tlk01a-1) ...
update-initramfs: Generating /boot/initrd.img-4.14.0-tlk01a
WARNING: Setting CRYPTSETUP in /etc/initramfs-tools/initramfs.conf is deprecated and will stop
 working in the future. Use /etc/cryptsetup-initramfs/conf-hook instead.
Searching for GRUB installation directory ... found: /boot/grub
Searching for default file ... found: /boot/grub/default
Testing for an existing GRUB menu.lst file ... found: /boot/grub/menu.lst
Searching for splash image ... none found, skipping ...
Found kernel: /boot/vmlinuz-4.13.0-16-generic
Found kernel: /boot/vmlinuz-4.14.0-tlk01a
Found kernel: /boot/vmlinuz-4.13.0-16-generic
Replacing config file /run/grub/menu.lst with new version
Updating /boot/grub/menu.lst ... done
Generating grub configuration file ...
Found linux image: /boot/vmlinuz-4.14.0-tlk01a
Found initrd image: /boot/initrd.img-4.14.0-tlk01a
Found linux image: /boot/vmlinuz-4.13.0-16-generic
Found initrd image: /boot/initrd.img-4.13.0-16-generic
done
```

## Reboot into New Kernel

Reboot into the new kernel after that packages above are installed.  In my case the GRUB menu only displayed for about 1 second (it previously was about 5) before booting into the new kernel.  I rebooted a second time to verify that the previous kernel was still selectable and bootable.

Run the following to verify you are in the new kernel:

```bash
uname -a
```

# Additional Information

This is additional information for understanding the build process.  It is not necessary for doing the build described in the initial sections, but can provide useful information for customizing future builds.

## GRUB Related

The GRUB related files are found in the **/boot/** directory, along with kernel, initrd, and other files.  The **/boot/grub/grub.cfg** contains the grub menu, along with the commands need to boot various operating system.  Do not change this, instead make changes in **/etc/default/grub** and the **/etc/grub.d/\*** files.  That way any changes you make won't be overwritten the next time a new kernel is added.  The **/etc/default/grub** - is where you should make changes to GRUB, such as menu timeout, while custom menu changes and additions should be made to the files in the **/etc/grub.d/** directory.  After making changes in these files run **sudo update-grub** to apply the changes to the **/boot/grub/grub.cfg** file.  

## The initrd Initial Root File System

The **initrd** is the boot loader initialized RAM disk. It is a gzipped cpio archive that has a minimal root file system.  It is is the initial root file system the boot loader loads into memory just before loading the kernel.  The kernel then uses this initial root file system to load drivers and then mount the actual root file system.

### Examining the Contents of the initrd RAM Disk File System

Because the **initrd** is a gzipped cpio archive, it can be unzipped and extracted.

* Copy the **initrd** file from the /boot folder (it will have a name such as, **initrd.img-4.14.0-default** to a temporary directory, giving the file a **\*.gz gzip** extension
* Run **gunzip initrd.img-4.14.0-default** to unzip to the cpio archive file
* Run **sudo cpio -i < initrd.img-4.14.0-default** to extract the files and directories from the **cpio** archive.

You can now see what file are initially used by the kernel as it is booting up.  One of the most interesting files to look at is the **init** script in the root.  This shows the process of bringing up the OS, establishing /proc, /dev, /sys, /tmp directories, calling other scripts, and moving things from the virtual file system to the real file system

## Using provided defconfigs for configuring the build

To get a starting configuration, you can use an existing defconfig as the template for your make config.  To see what is available for your system enter:

```bash
make help | grep defconfig
```

This will give you a list that applies to the architectures available to you (assuming you haven't set up cross platform compiling).

This is similar to what I did in my first build here, except I got my initial configuration from copying it from the  /boot/config using the Ubuntu config for my OS version.

# Kernel Install History


Date/Time        | Kernel Installed | Built on System          | Build Time | Processors | Image     | Issues
-----------------|------------------|--------------------------|------------|------------|-----------|--------
2017-11-17 23:58 | vmlinuz-4.14.0   | Ubuntu vmlinuz-4.13.0-16 | 55 minutes | 8          | Hyper-V | None 

