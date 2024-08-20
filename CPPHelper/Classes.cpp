// CPP HELPER BY RETEKUS //

#include <iostream>
#include "E:\Saves\Visual studio\Helper\CPPHelper\CPPHelper\CPPHelper.h"

using namespace std; //Use namespace std to exclude std:: syntax

//***CLASSES***//

//Struct - structure with it's own values and methods to work with this values
//Class - structure with fields and methods
//Object - instance of a class
 
//***STRUCT***//

struct StructName 
{


	//***CONSTRUCTOR***//
	//Constructor - function called when struct instance created

	StructName(int InputValue, int* InputData) : Value_(InputValue) //Equals to Value = InputValue
	{
		//Additional functional and side effects
		Data_ = new int[Value_]; //Dynamically allocate Data
		for (size_t i = 0; i < Value_; i++) 
			Data_[i] = InputData[i];
	}

	explicit StructName(int InputValue) : Value_(InputValue) //Constructor from 1 input parameter
	//Explicit modifier disallows users of class use non visible transformations, like StructName SN = 5;
	{
		Data_ = new int[Value_];
		for (size_t i = 0; i < Value_; i++)
			Data_[i] = 0;
	}

	//***COPY CONSTRUCTOR***//

	StructName(StructName const& Instance) //Constructor with struct/class parameter
	{
		Data_ = new int[Value_]; //Create a new array and fill it instea of having 2 objects with pointers to the same array
		for (size_t i = 0; i < Value_; i++)
			Data_[i] = Instance.Data_[i];
	}

	//***ASSIGN CONSTRUCTOR***//

	//"this" means instance of this object

	StructName& operator=(StructName const& Instance) //More about "operator" in operator overloading section
	{
		if (this != &Instance)
		{
			delete[] Data_; //Delete actual data if Instance is not the same object
			//Create new array, fill it... to prevent memory leaking
		}  
		return *this;
	}

	//***DESTRUCTOR***//
	//Destructor - function called when struct instance deleted

	~StructName()
	{
		delete[] Data_;
	}

	//***METHODS***//
	//Methods - functions inside structs

	int GetValue() { return Value_; }

	void SetValue(const int& InputValue) { this->Value_ = InputValue; }

	//***FIELDS (STRUCT VARIABLES)***//

	int Value_; //Usually looks like this: FieldName_
	int* Data_;
};

//This structure is a class

//***CLASS***//

class BasicClass //Class - structure with fields and methods, but with another standart access rules
{
public: //Access modifier, which allows any outside code use things under it

	BasicClass(int const& Value)
	{
		Value_ = Value;
		Data_ = new int[Value_];
		for (size_t i = 0; i < Value_; i++)
			Data_[i] = 0;
	}

	int GetValue() const { return Value_; }

protected: //Access modifier, which allows use things under it only for child classes
	int Value_;
	int* Data_;

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
		Value_ += Num;
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

noexcept //
