#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;
const int MXN = 1e5 + 2;

vector<pair<lli, int>> sgt; // rangeSum, minPoint
vector<int> input;
void init(int node, int left, int right){
    if(left == right) {
        sgt[node] = make_pair(input[left], left);
        return;
    }
    
    int mid = (left + right) / 2;
    init(node * 2, left, mid);
    init(node * 2 + 1, mid + 1, right);
    
    sgt[node].first = sgt[node * 2].first + sgt[node * 2 + 1].first;
    
    if(input[sgt[node * 2].second] <= input[sgt[node * 2 + 1].second]) sgt[node].second = sgt[node * 2].second;
    else sgt[node].second = sgt[node * 2 + 1].second;
}
pair<lli, int> query(int left, int right, int node, int nodeleft, int noderight){
    if(right < nodeleft || noderight < left) return make_pair(0, -1);
    if(left <= nodeleft && noderight <= right) return sgt[node];
    
    int mid = (nodeleft + noderight) / 2;
    pair<lli, int> low = query(left, right, node * 2, nodeleft, mid);
    pair<lli, int> high = query(left, right, node * 2 + 1, mid + 1, noderight);
    
    int idx;
    if(low.second == -1) idx = high.second;
    else if(high.second == -1) idx = low.second;
    else if(input[low.second] > input[high.second]) idx = high.second;
    else idx = low.second;
    
    return make_pair(low.first + high.first, idx);
}
lli solve(int left, int right){
    pair<lli, int> splitPoint = query(left, right, 1, 0, (int)input.size() - 1);
    
    lli answer = splitPoint.first * input[splitPoint.second];
    if(left <= splitPoint.second - 1) answer = max(answer, solve(left, splitPoint.second - 1));
    if(splitPoint.second + 1 <= right) answer = max(answer, solve(splitPoint.second + 1, right));
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N; cin>>N;
    sgt.resize(N * 4, make_pair(0, 0));
    input.resize(N);
    for(int i = 0; i < N; ++i) cin >> input[i];
    init(1, 0, N - 1);
    
    cout << solve(0, N - 1) << '\n';
}