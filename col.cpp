#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		int count = 0;
		int st[1000001] = {0};
		int pos[1000001] = {0};
		cin >> n;
		int a[n];
		for(int i = 0;i < n;i++) {
			cin >> a[i];
			st[a[i]] = 1;
		}
		sort(a,a+n);
		for(int i = 0;i < n;i++) {
			int temp = a[i];
			if(pos[a[i]] == 0) {
				if(2*temp <= 1000001 && st[2*temp] == 1) {
					count++;
					pos[2*temp] = 1;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
