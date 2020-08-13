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
#define tup tuple
#define mp make_pair
#define mt make_tuple

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

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

int N, L;
int wt,xt,dt;
vec<tup<int,int,int>> pos;
vi weights;

int main() {
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);

	cin >> N >> L;
	rep(N){
		cin >> wt >> xt >> dt;
		// if (dt == -1) xt = L-xt;
		pos.pub(mt(xt,dt,wt));
	}

	vec<pii> fin[N];

	sort(pos.begin(), pos.end());
	// at the end, we wnat the pair<leftmostweight, leftmost -1> and pair<rightmost weight,rightmost 1> + time = dist
	//so we need two sets, the ORDERD set of directions along with their dists pair<dist,dir>
	//nad the ORDERED set of weights pair<weight>




	//now both are teh same size
	//we simply match left with -1 and right with 1


	return 0;
}
