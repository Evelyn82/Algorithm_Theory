#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;

const int MXN=2002;
struct Point{
    ll x, y, order;
    Point() {}
    bool operator == (const Point &other) const {
        return x==other.x && y==other.y;
    }
    bool operator < (const Point &other) const {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
}v[MXN];

int ccw(const Point &a, const Point &b, const Point &c){
    ll ret = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}
ll dist(const Point &a, const Point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<n;++i){
            cin>>v[i].x>>v[i].y;
            v[i].order=i;
        }
        swap(v[0], *min_element(v, v+n));
        sort(v+1, v+n, [&](const Point &a, const Point &b){
            int cw=ccw(v[0], a, b);
            if(cw) return cw>0;
            return dist(v[0], a) < dist(v[0], b);
        });
        
        // v[0]기준으로 v[0].x가 동일한 지점들은(north direction) sorted된 것을 reverse 해줘야됨
        // 그 지점들중 제일 먼 지점 = pt
        int pt=n-1;
        for(int i=n-1;i>0;--i){
            if(ccw(v[0], v[pt], v[pt-1])==0) pt--;
            else break;
        }
        reverse(v+pt, v+n);
        for(int i=0;i<n;++i) cout<<v[i].order<<' '; cout<<'\n';
    }
}
