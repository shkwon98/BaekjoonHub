#include <stdio.h>

int minimum(int a, int b)
{
    if(a > b) return b;
    else return a;
}
int maximum(int a, int b)
{
    if(a > b) return a;
    else return b;
}

int main()
{
    int arrSize;
    scanf("%d", &arrSize);
    
    int num[arrSize];
    int min, max;
    for(int i = 0; i < arrSize; ++i)
    {
        scanf("%d", &num[i]);
        if (i == 0)
        {
            min = num[i];
            max = num[i];
        }
        else
        {
            min = minimum(min, num[i]);
            max = maximum(max, num[i]);
        }
    }
    printf("%d %d", min, max);    
    return 0;
}