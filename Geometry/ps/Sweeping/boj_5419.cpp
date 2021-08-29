#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MXN=75002;
const int SZ=1<<18;

pii p[MXN];
struct SegT{
    int d[SZ];
    SegT() {fill(d, d+SZ, 0);}
    
    void inc(int n){
        n+=SZ/2;
        while(n>0){
            d[n]++;
            n/=2;
        }
    }
    
    int sum(int left, int right) {return sum(left, right, 1, 0, SZ/2);}
    int sum(int left, int right, int node, int nodeleft, int noderight){
        if(right<=nodeleft || noderight<=left) return 0;
        if(left<=nodeleft && noderight<=right) return d[node];
        int mid=(nodeleft+noderight)/2;
        return sum(left, right, node*2, nodeleft, mid)+sum(left, right, node*2+1, mid, noderight);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<n;++i) cin>>p[i].first>>p[i].second;
        sort(p, p+n, [](const pii& a, const pii& b){
            return a.second<b.second;
        });
        
        int ny[MXN], idx=0;
        for(int i=0;i<n;++i){
            if(i>0 && p[i].second != p[i-1].second) idx++;
            ny[i]=idx;
        }
        
        for(int i=0;i<n;++i) p[i].second=ny[i];
        
        sort(p, p+n, [](const pii& a, const pii& b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        });
        
        SegT st;
        ll ret=0;
        for(int i=0;i<n;++i){
            ret+=st.sum(p[i].second, SZ/2);
            st.inc(p[i].second);
        }
        cout<<ret<<'\n';
    }
}
