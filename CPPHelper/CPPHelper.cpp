﻿// CPP HELPER BY RETEKUS //

//***BASIC DATA TYPES***//

	char Character;

	int Integer = 10; //Values in C++ can be rvalue or lvalue. Lvalues have place in memory
	//Integer is lvalue, 10 is rvalue

	float Float; //floating poit, 7 symbols after dot
	double Double; //float with 2x precision, 15 symbols after dot

	bool Boolean;

	size_t Size; //Usefull data type, have size of machine word, depending on system architecture

//***OPERATORS***//

	//Arifmetical: +  -  ++(inc)  --(dec)  *  /  %  +=  -=  *=  /=  %=

	//Bite: ~(not)  &(and)  |(or)  ^(xor)  &=  |=  ^=  <<(slide left)  >>(slide right)

	//Logic: !(not)  &&(and)  ||(or)  ==(equal)  <  >  <=  >=

	//Special: =(assert)  *(dereferencing)  &(get pointer)  ->((*Obj).Method)  ->*()  ,  .  ::

	//Special: [] () (type) new new[] delete delete[]

	//Type changer: (newType)Var  newType(Var)  

//***TYPE MODIFIERS***//

	int const PI = 3.14; //Make Pi non changable

	short ShInt; //short int
	long LongInt; //long == long int(more data)
	unsigned InsignedInt; //unsigned == unsigned int (only positive values)

	auto Val = 3; //type changes automatically

	//Short/long variables size depends on OS

//***MACROS***//

	//Macros are special commands for preprocessor
	//Preprocessor scans code before compiling and does macros commands
	//Macros can be used as functions
	//Preprocessor works with them like with text

	#include //include macro, used for adding parts of code. Usually its headers or libs

	//Some standart(stl) libs:
	#include <iostream> //Input Output Stream (C++ style console i/o system)
	#include <iomanip> //Input Output Manipulations (setw(val), ...)
	#include <vector> //standart dynamic array library
	#include <cstdlib> //classic C lib
	#include <cstdint> //fixed size integers (int_64t, uint64_t, ...) u - unsigned
	#include <string> //C++ string lib
	#include <set> //SET(of data) library
	#include <stddef> //definitions (like NULL)
	#include <algorithm> //usefull stl algorithms (sort...)
	#include <cmath> //mathematical functions (cos(), floor(), ...)
	#include <functional> //
	#include <regex> //Regular expressions

	#include "path/CPPHelper.h" //add ur own header(.h .hpp ...) files
	//Also .cpp files can be included, but its not recomended

	//"" and <> just shows place for preprocessor where file could be found

	#define PREPR_VALUE //preprocessor definition

	#ifdef PREPR_VALUE #endif //if PREPR_VALUE defined do code till endif
	#ifndef PREPR_VALUE #endif //if PREPR_VALUE undefined do code till endif

	#undef PREPR_VALUE //preprocessor undefinition

	#define MAX(a, b) a >= b ? a : b //example of macro function. 
	//Pasted just like a text, so behavior can be unpredictable

	#pragma someCommand //Compiler commands. Avaible comands depends on compiler 

//***SCOPE/LIFE TIME***//
	//Everything in C++ have its own scope and life time
	//Scope - visibility for other members
	//Life time - a period of time when something have its place in memory
	{ //Figure braces are the common way to limit somethings scope and life time
		int a;
		{
			int b = a; //"a" is avaible inside lover scope level
		} //Everything inside life time end, "b" is deleted from memory
		b = a; //Error, b is undeclared
	}

//***NAMESPACE***//
	//Namespace is a list of some functions, methods, variables...

	const float gEarth = 10;
	
	namespace preciseValue {
	const float gEarth = 9.81; 
	const float copperRes = 0.017; }
	
	namespace uselessFunc {
		void Nothing(){return;}}
		
	namespace insertedA {
		namespace insertedB {InVal = 0;}}

	gEarth == 10;
	preciseValue::gEarth == 9.81;

	{
		using namespace namespaceName; //key word using to use namespace everywhere in visible area
		using namespace uselessFunc::Nothing; //only 1 function inserted from namespace
		using namespace insertedA::insertedB; //multiple namespaces
		gEarth == ???; //Undefined behavior
		copperResistance == 0.017;
	}
	copperRes == undefined;

