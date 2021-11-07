#include<bits/stdc++.h>
using namespace std;
	
int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int a[k];
		for(int i=0;i<k;i++) cin>>a[i];
		int i=k-1;
		while(i>=0 && a[i]==n-(k-1)+i) i--;
		if(i<0){
			for(int j=0;j<k;j++){
				a[j]=j+1;
			}
		}else {
			a[i]+=1;
			for(int j=i+1;j<k;j++) a[j]=a[i]+j-i;
		 }
		for(int i=0;i<k;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}