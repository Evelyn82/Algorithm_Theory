#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    
    priority_queue<int> minHeap, maxHeap;
    int num;
    for(int i = 0; i < n; ++i){
        cin>>num;
        if(maxHeap.empty()) maxHeap.push(num);
        else if(maxHeap.size() > minHeap.size()) minHeap.push(-num);
        else maxHeap.push(num);
        
        if(minHeap.size() && (-minHeap.top() < maxHeap.top())){
            int right = -minHeap.top(); minHeap.pop();
            minHeap.push(-maxHeap.top()); maxHeap.pop();
            maxHeap.push(right);
        }
        cout << maxHeap.top() << '\n';
    }
}