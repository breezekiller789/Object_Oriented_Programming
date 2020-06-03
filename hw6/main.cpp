#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    FILE *fp = fopen("sample.in", "r");
    int Num_Students=0, cnt=0;
    int English_Grade[4], History_Grade[3], Math_Grade[8];
    char first_name[10];
    char last_name[10];
    char subject[10];
    char *line = (char *)malloc(sizeof(char) * MaxLine);
    char **words;
    words = (char **)malloc(sizeof(char *) * MaxLine);

    fscanf(fp, "%d", &Num_Students);

    cnt = Parser(words, fp);

    for(int i=0; i<cnt; i++){
        char *ptr = *(words+i);
        printf("%s\n", *(words+i));
        /* while(!isdigit(*ptr) && *ptr && *ptr != ','){ */
        /*     (*first_name)++ = (*ptr)++; */
        /* } */

    }






    /* fscanf(fp, "%d", &Num_Students); */
    /* printf("%d\n", Num_Students); */
    /* for(int i=0; i<Num_Students; i++){ */
    /*     fscanf(fp, "%s %s", first_name, last_name); */
    /*     fscanf(fp, "%s ", subject); */
    /*     if(strcmp(subject, "English") == 0){ */
    /*         fscanf(fp, "%d %d %d %d", &English_Grade[0], &English_Grade[1], */
    /*                 &English_Grade[2], &English_Grade[3]); */
    /*         printf("first name = %s\n", first_name); */
    /*         printf("last name = %s\n", last_name); */
    /*         printf("subject = %s\n", subject); */
    /*         for(int i=0; i<4; i++){ */
    /*             printf("%d ", English_Grade[i]); */
    /*         } */
    /*         printf("\n==========================="); */
    /*         printf("\n"); */
    /*     } */
    /*     else if(strcmp(subject, "History") == 0){ */
    /*         fscanf(fp, "%d %d %d", &History_Grade[0], &History_Grade[1], */
    /*                 &History_Grade[2]); */
    /*         printf("first name = %s\n", first_name); */
    /*         printf("last name = %s\n", last_name); */
    /*         printf("subject = %s\n", subject); */
    /*         for(int i=0; i<3; i++){ */
    /*             printf("%d ", History_Grade[i]); */
    /*         } */
    /*         printf("\n==========================="); */
    /*         printf("\n"); */
    /*     } */
    /*     else if(strcmp(subject, "Math") == 0){ */
    /*         fscanf(fp, "%d %d %d %d %d %d %d %d", &Math_Grade[0], &Math_Grade[1], &Math_Grade[2], */
    /*                 &Math_Grade[3], &Math_Grade[4], &Math_Grade[5], &Math_Grade[6], &Math_Grade[7]); */
    /*         printf("first name = %s\n", first_name); */
    /*         printf("last name = %s\n", last_name); */
    /*         printf("subject = %s\n", subject); */
    /*         for(int i=0; i<8; i++){ */
    /*             printf("%d ", Math_Grade[i]); */
    /*         } */
    /*         printf("\n==========================="); */
    /*         printf("\n"); */
    /*     } */
    /*     else{ */
    /*         printf("Parse Input Error\n"); */
    /*         exit(1); */
    /*     } */
    /* } */
    return 0;
}
