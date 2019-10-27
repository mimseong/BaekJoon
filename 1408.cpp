#include <iostream>
#include <string>
using namespace std;

int main() {
    string now_time;
    string start_time;
    cin >> now_time >> start_time;
    
    int now_sec = stoi(now_time.substr(0, 2))*3600 + stoi(now_time.substr(3, 2))*60 + stoi(now_time.substr(6, 2));
    int start_sec = stoi(start_time.substr(0, 2))*3600 + stoi(start_time.substr(3, 2))*60 + stoi(start_time.substr(6, 2));
    
    int left_sec = (now_sec - start_sec + 86400) % 86400;
    left_sec = 86400 - left_sec;
    
    printf("%02d:%02d:%02d", left_sec/3600, left_sec%3600/60, left_sec%3600%60);
    
    return 0;
}