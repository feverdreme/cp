#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

//iterators
#define rep(a) for(long long i=0; i<a;i++)
#define space ' '
// #define cout cout<<


long long n;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> n;

	if (n == 1){
		long long temp;
		cin >> temp;
		printf("1 1\n%d\n1 1\n0\n1 1\n0", -temp);

		return 0;
	}

	vector<long long> nums (n);
	rep(n){
		cin >> nums[i];
	}
	
	cout << "1 1" << endl;
	cout << -nums[0] << endl;

	cout << "2 " << n << endl;
	rep(n-1){
		cout << nums[i+1] * (n-1) << space;
	}
	cout << endl;

	cout << "1 " << n << endl;

	cout << 0 << space;
	rep(n-1){
		cout << -nums[i+1] * n << space;
	}
	cout << endl;
	
	return 0;
}
