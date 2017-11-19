#include<iostream>
#include<queue>
#include<algorithm>
//#define e 10000
using namespace std;
int vis[205][205];
int cost[205][205];
int at[205][205];
int p[205][205];
char ar[205][205];
int n,m,a,b,c,d;
bool check(int x,int y,int n,int m)
{
	if(x >= 0 && x <= n-1 && y >= 0 && y <= m-1) {
		return true;
	}else {
		return false;
	}
}
void match(char ar[205][205],int at[205][205])
{
	queue<int> q;
	q.push(a);
	q.push(b);
	vis[a][b] = 1;
	/*if(ar[a][b] == '#') {
		cost[a][b] = at[a][b];
		p[a][b] = at[a][b];
	}*/
	while(!q.empty()) {
		int u = q.front();q.pop();
		int v = q.front();q.pop();

		//cout << "popped value are " << u << " and " << v << endl;
		if(check(u-1,v,n,m)) {
			if(vis[u-1][v] == 0 || p[u][v] + 1 < cost[u-1][v]) {
				if(ar[u-1][v] == '.') {
					p[u-1][v] = p[u][v] + 1;
					cost[u-1][v] = p[u][v] + 1;
				}else if(ar[u-1][v] == '#'){
					if(p[u][v] + 1 >= at[u-1][v]) {
						cost[u-1][v] = p[u][v] + 1;
						p[u-1][v] = p[u][v] + 1;
					}else {
						cost[u-1][v] = at[u-1][v];
						p[u-1][v] = at[u-1][v];
					}
				}
				q.push(u-1);
				q.push(v);
				//cout << "pushed value are " << u-1 << " and " << v << endl;
				//cout << "cost is " << cost[u-1][v] << endl;
				vis[u-1][v] = 1;
			}
		}
		if(check(u+1,v,n,m)) {
			if(vis[u+1][v] == 0 || p[u][v] + 1 < cost[u+1][v]) {
				if(ar[u+1][v] == '.') {
					p[u+1][v] = p[u][v] + 1;
					cost[u+1][v] = p[u][v] + 1;
				}else if(ar[u+1][v] == '#') {
					if(p[u][v] + 1 >= at[u+1][v]) {
						cost[u+1][v] = p[u][v] + 1;
						p[u+1][v] = p[u][v] + 1;
					}else {
						cost[u+1][v] = at[u+1][v];
						p[u+1][v] = at[u+1][v];
					}
				}
				q.push(u+1);
				q.push(v);
				//cout << "pushed value are " << u+1 << " and " << v << endl;
				//cout << "cost is " << cost[u+1][v] << endl;
				vis[u+1][v] = 1;
			}
		}
		if(check(u,v-1,n,m)) {
			if(vis[u][v-1] == 0 || p[u][v] + 1 < cost[u][v-1]) {
				if(ar[u][v-1] == '.') {
					p[u][v-1] = p[u][v] + 1;
					cost[u][v-1] = p[u][v] + 1;
				}else if(ar[u][v-1] == '#'){
					if(p[u][v] + 1 >= at[u][v-1]) {
						cost[u][v-1] = p[u][v] + 1;
						p[u][v-1] = p[u][v] + 1;
					}else {
						cost[u][v-1] = at[u][v-1];
						p[u][v-1] = at[u][v-1];
					}
				}
				q.push(u);
				q.push(v-1);
				//cout << "pushed value are " << u << " and " << v-1 << endl;
				//cout << "cost is " << cost[u][v-1] << endl;
				vis[u][v-1] = 1;
			}
		}
		if(check(u,v+1,n,m)) {
			if(vis[u][v+1] == 0 || p[u][v] + 1 < cost[u][v+1]) {
				if(ar[u][v+1] == '.') {
					p[u][v+1] = p[u][v] + 1;
					cost[u][v+1] = p[u][v] + 1;
				}else if(ar[u][v+1] == '#'){
					if(p[u][v] + 1 >= at[u][v+1]) {
						cost[u][v+1] = p[u][v] + 1;
						p[u][v+1] = p[u][v] + 1;
					}else {
						cost[u][v+1] = at[u][v+1];
						p[u][v+1] = at[u][v+1];
					}
				}
				q.push(u);
				q.push(v+1);
				//cout << "pushed value are " << u << " and " << v+1 << endl;
				//cout << "cost is " << cost[u][v+1] << endl;
				vis[u][v+1] = 1;
			}
		}
	}
	cout << cost[c][d] << endl;
}
int main()
{
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		/*fill(&vis[0][0],&vis[0][0]+(e*e),0);
		fill(&cost[0][0],&cost[0][0]+(e*e),0);
		fill(&p[0][0],&p[0][0]+(e*e),0);*/
		for(int i = 0;i < 205;i++) {
			for(int j = 0;j < 205;j++) {
				vis[i][j] = 0;cost[i][j] = 0;p[i][j] = 0;
			}
		}
		
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				cin >> ar[i][j];
			}
		}
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				cin >> at[i][j];
			}
		}
		cin >> a >> b >> c >> d;
		match(ar,at);
	}
	return 0;
}


