#include <string>
#include <vector>
#include <sstream>
using namespace std;
using lli = long long int;
const int MXT = 360003;

lli totalView[MXT];
 int TimeConvension(const string& s){
     return ((s[0] - 48) * 10 + (s[1] - 48)) * 3600 + ((s[3] - 48) * 10 + (s[4] - 48)) * 60 + ((s[6] - 48) * 10 + (s[7] - 48));
 }
string solution(string play_time, string adv_time, vector<string> logs) {
    
    /*
    int h1, m1, s1;
    sscanf(play_time.c_str(), "%02d:%02d:%02d", &h1, &m1, &s1);
    int play = h1 * 3600 + m1 * 60 + s1;
    
    sscanf(adv_time.c_str(), "%02d:%02d:%02d", &h1, &m1, &s1);
    int adv = h1 * 3600 + m1 * 60 + s1;
    */
    
    int play = TimeConvension(play_time);
    int adv = TimeConvension(adv_time);
    
    //int h2, m2, s2;
    for(string log : logs){
        /*
        sscanf(log.c_str(), "%02d:%02d:%02d-%02d:%02d:%02d", &h1, &m1, &s1, &h2, &m2, &s2);
        
        int start = h1 * 3600 + m1 * 60 + s1;
        int end = h2 * 3600 + m2 * 60 + s2;
        */
        
        int start = TimeConvension(log.substr(0, 8));
        int end = TimeConvension(log.substr(9, 8));
        
        totalView[start]++;
        totalView[end]--;
    }
    
    for(int i = 1; i <= play; ++i) totalView[i] += totalView[i - 1];
    for(int i = 1; i <= play; ++i) totalView[i] += totalView[i - 1];

    int startTime = 0;
    lli mxCnt = totalView[adv - 1];
    for(int start = 1; start + adv - 1 <= play; ++start) {
        if(mxCnt <  totalView[start + adv - 1] - totalView[start - 1]) {
            mxCnt =  totalView[start + adv - 1] - totalView[start - 1];
            startTime = start;
        }
    }
    
    /*
    char answer[19];
    sprintf(answer, "%02d:%02d:%02d", startTime/3600, (startTime/60)%60, startTime % 60);
    return answer;
     */
    
    string answer = "";
    answer += startTime / 3600 / 10 + 48;
    answer += startTime / 3600 % 10 + 48;
    answer += ':';
    answer += startTime % 3600 / 60 / 10 + 48;
    answer += startTime % 3600 / 60 % 10 + 48;
    answer += ':';
    answer += startTime % 60 / 10 + 48;
    answer += startTime % 60 % 10 + 48;
    return answer;
}