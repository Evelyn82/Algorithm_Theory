#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MX = 1e6;

int sgt[MX * 4];
void update(int idx, int diff, int node, int nodeleft, int noderight){
    if(idx < nodeleft || noderight < idx) return;
    if(nodeleft == noderight){
        if(nodeleft == idx) sgt[node] += diff;
        return;
    }
    
    int mid = (nodeleft + noderight) >> 1;
    update(idx, diff, node * 2, nodeleft, mid);
    update(idx, diff, node * 2 + 1, mid + 1, noderight);
    sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}
void findFlavor(int ranking, int node, int nodeleft, int noderight){
    
    if(nodeleft == noderight){
        cout<<nodeleft<<'\n';
        update(nodeleft, -1, 1, 1, MX);
        return;
    }
    
    int mid = (nodeleft + noderight) / 2;
    
    if(ranking <= sgt[node * 2]) findFlavor(ranking, node * 2, nodeleft, mid);
    else findFlavor(ranking - sgt[node * 2], node * 2 + 1, mid + 1, noderight);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    
    int a, b, c;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a == 1){
            cin >> b;
            findFlavor(b, 1, 1, MX);
        }
        else{
            cin >> b >> c;
            update(b, c, 1, 1, MX);
        }
    }
}