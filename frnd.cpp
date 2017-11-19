#include<iostream>
#include<map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		unsigned long long int sum = 0;
		int n;
		cin >> n;
		map<unsigned long long int,unsigned long long int> m;
		map<unsigned long long int,unsigned long long int>::iterator it;
		for(int i = 0;i < n;i++) {
			unsigned long long int a[10] = {0};
			unsigned long long int temp,c;
			cin >> temp;
			while(temp > 0) {
				c = temp%10;
				//cout << " c is " << c << endl;
				if(a[c] == 0) {
					m[c]++;
					a[c] = 1;
				}
				temp /= 10;
			}
		}
		for(it = m.begin();it != m.end();it++) {
			unsigned long long int ans = (*it).second;
			sum += (ans*(ans-1))/2;
		}
		cout << sum << endl;
	}
	return 0;
}
