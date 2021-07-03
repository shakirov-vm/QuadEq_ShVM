#include <stdio.h>
#include <math.h>

int IsZero(double forCompare)
    {
        const double small = 1e-6;

        if (fabs(forCompare) <  small) return 1;
        if (fabs(forCompare) >= small) return 0;
    }
int SolveLinear(double b, double c, double* x)
{
        if (b!=0)
        {
            *x = -c/b;

            return 1;
        }
        if (IsZero(b) == 1 && IsZero(c) == 1)
        {
            return 3;
        }
        if (IsZero(b) == 1 && c!=0)
        {
            return 0;
        }
        else return -1;
}
int SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x)
{

        double discrim = b*b - 4*a*c;

        if (IsZero(discrim) == 1) discrim = 0;

        if (discrim > 0)
        {
            *x1 = (-b - sqrt(discrim))/(2*a);
            *x2 = (-b + sqrt(discrim))/(2*a);

            return 2;
        }

        if (discrim == 0)
        {
            *x = -b/2*a;
            *x = round(*x);

            return 1;

        }
        if (discrim < 0)
        {
            return 0;
        }
        else return -1;
}
