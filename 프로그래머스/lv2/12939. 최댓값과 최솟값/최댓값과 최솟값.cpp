#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {    
    string answer = "";
    vector<int> v;
    
    int startIdx = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
        {
            v.push_back(stoi(s.substr(startIdx, i - startIdx)));
            startIdx = i + 1;
        }
    }
    v.push_back(stoi(s.substr(startIdx, s.length() - startIdx)));

    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + ' ' + to_string(v.back());
    return answer;
}