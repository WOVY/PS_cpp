#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0;
    int passed = 0;
    
    queue<int> q;
    for (int i = 0; i < bridge_length; i++)
        q.push(0);
    
    while (passed < truck_weights.size()) {
        answer++;
        total_weight -= q.front();
        q.pop();
        if (total_weight + truck_weights[passed] <= weight) {
            q.push(truck_weights[passed]);
            total_weight += truck_weights[passed];
            passed++;
        } else {
            q.push(0);
        }
    }
        
    return answer + bridge_length;
}