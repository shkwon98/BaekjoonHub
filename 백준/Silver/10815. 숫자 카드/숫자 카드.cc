#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, num;
vector<int> vecCard, vecResult;
bool isfound;
int low, high, mid;

void init()
{
    cin >> n;
    vecCard.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        vecCard.push_back(num);
    }
    sort(vecCard.begin(), vecCard.end());

    cin >> m;
    vecResult.reserve(m);
}

int main()
{
    init();

    for (int i = 0; i < m; ++i)
    {
        cin >> num;

        low = 0;
        high = n - 1;
        isfound = false;
        while ((low <= high) && !isfound)
        {
            mid = (low + high) / 2;
            if (vecCard[mid] == num)
                isfound = true;
            else if (vecCard[mid] < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (isfound)
        {
            vecResult.push_back(1);
        }
        else
            vecResult.push_back(0);
    }

    for (auto it : vecResult)
    {
        cout << it << " ";
    }

    return 0;
}