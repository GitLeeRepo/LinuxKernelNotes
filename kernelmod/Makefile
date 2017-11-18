obj-m += Hello.o

KDIR = /usr/src/linux-headers-

all:
    $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
    rm -rf *.o *.ko *.mod *.symvers *.order

