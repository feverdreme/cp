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

int t;
string binstring;

int findfirstone(string & str){
	int ret = -1;
	rep(str.length()){
		if (str[i] == '1'){
			ret = i;
			break;
		}
	}
	return ret;
}

pii findsmallestblock(string & binstr){
	//the pii returns the pos and size
	int firocc = findfirstone(binstr);
	if (firocc != -1){
		//proceed
		vs blocks = ssplit(binstr, '0');
		string maxele = *max_element(blocks.begin(), blocks.end());

		int found = binstr.find(maxele);
		return mp(found, maxele.length());


	} else return mp(-1,-1);

}

int main() {
	cin >> t;
	while (t--){
		cin >> binstring;

		//greedy remove smallest block
		int firstone =  findfirstone(binstring);
		int aer = 0;
		int turns = 0;
		while (firstone != -1){
			turns++;
			pii possize  = findsmallestblock(binstring);
			binstring.erase(possize.fir, possize.sec);

			firstone = findfirstone(binstring);

			if (turns % 2) aer += possize.sec;
		}

		cout << aer << endl;

	}


	return 0;
}
