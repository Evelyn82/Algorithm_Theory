#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> ump;
void MakeCandidate(string order, int idx, string comb){
    ump[comb]++;
    if(idx == order.size()) return;
    
    for(int i = idx; i < order.size(); ++i){
        MakeCandidate(order, i + 1, comb + order[i]);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    string combination = "";
    for(string s : orders) {
        sort(s.begin(), s.end());
        MakeCandidate(s, 0, combination);
    }
    vector<bool> sz(11, false);
    for(int i : course) sz[i] = true;

    vector<pair<string, int>> candidate[11];
    for(auto m : ump){
        int len = (int)m.first.size();
        if(sz[len] && m.second > 1) {
            if(candidate[len].size() && candidate[len].begin()->second <= m.second) {
                if(candidate[len].begin()->second < m.second) candidate[len].clear();
                candidate[len].push_back(make_pair(m.first, m.second));
            }
            else if(candidate[len].empty()) {
                candidate[len].push_back(make_pair(m.first, m.second));
            }
        }
    }
    
    vector<string> answer;
    for(int i : course) {
        for(pair<string, int> j : candidate[i]){
            answer.push_back(j.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

/*
 테스트 10 〉    통과 (1.57ms, 4.32MB)
 테스트 11 〉    통과 (0.68ms, 4.34MB)
 테스트 12 〉    통과 (0.55ms, 4.32MB)
 테스트 13 〉    통과 (1.01ms, 4.34MB)
 테스트 14 〉    통과 (1.15ms, 4.27MB)
 테스트 15 〉    통과 (0.98ms, 4.32MB)
 테스트 16 〉    통과 (0.92ms, 4.27MB)
 테스트 17 〉    통과 (1.27ms, 4.27MB)
 테스트 18 〉    통과 (2.43ms, 4.33MB)
 테스트 19 〉    통과 (1.14ms, 4.27MB)
 테스트 20 〉    통과 (1.03ms, 4.33MB)
 */
