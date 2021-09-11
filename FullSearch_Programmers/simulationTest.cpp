#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count(3, 0);

    vector<int> firstArr = { 1,2,3,4,5 };
    vector<int> secondArr = { 2,1,2,3,2,4,2,5 };
    vector<int> thirdArr = { 3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (firstArr[i % firstArr.size()] == answers[i])
        {
            count[0]++;
        }
        if (secondArr[i % secondArr.size()] == answers[i])
        {
            count[1]++;
        }
        if (thirdArr[i % thirdArr.size()] == answers[i])
        {
            count[2]++;
        }

    }

    int max = *max_element(count.begin(), count.end());

    auto maxIndex = find(count.begin(), count.end(), max);
    while (maxIndex != count.end())
    {
        answer.push_back(maxIndex - count.begin() + 1);
        maxIndex = find(maxIndex + 1, count.end(), max);
    }

    return answer;
}

void simulationTest()
{
    vector<int> answer = solution({ 1,2,3,4,5 });
    //vector<int> answer = solution({ 1,3,2,4,2 });
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << endl;
}