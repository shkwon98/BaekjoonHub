#include <string>
#include <vector>

using namespace std;

int cnt1 = 0, cnt2 = 0;

void convert(string s)
{   
    if(s == "1") return;
    
    string newStr = "";
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '1') newStr += '1';
    }
    int len = newStr.length();
    cnt2 += s.length() - len;
    
    newStr = "";
    while(len > 0)
    {
        newStr = to_string(len % 2) + newStr;
        len /= 2;
    }
    cnt1++;
    
    convert(newStr);
}

vector<int> solution(string s) {
    vector<int> answer;
    
    convert(s);
    
    answer.push_back(cnt1);
    answer.push_back(cnt2);
    
    return answer;
}