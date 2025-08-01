#include <bits/stdc++.h>

	#define ll long long
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define cl(C) C.clear()
	#define cint cpp_int
	#define all(C) C.begin(), C.end()
	#define ALL(C) c,c+n
	int mod = 1e9+7;
 
	//Commands
 
		// Loops
 
		#define FOR(i,a,b) for (int i=a; i<=b; i++)
		#define FOR2(i,a,b) for (ll i=a; i<=b; ++i)
		#define FORD(i,a,b) for (int i=a; i>=b; i--)
		#define FORA(x,C) for (auto x:C)
		#define WHILE(x,y) while(cin>>x>>y)
		#define WHILEF(x,y,f) while(f>>x>>y)
		#define WHILE2(x) while(cin>>x)
		#define WHILEGL(a) while(getline(cin,a))
		#define WHILEGLF(a,f) while(getline(f,a))
 
		// Get values
 
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		#define ite(y,x,it) y<x>::iterator it
 
		// Clear containers
 
		#define reset(C) memset(C,0,sizeof(C))
		#define clearQueue(C, x) C = queue<x> ()
		#define Fill(C,a) fill(C.begin(), C.end(), a)
 
		// Customize containers
 
		#define SORT(C) sort(C.begin(), C.end())
		#define SORTD(C,x) sort(C.begin(), C.end(), greater<x>())
		#define SORTC(C,check) sort(C.begin(), C.end(), check)
		#define tlw(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = tolower(C[i])
		#define tup(C) for(int i=0; i<(sizeof(C)/sizeof(C[0])); i++) C[i] = toupper(C[i])
		#define Merge(C,F,K) merge(C.begin(), C.end(), F.begin(), F.end(), K.begin());
		#define Unique(C) C.erase(unique(C.begin(), C.end()), C.end())
		#define CutInHalf(C,F,x,y) y<x> F(C.begin() + C.size()/2 + 1, C.end()); C.resize(C.size()/2)
		#define revrs(C) reverse(C.begin(, C.end()))
		#define addString(token,a,b){if (a.length() < b.length()) swap(a,b);string token = "";reverse(a.begin(), a.end());reverse(b.begin(), b.end());int carry = 0;FOR(i,0,b.length()-1){carry = carry + (a[i] - '0') + (b[i] - '0');token.push_back(carry % 10 + '0');carry /= 10;}FOR(i,b.length(),a.length()-1){carry = carry + (a[i] - '0');token.pb(carry % 10 + '0');carry /= 10;}if (carry) token.pb(carry + '0');reverse(token.begin(), token.end());}
		#define multiplyString(token,a,b){reverse(A.begin(),A.end());reverse(B.begin(),B.end());string C;C.resize(A.length()+B.length(),'0');FOR(i,0,A.length()-1){int c = 0;FOR(j,0,B.length()-1){c += ((A[i]-'0') * (B[j]-'0') + C[i+j] -'0');C[i+j] = (char)(c%10 + '0');c/=10;}if (c > 0) C[i + B.length()] += c;}reverse(C.begin(),C.end());return C;}
		#define subtractString(token, a, b){string token = "";reverse(a.begin(), a.end());reverse(b.begin(), b.end());int carry = 0;int sum = 0;FOR(i,0,b.length()-1){sum = (a[i] - '0') - (b[i] - '0') - carry;if (sum < 0){carry = 1;sum += 10;}else carry = 0;token.pb(sum + '0');}FOR(i,b.length(),a.length()-1){sum = (a[i] - '0') - carry;if (sum < 0){carry = 1;sum += 10;}else carry = 0;token.pb(sum + '0');}reverse(token.begin(), token.end());while(token[0] == '0') token.erase(0,1);}
 
 
		// Scan and print containers
 
		#define get(C,a) for(int i=0; i<a; i++) cin>>C[i]
		#define get2(C,a,b) for(int i=0; i<a; i++) for (int j=0; j<b; j++) cin>>C[i][j]
		#define getVector(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getVector2(C) for(int i=0; i<C.size(); i++) for (int j=0; j<C[i].size(); j++) cin>>C[i][j]
		#define getDeque(C) for(int i=0; i<C.size(); i++) cin>>C[i]
		#define getSet(C, a, token) for(int i=0; i<a-1; i++) { cin>>token; C.insert(token); } cin>>token; C.insert(token)
		#define print(C,a) for(int i=0; i<a; i++) cout<<C[i]<<' '
		#define printVector(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
		#define printSet(C,x) for (set<x>::iterator it = C.begin(); it!= C.end(); ++it) cout<<*it<<' '
		#define printDeque(C) for(int i=0; i<C.size(); i++) cout<<C[i]<<' '
 
		// Converts between containers
 
		#define toSet(C,x) set<x> (C.begin(), C.end())
		#define toVector(C,x) vector<x> (C.begin(), C.end())
		#define toQueue(C,x) queue<x> (C.begin(), C.end())
		#define toDeque(C,x) deque<x> (C.begin(), C.end())
		#define toList(C,x) list<x> (C.begin(), C.end())
		#define toMultiset(C,x) multiset<x> (C.begin(), C.end())
 
		// Iterators
 
		#define pointer(A,x) A<x>::iterator
 
	// Containers
 
	#define um(x,y) unordered_map<x,y> 
	#define m(x,y) map<x,y> 
	#define p(x,y) pair<x,y> 
	#define us(x) unordered_set<x> 
	#define vec(x) vector<x> 
	#define vec2(C,x,y,token) vector<vector<token> > C(x, vector<token> (y))
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
 
	// System
	#define	run() int N; cin>>N; cin.ignore(); while(N--)
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#define pause() system("pause");
 
