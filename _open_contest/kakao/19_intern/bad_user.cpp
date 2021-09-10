#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> st;
vector<bool> visit;
void dfs(const vector<string>& user_id, const vector<string>& banned_id, int b_idx, int num){
    if(b_idx == banned_id.size()){
        st.emplace(num);
        return;
    }
    
    for(int i = 0; i < user_id.size(); ++i){
        if(visit[i]) continue;
        if(banned_id[b_idx].size() != user_id[i].size()) continue;
        
        int j;
        for(j = 0; j < banned_id[b_idx].size(); ++j){
            if(banned_id[b_idx][j] == '*') continue;
            if(banned_id[b_idx][j] != user_id[i][j]) break;
        }
        
        if(j == banned_id[b_idx].size()){
            visit[i] = true;
            dfs(user_id, banned_id, b_idx + 1, num | (1 << i));
            visit[i]=false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    visit.resize(user_id.size(), false);
    dfs(user_id, banned_id, 0, 0);
    return (int)st.size();
}