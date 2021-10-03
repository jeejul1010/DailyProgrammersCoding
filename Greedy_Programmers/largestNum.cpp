#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> collection;

    for (int i = 0; i < number.length(); i++)
    {
        while (!collection.empty() && k > 0 && number[i] > collection[collection.size() - 1])
        {
            collection.pop_back();
            k--;
        }
        collection.push_back(number[i]);
    }

    while (k > 0)
    {
        collection.pop_back();
        k--;
    }

    for (int i = 0; i < collection.size(); i++)
    {
        answer += collection[i];
    }
    return answer;
}

void largestNum()
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
}