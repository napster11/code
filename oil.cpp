#include<iostream>
#include<queue>
#include<map>
using namespace std;
int vis[255][255];
int count,m,n;
map<int,int> mp;
int a[300][300];
bool check(int x,int y)
{
	if(x >= 0 && x < m && y >= 0 && y < n)
		return true;
	else 
		return false;
}
void mat(int x,int y)
{
	queue<int> q;
	q.push(x);
	q.push(y);
	vis[x][y] = 1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		int v = q.front();
		q.pop();
		//cout << "popped value is " << u << " , " << v << endl;
		count++;
		//vis[u][v] = 1;
		if(check(u,v+1)) {
			if(a[u][v+1] == 1 && vis[u][v+1] == 0) {
				q.push(u);
				q.push(v+1);
				vis[u][v+1] = 1;
			}
		}
		if(check(u,v-1)) {
			if(a[u][v-1] == 1 && vis[u][v-1] == 0) {
				q.push(u);
				q.push(v-1);
				vis[u][v-1] = 1;
			}
		}
		if(check(u-1,v)) {
			if(a[u-1][v] == 1 && vis[u-1][v] == 0) {
				q.push(u-1);
				q.push(v);
				vis[u-1][v] = 1;
			}
		}
		if(check(u+1,v)) {
			if(a[u+1][v] == 1 && vis[u+1][v] == 0) {
				q.push(u+1);
				q.push(v);
				vis[u+1][v] = 1;
			}
		}
	}
}
int main()
{
	while(1) {
		for(int i = 0;i < 255;i++) {
			for(int j = 0;j < 255;j++) {
				vis[i][j] = 0;
			}
		}
		int ans = 0;
		map<int,int>::iterator it;
		cin >> m >> n;
		if(m == 0 && n == 0) {
			break;
		}else {
			for(int i = 0;i < m;i++) {
				for(int j = 0;j < n;j++) {
					cin >> a[i][j];
				}
			}
			for(int i = 0;i < m;i++) {
				for(int j = 0;j < n;j++) {
					if(a[i][j] == 1 && vis[i][j] == 0) {
						//cout << "start nodes are " << i << " and " << j << endl;
						count = 0;
						mat(i,j);
						mp[count]++;
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
		for(it = mp.begin();it != mp.end();it++) {
			cout << (*it).first << " " << (*it).second << endl;
		}
		mp.clear();

	}
	return 0;
}
 
