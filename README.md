# **solve the quadratic equations**
---
### documentation
In docs folder

### using the program
The program has two modes of operation: test and release.
In test mode, the program opens the files specified in the arguments and reads the coefficients of the quadratic equation and the pre-recorded solutions, after which it outputs the test results to the output file. Example of input file:

![изображение](https://user-images.githubusercontent.com/111515657/187025151-0da0f7e0-40e6-4461-b230-8be7d8e350c9.png)

The first string indicates the number of quadratic equations
The following strings indicate the coefficients and roots of the quadratic equation in the format: a b c count_of_roots x1 x2

To compile the program in test mode, enter the "make test" command in the console.
Example:

![изображение](https://user-images.githubusercontent.com/111515657/187024914-3ff04709-9c36-432e-a31a-0a2f82849e1e.png)

To run the program in test mode, enter the "\.prog input_file_name.txt output_file.txt".
Example:

![изображение](https://user-images.githubusercontent.com/111515657/187024961-15d19d47-cd5f-4499-b5dc-ada50f9bcfbe.png)

In release mode, the program opens the files specified in the arguments and reads the coefficients of the quadratic equation, after which it outputs the release results to the output file. 
Example of input file:

![изображение](https://user-images.githubusercontent.com/111515657/187025015-d4842049-ca0f-4c4f-b724-071b72bba9bd.png)

The first string indicates the number of quadratic equations
The following strings indicate the coefficients and roots of the quadratic equation in the format: a b c

To compile the program in test mode, enter the "make release" command in the console.
Example:

![изображение](https://user-images.githubusercontent.com/111515657/187025034-af3429c8-ca98-44db-aacb-0959a34690a3.png)

To run the program in release mode, enter the "\.prog input_file_name.txt output_file.txt".
Example:

![изображение](https://user-images.githubusercontent.com/111515657/187025050-235cab90-60cb-44f8-851d-115261b570b0.png)
