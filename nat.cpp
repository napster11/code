#include<iostream>
#include<queue>
using namespace std;
int ans = 0;
bool check(int sx,int sy,int m,int n,char ch[105][105])
{
	if(sx >= 0 && sx < m && sy >= 0 && sy < n) {
		if(ch[sx][sy] == '*' ) {
			return false;
		}else if(ch[sx][sy] == 'O' || ch[sx][sy] == '#'){
			return true;
		}
	}else {
		return false;
	}
}
int bfs(int a[105][105],char ch[105][105],int sx,int sy,int dx,int dy,int m,int n)
{
	int vis[105][105] = {0};
	queue<int> q1;
	q1.push(sx);
	q1.push(sy);

	vis[sx][sy] = 1;
	while(!q1.empty()) {
		int u = q1.front();
		q1.pop();
		int v = q1.front();
		q1.pop();
		cout << "poped values are " << u << " and " << v << endl; 
		if(check(sx-1,sy,m,n,ch)) {
			if(vis[sx-1][sy] == 0 || a[sx-1][sy] > a[sx][sy] + 1) {
				q1.push(sx-1);
				q1.push(sy);
				a[sx-1][sy] = a[sx][sy] + 1;
				vis[sx-1][sy] = 1;
			}
		}
		if(check(sx+1,sy,m,n,ch)) {
			if(vis[sx+1][sy] == 0 || a[sx+1][sy] > a[sx][sy] + 1) {
				q1.push(sx+1);
				q1.push(sy);
				a[sx+1][sy] = a[sx][sy] + 1;
				vis[sx+1][sy] = 1;
			}
		}
		if(check(sx,sy-1,m,n,ch)) {
			if(vis[sx][sy-1] == 0 || a[sx][sy-1] > a[sx][sy] + 1) {
				q1.push(sx);
				q1.push(sy-1);
				a[sx][sy-1] = a[sx][sy] + 1;
				vis[sx][sy-1] = 1;
			}
		}
		if(check(sx,sy+1,m,n,ch)) {
			if(vis[sx][sy+1] == 0 || a[sx][sy+1] > a[sx][sy] + 1) {
				q1.push(sx);
				q1.push(sy+1);
				a[sx][sy+1] = a[sx][sy] + 1;
				vis[sx][sy+1] = 1;
			}
		}
	}
	if(q1.empty()) {
		if(a[dx][dy] != 100000) {
			return a[dx][dy];
		}else {
			return -1;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int a[105][105];
		for(int i = 0;i < 105;i++) {
			for(int j  = 0;j < 105;j++) {
				a[i][j] = 100000;
			}
		}
		int n,m,sx,sy,dx,dy;
		cin >> m >> n;
		char ch[105][105];
		for(int i = 0;i < m;i++) {
			for(int j = 0;j < n;j++) {
				cin >> ch[i][j];
				if(ch[i][j] == '$') {
					sx = i;
					sy = j;
				}
				if(ch[i][j] == '#') {
					dx = i;
					dy = j;
				}
			}
		}
		a[sx][sy] = 0;
		//cout << sx << sy << dx << dy << endl;
		int temp = bfs(a,ch,sx,sy,dx,dy,m,n);
		for(int i = 0;i < m;i++) {
			for(int j = 0;j < n;j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << temp << endl;
	}
	return 0;
}


