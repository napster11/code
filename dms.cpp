#include<iostream>
using namespace std;
string cop(char e[])
{
        string s;
	int i = 0;
	while(e[i] != '\0') {
		s[i] = e[i];
		i++;
	}
	return s;
}
int check(int a,int u[10],int n)
{
    vector<int> pt;
    vector<int> :: iterator it;
    while(a >= 10) {
        pt.push_back(a%10);
        a /= 10;
    }
    pt.push_back(a);
    for(it = pt.end()-1;it >= pt.begin();it--) {
        u[n] = (*it);
        n++;
    }
    return n;
}
int main()
{
	while(!cin.eof()) {
		int s,n;
		string r;
		int u[15];
		cin >> s >> r;
		n = check(s,u,0);
		int a[15] = {0};
		char ch[n+1][252];
		int i = 0;
		int temp = r.length();
		int k = 0;
		int flag = 1;
		if(n%2 == 0) {
			int row = temp/n;
			if(row%2 == 0) {
				fill(a,u,1);

}
