#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == '|') str[i] = '.';
        }
        
        int nBall = 0;
        for(int i = 0; i < str.size() - 1; ++i)
        {
            if( (str[i] == '(' && str[i+1] == '.') || (str[i] == '.' && str[i+1] == ')') || (str[i] == '(' && str[i+1] == ')') ) nBall++;
        }
        
        cout << "#" << test_case << " " << nBall << "\n";
	}
	return 0;
}