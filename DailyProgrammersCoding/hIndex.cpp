#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "hIndex.h"

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int total = citations.size();

    sort(citations.begin(), citations.end());

    int i;
    for (i = total; i > 0; i--)
    {
        if (i <= citations[total - i]) {
            break;
        }
    }
    answer = i;

    return answer;
}

void hIndex()
{
    cout << solution({ 3,0,6,1,5 }) << endl;
    cout << solution({ 3,5,6,7,8 }) << endl;
}