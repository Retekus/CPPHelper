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
	//Field is a structure variable

	int _Value; //Usually looks like this: _FieldName or FieldName_
	int* _Data;
	mutable int _MutableVal;
	int _Val = 10; //Since C++11 its possible to init field right after declaration
	
//***METHOD***//
	//Method - function inside struct (member function)
	//The main difference is that method gets pointer to an instance of an object
	//Key word "this" is a pointer to exact instance of a class
	//Also methods can have default parameters, so some parameters can be sckiped during method call

	int GetValue() { return _Value; }
	
	int GetValueX2(); //Method declaration (example of outside realisation)
	
	bool ConstMeth() const {_MutableVal = 0; return _MutableVal == 0;} //If method const, compiler will check that fields are stable
	//Mutable key word makes fields changable inside constant methods

	void SetValue(const int& InputValue = 0) { this->_Value = InputValue; } //InputValue have default 0 value
	
//***CONSTRUCTOR***//
	//Constructor - method called when struct instance being created to intialize object
	//Constructor must have same name as struct/class
	
	StructName(){_Value = 0; _Data = nullptr;} //Default constructor
	//If 1 or more constructors are declared the default is disabled so redeclare it if needed

	StructName(int InputValue, int* InputData) : _Value(InputValue) //Initialisation list
	//Equals to _Value = InputValue
	//Init list highly recomended when fields are also structs (agregating)
	//Init list calls field constructor with parameters avoid creating it with default constructor
	//and calling its constructor with parameters then again
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
	} //Usually compiler trying to avoid using copy constructor (copy elision)
	//New object just creates on call place

//***ASSIGN CONSTRUCTOR***//

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

	//ATTENTION object definition can be understood as function declaration by compiler:
	StructName Struct1; //Variable definition
	StructName Struct2(); //Function declaration
	//Same possible with type changers looks like variables

	//Instances destructor works backward
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
	
	friend void FriendFunction(BasicClass& classInstance); //Friend function declaration
	//Friend finction have access to private and protected fields of a class
	//But are not in scope of a class and not invoked furing construction

	protected: //Access modifier, which allows use things under it only for child classes
	int _Value;
	int* _Data;

	private: //Access modifier, which allows use things under it only for this class
	//Best place for class fields, in terms of incapsulation (Keeping class invariant)

	int _ErrorCode = 404;
	};

	void FriendFunction(BasicClass& classInstance) {classInstance._ErrorCode = 0;} //Friend function definition looks like default function
	//Friend function still can be overloaded and used with other types and dont care about class life time 

//***FORWARD DECLARATION***//
	//Forward declaration is a way to avoid cycled reinclude of 2 or more classes in different files
	class ForwardDeclared;
	class UseFwD
	{
		ForwardDeclared fwd;
	};
	
	//>>>./ForwardDeclared.cpp
	class UseFwD;
	class ForwardDeclared
	{
		UseFwD user;
	};
	//>>../