// Namespaces
 
using namespace std;

// so buoc it nhat /*
main() {
	faster() 
	run() {
		int n;
		cin>>n;
		int a[n];
		FOR(i, 0, n - 1)	
			cin >> a[i];
		int list[n+1];
		reset(list);
		FOR(i,1,n-1){
			FOR(j,0,i-1){
				if(a[i] >= a[j] && list[i] < list[j] + 1){
					list[i] = list[j] + 1;
				}
			}
		}
		cout<<n-*max_element(list,list+n)-1<<endl;
	}
	return EXIT_SUCCESS;
}
//day con lap lai dai nhat
/*
signed main() {
	faster()
	run() {
		int n;
		string str;
		cin>>n>>str;
		int dp[n+1][n+1];
		FOR(i,0,n) {
			FOR(j,0,n){
				if(i==0||j==0){
					dp[i][j]=0;
				}
				else if(str[i-1]==str[j-1] && i-1 != j-1){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[n][n]<<endl;
	}
	return EXIT_SUCCESS;
}	*/
// bac thang
/*
main() {
	faster()
	run() {
		int n,k;
		cin>>n>>k;
		ll dp[n+1];
		reset(dp);
		dp[1] = 1;
		dp[0] = 1;
		FOR(i,2,n){
			FOR(j,1,min(i,k)){
				dp[i]+=(dp[i-j]);
				dp[i] %=mod;
			}
		}
		cout<<dp[n]<<endl;
	}
	return EXIT_SUCCESS;
}	*/
//to hop c(c,k)
/*
main(){
	faster()
	run() {
		int n,k;
		cin >> n >> k;
		int C[n+1];
		reset(C);
		C[0] = 1;
		FOR(i, 1, n)
			FORD(j, min(i, k), 1)
				C[j] = (C[j] + C[j-1]) % mod;
		cout << C[k] <<endl;
	}
	return EXIT_SUCCESS;
}
*/
//xau con chung dai nhat
/*
main() {
	faster()
	run() {
		string a;
		string b;
		cin>>a>>b;
		int dp[a.size()+1][b.size()+1];
		FOR(i,0,a.size()) {
			FOR(j,0,b.size()) {
				if(i==0 || j==0){
					dp[i][j]=0;
				}
				else if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;
	}
}	*/

 //day con co tong bang S
 /*
main(){
	faster()
	run() {
		int n, k;
		cin >> n >> k;
		int a[n];
		FOR(i,0,n-1)
			cin>>a[i];
		bool check[k+1];
		reset(check);
		FOR(i,0,n-1)
			FORD(j,k,a[i])
				if(check[j-a[i]] == 1 || j == a[i])
					check[j]=1;
		check[k] == 1 ? cout<< "YES\n":cout<<"NO\n";
	}
	return EXIT_SUCCESS;
}	*/

 // day con tang dai nhat
 /*
mainfect() {
	faster()
	// run() {
		int n;
		cin>> n;
		int a[n];
		FOR(i, 0 , n - 1) 	cin>>a[i];
		int list[n];
		reset(list);
		FOR(i, 1, n - 1){
			FOR(j, 0, i-1){
				if(a[i] > a[j] && list[i] < list[j] + 1){
					list[i]= list[j]+1;
				}
			}
		}
		cout<<*max_element(list,list+n)+1<<endl;
	// }
	return EXIT_SUCCESS;
}	*/