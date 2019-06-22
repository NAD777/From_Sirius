
#include <iostream>
#include <chrono>
#include <random>
using namespace std;
pair <int, int> Generate(mt19937& gen){
	uniform_int_distribution<int> d(0, 10);
	return {d(gen), d (gen)};
}
void Stress{
	mt19937 gen; 
	for(int i=0;i<100;i++){
		auto [x, p] = Generate(gen);
		cout<<"Check "<<x<< ' '<< p << endl;
		assert(func(x, p) == funcCheck(x, p));
	}
}
inr main(){
	const auto start = chrono::steady_clock::now();
	const auto finish = chrono::steady_clock::now();
	cout<<chrono::duration_cast<chrono::milliseconds> (finish - start).count() << endl;
	return 0;
}
