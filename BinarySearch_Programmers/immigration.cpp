#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    int size = times.size();
    long long min = 1;
    long long max = (long long)(times[size - 1]) * n;
    long long answer = max;

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += mid / times[i];
        }

        if (sum < n)
        {
            min = mid + 1;
        }
        else
        {
            if (mid < answer)
            {
                answer = mid;
            }
            max = mid - 1;
        }
    }
    return answer;
}

void immigration()
{
    cout << solution(6, { 7, 10 }) << endl;
}