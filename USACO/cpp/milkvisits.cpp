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

#define rep(a) for(int i=0; i<a;i++)
#define range(i,a,b) for(int i=a;a<b;i++)
#define fori(i,iter) for(auto i:iter)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

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

int N,M;
char cows[10001];
//adjacency list
vi adj[10001];

//we create a set of sets of cows
set<set<int>> groups;

//generate all the groups
set<int> traversed;
set<int> untraversed;

void dfs(int *node, set<int> *path){
    //while theres an undiscovered element in the set
    fori(pos,adj[*node]){
        //if the node is not in the path and not in the traversed set

    }
}

int main() {
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);

    cin >> N >> M;
    rep(N){
        cin >> cows[i];
    }

    int a,b;
    rep(N){
        //add to the adjaceny list
        cin >> a >> b;
        adj[a].pub(b);
        adj[b].pub(a);
        untraversed.insert(i+1);
    }

    //do the dfs with the set of elements
    set<int> path;
    while (traversed.size() != N){
        dfs(traversed.begin(),&path);
    }


	return 0;
}
