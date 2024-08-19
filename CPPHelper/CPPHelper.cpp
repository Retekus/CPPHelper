// CPP HELPER BY RETEKUS //

//***BASIC DATA TYPES***//

char Character;

int Integer;

float Float; //floating poit
double Double; //float with 2x size

bool Boolean;

size_t Size; //Usefull data type, have size of machine word, depending on system architecture

//***OPERATORS***//

//Arifmetical: + - ++(inc) --(dec) * / % += -= *= /= %=

//Bite: ~(not) &(and) |(or) ^(xor) &= |= ^= <<(slide left) >>(slide right)

//Logic: !(not) &&(and) ||(or) ==(equal) < > <= >= 

//Special: =(assert) *(dereferencing) &(get pointer) ->(same as (*Obj).Method) ->*(idk) , . ::(get into namespace)

//Special: [] () (type) new new[] delete delete[]

//***TYPE MODIFIERS***//

int const Pi = 3.14; //Make Pi non changable

long LongInt; //long == long int(more data)
unsigned InsignedInt; //unsigned == unsigned int (only positive values)

extern int SomeValue; //Declare variable without initialization

//***MACROS***//

#include <iostream> //add standart library (InputOutputSTREAM)
#include <vector> //standart dynamical array library
#include <cstdlib> //standart C library
#include <string> //standart C++ string library
#include <set> //standart SET library
#include <stddef> //NULL
#include <algorithm> //most popular algorithms (sort...)

#include "CPPHelper.h" //add ur own .cpp/.h/... files

//***FUNCTIONS***//
//Function - piece of code which does something and can be called anywhere, multiple times
// /*Function return type*/ /*Function name*/ (/*Function parameters*/) {/*Function logic*/;}

void Foo() {}; //Function declaration.
//Void functions return nothing

int Bar(int value)
{
    return value; //Function returns value
}

//***MAIN FUNCTION***//

int main() //Main function - function where the program begins, if program done returns 0
{
//***STANDART C++ STYLE CONSOLE IO***//

    std::cin >> Character >> Integer;

//***LOGIC BRANCHES***//

    bool IsTrue = true, IsTrueX = true;

    if (IsTrue) {/* do smth */ }
    else if (IsTrueX) {/* do smth if IsTrue == false, but if IsTrueX == true*/ }
    else {/* do smth if IsTrue == false and if IsTrueX == false */}

    bool Variable = (/*condition*/ 2 + 2 == 4) ? true : false; //ternary operator

    switch(Boolean /*variable equal to case*/)
    {
    case true: /*do smth*/;
    case false: /*do smth else*/;

    default: /*defauld instructions*/;
    }

//***LOOPS***//

    for (size_t i = 0; i < Integer; i++) 
    {
        /*do smth "Integer" times*/ 
        if (/*Some condition*/ true) break; //Break - stop loop if some condition is true
        else if (/*Some condition*/ true) continue; //Continue - start next loop itteration, skipping next code
        //Next code
    }

    for(auto Variable : Arr) {/*Variable == Arr[Item from 1st to last]*/ }

    while(Boolean){/*do smth while Boolean == true*/ }

    do {/*do smth once than check Boolean, if true - continue loop*/ } while (Boolean);

//***POINTERS***//

    int* Pointer = 0; //create pointer to memory cell with int variable inside (0 == nowhere)

    int* Pointer2 = &Integer; //& - get variable adress operator

    Integer = *Pointer; //dereference - get value inside Pointer pointing adress
	
	void Fun(int* ValPtr){*ValPtr = 0; return;} //set some value to 0
	...
	Fun(&Val); //function work with pointer
	
//***REFERENCES***//

	int Val = 0;
	int& ValRef = Val; //create reference wich can be used as variable itself
	
	void Fun(int& Val) {Val = 0; return;} //work with local val as it is external

//***ARRAYS***//

    int FixedArr[5] = {}; //create fixed 5 values array in stack memory
    //FixedArr is a pointer to first value in array
    //FixedArr[4] is equal to *(FixedArr + 4)
	
	int* ArrFun(int* NullArrElement(ArrName), int* LastArrElement + 1)
	{
		int* Ptr = NullArrElement + Smth;
		//great way to make some array function, also works with void arrays
		return Ptr;
	}
	
	bool FindElement(int* NullArrElement, int* LastArrElement, int* TargetElement)
	{
		if (NullArrElement == LastArrElement) return false;
		//function returns false if void array
		int* Ptr;
		TargetElement = Ptr; //get target element through pointer
		return true;
	}

    std::vector<int> Vector; //create vector - dynamic array with specific functions

    int* DynArr = new int[Integer]; //create dynamic array, allocated in heap

    int cols = 1, rows = 1; //cols and rows in 2d arrays

    int** DynArr2D = new int* [rows]; //create dynamic array, (memory fragmentation risc!) 
    for (size_t i = 0; i < rows; i++)
        DynArr2D[i] = new int[cols];

    int** DynArr2DEff = new int* [rows]; //create dynamic array. Efficient memory allocation
    DynArr2DEff[0] = new int[rows * cols];
    for (size_t i = 0; i < rows; i++)
        DynArr2DEff[i] = DynArr2DEff[i - 1] + cols;

}

//***FUNCTIONS OVERLOADING***//


void PrintValue(int const Value) { std::cout << "Value is int: " << Value; }
void PrintValue(char const Value) { std::cout << "Value is char: " << Value; }
void PrintValue(bool const Value) { std::cout << "Value is bool: " << Value ? "true" : "false"; }
//When function will be called, message will be printed depending on input parameter type

int ReturnHalf(int const Value) { return Value / 2; }
double ReturnHalf(double const Value) { return Value / 2; }
//Return type depends on input type

