#include <bits/stdc++.h>

using namespace std;

typedef long long z;
typedef unsigned long long uz;
typedef long l;
typedef unsigned int ui;

typedef vector<int> vi;
typedef vector<z> vz;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int,int> pii;
typedef pair<z,z> pzz;

typedef priority_queue<int, vector<int>, less<int> > max_heap;

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

int r,g,b;

int main() {
	cin >> r >> g >> b;
	int totsiz = r + g + b;

	vec<pair<int,char>> vr, vb, vg;

	int token;
	rep(r){
		cin >> token;
		vr.pub(mp(token,'r'));
	}
	rep(g){
		cin >> token;
		vg.pub(mp(token,'g'));
	}
	rep(b){
		cin >> token;
		vb.pub(mp(token,'b'));
	}

	sort(vr.begin(), vr.end(), greater<pair<int,char>>());
	sort(vg.begin(), vg.end(), greater<pair<int,char>>());
	sort(vb.begin(), vb.end(), greater<pair<int,char>>());

	int totarea = 0;
	int ms;
	pair<int,char> ma;
	int mf;

	while (totsiz >= 2){
		pair<int,char> m1 = vr.back(), m2 = vg.back(), m3 = vb.back();

		ma = max(m1,m2,m3);

		char ccolor = ma.sec;
		mf = ma.fir;

		switch(ccolor){
			case 'r':
				vr.pob();
				if (m2.fir > m3.fir) {ms = m2.fir; vg.pob();}
				else {ms = m3.fir; vb.pob();}

				totarea += mf * ms;
				totsiz -= 2;
				break;
			case 'g':
				vg.pob();
				if (m1.fir > m3.fir) {ms = m1.fir; vr.pob();}
				else {ms = m3.fir; vb.pob();}

				totarea += mf * ms;
				totsiz -= 2;
				break;
			case 'b':
				vb.pob();
				if (m1.fir > m2.fir) {ms = m1.fir; vr.pob();}
				else {ms = m2.fir; vg.pob();}

				totarea += mf * ms;
				totsiz -= 2;
				break;
				
		}
	}

	cout << totarea << endl;


 	return 0;
}
