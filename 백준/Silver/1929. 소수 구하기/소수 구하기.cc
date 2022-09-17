#include <iostream>
#include <cmath>

using namespace std;

bool checkPrimeNum(int number)
{
    if (number == 1) return false;
    if (number == 2) return true;
    else
    {
        for(int i = 2; i < sqrt(number) + 1; ++i)
        {
            if((number % i) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int min, max, curNum;
    cin >> min >> max;
    
    for(int i = min; i <= max; ++i)
    {
        if(checkPrimeNum(i)) cout << i << '\n';
    }
    
    return 0;
}