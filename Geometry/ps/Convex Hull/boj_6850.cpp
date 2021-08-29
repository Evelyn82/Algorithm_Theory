// 2680KB 
// 4ms

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#define X first
#define Y second
using namespace std;

const int MX=1e5+2;
typedef long long ll;
using pii=pair<int, int>;

int ccw(const pii& a, const pii& b, const pii& c){
    return (b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
}
int area(const pii& a, const pii& b){
    return a.X*b.Y-b.X*a.Y;
}
int main(){
    pii cvh[MX];
    int n; scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&cvh[i].X, &cvh[i].Y);
    }
    
    swap(cvh[0], *min_element(cvh, cvh+n));
    sort(cvh+1, cvh+n, [&cvh](pii &a, pii& b){
        int r= ccw(cvh[0], a, b);
        return r>0 || r==0 && a < b;
        // return r>0 || r==0 && a > b; -> AC
    });
  
    int sz=0;
    for(int i=0;i<n;++i){
        while(sz>1&&ccw(cvh[sz-2], cvh[sz-1], cvh[i])<=0) --sz;
        cvh[sz++]=cvh[i];
    }
    
    ll ans=0;
    for(int i=0;i<sz;++i) ans+=area(cvh[i], cvh[(i+1)%sz]);
    
    printf("%lld\n", abs(ans)/100);
}


// 5144KB
// 4ms
/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

const int MX=1e5+2;
typedef long long ll;
struct ConvexHull{
    ll x, y;
    ll p, q;
    ConvexHull(ll x1=0, ll y1=0):x(x1), y(y1), p(1), q(0){}
}c[MX];
bool cmp(const ConvexHull& a, const ConvexHull& b){
    if(a.q*b.p != a.p*b.q) return a.q*b.p < a.p*b.q;
    
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
ll ccw(const ConvexHull& a, const ConvexHull& b, const ConvexHull& c){
    return (a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y);
}
int main(){
    int n; scanf("%d",&n);
    ll x,y;
    for(int i=0;i<n;++i){
        scanf("%lld%lld", &x,&y);
        c[i]=ConvexHull(x,y);
    }
    sort(c, c+n, cmp);
    for(int i=1;i<n;++i){
        c[i].p=c[i].x-c[0].x;
        c[i].q=c[i].y-c[0].y;
    }
    sort(c+1, c+n, cmp);
    
    vector<int> s;
    s.push_back(0);
    s.push_back(1);
    int next=2;
    while(next<n){
        while(s.size()>=2){
            int first, second;
            second=s.back(); s.pop_back();
            first=s.back();
            if(ccw(c[first], c[second], c[next])>0){
                s.push_back(second);
                break;
            }
        }
        s.push_back(next++);
    }
    
    ll ans=0;
    ll x1=c[s[0]].x, y1=c[s[0]].y,x2=c[s[1]].x, y2=c[s[1]].y,x3, y3;
    for(int i=2;i<s.size();++i){
        x3=c[s[i]].x, y3=c[s[i]].y;
        ans+=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
        x2=x3; y2=y3;
    }
    printf("%.0lld\n", ans/100);
}
*/
