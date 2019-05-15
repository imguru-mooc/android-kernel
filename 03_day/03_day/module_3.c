#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	int value;
	printk("my_init()\n");
	value = gpio_get_value(170);
	printk("value=%d\n", value);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
}

module_init(my_init);
module_exit(my_exit);






