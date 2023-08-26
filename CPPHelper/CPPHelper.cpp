// CPP HELPER BY RETEKUS //

//***BASIC DATA TYPES***//

char Character;

int Integer;
long LongInt; //long == long int
unsigned InsignedInt; //unsigned == unsigned int (only positive values)

float Float; //floating poit
double Double; //float with 2x size

bool Boolean;

//***MACROS***//

#include <iostream> //add standart library (InputOutputSTREAM)
#include <vector> //standart dynamical array library
#include <cstdlib> //standart C library
#include <string> //standart C++ st0ing library
#include <set> //standart SET library

#include "CPPHelper.h" //add ur own .cpp/.h/... files

//***MAIN***//

int main() //main function starts the program, if program done returns 0
{
//***STANDART C++ STYLE CONSOLE IO***//

    std::cin >> Character >> Integer;

//***LOGIC BRANCHES***//

    if (bool IsTrue = true) {/* do smth */ }

    bool Variable = (/*condition*/ 2 + 2 == 4) ? true : false; //ternary operator

    switch(Boolean /*variable equal to case*/)
    {
    case true: /*do smth*/
    case false: /*do smth else*/

    default: /*defauld instructions*/
    }

//***LOOPS***//

    for (size_t i = 0; i < Integer; i++) {/*do smth "Integer" times*/ }

    for(auto Variable : Arr) {/*Variable == Arr[Item from 1st to last]*/ }

    while(Boolean){/*do smth while Boolean == true*/ }

    do {/*do smth once than check Boolean, if true - continue loop*/ } while (Boolean);

//***POINTERS***//

    int* Pointer; //create pointer to memory cell with int variable inside

    int* Pointer = &Integer; //& - get variable adress operator

    Integer = *Pointer; //get value inside Pointer pointing adress

//***ARRAYS***//

    int FixedArr[5] = {}; //create fixed 5 values array, with standart definition from 0 to 4
    //FixedArr is a pointer to first value in array
    //FixedArr[4] is equal to *(FixedArr + 4)

    std::vector<int> Vector; //create vector - dynamical array

    int* DynArr = new int[Integer]; //create dynamic array, allocated in heap

    int cols, rows; //cols and rows in 2d arrays

    int** DynArr2D = new int* [rows]; //create dynamic array, (memory fragmentation risc!) 
    for (size_t i = 0; i < rows; i++)
        DynArr2D[i] = new int[cols];

    int** DynArr2DEff = new int* [rows]; //create dynamic array. Efficient memory allocation
    DynArr2DEff[0] = new int[rows * cols];
    for (size_t i = 0; i < rows; i++)
        DynArr2DEff[i] = DynArr2DEff[i - 1] + cols;

}

