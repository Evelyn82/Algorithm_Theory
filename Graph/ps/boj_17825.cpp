#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const vector<int> path[5] = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
                        {13, 16, 19},
                        {22, 24},
                        {28, 27, 26},
                        {25, 30, 35, 40} // 변경된 line(x = 1, 2, 3)이 공유하는 부분 + 40 은 x == 0 로 변경해 처리
};

int dice[12];
bool stay[5][22];
pii state[4];
ll answer;

pii ChangePath(int stateIdx, int diceIdx){
    
    int x = state[stateIdx].first, y = state[stateIdx].second;
    int row = path[x][y] / 10;
    
    if(dice[diceIdx] <= path[row].size()){
        if(stay[row][dice[diceIdx] - 1]) return pii(x, y);
        return pii(row, dice[diceIdx] - 1);
    }
    else{
        int ny = dice[diceIdx] - (int)path[row].size() - 1; // 40 접근 절대 안함
        if(stay[4][ny]) return pii(x, y);
        return pii(4, ny);
    }
}

pii Move(int stateIdx, int diceIdx){
    
    int x = state[stateIdx].first, y = state[stateIdx].second;
    if(path[x].size() <= y) return pii(x, y);
        
    if(x == 0 && y > 0 && path[x][y] % 10 == 0) {
        if(path[x][y] / 10 == 4) return pii(x, y + 1);
        return ChangePath(stateIdx, diceIdx);
    }
    
    if(y + dice[diceIdx] < (int)path[x].size()) {
        if(x == 4 && path[x][y + dice[diceIdx]] == 40) {
            if(stay[0][20]) return pii(x, y);
            return pii(0, 20);
        }
        if(stay[x][y + dice[diceIdx]]) return pii(x, y);
        return pii(x, y + dice[diceIdx]);
    }
    else if(x == 0 || x == 4){
        return pii(x, (int)path[x].size());
    }
    // 공유로 넘어가는 구간
    int ny = dice[diceIdx] - ((int)path[x].size() - y);
    if(ny < 3){
        if(stay[4][ny]) return pii(x, y);
        return pii(4, ny);
    }
    if(ny == 3){  // 40
        if(stay[0][20]) return pii(x, y);
        return pii(0, 20);
    }
    return pii(x, (int)path[x].size());
}
void BackTracking(int diceIdx, ll sum){
    
    if(diceIdx == 10){
        answer = max(answer, sum);
        return;
    }
    
    for(int i = 0; i < 4; ++i){
        
        pii now = state[i];
        if(path[now.first].size() <= now.second) continue;
        
        pii next = Move(i, diceIdx);
        if(now == next) continue;
        
        now = state[i];
        stay[now.first][now.second] = false;
            
        state[i] = next;
        if(path[state[i].first].size() <= state[i].second) BackTracking(diceIdx + 1, sum);
        else {
            stay[state[i].first][state[i].second] = true;
            BackTracking(diceIdx + 1, sum + path[state[i].first][state[i].second]);
            stay[state[i].first][state[i].second] = false;
        }
        
        /*
        line 103 ~ 108과 동일 + 정답처리된 코드
        int plus = 0;
        if(state[i].second < path[state[i].first].size()){
            stay[state[i].first][state[i].second] = true;
            plus = path[state[i].first][state[i].second];
        }
        BackTracking(diceIdx + 1, sum + plus);
        if(state[i].second < path[state[i].first].size()) stay[state[i].first][state[i].second] = false;
        */
    
        state[i] = now;
        stay[state[i].first][state[i].second] = true;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 0; i < 10; ++i) cin >> dice[i];
    for(int i = 0; i < 4; ++i) state[i] = make_pair(0, 0);
    
    BackTracking(0, 0);
    cout << answer << '\n';
}