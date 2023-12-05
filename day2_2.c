#include <stdio.h>
#include<string.h>

int main(){

    char input[200];
    int sum = 0;

    while(fgets(input, 200, stdin) != NULL){
        int gameNum, cubesNum, redMax = 0, blueMax = 0, greenMax = 0;
        char color[10];

        sscanf(input, "Game %d:", &gameNum);
        char *token = strstr(input, ":");
        token = token + 1;

        size_t len = strcspn(token, "\n");
        token[len] = '\0';

        while(sscanf(token, "%d %9[^,;]", &cubesNum, color)==2){

            if(strcmp("red", color)==0 && cubesNum > redMax)
                redMax = cubesNum;
            else if(strcmp("blue", color) == 0 && cubesNum > blueMax)
                blueMax = cubesNum;
            else if(strcmp("green", color) == 0 && cubesNum > greenMax)
                greenMax = cubesNum;

            token = strpbrk(token, ",;");
            if(token == NULL)
                break;
            token = token + 1;
        }
        sum = sum + redMax * blueMax * greenMax;

    }
    printf("sum: %d\n", sum);
    return 0;
}