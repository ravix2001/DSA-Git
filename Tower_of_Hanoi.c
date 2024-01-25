#include<stdio.h>
void toh(int n, char source, char destination, char auxiliary){
    if(n==1){
        printf("Move disk %d from %c to %c\n",n,source,destination);
    }
    else{
        toh(n-1,source,auxiliary,destination);
        printf("Move disk %d from %c to %c\n",n,source,destination);
        toh(n-1,auxiliary,destination,source);    
    }
}
int main(){
    int n;
    char source='A', auxiliary='B', destination='C';
    printf("Enter the number of discs : ");
    scanf("%d",&n);
    toh(n,source,destination,auxiliary);
    return 0;
}
