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
#define get(i,x) get<i>(x)
#define fir first
#define sec second

//iterators
#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)

#define f0r(i,a) for(int i = 0;i<a;i++)

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

void setIO(string filename){
    freopen((filename+".in").c_str(),"r",stdin);
    freopen((filename+".out").c_str(),"w",stdout);
}

int N,K;
vec<pii> nums;

int main() {
//    setIO("gymnastics");
	freopen("gymnastics.in","r",stdin);
	freopen("gymnastics.out","w",stdout);

    cin >> K >> N;
    int session[N];
    for(int j=0;j<K;j++){
        rep(N){
            cin >> session[i];
        }
        for (int p1=0; p1<N;p1++){
            for (int p2=p1; p2<N;p2++){
                if (p1 < p2) nums.pub(mp(session[p1] , session[p2]));
            }
        }
    }
    set<pii> distinct (nums.begin(),nums.end());
	
	int ret = 0;
    fori(i,distinct){
        if (count(nums.begin(),nums.end(),i) == K) ret++;
    }

    cout << ret;
//cout << 1;



	return 0;
}
