#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int t; cin>>t;
	while(t--){
		int n ; cin>>n;
		int ans = n - n/2;
		cout<<ans<<"\n";
	}

	return 0;
}