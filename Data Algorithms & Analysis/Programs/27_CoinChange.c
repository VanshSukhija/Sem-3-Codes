#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dp[1000][1000];

int CoinChange(int money[], int index, int target){
    if(index==0){
        if(target%money[index]==0)
            return 1;
        else 
            return 0;
    }
    int nontake = CoinChange(money, index-1, target);
    int take = 0;
    if(target >= money[index])
        take = CoinChange(money, index, target-money[index]);
    return take+nontake;
}

int CoinChangeMemo(int money[], int index, int target){
    if(index==0){
        if(target%money[index]==0)
            return dp[index][target] = 1;
        else 
            return dp[index][target] = 0;
    }
    if(dp[index][target]!=-1)
        return dp[index][target];
    int nontake = CoinChangeMemo(money, index-1, target);
    int take = 0;
    if(target >= money[index])
        take = CoinChangeMemo(money, index, target-money[index]);
    return dp[index][target] = take+nontake;
}

void main(){
    int n;
    printf("Enter number of denominations: ");
    scanf("%d", &n);
    int money[n];
    printf("Enter denominations: ");
    for(int i=0; i<n; i++)
        scanf("%d", &money[i]);
    int sum;
    printf("Enter target sum: ");
    scanf("%d", &sum);
    printf("Number of ways: %d\n", CoinChange(money, n-1, sum));
    for(int i=0; i<=n; i++)
        for(int j=0; j<=sum; j++)
            dp[i][j] = -1;
    printf("Number of ways: %d\n", CoinChangeMemo(money, n-1, sum));    
}

/* 
3
1 2 3
4
*/

/*
4
2 5 3 6
10
*/