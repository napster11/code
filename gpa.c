#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
		a = 0;
	}else if(p >= 81) {
		a = 1;
	}else if(p >= 71) {
		a = 2;
	}else if(p >= 61) {
		a = 3;
	}else if(p >= 51) {
		a = 4;
	}else {
		a = 5;
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
	scanf("%d",&n);
	while(n--) {
		int i,j;
		char s1[100],st[100];
		double tot;
		int flag;
		flag = 0;
		double grade;
		tot = 0;
		double cr[6],mr[6];
		double m[6][5];
		double mar,at,mi,sum;
		for(i = 0;i < 6;i++) {
			scanf("%s",s1);
			cr[i] = atof(s1);
			tot += cr[i];
		}
		for(i = 0;i < 6;i++) {
			for(j = 0;j < 5;j++) {
				scanf("%s",st);
				if(st[0] == 'a') {
					m[i][j] = 0;
				}else {
					m[i][j] = atof(st);
				}
			}
			at = atd(m[i][4]);
			mi = min(m[i][0],min(m[i][1],m[i][2])); 
			sum = m[i][0] + m[i][1] + m[i][2];
			sum = sum - mi;
			sum = (sum*9)/8;
			mar = at + sum + (m[i][3]/2.0);

			//printf("%lf\n",mar);
			mr[i] = cal(mar);
			//printf("%lf\n",mr[i]);
		}
		for(i = 0;i < 6;i++) {
			grade += cr[i]*mr[i];
			if(mr[i] == 0.0) {
				flag = 1;
			}
		}
		if(flag == 1) {
			printf("FAILED, ");
		}else {
			printf("PASSED, ");
		}
		printf("%.2lf\n",grade/tot);
	}
	return 0;
}



