#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A[] = {0,1,2,3,4,5,6,7,8,9};
    int n;
    scanf("%d",&n);
    do{
        int x,y;
        x = y = 0;
        for(int i = 0;i<5;i++)
        {
            x += pow(10,4-i)*A[i];
            y += pow(10,4-i)*A[i+5];
        }
        if(y/x ==n)
            printf("X = %d Y = %d\n",x,y);

    }while(next_permutation(A,A+10));




    return 0;
}
