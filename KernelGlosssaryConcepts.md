# Overview

This document contains common terms and concepts that are reference by the other documents in the LinuxKernelNotes repository

# References

* [KernelGlossary](https://kernelnewbies.org/KernelGlossary)

# Terminology and Concepts

Note some of these definitions are copied from [https://kernelnewbies.org/KernelGlossary](https://kernelnewbies.org/KernelGlossary)

* **ABI** - Application Binary Interface, the interface of passed structures between the user processes (and libraries) and the kernel. For compatibility, it is important that these remain as static as possible (i.e. making sure that variables and structure members have the same bytesize as before, and in the same ordering). Occasionally breakage is necessary, requiring re-compilation of the user-space sources (note that this does not affect source-compatibility; that is a separate issue).
* **BusyBox** - software that provides several stripped-down Unix tools in a single executable file. BusyBox originally aimed to put a complete bootable system on a single floppy disk that would serve both as a rescue disk and as an installer for the Debian distribution. Since that time, it has been extended to become the de facto standard core user space toolset for embedded Linux devices and Linux distribution installers. Since each Linux executable requires several kilobytes of overhead, having the BusyBox program combine over two hundred programs together often saves substantial disk space and system memory. (Wikipedia)
* **dmesg** - Command to display or clear messages from the kernel rign buffer.  The default action (no parameters) is to display all messages from the kernel ring buffer.
* **Logical Processor** - on an Intel processor this is the number of cores, times the number of hyper threads per core.  So an 8 core system, with 2 hyper threads per core would be a total of 16 logical processors.  See **Virtual Processor** for a virtual machine environment.
* **Mainline** - vanilla Linux Kernel, without any vendor/distribution specific code or drivers. This branch is officially released as a new version approximately every ten weeks.  This is not the same as the **stable version**, which has been more thoroughly tested over a longer period, but doesn't have the latest features and fixes that the **mainline** version has.
* **MMU** - Memory Management Unit, part of the CPU hardware that enforces memory boundaries, and throw page faults, upon which the OS builds its coherent protection. The MMU maps virtual memory to actual, where protections allow
* **Virtual Processor** = on a Hyper-V image you can have up to the total number of logical processors on your host (cores + hyper threads).  This total includes all virtual machines currently running, so if you have 16 logical host processors, you can have one virtual machine with 16 virtual processors, or two virtual machines with 8 virtual processors each, etc.  See **Logical Processor**
