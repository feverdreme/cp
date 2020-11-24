#include <bits/stdc++.h>

using namespace std;

typedef long long z;
typedef unsigned long long uz;
typedef long l;
typedef unsigned int ui;
typedef double d;

typedef vector<int> vi;
typedef vector<z> vz;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int,int> pii;
typedef pair<z,z> pzz;

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

#define OE <<endl
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

//python functions
template<class T>
vec<T> filter(vec<T> iter, T delim){
	vec<T> ret;
	fori (i,iter){
		if (i != delim){
			ret.pub(i);
		}
	}
	return ret;
}

vs ssplit(string s, char delim){
	stringstream ss(s);
	string token;
	vs ret;

	while(getline(ss,token,delim)){
		ret.pub(token);
	}
	ret = filter<string>(ret,"");
	return ret;
}

int r,g,b,w;

int nodd(int a, int b, int c, int d){
	int numodd = 0;
	if (a % 2) numodd++;
	if (b%2) numodd++;
	if (c%2) numodd++;
	if (d%2) numodd++;

	return numodd;
}

int oddthree(int a, int b, int c){
	int numodd = 0;
	if (a % 2) numodd++;
	if (b%2) numodd++;
	if (c%2) numodd++;

	return numodd;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> r >> g >> b >> w;

		int res = nodd(r,g,b,w);
		if (res <= 1){
			cout << "Yes";
		}
		else if (r && g && b){
			//theres a chance
			switch (oddthree(r,g,b)) {
				case 3:
					cout << "Yes";
					break;
				case 2:
					if (w%2) cout << "Yes";
					else cout << "No";
					break;
				case 1:
					if (w%2 == 0) cout << "Yes";
					else cout << "No";
					break;
			}

		} else {
			cout << "No";
		}
		cout << endl;


	}
	return 0;
}
