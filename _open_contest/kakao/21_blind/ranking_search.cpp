#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mp;
vector<int> volunteer[3][2][2][2];
void init(){
    mp["cpp"] = 0;
    mp["java"] = 1;
    mp["python"] = 2;
    
    mp["backend"] = 0;
    mp["frontend"] = 1;
    
    mp["junior"] = 0;
    mp["senior"] = 1;
    
    mp["chicken"] = 0;
    mp["pizza"] = 1;
    
    mp["-"] = 3;
}
void SetVolunteer(vector<string> &info){
    string language, job, career, food;
    int l, j, c, f;
    int score;
    for(string s : info){
        stringstream ss(s);
        ss >> language >> job >> career >> food >> score;
        l = mp[language];
        j = mp[job];
        c = mp[career];
        f = mp[food];
        volunteer[l][j][c][f].push_back(score);
    }
    
    for(l = 0; l < 3; ++l)
        for(j = 0; j < 2; ++j)
            for(c = 0; c < 2; ++c)
                for(f = 0; f < 2; ++f)
                    sort(volunteer[l][j][c][f].begin(), volunteer[l][j][c][f].end());
}
int dfs(string state, int pos, int score){
    if(pos == 4){
        int l = state[0] - '0';
        int j = state[1] - '0';
        int c = state[2] - '0';
        int f = state[3] - '0';
        
        int count = lower_bound(volunteer[l][j][c][f].begin(), volunteer[l][j][c][f].end(), score) - volunteer[l][j][c][f].begin();
        return (int)volunteer[l][j][c][f].size() - count;
    }
    
    if(state[pos] != '3') return dfs(state, pos + 1, score);
    else{
        int sz = (pos)? 2 : 3, sum = 0;
        string newState;
        for(int i = 0; i < sz; ++i){
            newState = state;
            newState[pos] = i + '0';
            sum += dfs(newState, pos + 1, score);
        }return sum;
    }
}
vector<int> findQuery(vector<string> &query){
    string language, job, career, food, skip;
    int score;
    
    string state;
    vector<int> answer;
    for(string s : query){
        stringstream ss(s);
        ss >> language >> skip >> job >> skip >> career >> skip >> food >> score;
        state = mp[language] + '0';
        state += mp[job] + '0';
        state += mp[career] + '0';
        state += mp[food] + '0';
        
        answer.push_back(dfs(state, 0, score));
    }return answer;
}
vector<int> solution(vector<string> info, vector<string> query) {
    
    init();
    SetVolunteer(info);
    vector<int> answer = findQuery(query);
    return answer;
}

/*
    효율성  테스트
    테스트 1 〉	통과 (164.60ms, 43.6MB)
    테스트 2 〉	통과 (187.15ms, 44.3MB)
    테스트 3 〉	통과 (280.83ms, 43.4MB)
    테스트 4 〉	통과 (311.30ms, 43.7MB)
*/