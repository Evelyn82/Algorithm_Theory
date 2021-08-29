// 4ms, 1232KB
#include <cstdio>
#include <vector>
#include <stack>
#include <memory.h>
#include <algorithm>
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
using vpll=vector<pll>;

pll point;
bool vst[1002];
bool cmp(const pll &a, const pll &b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}
bool cmp2(const pll &a, const pll &b){
    pll pa=make_pair(a.first-point.first, a.second-point.second);
    pll pb=make_pair(b.first-point.first, b.second-point.second);
    
    ll t1=pa.second*pb.first, t2=pa.first*pb.second;
    if(t1!=t2) return t1<t2;
    return cmp(a, b);
}
bool ccw(const pll &a, const pll &b, const pll &c){
    pll ab=make_pair(b.first-a.first, b.second-a.second);
    pll ac=make_pair(c.first-a.first, c.second-a.second);
    
    if(ab.first*ac.second-ab.second*ac.first>0) return true;
    return false;
}
int main(){
    int n; ll px, py; scanf("%d%lld%lld", &n, &px,&py);
    vpll v(n);
    for(int i=0;i<n;++i) scanf("%lld%lld", &v[i].first, &v[i].second);
    v.push_back(make_pair(px, py));
    
    int ans=0;
    while(v.size()>3){
        sort(v.begin(), v.end(), cmp);
        point=v[0];
        sort(v.begin()+1, v.end(), cmp2);
        
        stack<int> s;
        s.push(0); s.push(1);
        int nxt=2;
        while(nxt<v.size()){
            while(s.size()>=2){
                int one, two;
                two=s.top(); s.pop();
                one=s.top();
                if(ccw(v[one], v[two], v[nxt])){
                    s.push(two); break;
                }
            }s.push(nxt++);
        }
        
        vector<int> vt;
        while(!s.empty()){
            vt.push_back(s.top()); s.pop();
        }
        
        bool flag=false;
        memset(vst, false, sizeof vst);
        for(int &i : vt){
            if(v[i].first==px && v[i].second==py) {flag=true; break;}
            vst[i]=true;
        }
        if(flag) break;

        vector<pll> tmpv;
        for(int i=0;i<v.size();++i){
            if(!vst[i]) tmpv.push_back(v[i]);
        }
        v.clear();
        v=tmpv;
        ans++;
        
    }printf("%d\n", ans);
}

// 4ms, 1232KB 
// using struct
/*
#include <cstdio>
#include <vector>
#include <memory.h>
#include <stack>
#include <algorithm>
using namespace std;

struct Point{
    double x,y;
    double p,q;

    Point() : p(0.0), q(0.0){}
    Point(double _x, double _y): x(_x),y(_y),p(0.0),q(0.0){}
    
    bool operator<(const Point &d){
        if(q*d.p != p*d.q) return q*d.p < p*d.q;
        return y==d.y?x<d.x : y<d.y;
    }
    int getCCW(const Point &a, const Point &b){
        double r=(this->x*a.y + a.x*b.y + b.x*this->y)-(this->y*a.x + a.y*b.x + b.y*this->x);
        if(r>0) return 1;
        if(r==0) return 0;
        return -1;
    }
};
int n, ans;
double px, py;
Point pp;
vector<Point> v;
bool vst[1002];
bool convexHull(){
    stack<int> st;
    st.push(0); st.push(1);
    int next=2;
    while(next<v.size()){
        while(st.size()>=2){
            int one, two;
            one=st.top(); st.pop();
            two=st.top();
            if(v[two].getCCW(v[one], v[next])>0){
                st.push(one);
                break;
            }
        }st.push(next++);
    }
    
    bool ret=(st.size()>2)?true:false;
    vector<int> vt;
    while(!st.empty()){
        vt.push_back(st.top());
        st.pop();
    }
    
    int dft=pp.getCCW(v[vt[vt.size()-1]], v[vt[0]]);
    bool flag=false;
    for(int i=0;i<vt.size()-1;++i){
        if(dft!=pp.getCCW(v[vt[i]], v[vt[i+1]])){
            flag=true; break;
        }
    }
    if(!flag) ans++;
    memset(vst, false, sizeof vst);
    for(int &i : vt) vst[i]=true;
    
    vector<Point> vvt;
    for(int i=0;i<v.size();++i) if(!vst[i]) vvt.push_back(v[i]);
    
    v.clear();
    for(Point next : vvt) v.push_back(next);
    return ret;
}
void init(){
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();++i){
        v[i].p=v[i].x-v[0].x;
        v[i].q=v[i].y-v[0].y;
    }
    sort(v.begin()+1, v.end());
    
}
int main(){
    scanf("%d%lf%lf", &n,&px,&py);
    pp=Point(px, py);

    double a, b;
    for(int i=0;i<n;++i){
        scanf("%lf%lf", &a, &b);
        v.push_back(Point(a,b));
    }
    ans=0;
    while(1){
        if(v.size()<3) break;
        init();
        if(!convexHull())break;
    }
    printf("%d\n", ans);
}

*/
