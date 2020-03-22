#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	set<int> s;

	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);

    set<int>:: iterator it;
	it=s.begin();
    advance(it,3);
	cout<<*it<<endl;
}