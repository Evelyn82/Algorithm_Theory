#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 20000 * 1e5;
const int MXN = 202;

int cost[MXN][MXN];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j) cost[i][j] = INF;
    
    for(vector<int> fare : fares){
        cost[fare[0]][fare[1]] = cost[fare[1]][fare[0]] = fare[2];
    }
    
    // floyd-warshall
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(cost[i][k] != INF && cost[k][j] != INF)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        
    
    int answer = cost[s][a] + cost[s][b];
    for(int i = 1; i <= n; ++i) answer = min(answer, cost[s][i] + cost[i][a] + cost[i][b]);
    return answer;
}