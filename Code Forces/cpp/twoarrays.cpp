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

ll t,n,T;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> t;
	while(t--){
		cin >> n >> T;

		vll arr (n);
		arr.empty();
		rep(n) cin >> arr[i];
		
		vec<short> ret(n);
		bool onWhite = true;

		for (ll i = 0; i<n; i++){

			ll num = arr[i];

			if (num * 2 == T) {
				if (onWhite){
					ret[i] = 1;
					onWhite = false;
				} else {
					ret[i] = 0;
					onWhite = true;
				}
				
				continue;
			}

			if (num == min(num, T-num)) ret[i] = 1;
			else ret[i] = 0;
		}

		disp(ret);
		cout << endl;

	}
	
	
	return 0;
}

/* cin >> n >> T;
		vll arr (n);

		rep(n) cin >> arr[i];

		vll white;
		vll black;
		ll arrsize = n;
		ll num;

		while(arr.size() > 0){
			num = arr.back();
			arrsize--;
			arr.pob();
			
			white.pb(arrsize);

			if (arr.size() == 0) break;
			auto it = find(arr.begin(), arr.end(), T-num);
			if (it == arr.end()){
				
				if (arr.size() == 0) break;

				num = arr.back();
				arrsize--;
				arr.pob();
				
				white.pb(arrsize);

			} else {
				if (arr.size() == 0) break;

				num = *it;
				arr.erase( remove(arr.begin(), arr.end(), num), arr.end());
				arrsize--;

				black.pb(it - arr.begin());
			}

		}

		vll ret (n);
		ret.empty();
		for (auto &i : white){
			ret[i] = 1;
		}
		for (auto &i : black){
			ret[i] = 0;
		}

		disp(ret);
		cout << endl; */