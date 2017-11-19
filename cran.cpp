#include<iostream>
#include<queue>
using namespace std;
void move(int a[505][505],int vis[505][505],int x,int y)
{
	queue<int> q;
	vis[x-1][y-1] = 1;

	q.push(x-1);
	q.push(y-1);

	while(!q.empty()) {
		int u = q.top();
		q.pop();
		int v = q.top();
		q.pop();

		if(check(u-1,v)) {
			if(vis[u-1][v] == 0) {
				a[u-1][v] = a[u][v] +1;
			}
		}
		if(check(u+1,v)) {


int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n,m,x,y;
		cin >> n >> m;
		int a[505][505] = {0};
		cin >> x >> y;
		int vis[505][505] = {0};
		move(a,vis,x,y);
	}
	return 0;
}
