#include<conio.h>
#include<stdio.h>
void main()
{
 int top,stack[50],n,i,item,c;
 clrscr();
 top=-1;
 printf("\nEnter the maximum size of the array: ");
 scanf("%d",&n);
  do
   {
    printf("\nEnter the operation\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    if(top==n-1)
    printf("\nOverflow");
    else
    {
      printf("\nEnter Element:");
      scanf("%d",&item);
      top++;
      stack[top]=item;
      printf("Element inserted:%d",item);
     }
    break;
   case 2:
   if(top==-1)
   printf("\nUnderflow");
   else
    {
     item=stack[top];
     top--;
     printf("\n");
     printf("Popped: %d",item);
    }
   break;
   case 3:
   printf("\nStack Elements:");
   for(i=0;i<=top;i++)
   printf("%d ",stack[i]);
   printf(" \n");
   break;
   case 4:exit();
   default:printf("\nEnter valid value");
  }
 }while(1);
 getch();
 }