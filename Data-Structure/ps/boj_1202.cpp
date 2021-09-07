#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    
    int m, v;
    vector<pii> jewelry;
    for(int i = 0; i < n; ++i){
        cin >> m >> v;
        jewelry.push_back(pii(m, v));
    }
    sort(jewelry.begin(), jewelry.end(), [&](const pii &a, const pii &b){
        return a.first < b.first;
    });
    
    int c;
    vector<int> bag;
    for(int i = 0; i < k; ++i){
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());
    
    long long answer = 0;
    priority_queue<int> pq;
    for(int i = 0, j = 0; i < k; ++i){
        while(j < n && jewelry[j].first <= bag[i])
            pq.push(jewelry[j++].second);
        
        if(pq.size()){
            answer += pq.top();
            pq.pop();
        }
    }cout << answer << '\n';
}