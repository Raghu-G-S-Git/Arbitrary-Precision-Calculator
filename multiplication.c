/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int carry = 0,result = 0;;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	Dlist *headR1 = NULL, *tailR1 = NULL;
	Dlist *headR2 = NULL, *tailR2 = NULL;


	temp1 = *tail1;
	for(int j=0; temp1 != NULL; j++)
	{
		result = (temp1->data * temp2->data + carry);
		carry = 0;
		if(result > 9)
		{
			carry = result / 10;
			result %= 10;
		}				
		insert_first(&headR1,&tailR1,result);
		temp1 = temp1->prev;
	}
	if(carry)
	{
		insert_first(&headR1,&tailR1,carry);
	}
	
	temp2 = temp2->prev;		

	for(int i=0; temp2 != NULL ; i++)
	{
		carry = 0;	
		temp1 = *tail1;	
		
		for(int k=0; k<=i; k++)
		{
			insert_first(&headR2,&tailR2,0);
		}
		while(temp1 != NULL)
		{
			result = (temp1->data * temp2->data + carry);
			carry = 0;
			if(result > 9)
			{
				carry = result / 10;
				result %= 10;
			}
			insert_first(&headR2,&tailR2,result);
			temp1 = temp1->prev;
	 	}
		if(carry)
		{
			insert_first(&headR2,&tailR2,carry);
		}

		addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

		temp2 = temp2->prev;

		delete_list(&headR1,&tailR1);
		delete_list(&headR2,&tailR2);

		headR1 = *headR;
		tailR1 = *tailR;
		*headR = NULL;
		*tailR = NULL;
	}	
	
	*headR = headR1;
	*tailR = tailR1;
}
