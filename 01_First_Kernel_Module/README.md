# Building
```
make
```

# Insert
```
$ sudo insmod ldd.ko

$ sudo dmesg 
[ 1339.274826] ldd: loading out-of-tree module taints kernel.
[ 1339.275383] ldd: module verification failed: signature and/or required key missing - tainting kernel
[ 1339.317075] Ruturaj: in my_module_init
```

# Remove
```
$ sudo rmmod ldd.ko
$ sudo dmesg 
[ 1339.274826] ldd: loading out-of-tree module taints kernel.
[ 1339.275383] ldd: module verification failed: signature and/or required key missing - tainting kernel
[ 1339.317075] Ruturaj: in my_module_init
[ 1347.927387] Ruturaj: in my_module_exit
```

# modinfo
```
$ sudo modinfo ldd.ko
filename:       /home/ruturaj/LinuxKernelModules/01_First_Kernel_Module/ldd.ko
description:    First Kernel Module
author:         RUTURAJ
license:        GPL
depends:        
name:           ldd
retpoline:      Y
vermagic:       6.12.43+deb13-amd64 SMP preempt mod_unload modversions
```