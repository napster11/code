#include<iostream>
#include<queue>
using namespace std;
int count;
class node {
public:
	int x;
	int y;
	int l;
	node(int a,int b,int c) {
		x = a;
		y = b;
		l = c;
	}
};
bool check(int a,int b,int c,int d)
{
	if(a >= 0 && a <= c-1 && b >= 0 && b <= d-1) {
		return true;
	}else {
		return false;
	}
}
int bfs(char a[10][20][20],int n,int m,int p,node c,int dis[10][20][20])
{
	queue<node> q;
	int u = c.x;
	int v = c.y;
	int r = c.l;
	a[r][u][v] = '1';
	dis[r][u][v] = 0;

	if(u == n-1 && v == m-1) return 0;
	q.push(c);

	while(!q.empty()) {
		int e = q.front().x;
		int f = q.front().y;
		int g = q.front().l;
		q.pop();
		//cout << e << " " << f << " " << g << endl;
		
		int i = (g+1)%p;
		if(check(e-1,f,n,m)) {
			if(a[i][e-1][f] == '0') {
				a[i][e-1][f] = '1';
				dis[i][e-1][f] = dis[g][e][f] + 1;
				//cout << "u-value is " << dis[i][e-1][f] << endl;
				if(e-1 == n-1 && f == m-1) return dis[i][e-1][f];
				q.push(node(e-1,f,i));
			}
		}
		if(check(e+1,f,n,m)) {
			if(a[i][e+1][f] == '0') {
				a[i][e+1][f] = '1';
				dis[i][e+1][f] = dis[g][e][f] + 1;
				//cout << "d-value is " << dis[i][e+1][f] << endl;
				if(e+1 == n-1 && f == m-1) return dis[i][e+1][f];
				q.push(node(e+1,f,i));
			}
		}
		if(check(e,f-1,n,m)) {
			if(a[i][e][f-1] == '0') {
				a[i][e][f-1] = '1';
				dis[i][e][f-1] = dis[g][e][f] + 1;
				//cout << "l-value is " << dis[i][e][f-1] << endl;
				if(e == n-1 && f-1 == m-1) return dis[i][e][f-1];
				q.push(node(e,f-1,i));
			}
		}
		if(check(e,f+1,n,m)) {
			if(a[i][e][f+1] == '0') {
				a[i][e][f+1] = '1';
				dis[i][e][f+1] = dis[g][e][f] + 1;
				//cout << "r-value is " << dis[i][e][f+1] << endl; 
				if(e == n-1 && f+1 == m-1) return dis[i][e][f+1];
				q.push(node(e,f+1,i));
			}
		}
	}
	return -1;
}
int main()
{
	int pt = 1;
	while(1) {
		int n,m,c;
		node temp(0,0,0);
		cin >> n >> m >> c;
		if(n == 0 && m == 0 && c == 0) {
			break;
		}else {
			count = 0;
			char a[10][20][20];
			int dis[10][20][20];
			for(int i = 0;i < 10;i++) {
				for(int j = 0;j < 20;j++) {
					for(int k = 0;k < 20;k++) {
						dis[i][j][k] = 0;
					}
				}
			}
			for(int i = 0;i < c;i++) {
				for(int j = 0;j < n;j++) {
					for(int k = 0;k < m;k++) {
						cin >> a[i][j][k];
						//cout << "val is " << a[i][j][k] << endl;
					}
				}
			}
			//cout << temp.x << temp.y << temp.l << endl;
			int ans = bfs(a,n,m,c,temp,dis);
			if(ans >= 0) {
				cout <<"Case " << pt << ": Luke and Leia can escape in " << ans << " steps." << endl;
			}else {
				cout << "Case " << pt << ": Luke and Leia cannot escape." << endl;
			}
		}
		pt++;
	}
	return 0;
}
