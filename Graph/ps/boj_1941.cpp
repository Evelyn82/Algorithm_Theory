#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char c[5][5];
int dx[] = {0, 0, -1, 1}, dy[]={1, -1, 0, 0};
bool vst[1<<25];
int answer;
void backTracking(int state, int sCnt, int totalCnt){
    vst[state] = true;
    if(sCnt + 3 < totalCnt) return;
    if(totalCnt == 7){
        if(sCnt > 3) answer++;
        return;
    }
    
    int x, y, nx, ny;
    for(int i = 0; i < 25; ++i){
        if(!(state & (1<<i))) continue;
        x = i / 5; y = i % 5;
        for(int j = 0; j < 4; ++j){
            nx = x + dx[j]; ny = y + dy[j];
            if(nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
            
            int pos = nx * 5 + ny;
            if((state & (1<<pos)) || vst[state | (1<<pos)]) continue;
            
            if(c[nx][ny] == 'S') backTracking((state | (1<<pos)), sCnt + 1, totalCnt + 1);
            else backTracking((state | (1<<pos)), sCnt, totalCnt + 1);
        }
    }
}
int main(){
    for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) scanf(" %c", &c[i][j]);
    
    // 25C7 = 480,700가지의 경우를 모두 탐색
    answer = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            int pos = i * 5 + j;
            if(c[i][j] == 'S') backTracking(1 << pos, 1, 1);
            else backTracking(1 << pos, 0, 1);
        }
    }printf("%d\n", answer);
}