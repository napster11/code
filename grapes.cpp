#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int k = 1;k <= t;k++) {
        int n,s;
        cin >> n >> s;
        int vis[100005] = {0};
        multiset<int> v[100005];
        multiset<int>::iterator it;
        vector<int> ans;
        for(int i = 0;i < n;i++) {
            int a,b,c;
            cin >> a;
            b = a/s;
            c = a%s;
            v[b].insert(c);
            if(vis[b] == 0) {
                ans.push_back(b);
                vis[b] = 1;
            }
        }
        sort(ans.begin(),ans.end());
        cout << "Scenario #" << k << ":\n\n";
        for(int i = 0;i < ans.size();i++) {
            int q = ans[i];
            int j = 0;
            cout << q << " | ";
            for(it = v[q].begin();it != v[q].end();it++) {
                   // if(it != v[q].end()-1) {
                       // cout << (*it) << " ";
                   // }else {
                        cout << (*it) << " ";
                   // }
            }
	    cout << endl;
        }
        cout << endl;
    }
	return 0;
}
