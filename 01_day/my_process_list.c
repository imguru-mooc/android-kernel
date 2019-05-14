#if 1
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	for_each_process(p)
		printk("pid=%5d, comm=%s\n", p->pid, p->comm );

	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
#endif
#if 0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	struct list_head *temp;
	for( temp = init_task.tasks.next;
			temp != &init_task.tasks;
			temp = temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("pid=%5d, comm=%s\n", p->pid, p->comm );
	}

	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
#endif
#if 0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *p;
	struct list_head *temp;
	for( temp = current->tasks.next;
			temp != &current->tasks;
			temp = temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("pid=%5d, comm=%s\n", p->pid, p->comm );
	}
	p = list_entry( temp, struct task_struct, tasks );
	printk("pid=%5d, comm=%s\n", p->pid, p->comm );

	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
#endif






