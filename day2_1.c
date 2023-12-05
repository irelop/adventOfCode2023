#include <stdio.h>
#include<string.h>

const int RED_MAX = 12;
const int BLUE_MAX = 14;
const int GREEN_MAX = 13;

int main(){

    char input[200];
    int sum = 0;

    while(fgets(input, 200, stdin) != NULL){
        int gameNum, cubesNum;
        char color[10];
        short possible = 1;

        sscanf(input, "Game %d:", &gameNum);
        char *token = strstr(input, ":");
        token = token + 1;
        while(sscanf(token, "%d %9[^,;]", &cubesNum, color)==2 && possible){

            if((strcmp("red", color)==0 && cubesNum > RED_MAX)
                || (strcmp("blue", color) == 0 && cubesNum > BLUE_MAX)
                || (strcmp("green", color) == 0 && cubesNum > GREEN_MAX))
                possible = 0;

            token = strpbrk(token, ",;");
            if(token == NULL)
                break;
            token = token + 1;
        }

        if(possible)
            sum = sum + gameNum;

    }
    printf("sum: %d\n", sum);
    return 0;
}