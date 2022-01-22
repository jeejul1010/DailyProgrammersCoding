#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);

    stack<int> s;

    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i]) //prices[i]보다 큰 값 다 찾아내서(이전으로 거슬러가면서) 해당 answer값 도출, 저장하기
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = size - 1 - s.top();
        s.pop();
    }
    return answer;
}

void stockPrice()
{
    vector<int> sol = solution({ 1, 2,3,2,3 });
    for (auto i : sol)
    {
        cout << i << endl;
    }
}