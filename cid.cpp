#include<iostream>
#define e 1000000007
using namespace std;
unsigned long long int pw(unsigned long long int n,unsigned long long int l)
{
	unsigned long long int ans = 1;
	while(l) {
		if(l%2) {
			ans = (ans*n)%e;
		}
		n = (n*n)%e;
		l /= 2;
	}
	return ans;
}
int main()
{
	while(1) {
		unsigned long long int n,l,sum;
		sum = 0;
		cin >> n >> l;
		if(n == 0 && l == 0) {
			break;
		}else {
			for(unsigned long long int i = 1;i <= l;i++) {
				sum += pw(n,i)%e;
			}
		}
		cout << sum%e << endl;
	}
	return 0;
}

