#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fw, pos;
int sum(int idx){
    int cnt = 0;
    while(idx > 0){
        cnt += fw[idx];
        idx -= (idx & -idx);
    }return cnt;
}
void update(int idx, int diff){
    while(idx < fw.size()){
        fw[idx] += diff;
        idx += (idx & -idx);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for(int tc = 0; tc < t; ++tc){
        int n, m; cin >> n >> m;
        fw.clear(); fw.resize(n + m + 2, 0);
        pos.clear(); pos.resize(n + 1);
        
        int idx = n + m + 1;
        for(int i = n; i > 0; --i, --idx) {
            update(idx, 1);
            pos[i] = idx;
        }
        int num;
        for(int i = 0; i < m; ++i){
            cin >> num;
            cout << sum(pos[num] - 1) <<' ';
            update(pos[num], -1);
            update(idx, 1);
            pos[num] = idx--;
        }cout << '\n';   
    }
}
