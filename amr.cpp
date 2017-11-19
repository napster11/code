#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int sum = 0;
		char c;
		int n,m,k;
		int on = 0;
		cin >> n >> m >> k;
		priority_queue<int> q;
		for(int i = 0;i < n;i++) {
			int off = 0;
			for(int j = 0;j < m;j++) {
				cin >> c;
				if(c == '.') {
					off++;
				}else {
					on++;
				}
			}
			q.push(off);
		}
		for(int p = 0;p < k;p++) {
			int temp;
			on += q.top();
			temp = m-q.top();
			on -= temp;
			q.pop();
			q.push(temp);
		}
		cout << on << endl;
		//q.clear();
	}
	return 0;
}


