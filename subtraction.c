/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int borrow = 0, result = 0;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	
	while (temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL &&  temp2 != NULL)
		{
			if(temp1->data >= temp2->data)
			{
				result = temp1->data - temp2->data - borrow;
				borrow = 0;
			}
			else
			{
				result = (temp1->data + 10) - temp2->data - borrow;
				borrow = 1;
			}

			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else
		{
			if(temp1->data == 0 && borrow == 1)
			{
				result = 10 - borrow;
				borrow = 1;
			}
			else
			{
				result = temp1->data - borrow;
				borrow = 0;
			}

			temp1 = temp1->prev;
		}
		if(temp1 == NULL && temp2 == NULL && result%10 == 0)
			break;
		insert_first(headR,tailR,result%10);
	}
	
}
