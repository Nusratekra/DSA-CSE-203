#include<stdio.h>
int main(){
 int n,i;
 scanf("%d",&n);
 int a[n];
 for(i = 0;i<n;i++){
    scanf("%d",&a[i]);
 } printf("After Traverse: \n");
 for(i = 0;i<n;i++){
    printf("%d\t",a[i]);
 }
}
