
#include "foo.hpp"

#ifndef DEBUG
    #define DEBUG
#endif

/**
 * @brief 
 * 
 * @param [in] argc count of input files
 * @param [in] argv names array of input files
 * @return int 
 */


int main (int argc, char *argv[])
{
    if (!check_param (argc, argv[1], argv[2])) return INPUT_ERROR;

    Equation coef = {};
    
    Roots roots = {};

    #ifndef NDEBUG 
        Test_roots test_roots = {};
    #endif

    FILE *f_input = NULL;
    char *input_name = argv[1];
    int count_of_equations = 0;

    FILE *f_output = NULL;
    char *output_name = argv[2];
    f_output = fopen(output_name, "w");

    if ((f_input = fopen (input_name, "r")) == NULL)
    {
        printf ("didn`t open %s", input_name);
        return OPEN_FILE_ERROR;
    }
        
    if (!fscanf (f_input, "%d", &count_of_equations))
    {
        printf ("incorrect count of equations");
        return COUNT_EQ_ERROR;
    }

    for (int i = 0; i < count_of_equations; i++)
    {
        #ifdef NDEBUG
            if (read_string (&coef, f_input))
            {
                solve (&coef, &roots);
                release_output (f_output, &roots, i);
            }
            else
            {
                fprintf (f_output, "error in input of equation %d\n", i+1);
                return INPUT_ERROR;
            }
        #else
            if (read_string_test (&coef,&test_roots, f_input, input_name))
            {
                solve (&coef, &roots);
                test_output (f_output, &test_roots, &roots, i);
            }
            else
            {
                fprintf (f_output, "error in input of equation %d\n", i+1);
                return INPUT_ERROR;
            }
        #endif
    }
    
    fclose(f_input);
    fclose(f_output);
    
    return 0;
}
