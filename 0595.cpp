//AOJ0595 ACCEPTED
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define reep(i,n,m) for(int i=(n);i<(m);i++)
#define rep(i,n) reep(i,0,n)

#define J 1
#define O 2
#define I 3
#define JO 4
#define JI 5
#define OI 6
#define JOI 7

#define MAX 10007

int dp[8][1005] ={0};

int main(void){
	int n;
	cin >> n;
	string sc;
	cin >> sc;

	dp[J][0] = 1;
	reep(i,1,n+1){
		if(sc[i-1]=='J'){
			dp[J][i] 	+= (dp[J][i-1] + dp[JO][i-1] + dp[JI][i-1] + dp[JOI][i-1])%MAX;
			dp[JO][i] 	+= (dp[J][i-1] + dp[JO][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[O][i-1] + dp[OI][i-1])%MAX;
			dp[JI][i] 	+= (dp[J][i-1] + dp[JO][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[I][i-1] + dp[OI][i-1])%MAX;
			dp[JOI][i] 	+= (dp[J][i-1] + dp[JO][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[I][i-1] + dp[O][i-1] + dp[OI][i-1])%MAX;
		}else if(sc[i-1]=='O'){
			dp[O][i] 	+= (dp[O][i-1] + dp[OI][i-1] + dp[JO][i-1] + dp[JOI][i-1])%MAX;
			dp[OI][i]	+= (dp[O][i-1] + dp[OI][i-1] + dp[JO][i-1] + dp[JOI][i-1] + dp[I][i-1] + dp[JI][i-1])%MAX;
			dp[JO][i]	+= (dp[O][i-1] + dp[OI][i-1] + dp[JO][i-1] + dp[JOI][i-1] + dp[J][i-1] + dp[JI][i-1])%MAX;
			dp[JOI][i]	+= (dp[O][i-1] + dp[OI][i-1] + dp[JO][i-1] + dp[JOI][i-1] + dp[J][i-1] + dp[I][i-1] + dp[JI][i-1])%MAX;
		}else{
			dp[I][i]	+= (dp[I][i-1] + dp[OI][i-1] + dp[JI][i-1] + dp[JOI][i-1])%MAX;
			dp[OI][i]	+= (dp[I][i-1] + dp[OI][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[O][i-1] + dp[JO][i-1])%MAX;
			dp[JI][i]	+= (dp[I][i-1] + dp[OI][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[J][i-1] + dp[JO][i-1])%MAX;
			dp[JOI][i]	+= (dp[I][i-1] + dp[OI][i-1] + dp[JI][i-1] + dp[JOI][i-1] + dp[J][i-1] + dp[O][i-1] + dp[JO][i-1])%MAX;
		}
	}

	int ans = 0;
	reep(i,1,1<<3){
		ans += dp[i][n];
		ans %= MAX;
	}

	cout << ans << endl;

    /*printf("JOI->%d\n",dp[JOI][1]);
	reep(i,1,1<<3){
        printf("--%d\n",dp[i][2]);
	}*/
}
