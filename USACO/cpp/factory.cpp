#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
// #pragma GCC optimize ("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pz;

#define vec vector
#define pb push_back
#define pub push_back
#define pob pop_back
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define get(i,x) get<i>(x)
#define f first
#define s second

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define F0R(i,a) for(int i = 0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define R0F(i,a) for(int i=a;i>=0;i--)

#define OE <<endl
#define aendl "<-\n"
#define space ' '
#define elif else if
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dispbr(n) for(auto& i:n) cout<<i<<endl;
#define disp(n) for(auto& i:n) cout<<i<<space

vi factors(int n){
	vi factors;
	double sqrtofn=sqrt(n);
	int count=1;
	while(count<=sqrtofn){
		if(n%count==0){
			factors.pub(count);
			if(count*count!=n)factors.pub(n/count);
		}
		count++;
	}
	return factors;
}

template<class T>
vec<T> filter(vec<T> iter, T delim){
	vec<T> ret;
	fori (i,iter) if (i != delim) ret.pub(i);
	return ret;
}

vs ssplit(string s, char delim){
	stringstream ss(s);
	string token;
	vs ret;
	while(getline(ss,token,delim)) ret.pub(token);
	ret = filter<string>(ret,"");
	return ret;
}

template<class InputIterator>
ll arr_sum(InputIterator first, InputIterator last){
	ll sum = 0;
	while(first != last){
		sum += *first;
		first++;
	}
	return sum;
}

template<class InputIterator, class T>
InputIterator arr_remove(InputIterator first, InputIterator last, const T& val){
	while (first != last){
		if (*first == val) return first;
	}
	throw "Element does not exist\n";
}

template<class InputIterator, class T>
vll find_all(InputIterator first, InputIterator last, const T& val){
	vec<T> inds;

	InputIterator ptr = first;

	while(ptr != last){
		if (*ptr == val) inds.pb(ptr - first);
		ptr++;
	}

	return inds;
}

template <class T>
void Max(T &a, const T &b)
{
	T *ptr = &a;
	*ptr = max(a, b);
}

template <class T>
void Min(T &a, const T &b)
{
	T *ptr = &a;
	*ptr = min(a, b);
}

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

/*
Time complexities

O(n) = 10^8
O(n^2) = 10^4
O(n^3) = 200
O(logn) = Very big number, fucking massive 10^(4 * 10^8)
O(nlogn) = 10^7
O(2^n) = 24
*/

/*
3
1 2
3 2
*/

int n;
map<int, vi> edges;
set<int> unvcpy;

bool dfs(int endp, int st){
	if (endp == st) return true;

	stack<int> stk;
	set<int> unvisited (unvcpy.begin(), unvcpy.end());
	stk.push(st);

	int t;
	while(!stk.empty()){
		t = stk.top();
		stk.pop();

		if (t == endp) return true;
		else {
			for (auto &v : edges[t]){

				if (unvisited.count(v)){
					stk.push(v);
					unvisited.erase(v);
				}
			}
		}

	}

	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	setIO("factory");

	cin >> n;

	rep(n) unvcpy.insert(i+1);
	
	int t1, t2;
	rep(n-1){
		cin >> t1 >> t2;
		edges[t1].pb(t2);
	}

	//brute force every possible end point
	bool alltrue;

	for (int endp = 1; endp <= n; endp++)
	{
		alltrue = true;

		for (int st = 1; st <= n; st++){
			if (!dfs(endp, st)){
				alltrue = false;
				break;
			}
		}

		if (alltrue){
			cout << endp;
			return 0;
		}
	}
	
	cout << "-1";

	return 0;
}
