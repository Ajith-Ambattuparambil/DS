#include<stdio.h>
#include<stdlib.h>
//Declaring the node
struct node
   {
     int number;
     struct node *next;
   };
int search_value(struct node *list1,int num);

void append_node(struct node *list1, int num);

void display_list(struct node *list1);

void delete_node(struct node *list1,int num);
  
int main()
   {
      int num=0,input=1,retval=0;
      struct node *list1;
      list1=(struct node*) malloc(sizeof(struct node));
      list1->number=0;
      list1->next=NULL;
   
      while(input!=0)
         {
            printf("\n--Menu Selection --\n");
            printf("0)Quit\n");
            printf("1)Insert\n");
            printf("2)Delete\n");
            printf("3)Search\n");
            printf("4)Display\n");
            scanf("%d",&input);
            
            switch(input)
                {
                case 0:
                printf("Bye\n");
                input=0;
                break;
                
                case 1:
                printf("Your choice is 'insertion'\n");
                printf("Enter the value to be inserted: ");
                scanf("%d",&num);
                append_node(list1,num);
                break;
                
                case 2:
                printf("Your choice is 'Deletion'\n");
                printf("Enter the value to be deleted: ");
                scanf("%d",&num);
                delete_node(list1,num);
                break;
                
                case 3:
                printf("Your choice is 'Search'\n");
                printf("Enter the value you want to find: ");
                scanf("%d",&num);
                if((retval=search_value(list1,num))==-1)
                printf("Value '%d' not found\n",num);
                else
                printf("Value '%d' located at position '%d'\n",num,retval);
                break;
                
                case 4:
                printf("Your choice is 'Display'\n");
                display_list(list1);
                break;
                
               default: printf("Not a valid option selected");
             }  /*Switch closed*/
          } /*while closed*/       
      free(list1);
      return (0);    
   }   
   
void display_list(struct node *list1)
   { 
      list1=list1->next;
      while(list1->next!=NULL)
         {
             printf("%d ",list1->number);
             list1=list1->next;
         }
      printf("%d ",list1->number);
   }
   
void append_node(struct node *list1,int num)
   {
      while(list1->next!=NULL)
      list1=list1->next;
      
      list1->next=(struct node *)malloc(sizeof(struct node));
      list1->next->number=num;
      list1->next->next=NULL;
   }
   
void delete_node(struct node *list1,int num)
   {
      struct node *temp;
      temp=(struct node*)malloc(sizeof(struct node));
      if(list1->number==num)
         {
            //Remove the node
            temp=list1->next;
            free(list1);
            list1=temp;
         }
      else
         {
            while(list1->next->number!=num)list1=list1->next;
            temp=list1->next->next;
            free(list1->next);
            list1->next=temp;
         }
   }
   
int search_value(struct node *list1,int num)
   {
       int retval=-1;
       int i=1;
       while(list1->next!=NULL)
          {
             if(list1->next->number==num)
             return i;
             else
             i++;
             list1=list1->next;
          }
      return retval;
   }                             
              
               
