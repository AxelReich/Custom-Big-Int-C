#include <iostream>

using namespace std; 

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
    friend ostream& operator << (ostream& os, const MyInt& x);      // Print the number in regular formatting 
    friend istream& operator >> (istream& is, const MyInt& x);      // Ignore leading spaces, until there is a num. 


public:
    //Constructors 

    MyInt(int n = 0);		    // If negative parameter, set to 0. Else, set value to the parameter 
    MyInt(const char* c);       // C-string that is a combination of chars with a '\n' at the end. If Empty, or have chars, or does not have any nums 
                                                                                                // integer = 0
    ~MyInt();                   // When myInt is deallocated, should deallocate any data 

    // Copy constructor and assignment operator for deep copy
    MyInt(const MyInt& x);
    MyInt& operator=(const MyInt& x);

    void checkInvalidParameter();

    // getters
    int GetSize()  const;
    int GetArray() const;

    // setters 
    void SetSize(int n);
    void SetArray(int n);
    void Grow();

    // Other operator overloads  ++int; int++
        // Pre, returns the value incremented 
    MyInt operator++();
        // Post, returns a copy before incrementing the value
    MyInt operator++(int x);

private:
    int size;
    int *arrInt;               // integer = [1,2,3,4,5]      When printed should be: 12345

    void Resize(int NewSize);     // I should never put it more than 5 spots more than there are 
                                    // Normally use it when the istream is called and the user has to type the int.  

};

// Is all this data enough????