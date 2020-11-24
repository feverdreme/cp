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
#define mp make_pair

//iterators
#define rep(i,a) for(int i=0; i<a;i++)
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

int main() {
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);

	cint(N);
	set<pii> coors;
	int t1,t2;
	rep(i,N){
		cin >> t1 >> t2;
		coors.insert(mp(t1,t2));
	}

	int area = 0;
	fori(c1,coors){
		fori(c2,coors){
			fori(c3,coors){
				if (c1 != c2 && c2 != c3 && c1 != c3){
					//check if tehy fit
					int x1 = c1.first, x2 = c2.first, x3 = c3.first, y1 = c1.second, y2 = c2.second, y3 = c3.second;
					if (x1 == x2 and x1 != x3 and y2 == y3 and y1 != y3){
						area = max(area, abs((y2-y1)*(x2-x3)));
					}
				}
			}
		}
	}
	cout << area;

	return 0;
}
