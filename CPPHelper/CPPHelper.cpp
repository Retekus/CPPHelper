// CPP HELPER BY RETEKUS //

//***DATA TYPES***//

char Character;

int Integer;
long LongInt; //long == long int
unsigned InsignedInt; //unsigned == unsigned int (only positive values)

float Float; //floating poit
double Double; //float with 2x size

bool Boolean;

//***MACROS***//

#include <iostream> //add standart library
#include "CPPHelper.h" //add ur own .cpp/.h/... files

//***LOGIC BRANCHES***//

void Branches()
{
    if (bool IsTrue = true) {/* do smth */ }

    bool Variable = (/*condition*/ 2 + 2 == 4) ? true : false; //ternary operator

    switch(Boolean /*variable equal to case*/)
    {
    case true: /*do smth*/
    case false: /*do smth else*/

    default: /*defauld instructions*/
    }
}

//***LOOPS***//

void Loops()
{
    for (size_t i = 0; i < Integer; i++) {/*do smth "Integer" times*/ }

    for(auto Variable : Arr) {/*Variable == Arr[Item from 1st to last]*/ }

    while(Boolean){/*do smth while Boolean == true*/ }

    do {/*do smth once than check Boolean, if true - continue loop*/ } while (Boolean);
}

//**POINTERS**//

int main()
{
    std::cout << "Hello World!\n";
}

