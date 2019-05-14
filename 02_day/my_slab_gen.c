#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

typedef struct
{
	int gpio;
	char name[200];
} DEV_INFO;

static struct kmem_cache *my_struct_cachep;

#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)
#define ARCH_MIN_TASKALIGN	L1_CACHE_BYTES

int my_init(void)
{
	DEV_INFO *p;
	my_struct_cachep =
		kmem_cache_create("my_struct", sizeof(DEV_INFO),
			1, SLAB_PANIC | SLAB_NOTRACK, NULL);
	p = kmem_cache_alloc(my_struct_cachep, GFP_KERNEL);
	p->gpio = 190;
	strcpy(p->name, "mydev");
	printk("gpio=%d, name=%s\n", p->gpio, p->name );
	kmem_cache_free(my_struct_cachep, p);
	return 0;
}

void my_exit(void)
{
	kmem_cache_destroy(my_struct_cachep);
}

module_init(my_init);
module_exit(my_exit);






