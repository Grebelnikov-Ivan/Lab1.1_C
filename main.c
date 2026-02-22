#include <stdio.h>
#include <string.h>

char* creat_set(char st[]);
char* del_same_ones(char st[], char ch, int start_i);
char* compact_str_to_condition(char st1[], char st2[]);

int main() {
    char st1[1000], st2[1000];
    scanf("%s", st1);
    scanf("%s", st2);
    char* result = creat_set(st2);
    printf("%s", result);
    char* result2 = compact_str_to_condition(st1, st2);
    printf("%s", result2);

    return 0;

}


char* creat_set(char st[]){
    int i = 0;
    int len_st = strlen(st);
    while (i < len_st){
        int j = i + 1;
        while(j < len_st){
            if (st[i] == st[j]){
                st = del_same_ones(st, st[i], j);
                len_st = strlen(st);
                break;
            }
            else{
                j++;
            }

        }
        i++;
    }
    return st;
}


char* del_same_ones(char st[], char ch, int start_i){
    int i = start_i;
    int j = start_i;

    int len_st = strlen(st);
    while (i < len_st){
        if (st[i] != ch) {
            st[j] = st[i];
            j ++;
        }
        i ++;
    }
    st[j] = '\0';
    /*for (int c = 0; c < j; c ++)
        printf("%c", st[c]);*/
    return st;
}

char* compact_str_to_condition(char st1[], char st2[]){
    int i = 0;
    int len_st1 = strlen(st1);
    while (i < len_st1){
        int j = 0;
        int len_st2 = strlen(st2);
        while(j < len_st2){
            if (st1[i] == st2[j]){
                st1 = del_same_ones(st1, st1[i], i);
                len_st1 = strlen(st1);
                i--;
                break;
            }
            else{
                j++;
            }
        }
        i++;
    }
    return st1;
}


