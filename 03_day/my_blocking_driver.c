#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/wait.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

static int k_temp;
static DECLARE_WAIT_QUEUE_HEAD(my_wait);
static void *dev = (void*)0x1234;

irqreturn_t my_irq_handler(int irq, void *id)
{
	int value;
	printk("my_irq_handler()\n");
	value = gpio_get_value(170);
	if( value == 0 )
	{
		printk("Pressed Event!!\n");
		k_temp=23;
		wake_up_interruptible(&my_wait);
	}
	else
		printk("Released Event!!\n");
	return IRQ_HANDLED;
}

int my_open (struct inode *inode, struct file *filp)
{
	printk("my_open()\n");
	k_temp = -999;
	return 0;
}

int my_close (struct inode *inode, struct file *filp)
{
	printk("my_close()\n");
	return 0;
}

ssize_t my_read (struct file *filp, char __user *buff, size_t size, loff_t *off)
{
	printk("my_read()\n");
	if( k_temp == -999 )
		interruptible_sleep_on(&my_wait);
	put_user(k_temp, (int*)buff);
	return size;
}

static struct file_operations fops = 
{
	.open    = my_open,
	.read    = my_read,
	.release = my_close,
};

static struct miscdevice misc = 
{
	.minor = MISC_DYNAMIC_MINOR, 
	.name = "mydev",
	.fops = &fops,
};

int my_init(void)
{
	int ret;
	unsigned long flags=0x83;
	misc_register( &misc );
	ret = request_irq(379, my_irq_handler, flags, "MY INT", dev);
	return 0;
}

void my_exit(void)
{
	misc_deregister( &misc );
	free_irq(379, dev);
}

module_init(my_init);
module_exit(my_exit);






