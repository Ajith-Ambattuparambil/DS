#include<stdio.h>
int front=-1,rear=-1,max,item;
int queue[20];
void insert();
void deletion();
void search();
void display();
int main()
   {
      int choice;
      printf("Enter the size of the Queue: ");
      scanf("%d",&max);
      do
             {
           printf("\nEnter the choice:\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n5. Exit!\n"); 
           scanf("%d",&choice);
           switch(choice)
                      {
                case 1: insert();
                        break;
                case 2: deletion();
                        break;
                case 3: search();         
                        break;
                case 4: display();
                        break;
                case 5: printf("Exiting as per wish!");
                        break;
                default: printf("\nInvalid choice. Please check the menu again!!!");
                        break;
                  }           
         }                           
     while(choice!=5);
     return 0;     
   }
void insert()
   {
     int temprear=rear;
     printf("\nrear=%d",rear);
     rear=(rear+1)%(max);
     printf("\nrear=%d",rear);
     printf("\nmax= %d",max);
     printf("\nfront=%d",front);
    if(front==-1)
        {
           front=0;
           rear=0;
           printf("\nEnter the element to insert:\n");
           scanf("%d",&item);
           queue[rear]=item;
        }
    else if(rear==front)
        {
            printf("\nQueue overflow\n");
            rear=temprear;
        }
    else
        {  
            printf("\nEnter the element to insert:\n");
            scanf("%d",&item);
            queue[rear]=item;
        }
}
void deletion()
   {
   
     if(front==-1)
     printf("\nQueue underflow\n");
     else if(front==rear)
        {
        printf("\nDelete element %d",queue[front]);
        front=-1;
        rear=-1;
        }
        else
            {  
             front=(front+1)%max;
                printf("\nDeleted the element %d",queue[front]);
            }
   }         
void search()
   {               
        int data,i=1,dfront=front;
        printf("\nEnter the element to search:\n");
        scanf("%d",&data);
        if(front==-1)
                printf("\nQueue is empty\n");
        else
           {
              for(;dfront!=rear;dfront=((dfront+1)%(max)))
                                  {
                    if(queue[dfront]==data)
                    printf("\nElement fount at %d th position",i);
                     i++;
                                 }
                  if(queue[dfront]==data)
                  printf("\nElement fount at %d th position",i);
                }
      }   
void display()
    {
        int i=front;
        printf("front=%d \n rear=%d",front,rear);
        if(front==-1)
            {
                printf("\nQueue is empty\n");
            }
        else
            {
                for(;i!=rear;i=((i+1)%(max)))
                {
                    printf("\n%d",queue[i]);
                }
                 printf("\n%d",queue[i]);
            }
    }          
            
