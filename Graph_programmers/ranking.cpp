#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sol(int n, vector<vector<int>> results) {
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    for (auto r : results)
    {
        graph[r[0]][r[1]] = true;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (graph[j][k] && graph[k][i])
                {
                    graph[j][i] = true;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] || graph[j][i])
            {
                count++;
            }
        }
        if (count == n - 1)
        {
            answer++;
        }
    }

    return answer;
}

void ranking()
{
    cout << sol(5, { {4, 3},{4, 2}, {3, 2}, {1, 2}, {2, 5} }) << endl;
}