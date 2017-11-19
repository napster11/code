#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n,k,a,b,ans;
		cin >> n;
		char ar[n];
		a = 0;
		b = 0;
		ans = 0;
		for(int i = 0;i < n;i++) {
			cin >> ar[i];;
			if(ar[i] == '1') {
				a++;
			}else {
				b++;
			}
		}
		int j = n-1;
		while(j >= 0) {
			cout << "a and b are " << a << " " << b << endl;
			if(a > b) {
				ans  = j+1;
				break;
			}else {
				if(ar[j] == '1') {
					a--;
				}else {
					b--;
				}
			}
			j--;
		}
		cout << ans << endl;
	}
	return 0;
}
