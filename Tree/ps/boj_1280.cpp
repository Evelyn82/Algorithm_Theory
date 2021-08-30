#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MXN = 2e5 + 2;
const int DIV = 1000000007;

ll fw[MXN], cnt[MXN];
ll sum(ll arr[], int idx){
    ll ret = 0;
    while(idx > 0){
        ret += arr[idx];
        idx -= (idx & -idx);
    }return ret;
}
void update(ll arr[], int idx, int cost){
    while(idx < MXN){
        arr[idx] += cost;
        idx += (idx & -idx);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    
    int pos; cin>>pos; pos++;
    update(fw, pos, pos);
    update(cnt, pos, 1);
    
    ll answer = 1;
    for(int i = 2; i <= N; ++i){
        cin >> pos; pos++;
        
        update(fw, pos, pos);
        update(cnt, pos, 1);
        ll leftCost = sum(fw, pos);
        ll leftCount = sum(cnt, pos);
        ll leftDiff = ((leftCount * pos) - leftCost) % DIV;
        
        ll rightCost = sum(fw, MXN) - leftCost;
        ll rightCnt = sum(cnt, MXN) - leftCount;
        ll rightDiff = abs((rightCnt * pos) - rightCost) % DIV;
        
        answer = (answer * (leftDiff + rightDiff)) % DIV;
    }cout<< answer % DIV<<'\n';
}