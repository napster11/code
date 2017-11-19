#include<iostream>
#include<map>
#include<cstring>
#include<sstream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	getchar();
	while(t--) {
		string s,s1;
		getline(cin,s);
		map<string,int> st;
		stringstream ss;

		ss << s;
		while(ss >> s1) {
			//cout << s1 << endl;
			st[s1]++;
		}
		cout << st.size() << endl;
	}
	return 0;
}
			
