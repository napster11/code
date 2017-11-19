#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int c[26] = {0};
		string a = "aeiou";
		string b = "bcdfghjklmnpqrstvwxyz";
		string s;
		cin >> s;
		int temp;
		for(int i = 0;i < s.length();i++) {
			if(s[i]==97||s[i]==101||s[i]==105||s[i]==111||s[i]==117) {
				temp = (c[s[i]-97]*5 + a.find(s[i]))%21;
				cout << b[temp];
				c[s[i]-97]++;
			}else {
				temp = (c[s[i]-97]*21 + b.find(s[i]))%5;
				cout << a[temp];
				c[s[i]-97]++;
			}
		}
		cout << endl;
	}
	return 0;
}

