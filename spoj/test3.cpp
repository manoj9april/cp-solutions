#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int a[n];

	for(int i=0; i<n; i++) cin>>a[i];

	sort(a,a+n);

	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++) cout<<i+1<<"   ";
	cout<<endl;

}

// 0 1 0 0 3 2 6 7 4 6 9 4