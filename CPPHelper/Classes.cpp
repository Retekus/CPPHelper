#include <iostream>
#include "CPPHelper.h"

using namespace std; //Use namespace std to exclude std:: syntax

//***STRUCT***//
//Struct - structure with own values and methods to work with this values

struct StructName //Definition of structure
{

	//***CONSTRUCTOR***//
	//Constructor - function called when struct instance created

	StructName(int InputValue, int* InputData) : Value(InputValue) //Equals to Value = InputValue
	{
		//Additional functional and side effects
		Data = new int[Value]; //Dynamically allocate Data
		for (size_t i = 0; i < Value; i++) 
			Data[i] = InputData[i];
	}

	//***DESTRUCTOR***//
	//Destructor - function called when struct instance deleted

	~StructName()
	{
		delete[] data;
	}

	//***METHODS***//
	//Methods - functions inside structs

	int GetValue() { return Value; }

	void SetValue(const int& InputValue) { this->Value = InputValue; }

	//***FIELDS (STRUCT VARIABLES)***//

	int Value;
	int* Data;
};

//This structure is a class

//***CLASS***//

class BasicClass //Class - structure with fields and methods
{

};