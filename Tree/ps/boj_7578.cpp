#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MX = 1e6 + 1;

vector<int> fw;
int lineA[MX], lineB[MX];
int sum(int idx){
    int cnt = 0;
    while(idx > 0){
        cnt += fw[idx];
        idx -= (idx & -idx);
    }return cnt;
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
    for(int i = 1; i <= n; ++i) cin >> lineA[i];
    for(int i = 1; i <= n; ++i){
        int num; cin >> num;
        lineB[num] = i;
    }
    
    fw.resize(n + 1, 0);
    long long ret = 0;
    for(int i = 1; i <= n; ++i){
        int bIdx = lineB[lineA[i]];
        
        ret += sum(n) - sum(bIdx);
        update(bIdx);
    }cout << ret << '\n';
}