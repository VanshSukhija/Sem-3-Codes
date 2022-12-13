#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int max(int a, int b){return (a>b)?a:b;}

int LCSrec(char str1[], char str2[], int len1, int len2){
    if(len1>0 && len2>0){
        if(str1[len1-1]==str2[len2-1])
            return 1 + LCSrec(str1, str2, len1-1, len2-1);
        else{
            int i = LCSrec(str1, str2, len1-1, len2);
            int j = LCSrec(str1, str2, len1, len2-1);
            if(i>=j)
                return i;
            else
                return j;
        }
    }
    else
        return 0;
}
int dp[100][100];
int LCSmemo(char str1[], char str2[], int len1, int len2){
    if(len1>0 && len2>0){
        if(dp[len1][len2] != -1)
            return dp[len1][len2];
        if(str1[len1-1]==str2[len2-1])
            return dp[len1][len2] = 1 + LCSmemo(str1, str2, len1-1, len2-1);
        else{
            int i = LCSmemo(str1, str2, len1-1, len2);
            int j = LCSmemo(str1, str2, len1, len2-1);
            if(i>=j)
                return dp[len1][len2] = i;
            else
                return dp[len1][len2] = j;
        }
    }
    else
        return 0;
}

int LCS(char str1[], char str2[], int len1, int len2){
    int dp[len1+1][len2+1];
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    // for(int i=0; i<=len1; i++){
    //     for(int j=0; j<=len2; j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }
    return dp[len1][len2];
}

void printLCS(char str1[], char str2[], char str3[], int len1, int len2, int len3){
    int i=len1, j=len2, k=-1;
    while(i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1]){
            str3[++k] = str1[i-1];
            i--, j--;
        }
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
    }
    str3[++k] = 0;
    
    puts(strrev(str3));
}

void main(){
    char str1[100], str2[100];
    printf("Enter the strings:\n");
    scanf("%s%s", str1, str2);
    printf("Length of Longest Common Subsequence: %d\n", LCSrec(str1, str2, strlen(str1), strlen(str2)));
    for(int i=0; i<=strlen(str1); i++){
        for(int j=0; j<=strlen(str2); j++){
            dp[i][j] = -1;
            dp[0][j] = 0;
            dp[j][0] = 0;
        }
    }
    printf("Length of Longest Common Subsequence: %d\n", LCSmemo(str1, str2, strlen(str1), strlen(str2)));
    int len3 = LCS(str1, str2, strlen(str1), strlen(str2));

    // printf("\n");
    // for(int i=0; i<=strlen(str1); i++){
    //     for(int j=0; j<=strlen(str2); j++){
    //         printf("%d\t", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    printf("Length of Longest Common Subsequence: %d\n", len3);
    char str3[len3];
    printLCS(str1, str2, str3, strlen(str1), strlen(str2), len3);
}

/* 
AEDFHR
ABCDGH
*/

/* 
GGXTXAYB
AGGTAB
*/

/* 
abcde
bdgek
*/