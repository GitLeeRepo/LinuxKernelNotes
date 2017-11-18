# Overview

Notes on creating device drivers and kernel modules

# Reference

## Books

* [Linux Device Drivers, 3rd Edition](https://www.amazon.com/Linux-Device-Drivers-Jonathan-Corbet/dp/0596005903/ref=cm_cr_arp_d_product_top?ie=UTF8).  The free ppf version of this O'Reilly book available [here](https://lwn.net/Kernel/LDD3/).

## YouTube Videos

* [Syscalls, Kernel vs. User Mode and Linux Kernel Source Code](https://www.youtube.com/watch?v=fLS99zJDHOc)

# Terminology and Concepts

Refer to my [KernelGlosssaryConcept](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelGlosssaryConcepts.md#overview) document.

# Tools

## insmod

You use **insmod** to load a kernel module

```bash
sudo insmod mykrnlmod.ko
```
Assumes you are in the directory for mykrnlmod.o, oherwise provide the path

## rmmod

You use **rmmod** to unload a kernel module

```bash
sudo rmmod mykrnlmod
```
Note: no extension is used here, as it was with **insmod**.  You also do not need to provide a path if you are not in the directory.

## dmsg

The **dmsg** command allows you to see messages written inside the kernel ring/space.  Very useful for viewing the output of your module.

To display the messages:

```bash
dmesg
```
To display the messages and then clear all existing messages:

```bash
sudo dmesg -c
```

# Examples

## Simple Example

This code simply prints a message on loading, and another message on unloading, they can be viewed using the **dmsg** command.

```c
// mykrnlmod.c
//
//  Displays an initialization message upon loading the module, and an exit
//  message when unloading the module.  These messages are viewed by the
//  'dmsg' command without parameters.  To clear the kernel messages use
//  'sudo dmsg -c', which will display them before clearing them.
//
//   Load with 'sudo insmod mykrnlmod.ko'
//   Unload with 'sudo rmmod mykrnlmod'

#include <linux/module.h>
#include <linux/init.h>

static int my_init(void) {
    printk(KERN_INFO "pk:mykernlmod: module loaded at 0x%p\n", my_init);
    return 0;
}

static void my_exit(void) {
    printk(KERN_INFO "pk:mykernlmod: module unloaded from 0x%p\n", my_init);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Traeven");
MODULE_LICENSE("GPL v2");
```
