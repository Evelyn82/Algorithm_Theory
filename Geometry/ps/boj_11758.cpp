#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int x[3], y[3];
	for(int i=0;i<3;++i) scanf("%d %d",&x[i], &y[i]);
	
	int d=(x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]);
	if(d>0) printf("1\n");
	else if(d==0) printf("0\n");
	else printf("-1\n");
}
