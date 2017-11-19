#include<iostream>
#include<vector>
using namespace std;
#define l 10000000
int main()
{
	//int a[1000001] = {0};
	//int b[1000001];
	vector<long long int> b(l); 
	vector<long long int> a(l,0);
	for(long long int i  = 2;i <= l;i++) {
		if(a[i] == 0) {
			long long int temp = 1;
			while(temp*i <= l) {
				if(a[temp*i] == 0) {
					a[temp*i] = i;
				}
				temp++;
			}
		}
	}
	b[0] = 0;
	for(long long int i = 1;i <= l;i++) {
		b[i] = b[i-1] + a[i];
		//cout << b[i] << " ";
	}
	int t;
	cin >> t;
	while(t--) {
		long long int n;
		cin >> n;
		cout << b[n] << endl;
	}
	return 0;
}
