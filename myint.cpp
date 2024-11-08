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
MyInt operator+(const MyInt& x, const MyInt& y)
{
    // Find the maximum size of the two MyInt objects
    int maxSize = max(x.size, y.size);
    bool carry = false;  // Store carry (either 0 or 1)

    // Create a result MyInt with an extra space for possible carry
    MyInt result;
    result.arrInt = new int[maxSize + 1]; 
    result.size = maxSize + 1;  

    int i;
    for (i = 0; i < maxSize; ++i) {
        int sum = carry;  // Start with the carry from the previous iteration

        // Add digits from x and y if within bounds
        if (i < x.size) sum += x.arrInt[x.size - i - 1];
        if (i < y.size) sum += y.arrInt[y.size - i - 1];

        result.arrInt[result.size - i - 1] = sum % 10;  // Store last digit of sum
        carry = sum / 10;  // Update carry
    }

    // Handle the final carry, if present
    if (carry) {
        result.arrInt[0] = carry;
    } else {
        // If there's no carry, adjust the result size to ignore extra space
        for (int j = 1; j < result.size; ++j) {
            result.arrInt[j - 1] = result.arrInt[j];
        }
        result.size--;
    }

    // Remove any leading zeros
    while (result.size > 1 && result.arrInt[0] == 0) {
        for (int k = 1; k < result.size; ++k) {
            result.arrInt[k - 1] = result.arrInt[k];
        }
        result.size--;
    }

    return result;
}

MyInt operator* (const MyInt& x, const MyInt& y)
{
    // Max size of array x + y
    int maxSize = x.size + y.size;

    MyInt result;
    result.arrInt = new int[maxSize];

    // Initialize the array to 0
    for (int i = 0; i < maxSize; i++){
        result.arrInt[i] = 0;
    }

    // Perform multiplication using long multiplication
    for (int i = 0; i < x.size; ++i) {
        int carry = 0;
        for (int j = 0; j < y.size; ++j) {
            int product = x.arrInt[x.size - i - 1] * y.arrInt[y.size - j - 1] + result.arrInt[maxSize - i - j - 1] + carry;
            result.arrInt[maxSize - i - j - 1] = product % 10;  // Store the single digit
            carry = product / 10;  // Update carry for next iteration
        }
        // If there's a remaining carry, add it to the next position in the result
        result.arrInt[maxSize - i - y.size - 1] += carry;
    }

    // Remove leading zeros (if any) from the result
    int newSize = maxSize;
    while (newSize > 1 && result.arrInt[maxSize - newSize] == 0) {
        --newSize;
    }
    result.size = newSize;

    // Adjust result array if there were leading zeros
    if (newSize < maxSize) {
        int* trimmedArr = new int[newSize];
        for (int i = 0; i < newSize; ++i) {
            trimmedArr[i] = result.arrInt[maxSize - newSize + i];
        }
        delete[] result.arrInt;
        result.arrInt = trimmedArr;
    }

    return result;
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
bool operator<(const MyInt& x, const MyInt& y)
{
    if (x.size < y.size) {
        return true;
    }
    // If x has more digits than y, x is larger
    if (x.size > y.size) {
        return false;
    }
    // If sizes are equal, compare digit by digit (from most significant)
    for (int i = 0; i < x.size; ++i) {
        if (x.arrInt[i] < y.arrInt[i]) {
            return true;
        }
        if (x.arrInt[i] > y.arrInt[i]) {
            return false;
        }
    }
    // If they are equal
    return false;
}
bool operator>  (const MyInt& x, const MyInt& y)
{
    return y < x;
}
bool operator<= (const MyInt& x, const MyInt& y)
{
    return !(y<x);
}
bool operator>= (const MyInt& x, const MyInt& y)
{
    return !(x<y);
}
bool operator== (const MyInt& x, const MyInt& y)
{

    // If x has more digits than y, x is larger
    if (x.size != y.size) {
        return false;
    }
    // If sizes are equal, compare digit by digit (from most significant)
    for (int i = 0; i < x.size; ++i) {
        if (x.arrInt[i] == y.arrInt[i]) {
            return true;
        }
        if (x.arrInt[i] == y.arrInt[i]) {
            return true;
        }
    }
    // If they are equal
    return true;
}
bool operator!= (const MyInt& x, const MyInt& y)
{
    return !(x == y);
}

// operator overloads for input and output 
ostream& operator << (ostream& os, const MyInt& x)      // Print the number in regular formatting 
{
    for (int i = 0; i < x.size; i++){
        os << x.arrInt[i];
    }
    os << endl;
    return os;
}
istream& operator>>(istream& is  , MyInt& x) 
{
    delete[] x.arrInt;
    x.arrInt = new int[0];
    x.size = 0;
    // Skip leading white spaces
    while (isspace(is.peek())) {
        is.get();  // Read and discard white space characters
    }

    // Create a temporary buffer to store the digits as we read them
    char* c;  // Using string for temporary storage of digits
    
    // Read digits one at a time
    char ch;
    int size = 0;
    while (is.get(ch) && isdigit(ch)) {
        if (size >= x.size){
            x.Resize(1);
        }
        x.arrInt[size] = C2I(ch); 
        size ++;

    }
    cout << size;

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


}

void MyInt::Resize(int newSize)
{  
    // Create temp 
    int* tempArray = new int[size+newSize];

    // Copy values 
    for (int i = 0; i < size; i++){
        tempArray[i] = arrInt[i]; 
    }
    // Delete
    delete[] arrInt;

    // set tthe size to the new one
    size = size+newSize;

    // Set the pointer of the temporary array to arrInt
    arrInt = tempArray;

    cout << size;
}

// Other operator overloads  ++int; int++
// Pre, returns the value incremented 
// Check in these two if they are a nine, if they are a nine add a new array, delete the previous one. Else just increment ti 
MyInt MyInt::operator++() 
{

}
// Post, returns a copy before incrementing the value
MyInt MyInt::operator++(int x)
{

}



