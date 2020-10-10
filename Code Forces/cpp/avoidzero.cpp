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

vi rearrange(vi &arr){

	vi ret;
	ret.empty();
	
	set<int> check (arr.begin(), arr.end());
	if (check.size() == 2){
		auto it = check.begin();
		int m1 = *it;
		check.erase(it);
		it = check.begin();
		int m2 = *it;
		check.erase(it);

		int c1 = count(arr.begin(), arr.end(), m1);
		int c2 = count(arr.begin(), arr.end(), m2);

		if (c1 > c2){
			rep(c1) ret.pb(m1);
			rep(c2) ret.pub(m2);
		} else {
			rep(c2) ret.pb(m2);
			rep(c1) ret.pub(m1);
		}

		if (ret[0] == 0){
			reverse(ret.begin(), ret.end());
		}

		return ret;
	} else if (check.size() == 1){

		rep(arr.size()) ret.pb(arr[0]);

		return ret;
	}

	int currsum = 0;

	while (arr.size() != 0){

		for (auto &i : arr){
			if (currsum + i != 0){
				ret.pb(i);
				
				for (int j=0;j<arr.size();j++){
					if (arr[j] == i){
						arr.erase(arr.begin() + j);
						break;
					}
				}

				currsum += i;
				break;
			}
		}
	}

	if (ret[0] == 0){
		reverse(ret.begin(), ret.end());
	}

	return ret;
}

int t, n;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> t;

	while(t--){
		cin >> n;

		vi arr(n);
		arr.empty();

		rep(n){
			cin >> arr[i];
		}

		int s = 0;
		for (auto &i : arr){
			s += i;
		}

		sort(arr.begin(), arr.end());

		if (s != 0){
			cout << "YES" << endl;
			
			for (auto &i : rearrange(arr)) cout << i << space;

		} else cout << "NO";

		cout << endl;
	}
	
	
	return 0;
}
