# Overview

Notes on the Linux Kernel, Modules, and Device drivers

# References

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

# Importand Directories and Files

Refer to my separate [KernelDirectoriesAndFiles](https://github.com/GitLeeRepo/LinuxKernelNotes/blob/master/KernelDirectoriesAndFiles.md#overview) document

# Interesting Kernel Code to Study

**KEY**
* EBP - Early Boot Process

Directory                     | File              | Description 
------------------------------|-------------------|------------------------------------------------------------------------
arch/x86/boot                 | main.c            | EBP, Real mode boot code, calls to protected mode at end
arch/x86/boot                 | pm.c              | EBP, disables intrupts and switches to protected mode
arch/x86/include/uapi/asm     | boot_parms.h      | EBP, header defining boot_parms struct
init                          | main.c            | EBP, starts init
init                          | initramefs.c      | EBP, load initramfs
intit                         | do_mounts.c       | EBP, load ramdisk, mount & init root 
