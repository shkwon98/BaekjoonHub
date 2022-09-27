#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string input;
vector<string> v;

bool test(string s, int start, int end)
{
    if(end == 0)
        return true;
    
    int mid = end / 2;
    for(int i = 0; i < mid; ++i)
    {
        if(s[i] == s[end - i])
            return false;
    }
    return test(s, 0, mid - 1);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;
        v.push_back(input);
    }
    
    for(int i = 0; i < v.size(); ++i)
    {
        if (test(v[i], 0, v[i].length() - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
