#include <stdio.h>
struct list_head {
	struct list_head *next, *prev;
};

void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)
//---------------------------------------------------------------
typedef struct
{
	int sid;
	struct list_head node;
}SAWON;

void display( struct list_head *head )
{
	struct list_head *temp;
	SAWON *s;
	printf("[head]");
	for( temp = head->next; temp != head; temp=temp->next )
	{
		s = list_entry(temp, SAWON, node );
		printf("<->[%d]", s->sid);
	}
	printf("<->[head]\n");
}

int main()
{
	SAWON s[7];
	int i;
	LIST_HEAD(head);
	for(i=0; i<7; i++)
	{
		s[i].sid = i+1000;
		list_add_tail( &s[i].node, &head );
	}
	display(&head);
	return 0;
}
