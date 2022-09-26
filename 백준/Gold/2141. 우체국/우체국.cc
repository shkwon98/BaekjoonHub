#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > village;
vector<long long> sum;
int N;

int binsrc()
{
	int ans = 0;
	int low = 0, high = N - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		long long leftSum = sum[mid];
		long long rightSum = sum[N - 1] - sum[mid];

		if (leftSum >= rightSum)
		{
			high = mid - 1;
			ans = village[mid].first;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int pos, num;
		cin >> pos >> num;
		village.push_back({ pos, num });
	}
	sort(village.begin(), village.end());

	sum.push_back(village[0].second);
	for (int i = 1; i < N; ++i)
		sum.push_back(sum[i - 1] + village[i].second);

	cout << binsrc();

	return 0;
}