#include<stdio.h>
#include<conio.h>
void main()
  {
     int a,n,queue[10],front,rear,item,i;
     clrscr();
     front=rear=-1;
     printf("\nEnter the number of elements in the queue:\n");
     scanf("%d",&n);
     do
       {
	  printf("\nEnter the operation you want to perform:\n1.INSERTION \n2.DELETION \n3.DISPLAY \n4.EXIT\n");
	  scanf("%d",&a);
	  switch(a)
	    {
	      case 1:if(rear==n-1)
		     printf("\nQueue overflow");
		     else
		       {
			 if(front==-1)
			 front=0;
			 printf("\nEnter the item:");
			 scanf("\n%d",&item);
			 rear++;
			 queue[rear]=item;
			 printf("\n%d Inserted into the queue:",item);
		       }
		     break;
	      case 2:if(front==-1||front>rear)
		     printf("\nQueue underflow");
		     else
		       {
			  item=queue[front];
			  front++;
			  printf("\n%d is deleted\n",item);
		       }
		     break;
	      case 3:if(front==-1)
		     printf("Empty queue");
		     else
		       {
			 printf("\nQueue elements are:\t");
			 for(i=front;i<=rear;i++)
			 printf("\n%d\t",queue[i]);
		       }
		     printf("\n");
		     break;
	       case 4: exit();
	       default:printf("\nEnter a valid option");
	       break;
	   }
	 }
     while(1);
   getch();
 }

