# Overview

Notes on building a Linux Kernel on an Ubuntu System

# References

* [Liinux Kernel Source](https://www.kernel.org/)
* [Ubuntu Kernel Build Info](https://wiki.ubuntu.com/KernelTeam/GitKernelBuild)
[Linux Kernel Newbies](https://kernelnewbies.org/)
* [Linux From Scratch](http://www.linuxfromscratch.org/lfs/view/stable/) - Walkthough of building the LFS kernel

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

Note some of these definitions are copied from [https://kernelnewbies.org/KernelGlossary](https://kernelnewbies.org/KernelGlossary)

* **ABI** - Application Binary Interface, the interface of passed structures between the user processes (and libraries) and the kernel. For compatibility, it is important that these remain as static as possible (i.e. making sure that variables and structure members have the same bytesize as before, and in the same ordering). Occasionally breakage is necessary, requiring re-compilation of the user-space sources (note that this does not affect source-compatibility; that is a separate issue).
* **Logical Processor** - on an Intel processor this is the number of cores, times the number of hyper threads per core.  So an 8 core system, with 2 hyper threads per core would be a total of 16 logical processors.  See **Virtual Processor** for a virtual machine environment.
* **Mainline** - vanilla Linux Kernel, without any vendor/distribution specific code or drivers. This branch is officially released as a new version approximately every ten weeks.  This is not the same as the **stable version**, which has been more thoroughly tested over a longer period, but doesn't have the latest features and fixes that the **mainline** version has.
* **MMU** - Memory Management Unit, part of the CPU hardware that enforces memory boundaries, and throw page faults, upon which the OS builds its coherent protection. The MMU maps virtual memory to actual, where protections allow
* **Virtual Processor** = on a Hyper-V image you can have up to the total number of logical processors on your host (cores + hyper threads).  This total includes all virtual machines currently running, so if you have 16 logical host processors, you can have one virtual machine with 16 virtual processors, or two virtual machines with 8 virtual processors each, etc.  See **Logical Processor**

# Prereqisites

Download and install the toolchain needed to build the kernel{

```bash
sudo apt-get install git build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache
```

# Downalod Kernel

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

The build is a lengthy process, so dedicate as many processesor to your machine as feasible (on a Hyper-V image you can have up to the total number of logical processors on your host (cores + hyper threads).  This total includes all virtual machines currently running, so if you have 16 logical host processors, you can have one virtual machine with 16 virtual processors, or two virtual machines with 8 virtual processors each, etc.

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
sudo dpkg -i linux-image-2.6.24-rc5-custom_2.6.24-rc5-custom-10.00.Custom_i386.deb
sudo dpkg -i linux-headers-2.6.24-rc5-custom_2.6.24-rc5-custom-10.00.Custom_i386.deb
```
Note the **cd ..**, this is because the **\*.db** packages were placed on directory up in the hierarchy from where you ran the build.
