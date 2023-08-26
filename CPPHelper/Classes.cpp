#include <iostream>
#include "CPPHelper.h"

using namespace std; //use namespace std to exclude std:: syntax

struct StructName //definition of structure
{

	//***CONSTRUCTOR***//
	StructName(int InputValue, int* InputData) : Value(InputValue) //Value = InputValue
	{
	}

	//***METHODS***//
	//methods - functions inside structs

	int GetValue() { return Value; }

	privat:

	int Value;
	int* Data;
};