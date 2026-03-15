#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

void lab1_1();
int check_correctness_ASCII(char st[]);
int compact_str_to_condition(char st1[], char st2[]);
int analogue_strlen(const char st[]);


void lab1_2();
int not_empty(int len_st);
int only_numbers(const char st[], int len_st);
int check_divisible_n(const char st[], int n);
int do_check(char st[], int n);


int lab1_3();
int check_correctness_symbol(char ch);
// int check_w(char w[]);
int print_all_matching_words(char st[], const char w[]);


int main() {
    // lab1_1();

    // lab1_2();

    lab1_3();

    return 0;
}


void lab1_1(){
    char *st1 = NULL;
    char st11[1000] = "abcdefghij";
    st1 = st11;
    char *st2 = NULL;
    char st22[1000] = "acegi";
    st2 = st22;
    // char st1[1000] = "abcdefghij";
    // char st2[1000] = "acegi"; // bdfhj

    // char st1[1000] = "Sfdsm";
    // char st2[1000] = ""; // Sfdsm

    // char st1[1000] = "";
    // char st2[1000] = "asdf"; // ""

    // char st1[1000] = "asdf";
    // char st2[1000] = "sadf"; // ""

    // char st1[1000] = "a b c 1 2 3";
    // char st2[1000] = " 123"; // abc


    // char st1[1000] = "abcdef";
    // char st2[1000] = "xyz"; // abcdef

    // char st1[1000] = "dggffAAA";
    // char st2[1000] = "gA"; // dff


    // char st1[1000] = "aaaaabbbbbcccccdddd";
    // char st2[1000] = "abc"; // dddd

    // char st1[1000] = "abc丝defghij";
    // char st2[1000] = "acegi";
    clock_t start = clock();
    if (compact_str_to_condition(st1, st2) == 1)
        printf("error");
    else
        printf("rez: %s", st1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("    time: %.12f\n", time_spent);
}


int check_correctness_ASCII(char st[]){
    if (st == NULL) {
        return 1;
    }
    int i = 0;
    if (st[strlen(st)] != '\0')
        return 3;
    while (st[i] != '\0'){
        unsigned char uc = (unsigned char)st[i];
        if (uc > 127)
            return 4;
        i ++;
    }
    return 0;
}

int compact_str_to_condition(char st1[], char st2[]) {
    if (check_correctness_ASCII(st1) != 0)
        return 1;
    if (check_correctness_ASCII(st2) != 0)
        return 1;
    int flags[256] = {0}; // характеристический массив
    int i = 0;

    while (st2[i] != '\0') {
        unsigned codech = (unsigned char) st2[i];  // получаем ASCII код
        flags[codech] = 1;
        i++;
    }
    i = 0;
    int j = 0;

    while (st1[i] != '\0') {
        unsigned codech = (unsigned char) st1[i];

        if (flags[codech] == 0) {
            st1[j] = st1[i];
            j++;
        }
        i++;
    }
    st1[j] = '\0';
    return 0;
}


int analogue_strlen(const char st[]){
    int len = 0;
    while (st[len] != '\0')
        len ++;
    return len;
}


void lab1_2(){
    char *st1 = NULL;
    char st11[1000] = "3468932";
    st1 = st11;
    int n = 4;
    // char st1[1000] = "3468932";
    // char st1[1000] = "";
    // char st1[1000] = "3";
    // char st1[1000] = "n";
    // char st1[1000] = "n4";
    // char st1[1000] = "14";
    // char st1[1000] = "-3468932";
    // char st1[1000] = "346丝8932";
    do_check(st1, n);
}

int not_empty(int len_st){
    if (len_st == 0)
        return 1;
    return 0;
}


int only_numbers(const char st[], int len_st){
    if (st == NULL) {
        return 1;
    }
    for (int i = 0; i < len_st; i++) {
        if (st[i] < '0' || st[i] > '9') {
            if (!(st[i] == '-' && i == 0)) //  len_st != 1
                return 1;
        }
    }
    return 0;
}

int check_divisible_n(const char st[], int n){
    if (st == NULL) {
        return 1;
    }
    errno = 0;
    long result = strtol(st, NULL, 10);

    if (errno == ERANGE)
        return 1;
    /*if (len_st == 1){
        if ((st[0] - '0') % 4 == 0)
            return 1;
    }

    if ((st[len_st - 1] - '0' + (st[len_st - 2] - '0') * 10) % 4 == 0)
        return 0;*/
    if (result % n == 0)
        return 0;
    return 1;
}

int do_check(char st[], int n){
    if (check_correctness_ASCII(st) != 0){
        printf("error");
        return 1;
    }
    int len_st = analogue_strlen(st);
    if (not_empty(len_st) != 0){
        printf("the line is empty");
        return 1;
    }

    if (only_numbers(st, len_st) != 0) {
        printf("the string is not just numbers");
        return 1;
    }

    int r = check_divisible_n(st, n) != 0;
    if (r == 1)
        printf("the number is not divisible");
    else
        printf("the number is divisible");
    return 0;
}


int lab1_3() {
    char *st = NULL;
    char st11[1000] = "qwe   vqwe qw wq,qww q.";
    st = st11;

    char *w = NULL;
    char ww[1000] = "qw";
    w = ww;
    // char st[1000] = "qwe   vqwe qw wq,qww q.";
    // char w[1000] = "qw";

    // char st[1000] = "qwe   Дqwe qw wq,qww q.";
    // char w[1000] = "qw";

    // char st[1000] = "qwe   vqwe qw wq,qww q.";
    // char w[1000] = "яw";

    // char st[1000] = "as,a fa a.";
    // char w[1000] = "ammz";

    // char st[1000] = "as ad af a .";
    // char w[1000] = "a";

    // char st[1000] = "as ad as .";
    // char w[1000] = "asssss";

    // char st[1000] = "as ad af as.";
    // char w[1000] = "as";

    // char st[1000] = "as ad af.";
    // char w[1000] = "amSD";

    // char st[1000] = "DSdas ad af.";
    // char w[1000] = "am";
    if (check_correctness_ASCII(st) != 0)
        return 1;
    if (check_correctness_ASCII(w) != 0)
        return 1;
    // change_st_w(st, w);
    if (print_all_matching_words(st, w) != 0)
        printf("error");
    return 0;
}


int check_correctness_symbol(char ch){
    unsigned char uc = (unsigned char)ch;
    if (!(ch >= 'a' && ch <= 'z')){
        if (ch != ' ' && ch != ','){
            if (uc > 127)
                return 3;
            return 2;
        }
        else
            return 1; // ch == ' ' || ch == ','
    }
    return 0; // abc...z
}

/*int check_w(char w[]){
    int i = 0;
    while (w[i] != '\0'){
        if (check_correctness_symbol(w[i]) != 0) {
            return 1;
        }
        i ++;
    }
    return 0;
}*/
// нужно создать массив

int print_all_matching_words(char st[], const char w[]){
    int start_sl = 0, i = 0, f = 0, r_check = 0;
    int len_w = analogue_strlen(w);
    while (st[i] != '.' && st[i] != '\0'){
        r_check = check_correctness_symbol(st[i]);
        if (r_check >= 2)
            return 1;
        if (r_check == 0){
            if (st[i] != w[i - start_sl])
                f = 1;
        }
        else{
            if (f == 1 || i - start_sl != len_w && i - start_sl != 0){
                //
                while (start_sl < i){
                    printf("%c", st[start_sl]);
                    start_sl ++;
                }
                printf("%c", ' ');
                f = 0;
            }
            start_sl = i + 1;
        }
        i ++;
    }
    if (f == 1 || i - start_sl != len_w && i - start_sl != 0){
        while (start_sl < i) {
            printf("%c", st[start_sl]);
            start_sl ++;
        }
    }
    return 0;
}