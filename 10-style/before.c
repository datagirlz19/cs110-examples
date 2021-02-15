#include <stdio.h>
int main(){
  int n;
    printf("Enter shape size: ");
    scanf("%u",&n);
    for(int r=0;r<n;r++){
     for(int c=0;c<n;c++){
        if (r%2==0){
          printf("<");
        }
        else{ printf(">");}
    }
printf("\n");
}
return 0;
}
