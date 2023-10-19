#include<stdio.h>
int main()
  {
    int i,item,a[10],n,k=0,option,m,h,l=0;
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    printf("\nEnter the elements in the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    do
      {
        printf("\nSelect the search operation you want to perform:\n1. Linear search\n2. Binary search\n3. Exit\n");
        scanf("%d",&option);
        printf("\nWhich element do you want to search?:\n");
        scanf("%d",&item);
        switch(option)
           {
              case 1:
              for(i=0;i<n;i++)
                 {
                     if(a[i]==item)
	                      {
                           printf("Search for item %d successful at the index %d\n",item,i+1);
                           k++;
                           break;
	                      }
                  }
             if(k==0)
             printf("Item not found!!!\n");
             break;
             case 2:   
             h=n-1;
             m=(l+h)/2;
             while(l<=h)
                {
                   if(a[m]==item)
                      {                
                          printf("Search for %d successful, Found at location %d\n", item, m+1);
                          break;
                      }
            else if(item<a[m])
            h=m-1;
            else if(item>a[m])
            l=m+1;
            m=(l+h)/2;
                }
            if(l>h)
            printf("Not found!%d is not present in the list\n",item);
            break;
   case 3:
       printf("Exiting!");
       break;
   default:
      printf("Invalid option!\n");
          }
  }
while(option!=3);  
return 0;
}
