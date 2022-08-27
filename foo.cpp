#include "foo.hpp"

bool read_string (Equation *coef, FILE *file)
{
    assert (coef != NULL);
    assert (file != NULL);

    int count_of_input = fscanf (file, "%lg %lg %lg ", &(coef->a), &(coef->b), &(coef->c));
    
    return (count_of_input == INPUT_ERROR);
}

void release_output (FILE *f_output, Roots *roots, int number_of_equation)
{
    assert (isfinite(number_of_equation));
    assert (f_output != NULL);
    assert (roots != NULL);

    fprintf (f_output, "solution(s) of equation %d:  ", number_of_equation + 1);
                
    switch(roots->count_of_roots)
    {
        case ZERO_ROOTS:
            fprintf (f_output, "no solutions \n");
            break;  
        case ONE_ROOT:
            fprintf (f_output, "x = %lg \n", roots->x1);
            break;
        case TWO_ROOTS:
            fprintf (f_output, "x1 = %lg x2 = %lg \n", roots->x1, roots->x2);
            break;
        case INF_ROOTS:
            fprintf (f_output, "infinity solutions \n");
            break;
        default:
            fprintf (f_output, "incorrect input \n");
    }
}

void solve (Equation *coef, Roots *roots)
{
    assert (roots != NULL);
    assert (isfinite(coef->a));
    assert (isfinite(coef->b));
    assert (isfinite(coef->c));

    if (is_zero(coef->a, 0))
    { 
        linear (coef, roots);
    }
    else
    {
        quadratic (coef, roots);
    }
}

bool is_zero (double number_1, double number_2)
{
    assert (isfinite(number_1));
    assert (isfinite(number_2));    
    
    return fabs (number_1 - number_2) < DBL_EPSILON;

}


void quadratic (Equation *coef, Roots *roots)
{      
    assert (roots != NULL);
    assert (isfinite(coef->a));
    assert (isfinite(coef->b));
    assert (isfinite(coef->c));

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    if (D < 0)
    {
        roots->count_of_roots = ZERO_ROOTS;
    }
    else if (is_zero(D, 0))
    {
        roots->x1 = -coef->b / (2 * coef->a);
        roots->count_of_roots = ONE_ROOT;
    }
    else 
    {
        D = sqrt (D);
        
        roots->x1 = (-coef->b + D) / (2 * coef->a);
        roots->x2 = (-coef->b - D) / (2 * coef->a);
        
        roots->count_of_roots = TWO_ROOTS;
    } 

}


void linear (Equation *coef, Roots *roots)
{
    assert (roots != nullptr);
    assert (isfinite(coef->a));
    assert (isfinite(coef->b));
    assert (isfinite(coef->c));
    
    if (is_zero(coef->a, 0) && is_zero(coef->b, 0) && is_zero(coef->c, 0))
    {
        roots->count_of_roots = INF_ROOTS;
    }
    else if (is_zero(coef->c, 0))
    {
        roots->count_of_roots = ZERO_ROOTS;
    }
    else
    {
        roots->x1 = -coef->c / coef->b;
        roots->count_of_roots = ONE_ROOT;
    }
}


bool check_param (int argc, char *first_arg, char *second_arg)
{

    if (argc == 1)
    {
        printf ("example: \\.prog input_file.txt output_file.txt\n");
        return FALL;
    }
    else if ((argc != 3))
    {
        printf ("incorrect number of parametrs \n\n" \
               "example: \\.prog input_file.txt output_file.txt\n\n");
        return FALL;
    }
    else if (check_extension(first_arg, "txt") ==  ERROR or check_extension(second_arg, "txt") ==  ERROR)
    {
        printf ("files should have the .txt extension");
        return FALL;
    }
    return SUCCESS;
}


int check_extension (char *file_name, const char *extension)
{
    char *last_word = strchr(file_name, '.')+1;

    if (strstr(last_word, extension))
        return SUCCESS;
    else
        return ERROR;
}

