#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (i == j)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                if (triangle[i][j] + triangle[i - 1][j - 1] > triangle[i][j] + triangle[i - 1][j])
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
            }
        }
    }

    sort(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    answer = triangle[triangle.size() - 1][triangle.size() - 1];

    return answer;
}

void integerTriangle() {
    cout << solution({ {7}, {3,8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} }) << endl;
}