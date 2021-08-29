//
//  13433.cpp
//  open contest
//
//  Created by Evelyn 💚 on 2021/01/25.
//

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN=8;
int main(){
    int r[MAXN], a[MAXN];
    double d[MAXN][MAXN], ret[MAXN];
    int i,j,n; scanf("%d", &n);
    for(i=0;i<n;++i) {
        scanf("%d", &r[i]);
        for(j=0;j<i;++j){
            d[i][j]=d[j][i]=2.0*sqrt((double)r[i]*r[j]);
        }
        a[i]=i;
    }
    
    double ans=1e15;
    do{
        ret[0]=0;
        for(i=1;i<n;++i){
            ret[i]=0;
            for(j=0;j<i;++j){
                ret[i]=max(ret[i], ret[j]+d[a[i]][a[j]]);
            }
        }ans=min(ans, ret[n-1]);
    }while(next_permutation(a, a+n));
    printf("%.11lf\n", ans);
}
