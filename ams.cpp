#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
string cop(char e[])
{
    string s;
	int i = 0;
	while(e[i] != '\0') {
		s[i] = e[i];
		i++;
	}
	return s;
}
int check(int a,int u[10],int n)
{
    vector<int> pt;
    vector<int> :: iterator it;
    while(a >= 10) {
        pt.push_back(a%10);
        a /= 10;
    }
    pt.push_back(a);
    for(it = pt.end()-1;it >= pt.begin();it--) {
        u[n] = (*it);
        n++;
    }
    return n;
}
int main()
{
    while(!cin.eof()) {
        int s,n;
        string r;
        int u[15];
        cin >> s >> r;
        n = check(s,u,0);
        int a[15] = {0};
        char ch[n+1][252];
        int i = 0;
        int temp = r.length();
        int k = 0;
        int flag = 1;
        while(flag) {
                if(k%2 == 0) {
                    for(int p = 0;p < n;p++) {
                        if(p%2 == 0) {
                            for(int y = i;y < i+2;y++) {
                                if(y < temp) {
                                    ch[u[p]][a[u[p]]] = r[y];
                                    a[u[p]]++;
                                }else {
                                    flag = 0;
                                }
                            }
			    i += 2;
                        }else if(p%2 != 0 ){
                            if(i < temp) {
                                ch[u[p]][a[u[p]]] = r[i];
                                i++;
                                a[u[p]]++;
                            }else {
                                flag = 0;
                            }
                        }
                    }
                }else {
                    for(int p = 0;p < n;p++) {
                        if(p%2 == 0 ) {
                            if(i < temp) {
                                ch[u[p]][a[u[p]]] = r[i];
                                i++;
                                a[u[p]]++;
                            }else {
                                flag = 0;
                            }
                        }else if(p%2 != 0){
                            for(int y = i;y < i+2;y++) {
                                if(y < temp) {
                                    ch[u[p]][a[u[p]]] = r[y];
                                    a[u[p]]++;
                                }else {
                                    flag = 0;
                                }
                            }
			    i += 2;
                        }
                    }
                }
                k++;
        }
        for(int j = 1;j <= n;j++) {
                for(int k = 0;k < a[j];k++) {
                        cout << ch[j][k];
                }
        }
        cout << endl;
    }
    return 0;
}


