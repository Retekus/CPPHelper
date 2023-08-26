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



}

