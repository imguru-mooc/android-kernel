#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

int init_module(void)
{
	int value;
	printk("init_module()\n");
	value = gpio_get_value(170);
	printk("value=%d\n", value);
	return 0;
}

void cleanup_module(void)
{
	printk("cleanup_module()\n");
}
