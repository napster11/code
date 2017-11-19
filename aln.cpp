#include<iostream>
using namespace std;
int main()
{
	int n,max;
	cin >> n >> max;
	int a[n],b[n],at[n],bt[n];
	
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int j = 0;j < n;j++) {
		cin >> b[j];
	}

	at[0] = a[0];
	bt[0] = b[0];

	for(int i = 1;i < n;i++) {
		if(at[i-1]+a[i] < bt[i-1]+b[i]+a[i]) {
			at[i] = at[i-1]+a[i];
		}else {
			at[i] = bt[i-1]+b[i]+a[i];
		}

		if(bt[i-1]+b[i] < at[i-1]+a[i]+b[i]) {
			bt[i] = bt[i-1]+b[i];
		}else {
			bt[i] = at[i-1]+a[i]+b[i];
		}
	}
	int q,temp;
	for(int k = n-1;k >= 0;k--) {
		if(at[k] < bt[k]) {
			if(at[k] <= max) {
				q = 1;
				temp = k;
			}
		}else {
			if(bt[k] <= max) {
				q = 2;
				temp = k;
			}
		}
		if(q == 1||q == 2) {
			break;
		}
	}
	if(q == 1) {
		cout << temp+1 << " " << at[temp] << endl;
	}else {
		cout << temp+1 << " " << bt[temp] << endl;
	}
	return 0;
}
