#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
    int main(){
        int n;
        scanf("%d", &n);
        int arr[n],res[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
            res[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(arr[i]<arr[(i+j)%n]){
                    res[i]=arr[(i+j)%n];
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
        printf("%d ",res[i]);
            }
    return 0;
    }
