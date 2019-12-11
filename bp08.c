#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tokenize(char *str, char delim, unsigned int *num);

int main(int argc, char **argv)
{
        char *str;
        char **tokens;
        unsigned int nTokens;
        unsigned int i;

        if (argc != 3) {
                printf("You should have 2 instead of %i arguments\n", argc - 1);
                return 0;
        }
        if (strlen(argv[2]) != 1) {
                printf("Your second argument is not a single character\n");
                return 0;
        }
        str = (char*)calloc((strlen(argv[1]) + 1), sizeof(char));
        strcpy(str, argv[1]);
        tokens = tokenize(str, argv[2][0], &nTokens);
        printf("%i\n", nTokens);
        for (i = 0; i < nTokens; ++i) {
                printf("%s ", tokens[i]);
        }
        putchar('\n');
        free(str);
        free(tokens);
        return 0;
}

char **tokenize(char *str, char delim, unsigned int *num)
{
        char **tokens = NULL;
        *num = 0;

        if (strlen(str) == 0) {
                return NULL;
        }

        while (*str) {
                if (*str == delim) {
                        *str = '\0';
                        if(!(*(str + 1) == delim) && !(*(str + 1) == '\0')) {
                                ++(*num);
                                tokens = (char **)realloc(tokens, (*num) * sizeof(char *));
                                tokens[*(num) - 1] = (str + 1);
                        }
                }
                ++str;
        }
        return tokens;
}
