#include "myint.h"
#include <iostream>

using namespace std;

//What should I do with these two functions? Call them for the Conversor constructor????

int C2I(char c)
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	return -1;	// error
   return (c - '0');				    // success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
   if (x < 0 || x > 9)		return '\0';	// error
   return (static_cast<char>(x) + '0'); 	// success
}


// Add in operator overload and member function definitions 


// these overload starters are declared as friend functions

MyInt operator+ (const MyInt& x, const MyInt& y)
{
    //TODO 
    return x;
}
MyInt operator* (const MyInt& x, const MyInt& y)
{
    //TODO 
    return x;
}
//Optional
MyInt operator- (const MyInt& x, const MyInt& y) // If result negative, do not return anything  
{
    //TODO 
    return x;
}
//Optional 
MyInt operator% (const MyInt& x, const MyInt& y)
{
    //TODO 
    return x;
}
//Optional 
MyInt operator/ (const MyInt& x, const MyInt& y)
{
    //TODO 
    return x;
}

// Operator overloads for comparison 
bool operator<  (const MyInt& x, const MyInt& y)
{
    //TODO:
    return false;

}
bool operator>  (const MyInt& x, const MyInt& y)
{
    //TODO:
    return false;

}
bool operator<= (const MyInt& x, const MyInt& y)
{
    //TODO:
    return false;
}
bool operator>= (const MyInt& x, const MyInt& y)
{
    //TODO:
    return false;
}
bool operator== (const MyInt& x, const MyInt& y)
{
    //TODO
    return false;
}
bool operator!= (const MyInt& x, const MyInt& y)
{
    //TODO
    return false;
}

// declare overloads for input and output 
ostream& operator << (ostream& os, const MyInt& x)      // Print the number in regular formatting 
{
    //TODO
    return os;
}
istream& operator >> (istream& is, const MyInt& x)      // Ignore leading spaces, until there is a num. 
{
    //TODO
    return is;
}


//Constructors 

MyInt::MyInt(int n)		    // If negative parameter, set to 0. Else, set value to the parameter 
{

}
MyInt::MyInt(const char* i)       // C-string that is a combination of chars with a '\n' at the end. If Empty, or have chars, or does not have any nums. Int = 0                                                                           
{

}
MyInt::~MyInt()                   // When myInt is deallocated, should deallocate any data 
{

}

// Copy constructor and assignment operator for deep copy
MyInt::MyInt(const MyInt& i)
{

}
MyInt& MyInt::operator=(const MyInt& i)
{

}

// getters
int MyInt::GetSize()  const
{

}
int MyInt::GetArray() const
{

}

// setters 
int MyInt::SetSize()
{

}
//I Thint that SetArray is not necessary ????
int MyInt::SetArray()
{

}
int MyInt::Grow()
{

}


// Other operator overloads  ++int; int++
// Pre, returns the value incremented 
MyInt MyInt::operator++()
{

}
// Post, returns a copy before incrementing the value
MyInt MyInt::operator++(int x)
{

}


// Are all the functions and the data are okay? Check this again.