//***INHARITANCE***//

	class BC1 : protected BasicClass {}; //Protected inheritance makes public fields - protected
	class BC2 : private BasicClass {}; //Private inheritance makes public and protected fields - private
	
	class FinalClass final {}; //Key word "final" makes class non inharitable
	
	BC1 bc1;
	BasicClass& bref = bc1; //Refs can be converted from child to base class
	BasicClass* bref = &bc1; //Same with pointers. But it doesnt work backwards
	
	BasicClass b;
	b = bc1; //Base class instance can be defined by child class, but it will only get fields declared in base class (cutoff)
	
	class BasicClassWithMoreFunctional : public BasicClass, private StructName //New class inharited from BasicClass and StructName
	//New class have same fields with same private modifier
	//Public inharitance is common used and matches standart OOP inharitance rules
	//Multiple inharitance not recomended, high risc of undifined behavior, but sometimes its usefull to add some functionality
	{
	private:

//***AGGREGATING***//
	//Using class as field of another class
	//Sometimes inharitance used when aggregating is enough

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
	
//***CLASS INCLUDE CLASS***//
	//C++ allows to add classes into classes
	class Server
	{
		class HostConfigurator
		{
			void ipConfig() {std::cout << _adress;} //Inserted class have access to outer class private fields
		};
		private:
		int _adress;
	};
	Server::HostConfigurator IPconf();
	IPconf.ipConfig();

//***OPERATOR OVERLOADING***///

	class NonBasicClassB : public BasicClassWithMoreFunctional
	{
	NonBasicClassB operator+(int const& Num)
	{
		_Value += Num;
		return *this;
	}
	
	friend NonBasicClassB operator+(const StructName snVar, const NonBasicClassB nbcB);

	bool operator==(NonBasicClassB const& other) const //ref used to avoid copying
	{
		if (other._Value == this->_Value) return true;
		return false;
	}
	
	NonBasicClassB& operator++() {}; //Prefix increment - ++val
	NonBasicClassB& operator++(int) {}; //Postfix increment - val++	
	
	const NonBasicClassB& operator[](size_t i) const {return _Data[i];} //Read only
	NonBasicClassB& operator[](size_t i) {return _Data[i];} //Read/write
	public:
	};

	NonBasicClassB operator+(const StructName snVar, const NonBasicClassB nbcB)
	{ //Outside realisation with friend modyfier
		this->_Value += snVar._Value;
		return *this;
	}
	
	class Less
	{	bool operator()(const int left, const int right) { //Functor - operator overload wich allows to work with class like with function
			return left < right;
	}};
	Less less;
	if (less(3,4)) std::cout << "less";

	//Sometimes it is neccessary to disallow copying of some specific objects, like large data bases
	struct UniqStructure
	{
		UniqStructure(UniqStructure const& a) = delete; //Since C++11 it is possible to do it by "delete" keyword
		private:
		UniqStructure& operator=(UniqStructure const& a); //Private constructors and operators are unavaible
	}
	
		struct NonUniqStructure
	{
		NonUniqStructure(NonUniqStructure const& a) = default; //Since C++11 it is possible to say compiler force make default copy constructor
		NonUniqStructure& operator=(NonUniqStructure const& a) = default;
	}

//***OVERRIDING***///
	//By default compiler use static linkage so it must know what and where te use
	//Virtual methods are stored in special table and can be choosen during runtime
	//This table also needs some room in memory

	class Animal
	{
	public:

	void PrintFoodPriority() const { cout << "Unknown"; } //Example of method for override

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

	void PrintName() const override { cout << "Dog"; } //If we use "Animal" declaration(pointer/link) we will see "Dog"
	//"override" isnt neccessary, but recomended because compiler will check names matching

	int GetAnimalAge() const 
	{
		return Age_; 
	}

	~Dog() { delete HairColor_; } //Dog destructor will be called first, than animal destructor

	private:
	char* HairColor_; //Additional field
	};

	class Terriere : Dog
	{
		void PrintName() const override { cout << "Terriere"; }
	};

	Dog dog; dog.PrintName(); //"Dog"
	
	Terriere terriere; terriere.PrintName(); //"Terriere"
	
	Dog* someOne = new Terriere();
	someOne->PrintName(); //Still "Terriere" with parrent pointer
	
	const Dog& someOneNew = Terriere();
	someOneNew->PrintName(); //Still "Terriere" with parrent reference
	
//***ADL***///
	//Argument dependent name lookup
	//Pattern wich says compiler to use functions/operators from the same namespase where object is defined
	//but only if there is no this functions/operators in current namespace
	namespace NS
	{
		struct A { ... };
		std::ostream& operator<<(std::ostream& out, const &A val) { /*new behaviour*/ }
		void FuncA(const A& val) {...}
	}
	
	NS::A a;
	
	std::cout << a; //new behaviour
	FuncA(a); //Automaticly used function from NS
	
//***MOVE SEMANTICS***//
	//Move semantics in classes
	class Buffer
	{
	private:
		size_t _size;
		int* _data;
	public:
		~Buffer() {delete _data;}
		Buffer(Buffer&& moved);
		Buffer& operator=(Buffer&& moved);

	};
	
	//Move constructor
	Buffer::Buffer(Buffer&& moved) : _data(moved._data), _size(moved._size)
	{
		moved._data = nullptr;
		moved._size = 0;
	}
	Buffer b1;
	Buffer b2 = std::move(b1); //b1 already moved but still alive, so it's data should be nulled
	//otherwise b2 data can be deleted while b1 destructor will be called
	
	Buffer::Buffer& operator=(Buffer&& moved)
	{
		if (this = &moved) return *this; //check of moving itself
		delete[] _data; //delete old data
		...
		return *this;
	}
	Buffer b1;
	Buffer b2; 
	b2 = std::move(b1);
	
//***CLASS TEMPLATES***//
	//Class templates allow create classes wich can have different field types
	
	template<class T> //T is a parameter wich will be pushed into class
	class Matrix
	{
		T* _data;
	};
	Matrix<double> matrix;
	Matrix<int> matrix;
	
	template<> //Specialized template: if T is bool then this exact realisation will be used
	class Matrix<bool> 
	{
		void* _data;
		...
	}
	
	template<class T, size_t size>
	class Array
	{
		T* _data[size];
	};
	Array<int, 5> arr;