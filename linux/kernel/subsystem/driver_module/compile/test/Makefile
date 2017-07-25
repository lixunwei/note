KVERS = $(shell uname -r)
obj-m += mutex.o

build:kernel_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
clean:
    make -C /lib/modules/$(kVERS)/build M=$(CURDIR) clean
