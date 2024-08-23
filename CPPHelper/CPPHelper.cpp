// CPP HELPER BY RETEKUS //

//***BASIC DATA TYPES***//

char Character;

int Integer;

float Float; //floating poit, 7 symbols after dot
double Double; //float with 2x precision, 15 symbols after dot

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


//***MACROS***//

//Macros are special commands for preprocessor
//Preprocessor scans code before compiling and does macros commands
//Macros can be used as functions, but preprocessor works with them like with text

#include //include macro, used for adding parts of code. Usually its headers or libraris

//Some standart(stl) libs:
#include <iostream> //Input Output Stream (C++ style console i/o system)
#include <iomanip> //Input Output Manipulations (setw(val), ...)
#include <vector> //standart dynamic array library
#include <cstdlib> //classic C lib
#iclude <cstdint> //fixed size integers (int_64t, uint64_t, ...) u - unsigned
#include <string> //C++ string lib
#include <set> //SET(of data) library
#include <stddef> //definitions (like NULL)
#include <algorithm> //usefull stl algorithms (sort...)

#include "path/CPPHelper.h" //add ur own header(.h .hpp ...) files
//Also .cpp files can be included, but its is a bad style

//"" and <> just shows place for preprocessor where file could be found

#define PREPR_VALUE //preprocessor definition

#ifdef PREPR_VALUE #endif //if PREPR_VALUE defined do code till endif
#ifndef PREPR_VALUE #endif //if PREPR_VALUE undefined do code till endif

#undef PREPR_VALUE //preprocessor undefinition

#define MAX(a, b) a >= b ? a : b //example of macro function. 
//Pasted just like a text, so behavior can be unpredictable

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
	
//It is recomended to use commonly true conditions in brunches for better pefomance (brunch missprediction)

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

//Pointers are representing adress in memory. Every type have its own fixed size but pointers are usually
//have fixed size for every type
//On 64-bit OS usually pointer is 8 bytes

    int* Pointer = 0; //create pointer to memory cell with int variable inside (0 == nowhere(C style))
	
	void* InvalidPtr = nullptr; //special value for invalid pointer (C++ style)
	
    int* Pointer2 = &Integer; //& - get variable adress operator
	
	void* VoidPtr = 0x1000; //pointer of unknown type
	
	char* CharPtr = (char*) 0x1000; //link 0x1000 to char adress
	
	//Larger aress cells converts different, depends on hardwear architecture
	//For x86 - little endian (bytes are growing from end to begin). Important for crossplatform apps

    Integer = *Pointer; //dereference - get value inside Pointer pointing adress
	
	void Fun(int* ValPtr){*ValPtr = 0; return;} //set some value to 0
	...
	Fun(&Val); //function work with pointer
	
	ClassType* ClassPtr = &Class;
	ClassPtr->ClassField = Val; // -> operator equal to (*ClassPtr).ClassField...
	
	int* Ptr = Pointer + 2; //move pointer on 2 => 2 * 8 bytes = on 16 bytes (for 64-bit OS)
	
	ptrdiff_t Diff = Pointer - Pointer2; //special type wich 100% can contain 2 pointers difference
	
	const char* str = "Text"; //"Text" is char array by default, not string from <string> lib
	
//***REFERENCES***//

	int Val = 0;
	int& ValRef = Val; //create reference wich can be used as variable itself
	
	void Fun(int& Val) {Val = 0; return;} //work with local val as it is external
	
	void ArrFun(int (&Arr)[5]) {...} //now calling ArrFun with Arr[val != 5] throws error
	
	void Fun(heavyType const &Val) {...} //constant references are useful for large objects

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
	
//***DYNAMIC MEMORY***//

	//C - style dyn mem functions: malloc, calloc, realloc, free
	//C++ - style:
	int* PtrInt = new int(InitValue); //create int in dym mem
	delete PtrInt; //free mem from int
	
	int* Arr = new int[DynValue]; //create int arr in dyn mem
	delete[] Arr; //free mem from int arr
	
//***DYNAMIC ARRAYS***//

    int* DynArr = new int[Integer]; //create dynamic array, allocated in heap

    int cols = 1, rows = 1; //cols and rows in 2d arrays

    int** DynArr2D = new int* [rows]; //create dynamic array, (memory fragmentation risc!) 
    for (size_t i = 0; i < rows; i++)
        DynArr2D[i] = new int[cols];

    int** DynArr2DEff = new int* [rows]; //create dynamic array. Efficient memory allocation
    DynArr2DEff[0] = new int[rows * cols];
    for (size_t i = 1; i < rows; i++)
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