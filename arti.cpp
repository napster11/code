#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int count;
int vis[100005];
int dis[100005];
int pr[100005];
int low[100005];
int ap[100005];
void dfs2(vector<long long int > v[100005],int s)
{
	vector<long long int>::iterator it;
	int child = 0;
	vis[s] = 1;
	count++;
	dis[s] = count;
	low[s] = count;
	cout << "node is " << s << " and parent is " << pr[s] << " and low value is " << low[s] << endl;

	for(it = v[s].begin();it != v[s].end();it++) {
		if(vis[*it] == 0) {
			cout << "child of " << s << " is " << (*it) << endl;
			child++;
			pr[(*it)] = s;
			dfs2(v,(*it));
			low[s] = min(low[s],low[*it]);
			if(pr[s] == 0 && child > 1) {
				ap[s] = 1;
				cout << "arti point is " << s << endl;
			}
			if(pr[s] != 0 && low[*it] >= dis[s]) {
				ap[s] = 1;
				cout << "arti point is " << s << endl;
			}
		}
		else if((*it) != pr[s]) {
			low[s] = min(low[s],dis[(*it)]);
			cout << "updates value of low-> " << s << " by " << (*it) << " is " << low[s] << endl;
		}
	}
}
int main()
{

	int ver,e;
	while(1) {
		cin >> ver >> e;
		vector<long long int> v[100005];
		if(ver == 0 && e == 0) {
			break;
		}else {
			for(int i = 0;i <= ver;i++) {
				dis[i] = 0;
				vis[i] = 0;
				pr[i] = 0;
				low[i] = 0;
				ap[i] = 0;
			}
			long long int temp,s,temp1;
			temp1 = 0;
			//vector<long long int> v[100005];
			vector<long long int> ans;
			vector<long long int >::iterator it;
			//cout << "enter the no. of vertexes and edges\n";
		
			for(int i = 1;i <= e;i++) {
				int a,b;
				cin >> a >> b;
				v[a].push_back(b);
				v[b].push_back(a);
			}	
			count  = 0;
			for(int i = 1;i <= ver;i++) {
				if(vis[i] == 0) {
					//count  = 0;
					dfs2(v,i);
					//ans.push_back(count);
				}
			}
			int arti = 0;
			for(int i = 1;i <= ver;i++) {
				if(ap[i] == 1) {
					//cout << "arti point is " << i << endl;
					arti++;
				}
			}
			cout << arti << endl;
		}
	}
	return 0;
}


