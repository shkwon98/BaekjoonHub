#include <iostream>
#include <string>
using namespace std;

string num;
bool chk;

int main()
{
    while(1)
    {
        cin >> num;
        if(num == "0") break;
        
        chk = true;
        for(int i = 0; i < num.length() / 2; ++i)
        {
            if(num[i] != num[num.length() - i - 1])
            {
                chk = false;
                break;
            }
        }
        if(chk) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}