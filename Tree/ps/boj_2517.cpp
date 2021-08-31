#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<int> fw;
int sum(int idx){
    int ret = 0;
    while(idx > 0){
        ret += fw[idx];
        idx -= (idx & -idx);
    }return ret;
}
void update(int idx){
    while(idx < fw.size()){
        fw[idx]++;
        idx += (idx & -idx);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    fw.resize(n + 1, 0);
    
    vector<pii> input(n);
    for(int i = 0; i < n; ++i){
        cin >> input[i].second;
        input[i].first = i + 1;
    }
    sort(input.begin(), input.end(), [&](const pii &a, const pii &b){return a.second > b.second;});
    
    vector<int> ret(n);
    for(pii p : input){
        ret[p.first - 1] = sum(p.first) + 1;
        update(p.first);
    }
    for(int i : ret) cout << i << '\n';
}