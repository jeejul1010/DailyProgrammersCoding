#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number)
    {
        return 1;
    }

    int answer = 0;

    vector<unordered_set<int>> dp(8);
    for (int i = 0; i < 8; i++)
    {
        int n = 0;
        int digit = i + 1;
        while (digit > 0)
        {
            n = n * 10 + N;
            digit--;
        }
        dp[i].insert(n);
    }

    /*for (int i = 0; i < 8; i++)
    {
        for (auto& x : dp[i])
        {
            cout << x << endl;
        }
    }*/

    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto& x : dp[j])
            {
                for (auto& y : dp[i - j - 1])
                {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (y != 0)
                    {
                        dp[i].insert(x / y);
                    }
                }
            }

        }
        if (dp[i].find(number) != dp[i].end())
        {
            return i + 1;
        }
    }
    answer = -1;
    return answer;
}

void nExpression()
{
    cout << solution(5, 12) << endl;
    cout << solution(2, 11) << endl;
}