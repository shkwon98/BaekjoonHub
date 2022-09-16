#include <stdio.h>

int func(int num)
{
    int arr[9][5] = {{111, 123, 135, 147, 159},
                     {222, 234, 246, 258, 210},
                     {333, 345, 357, 369, 321},
                     {444, 456, 468, 432, 420},
                     {555, 567, 579, 543, 531},
                     {666, 678, 654, 642, 630},
                     {777, 789, 765, 753, 741},
                     {888, 876, 864, 852, 840},
                     {999, 987, 975, 963, 951}};
    int total = 0;
    if(num == 1000) num -= 1;

    int i = (num / 100) - 1;
    if(i >= 0)
    {
        total += (99 + 5 * i);
        for(int j=0; j<5; j++)
        {
            if (num >= arr[i][j]) total++;
        }
    }
    else
    {
        total = num;
    }
    
    return total;
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", func(num));
    return 0;
}