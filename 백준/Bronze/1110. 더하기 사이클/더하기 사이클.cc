#include <stdio.h>

int main()
{
    int n, m, p;
    scanf("%d", &n);
    m = n;
    p = 100;
    
    int x, y;
    int i = 0;
    while(p != n)
    {
        x = m / 10;
        y = m % 10;
        p = y * 10 + (x + y) % 10;
        m = p;
        i++;
    }
    printf("%d", i);
    
    return 0;
}