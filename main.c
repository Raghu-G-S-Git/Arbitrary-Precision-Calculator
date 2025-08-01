/**************************************************************************************************************************************************************
*Name 		: Raghu G S
*Objective 	: The objective of this project is to design and implement an Arbitrary Precision Calculator in the C programming language 
*			that can perform arithmetic operations (such as addition, subtraction, multiplication, and division) on numbers of unlimited 
*			length and precision, surpassing the limitations of built-in data types. This calculator utilizes custom data structures 
*			(e.g., linked lists or arrays) to represent and manipulate large numbers digit-by-digit or bit-by-bit, allowing accurate 
*			computation for scientific, financial, or cryptographic applications where standard types like int, long, or double are 
*			insufficient. The project emphasizes low-level memory management, algorithm optimization, and efficient handling of user 
*			input through a command-line interface.
*Title		: main function(Driver function)
*Description: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

int main()
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;
	char option, operator;

	do
	{
		/* Code for reading the inputs */
		int i=0;
		char optr1[100];
		char optr2[100];
		printf("Enter <operator1> <operand> <operator2>\n");
		scanf("%s %c %s",optr1,&operator,optr2);

		/* Function for extracting the operator */
		
		if(optr1[0] == '-')
		{
			neg_flag1 = 1;
			i++;
		}

		while(optr1[i] != '\0')
		{
			if(insert_last(&head1, &tail1, optr1[i] - '0') == FAILURE) return -1;
			i++;	
		}
		
		i=0;
		if(optr2[0] == '-')
		{
			neg_flag2 = 1;
			i++;
		}
		while(optr2[i] != '\0')
		{
				if(insert_last(&head2, &tail2, optr2[i] - '0') == FAILURE) return -1;
				i++;
		}
		

		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				flag = 0;

				if(neg_flag1 == 1 && neg_flag2 == 0)
				{
					addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					headR->data = -headR->data;
				}

				else if(neg_flag1 == 0 && neg_flag2 == 1)
				{
					addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					//headR->data = -headR->data;
				}

				else if(strlen(optr1) > strlen(optr2))
				{
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}

				else if(strlen(optr1) < strlen(optr2))
				{
					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
					if(!(neg_flag1 == 1 && neg_flag2 == 1))
						headR->data = -headR->data;
				}

				else
				{
					if(strcmp(optr1,optr2) > 0)
					{
						subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					}
					else if(strcmp(optr1,optr2) < 0)
					{
						subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
						if(!(neg_flag1 == 1 && neg_flag2 == 1))
							 headR->data = -headR->data;
					}
					else
					{
						break;
					}
				}
				if(neg_flag1 == 1 && neg_flag2 == 1 && (strlen(optr1) > strlen(optr2)))
				 	headR->data = -headR->data;


				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				if((neg_flag1 == 1 && neg_flag2 == 0) ||(neg_flag1 == 0 && neg_flag2 == 1))
					headR->data = -headR->data;
				break;
			case '/':	
				/* call the function to perform the division operation */
				division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		
		print_list(headR);
		printf("----------------------------------\n\n");
		printf("Want to continue? Press [yY | nN]: ");
		scanf("\n%c", &option);
		delete_list(&head1, &tail1);
		delete_list(&head2, &tail2);
		delete_list(&headR, &tailR);
		flag = 0;
		neg_flag1 = 0;
		neg_flag2 = 0;

	}while (option == 'y' || option == 'Y');

	return 0;
}

int insert_last(Dlist **head, Dlist **tail, int data)
{
    //Create the Node
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    //Update Node
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    
    //Check if the list is empty
    if(*head == NULL)
    {
        *head = new;        //Update Node for empty list
        *tail = new;
    }
    else
    {
        (*tail)->next = new;        //Update Node if Not empty
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}

int insert_first(Dlist **head, Dlist **tail, int data)
{
    //Create the Node
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    //Update Node
    new->data = data;
    new->prev = NULL;
    
    //Check if the list is empty 
    if(*head == NULL)
    {
        *head = new;        //Update Node for empty list
        new->next = NULL; 
        *tail = new;
    }
    else
    {
        (*head)->prev = new;    //Update Node if Not empty
        new->next = *head;
        *head = new;
    }
    return SUCCESS;

}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("0\n");
	}
	else
	{
	    //printf("Head -> ");
	    while (head != NULL)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
		printf("\n");
    }
}

int delete_list(Dlist **head, Dlist **tail)
{
    //Check if the list is empty
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    //Logic for deleting if only one element is present
    if(*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
        return SUCCESS;
    }
    
    //Logic for deleting if multiple elements are present
    Dlist *temp = *head;
    while(temp->next !=NULL)
    {
        temp = temp->next;
        free(temp->prev);
    }
    free(temp);
    *head = *tail = NULL;
    
    return SUCCESS;
}