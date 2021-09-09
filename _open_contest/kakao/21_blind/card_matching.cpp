#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
vector<pair<pii, pii>> card;
struct pos{
    int cost, x, y;
    pos(int _cost, int _x, int _y) : cost(_cost), x(_x), y(_y){}
};
bool operator<(const pos &a, const pos &b) {return a.cost > b.cost;}
bool inRange(int x, int y) {return 0 <= x && x < 4 && 0 <= y && y < 4;}

bool isEmpty(vector<vector<int>> &board){
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) if(board[i][j]) return false;
    return true;
}
int getDistence(pii from, pii to, const vector<vector<int>> &board){
    int dist[4][4];
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) dist[i][j] = 2e9;
    
    priority_queue<pos> pq;
    pq.push(pos(0, from.first, from.second));
    dist[from.first][from.second] = 0;
    
    while(!pq.empty()){
        pos now = pq.top(); pq.pop();
        
        if(now.x == to.first && now.y == to.second) return now.cost;
        if(dist[now.x][now.y] < now.cost) continue;
        
        for(int i = 0; i < 4; ++i){
            int nx = now.x, ny = now.y;
            
            int cnt = 1, nextCost;
            while(inRange(nx + dx[i], ny + dy[i])) {
            
                nx += dx[i]; ny += dy[i];
                if(board[nx][ny]) break;
                
                nextCost = now.cost + cnt++;
                if(dist[nx][ny] <= nextCost) continue;
                
                dist[nx][ny] = nextCost;
                pq.push(pos(nextCost, nx, ny));
            }
            if(dist[nx][ny] > now.cost + 1){
                dist[nx][ny] = now.cost + 1;
                pq.push(pos(now.cost + 1, nx, ny));
            }
        }
    }
}
int BackTracking(int r, int c, vector<vector<int>>& board){
    if(isEmpty(board)) return 0;
    
    int answer = 2e9;
    for(int k = 1; k < 7; ++k){
        if(card[k].first.first == -1) continue;
        if(board[card[k].first.first][card[k].first.second]){
            
            int dist1 = getDistence(pii(r, c), card[k].first, board) + getDistence(card[k].first, card[k].second, board);
            int dist2 = getDistence(pii(r, c), card[k].second, board) + getDistence(card[k].second, card[k].first, board);
            //int dist3 = getDistence(card[k].first, card[k].second, board);
            
            board[card[k].first.first][card[k].first.second] = 0;
            board[card[k].second.first][card[k].second.second] = 0;
            
            dist1 += BackTracking(card[k].second.first, card[k].second.second, board);
            dist2 += BackTracking(card[k].first.first, card[k].first.second, board);
            
            answer = min(answer, min(dist1, dist2) + 2);
            
            board[card[k].first.first][card[k].first.second] = k;
            board[card[k].second.first][card[k].second.second] = k;
        }
    }
    return answer;
}
int solution(vector<vector<int>> board, int r, int c) {
    
    card.resize(7, make_pair(pii(-1, -1), pii(-1, -1)));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(board[i][j]){
                if(card[board[i][j]].first.first == -1) card[board[i][j]].first = make_pair(i, j);
                else card[board[i][j]].second = make_pair(i, j);
            }
        }
    }
    return BackTracking(r, c, board);
}