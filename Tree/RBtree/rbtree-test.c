
#include <stdio.h>
#include "rbtree.h"
#include <stdlib.h>
#include <time.h>

struct mytype {
	struct rb_node node;
	int key;
};

struct rb_root mytree = RB_ROOT;

/** Same as binary sort tree**/
struct mytype *my_search(struct rb_root *root, int key)
{
	struct rb_node *node = root->rb_node;
	struct mytype *data;

	while (node) {
		data = container_of(node, struct mytype, node);
		int result;

		if(key < data->key) 
			node = node->rb_left;
		else if(key > data->key) 
			node = node->rb_right;
		else 
			return data;
	} 

	return NULL;
}

int my_insert(struct rb_root *root, struct mytype *data)
{
	struct rb_node **new = &(root->rb_node), *parent = NULL;
	struct mytype *this;
	/* Figure out where to put new node */

	while (*new) {
		this = container_of(*new, struct mytype, node);
		int result;

		parent = *new;

		if(this->key > data->key) 
			new = &((*new)->rb_left);
		else if(this->key  < data->key) 
			new = &((*new)->rb_right);
		else 
			return 0;
	}

	/* Add new node and rebalance tree. */
	rb_link_node(&(data->node), parent, new);
	print_tree(&mytree);
	rb_insert_color(&(data->node), root);

	print_tree(&mytree);

	return 1;
}

//int array[]={13,15,11,8,17,1,6,22,25,27};    //上图所示红黑树实例
//int array[]={1,2,3,4,5,6,7,8,9};    //上图所示红黑树实例
int array[]={1,2,3,8,6,5,7,9};

#define TAB_SIZE(array) (sizeof(array)/sizeof(array[0])) 

void padding ( char ch, int n )
{
	int i;

	if(n>0)
	{
		for ( i = 0; i < (n-1); i++ )
		printf ( "%c",ch );
		printf ( "--------" );
	}
}

void print_node ( struct rb_node *node, int level )
{
	if ( node == NULL )
	{
		padding ( '\t', level );
		printf ( "\033[42;37m%s\033[0m\n", "null" );
	}
	else
	{
		print_node ( node->rb_right, level + 1 );
		padding ( '\t', level );

		if(rb_is_black(node))
		{
			struct mytype *black = container_of(node, struct mytype, node);
			printf ( "\033[47;30m%3d\033[0m\n", black->key );
		}
		else
		{
			struct mytype *red = container_of(node, struct mytype, node);
			printf ( "\033[41;37m%3d\033[0m\n", red->key );
		}

		print_node ( node->rb_left, level + 1 );
	}
}

void print_tree(struct rb_root* tree)
{
    printf("-------------------------------------------\n");
	print_node(tree->rb_node,0);
	printf("-------------------------------------------\n");
}

int  main(void)
{
	struct rb_node *node;
	struct mytype *mynode;
	int i;

	for(i = 0; i < TAB_SIZE(array); i++)
	{
		mynode = malloc(sizeof(struct mytype));
		//array[i]=(rand()%100);
		mynode->key= array[i];
		printf("i = %d, key is %d\n", i,mynode->key);
		my_insert(&mytree, mynode); 
	}


	printf("*********** Up ****************************\n");

	i = 0;
	for(node = rb_first(&mytree); node; node = rb_next(node))
	{
		printf("i = %d, key = %d\n", i, (rb_entry(node, struct mytype, node))->key);
		i++;
	}

	printf("------------Down---------------------------\n");

	i = 0;
	for(node = rb_last(&mytree); node; node = rb_prev(node))
	{
		printf("i = %d, key = %d\n", i, (rb_entry(node, struct mytype, node))->key);
		i++;
	}
		    /*
	printk("------------Erase and Up---------------------------\n");
	mynode = my_search(&mytree, array[2]);
	if(mynode) 
	{
	rb_erase(&(mynode->node), &mytree);
	kfree(mynode);
	printk("Erased %d node !\n",array[2]);
	}
	*/

	print_tree(&mytree);
	printf("-------------------------------------------------------\n"); 

	return 0;
}

