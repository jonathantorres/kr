#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);
void itoa2(int n, char s[]);

int main(void)
{
    int n = 324;
    char s[25];

    itoa(n, s);
    printf("%d = %s\n", n, s);
    return 0;
}

// reverse: reverse string s in place
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// itoa: convert n to characters in s
void itoa(int n, char s[])
{
    int i, sign;
    sign = n;
    n = abs(n); // sets n to be positive
    i = 0;
    // generate digits in reverse order
    do {
        s[i++] = n % 10 + '0'; // get next digit
    } while ((n /= 10) > 0); // delete it

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

// itoa: convert n to characters in s
void itoa2(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) { // record sign
        n = -n; // make n positive
    }
    i = 0;
    // generate digits in reverse order
    do {
        s[i++] = n % 10 + '0'; // get next digit
    } while ((n /= 10) > 0); // delete it

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}