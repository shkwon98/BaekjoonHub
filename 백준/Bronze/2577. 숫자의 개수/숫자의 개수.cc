#include <iostream>
#include <string>
using namespace std;

int A, B, C;
string num;
int arr[10] = {};

int main()
{
    cin >> A >> B >> C;
    num = to_string(A * B * C);
    for (int i = 0; i < num.length(); ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j == num[i] - '0')
            {
                arr[j]++;
                break;
            }
        }
    }
    
    for (int j = 0; j < 10; ++j)
    {
        cout << arr[j] << "\n";
    }
    
    return 0;
}
