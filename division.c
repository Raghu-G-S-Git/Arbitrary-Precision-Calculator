/*******************************************************************************************************************************************************************
*Title			 : Division
*Description	 : This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		 : int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

void division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	long long int count = 0;

    while (1) 
	{
        // Count lengths
        int len1 = 0, len2 = 0;
        Dlist *temp1 = *head1, *temp2 = *head2;
        while (temp1) 
		{
            len1++;
            temp1 = temp1->next;
        }
        while (temp2) 
		{
            len2++;
            temp2 = temp2->next;
        }
        // Compare head1 and head2
        int is_less = 0, is_equal = 1;
        if(len1==0 || len2==0)	break;
        else if (len1 < len2)    break;
        else if (len1 == len2) 
		{
            temp1 = *head1;
            temp2 = *head2;
            while (temp1 && temp2) 
			{
                if (temp1->data < temp2->data) 
				{
                    is_less = 1;
                    is_equal = 0;
                    break;
                } 
				else if (temp1->data > temp2->data) 
				{
                    is_equal = 0;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            if (is_less) break;
            if (is_equal) 
			{
                count++;
                delete_list(head1, tail1);//Function for deleting
                break;
            }
        }
		// Subtract head2 from head1
        subtraction(head1, tail1, head2, tail2, headR, tailR);//Function call for subtraction
        delete_list(head1, tail1);//Function for deleting
        *head1 = *headR;
        *tail1 = *tailR;
        *headR = NULL;
        *tailR = NULL;
		
        count++;

        if (*head1 == NULL)
            break;
    }

	delete_list(headR, tailR);
	
    while(count)
    {
		insert_first(headR, tailR, count%10);
		count = count/10;
    }

}