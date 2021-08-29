#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int MX=1e5+2;
pll v[MX];
int main(){
    int n, sz=0; scanf("%d", &n);
    
    ll a, b; char c;
    for(int i=0;i<n;++i){
        scanf("%lld%lld %c",&a, &b, &c);
        if(c=='Y') v[sz++]=make_pair(a,b);
    }
    sort(v, v+sz);
    for(int i=1;i<sz;++i){
        v[i].first-=v[0].first;
        v[i].second-=v[0].second;
    }
    sort(v+1, v+sz, [](pll& a, pll&b){
        ll cross=a.first*b.second-b.first*a.second;
        if(cross==0){
            if(a.second==b.second) return a.first<b.first;
            else return a.second>b.second;
        }
        else if(cross<0) return false;
        return true;
    });
    
    printf("%d\n",sz);
    printf("%lld %lld\n",v[0].first, v[0].second);
    for(int i=1;i<sz;++i){
        printf("%lld %lld\n",v[i].first+v[0].first, v[i].second+v[0].second);
    }
}
