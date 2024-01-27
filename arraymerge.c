#include <stdio.h>
#include <conio.h>
void main()
{

    int i, a[10], b[10], c[20], n1, n2, temp, k;
    printf("Enter the size of array 1\n");
    scanf("%d", &n1);
    printf("Enter the %d elements\n", n1);
    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("Array 1\n");
    for (i = 0; i < n1; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter the size of array 2\n");
    scanf("%d", &n2);
    printf("Enter the %d elements\n", n2);
    for (i = 0; i < n2; ++i)
    {
        scanf("%d", &b[i]);
    }
    printf("Array 2\n");
    for (i = 0; i < n2; ++i)
    {
        printf("%d ", b[i]);
    }
    i = 0;
    int j = 0;
    for (int i = 0; i < n1; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        c[n1 + i] = b[i];
    }
    k = n1 + n2;
    for (i = 0; i < k - 1; ++i)
    {
        for (int j = 0; j < k - i - 1; ++j)
        {
            if (c[j] > c[j + 1])
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    printf("\nMerged Array \n");
    for (i = 0; i < n1 + n2; ++i)
    {
        printf("%d ", c[i]);
    }
    getch();
}
