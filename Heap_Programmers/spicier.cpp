#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    //priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end()); 이렇게 할 수도 있군..!

    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    int temp;
    while (first < K) {
        temp = first + second * 2;
        answer++;
        pq.push(temp);
        first = pq.top();
        pq.pop();
        if (!pq.empty()) {
            second = pq.top();
            pq.pop();
        }
        else {
            if (first < K) {
                return -1;
            }
            else {
                return answer;
            }
        }
    }
    return answer;
}

void spicier() {
    cout << solution({ 1,2,3,9,10,12 }, 7) << endl;
}