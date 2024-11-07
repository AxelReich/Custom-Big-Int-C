#include "myint.h"
#include <iostream>

using namespace std;


int C2I(char c)
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	return -1;	// error
   return (c - '0');				    // success
}



// These overloads were declared as friends functions 

MyInt operator+ (const MyInt& x, const MyInt& y)
{
    
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

// operator overloads for input and output 
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
    // Skip the leading spaces
    while (isspace(is.peek())){
        is.get();
    }

    //Check next if it a digit 

    int capacity = 5;
    char* intArr = new char[capacity];
    int i = 0;

    char ch;

    while (isdigit(ch) && is.get(ch)){
        if (i >= capacity){
            capacity += 5;
            char* newintArr = new char[capacity];
            for (int i = 0; i < capacity; i++){
                newintArr[i] = intArr[i]; 
            }
            delete[] intArr;
            intArr = newintArr;
        }
    }

    // TODO 

    return is;
}


//Constructors 
MyInt::MyInt(int n)		    // If negative parameter, set to 0. Else, set value to the parameter // Because it is an INT then it would not accept any large value. 
{
    // Set Size depending on the lenght of the parameter
    SetSize(n); 
    SetArray(n);
}
MyInt::MyInt(const char* c)       // C-string that is a combination of chars with a '\n' at the end. If Empty, or have chars, or does not have any nums. Int = 0                                                                           
{
    // Invalid parameter 
    if (c == nullptr || c == '\0' || c[0] == '-'){
        size = 1;
        arrInt = new int[size];
        arrInt[0] = 0;
        return;
    }

    // Allocate the memory 
    size = 0;
    for (int i = 0; c[i] != '\0'; i++){
        if (c[i] < '0' || c[i] > '9'){
            size = 1;
            arrInt = new int[size];
            arrInt[0] = 0;
            return;
        }
        size++;
    }

    // Create the array
    arrInt = new int[size];

    // Put values inside the array
    for (int i = 0; i < size; i++){
        arrInt[i] = C2I(c[i]);
    }
}
//Destructor
MyInt::~MyInt()                   // When myInt is deallocated, should deallocate any data 
{
    delete[] arrInt;
    arrInt = nullptr;             
}
// Copy constructor and assignment operator for deep copy
MyInt::MyInt(const MyInt& x) : size(x.size)         // Should use this when  
{
    arrInt = new int[size];
    for (int i = 0; i < size; i++){
        arrInt[i] = x.arrInt[i];
    }

}
MyInt& MyInt::operator=(const MyInt& x)             // Should use this when 
{
    // Check for self assignment 
    if (this == &x){
        return *this;
    }

    delete[] arrInt;

    // Allocate new memory
    size = x.size;
    arrInt = new int[size];
    
    for (int i = 0; i < size; i++){
        arrInt[i] = x.arrInt[i];
    }

    return *this;
}

// getters
int MyInt::GetSize()  const
{
    return size;
}


// setters 
void MyInt::SetSize(int n)
{
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
    SetArray(n);

}
void MyInt::SetArray(int n)
{
        // Allocate space in memory for arr int and fills them with the numbers   
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


// Other operator overloads  ++int; int++
// Pre, returns the value incremented 
MyInt MyInt::operator++()
{

}
// Post, returns a copy before incrementing the value
MyInt MyInt::operator++(int x)
{

}



// I dont understand, isnt supposed to be that there could be an infinite amount of numbers
// Where should this happen if in the constructor you can only put 2 billion, where should this be able to happen????