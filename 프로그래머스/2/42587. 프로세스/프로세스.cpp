#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    
    queue <pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < size; i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    int cnt = 0;
    
    while(!q.empty()) {
        pair<int, int> process = q.front();
        q.pop();
        
        if (process.second == pq.top()) {
            cnt++;
            pq.pop();
            
            if (process.first == location) {
                return cnt;
            }
        }
        else {
            q.push(process);
        }
        
    }
        
    return answer;
}