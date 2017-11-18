// mykrnlmod.c
// From: https://www.youtube.com/watch?v=Ni_FuuYmsHw&list=PLbzoR-pLrL6rr4Yn46TYDee--jzHhqdfQ&index=14
//       from the Linux Foundation.  It is just an intro, not the full course, and does not
//       have the full build details which are necessary to compile this, so at the moment
//       this is not usable.
//
//       Once built it is loadable with 'sudo /sbin/insmod mykrnlmod.ko'
//       and unloadable with 'sudo /sbin/rmmod mykrnlmod'

#include <linux/module.h>
#include <linux/init.h>

static int my_init(void) {
    // two different output methods that display same thing when running 'dmesg'
    // at least when printk is using KERN_INFO, KEN_ALERT displays differently
    pr_info("pr:mykernlmod: module loaded at 0x%p\n", my_init);
    printk(KERN_INFO "pk:mykernlmod: module loaded at 0x%p\n", my_init);
    return 0;
}

static void my_exit(void) {
    // two different output methods that display same thing when running 'dmesg'
    // at least when printk is using KERN_INFO, KEN_ALERT displays differently
    pr_info("pr:mykernlmod: module unloaded from 0x%p\n", my_exit);
    printk(KERN_INFO "pk:mykernlmod: module unloaded from 0x%p\n", my_init);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Traeven");
MODULE_LICENSE("GPL v2");
