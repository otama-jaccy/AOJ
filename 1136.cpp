#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define reep(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) reep(i,0,n)

#define ft first
#define sd second

using namespace std;

typedef pair<int, int> pii;

class Line{
public:
    int m;
    vector<pii> p;
    void normalize(){
        int dx = p[0].first, dy = p[0].second;
        rep(i,m){
            p[i].ft -= dx;
            p[i].sd -= dy;
        }

        if(p[1].ft==0){
            if(p[1].sd>0){
                reep(i,1,m){
                    p[i] = pii(p[i].sd, -p[i].ft);
                }
            }else{
                reep(i,1,m){
                    p[i] = pii(-p[i].sd, p[i].ft);
                }
            }
        }else if(p[1].ft<0){
            reep(i,1,m){
                p[i] = pii(-p[i].ft, -p[i].sd);
            }
        }
    }
};


int main(){
    int n;
    while(cin>>n,n){
        vector<Line> line(n+1);
        rep(i,n+1){
            int m;
            cin >> m;
            line[i].m = m;
            while(m--){
                int x,y;
                cin >> x >> y;
                line[i].p.push_back(pii(x,y));
            }
            line[i].normalize();

            if(i>0){
                Line rline = line[i];
                reverse(rline.p.begin(), rline.p.end());
                rline.normalize();
                if(line[0].p==rline.p || line[0].p==line[i].p){
                    cout << i << endl;
                }
            }
        }
        cout << "+++++" << endl;
    }
}
