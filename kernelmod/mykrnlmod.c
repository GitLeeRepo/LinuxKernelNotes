# mykrnlmod.c
# From: https://www.youtube.com/watch?v=Ni_FuuYmsHw&list=PLbzoR-pLrL6rr4Yn46TYDee--jzHhqdfQ&index=14
#       from the Linux Foundation.  It is just an intro, not the full course, and does not
#       have the full build details which are necessary to compile this, so at the moment
#       this is not usable.
#
#       Once built it is loadable with 'sudo /sbin/insmod mykrnlmod.ko'
#       and unloadable with 'sudo /sbin/rmmod mykrnlmod'

#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void) {
    pr_info("mykernlmod: module loaded at 0x%p\n", my_init);
    return 0;
}

static void __exit my_exit(void) {
    pr_info("mykernlmod: module unloaded from 0x%p\n", my_exit);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Traeven");
MODULE_LICENSE("GPL v2");
