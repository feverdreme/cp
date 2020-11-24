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

int t, n, k;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	ofstream cout ("input.in");

	cin >> t;
	while (t--){
		cin >> n >> k;

		string games;
		cin >> games;

		bool pw = false;

		for (int i=0;i<n;i++){

			if (games[i] == 'L'){
				if (pw){
					games[i] = 'W';
					k--;
					pw = true;

					if (k == 0) break;

				} else if (i != n-1 && games[i+1] == 'W'){
					games[i] == 'W';
					k--;
					pw = true;

					if (k == 0) break;
				} else {
					pw = false;
				}
			} else {
				pw = true;
			}
		}

		int score=0;
		pw = false;
		for (auto &i : games){
			if (i == 'W'){
				
				if (pw) score += 2;
				else score += 1;

				pw = true;

			} else {
				pw = false;
			}
		}

		cout << score << endl;
		
	}
	
	
	return 0;
}
