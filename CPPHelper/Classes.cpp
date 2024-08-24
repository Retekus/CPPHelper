// CPP HELPER BY RETEKUS //

#include <iostream>
#include "path\CPPHelper.h"

using namespace std; //Use namespace std to exclude std:: syntax

//***CLASSES***//

//Struct - structure with it's own values and methods - member functions
//Class - structure with specific access preferences (everything private)
//Object - instance of a class/struct
 
 //Commonly classes are declared in header(.h .hpp ...) files
 //and defined in .cpp files
 //This separation allows to recompile .cpp files without recompiling the whole project
 //But if declaration inside header needs to be changed, all files with this header
 //included must be recompiled
 
//***STRUCT***//

struct StructName 
{
	//***FIELDS***//
	//Field is just a name for structs variable

	int _Value; //Usually looks like this: _FieldName
	int* _Data;
	
	//***METHODS***//
	//Methods - functions inside structs

	int GetValue() { return _Value; }
	
	int GetValueX2(); //Method declaration (example of outside realisation)

	void SetValue(const int& InputValue) { this->_Value = InputValue; }
	
	//***CONSTRUCTOR***//
	//Constructor - method called when struct instance being created to intialize object
	//Constructor must have same name as struct/class
	
	StructName(){_Value = 0; _Data = nullptr;} //Default constructor
	//If 1 or more constructors are declared the default is disabled so redeclare it if needed

	StructName(int InputValue, int* InputData) : _Value(InputValue) //Initialisation list
	//Equals to Value = InputValue
	//ATTENTION there fields are initialasing in the same order as they declared (_Value than _Data than ...)
	{
		//Additional things and side effects
		_Data = new int[_Value]; //Allocate _Data in heap
		for (size_t i = 0; i < _Value; i++) 
			_Data[i] = InputData[i];
	}

	explicit StructName(int InputValue = 0) : _Value(InputValue) //Constructor from 1 input parameter
	// = 0 sets InputValue default valute to 0
	//Explicit modifier disallows users of class use non visible transformations, like (StructName StructInstance = 5;)
	{
		_Data = new int[_Value];
		for (size_t i = 0; i < _Value; i++)
			_Data[i] = 0;
	}
	//Since C++11 it is recomended to make all constructors "explicit"
	
	explicit StructName(int InputValue = 0, int* InputData = nullptr) : _Value(InputValue), _Data(InputData) {}
	//Multi functional constructor, can take 0, 1 or 2 parameters and work as default
	
	//***COPY CONSTRUCTOR***//

	StructName(StructName const& Instance) //Constructor with struct/class parameter
	{
		_Data = new int[_Value]; //Create a new array and fill it instea of having 2 objects with pointers to the same array
		for (size_t i = 0; i < _Value; i++)
			_Data[i] = Instance._Data[i];
	}

	//***ASSIGN CONSTRUCTOR***//

	//Key word "this" is a pointer to exact instance

	StructName& operator=(StructName const& Instance) //More about "operator" in operator overloading section
	{
		if (this != &Instance)
		{
			delete[] _Data; //Delete actual data if Instance is not the same object
			//Create new array, fill it... to prevent memory leaking
		}  
		return *this;
	}

	//***DESTRUCTOR***//
	//Destructor - function called when struct instance deleted

	~StructName()
	{
		delete[] _Data;
	}
	
}; //ATTENTION struct/class must have semicolon after figure brackets

int StructName::GetValueX2() { return this->_Value * 2} //Method defenition (example of outside realisation)

//ATTENTION object definition can be converted into function declaration by compiler:
StructName Struct1; //Variable definition
StructName Struct2(); //Function declaration
//Same possible with type changers

//Instances destructors works backward
{	StructName Struct1;
	StructName Struct2;
} //Struct2 deleted than Struct1

//***CLASS***//

class BasicClass //Class - structure with fields and methods, but with another standart access rules
{
public: //Access modifier, which allows any outside code use things under it

	BasicClass(int const& Value)
	{
		_Value = Value;
		_Data = new int[_Value];
		for (size_t i = 0; i < _Value; i++)
			_Data[i] = 0;
	}

	int GetValue() const { return _Value; }

protected: //Access modifier, which allows use things under it only for child classes
	int _Value;
	int* _Data;

private: //Access modifier, which allows use things under it only for this class
	//Best place for class fields, in terms of incapsulation (Keeping class invariantable)

	int ErrorCode = 404;
};

//***INHARITANCE***//

class BasicClassWithMoreFunctional : public BasicClass //New class inharited from BasicClass
//New class have same fields with same private modifier
//Public inharitance is common used and matches standart OOP inharitance rules
//Multiple inharitance not recomended, high risc of undifined behavior
{
private:

	//***AGGREGATING***//
//Using class as field of another class
//Sometimes inharitance used when aggregating must be used

	StructName NewField_; 
};

//***OVERLOADING***///

class NonBasicClassA : public BasicClassWithMoreFunctional
{
public:

	void CheckInputType(int InputValue) { std::cout << "Value is int: " << InputValue; };
	void CheckInputType(double InputValue) { std::cout << "Value is double: " << InputValue; };
	void CheckInputType(char InputValue) { std::cout << "Value is char: " << InputValue; };
	//Now method is overloaded
	//When method called, it will work different depending on input value type

};

//***OPERATOR OVERLOADING***///

class NonBasicClassB : public BasicClassWithMoreFunctional
{
	NonBasicClassB operator+(int const& Num)
	{
		_Value += Num;
		return *this;
	}
public:
};

//***OVERRIDING***///

class Animal
{
public:

	void PrintFoodPriority() const { cout << "Unknown"; } //Just method for override

	virtual void PrintName() const { cout << "Unknown"; } //Virtual method. Const means that fields stay constant
	//Virtual means that if we call class child object using parent type declaration(pointer/link), method still be used from child class 

	virtual int GetAnimalAge() const = 0; //Pure virtual method (abstract), makes class abstract also
	//Instance of abstract class cannot be created straight forward, cause pure method cannot be called

	virtual ~Animal(){} //Virtual distructor. MUST be in any class with virtual methods, otherwise memory leak garantied

protected:
	int Age_;
	int FoodPriority_;
};

class Dog : Animal
{
public:

	void PrintFoodPriority() const { cout << "Meat"; } //If we use "Animal" declaration(pointer/link) we will see "Unknown"

	void PrintName() const { cout << "Dog"; } //If we use "Animal" declaration(pointer/link) we will see "Dog"

	int GetAnimalAge() const 
	{
		return Age_; 
	}

	~Dog() { delete HairColor_; } //Dog destructor will be called first, than animal destructor

private:
	char* HairColor_; //Additional field
};

//noexcept //
//forward declaration//
