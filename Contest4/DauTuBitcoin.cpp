#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast()
    int n;
    cin>>n;
    int a[n];
    FOR(i,0,n-1) 
        cin>>a[i];
    int k=0;
    int x=a[0];
    FOR(i,1,n-1){
        x=max(a[i],x);
        int d=a[i];
        if(x > d){
            k=max(x-d,k);
        }
    }
    if(k>0) cout<<k<<endl;
    else
    cout<<"Lo nang roi!"<<endl;
}