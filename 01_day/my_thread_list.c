#if 1
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");

int my_init(void)
{
	struct task_struct *g, *t;
	do_each_thread(g,t)
	{
		if( g==t )
			printk("tgid=%5d, pid=%5d, comm=%s\n", g->tgid, g->pid, g->comm );
		else 
			printk("\ttgid=%5d, pid=%5d, comm=%s\n", t->tgid, t->pid, t->comm );
	}while_each_thread(g,t);

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
	struct task_struct *g, *t;
	struct list_head *temp;
	for_each_process(g)
	{
		printk("tgid=%5d, pid=%5d, comm=%s\n", g->tgid, g->pid, g->comm );
		for( temp = g->thread_group.next;
			 temp != &g->thread_group;
			 temp = temp->next )
		{
			t = list_entry( temp, struct task_struct, thread_group);
			printk("\ttgid=%5d, pid=%5d, comm=%s\n", t->tgid, t->pid, t->comm );
		}
	}

	return 0;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
#endif






