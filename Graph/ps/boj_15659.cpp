#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void MulAndDiv(vector<ll> &num, vector<int> &sign){
    
    for(int i = 0; i < sign.size();){
        if(sign[i] == 2){
            num[i] *= num[i + 1];
            sign.erase(sign.begin() + i);
            num.erase(num.begin() + i + 1);
        }
        else if(sign[i] == 3){
            num[i] /= num[i + 1];
            sign.erase(sign.begin() + i);
            num.erase(num.begin() + i + 1);
        }
        else ++i;
    }
}
void AddAndSub(vector<ll> &num, vector<int> &sign){
    
    for(int i = 0; i < sign.size();){
        if(sign[i] == 0){
            num[i] += num[i + 1];
            sign.erase(sign.begin() + i);
            num.erase(num.begin() + i + 1);
        }
        else if(sign[i] == 1){
            num[i] -= num[i + 1];
            sign.erase(sign.begin() + i);
            num.erase(num.begin() + i + 1);
        }
        else ++i;
    }
}
void solve(vector<int>& num, vector<int>& sign){
    
    pair<ll, ll> answer = make_pair(-1e9, 1e9);
    vector<ll> num2;
    vector<int> sign2;
    
    do{
        
        num2.clear();
        for(int i = 0; i < num.size(); ++i) num2.push_back((ll)num[i]);
        sign2.clear();
        for(int i : sign) sign2.push_back(i);
        
        MulAndDiv(num2, sign2);
        AddAndSub(num2, sign2);
        
        answer.first = max(answer.first, num2[0]);
        answer.second = min(answer.second, num2[0]);
    }while(next_permutation(sign.begin(), sign.end()));
    
    cout << answer.first << '\n' << answer.second << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; ++i) cin >> num[i];
    
    int cnt;
    vector<int> sign;
    for(int i = 0; i < 4; ++i) {
        cin >> cnt;
        for(int j = 0; j < cnt; ++j) sign.push_back(i);
    }
    solve(num, sign);
}