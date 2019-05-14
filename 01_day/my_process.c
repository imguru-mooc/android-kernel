#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *temp;
	temp = current;
	printk("pid=%d, comm=%s\n", temp->pid, temp->comm );
	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);






