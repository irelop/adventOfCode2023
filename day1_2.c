#include <stdio.h>
#include <string.h>

const char ONE[4] = "one";
const char TWO[4] = "two";
const char THREE[6] = "three";
const char FOUR[5] = "four";
const char FIVE[5] = "five";
const char SIX[4] = "six";
const char SEVEN[6] = "seven";
const char EIGHT[6] = "eight";
const char NINE[5] = "nine";

int findFirstNum(char input[], int i){
    int k;

    switch(input[i]){
        case 'o':
            for(int j=1; j<3; j++){
                if(i+j>=strlen(input) || input[i+j] != ONE[j])
                    return 0;
            }
            return 1;
        case 't':
            for(k=1; k<3; k++){
                if(i+k>=strlen(input))
                    return 0;
                else if(input[i+k] != TWO[k])
                    break;
            }
            if(k<3 && i+k<strlen(input)){
                for(int j=1; j<5; j++){
                    if(i+j>=strlen(input) || input[i+j] != THREE[j])
                        return 0;
                }
                return 3;
            }
            else return 2;
        case 'f':
            for(k=1; k<4; k++){
                if(i+k>=strlen(input))
                    return 0;
                else if(input[i+k] != FOUR[k])
                    break;
            }
            if(k<4){
                for(int j=1; j<4; j++){
                    if(i+j>=strlen(input) || input[i+j] != FIVE[j])
                        return 0;
                }
                return 5;
            }
            else return 4;
        case 's':
            for(k=1; k<3; k++){
                if(k+i>=strlen(input))
                    return 0;
                else if(input[i+k] != SIX[k])
                    break;
            }
            if(k<3){
                for(int j=1; j<5; j++){
                    if(j+i>=strlen(input) || input[i+j] != SEVEN[j])
                        return 0;
                }
                return 7;
            }
            else return 6;
        case 'e':
            for(int j=1; j<5; j++){
                if(j+i>=strlen(input) || input[i+j] != EIGHT[j])
                    return 0;
            }
            return 8;
        case 'n':
            for(int j=1; j<4; j++){
                if(i+j>=strlen(input) || input[i+j] != NINE[j])
                    return 0;
            }
            return 9;

        default: return 0;
    }
}

int findLastNum(char input[], int i){
    int j, k, l;

    switch(input[i]){
        case 'e':
            for(j=1; j<3; j++){
                if(i<j)
                    return 0;
                else if(input[i-j] != ONE[2-j])
                    break;
            }
            if(j<3){
                for(k=1; k<5; k++){
                    if(i<k || input[i-k] != THREE[4-k])
                        break;
                }
                if(k<5){
                    for(l=1; l<4; l++){
                        if(i<l)
                            return 0;
                        else if(input[i-l] != FIVE[3-l])
                            break;
                    }
                    if(l<4){
                        for(int m=0; m<4; m++){
                            if(i<m || input[i-m] != NINE[3-m])
                                return 0;
                        }
                        return 9;
                    }
                    else return 5;
                }
                else return 3;
            }
            else return 1;
        case 'o':
            for(j=1; j<3; j++){
                if(i<j || input[i-j] != TWO[2-j])
                    return 0;
            }
            return 2;
        case 'r':
            for(j=1; j<4; j++){
                if(i<j || input[i-j] != FOUR[3-j])
                    return 0;
            }
            return 4;
        case 'x':
            for(j=1; j<3; j++){
                if(i<j || input[i-j] != SIX[2-j])
                    return 0;
            }
            return 6;
        case 'n':
            for(j=1; j<5; j++){
                if(i<j || input[i-j] != SEVEN[4-j])
                    return 0;
            }
            return 7;
        case 't':
            for(j=1; j<5; j++){
                if(i<j || input[i-j] != EIGHT[4-j])
                    return 0;
            }
            return 8;
        default: return 0;
    }
}

int main() {
    char input[100];
    int sum = 0;

    while(fgets(input, 100, stdin) != NULL){
        int firstDigit = 0, lastDigit = 0;
        for(int i=0; i<strlen(input); i++){
            if(input[i]>=48 && input[i]<=57){ //input[i] is a number
                firstDigit = input[i] - 48;
                break;
            }
            else {
                firstDigit = findFirstNum(input, i);
                if(firstDigit != 0)
                    break;
            }
        }
        for(int i=strlen(input)-1; i>=0; i--){
            if(input[i]>=48 && input[i]<=57){
                lastDigit = input[i] - 48;
                break;
            }
            else{
                lastDigit = findLastNum(input, i);
                if(lastDigit != 0)
                    break;
            }
        }
        sum = sum + firstDigit * 10 + lastDigit;
    }

    printf("sum: %d\n", sum);

    return 0;
}


