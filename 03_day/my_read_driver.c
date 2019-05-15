#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

int my_open (struct inode *inode, struct file *filp)
{
	printk("my_open()\n");
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
	put_user(77, (int*)buff);
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
	misc_register( &misc );
	return 0;
}

void my_exit(void)
{
	misc_deregister( &misc );
}

module_init(my_init);
module_exit(my_exit);






