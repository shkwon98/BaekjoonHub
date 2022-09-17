#include <iostream>

using namespace std;

int main()
{
    int day = 1;
    int upward, downward, goal;
    
    cin >> upward >> downward >> goal;
    
    day += (goal - upward) / (upward - downward);
    if((goal - upward) % (upward - downward)) day++;
    
    cout << day;
    return 0;
}