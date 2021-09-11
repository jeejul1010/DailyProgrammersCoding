#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

bool isPrime(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> primes;

    sort(numbers.begin(), numbers.end());

    do
    {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            int tmp = stoi(temp);
            if (isPrime(tmp))
            {
                primes.insert(tmp);
            }
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = primes.size();

    return answer;
}

void findingPrime()
{
    cout << solution("17") << endl;
    cout << solution("011") << endl;
}