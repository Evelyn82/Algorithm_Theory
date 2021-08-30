// 2804KB, 88ms
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> fw;
ll query(int idx){
    
    ll sum = 0;
    while(idx > 0){
        sum += fw[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx, ll diff){
    while(idx < fw.size()){
        fw[idx] += diff;
        idx += (idx & -idx);
    }
}
void change(int idx, ll num){
    ll now = query(idx) - query(idx - 1);
    update(idx, num - now);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N, Q; cin >> N >> Q;
    fw.resize(N + 1, 0);
    
    ll num;
    for(int i = 1; i <= N; ++i){
        cin >> num;
        update(i, num);
    }
    
    int x, y, a, b;
    for(int i = 0; i < Q; ++i){
        cin >> x >> y >> a >> b;
        
        if(x > y) swap(x, y);
        if(x > 0) cout << query(y) - query(x - 1) << '\n';
        else cout << query(y) << '\n';
        change(a, (ll)b);
    }
}