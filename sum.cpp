#include<iostream>
#include<vector>
# define e 1000000003
using namespace std;
int main()
{
	unsigned long long int a[1000001];
	a[0] = 0;
	unsigned long long int temp;
	vector<unsigned long long int> v;
	v.push_back(0);
	for(unsigned long long int i = 1;i <= 1000000;i++) {
		a[i] = (a[i-1] %e + (i*i*i) %e) %e;
		//cout << a[i] << endl;
	}
	for(int i = 1;i <= 1000000;i++) {
		temp = (a[i]%e + v[i-1]%e ) %e;
		v.push_back(temp);
	}
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		cout << v[k] << endl;
	}
	return 0;
}




