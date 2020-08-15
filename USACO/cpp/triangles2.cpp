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

int N;

int main() {
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);

    cin >> N;
    pii pointsX[N], pointsY[N];
    int temp, temp2;
    rep(N){
        cin >> temp >> temp2;
        pointsX[i] = mp(temp,temp2);
        pointsY[i] = mp(temp2,temp);
    }
    sort(pointsX,pointsX+N);
    sort(pointsY,pointsY+N);

    /*
        so first we get the sorted,
        for every point, we get the all the x's thats O(n), then we get all the Y's using a binary search
        then we can just compute them
    */

	return 0;
}
