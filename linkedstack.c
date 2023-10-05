#include<stdio.h>
#include<stdlib.h>
struct node
      {
	 int data;
	 // creating a node(struct) pointer to point next element of linked list;
	 struct node *next;
      };
 struct node *head=NULL;
 struct node dummy;
void ins_end()
     {
	int data;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&data);
	 temp=(struct node*)malloc(sizeof(dummy));
	  temp->data=data;
	  temp->next=NULL;
	  //if the linkedlist is empty .then temp has the adress of the first element so we asign the adress to head
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;
	    //to find the last element in linked list we go trough the linked list until we find the pointer with null which indicate the last element
	    while(ptr->next!=NULL)
		{
		    ptr=ptr->next;
		}
	    //then we asign the adress of new now(temp) to the pointer of last not which means the new node is connected to last node
	    ptr->next=temp;
	  }
     }
void display()
     {
	int i=1;
	struct node *ptr;
	ptr=head;
	if(ptr!=NULL)
	  {
	    while(ptr->next!=NULL)
	      {
	       printf("Element at %d is %d \n",i,ptr->data);
	       ptr=ptr->next;
	       i++;
	      }
	    printf("Element at %d is %d \n",i,ptr->data);
	  }
	else
	   {
	     printf("\nLinked list is empty\n");
	   }


     }
void dlt_end()
    {
		struct node *dlt,*pre;
		pre=NULL;
		dlt=head;
		int i=0;
		if(dlt!=NULL)
			{

			   while(dlt->next!=NULL)
			       {
				    pre=dlt;
			     	dlt=dlt->next;
					i=i+1;
			       }
			   printf("\nDeleting the element %d",dlt->data);
			   if(dlt==head)
			     {head=NULL;
			      free(dlt);
				 }
				else
				  {
			        pre->next=NULL;
				  }
			}
		else 
		    printf("The Linked list is empty");		
	}
int main()
    {
	int choice;
	do{
	    printf("\n1. Insert\n2. Display\n3. Delete \n4. Exit");
	    printf("\nEnter your choice:\n");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : ins_end();
			     break;
		    case 2 : display();
			     break;
		    case 3 : dlt_end();
			     break;	 
		    case 4 : printf("Exiting");
			   break;
		    default : printf("Invalid choice. If you want to exit please enter 8 as choice!!!");

		}
	}while(choice!=4);
	return 0;
}
