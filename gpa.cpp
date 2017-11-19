#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
double min(double a,double b)
{
	if(a < b)
		return a;
	else
		return b;
}
double atd(double p)
{
	double a;
	if(p >= 91) {
		a = 0.0;
	}else if(p >= 81) {
		a = 1.0;
	}else if(p >= 71) {
		a = 2.0;
	}else if(p >= 61) {
		a = 3.0;
	}else if(p >= 51) {
		a = 4.0;
	}else {
		a = 5.0;
	}
	return a;
}
double cal(double a)
{
	double pt;
	if(a >= 91) {
		pt = 10;
	}else if(a >= 81) {
		pt = 9;
	}else if(a >= 71) {
		pt = 8;
	}else if(a >= 61) {
		pt = 7;
	}else if(a >= 51) {
		pt = 6;
	}else if(a == 50) {
		pt = 5;
	}else {
		pt = 0;
	}
	return pt;
}
int main()
{
	int n;
	cin >> n;
	while(n--) {
		char s[100],st[100];
		double tot = 0;
		double cr[6],mr[6];
		double m[6][5];
		for(int i = 0;i < 6;i++) {
			cin >> s;
			cr[i] = atof(s);
			tot += cr[i];
		}
		for(int i = 0;i < 6;i++) {
			for(int j = 0;j < 5;j++) {
				cin >> st;
				if(st[0] == 'a') {
					m[i][j] = 0;
				}else {
					m[i][j] = atof(st);
				}
			}
			double mar;
			double at = atd(m[i][4]);
			double mi = min(m[i][0],min(m[i][1],m[i][2])); 
			double sum = m[i][0] + m[i][1] + m[i][2];
			sum = sum - mi;
			sum = (sum*9)/8;
			mar = at + sum + (m[i][3]/2.0);
			mr[i] = cal(mar);
		}
		int flag = 0;
		double grade;
		for(int i = 0;i < 6;i++) {
			grade += cr[i]*mr[i];
			if(mr[i] == 0.0) {
				flag = 1;
			}
		}
		if(flag == 1) {
			cout << "FAILED, ";
		}else {
			cout << "PASSED, ";
		}
		cout << grade/tot << endl;
	}
	return 0;
}



