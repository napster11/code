#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int count;
int vis[100005] = {0};
vector<long long int> v[100005];
/*void dfs(int cost[100][100],int s,int v,int vis[100])
{
	stack<int> st;
	st.push(s);
	vis[s] = 1;
	while(!st.empty()) {
		s = st.top();
		//cout << "source is " << s << endl;
		st.pop();
		for(int i = 1;i <= v;i++) {
			if(i != s) {
				if(cost[s][i] == 1 && vis[i] == 0) {
					st.push(i);
					vis[i] = 1;
				}
			}
		}
		cout << s << " " << endl;//"node is " << s << endl;
	}
}*/
void dfs2(int s)
{
	vector<long long int>::iterator it;
	vis[s] = 1;
	count++;
	//cout << "node is " << s << endl;

	for(it = v[s].begin();it != v[s].end();it++) {
		if(vis[*it] == 0) {
			dfs2((*it));
		}
	}
}
int main()
{
	long long int temp,ver,e,s,temp1;
	temp1 = 0;
	//vector<long long int> v[100005];
	vector<long long int> ans;
	vector<long long int >::iterator it;
	//cout << "enter the no. of vertexes and edges\n";
	cin >> ver >> e;

	for(int i = 1;i <= e;i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	/*for(int i = 1;i <= ver;i++) {
		for(it = v[i].begin();it != v[i].end();it++) {
			cout << (*it) < " ";
		}
		cout << endl;
	}*/
	for(int i = 1;i <= ver;i++) {
		if(vis[i] == 0) {
			count  = 0;
			dfs2(i);
			ans.push_back(count);
		}
	}
	temp = (ver*(ver-1))/2;
	for(it = ans.begin();it != ans.end();it++) {
		temp1 += ((*it)*(*it - 1))/2;
	}
	cout << (temp-temp1) << endl;
	//cout << "no. of connected components are " << ans.size() << endl;
	//dfs(cost,s,v,vis);
	return 0;
}


