#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> v;
string input;

void vps(string str)
{
    int strLen = str.length();
    int cnt = 0;
    for(int i = 0; i < strLen; ++i)
    {
        if(str[i] == '(') cnt++;
        else cnt--;

        if(cnt < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    if(cnt != 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0; i < N; ++i)
        vps(v[i]);

    return 0;
}