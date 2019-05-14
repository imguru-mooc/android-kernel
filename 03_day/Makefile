obj-m = my_vmalloc.o

KDIR = /root/htc/flounder
PWD  = $(shell pwd)

default : 
	make -C $(KDIR)  SUBDIRS=$(PWD) modules

clean : 
	make -C $(KDIR)  SUBDIRS=$(PWD) clean
