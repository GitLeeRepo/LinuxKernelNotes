obj-m += mykrnlmod.o

KDIR=/home/tracy/source/kernel/linux-4.14

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order

