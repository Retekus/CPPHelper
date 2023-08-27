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

	explicit StructName(int InputValue) : Value(InputValue) //Constructo from 1 input parameter
	//Explicit modifier disallows users of class use non visible transformations, like StructName SN = 5;
	{
		Data = new int[Value];
		for (size_t i = 0; i < Value; i++)
			Data[i] = 0;
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

class BasicClass //Class - structure with fields and methods, but with another standart access rules
{
public: //Access modifier, which allows any outside code use things under it

protected: //Access modifier, which allows use things under it only for child classes

private: //Access modifier, which allows use things under it only for this class
	//Best place for class fields, in terms of incapsulation (Keeping class invariantable)
	int Value;
	int* Data;
};