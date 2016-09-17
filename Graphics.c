#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){

    FILE* input = fopen(argv[2], "rb"); //rb in windows not r
    char *pixBuffer; //char pointing to the buffer

    FILE* output = fopen(argv[3], "wb"); //rw in windows not w

    int format = atoi(argv[1]); //converting to integer

    if(format == 3) //if it's 3
    {
        int ch;
        while((ch = fgetc(input)) != EOF); //while it's not the end
        if(ch ==EOF)
        {
            if(feof(input))
            {
                fprintf(stderr, "Invalid1\n");
            }
            else if(ferror(input)){
                fprintf(stderr, "Error1\n");
        }
            return 1;
        }
    while((ch = fgetc(input)) != EOF && ch !='3' && ch != '6'); //when it's not 3 or 6 we get an error because it should be 3 or 6
    if(ch == EOF)
    {
        if(feof(input)){
                fprintf(stderr, "Invalid2\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error2\n");
        }
        return 1;
    }
    int magicNum = ch;

    while((ch = fgetc(input)) != EOF && isspace(ch)); //if the ch is white space
    if(ch == EOF)
    {
        if(feof(input)){
            fprintf(stderr, "Invalid3\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error3\n");
        }
        return 1;
    }
    int width;
    int status = fscanf(input, "%d", &width);
    if(status == EOF){
        if(feof(input)){
            fprintf(stderr, "Invalid4\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error4\n");
        }
        return 1;

    }
    if(status < 1)
    {
        fprintf(stderr, "Invalid5\n");
    }
    while((ch = fgetc(input)) != EOF && isspace(ch));
    if(ch ==EOF){
        if(feof(input)){
            fprintf(stderr, "Invalid6\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error6\n");
        }
        return 1;
    }
    int height;
    if(status == EOF){ //not correct
        if(feof(input)){
            fprintf(stderr, "Invalid7\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error7\n");
        }
        return 1;

    }
    if(status < 1){ //not correct
        fprintf(stderr, "Error8\n");
    }
    int maxcolor;
    int status2 = fscanf(input, "%d", &maxcolor);
    if(status2 == EOF){
        if(feof(input)){
            fprintf(stderr, "Invalid9\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error9\n");
        }
        return 1;
    }
    if(status2 < 1){
        fprintf(stderr, "Error10\n");
    }
    if(ch == EOF){
        if(feof(input)){
            fprintf(stderr, "Invalid11\n");
        }
        else if(ferror(input)){
            fprintf(stderr, "Error11\n");
        }
        return 1;
    }
    else if(!isspace(ch)){
        fprintf(stderr, "Error12\n");
    }
    int i;
    int j;
    size_t size = width * height * 3;
    pixBuffer = (unsigned char *)malloc(size);
    if(ch == '6'){
        fread(pixBuffer, 1, size, input);
        }
    else if(ch == '3'){
        for(i = 0; i < width; i++){
            for(j = 0; j < height; j++){
                fscanf(input, "%d", &(pixBuffer[(i * width + j)*3]));
                while((ch = fgetc(input)) != EOF && isspace(ch));
                if(ch == EOF){
                    if(feof(input)){
                        fprintf(stderr, "Invalid13\n");
                    }
                    else if(ferror(input)){
                        fprintf(stderr, "Error13\n");
                    }
                    return 1;
                }
                fscanf(input, "%d", &(pixBuffer[(i * width + j)*3 + 1]));
                while((ch = fgetc(input)) != EOF && isspace(ch));
                if(ch == EOF){
                    if(feof(input)){
                        fprintf(stderr, "Invalid14\n");
                    }
                    else if(ferror(input)){
                        fprintf(stderr, "Error14\n");
                    }
                    return 1;
                }
                fscanf(input, "%d", &(pixBuffer[(i * width + j)*3 +2]));
                while((ch = fgetc(input)) != EOF && isspace(ch));
                if(ch == EOF){
                    if(feof(input) && i < (width-1) && j < (height - 1)){
                        fprintf(stderr, "Invalid15\n");
                    }
                    else if(ferror(input)){
                        fprintf(stderr, "Error15\n");
                    }
                    return 1;
                }
            }
        }
    }


    }

}
