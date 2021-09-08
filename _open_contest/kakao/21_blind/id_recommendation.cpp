#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    // step-1
    for(char &c : new_id){
        if(c >= 'A' && c <= 'Z') c += 32;
    }
    
    // step-2
    string new_id2 = "";
    for(char c : new_id){
        if(c >= 'a' && c <= 'z') new_id2 +=c;
        else if(c >= '1' && c <= '9') new_id2 +=c;
        else if(c =='-' || c=='_' ||c == '.') new_id2 +=c;
    }
    new_id = new_id2;
    
    // step-3
   new_id2 = "";
    for(int i = 0; i < new_id.size(); ++i){
        if(new_id[i] == '.') {
            while(i + 1 < new_id.size() && new_id[i + 1] == '.') {i++;}
            new_id2 +='.';
        }
        else  new_id2 += new_id[i];
    }
    new_id = new_id2;
    
    // step-4
    new_id2 = new_id;
    if(new_id[0] == '.') {
        new_id2 = new_id.substr(1);
        if(new_id2.back() == '.') new_id2.pop_back();
    }
    else if(new_id.back() == '.') new_id2.pop_back();
    new_id = new_id2;
    
    // step-5
    if(new_id.empty()) new_id = 'a';
    
    // step-6
    if(new_id.size() > 15) new_id = new_id.substr(0, 15);
    if(new_id.back() == '.') new_id.pop_back();
    
    // step-7
    while(new_id.size() < 3){
        new_id += new_id.back();
    }
    return new_id;
}