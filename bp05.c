#include <stdio.h>
#include <string.h>

#define MIN_STRING 3
#define MAX_STRING 30
#define TRUE 1

int read_string(char input[]);
int count_string(char w[], char c);
void flush_buff(void);

int main(void)
{
        int status;
        char string[MAX_STRING + 1];
        printf("Dieses Programm zählt die Anzahl der \'!\' und \'?\'.\n");
        while(TRUE) {
                printf("Eine Eingabe:\n");
                status = read_string(string);
                if (status == 0){
                        printf("Ungültige Eingabe. Neue Eingabe:\n");
                        continue;
                }
                if(!(strcmp(string, "ende"))) {
                        break;
                }  else {
                        printf("Anzahl an \'?\' im String: %i\n", count_string(string, '?'));
                        printf("Anzahl an \'!\' im String: %i\n", count_string(string, '!'));
                }
        }
        printf("Ende des Programms.\n");
        return 0;
}

int read_string(char input[])
{
        int i = 0;
        char c = getchar();
        while (c != '\n' && i < MAX_STRING) {
                input[i++] = c;
                c = getchar();
        }
        printf("%i\n", i);
        if(i < MIN_STRING) {
                return 0;
        } else if(i == MAX_STRING && c != '\n') {
                flush_buff();
                return 0;
        }
        input[i] = '\0';
        return 1;
}

int count_string(char w[], char c)
{
        int i, char_count;
        i = 0;
        char_count = 0;
        while (w[i] != '\0')
        {
                if(w[i] == c) {
                        char_count += 1;
                }
                ++i;
        }
        return char_count;
}

void flush_buff(void)
{
        char c = getchar();
        while (c != '\n'){
                c = getchar();
        }
}
