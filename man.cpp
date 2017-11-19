#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	string st = "wmanku";
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
			int i = 0;
			int div = 1;
			int ans;
			vector<char> a;
		while(1) {
			if(n%div) {
				ans = n/div + 1;
			}else {
				ans = n/div;
			}
			if(n > div) {
			a.push_back(st[ans%5]);
			}else {
				break;
			}
			div *= 5;
			n = n-div;
			i++;
		}
		for(int j = i-1;j >= 0;j-- ) {
			cout << a[j];
		}
		cout << endl;
		a.clear();
	}
	return 0;
}



