#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int first = 0;
    int last = people.size() - 1;

    int temp = 0;
    while (first < last)
    {
        temp = people[first] + people[last];
        if (temp <= limit)
        {
            first++;
            last--;
        }
        else
        {
            last--;
        }
        answer++;
    }

    if (first == last)
    {
        answer++;
    }
    return answer;
}

void lifesaver()
{
    cout << solution({ 70, 50, 80, 50 }, 100) << endl;
    cout << solution({ 70, 80, 50 }, 100) << endl;
}