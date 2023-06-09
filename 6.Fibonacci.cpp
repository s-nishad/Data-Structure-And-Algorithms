#include<stdio.h>
#include <iostream>

using namespace std;

void fibonacci(int n)
{
    int n1=0, n2=1,n3,sum=1;
    for(int i=2; i<n; i++)
    {
        n3 = n1+n2;
        n1 = n2;
        n2 = n3;

        sum = sum + n3;

        printf("%d ",n3);
    }
    printf("\nSum is %d",sum);
}

int main()
{
    int x;
    cout << "Enter the number of element: ";
    scanf("%d", &x);
    printf("Fibonacci Series: 0 1 ");
    fibonacci(x);
    return 0;
}