//***FUNCTIONS***//
	//Function - piece of code which does something and can be called anywhere, multiple times
	// /*Function return type*/ /*Function name*/ (/*Function parameters*/) {/*Function logic*/;}

	void Foo(); //Function declaration.
	//Void functions return nothing
	void Foo() { /*realisation*/ return; } //Function definition

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
		
	//It is recomended to use commonly true conditions in brunches for better pefomance (brunch prediction)

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
	
	char* CharPtr = (char*) 0x1000; //link mem cell "0x1000" to CharPtr known as char adress
	
	//For large sized data pointers can work different on different machines.
	//A CPU may read a digital word big end first or little end first.
	//A big-endian system stores the most significant byte of a word at the smallest memory address and 
	//the least significant byte at the largest. 
	//A little-endian system, in contrast, stores the least-significant byte at the smallest address.
	//0A0B on (Lil-end: 0x0001: 0B 0x0002: 0A) VS (Big-end: 0x0001: 0A 0x0002: 0B)

    Integer = *Pointer; //dereference - get value inside Pointer pointing adress
	
	void Fun(int* ValPtr){*ValPtr = 0; return;} //set some value to 0
	...
	Fun(&Val); //function work with pointer
	
	ClassType* ClassPtr = &Class;
	ClassPtr->ClassField = Val; // -> operator equal to (*ClassPtr).ClassField...
	
	int* Ptr = Pointer + 2; //move pointer on 2 => 2 * 8 bytes = on 16 bytes (for 64-bit OS)
	
	ptrdiff_t Diff = Pointer - Pointer2; //special type wich 100% can contain 2 pointers difference
	
	const char* str = "Text"; //"Text" is char array by default, not string from <string> lib
	
//***SMART POINTER***//

	
	
//***FUNCTION POINTER***//
	//Function poiter is a powerfull ability, used in patterns like: callback, conveyor
	
	void Func(int x) {return;}

	typedef void (*FuncPtr)(int); //define FuncPtr as type wich is pointer to void function with int parameter
	FuncPtr ptr = Func; //adress of a function
	ptr(Val); //used as standart function call
	
	using FooPtr = void(*)(int); //C++11 typedef althernative
	
//***LAMBDA FUNCTION***//
	//Lambda function is function with short declaration, wich can use outside variables
	//Syntax: [take list](parameters){body}
	//[] - without outside take
	//[=] - take all value(copy)
	//[&] - take all reference
	//[x, y] - take x y value(copy)
	//[x, &y] - take x value and y ref
	//[x, &y], [=, &y], ...

	auto LFunc = [](int Val){ return Val;};
	
	auto Func = [x](){ x = 10; } //ERROR x copied but not changable
	//without mutable key word compiler will throw error
	auto Func = [x]() mutable { x = 10; }
	
//***REFERENCES***//


	int Val = 0;
	int& ValRef = Val; //create reference wich can be used as variable itself
	//Defaul reference can work with only lvalues (lvalue reference)
	
	const int& CValRef = 0; //But const ref can also work with rvalues
	//Const ref continues rvalue life time till end of scope
	
	int&& ValRefR = 10; //Rvalue reference works with rvalues
	//Rvalue references are used in move semantics
	
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
	
	//Placement new
	void* ptr = NewAlloc(sizeof(Val)); //Self made allocation system, might be useful in some cases
	Val* Arr = new(ptr) Val[10]; //"new" operator places memory directly where needed
	Arr->~Val(); //force call destructor
	NewFree(ptr); //self made mem free
	//Memory leveling can cause problems and bring undifined behaviour
	
	//ALIGNING
	//Aligning is compiler function for better and faster data proccessing
	//Aligning works different on different platforms and OSs
	#pragma pack(push, 1) //Change data packing aligning to 1 (without alight)
	//...code
	#pragma pack(pop) //Back to default alining
	
	alignof(char) == 1; //Get needed space for char
	sizeof(Pointer) == ...; //Get size of taken room in memory. It can be variables, arrays, objects and so on
	offsetof(ptr1, ptr2) == ...; //Get offset between 2 pointers
	alignas(RequiredVolume) char arr[Val]; //Custom alignment. RequiredVolume must be larger than needed
	
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

	} //end main

//***FUNCTIONS OVERLOADING***//

	void PrintValue(int const Value) { std::cout << "Value is int: " << Value; }
	void PrintValue(char const Value) { std::cout << "Value is char: " << Value; }
	void PrintValue(bool const Value) { std::cout << "Value is bool: " << Value ? "true" : "false"; }
	//When function will be called, message will be printed depending on input parameter type

	int ReturnHalf(int const Value) { return Value / 2; }
	double ReturnHalf(double const Value) { return Value / 2; }
	//Return type depends on input type

