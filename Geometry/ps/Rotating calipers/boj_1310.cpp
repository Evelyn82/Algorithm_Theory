#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
using pii=pair<int, int>;

const int MXN=1e5+2;
struct point {
    int x, y, p, q;
    point() {};
    point(int _x, int _y, int _p, int _q) : x(_x), y(_y), p(_p), q(_q) {}
 
    bool operator < (const point& other) const {
        if (1ll * q * other.p != 1ll * p * other.q) return 1ll * q * other.p < 1ll * p * other.q;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    point operator - (const point& other) const{
        return {x-other.x, y-other.y, 0, 0};
    }
};
 
ll ccw(const point &a, const point &b, const point &c)
{
    pii ab=make_pair(b.x-a.x, b.y-a.y);
    pii ac=make_pair(c.x-a.x, c.y-a.y);
    return 1ll * ab.first*ac.second - 1ll * ab.second*ac.first;
}
ll ccw(const point &a, const point &b){
    return 1ll * a.x*b.y - 1ll * a.y*b.x;
}
ll dist(const point& a, const point& b)
{
    return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

int main(){
    int n; scanf("%d", &n);
    vector<point> p;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.push_back(point(x, y, 0, 0));
    }
 
    if (n == 1) {
        puts("0"); return 0;
    }
 
    sort(p.begin(), p.end());
    for (int i = 1; i < n; ++i) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p.begin() + 1, p.end());
 
    vector<point> c;
    int nxt = 2;
    for(point& i : p) {
        while (c.size() > 1 && ccw(c[c.size() - 2], c[c.size() - 1], i) <= 0) c.pop_back();
        c.push_back(i);
    }
    
    int sz=c.size();
    auto _next=[sz](int i){return (i+1)%sz;};
    
    int left=0, right=0;
    for(int i=0;i<sz;++i){
        if(c[left].x > c[i].x) left=i;
        if(c[right].x< c[i].x) right=i;
    }
    long long ans = dist(p[left], p[right]);
    for (int i = 0; i < sz; ++i) {
       if(ccw(c[_next(left)] - c[left], c[right] - c[_next(right)])>0) left=_next(left);
       else right=_next(right);
   
       ans = max(ans, dist(c[left], c[right]));
    }
 
    printf("%lld\n", ans);
    return 0;
}
