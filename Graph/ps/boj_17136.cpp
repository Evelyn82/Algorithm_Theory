#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ary[10][10], answer;
vector<int> paper;
bool isEmpty(){
    for(int i = 0; i < 10; ++i) for(int j = 0; j < 10; ++j) if(ary[i][j]) return false;
    return true;
}
bool matching(int x, int y, int sz){
    if(x + sz > 10 || y + sz > 10) return false;
    for(int i = x; i < x + sz; ++i){
        for(int j = y; j < y + sz; ++j){
            if(ary[i][j] == 0) return false;
        }
    }
    for(int i = x; i < x + sz; ++i){
        for(int j = y; j < y + sz; ++j){
            ary[i][j] = 0;
        }
    }return true;
}
void backTracking(int x, int y, int cnt){
    if(y == 10){
        backTracking(x + 1, 0, cnt);
        return;
    }
    
    if(x==10){
        answer = min(answer, cnt);
        return;
    }
    
    if(ary[x][y] == 0){
        backTracking(x, y+1, cnt);
        return;
    }

    for(int k = 5; k > 0; --k){
        if(paper[k] && matching(x, y, k)){
            paper[k]--;
            backTracking(x, y+k, cnt+1);
                        
            for(int nx = x; nx < x + k; ++nx){
                for(int ny = y; ny < y + k; ++ny){
                    ary[nx][ny] = 1;
                }
            }paper[k]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 0; i < 10; ++i) for(int j = 0; j < 10; ++j) cin >> ary[i][j];
    paper.resize(6, 5);
    
    answer = 26;
    backTracking(0, 0, 0);
 
    if(answer == 26) cout << -1 << '\n';
    else cout << answer << '\n';
}