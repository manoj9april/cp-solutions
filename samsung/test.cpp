#include<iostream>
using namespace std;

int cnt = 0;
void fun(){
	try{
		cnt++;
		fun();
	}catch(exception e){
		return;
	}
	return;
}
int main(){
	fun();
	cout<<"count : "<<cnt<<endl;
	return 0;
}