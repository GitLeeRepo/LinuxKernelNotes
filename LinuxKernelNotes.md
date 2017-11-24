# Overview

Notes on the Linux Kernel, Modules, and Device drivers

# References

* [Linux Cross Reference](http://elixir.free-electrons.com/linux/latest/source) - website cross reference of current code, back to version 2.6.

## Books

* [Linux Kernel Development 3rd Ed](https://www.amazon.com/Linux-Kernel-Development-Robert-Love/dp/0672329468/ref=cm_cr_arp_d_product_top?ie=UTF8)

## YouTube

* [Building the Simplest Possible Linux System](https://www.youtube.com/watch?v=Sk9TatW9ino&t=6330s)
* [Syscalls, Kernel vs. User Mode and Linux Kernel Source Code](https://www.youtube.com/watch?v=fLS99zJDHOc)
* [Kernel Mode Memory Allocation](https://www.youtube.com/watch?v=1Y3Ot5xFZDA&list=PL2TXDotVKyDBEfWSKcePqRRCp9EehqDGF)

# My Other Notes

* [BuildingAKernelNotes](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/BuildingAKernelNotes.md#overview)
* [LinuxSysProgNotes](https://github.com/GitLeeRepo/LinuxSysProgNotes/blob/master/LinuxSysProgNotes.md#overview)

# Terminology and Concepts

Refer to my [KernelGlosssaryConcept](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelGlosssaryConcepts.md#overview) document.

# Important Directories and Files

Refer to my separate [KernelDirectoriesAndFiles](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelDirectoriesAndFiles.md#overview) document

# Kernel Documentation

This section is a reference to the kernel documentation in the kernel source tree itself.


Subdirectory of Documentation | Document Name     | Comment
------------------------------|-------------------|----------------------------------------------------------------
/                             | index.rst         | Starting point Index to other documents
/process                      | index.rst         | Links to docs on the the process of developing for the kernel
/process                      | howto.rst         | Good overview of the process of developing for the kernel

# Interesting Kernel Code to Study

**KEY**
* EBP - Early Boot Process
* MOD - Module related

Directory                     | File              | Description 
------------------------------|-------------------|------------------------------------------------------------------------
arch/x86/kernel               | head32.c          | ERP, has i386_start_kernel, which calls /init/main.c/start_kernel
arch/x86/kernel               | head64.c          | EBP, has x86_64_start_kernel, which calls /init/main.c/start_kernel
arch/x86/boot                 | main.c            | EBP, Real mode boot code, calls to protected mode at end
arch/x86/boot                 | pm.c              | EBP, disables intrupts and switches to protected mode
arch/x86/include/uapi/asm     | bootparms.h       | EBP, header defining boot_parms struct
init                          | main.c            | EBP, contains start_kernel, starts init
init                          | initramefs.c      | EBP, load initramfs
intit                         | do_mounts.c       | EBP, load ramdisk, mount & init root 
kernel                        | module.c          | MOD, manages, loads, unloads modules
