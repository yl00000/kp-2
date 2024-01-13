#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
double getInput(const char *prompt);
bool isScientificNotation(const char *input);

double median(double a, double b, double c);
double bisector(double a, double b, double c, double p);
double hight(double a, double b, double c, double p);
int area(double a, double b, double c, double p);
int perimeter(double a, double b, double c);

int main(void)
{

    double a, b, c;
    while (1)
    {
        while (1)
        {
            a = getInput("Enter the first side a: ");
            b = getInput("Enter the second side b: ");
            c = getInput("Enter the third side c: ");
            if (a < 0 || b < 0 || c < 0)
            {
                printf("\n");
                printf("Enter only positive numbers. Please try again.\n");
                printf("\n");
            }
            else if ((a + b) <= c || (a + c) <= b || (c + b) <= a)
            {
                printf("\n");
                printf("Triangle does not exist. Please try again.\n");
                printf("\n");
            }
            else
            {
                break;
            }
        }

        double p = (a + b + c) / 2.0;
        printf("\n");
        printf("\t Computed Triangle Properties:\n");
        area(a, b, c, p);
        perimeter(a, b, c);
        printf("\t The median to side a is: %f\n", median(a, b, c));
        printf("\t The median to side b is: %f\n", median(b, a, c));
        printf("\t The median to side c is: %f\n", median(c, b, a));
        printf("\n");
        printf("\t The bissectrice to side a is: %f\n", bisector(a, b, c, p));
        printf("\t The bissectrice to side b is: %f\n", bisector(b, a, c, p));
        printf("\t The bissectrice to side c is: %f\n", bisector(c, b, a, p));
        printf("\n");
        printf("\t The height to side a is: %f\n", hight(a, b, c, p));
        printf("\t The height to side b is: %f\n", hight(b, a, c, p));
        printf("\t The height to side c is: %f\n", hight(c, b, a, p));
        printf("\n");
        char answer = ' ';
        printf("Would you like to continue? Y/N: ");
        while (answer != 'N' && answer != 'Y')
        {
            scanf("%c", &answer);
        }
        if (answer == 'Y')
        {
            printf("\n");
        }
        else if (answer == 'N')
        {

            break;
        }
    }
    return 0;
}

int area(double a, double b, double c, double p)
{
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("\n");
    printf("\t Area of the triangle is: %f \n", area);
    printf("\n");
    return 0;
}
int perimeter(double a, double b, double c)
{
    double P = a + b + c;
    printf("\t Perimeter of the triangle is: %f \n", P);
    printf("\n");
    return 0;
}

double median(double a, double b, double c)
{
    double m = 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    return m;
}
double bisector(double a, double b, double c, double p)
{
    double bisect = 2 / (b + c) * sqrt(b * c * p * (p - a));
    return bisect;
}
double hight(double a, double b, double c, double p)
{
    double h = (2 * sqrt(p * (p - a) * (p - b) * (p - c))) / a;
    return h;
}
double getInput(const char *prompt)
{
    char input[15];
    double number;

    do
    {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i]; i++)
        {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input))
            {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput)
        {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input)
{
    int len = strlen(input);
    int eCount = 0;
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (c == 'e' || c == 'E')
        {
            eCount++;
        }
        else if (isdigit(c) && eCount == 0)
        {
            digitsBeforeE++;
        }
        else if (isdigit(c) && eCount == 1)
        {
            digitsAfterE++;
        }
    }

    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}
