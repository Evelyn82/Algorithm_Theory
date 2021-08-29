#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

struct Linear{
    ll p,q;
    double xpos;
};
bool operator<(const ll x, const Linear other){
    return x<other.xpos;
}
double cross(const Linear& a, const Linear& b){
    return (double)(b.q-a.q)/(double)(a.p-b.p);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<int> h(n), cost(n);
    for(int i=0;i<n;++i) cin>>h[i];
    for(int i=0;i<n;++i) cin>>cost[i];
    
    vector<Linear> f;
    vector<ll> dp(n+1,0);
    for(int i=1;i<n;++i){
        Linear g = {cost[i-1], dp[i-1], 0};
        while(!f.empty()){
            g.xpos=cross(g,f.back());
            if(f.back().xpos<g.xpos) break;
            f.pop_back();
        }f.push_back(g);
        
        int pos=upper_bound(f.begin(), f.end(), h[i])-f.begin();
        pos--;
        
       // upper_bound implementation
        /*
        if(x<f[top-1].s){
            low=0, high=top-1;
            while(low+1<high){
                mid=(low+high)/2;
                (x<f[mid].s ? high : low)=mid;
            }fpos=low;
        }
        */
        
        // height(arr h)가 단조 증가이므로 이전 선분의 검사가 필요없고, 새로 생긴 선분의 검사만 하면된다.
        // O(N*logN) -> O(N)
        /*
        if(idx>=f.size()) idx=f.size()-1;      // idx = 0 (init)
        while(idx+1<f.size() && f[idx+1].xpos<h[i]) idx++;
        dp[i]=f[idx].p*h[i] + f[idx].q;
        */
        
        dp[i]=f[pos].p*h[i]+f[pos].q;
    }cout<<dp[n-1]<<'\n';
}
