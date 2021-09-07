#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> inDegree;
vector<vector<int>> adj;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    inDegree.resize(n + 1, 0);
    adj.resize(n + 1);
    
    int now, next;
    for(int i = 0; i < m; ++i){
        cin >> now >> next;
        adj[now].push_back(next);
        inDegree[next]++;
    }
    
    priority_queue<int> pq;
    for(int i = 1; i <= n; ++i){
        if(inDegree[i] == 0) pq.push(-i);
    }
    
    while(pq.size()){
        now = -pq.top(); pq.pop();
        cout << now << ' ';
        
        for(int i = 0; i < adj[now].size(); ++i){
            if(--inDegree[adj[now][i]] == 0) pq.push(-adj[now][i]);
        }
    }
}