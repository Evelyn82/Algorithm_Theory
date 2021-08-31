#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> sgt, h;
void init(int node, int nodeleft, int noderight){
    if(nodeleft == noderight) {
        sgt[node] = nodeleft;
        return;
    }
    
    int mid = (nodeleft + noderight) >> 1;
    init(node * 2, nodeleft, mid);
    init(node * 2 + 1, mid + 1, noderight);
    
    if(h[sgt[node * 2]] <= h[sgt[node * 2 + 1]]) sgt[node] = sgt[node * 2];
    else sgt[node] = sgt[node * 2 + 1];
}
int findNode(int left, int right, int node, int nodeleft, int noderight){
    if(right < nodeleft || noderight < left) return -1;
    if(left <= nodeleft && noderight <= right) return sgt[node];
    
    int mid = (nodeleft + noderight) >> 1;
    int low = findNode(left, right, node * 2, nodeleft, mid);
    int high = findNode(left, right, node * 2 + 1, mid + 1, noderight);
    
    if(low == -1) return high;
    if(high == -1) return low;
    if(h[low] <= h[high]) return low;
    return high;
}
ll solve(int left, int right){
    int splitPoint = findNode(left, right, 1, 0, (int)h.size() - 1);
    ll answer = (ll)(right - left + 1) * (ll)h[splitPoint];
    
    if(left <= splitPoint - 1) answer = max(answer, solve(left, splitPoint - 1));
    if(splitPoint + 1 <= right) answer = max(answer, solve(splitPoint + 1, right));
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    while(cin >> n){
        if(n == 0) break;
        
        h.clear(); h.resize(n);
        for(int i = 0; i < n; ++i) cin >> h[i];
        
        sgt.clear();
        int sz = (int)(ceil(log2(n)) + 1e-9);
        int sz2 = (1 << (sz + 1));
        sgt.resize(sz2, 0);
    
        init(1, 0, n - 1);
        cout<<solve(0, n - 1)<<'\n';
    }
}