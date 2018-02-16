#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 500

/*	note that the problem specific chunks of code are:
	1. struct item
	2. intial variable
	2. the Show function
*/

typedef struct item {
	char dir[SIZE];
} Item ;

typedef struct node {
	struct node * prev ;
	struct node * next ;
	struct item data ;
} Node ;

typedef struct stack {
	struct node * head ;
	struct node * tail ;
	int size ;
} Stack ;

// ADT Function Prototypes:

void Initialize(Stack *);
/*	should be used immediately after creating a stack
	it sets (resets) all pointers to NULL and
	size variable to zero.							 */

void Pushin(Stack * , Item);
/*	this function is used to populate the stack with data	*/

Item Unpush(Stack *);
/*	this is used to get data from the stack */

void Traverse(Stack * , void (*)(Item*));
/*	the purpos of this function is to manipulate the whole stack
	with some specific Function 								 */

void Show(Stack *);
/*	this function shows the contents of the whole stack arranged from head
	to tail and seperated throgh (/) symbole								*/

void Destroy(Stack *);

Item initial = { "" } ;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    Item temp ;
    Item root = {"/"};
    char ins[10];
    char param[500];
    char test ;
    char * chunk ;
    int n , i ;
    Stack path ;

    Initialize(&path);
    Pushin(&path , root);

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%s", ins);

        if (ins[0] == 'c')
        {
            getchar();
            test = getchar();
            if (test == '/')
            {
                Destroy(&path);
                Initialize(&path);
                Pushin(&path , root);
            }
            ungetc(test , stdin);
            scanf("%s", param);
            chunk = strtok(param , "/");
            if (chunk[0] == '.')
                Unpush(&path);
            else
            {
                strcpy(temp.dir , chunk);
                Pushin(&path , temp);
            }
            while ((chunk = strtok(NULL , "/")) != NULL)
            {
                if (chunk[0] == '.')
                    Unpush(&path);
                else
                {
                strcpy(temp.dir , chunk);
                Pushin(&path , temp);
                }
            }
        }
        else
        {
            Show(&path);
            if ((i + 1) != n)
                putchar('\n');
        }
    }

    return 0 ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Initialize(Stack * arg)
{
	arg->head = NULL ;
	arg->tail = NULL ;
	arg->size = 0 ;
}

void Pushin(Stack * arg1 , Item arg2)
{
//	allocating the new node.
	Node * nptr = (Node *) malloc(sizeof(Node));

//  initializing the node.
    nptr->prev = nptr->next = NULL ;
    nptr->data = initial ;

//	checking if this is the first node and if so setting the head to it.
	if (arg1->head == NULL)
		arg1->head = nptr ;

//	getting the node information.
	nptr->prev = arg1->tail ;
	nptr->data = arg2 ;

//	changing the previous node accordingly.
	if (arg1->size != 0)
		arg1->tail->next = nptr ;

//	changing the stack accordingly.
	++arg1->size ;
	arg1->tail = nptr ;
}

Item Unpush(Stack * arg)
{
//	allocating the needed variables.
	Item data = arg->tail->data ;
	Node * nptr = arg->tail ;

//	changing the stack accordingly.
	arg->tail = arg->tail->prev ;
	--arg->size ;
	if (arg->size == 0)
		arg->head = NULL ;

//	changing the previous node accordingly
	arg->tail->next = NULL ;

//	freeing the allocated memory.
	free(nptr);

//	returning the desiered data
	return data ;
}

void Traverse(Stack * arg , void (* func)(Item *))
{
//	allocating the needed variables.
	Node * nptr = arg->head ;

//	traversing the stack.
	while (nptr != NULL)
	{
		func(&nptr->data);
		nptr = nptr->next ;
	}
}

void Show(Stack * arg)
{
//	allocating the needed variables
	Node * nptr = arg->head ;

//	traversing the stack and displaying every node data.
	while (nptr != NULL)
	{
	//	showing the information.
		printf("%s", nptr->data.dir);
		if (nptr != arg->head)
            putchar('/');

		nptr = nptr->next ;
	}
}

void Destroy(Stack * arg)
{
//	allocating the needed variables
	Node * nptr1 = arg->head ;
	Node * nptr2 = nptr1 ;

//	traversing the stack and destroying every node.
	while (nptr1 != NULL)
	{
		nptr1 = nptr1->next ;
		free(nptr2);
		nptr2 = nptr1 ;
	}
}
