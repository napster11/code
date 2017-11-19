#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;
int cas;
int main()
{
	int ar[100][10];
	vector<string> v(10);
	vector<string> str;
	string key,data;
	while(cin >> key) {
		memset(ar,0,sizeof(ar));
		cin >> data;
		int i = 0;
		int n = data.size();
		cas = 1;
		int k = 0;
		while(i < n) {
			for(int j = 0; j < key.size(); j++) {
				if(cas == 1) {
					if(j%2 == 0) {
						if(i+1 < n) {
							//printf("%c%c ",data[i],data[i+1]);
							ar[k][key[j]-'0'] = 2;
							v[key[j]-'0'] += data[i++];
							v[key[j]-'0'] += data[i++];

						}
						else{
							ar[k][key[j]-'0'] = 1;
							//printf("%c ",data[i]);
							v[key[j]-'0'] += data[i++];
							break;
						}
					}
					else{
						ar[k][key[j]-'0'] = 1;
						//printf("%c ",data[i]);
						v[key[j]-'0'] += data[i++];
					}
				}
				else{
					if(j%2) {
						if(i+1 < n) {
							ar[k][key[j]-'0'] = 2;
							//printf("%c%c ",data[i],data[i+1]);
							v[key[j]-'0'] += data[i++];
							v[key[j]-'0'] += data[i++];

						}
						else{
							ar[k][key[j]-'0'] = 1;
							//printf("%c ",data[i]);
							v[key[j]-'0'] += data[i++];
							break;
						}
					}
					else{
						ar[k][key[j]-'0'] = 1;
						//printf("%c ",data[i]);
						v[key[j]-'0'] += data[i++];
					}

				}
				if(i >= n) {
					//printf("\n");
					k++;
					break;
				}
			}
			k++;
			//printf("\n");
			if(cas == 1) {
				cas = 2;
			}
			else{
				cas = 1;
			}
		}
		/*for(int i = 0 ; i < k; i++) {
		  for(int j = 1; j <= key.size(); j++) {
		  printf("%d ",ar[i][j]);
		  }
		  printf("\n");
		  }*/
		str.push_back("");
		int x = 0;
		for(int i = 1; i <= key.size(); i++) {
			int xx = i;
			str.push_back("");
			for(int j = 0; j < k; j++) {
				if(ar[j][i] == 2) {
					str[i] += data[x];
					str[i] += data[x+1];
					x++;
					x++;
				}
				else if(ar[j][i]) {
					str[i] += data[x];
					x++;
				}
			}
			//cout<<str[i]<<endl;
		}
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < key.size(); j++) {
				//printf("xz");
				int xx = key[j]-'0';
				if(ar[i][xx] == 2) {
					printf("%c%c",str[xx][0],str[xx][1]);
					//getchar();
					//getchar();
					str[xx].erase(str[xx].begin());
					str[xx].erase(str[xx].begin());
				}
				else if(ar[i][xx]) {
					printf("%c",str[xx][0]);
					//getchar();
					//getchar();
					str[xx].erase(str[xx].begin());
				}
			}
		}
		cout<<endl;
		key.clear();
		data.clear();
		str.clear();
	}
	return 0;
}



