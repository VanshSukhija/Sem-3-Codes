#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int min(int a, int b){return (a<b)?a:b;}

// int MCM(int arr[][2], int n){
//     int dp[n][n];
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(i==j)
//                 dp[i][j] = 0;
//             else
//                 dp[i][j] = 100000000;
//         }
//     }

//     for(int i=1; i<n; i++){
//         for(int j=0; j<n-i; j++){
//             int mini = arr[j][0];
//             for(int k=j; k<=i+j; k++)
//                 mini *= arr[k][1];
                
//             for(int k=j; i>1 && k<i+j; k++){
//                 if(dp[j][k] + dp[k+1][i+j] + arr[j][0]*arr[k][1]*arr[i+j][1] < mini)
//                     mini = dp[j][k] + dp[k+1][i+j] + arr[j][0]*arr[k][1]*arr[i+j][1];
//             }
//             if(mini < dp[j][i+j])
//                 dp[j][i+j] = mini;
//         }
//     }
    
//     printf("\n");
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++)
//             printf("%d ", dp[i][j]);
//         printf("\n");
//     }
//     return dp[0][n-1];
// }

int matrixMultiplication(int arr[], int n){ // nhi chl rha
    long long dp[n][n];
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(i==j)
                dp[i][j] = 0;
            else
                dp[i][j] = 1e9;
        }
    }
    // j = starting point... i = number of matrices apart from jth matrix ... i+j = ending point
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-i; j++){
            long long mini = 1e9;
            for(int k=j; k<i+j; k++)
                mini = min(mini, dp[j][k] + dp[k+1][i+j] + arr[j-1]*arr[k]*arr[i+j]);
            if(mini < dp[j][i+j])
                dp[j][i+j] = mini;
        }
    }
    return dp[1][n-1];
}

int MCMrec(int arr[], int start, int end){
    if(start==end)
        return 0;
    int minn = 100000000, count;
    for(int k=start; k<end; k++){
        int a = MCMrec(arr, start, k);
        int b = MCMrec(arr, k+1, end);
        int count = a + b + arr[start-1]*arr[k]*arr[end];
        if(count < minn)
            minn = count;
    }
    return minn;
}
int dp[100][100];
int MCMmemo(int arr[], int start, int end){
    if(start==end)
        return dp[start][end] = 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    int minn = 100000000, count;
    for(int k=start; k<end; k++){
        int a = MCMrec(arr, start, k);
        int b = MCMrec(arr, k+1, end);
        int count = a + b + arr[start-1]*arr[k]*arr[end];
        if(count < minn)
            minn = count;
    }
    return dp[start][end] = minn;
}

int MCMtab(int arr[], int size){ // nhi chl rha
    int dp[size+1][size+1];
    for(int i=0; i<=size; i++)
        dp[i][i] = 0;
    for(int start=1; start<size; start++){
        for(int end=1; end<=size; end++){
            int minn = 100000000, count;
            for(int k=start; k<end; k++){
                int a = dp[start][k];
                int b = dp[k+1][end];
                int count = a + b + arr[start-1]*arr[k]*arr[end];
                if(count < minn)
                    minn = count;
            }
            dp[start][end] = minn;
        }
    }
    // for(int i=0; i<=size; i++){
    //     for(int j=0; j<=size; j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[1][size];
}

void main(){
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    printf("Enter the number of rows and columns of matrices:\n");
    int arr[n+1];
    for(int i=0; i<=n; i++)
        scanf("%d", &arr[i]);
    printf("Minimum multiplications: %d\n", MCMrec(arr, 1, n));
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(i==j)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    printf("Minimum multiplications: %d\n", MCMmemo(arr, 1, n));
    printf("Minimum multiplications: %d\n", matrixMultiplication(arr, n)); // nhi chl rha
}

/* 
5
1 2 3 4 5 6
*/

/* 
3
10 5 100 50
*/