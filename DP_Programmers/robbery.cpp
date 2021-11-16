#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

int solution(vector<int> money) {
    int answer = 0;
    int num = money.size();
    vector<int> dp(num); //첫 번째 집 털기
    vector<int> dp2(num); //첫 번째 집 털지 않기

    dp[0] = money[0];
    dp[1] = dp[0];
    dp2[0] = 0;
    dp2[1] = money[1];

    for (int i = 2; i < num - 1; i++)
    {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }
    for (int i = 2; i <= num - 1; i++)
    {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    answer = max(dp[num - 2], dp2[num - 1]);

    return answer;
}

void robbery()
{
    cout << solution({ 1,2,3,1 }) << endl;
}