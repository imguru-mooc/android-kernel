#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	char *p;
	p = (char*)kmalloc( 32, GFP_KERNEL);  
	p[0]    = 'a';
	p[31]   = 'z';
	printk("%c - %c\n", p[0], p[31] );
	kfree( p );
	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);






