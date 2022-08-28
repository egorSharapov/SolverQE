/**
 * @file main.cpp
 * @author snake_eyes
 * @brief solver of the quadratic equations
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <assert.h>

#ifndef FOO_HPP_INCLUDED
#define FOO_HPP_INCLUDED


/**
 * @brief enumeration of number of roots
 */
enum NUM_ROOTS 
{
    ZERO_ROOTS  = 0, ///< zero roots of the quadratic equation
    ONE_ROOT    = 1, ///< one root of the quadratic equation
    TWO_ROOTS   = 2, ///< two roots of the quadratic equation
    INF_ROOTS   = -1 ///< infinty roots of the quadratic equation
    
};


/**
 * @brief enumeration of errors code
 */
enum ERRORS_CODE 
{
    ERROR           = -1,
    FALL            = 0,
    SUCCESS         = 1, 
    INPUT_ERROR     = 3, ///< incorrect input error  
    OPEN_FILE_ERROR = 4, ///< error of open file
    COUNT_EQ_ERROR  = 5, ///< error count of eqations in input file
};


/**
 * @brief structure roots of the quadratic equation
 */
typedef struct
{
    int count_of_roots = NAN; //< count roots of the quadratic equation
    double x1          = NAN; //< first root of the quadratic equation
    double x2          = NAN; //< second root of the quadratic equation
} Roots;


/**
 * @brief  structure coefficients of equation
 */
typedef struct
{
    double a = NAN; //< coefficient at the quadratic term
    double b = NAN; //< coefficient at the linear term
    double c = NAN; //< free member
} Equation;


/**
 * @brief structure test roots of the quadratic equation
 */
typedef struct
{
    int count_of_roots  = NAN; //< count roots of the quadratic equation
    double x1           = NAN; //< first root of the quadratic equation
    double x2           = NAN; //< second root of the quadratic equation
} Test_roots;


/**
 * @brief checks user-entered command line arguments
 *
 * @param [in] argc count of input files
 * @param [in] first_arg name of input file
 * @param [in] second_arg name of output file
 * @return true if the command line arguments are entered correctly: files and their names
 * @return false if the command line arguments are entered incorrectly
 */
bool check_param (int argc, char *first_arg, char *second_arg);


/**
 * @brief checkes extension in file name
 * 
 * @return int returns error code
 */
int check_extension (char *file_name, const char *extension);


/**
 * @brief function of writing values ​​to the release file
 * 
 * @param [in] file name of output file
 * @param [in] roots structure roots of the quadratic equation
 * @param [in] i number of the read equation
 */
void release_output (FILE *output_file, Roots *roots, int number_of_eqation);

/**
 * @brief function of writing values ​​to the test file
 * 
 * @param [in] file name of output file
 * @param [in] test_roots structure of checked roots
 * @param [in] roots structure roots of the quadratic equation
 * @param [in] number_of_equation number of the read equation
 */
void test_output (FILE *output_file, Test_roots *test_roots, Roots *roots, int number_of_equation);

/**
 * @brief read one string from input file
 * 
 * @return true if the string is read correctly
 * @return false if the line is read incorrectly
 */
bool read_string (Equation *coef, FILE *file);


/**
 * @brief read one string from input file in test mode
 * 
 * @return true if the string is read correctly
 * @return false if the line is read incorrectly
 * 
 */
bool read_string_test (Equation *coef, Test_roots *test, FILE *file, char*);


/**
 * @brief solve the quadratic equation
 * 
 * @param [in] coef structure coefficients of the quadratic equation
 * @param [in] roots structure roots of the quadratic equation
 */
void solve (Equation *coef, Roots *roots);


/**
 * @brief solve the quadratic equation
 * 
 * @param [in] coef structure coefficients of the quadratic equation
 * @param [in] roots structure roots of the quadratic equation
 */
void quadratic (Equation *coef, Roots *roots);


/**
 * @brief solve the linear equation
 * 
 * @param [in] coef structure coefficients of the quadratic equation
 * @param [in] roots structure roots of the quadratic equation
 */
void linear (Equation *coef, Roots *roots);


/**
 * @brief compares the difference of two numbers with zero
 * 
 * @return true if the difference number is zero
 * @return false if the difference number isn`t zero
 */
bool is_zero (double, double);

#endif // FOO_HPP_INCLUDED
