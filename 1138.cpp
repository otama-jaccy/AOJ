#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <map>

#define reep(i,n,m) for(int i=(n);i<(m);i++)
#define rep(i,n) reep(i,0,n)

using namespace std;

typedef pair<int, double> pii;

class Inf{
public:
    int position;
    int used;
    double cost;

    bool operator<(const Inf &a) const{
        return a.cost<cost;
    }

    Inf(int p, double c, int u){
        position = p;
        cost = c;
        used = u;
    }
};

int main(void){
    int n,m,p,a,b;
    while(cin>>n>>m>>p>>a>>b,n|m|p|a|b){
        int ticket[8];
        rep(i,n){
            cin >> ticket[i];
        }
        vector<vector<pii>> road(31);

        rep(i,p){
            int x,y,z;
            cin >> x >> y >> z;
            road[x].push_back(pii(y,z));
            road[y].push_back(pii(x,z));
        }
        priority_queue<Inf> Q;
        Q.push(Inf(a, 0, 0));
        bool flg[31][1<<8+1] = {0};
        double ans = -1;
        while(!Q.empty()){
            Inf q = Q.top();
            int position = q.position;
            Q.pop();
            if(flg[position][q.used]){
                continue;
            }
            flg[position][q.used] = true;
            if(position==b){
                ans = q.cost;
                break;
            }

            rep(i, road[position].size()){
                pii r = road[position][i];
                rep(k,n){
                    if(q.used&(1<<k)){
                        continue;
                    }
                    int p = r.first;
                    double c = r.second/ticket[k]+q.cost;
                    int u = q.used+(1<<k);
                    Q.push(Inf(p,c,u));
                }
            }
        }
        if(ans<0){
            cout << "Impossible" << endl;
        }else{
            cout << ans << endl;
        }
    }
}
