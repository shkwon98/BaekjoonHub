#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;
pair<int, int> station[10000];

int N, cnt = 0;
int goalDist, reachableDist;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> station[i].first >> station[i].second;
	}
	sort(station, station + N);
	cin >> goalDist >> reachableDist;

	int idx = 0;
	while (goalDist > reachableDist)
	{
		while (idx < N && station[idx].first <= reachableDist)
			pq.push(station[idx++].second);

		if (!pq.empty())
		{
			reachableDist += pq.top();
			pq.pop();
			cnt++;
		}
		else if (idx == N || station[idx].first > reachableDist)
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt;

	return 0;
}