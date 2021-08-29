// https://justicehui.github.io/apio/2018/08/20/BOJ4008/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
using vll=vector<ll>;
const int MXN=1e6+2;

int a,b,c;
vll v(MXN), pSum(MXN), dp(MXN), stk(MXN), xpos(MXN);
inline ll consFunc(ll x){
    return (ll)a*x*x + (ll)b*x + c;
}
inline ll k(ll i){
    return -2*a*pSum[i];
}
inline ll m(ll i){
    return a*pSum[i]*pSum[i] - b*pSum[i] + dp[i];
}
inline double getCross(int f, int g){
    ll k1=k(f), m1=m(f);
    ll k2=k(g), m2=m(g);
    return (double)(m1-m2) / (k2-k1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n>>a>>b>>c;
    for(int i=1;i<=n;++i){
        cin>>v[i];
        pSum[i]=pSum[i-1]+v[i];
    }
    
    int top=0, now=1;
    for(int i=1;i<=n;++i){
        dp[i]=consFunc(pSum[i]);
        if(top){
            while(now<top && xpos[now+1]<pSum[i]) now++;
            int j=stk[now];
            dp[i]=max(dp[i], dp[j]+consFunc(pSum[i]-pSum[j]));
            
            while(top>1 && xpos[top]>getCross(stk[top], i)) --top;
            stk[++top]=i;
            xpos[top]=getCross(stk[top-1], i);
            if(now>top) now=top;
        }
        else{
            stk[++top]=i;
            xpos[top]=-1e9;
        }
    }
    cout<<dp[n]<<'\n';
}
