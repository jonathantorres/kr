#include <stdio.h>

float to_celcius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper  = 300;
    step = 20;
    fahr = lower;

    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper) {
        celsius = to_celcius(fahr);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
