#include<iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
//итераторы
int main(){
    vector<int> v = {7,1,4,9};

    auto it = v.begin();
    cout<<*it;
    ++it;
    cout<<*it;
    ////////////
    deque <int> q = {7,1,4,9};
    cout<<cout_if(v.begin(), v.end(), [](int x){
    	return x%2 == 0;
    }
    sort(q.begin(), q.end());
    for(int x:v){
    	cout<<x<<' ';
    }
    cout<<endl;
    ////////////
    set<int> s = {6, 1, 6, 4};
    cout<<distance(s.begin(), s.end())<<endl;
    ////////////
    vector<int> ve1={3,8,9,12};
    vector<int> ve2={1,4,7,8};
    vector<int> res(8);
    merge(ve1.begin(), ve1.end(), ve2.begin(), ve2.end(), res.begin());
    for(int x: res){
    	cout<<x<<' ';
    }
    cout<<endl;
    ////////////
    vector<int> vec1={3,8,9,12};
    vector<int> vec2={1,4,7,8};
    vector<int> res1;
    set_intersaction(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(res));
    for(int x: res1){
    	cout<<x<<' ';
    }
    cout<<endl;
    ////////////
   	vector<int> vector1 = {3,8,9,12}
   	sort(vector1.rbegin(), vector1.rend());
   	////////////
   	
   	return 0;
}