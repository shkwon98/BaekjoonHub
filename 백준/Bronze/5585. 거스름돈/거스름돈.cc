#include <iostream>
using namespace std;

int price, change, sum = 0;

int main()
{
    cin >> price;
    change = 1000 - price;
    
    sum += change / 500;
    change = change % 500;

    sum += change / 100;
    change = change % 100;

    sum += change / 50;
    change = change % 50;

    sum += change / 10;
    change = change % 10;

    sum += change / 5;
    change = change % 5;

    sum += change;
    change = 0;

    cout << sum;
    
    return 0;
}
