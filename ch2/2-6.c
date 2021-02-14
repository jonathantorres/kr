#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, int y);
unsigned int getbits(unsigned int x, int p, int n);

int main(void)
{
    unsigned int x = 150;
    unsigned int y = 100;
    int p = 3;
    int n = 4;
    printf("%u set-> %u = %u\n", x, y, setbits(x, p, n, y));
    return 0;
}

// returns x with the n bits that begin at position p,
// set to the rightmost n bits of y,
// leaving the other bits unchanged
// TODO: there's a bug here, try with different test cases
// maybe see (ex. 2-7)
unsigned int setbits(unsigned int x, int p, int n, int y)
{
    unsigned int ry = getbits(y, p, n);
    int xa = x & (~0 << n);
    ry = ry << (p+1-n);
    return xa | ry;
}

// getbits: get n bits from position p
unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
