#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
void MyAlgorithm(int n){
	bool prime[n+1];
	memset(prime, true,sizeof(prime));
	for (int p=2;p*p<=n;p++){
		if (prime[p] == true){
			for (int i=p*p;i<=n;i+=p){
				prime[i]=false;
			}
		}
	}
	int size=0,index=0;
	for (int p=2;p<=n;p++){
		if(prime[p]){
			size++;
		}
	} 
	int primes[size];
	for(int p=2;p<=n;p++){
		if(prime[p]){
			primes[index]=p;
			index++;
		}
	}
	vector<int>factors;
	index=0;
	while (n>1){
		if(n%primes[index]==0){
			factors.push_back(primes[index]);
			n=n/primes[index];
			index=0;
		}
		else{
			index++;
		}
	}
	for(int x:factors){
		cout<<x<<"*";
	}
	cout<<1;
	cout<<endl;
}
int main (){
	while(true){
		int n;
		cout<<"Enter a number please :";
		cin>>n;
		cout<<n<<"=";
		MyAlgorithm(n); 
	} 
}