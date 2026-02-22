#include <stdio.h>
#include <string.h>

void creat_set(char st[]);
void del_same_ones(char st[], char ch, int start_i, char**r_st, int*r_len);

int main() {
    char st1[1000], st2[1000];
    scanf("%s", st1);
    printf("%s", st1);
    scanf("%s", st2);
    char* r_st;
    int r_len;
    del_same_ones(st2, 'a', 3, &r_st, &r_len);
    printf("%s", r_st);
    printf("%d", r_len);

    return 0;

}


void creat_set(char st[]){

}

void del_same_ones(char st[], char ch, int start_i, char**r_st, int*r_len){
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
    printf("%s", st);
    /*for (int c = 0; c < j; c ++)
        printf("%c", st[c]);*/
    *r_st = st;
    *r_len = j;
}

