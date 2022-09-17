#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputNum;
    char temp;
    int tempIdx;
    cin >> inputNum;
    
    for(int i = 0; i < inputNum.size() - 1; ++i)
    {
        temp = inputNum[i];
        tempIdx = i;
        for(int j = i + 1; j < inputNum.size(); ++j)
        {
            if(temp < inputNum[j])
            {
                temp = inputNum[j];
                tempIdx = j;
            }
        }
        inputNum[tempIdx] = inputNum[i];
        inputNum[i] = temp;
    }
    
    cout << inputNum;
    
    return 0;
}