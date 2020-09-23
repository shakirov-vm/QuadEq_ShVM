#include <stdio.h>
#include <math.h>

void QuadTest()
{
    double Koef_a[] = {1, 1, 1, 1, 1, 1};
    double Koef_b[] = {-3, 2, 2, 0, 4.000000004, 4.000000001};
    double Koef_c[] = {2, 1, 3, 0, 4.000000001, 4.000000004};
    int nRoots[] =    {2, 1, 0, 1, 1, 1};
    double RootX1[] = {1, NAN, NAN, NAN, NAN, NAN};
    double RootX2[] = {2, NAN, NAN, NAN, NAN, NAN};
    double RootX [] = {NAN, -1, NAN, 0, -2, -2};

    int Test_n_Roots[] = {0};
    double TestX1[] = {0};
    double TestX2[] = {0};
    double TestX [] = {0};
    int i = 0;

    for (i; i < 6; i++)
    {
        Test_n_Roots[i] = SolveQuadratic(Koef_a[i],Koef_b[i],Koef_c[i],&TestX1[i],&TestX2[i],&TestX[i]);

        if (Test_n_Roots[i] == nRoots[i])
        {
        if (Test_n_Roots[i] == 2)
            {
            if ((RootX1[i] == TestX1[i]) && (RootX2[i] == TestX2[i]))
                {
                printf("Test %i ok", i+1);
                }
            else
                printf("Test %i BAD", i+1);
            printf("\n");
            }
        if (Test_n_Roots[i] == 1)
            {
            if (RootX[i] == TestX[i])
                printf("Test %i ok", i+1);
            if (RootX[i] != TestX[i])
                printf("Test %i BAD", i+1);
            printf("\n");
            }
        if (Test_n_Roots[i] == 0)
            printf("Test %i ok\n", i+1);
        }
        else printf("Error in test.");
    }
    double LKoef_b[] = {0, 0, 1};
    double LKoef_c[] = {0, 1, 2};
       int LnRoots[] = {3, 0, 1};
    double LRootX [] = {NAN, NAN, -2};

    int LTest_n_Roots[] = {0};
    double LTestX [] = {0};

    int j = 0;

    for (j; j < 3; j++)
    {
        LTest_n_Roots[j] = SolveLinear(LKoef_b[j], LKoef_c[j], &LTestX[j]);

        if (LTest_n_Roots[j] == LnRoots[j])
        {
        if (LTest_n_Roots[j] == 3)
            {
                printf("Test %i ok\n", j+7);
            }
        if (LTest_n_Roots[j] == 1)
            {
            if (LRootX[j] == LTestX[j])
                printf("Test %i ok",j+7);
            if (LRootX[j] != LTestX[j])
                printf("Test %i BAD", j+7);
            printf("\n");
            }
        if (LTest_n_Roots[j] == 0)
            printf("Test %i ok\n", j+7);

        }
        else printf("Error in test.");
    }
}
