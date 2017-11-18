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
