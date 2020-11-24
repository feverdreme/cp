#include <bits/stdc++.h>

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
#define space " "
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

int N,M,Sx,Sy;
int main() {
	cin >> N >> M >> Sy >> Sx;

	//do the entire row, ending on a border, then keep
	cout << Sy << " " << Sx << endl;

	for (int x = 1;x<=M;x++){
		if (x != Sx) cout << Sy << space << x << endl;
	}
	//do the top now
	int currx = M;
	for (int y = Sy-1; y>=1 ; y--){
		if (currx == M){
			for (int x=M; x>=1; x--){ cout << y << space << x << endl; currx = 1;}
		} else {
			for (int x=1; x <= M; x++){cout << y << space << x << endl; currx = M;}
		}
	}

	//do the bottom
	for (int y = Sy+1;y<=N;y++){
		if (currx == M){
			for (int x=M; x >= 1; x--){cout << y << space << x << endl; currx = 1;}
		} else {
			for (int x=1; x <= M; x++){cout << y << space << x << endl; currx = M;}
		}
	}


	return 0;
}
