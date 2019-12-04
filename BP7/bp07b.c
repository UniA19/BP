#include <stdio.h>

void append_pointer(char *destination, char *source);
void append_array(char destination[], char source[]);

#define ARR_SIZE 10
int main(void)
{
        char str1[ARR_SIZE] = "abdc";
        char str2[ARR_SIZE] = "fghi";
        char str3[ARR_SIZE] = "abdc";
        char str4[ARR_SIZE] = "fghi";
        printf("str1 = \"%s\"\n", str1);
        printf("str2 = \"%s\"\n", str2);
        printf("str3 = \"%s\"\n", str3);
        printf("str4 = \"%s\"\n", str4);
        printf("append_pointer(str1, str2)\n");
        append_pointer(str1, str2);
        printf("append_array(str3, str4)\n");
        append_array(str3, str4);
        printf("str1 = \"%s\"\n", str1);
        printf("str2 = \"%s\"\n", str2);
        printf("str3 = \"%s\"\n", str3);
        printf("str4 = \"%s\"\n", str4);
        return 0;
}

void append_pointer(char *destination, char *source) {
        while (*destination) ++destination;
        while ((*destination++ = *source++));
}

void append_array(char destination[], char source[])
{
        int i;
        int j;
        for (i = 0; destination[i]; ++i) {}
        for (j = 0; (destination[i++] = source[j++]);)  {}
}
