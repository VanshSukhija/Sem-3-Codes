#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int dp[100][100];

int max(int a, int b){return (a>b)?a:b;}

int RodCut(int price[], int ind, int totLen){
    if(ind==0)
        return totLen*price[0];

    int take = -1;
    int nontake = RodCut(price, ind-1, totLen);
    if(ind+1 <= totLen)
        take = price[ind] + RodCut(price, ind, totLen-ind-1);
    return (take > nontake) ? take : nontake;
}

int RodCutMemo(int price[], int ind, int totLen){
    if(ind==0)
        return dp[ind][totLen] = totLen*price[0];
    if(dp[ind][totLen] != -1)
        return dp[ind][totLen];

    int take = -1;
    int nontake = RodCutMemo(price, ind-1, totLen);
    if(ind+1 <= totLen)
        take = price[ind] + RodCutMemo(price, ind, totLen-ind-1);
    return dp[ind][totLen] = (take > nontake) ? take : nontake;
}

void main(){
    int n;
    printf("Enter length of rod: ");
    scanf("%d", &n);
    int price[n];
    printf("Enter prices:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &price[i]);
    printf("Maximum Cost obtained: %d\n", RodCut(price, n-1, n));
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    printf("Maximum Cost obtained: %d\n", RodCutMemo(price, n-1, n));
}

/*
8
3 5 8 9 10 17 17 20
*/