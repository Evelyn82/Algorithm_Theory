#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int ALPHA = 27;

int toInt(char c){
    if(c == '?') return 26;
    return c - 'a';
}
struct Trie{
    bool endPoint;
    int count;
    Trie* child[ALPHA];

    Trie() : endPoint(false), count(0){
        for(int i = 0; i < ALPHA; ++i) child[i] = NULL;
    }
    
    void insert(const char* key){
        if(*key == 0) {
            endPoint = true;
            return;
        }
        
        int next = toInt(*key);
        if(!child[next]) child[next] = new Trie();
        child[next] -> insert(key + 1);
    }
    
    void update(const char* key){
        if(*key == 0){
            if(endPoint) ++count;
            return;
        }
        
        int next = toInt(*key);
        if(child[26]) child[26] -> update(key + 1);
        
        if(child[next]) child[next] -> update(key + 1);
        else return;
    }
    
    int getCount(const char* key){
        if(*key == 0) return count;
        
        return child[toInt(*key)] -> getCount(key + 1);
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    
    Trie* root = new Trie();
    for(string &query : queries) root -> insert(query.c_str());
    for(string &word : words) root -> update(word.c_str());
    
    vector<int> answer;
    for(string &query : queries) answer.push_back(root -> getCount(query.c_str()));
    return answer;
}