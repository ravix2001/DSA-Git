#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int p, int r){
    int x, i, j;
    x = arr[r];
    i = p-1;
    for(j=p; j<=r-1; j++){
        if(arr[j] <= x){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[r]);
    return i+1;
}
void Quick_sort(int arr[], int p, int r){
    int q;
    if(p<r){
        q = partition(arr, p, r);
        Quick_sort(arr, p, q-1);
        Quick_sort(arr, q+1, r);
    }
}
int main(){
    int arr[]={10,1,9,5,3,4,6,44},i,p,r;
    p = 0;
    r = (sizeof(arr)-1)/sizeof(int);
    Quick_sort(arr,p,r);
    for(i=0; i<=r; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n%d",sizeof(arr));
    printf("\n%d",sizeof(int));
    return 0;
}
