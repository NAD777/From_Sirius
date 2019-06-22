#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <set>
#include <unordered_set>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)
//константность, использование своих типов
using namespace std;
bool isPal(const string& s){ // передает строку в функцию по ссылке => можно будет изменить

}
struct Event{
    int coord;
    int type;
    int index=0;
//    bool operator<(const Event& other) const {
//        return coord<other.coord;
////        return this->coord<other.coord;
//    }
    bool operator==(const Event& other) const {
        return coord==other.coord && type == other.coord&&index==other.index;
//        return this->coord<other.coord;
    }
};
struct CompareEvents{
    bool operator()(const Event& lhs, const Event &rhs) const{
        return lhs.coord < rhs.coord;
    }
};
struct EventHash{
    uint64_t operator()(const Event& event) const{
        return event.coord*10000007 + event.index;
    }
};
ostream& operator <<(ostream& s, const Event& event){
    return s<<'{'<<event.coord<<", "<<event.type<<'}';

}

int main()
{
//    set<Event> events;
//    events.insert({6,7});
//    vector<int> num = {6,1,2,6};
//    sort(num.begin(), num.end(), greater<>{});
//    set <int, greater<int>> numbers = {6,1,8,2}; //less - дефолтный компартор по возрастанию, greater - убывание
//    for(int x:numbers){
//        cout<<x;
//    }
//    cout<<endl;
//    set<Event, CompareEvents> events= {{4,6}, {7,6}};
//    for(const Event& event: events){
//        cout<<event<<endl;
//    }
    unordered_set<Event, EventHash> events = {{4,6}, {7,6}, {4,6}};
    for(const Event& event: events){
        cout<<event<<endl;
    }
    return 0;
}
