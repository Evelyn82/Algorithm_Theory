#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const double pi = 3.1415926535;
int n;
ll L;
vpll v, cvh;
double dist(const pll& a, const pll& b){
    ll dx=a.x-b.x;
    ll dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
int ccw(const pll& a, const pll& b, const pll& c){
    pll ab=mp(b.x-a.x, b.y-a.y);
    pll ac=mp(c.x-a.x, c.y-a.y);
    
    ll ret=ab.x*ac.y-ab.y*ac.x;
    if(ret>0) return 1;
    if(ret) return -1;
    return 0;
}
ll dot(const pll& a, const pll& b){
    return a.x*b.x+a.y*b.y;
}
int main(){
    scanf("%d %lld", &n, &L);
    v.resize(n);
    for(int i=0;i<n;++i) scanf("%lld %lld", &v[i].x, &v[i].y);
    swap(v[0], *max_element(v.begin(), v.end()));
    sort(v.begin()+1, v.end(), [&](const pll& a, const pll&b){
        int ret=ccw(v[0], a,b);
        if(ret) return ret>0;
        return dist(v[0],a)<dist(v[0],b);
    });
    
    for(pll& i : v){
        while(cvh.size()>=2 && ccw(cvh[cvh.size()-2], cvh.back(), i)<=0) cvh.pop_back();
        cvh.push_back(i);
    }
    
    int sz=(int)cvh.size();
    double ans=0;
    for(int i=0;i<sz;++i){
        pll prev=cvh[(i+sz-1)%sz], now=cvh[i], next=cvh[(i+1)%sz];
        double prevDist=dist(prev, now);
        double nextDist=dist(now, next);
        ans+=nextDist;
        
        ll inner=dot(mp(prev.x-now.x, prev.y-now.y), mp(next.x-now.x, next.y-now.y));
        double theta=acos((double)inner/prevDist/nextDist);
        theta=pi-theta;
        ans+=L*theta;
    }printf("%.0lf\n", ans);
}
