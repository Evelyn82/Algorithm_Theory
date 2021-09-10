#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> candidateKey;
set<string> isUnique;
void BackTracking(vector<string> state, int key, int idx, vector<vector<string>>& r){
    if(idx == (int)(r[0].size())) return;
    
    BackTracking(state, key, idx + 1, r);
    
    isUnique.clear();
    for(int i = 0; i < r.size(); ++i) {
        state[i] += r[i][idx];
        isUnique.insert(state[i]);
    }
    if(isUnique.size() == r.size()) candidateKey.push_back(key | (1 << idx));
    else BackTracking(state, key | (1 << idx), idx + 1, r);
}
int GetCandidateKeyCount(){
    sort(candidateKey.begin(), candidateKey.end());
    //candidateKey.erase(unique(candidateKey.begin(), candidateKey.end()), candidateKey.end());
    
    int count = 0;
    for(int j = (int)candidateKey.size() - 1; j > -1; --j){
        int i;
        for(i = 0; i < j; ++i){
            if((candidateKey[i] & candidateKey[j]) == candidateKey[i]) break;
        }
        if(i == j) ++count;
    }return count;
}
int solution(vector<vector<string>> relation) {

    vector<string> candidate(relation.size(), "");
    BackTracking(candidate, 0, 0, relation);
    
    return GetCandidateKeyCount();
}