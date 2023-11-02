#include<stdio.h>
int u[10]={1,2,3,4,5,6,7,8,9,10};
void display(int *arr);
int main()
   {
      int universal[10]={1,1,1,1,1,1,1,1,1,1};
      int a[10]={1,1,1,0,0,0,1,0,0,1};
      int b[10]={1,0,0,1,0,0,1,1,1,0};
      int i,a_union_b[10],a_inter_b[10],a_differ_b[10],b_differ_a[10];
      printf("\n\t\t Universal set is:\n");
      display(universal);
      printf("\n\t\t Set A is:\n");
      display(a);
      printf("\n\t\t Set B is:\n");
      display(b);
      printf("\n\t\t A union B is:\n");
      for(i=0;i<10;i++)
          a_union_b[i]=a[i]||b[i];
          display(a_union_b);
      printf("\n\t\t A intersection B is:\n");
      for(i=0;i<10;i++)
          a_inter_b[i]=a[i]&&b[i];
          display(a_inter_b);    
      printf("\n\t\t The difference of A and B is:\n");
      for(i=0;i<10;i++)
          a_differ_b[i]=a[i]-b[i];
          display(a_differ_b);
      printf("\n\t\t The difference of A and B is:\n");
      for(i=0;i<10;i++)
          b_differ_a[i]=b[i]-a[i];
          display(b_differ_a);        
      return 0;
   }
void display(int *arr)
   {
      int *ar=arr,i;
      for(i=0;i<10;i++)
              {
            if(*ar==1)
            printf("%d \t",u[i]);
            ar++;
              }
   }          
          

