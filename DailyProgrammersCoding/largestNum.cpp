#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "largestNum.h"

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> strings;
    for (int i = 0; i < numbers.size(); i++)
    {
        strings.push_back(to_string(numbers[i]));
    }

    sort(strings.begin(), strings.end(), cmp);

    string answer = "";
    for (int i = 0; i < strings.size(); i++)
    {
        answer += strings[i];
    }

    if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}

void largestNum(vector<int> nums)
{
    cout << solution(nums) << endl;
}