#include "foo.hpp"


bool read_string_test (Equation *coef, Test_roots *test_roots, FILE *file, char  *name)
{
    assert (test_roots != NULL);
    assert (coef       != NULL);
    assert (file       != NULL);
    assert (name       != NULL);

    int count_of_input = fscanf (file, "%lg %lg %lg ", &(coef->a), &(coef->b), &(coef->c));
    
    if (!fscanf (file, "%d", &(test_roots->count_of_roots)))
    {
        printf("%d", test_roots->count_of_roots);
        return INPUT_ERROR;
    }
        
    switch (test_roots->count_of_roots)
    {
    case ONE_ROOT:
        fscanf (file, "%lg", &(test_roots->x1));
        break;

    case TWO_ROOTS:
        fscanf (file, "%lg %lg", &(test_roots->x1), &(test_roots->x2));
        break;

    default:
        return (count_of_input == INPUT_ERROR);
        break;
    }

    return (count_of_input == INPUT_ERROR);
}


void test_output (FILE *output_file, Test_roots *test_roots, Roots *roots, int number_of_eqation)
{
    assert(output_file != NULL);
    assert(test_roots  != NULL);
    assert(roots       != NULL);
    assert(isfinite(number_of_eqation));

    fprintf (output_file, "test of equation %d: ", number_of_eqation+1);

    if (test_roots->count_of_roots != roots->count_of_roots)
    {
        fprintf (output_file, "count of roots error: received %d but expect %d\n", roots->count_of_roots, test_roots->count_of_roots);
    }
    else if ((test_roots->count_of_roots == ONE_ROOT) && !is_zero(test_roots->x1, roots->x1))
    {
        fprintf (output_file, "value of roots error: received x = %lg but expect x = %lg\n", roots->x1, test_roots->x1);
    }
    else if ((test_roots->count_of_roots == TWO_ROOTS) && !is_zero(test_roots->x1,  roots->x1) && !is_zero(test_roots->x1,  roots->x1))
    {
        fprintf (output_file, "value of roots error: received x1 = %lg x2 = %lg but expect x1 = %lg x2 = %lg\n", 
                                                              roots->x1, roots->x2,       test_roots->x1, test_roots->x2);
    }
    else
    {
        fprintf (output_file, "success! \n");       
    }
}

