# Linux Kernel Modules

A hands-on exploration of Linux Loadable Kernel Module (LKM) development. This repository walks through the fundamentals of writing, building, and interacting with kernel modules — starting from a minimal "hello world" module and progressively building up to a fully functional `/proc` filesystem driver with read and write support.

## Overview

Each directory is a self-contained module that builds on the concepts introduced in the previous one:

| # | Directory | Topic | Key Concepts |
|---|-----------|-------|--------------|
| 01 | [First Kernel Module](./01_First_Kernel_Module) | Minimal loadable module | `module_init`, `module_exit`, `printk`, `MODULE_LICENSE` |
| 02 | [Proc File Creation](./02_Proc_File_Creation) | Creating a `/proc` entry | `proc_create`, `proc_remove`, `struct proc_ops` |
| 03 | [Implement Read](./03_Implement_Read) | Reading from `/proc` | `proc_read` callback, `copy_to_user`, offset handling |
| 04 | [Implement Read Write](./04_Implement_Read_Write) | Reading & writing to `/proc` | `proc_write` callback, `copy_from_user`, bidirectional I/O |

## Prerequisites

- Linux system with kernel headers installed
- `make` and `gcc` build tools
- Root privileges (for `insmod` / `rmmod`)

```bash
# Debian / Ubuntu
sudo apt install build-essential linux-headers-$(uname -r)
```

## Quick Start

Each module follows the same workflow:

```bash
# 1. Build the module
cd 01_First_Kernel_Module
make

# 2. Insert the module into the running kernel
sudo insmod ldd.ko

# 3. Check kernel log for module output
sudo dmesg | tail

# 4. Remove the module
sudo rmmod ldd

# 5. Clean build artifacts
make clean
```

## Module Details

### 01 — First Kernel Module

The simplest possible kernel module. Registers `init` and `exit` functions that print messages to the kernel log via `printk`.

```c
module_init(my_module_init);   // Called on insmod
module_exit(my_module_exit);   // Called on rmmod
```

### 02 — Proc File Creation

Extends the first module by creating an entry at `/proc/ldd_driver` using `proc_create()`. The entry appears when the module is loaded and is removed on unload via `proc_remove()`.

```bash
# After insmod:
ls -ltr /proc | grep ldd
# -r--r--r--  1 root root 0  ...  ldd_driver
```

### 03 — Implement Read

Adds a `proc_read` callback to the proc entry, allowing userspace programs to read data from the module. Uses `copy_to_user()` to safely transfer a kernel buffer to userspace.

```bash
cat /proc/ldd_driver
# There is a read
```

### 04 — Implement Read Write

Completes the proc interface by adding a `proc_write` callback alongside the existing read. Uses `copy_from_user()` to receive data from userspace and stores it in an internal buffer, which can then be read back.

```bash
echo "hello kernel" | sudo tee /proc/ldd_driver
cat /proc/ldd_driver
# hello kernel
```

## Useful Commands

| Command | Description |
|---------|-------------|
| `sudo insmod ldd.ko` | Load the kernel module |
| `sudo rmmod ldd` | Unload the kernel module |
| `sudo dmesg \| tail` | View recent kernel log messages |
| `sudo modinfo ldd.ko` | Display module metadata (author, license, etc.) |
| `lsmod \| grep ldd` | Check if the module is currently loaded |

## Environment

Developed and tested on:

- **OS:** Debian (kernel 6.12)
- **Arch:** x86_64
- **License:** GPL

## License

This project is licensed under the GNU General Public License v2.0 — see the [LICENSE](./LICENSE) file for details.