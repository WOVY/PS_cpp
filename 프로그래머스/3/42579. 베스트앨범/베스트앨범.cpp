#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair <int, int>> list;
    unordered_map<string, int> m;
    
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        list.push_back({i, plays[i]});
    }
    
    int genre_size = m.size();
    sort(list.begin(), list.end(),
         [] (const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second;});
    
    for (int i = 0; i < genre_size; i++) {
        auto max_genre = max_element(m.begin(), m.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
        int cnt = 0;
        for (int j = 0; j < genres.size() && cnt < 2; j++) {
              if (max_genre->first == genres[list[j].first]) {
                  answer.push_back(list[j].first);
                  cnt++;
              }
        }
        m.erase(max_genre);
    }
    
    return answer;
}