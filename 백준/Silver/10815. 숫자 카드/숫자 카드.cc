#include <iostream>
#include <algorithm>

using namespace std;

int n, m, num;
int card[500001], result[500001];
bool isfound;
int low, high, mid;

void init()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> card[i];
    sort(card, card + n);

    cin >> m;
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
            if (card[mid] == num)
                isfound = true;
            else if (card[mid] < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (isfound)
        {
            result[i] = 1;
        }
        else
            result[i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}