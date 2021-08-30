// 5544KB, 136ms
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> sgt;
vector<int> input;
ll init(int node, int left, int right){
    if(left == right) return sgt[node] = (ll)input[left];
    
    int mid = (left + right) / 2;
    return sgt[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}
ll rangeSum(int left, int right, int node, int nodeleft, int noderight){
    if(right < nodeleft || noderight < left) return 0;
    if(left <= nodeleft && noderight <= right) return sgt[node];
    
    int mid = (nodeleft + noderight) / 2;
    return rangeSum(left, right, node * 2, nodeleft, mid) + rangeSum(left, right, node * 2 + 1, mid + 1, noderight);
}
void update(int idx, ll diff, int node, int nodeleft, int noderight){
    if(idx < nodeleft || noderight < idx) return;
    if(nodeleft == noderight) {
        sgt[node] = diff;
        return;
    }
    
    int mid = (nodeleft + noderight) / 2;
    if(idx <= mid) update(idx, diff, node * 2, nodeleft, mid);
    else update(idx, diff, node * 2 + 1, mid + 1, noderight);
    
    sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N, Q; cin >> N >> Q;
    sgt.resize(N * 4, 0);
    input.resize(N);
    
    for(int i = 0; i < N; ++i) cin >> input[i];
    init(1, 0, N - 1);
    
    int x, y, a, b;
    for(int i = 0; i < Q; ++i){
        cin >> x >> y >> a >> b;
        
        if(x > y) swap(x, y);
        cout << rangeSum(x - 1, y - 1, 1, 0, N - 1) << '\n';
        update(a - 1, (ll)b, 1, 0, N - 1);
    }
}