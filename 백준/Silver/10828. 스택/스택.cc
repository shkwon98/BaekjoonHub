#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, num;
string command;
stack<int> s;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> command;
        if(command == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if(command == "pop")
        {
            if(s.empty())
                cout << -1 << "\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(command == "size")
        {
            cout << s.size() << "\n";
        }
        else if(command == "empty")
        {
            if(s.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(command == "top")
        {
            if(s.empty())
                cout << -1 << "\n";
            else
            {
                cout << s.top() << "\n";
            }
        }
    }
    
    return 0;
}