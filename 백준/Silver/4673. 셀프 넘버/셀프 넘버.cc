#include <iostream>

using namespace std;

int main()
{   
    int num[10001] = {0,};
    
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
        {
            for(int c = 0; c < 10; c++)
            {
                for(int d = 0; d < 10; d++)
                {
                    if(1001*a + 101*b + 11*c + 2*d <= 10000)
                    {
                        num[1001*a + 101*b + 11*c + 2*d] = 1;
                    }
                }
            }
        }
    }
    
    for(int n = 1; n <= 10000; n++)
    {
        if(!num[n]) cout << n << "\n";
    }
    
    return 0;
}