#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q;
    int totalWeight = 0;
    int idx = 0;
    int current = 0;

    while (1)
    {
        if (idx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        answer++;

        if (q.size() == bridge_length)
        {
            totalWeight -= q.front();
            q.pop();
        }

        current = truck_weights[idx];
        if (totalWeight + current <= weight)
        {
            q.push(current);
            totalWeight += current;
            idx++;
        }
        else
        {
            q.push(0);
        }
    }

    return answer;
}

void bridgeTruck()
{
    cout << solution(2, 10, { 7, 4, 5, 6 }) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
}