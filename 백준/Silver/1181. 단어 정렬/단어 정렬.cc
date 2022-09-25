#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string input;
vector<string> v;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); ++i)
            return a < b;
    }
    else
        return a.length() < b.length();
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << "\n";
    }

    return 0;
}