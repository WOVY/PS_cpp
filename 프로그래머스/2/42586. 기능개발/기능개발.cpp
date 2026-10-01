#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> deploy;
    
    for (int i = 0; i < progresses.size(); i++) {
        int day = ((100 - progresses[i]) + speeds[i] - 1) / speeds[i];
        deploy.push_back(day);
    }
    
    int size = deploy.size();
    int max = deploy[0];
    int cnt = 1;
    
    for (int i = 1; i < size; i++) {        
        if (max < deploy[i]) {
            answer.push_back(cnt);
            cnt = 1;
            max = deploy[i];

        }
        else if (max >= deploy[i]) {
            cnt++;
        }
        if (i == size - 1) {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}