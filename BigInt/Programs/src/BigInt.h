#include <string>
using namespace std;

class BigInt 
{
    bool flag;
    string digits;

    public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);

    // helper functions
    BigInt sub(const BigInt&) const;
    BigInt sum(const BigInt&) const;
    BigInt mult(const BigInt&) const;

    // member functions
    string to_string() const;
    bool operator==(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<=(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator>=(const BigInt&) const;
    BigInt operator-(const BigInt&) const;
    BigInt operator+(const BigInt&) const;
    BigInt operator*(const BigInt&) const;
};
