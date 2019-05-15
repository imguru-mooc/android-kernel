#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/wait.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/input.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

static struct input_dev *my_input;
static void *dev = (void*)0x1234;

irqreturn_t my_irq_handler(int irq, void *id)
{
	int value;
	printk("my_irq_handler()\n");
	value = gpio_get_value(170);
	value = value ^ 1;
	if( value == 1 )
	{
		printk("Pressed Event!!\n");
		input_report_key(my_input, KEY_VOLUMEUP, value);
		input_sync(my_input);
	}
	else
	{
		printk("Released Event!!\n");
		input_report_key(my_input, KEY_VOLUMEUP, value);
		input_sync(my_input);
	}
	return IRQ_HANDLED;
}

int my_init(void)
{
	int ret;
	unsigned long flags=0x83;

	my_input = input_allocate_device();

	__set_bit( EV_KEY , my_input->evbit);
	__set_bit( KEY_VOLUMEUP, my_input->keybit);
	ret = input_register_device(my_input);
	ret = request_irq(379, my_irq_handler, flags, "MY INT", dev);
	return 0;
}

void my_exit(void)
{
	input_unregister_device(my_input);
	free_irq(379, dev);
}

module_init(my_init);
module_exit(my_exit);






