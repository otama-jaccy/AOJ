#include <iostream>
#include <cstdio>

using namespace std;

int solve0(int money, int year){
    int fee;
    double rate;
    cin >> rate >> fee;
    int savings = 0;

    while(year--){
        savings += int(rate*money);
        money -= fee;
    }
    return money+savings;
}

int solve1(int money, int year){
    int fee;
    double rate;
    cin >> rate >> fee;

    while(year--){
        money += money*rate;
        money -= fee;
    }
    return money;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int money,year,n;
        cin >> money >> year >> n;
        int ans = 0;
        while(n--){
            int type;
            cin >> type;
            if(type==0){
                ans = max(solve0(money, year), ans);
            }else if(type==1){
                ans = max(solve1(money, year), ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
