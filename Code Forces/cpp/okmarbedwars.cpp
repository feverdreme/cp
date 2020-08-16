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
#define R0F(i,a,b) for(int i=a;i>=0;i--)

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
string players;

pii extend(int pos){
	int lind = pos,rind = pos+1;

	//first do lind
	if (pos >= 2){
		//you can just subtract
		if (players[pos-1] == "R" && players[pos-2] == "L") lind = pos-1;
	} else if (pos == 1){
		if (players[pos-1] == "R" && players[N-1] == "L") lind = pos-1;
	} else if (players[N-1] == "R" && players[N-2] == "L") lind = N-1;

	//now do the rind
	if (pos <= N-4){
		if (players[pos+2] == "L" && players[pos+3] == "R") rind = pos+2;
	} else if (pos == N-3){
		if (players[pos+2] == "L" && players[0] == "R") rind = pos+2;
	} else if (pos == N-2){
		if (players[0] == "L" && players[1] == "R") rind = 0;
	} else if (pos == N-1 && players[1] == "L" && players[2] == "R") rind = 1;

	return mp(lind,rind);
}

int main() {
	cin >> t;
	while (t--){
		vec<pii> good;

		cin >> N;
		cin >> players;

		if (count(players.begin(), players.end(), players[0]) == N){
			cout << N / 2 << endl;
			continue;
		}

		int pos = players.find("RL");
		if (pos == -1) pos = N-1;

		good.pub(extend(pos));

	}

	return 0;
}
