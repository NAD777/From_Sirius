#include<iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;
//string view
void Print(string_view s){
    cout<<s<<endl;
}
vector <string> Split(const string& s){
    vector <string> words;
    size_t pos = 0;
    while(true){
        const size_t word_end = s.find(' ', pos);
        words.push_back(s.substr(pos, word_end - pos));
        if(word_end == s.npos){
            break;
        }
        else{
            pos = word_end + 1;
        }
    }
    return words;
}
int main(){
    for(const string& word: Split("ab cd e")){
        cout<<word<<endl;
    }
    return 0;
}
