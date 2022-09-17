#include <iostream>
#include <cmath>

using namespace std;

bool checkPrimeNum(int number)
{
    if (number == 1) return false;
    
    for(int i = 2; i <= sqrt(number); ++i)
    {
        if((number % i) == 0) return false;
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