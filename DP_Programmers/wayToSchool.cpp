#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> path(m, vector<int>(n, -1));

    for (int i = 0; i < puddles.size(); i++)
    {
        path[puddles[i][0] - 1][puddles[i][1] - 1] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (path[i][j] == 0)
            {
                continue;
            }
            if (i == 0 && j == 0)
            {
                path[i][j] = 1;
            }
            else if (i == 0)
            {
                path[i][j] = path[i][j - 1];
            }
            else if (j == 0)
            {
                path[i][j] = path[i - 1][j];
            }
            else
            {
                path[i][j] = (path[i][j - 1] + path[i - 1][j]) % 1000000007;
            }
        }
    }

    answer = path[m - 1][n - 1];
    return answer;
}

void wayToSchool()
{
    cout << solution(4, 3, { {2, 2} }) << endl;
}