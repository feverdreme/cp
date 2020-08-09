#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <tuple>
#include <utility>
#include <cmath>

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

//iterators
#define rep(i,a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define OE <<endl
// #define cout cout<<
#define cint(n) int n;cin>>n;
#define dvec(v) fori(i,v){cout << i OE;}

void setIO(string io){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((io + ".in").c_str(),"r",stdin);
	freopen((io + ".out").c_str(),"w",stdout);
}

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

int main() {
	setIO("photo");
	cint(N);

	int nums[N-1];
	rep(i,N-1){
		cin >> nums[i];
	}

	int used[N];
	set<int> usedset;

	range(i,1,N){
		if (i == 1){
			used[0] == i;
			usedset.insert(i);
		} else {
			int newnum = nums[i]
		}
	}

	return 0;
}
