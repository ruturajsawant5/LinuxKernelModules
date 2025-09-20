#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
//#include <string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RUTURAJ");
MODULE_DESCRIPTION("First Kernel Module");

ssize_t my_proc_read(struct file* name, char* user_space_buffer, size_t count, loff_t* offset);
ssize_t my_proc_write(struct file* name, const char* user_space_buffer, size_t count, loff_t* offset);

static struct proc_dir_entry* my_proc_entry;
static struct proc_ops my_proc_fops ={
    .proc_read = my_proc_read,
    .proc_write = my_proc_write
};
static char buffer[1024];

static int my_module_init(void)
{
    printk("Ruturaj: my_module_init Entry\n");

    my_proc_entry = proc_create("ldd_driver",   //const char *name, 
                                0,              //umode_t mode, 
                                NULL,           //struct proc_dir_entry *parent, 
                                &my_proc_fops); //struct proc_ops *proc_fops
    
    printk("Ruturaj: my_module_init Exit\n");
    return 0;
}

static void my_module_exit(void)
{
    printk("Ruturaj: my_module_exit Entry\n");

    proc_remove(my_proc_entry);

    printk("Ruturaj: my_module_exit Exit\n");
}

ssize_t my_proc_read(struct file* name, 
                    char* user_space_buffer, 
                    size_t count, 
                    loff_t* offset)
{
    //strcpy(buffer, "There is a read\n");
    //not handling offset properly
    size_t len = strlen(buffer);
    
    if(*offset >= len)
        return 0;

    copy_to_user(user_space_buffer, buffer, len);
    *offset = len;
    printk("Did a little read\n");

    return len;
}

ssize_t my_proc_write(struct file* name, const char* user_space_buffer, size_t count, loff_t* offset)
{
    copy_from_user(buffer, user_space_buffer, count);
    buffer[count] = '\0';
    printk("Did a little write");
    return count;
}

module_init(my_module_init);
module_exit(my_module_exit);