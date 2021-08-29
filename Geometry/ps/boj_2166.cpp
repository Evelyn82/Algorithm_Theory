// 0ms
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    long long x1,y1,x2,y2,x3,y3; scanf("%lld%lld%lld%lld", &x1,&y1,&x2,&y2);
    
    long long ans=0;
    for(int i=2;i<n;++i){
        scanf("%lld%lld", &x3,&y3);
        ans+=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
        x2=x3; y2=y3;
    }printf("%.1lf\n", fabs(ans)/2);
}

// 4ms
/*
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN=1e4+10;
double x[MAXN], y[MAXN];
int main(){
    int n; scanf("%d", &n);
    for(int i=1;i<=n;++i) scanf("%lf%lf", &x[i], &y[i]);
    y[0]=y[n];
    y[n+1]=y[1];
    
    double ret=0;
    for(int i=1;i<=n;++i){
        ret+=x[i]*(y[i+1]-y[i-1]);
    }
    printf("%.1f\n", fabs(ret/2));
}
*/
