#include <iostream>
#include <vector>
#define N 3
using namespace std;

long long int memory[10][N + 1] = {0};
vector<vector<int>> validMoves(10);

long long int f(int start, int len)
{
    if (len == 1)
        return 1;

    if (memory[start][len] != 0)
        return memory[start][len];

    long long int ans = 0;

    for (int i = 0; i < validMoves[start].size(); i++)
    {
        int key = validMoves[start][i];
        ans += f(key, len - 1);
    }

    memory[start][len] = ans;

    return memory[start][len];
}

int main()
{
    // Write C++ code here
    int matrix[4][3] = {
        {1, 2, 3}, //0
        {4, 5, 6}, //1
        {7, 8, 9}, //2
        {-1, 0, -1} //3
    };              // 0 1 2

    int moveX[] = {0, -1, 0, 1};
    int moveY[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 3 && (j == 0 || j == 2))
                continue;
            int prevmove = matrix[i][j];
            // validMoves[prevmove].push_back(prevmove);

            for (int k = 0; k < 4; k++)
            {
                int x = i + moveX[k];
                int y = j + moveY[k];

                if (x >= 0 && x < 4 && y >= 0 && y < 3 && matrix[x][y] != -1)
                {
                    int nextmove = matrix[x][y];
                    validMoves[prevmove].push_back(nextmove);
                }
            }
        }
    }

    long long int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += f(i, N);
    }
    cout << ans << endl;
    return 0;
}
