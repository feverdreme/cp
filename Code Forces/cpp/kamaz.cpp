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
#define pb push_back
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

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

int t, n;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	
	cin >> t;
	while(t--){
		cin >>> n;
		vi arr (n);
		rep(n) cin >> arr[i];

		map<int,int> sinceseen;

		for (auto &i : arr){
			sinceseen.insert({i, 0});
		}

		map<int,int> maxseen (sinceseen.begin(), sinceseen.end());

		F0R(i,n){
			int num = arr[i];
			int lastseen = sinceseen[num];
			sinceseen[num] = i;

			maxseen[num] = max(maxseen[num], i - lastseen);
		}

		for (auto &i : sinceseen){
			maxseen[i.fir] = max(maxseen[i.fir] , n - sinceseen[i.sec]);
		}

		vi ret (n, -1);
		sort(maxseen.begin(), maxseen.end());

		for (auto &i : maxseen){
			int num = i.sec + 1;

			if (ret[num] != -1){
				ret[num] = i.fir;
			}
		}

		disp(ret);
		cout << endl;
		

	}

	
	return 0;
}
