#include<stdio.h>
#include<stdlib.h>
struct node
      {
	 int data;
	 struct node *next;
      };
struct node *head=NULL;
struct node dummy;
void ins_strt()
     {  int input;
	struct node *temp;
	printf("\nEnter the value to input: ");
	scanf("%d",&input);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=input;
	temp->next=head;
	head=temp;
     }
void ins_end()
     {
	int input;
	struct node *ptr,*temp;
	printf("\nenter the value to input : ");
	scanf("%d",&input);
	 temp=(struct node*)malloc(sizeof(dummy));
	  temp->data=input;
	  temp->next=NULL;
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;
	    while(ptr->next!=NULL)
		{
		    ptr=ptr->next;
		}
	    ptr->next=temp;
	  }
     }
void ins_pos()
     {
	int data,pos,i;
	struct node *ptr,*swap,*temp;
	printf("\nEnter the value to input: ");
	scanf("%d",&data);
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	temp=(struct node*)malloc(sizeof(dummy));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	  {
	    head=temp;
	  }
	else
	  {
	    ptr=head;
	    for(i=1;i<(pos-1)&&(ptr->next!=NULL);i++)
	       {
		 printf("%d",ptr->data);
		 ptr=ptr->next;
	       }
	    if(i==(pos-1))
	       {
		 swap=ptr->next;
		 ptr->next=temp;
		 temp->next=swap;
	       }
	     else
	       
		 printf("invalid position");
	       
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
	     printf("\nLinked list is empty\n");
     }
void search()
	{
	  int data,i;
	  struct node *ptr;
	  ptr=head;
	  if(head!=NULL)
	  {
	  printf("Enter the element to be searched:\n");
	  scanf("%d",&data);
	  for(i=1;ptr->next!=NULL;i++)
	  	{
	  	   if(ptr->data==data)
	  		  printf("\nData found at position: %d \n",i);
	  	    ptr=ptr->next;
	  	}
	  if(ptr->data==data)
	  		  printf("\nData found at position %d \n",i);
	  else
	  printf("The value to be searched is not present in the program!!!");	
	  }	
	  else
	  printf("The list is empty!!!");
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
			   printf("\nDeleting element from position %d and value is %d",i,dlt->data);
			   if(dlt==head)
			     {head=NULL;
			      free(dlt);
				 }
				else
				  {
			        pre->next=NULL;
			        free(dlt);
				  }
			}
		else 
		    printf("The Linked list is empty");		
	}
void dlt_pos()
     {
		int pos,i=1;
		struct node *dlt,*pre;
		dlt=head;
		printf("Enter the postion of element to be deleted:\n");
		scanf("%d",&pos);
		if(dlt!=NULL)
		 {
			while(dlt->next!=NULL&&i<(pos))
			  {
				i++;
				pre=dlt;
				dlt=dlt->next;
				printf("\nDeleting element from position %d and value is %d",i,dlt->data);
			  }
			  if(i==pos && dlt==head)
			    {
					head=dlt->next;
					printf("Head is changed");
					printf("\nDeleting element from position %d and value is %d",i,dlt->data);
					free(dlt);
				}
			  else if(i==pos)
			    {
					pre->next=dlt->next;
					printf("\nDeleting element from position %d and value is %d",i,dlt->data);
					free(dlt);
				}
			  else
			      printf("Invalid position");	
		 }
		else
		printf("The linked list is empty"); 
	 }	
void dlt_strt()
	{
		struct node *dlt;
		dlt=head;
		if(dlt!=NULL)
		  {
			head=dlt->next;
			printf("\nDeleted element is %d \n",dlt->data);
			free(dlt);
		  }
		 else
		    printf("The linked list is empty") ;
	}		 
int main()
    {
	int choice;
	do{
	    printf("\n1. Add at start\n2. Add at position\n3. Add at end\n4. Display\n5. Delete from end\n6. Delete from start\n7. Delete at position \n8. Search for an element\n9. Exit");
	    printf("\nEnter your choice:\n");
	    scanf("%d",&choice);
	    switch(choice)
		{
		    case 1 : ins_strt();
			     break;
		    case 2 : ins_pos();
			     break;
		    case 3 : ins_end();
			     break;
		    case 4 : display();
			     break;
		    case 5 : dlt_end();
			     break;
	     	    case 6: dlt_strt();
			    break;
		    case 7: dlt_pos();
			   break;	
		    case 8: search();
		            break;	   	 
		    case 9 : printf("Exiting\n");
		            break;
		    default : printf("Invalid choice. If you want to exit please enter 8 as choice!!!");
		}
	}while(choice!=9);
	return 0;
    }
