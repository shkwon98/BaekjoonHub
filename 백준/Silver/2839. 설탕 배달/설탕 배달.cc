#include <iostream>

using namespace std;

int main()
{
    int totalMass;
    int x, y, nBag;
    cin >> totalMass;
    
    for(x = 0; x <= totalMass / 3; ++x)
    {
        if((totalMass - 3 * x) % 5 == 0)
        {
            y = (totalMass - 3 * x) / 5;
            nBag = x + y;
            break;
        }
        nBag = -1;
    }    
    
    cout << nBag;
    return 0;
}