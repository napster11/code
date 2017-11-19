#include<iostream>
#include<queue>
using namespace std;
int vis[100][100] = {0};
int vis1[100][100] = {0};
int fr[100][100] = {0};
int ar[100][100] = {0};
int cost[100][100] = {0};
char a[100][100];
int sx,sy,dx,dy,fx,fy;
bool check(char a[100][100],int x,int y,int r,int c)
{
	if(x >= 0 && x <= r-1 && y >= 0 && y <= c-1) {
		if(a[x][y] == '.' || a[x][y] == 'D') {
			return true;
		}else if(a[x][y] == '*' || a[x][y] == 'X') {
			return false;
		}
	}else {
		return false;
	}
}
bool check1(char a[100][100],int x,int y,int r,int c)
{
	if(x >= 0 && x <= r-1 && y >= 0 && y <= c-1) {
		if(a[x][y] == '.' || a[x][y] == 'S') {
			return true;
		}else if(a[x][y] == 'X' || a[x][y] == 'D') {
			return false;
		}
	}else {
		return false;
	}
}
void bfs(char a[100][100],int r,int c)
{
	queue<int> q;
	q.push(fx);
	q.push(fy);
	vis1[fx][fy] = 1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int v = q.front();
		q.pop();

		if(check1(a,u-1,v,r,c)) {
			if(vis1[u-1][v] == 0) {
				vis1[u-1][v] = 1;
				fr[u-1][v] = fr[u][v] + 1;
				q.push(u-1);
				q.push(v);
			}
		}
		if(check1(a,u+1,v,r,c)) {
			if(vis1[u+1][v] == 0) {
				vis1[u+1][v] = 1;
				fr[u+1][v] = fr[u][v] + 1;
				q.push(u+1);
				q.push(v);
			}
		}
		if(check1(a,u,v-1,r,c)) {
			if(vis1[u][v-1] == 0) {
				vis1[u][v-1] = 1;
				fr[u][v-1] = fr[u][v] + 1;
				q.push(u);
				q.push(v-1);
			}
		}
		if(check1(a,u,v+1,r,c)) {
			if(vis1[u][v+1] == 0) {
				vis1[u][v+1] = 1;
				fr[u][v+1] = fr[u][v] + 1;
				q.push(u);
				q.push(v+1);
			}
		}
	}
}
void move(char a[100][100],int r,int c) 
{
	queue<int> q;
	q.push(sx);
	q.push(sy);
	vis[sx][sy] = 1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int v = q.front();
		q.pop();

		//cout << "popped value are " << u << " and " << v << endl;
		if(check(a,u-1,v,r,c)) {
			if((ar[u][v] + 1 < fr[u-1][v]) && (vis[u-1][v] == 0 || ar[u][v] + 1 < cost[u-1][v])) {
				//cout << " moved up at " << u-1 << " and " << v << endl;
				cost[u-1][v] = ar[u][v]+1;
				ar[u-1][v] = ar[u][v]+1;
				vis[u-1][v] = 1;
				q.push(u-1);
				q.push(v);
			}
		}
		if(check(a,u+1,v,r,c)) {
			if((ar[u][v] + 1 < fr[u+1][v]) && (vis[u+1][v] == 0 || ar[u][v] + 1 < cost[u+1][v])) {
				//cout << " moved down at " << u+1 << " and " << v  << endl;
				cost[u+1][v] = ar[u][v] + 1;
				ar[u+1][v] = ar[u][v] + 1;
				vis[u+1][v] = 1;
				q.push(u+1);
				q.push(v);
			}
		}
		if(check(a,u,v-1,r,c)) {
			if((ar[u][v] + 1 < fr[u][v-1]) && (vis[u][v-1] == 0 || ar[u][v] + 1 < cost[u][v-1])) {
				//cout << " moved left at " << u << " and " << v-1 << endl;
				cost[u][v-1] = ar[u][v]+1;
				ar[u][v-1] = ar[u][v] +1;
				vis[u][v-1] = 1;
				q.push(u);
				q.push(v-1);
			}
		}
		if(check(a,u,v+1,r,c)) {
			if((ar[u][v] + 1 < fr[u][v+1]) && (vis[u][v+1] == 0 || ar[u][v] + 1 < cost[u][v+1])) {
				//cout << " moved right at " << u << " and " << v+1 << endl;
				cost[u][v+1] = ar[u][v]+1;
				ar[u][v+1] = ar[u][v] + 1;
				vis[u][v+1] = 1;
				q.push(u);
				q.push(v+1);
			}
		}
	}
	if(cost[dx][dy] == 10000 || cost[dx][dy] == 0) {
		cout << "KAKTUS\n";
	}else {
		cout << cost[dx][dy] << endl;
	}
}
int main()
{
	int r,c;
	cin >> r >> c;
	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			char c;
			cin >> a[i][j];
			if(a[i][j] == 'D') {
				dx = i;
				dy = j;
			}else if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			}else if(a[i][j] == '*') {
				fx = i;
				fy = j;
			}else if(a[i][j] == 'X') {
				ar[i][j] = -1;
			}
		}
	}
	fr[dx][dy] = 10000;
	//cout << sx << sy << dx << dy << endl;
	//cout << "dest. has initial value is " << fr[dx][dy] << endl;
	bfs(a,r,c);
	/*for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			cout << fr[i][j] << " ";
		}
		cout << endl;
	}*/
	move(a,r,c);
	/*for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}


