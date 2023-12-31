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
	printf("\nEnter the value to input : ");
	scanf("%d",&data);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=NULL;
	  //if the linkedlist is empty, then temp has the address of the first element so we asign the address to head
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;
	    //To find the last element in linked list we go through the linked list until we find the pointer with null which indicate the last element
	    while(ptr->next!=NULL)
		    ptr=ptr->next;
	    //Then we assign the address of new now(temp) to the pointer of last not which means the new node is connected to last node
	    ptr->next=temp;
	  }
     }
void display()
     {
	int i=1; // Start counting elements
	struct node *ptr; // Declare a pointer to a node
	ptr=head; // Start at the head of the list
	if(ptr!=NULL) // Check if the list is not empty
	  {
	    while(ptr->next!=NULL) // Traverse through the lis
	      {
	       printf("Element at %d is %d \n",i,ptr->data); // Display element
	       ptr=ptr->next; // Move to the next node
	       i++; // Increment the counter
	      }
	    printf("Element at %d is %d \n",i,ptr->data); // Display the last element
	  }
	else
	     printf("\nLinked list is empty\n"); // The list is empty
     }
void dlt_end()
    {
		struct node *dlt,*pre;  // Struct pointer to node, points to last node
		pre=NULL;
		dlt=head;
		int i=0;
		if(dlt!=NULL) // If linked list is not empty
			{
			   while(dlt->next!=NULL) // Loop until the end of linked list is reached
			       {
				    pre=dlt;
			     	dlt=dlt->next;
					i=i+1;
			       }
			   printf("\nDeleting the element %d",dlt->data); // Delete last node and update list
			   if(dlt==head)
			     {head=NULL;
			      free(dlt);
				 }
				else
			        pre->next=NULL;  
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
		    default : printf("Invalid choice. If you want to exit please enter 4 as choice!!!");

		}
	}
	while(choice!=4);
	return 0;
}
