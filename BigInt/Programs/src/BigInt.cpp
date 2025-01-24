#include <iostream>
#include <string>
#include <algorithm>
#include "BigInt.h"
#define to_num(c) (c-'0')
using namespace std;

BigInt::BigInt()
{
    flag = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    flag = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    flag = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;  
}

string BigInt::to_string() const
{
    return (!flag) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& i2) const
{
    if (digits.size() != i2.digits.size()) return false;
    if (flag != i2.flag) return false;
    for (int i = 0; i < digits.size(); i++)
        if (digits[i] != i2.digits[i])
            return false;
    return true;
}

bool BigInt::operator>(const BigInt& i2) const
{
    if (!flag && i2.flag) return true;
    if (flag && !i2.flag) return false;
    // They have the same sign
    if (digits.size() > i2.digits.size()) {
        return flag ? false : true;
    }
    if (digits.size() < i2.digits.size()) {
        return flag ? true : false;
    }
    // They have the same number of digits 
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] > i2.digits[i]) {
            return flag ? false : true;
        }
    }
    // They are equal
    return false;
}

bool BigInt::operator!=(const BigInt& i2) const
{
    return !(this->operator==(i2));
}

bool BigInt::operator<=(const BigInt& i2) const
{
    return !(this->operator>(i2));
}

bool BigInt::operator<(const BigInt& i2) const
{
    return !(this->operator==(i2)) && !(this->operator>(i2));
}

bool BigInt::operator>=(const BigInt& i2) const
{
    return (this->operator>(i2)) || (this->operator==(i2));
}

BigInt BigInt::sum(const BigInt& i2) const
{
    string digsum1, digsum2, temp;
    digsum1 = digits;
    digsum2 = i2.digits;

    if (digsum1.size() < digsum2.size()) {
        temp = digsum1;
        digsum1 = digsum2;
        digsum2 = temp;
    }

    reverse(digsum1.begin(), digsum1.end());
    reverse(digsum2.begin(), digsum2.end());

    string sum_total;
    char carry = 0;

    for (size_t i = 0; i < digsum1.size(); i++) {
        int digit1 = digsum1[i] - '0';
        int digit2 = (i < digsum2.size()) ? digsum2[i] - '0' : 0;

        int digitSum = digit1 + digit2 + carry;
        sum_total.push_back((digitSum % 10) + '0');
        carry = digitSum/10;
    }
    
    if (carry > 0) {
        sum_total.push_back(carry + '0');
    }

    reverse(sum_total.begin(), sum_total.end());

    return BigInt(sum_total);
}

BigInt BigInt::mult(const BigInt& i2) const
{
    string multnum, multcount, temp;
    multnum = digits;
    multcount = i2.digits;

    reverse(multnum.begin(), multnum.end());

    string mult_total;
    char carry = 0;

    for (size_t i = 0; i < multcount.size(); i++) {
        int digit1 = digsum1[i] - '0';

        int digitMult = digit1 + digit1 + carry;
        mult_total.push_back((digitMult % 10) + '0');
        carry = digitMult/10;
    }
    
    if (carry > 0) {
        mult_total.push_back(carry + '0');
    }

    reverse(mult_total.begin(), mult_total.end());

    return BigInt(mult_total);
}

BigInt BigInt::operator+(const BigInt& i2) const
{
    BigInt sum;

    return sum;
}

BigInt BigInt::operator*(const BigInt &) const
{
    BigInt mult;

    return BigInt();
}
