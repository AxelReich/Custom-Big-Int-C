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
    for(int i = 0; i < x.size; i++){
        os << x.arrInt[i];
    }
    os << endl;
    return os;
}
istream& operator >> (istream& is, const MyInt& x)      // Ignore leading spaces, until there is a num. 
{
    //TODO
    return is;
}


//Constructors 

MyInt::MyInt(int n)		    // If negative parameter, set to 0. Else, set value to the parameter // Because it is an INT then it would not accept any large value. 
{
    // If n is negative, set it to 0
    if (n < 0) {
        n = 0;
    }

    
    // Use temp to not compare the value 
    int temp = n;
    size = 0;
    if (temp == 0) { 
        size = 1;  // So the loop only runs once 
    }
    while (temp > 0) {
        size++;  
        temp /= 10;  // So it does not change the value of n we use the temp
    }

    // Allocate memory for the array to store the digits
    arrInt = new int[size];


    // Fill the array with digits in reverse order
    int index = 0;
    while (n > 0) {
        arrInt[index++] = n % 10;  // Store the last digit
        n /= 10;  // Remove the last digit from n
    }

    // Reverse the array 
    for (int i = 0; i < size / 2; i++) {
        // Swap elements at index i and size - 1 - i
        int temp = arrInt[i];
        arrInt[i] = arrInt[size - 1 - i];
        arrInt[size - 1 - i] = temp;
    }

    // Handle the case for n == 0, where the array needs to hold 0
    if (size == 1) {
        arrInt[0] = 0;
    }
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


// Are all the functions and the data are okay? Check this again.7