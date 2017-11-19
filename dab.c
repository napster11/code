#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		char c;
		double q,q1;
		q = 0.0;
		int n,i;
		scanf("%d",&n);
		double l[n],g[n],r[n];
		for(i = 0;i < n;i++) {
			scanf("%lf%lf%lf",&l[i],&g[i],&r[i]);
		}
		int k;

		scanf("%d",&k);
		getchar();
		scanf("%c",&c);

		if(c == 'L') {
			for(i = 0;i < n;i++) {
				q += l[i]/(l[i]+g[i]+r[i]);
			}
			//printf("%lf\n",q);
			q1 = l[k-1]/(l[k-1]+g[k-1]+r[k-1]);
			q = q1/q;
			printf("%.9lf\n",q);
		}else if(c == 'G') {
			for(i = 0;i < n;i++) {
				q += g[i]/(l[i]+g[i]+r[i]);
			}
			q1 = g[k-1]/(l[k-1]+g[k-1]+r[k-1]);
			q = q1/q;
			printf("%.9lf\n",q);
		}else if(c == 'R') {
			for(i = 0;i < n;i++) {
				q += r[i]/(l[i]+g[i]+r[i]);
			}
			q1 = r[k-1]/(l[k-1]+g[k-1]+r[k-1]);
			q = q1/q;
			printf("%.9lf\n",q);
		}
	}
	return 0;
}

