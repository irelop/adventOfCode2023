#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//48-57
int main() {
    char input[60];
    int sum = 0;

    while(fgets(input, 60, stdin) != NULL){
        int firstDigit = 0, lastDigit = 0;
        for(int i=0; i<strlen(input); i++){
            if(input[i]>=48 && input[i]<=57){ //input[i] is a number
                firstDigit = input[i] - 48;
                break;
            }
        }
        for(int i=strlen(input)-1; i>=0; i--){
            if(input[i]>=48 && input[i]<=57){
                lastDigit = input[i] - 48;
                break;
            }
        }
        sum = sum + firstDigit * 10 + lastDigit;
    }

    printf("%d\n", sum);

    return 0;
}
