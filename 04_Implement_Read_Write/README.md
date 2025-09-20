# Building
```
make
```

# Insert
```
$ sudo insmod ldd.ko

$ sudo dmesg 
[  766.696838] ldd: loading out-of-tree module taints kernel.
[  766.697403] ldd: module verification failed: signature and/or required key missing - tainting kernel
[  766.748542] Ruturaj: my_module_init Entry
[  766.748834] Ruturaj: my_module_init Exit
```

```
ruturaj@debian:~/LinuxKernelModules/02_Proc_File_Creation$ sudo insmod ldd.ko 
ruturaj@debian:~/LinuxKernelModules/02_Proc_File_Creation$ ls -ltr /proc | grep ldd
-r--r--r--  1 root             root                           0 Sep 20 23:45 ldd_driver
```

# Remove
```
ruturaj@debian:~/LinuxKernelModules/02_Proc_File_Creation$ sudo rmmod ldd
ruturaj@debian:~/LinuxKernelModules/02_Proc_File_Creation$ sudo dmesg
[  766.696838] ldd: loading out-of-tree module taints kernel.
[  766.697403] ldd: module verification failed: signature and/or required key missing - tainting kernel
[  766.748542] Ruturaj: my_module_init Entry
[  766.748834] Ruturaj: my_module_init Exit
[  794.786325] Ruturaj: my_module_exit Entry
[  794.786330] Ruturaj: my_module_exit Exit
```

```
ruturaj@debian:~/LinuxKernelModules/02_Proc_File_Creation$ ls -ltr /proc | grep ldd
```