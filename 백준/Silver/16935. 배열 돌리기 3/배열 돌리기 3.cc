#include <iostream>
#include <cstring>
using namespace std;

int N, M, R, num;
int arr[100][100];
int temp[100][100];

void action(int num)
{
    bool isRotated = false;
    switch (num)
    {
        case 1:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    temp[i][j] = arr[N - 1 - i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    temp[i][j] = arr[i][M - 1 - j];
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
            isRotated = true;
            break;
        case 4:
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    temp[i][j] = arr[j][M - 1 - i];
                }
            }
            isRotated = true;
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

    if (isRotated)
    {
        int tmp = N;
        N = M;
        M = tmp;
        isRotated = false;
    }

    memcpy(arr, temp, sizeof(arr));
}

int main()
{
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