#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> par;
int findPar(int idx){
    if(idx == par[idx]) return idx;
    return par[idx] = findPar(par[idx]);
}
void merge(int a, int b){
    int parA = findPar(a);
    int parB = findPar(b);
    if(parA > parB) swap(parA, parB);
    par[b] = parA;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int g, p; cin >> g >> p;
    for(int i = 0; i <= g; ++i) par.push_back(i);
    
    int num;
    vector<int> order;
    for(int i = 0; i < p; ++i){
        cin >> num;
        order.push_back(num);
    }
    
    int answer = 0;
    for(int i = 0; i < p; ++i){
        int pos = findPar(order[i]);
        if(pos == 0) break;
        answer++;
        merge(pos - 1, pos);
    }
    cout << answer << '\n';
}