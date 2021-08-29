#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
using pll=pair<ll, ll>;
using vpll=vector<pll>;

pll point;
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

    // AC
    /*
    if(a.first*b.second+b.first*c.second+c.first*a.second-b.first*a.second-c.first*b.second-a.first*c.second>0) return true;
    return false;
     */
}
int main(){
    int n; scanf("%d", &n);
    vpll v(n);
    for(int i=0;i<n;++i) scanf("%lld %lld", &v[i].first, &v[i].second);
    
    sort(v.begin(), v.end(), cmp);
    point=v[0];
    sort(v.begin()+1, v.end(), cmp2);
    
    stack<int> s;
    s.push(0); s.push(1);
    int nxt=2;
    while(nxt<n){
        while(s.size()>=2){
            int one, two;
            two=s.top(); s.pop();
            one=s.top();
            if(ccw(v[one], v[two], v[nxt])){
                s.push(two); break;
            }
        }
        s.push(nxt++);
    }
    printf("%d\n", (int)s.size());
    return 0;
}
