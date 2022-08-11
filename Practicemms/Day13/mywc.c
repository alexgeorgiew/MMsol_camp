#include<stdio.h>
// ./a.out FILE_NAME SEARCHED_WORD
int main(int argc, char * argp[]) {
    // Open file for reading
    FILE* f = fopen(argp[1], "r");
    int cur_sym;
    
    // We want to count occurances of word in file
    char *word = argp[2];

    // word_counter is the:
    // NUMBER OF CONSECUTIVE SYMBOLS FROM WORD, FOUND IN FILE
    // res is the number of occurances of word in file
    int word_counter = 0, res = 0;
    // Read each symbol from file once
    while((cur_sym=fgetc(f))!=EOF) {
        printf("cur_sym: %c\n", cur_sym);
        printf("word_counter: %d\n", word_counter);
        printf("word[word_counter]: %c\n", word[word_counter]);
        if (cur_sym != word[word_counter])
        {
            word_counter = 0;
            printf("No match - resetting word_counter to 0\n");
        }
        if(cur_sym == word[word_counter]){
            word_counter++;
            printf("word[word_counter] and cur_sym match - adding 1 to word_counter\n");
        }
        
        if(word[word_counter] == '\0') {
            res++;
            word_counter = 0;
            printf("Occurance of word found - res++\n");
        }
        printf("\n");
    }
    fprintf(stdout, "%d\n", res);
    fclose(f);
    return 0;
}
