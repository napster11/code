#include <iostream>
#include <cstring>
#include <queue>
#define pp pair<int,int>

using namespace std;

int max(int r, int t)
{
    return r > t ? r : t;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)  {
                int n,m;
                cin >> n >> m;
                
                char s[n][m];
                int b[n][m];
                int p[n][m];
                int x1,y1;
                int x2,y2;
                
                for(int i = 0; i < n; i++)  {
                        cin >> s[i];
                }
                
                for(int i = 0; i < n; i++)  {
                        for(int j = 0; j < m; j++)  {
                                cin >> b[i][j];
                        }
                }
                
                cin >> x1 >> y1 >> x2 >> y2;
                
                //memset(p,10000,sizeof(p));
                
                for(int i = 0; i < n; i++)  {
                        for(int j = 0; j < m; j++)  {
                                p[i][j] = 99999;
                        }
                }
                
                p[x1][y1] = 0;
                
                queue<pp> q;
                
                q.push(pp(x1,y1));
                
                pp num;
                int x,y;
                
                while(!q.empty())  {
                                  num = q.front();
                                  q.pop();
                                  x = num.first;
                                  y = num.second;
                                  
                                  if(x > 0 && max(p[x][y]+1,b[x-1][y])<p[x-1][y])  {
                                       p[x-1][y] = max(p[x][y]+1,b[x-1][y]);
                                       q.push(pp(x-1,y));
				       cout << "pushed value are " << x-1 << " and " << y << endl;
				       cout << "cost is " << p[x-1][y] << endl;
                                  }
                                  if(x < (n-1) && max(p[x][y]+1,b[x+1][y])<p[x+1][y])  {
                                       p[x+1][y] = max(p[x][y]+1,b[x+1][y]);
                                       q.push(pp(x+1,y));
				        cout << "pushed value are " << x+1 << " and " << y << endl;
                                        cout << "cost is " << p[x+1][y] << endl;
                                  }
                                  if(y > 0 && max(p[x][y]+1,b[x][y-1])<p[x][y-1])  {
                                       p[x][y-1] = max(p[x][y]+1,b[x][y-1]);
                                       q.push(pp(x,y-1));
				        cout << "pushed value are " << x << " and " << y-1 << endl;
                                        cout << "cost is " << p[x][y-1] << endl;

                                  }
                                  if(y < (m-1) && max(p[x][y]+1,b[x][y+1])<p[x][y+1])  {
                                       p[x][y+1] = max(p[x][y]+1,b[x][y+1]);
                                       q.push(pp(x,y+1));
				        cout << "pushed value are " << x << " and " << y+1 << endl;
                                        cout << "cost is " << p[x][y+1] << endl;

                                  }
                }
                
                /*cout << "\n\n";
                for(int i = 0; i < n; i++)  {
                        for(int j = 0; j < m; j++)  {
                                cout << b[i][j] << "   ";
                        }
                        cout << endl;
                }
                
                cout << "\n\n";
                
                cout << "\n\n";
                for(int i = 0; i < n; i++)  {
                        for(int j = 0; j < m; j++)  {
                                cout << p[i][j] << "   ";
                        }
                        cout << endl;
                }
                
                cout << "\n\n";*/
                
                cout << p[x2][y2] << endl;
    }
    
    return 0;
}

