#include <iostream>
#include <cstring>
using namespace std;

int N, M, R, num;
int arr[100][100];
int temp[100][100];

void action(int num)
{
    switch (num)
    {
        case 1:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    temp[N - 1 - i][j] = arr[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    temp[i][M - 1 - j] = arr[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    temp[i][j] = arr[N - 1 - j][i];
                }
            }
            swap(N, M);
            break;
        case 4:
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    temp[i][j] = arr[j][M - 1 - i];
                }
            }
            swap(N, M);
            break;
        case 5:
            for (int i = 0; i < N / 2; ++i)
            {
                for (int j = 0; j < M / 2; ++j)
                {
                    temp[i][j + M / 2] = arr[i][j];
                }
            }
            for (int i = 0; i < N / 2; ++i)
            {
                for (int j = M / 2; j < M; ++j)
                {
                    temp[i + N / 2][j] = arr[i][j];
                }
            }
            for (int i = N / 2; i < N; ++i)
            {
                for (int j = M / 2; j < M; ++j)
                {
                    temp[i][j - M / 2] = arr[i][j];
                }
            }
            for (int i = N / 2; i < N; ++i)
            {
                for (int j = 0; j < M / 2; ++j)
                {
                    temp[i - N / 2][j] = arr[i][j];
                }
            }
            break;
        case 6:
            for (int i = 0; i < N / 2; ++i)
            {
                for (int j = 0; j < M / 2; ++j)
                {
                    temp[i + N / 2][j] = arr[i][j];
                }
            }
            for (int i = 0; i < N / 2; ++i)
            {
                for (int j = M / 2; j < M; ++j)
                {
                    temp[i][j - M / 2] = arr[i][j];
                }
            }
            for (int i = N / 2; i < N; ++i)
            {
                for (int j = M / 2; j < M; ++j)
                {
                    temp[i - N / 2][j] = arr[i][j];
                }
            }
            for (int i = N / 2; i < N; ++i)
            {
                for (int j = 0; j < M / 2; ++j)
                {
                    temp[i][j + M / 2] = arr[i][j];
                }
            }
            break;
    }
    memcpy(arr, temp, sizeof(arr));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < R; ++i)
    {
        cin >> num;
        action(num);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << temp[i][j] << ' ';
        cout << "\n";
    }
}