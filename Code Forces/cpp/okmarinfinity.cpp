#include <bits/stdc++.h>

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
#define pub push_back
#define pob pop_back
#define tup tuple
#define mp make_pair
#define mt make_tuple
#define get(i,x) get<i>(x)
#define fir first
#define sec second

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define F0R(i,a) for(int i = 0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define R0F(i,a) for(int i=a;i>=0;i--)

#define OE <<endl
#define space ' '
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dvec(v) fori(i,v){cout << i OE;}

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

int t, N;
ll K;

int main() {
	cin >> t;

	while (t--){
		cin >> N >> K;
		int arr[N];
		bool zex = false;
		rep(N){
			cin >> arr[i];
		}

		if (K == 0){
			fori(i,arr) cout << i << space;
			cout << endl;
			continue;
		}

		int maxn = *max_element(arr,arr+N);

		rep(N) arr[i] = maxn - arr[i];

		if (K == 1) {
			fori(i,arr) cout << i << space;
			cout << endl;
			continue;
		} else if (K % 2 == 0) {
			maxn = *max_element(arr, arr+N);
			rep(N) arr[i] = maxn - arr[i];
			fori(i,arr) cout << i << space;
			cout << endl;
			continue;
		} else {
			maxn = *max_element(arr, arr+N);
			rep(N) arr[i] = maxn - arr[i];
			maxn = *max_element(arr, arr+N);
			rep(N) arr[i] = maxn - arr[i];

			fori(i,arr) cout << i << space;
			cout << endl;
			continue;
		}


	}

	return 0;
}
