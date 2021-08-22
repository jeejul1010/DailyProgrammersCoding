#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int stolenCount = 0;
    vector<int> students(n + 1);

    for (int i = 0; i < lost.size(); i++)
    {
        students[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        students[reserve[i]]++;
    }

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i] == -1)
        {
            if (students[i - 1] == 1)
            {
                students[i - 1] = 0;
                students[i] = 0;
            }
            else if (i!=n && students[i + 1] == 1)
            {
                students[i + 1] = 0;
                students[i] = 0;
            }
            else
            {
                stolenCount++;
            }
        }
    }

    answer = n - stolenCount;

    return answer;
}

void gymClothes()
{
    cout << solution(5, { 2, 4 }, { 1, 3, 5 }) << endl;
    cout << solution(5, { 2, 4 }, {3}) << endl;
    cout << solution(3, {3}, {1}) << endl;
}