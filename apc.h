#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int flag = 0;
static int neg_flag1 = 0;
static int neg_flag2 = 0;

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int insert_last(Dlist **head, Dlist **tail, int data);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
void division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int insert_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int delete_list(Dlist **head, Dlist **tail);

#endif
