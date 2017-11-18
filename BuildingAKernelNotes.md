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
* **Mainline** - vanilla Linux Kernel, without any vendor/distribution specific code or drivers. This branch is officially released as a new version approximately every ten weeks.  This is not the same as the **stable version**, which has been more thoroughly tested over a longer period, but doesn't have the latest features and fixes that the **mainline** version has.
* **MMU** - Memory Management Unit, part of the CPU hardware that enforces memory boundaries, and throw page faults, upon which the OS builds its coherent protection. The MMU maps virtual memory to actual, where protections allow

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

## Kernel Config File

Copy your existing kernel config file to the root of your source tree to be used as a template for the new build:

```bash
cp /boot/config-`uname -r` .config
```

Modify this configuration using make, by responding to the prompts (safe to take the defaults):

```bash
make <config file>
```

or automatically accept all defaults:

```bash
yes '' | make <config file>
```

