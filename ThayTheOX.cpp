
#include <bits/stdc++.h>
	#define ll long long
	#define ld long double
	#define ull unsigned long long
	#define pb push_back
	#define eb emplace_back
	#define f first
	#define s second
	#define p pair
	#define all(C) C.begin(), C.end()
	#define Begin() int N; cin>>N; cin.ignore(); while(N--)
	
	//Commands
	
		// Loops
		
		#define FOR(i,a,b) for (ll i=(ll)a; i<=(ll)b; i++)
		#define FOR2(i,a,b) for (ll i=(ll)a; i<=(ll)b; ++i)
		#define FORD(i,a,b) for (ll i=(ll)a; i>=(ll)b; i--)
		
		// Get values
		
		#define maxOf(C) max_element(C.begin(), C.end()) - C.begin()
		#define minOf(C) min_element(C.begin(), C.end()) - C.begin()
		
		// Clear containers
		
		#define reset(C) memset(C,0,sizeof(C))
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
		#define revrs(C) reverse(C.begin(), C.end())
		
		// Scan and print containers

		#define getVector(C) for(ll _=0; _<C.size(); _++) cin>>C[_]
		#define printVector(C) for(int _=0; _<C.size(); _++) cout<<C[_]<<' '
		
	// Containers
	
	#define vec(x) vector<x> 
	#define Matrix(x) vector<vector<x> >
	#define Rubik(x) vector<vector<vector<x> > >
	#define pq(x) priority_queue<x>
	#define reverse_pq(x) priority_queue<x, vector<x>, greater<x> >
	#define ordered_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
	#define ordered_multiset(T) tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>
	
	#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;


void Process()
{
	string s;
	cin >> s;
	string t = "";
	ll C[26];
	reset(C);
	s = '0' + s;
	FOR(i, 1, s.length() - 1)
	{
		C[s[i] - 'a'] = i;
	}

	ll now = 25;
	ll ite = 1;
	while (now >= 0 && ite < s.length())
	{
		if (C[now] == 0)
		{
			now--;
			continue;
		}
		while (ite <= C[now])
		{
			if (s[ite] == now + 'a') t += (now + 'a');
			ite++;
		}
		now--;
	}
	cout << t << endl;
}

signed main() 
{
	faster();
		Process();
}