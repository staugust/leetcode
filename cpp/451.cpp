#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char findMost(int * arr){
    char c = 0;
    int ct = 0;
    char res = 0;
    while(c != '{'){
        if(arr[c] > ct){
            ct = arr[c];
            res = c;
        }
        c++;
    }
    return res;
}

char* frequencySort(char* s) {
    printf("%s\n",s);
    int arr[256] = {0};
    char * h = s;
    char * head = s;
    char ch = 0;
    int loop = 0;
    int count = 0;
    for(count = 0; count != 256; ++count){
        arr[count] = 0;
    }
    while(*h != '\0'){
        printf("%c --> %d\n", *h, arr[*h]);
        arr[*h++] +=1;
    }
    while(loop < 64){
        ch = findMost(arr);
        printf("%c  %d\n",ch, arr[ch]);
        if(arr[ch] > 0){
            for(count = 0; count < arr[ch]; count++){
                *head++=ch;
            }
            loop++;
            arr[ch] = 0;
        }
        else{
            break;
        }
    }
    return s;
}


//int main(void){
//    char * s = (char *)calloc(sizeof(char), 100);
//    memcpy(s,"2a554442f544asfasssffffasss", strlen("2a554442f544asfasssffffasss"));
//    frequencySort(s);
//
//    printf("%s\n",s);
//    system("pause");
//}