//***CONSTANT***//
	//Key word "const" works with value on the left

	int const * ptr = &Val; //pointer to const value
	*ptr = 0; //Error

	int * const ptr = &Val; //constant pointer to changable value
	ptr = nullptr; //Error

	int const * const ptr = &Val; //constant pointer to constant value

	//Constant references
	int& const Ref = Val; //Error. References are already constant
	int const & Ref = Val; //Reference to constant value

	void Func(int const & Val){return;} //Ref to const helps avoid copying

	StructName const * Struct = StructName(); //Define object
	Struct->NonConstMethod(); //Error. Non constant methods are unavaible for constant objects

//***CAST***//
	//Cast is change of types

	newType NewTypeVar = static_cast<newType>(OldTypeVar); //Compiler checks for cast ability

	void Func(const int* ptr)
	{
		*const_cast<int*>(ptr) = 0; //Const cast allows to disable constant and change value
	}

	newType* NewTypeVar = dynamic_cast<newType*>(OldTypeVar); //Same as static, but check happens during runtime (RTTI must be on)
	//If something wrong returns nullptr

	newType* NewTypeVar = reinterpret_cast<newType*>(OldTypeVar); //Cast without any checks (NOT RECOMENDED)

	//C-cast
	int val = (int)DoubleVal; //C style cast, in C++ works like static cast or reinterpret if static impossible (NOT RECOMENDED)
	
//***MOVE SEMANTICS***//
	//Move semantic is a mechanism wich allows to use expressions multiple times without copying by moving it
	//Moving means data moves inside proccessor's registers without calling pointers, finding data, clearing cach... 
	//Since C++ expressions can be rvalue, lvalue, glvalue, xvalue and prvalue
	//Glvalue - generalized lvalue
	//Prvalue - pure rvalue
	//Xvalue - expiring value
	//Rvalue can be xvalue or prvalue
	
	//XVALUE//
	//expiring value - close to its end
	int&& foo(){return 3;}
	foo(); //xvalue
	
	static_cast<int&&>(5); //xvalue
	std::move(5); //same as static cast - xvalue
	
	//PRVALUE//
	//Everything thats not lvalue or xvalue
	int foo(){return 3;}
	foo(); //prvalue
	
	//Scott Myers rule:
	//If u can take adress - it is lvalue
	//If it is ref to lvalue - it is also lvalue
	//Everything else is rvalue
	
	//Perfect forvarding
	bar(T& t);
	bar(T&& t);
	
	void foo(T& x)
	{
		bar(x); //can cause compile problems if x - rvalue
	}
	void foo(T&& x)
	{
		bar(std::move(x)); //function redefinition, can be time consuming if more complicated realisation
	}
	
	void foo(T&& x)
	{
		bar(std::forward<T>(x)); //std::forward keeps reference type - if x rvalue it will give bar() rvalue, if lvalue then lvalue
	}
	
//***FUNCTION TEMPLATES***//	
	//Function templates allow us to make functions with different signature
	
	template <class T> //"class" is just a key word, also "typename" can be used, result the same
	void PrintLN(const T& val)
	{
		std::cout << val;
	}
	PrintLN<int>(5);
	PrintLN(5); //compiler can automaticly pick needed template
	
	template <int Val> //also types can be clearly defined
	void PrintLN()
	{
		std::cout << val;
	}
	int Num = 3; //3 is a value of runtime, template must have compile time values
	PrintLN<Num>(); //Error, compiler must know value before compiling
	
	const int Num = 3;
	PrintLN<Num>(); //Ok
	PrintLN<3>(); //Ok
	
	int Func(int v) {return v;}
	const int Num = Func(3);
	PrintLN<Num>(); //Error
	
	constexpr int bar() {return 0;} //"constexpr" keyword allows compiler to calculate return value during compiling
	
	const int Num = bar(3);
	PrintLN<Num>(); //Can also cause error if function cant be proccessed during compile time
	
	template <int* Val> //Error, templates cant work with pointers
	
	template <class Val, class Counter = int> //Template can have default type parameter
	void foo(){Counter Val = Value;}
	foo<char>(); //Counter is int by default
	foo<char, size_t>(); //Counter now is size_t

//***RVO/NRVO***//
	