#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
string input;
vector<string> v;

int getSum(string a)
{
    int sum = 0;
    for(int i = 0; i < a.length(); ++i)
    {
        if(a[i] - '0' >= 0 && a[i] - '0' <= 9)
            sum += a[i] - '0';
    }
    return sum;
}

bool compare(string a, string b)
{
    if(a.length() != b.length())
        return a.length() < b.length();
    else
    {
        int aSum = getSum(a);
        int bSum = getSum(b);
        if(aSum != bSum)
            return aSum < bSum;
        else
            return a < b;
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; ++i)
        cout << v[i] << "\n";
    
    return 0;
}