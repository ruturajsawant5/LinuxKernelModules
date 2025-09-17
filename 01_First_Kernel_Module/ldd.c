#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RUTURAJ");
MODULE_DESCRIPTION("First Kernel Module");

static int my_module_init(void)
{
    printk("Ruturaj: in my_module_init\n");
    return 0;
}

static void my_module_exit(void)
{
    printk("Ruturaj: in my_module_exit\n");
}

module_init(my_module_init);
module_exit(my_module_exit);