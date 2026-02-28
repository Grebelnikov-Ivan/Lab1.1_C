#include <stdio.h>

void lab1_1();
char* creat_set(char st[]);
char* del_same_ones(char st[], char ch, int start_i);
char* compact_str_to_condition(char st1[], char st2[]);
int analogue_strlen(const char st[]);


void lab1_2();
int parity_check(const char st[], int len_st);
int not_empty(int len_st);
int only_numbers(const char st[], int len_st);
int divisible_4(const char st[], int len_st);
int do_check(const char st[], int len_st);


int main() {
    lab1_1();

    lab1_2();

    return 0;
}


void lab1_1(){
    char st1[1000] = "lmnawkagg";
    char st2[1000] = "anwwamnn";
    char* result2 = compact_str_to_condition(st1, st2);
    printf("rez: %s", result2);

}


char* creat_set(char st[]){
    int i = 0;
    int len_st = analogue_strlen(st);
    while (i < len_st){
        int j = i + 1;
        while(j < len_st){
            if (st[i] == st[j]){
                st = del_same_ones(st, st[i], j);
                len_st = analogue_strlen(st);
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

    int len_st = analogue_strlen(st);
    while (i < len_st){
        if (st[i] != ch) {
            st[j] = st[i];
            j ++;
        }
        i ++;
    }
    st[j] = '\0';
    return st;
}

char* compact_str_to_condition(char st1[], char st2[]){
    st2 = creat_set(st2);
    int i = 0;
    int len_st1 = analogue_strlen(st1);
    while (i < len_st1){
        int j = 0;
        int len_st2 = analogue_strlen(st2);
        while(j < len_st2){
            if (st1[i] == st2[j]){
                st1 = del_same_ones(st1, st1[i], i);
                len_st1 = analogue_strlen(st1);
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


int analogue_strlen(const char st[]){
    int len = 0;
    while (st[len] != '\0')
        len ++;
    return len;
}


void lab1_2(){
    char st1[1000] = "aewr4";
    int len_st = analogue_strlen(st1);
    do_check(st1, len_st);
}



int not_empty(int len_st){
    if (len_st == 0)
        return 1;
    return 0;
}


int parity_check(const char st[], int len_st){
    char st2[6] = "02468";
    for (int i = 0; i < 5; i ++){
        if (st[len_st - 1] == st2[i]){
            return 0;
        }
    }
    return 1;
}

int only_numbers(const char st[], int len_st){
    for (int i = 0; i < len_st; i++) {
        if (st[i] < '0' || st[i] > '9') {
            return 1;
        }
    }
    return 0;
}

int divisible_4(const char st[], int len_st){
    if (len_st == 1){
        if ((st[0] - '0') % 4 == 0)
            return 1;
    }

    if ((st[len_st - 1] - '0' + (st[len_st - 2] - '0') * 10) % 4 == 0)
        return 0;
    return 1;
}

int do_check(const char st[], int len_st){
    if (not_empty(len_st) != 0){
        printf("the line is empty");
        return 1;
    }
    if (parity_check(st, len_st) != 0) {
        printf("it is not an even or decimal number, meaning it is not divisible by 4");
        return 1;
    }

    if (only_numbers(st, len_st) != 0) {
        printf("the string is not just numbers");
        return 1;
    }

    if (divisible_4(st, len_st) != 0)
        printf("the number is not divisible by 4");
    else
        printf("the number is divisible by 4");
    return 0;
}






