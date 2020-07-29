// #include <iostream>
// #include <cstdio>
// #include <sstream>
// #include <fstream>
//
// #include <vector>
// #include <array>
// #include <deque>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <vector>
// #include <algorithm>
// #include <bitset>
// #include <string>
// #include <tuple>
// #include <utility>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long z;
typedef unsigned long long uz;
// typedef long l;
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

template<class T>
void reversearr(T arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int N,a1,a2,b1,b2;
long K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	cin >> N >> K >> a1 >> a2 >> b1 >> b2;

  int arr[N], darr[N];
	rep(i,N){
		arr[i] = i+1;
		darr[i] = i+1;
	}

	long cyclecount = 0;

	rep(i,K){
		reversearr(arr,a1-1,a2-1);
		reversearr(arr,b1-1,b2-1);
		if (arr == darr or i == K-1){
			cyclecount = i+1;
			break;
		};
	}

	if (cyclecount != K){
		//then this is the cycle
		rep(i,K%cyclecount){
			reversearr(arr,a1-1,a2-1);
			reversearr(arr,b1-1,b2-1);
		}
	}

	fori(i,arr){
		cout << i OE;
	}


	return 0;
}
