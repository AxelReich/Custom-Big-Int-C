#include <iostream>

class MyInt
{
   // these overload starters are declared as friend functions

    friend MyInt operator+ (const MyInt& x, const MyInt& y);
    friend MyInt operator* (const MyInt& x, const MyInt& y);
    //Optional
    friend MyInt operator- (const MyInt& x, const MyInt& y); // If result negative does not 
    //Optional 
    friend MyInt operator% (const MyInt& x, const MyInt& y);
    //Optional 
    friend MyInt operator/ (const MyInt& x, const MyInt& y);

    // Operator overloads for comparison 
    friend bool operator<  (const MyInt& x, const MyInt& y);
    friend bool operator>  (const MyInt& x, const MyInt& y);
    friend bool operator<= (const MyInt& x, const MyInt& y);
    friend bool operator>= (const MyInt& x, const MyInt& y);
    friend bool operator== (const MyInt& x, const MyInt& y);
    friend bool operator!= (const MyInt& x, const MyInt& y);

    // declare overloads for input and output 
    friend ostream& operator << (ostream& os, const MyInt& x);
    friend istream& operator >> (istream& is, const MyInt& x);


public:
   MyInt(int n = 0);		// first constructor

    //TODO: Add the other conversor constructors 
    // be sure to add in the second constructor, and the user-defined 
    //  versions of destructor, copy constructor, and assignment operator



private:

   // Add member data to count the size of the array and the array 
   // member data (suggested:  use a dynamic array to store the digits)

};