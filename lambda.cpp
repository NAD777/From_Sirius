#include<iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
//итераторы
int main(){
    vector<int> v = {1, 5, 6, 9, 18, 38);
    set<int> residues = {6, 8};
   	cout<<count_if(v.begin()v.end(), [&residues](int x){ //[] - то что в нее передается, аргкмент функции, тел лямбда функции
        return residues.cout(x%10);
    });
   	return 0;
}