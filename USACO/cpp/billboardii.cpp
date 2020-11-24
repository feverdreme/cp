#include <iostream>
#include <string>

#pragma GCC optimize("Ofast")
// #pragma GCC optimize ("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

void setIO(string filename){
	freopen((filename + ".in").c_str(), "r" , stdin);
	freopen((filename + ".out").c_str(), "w" , stdout);
}

/*
Time complexities

O(n) = 10^8
O(n^2) = 10^4
O(n^3) = 200
O(logn) = Very big number, fucking massive 10^(4 * 10^8)
O(nlogn) = 10^7
O(2^n) = 24
*/

/*
2 1 7 4
5 -1 10 3
*/

int x1, x2, y1, y2;
int w1, w2, z1, z2;

int main() {
	std::ios_base::sync_with_stdio(false);cin.tie(0);

	setIO("billboard");

	cin >> w1 >> z1 >> w2 >> z2 >> x1 >> y1 >> x2 >> y2;

	//check if it completely goes on up, down, left, right

	//we also check if it completely covers it

	//check if its above or below
	if (x1 <= w1 && x2 >= w2){
		//if all
		if (y1 <= z1 && y2 >= z2){
			cout << "0";
			goto endlbl;
		}

		//if below
		if (y1 <= z1 && y2 < z2){

			int ret = (z2 - y2) * (w2 - w1);
			cout << ret;
			goto endlbl;
		}

		//if up
		if (y1 > z1 && y2 >= z2){

			int ret = (y1 - z1) * (w2 - w1);
			cout << ret;
			goto endlbl;
		}
	}

	if (y2 >= z2 && y1 <= z1){
		//if left
		if (x1 <= w1 && x2 < w2){

			int ret = (w2 - x2) * (z2 - z1);
			cout << ret;
			goto endlbl;
		}

		//if right
		if (x2 >= w2 && x1 > w1){

			int ret = (w1 - x1) * (z2 - z1);
			cout << ret;
			goto endlbl;
		}
	}

	cout << (w2 - w1) * (z2 - z1);

	endlbl:
	return 0;
}
