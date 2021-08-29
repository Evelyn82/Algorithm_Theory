#define _USE_MATH_DEFINES
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

struct Circle{
    double x,y,r;
}c[2];
double theta(double r1, double r2, double diff){
    return 2*acos((pow(diff,2)+pow(r1,2)-pow(r2,2))/(2*diff*r1));
}
double overlap(double diff){
    double t1=theta(c[0].r, c[1].r, diff);
    double t2=theta(c[1].r, c[0].r, diff);
    return (pow(c[0].r,2)*(t1-sin(t1))+pow(c[1].r,2)*(t2-sin(t2)))/2;
}
double solve(){
    double diff=sqrt(pow(c[0].x-c[1].x,2)+pow(c[0].y-c[1].y,2));
    
    if(diff>=c[0].r+c[1].r) return 0.0;
    if(abs(c[0].r-c[1].r)>=diff){
        return M_PI*pow(min(c[0].r,c[1].r),2);
    }
    return overlap(diff);
}
int main(){
    for(int i=0;i<2;++i) scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
    printf("%.3lf\n", solve());
}
