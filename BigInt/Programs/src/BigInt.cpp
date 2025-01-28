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

BigInt BigInt::sub(const BigInt & i2) const
{
    string num1 = digits;
    string num2 = i2.digits;
    bool isNegative1 = flag;
    bool isNegative2 = i2.flag;      
    bool resultNegative = false;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result;
    int borrow = 0;

    std::cout << isNegative1 << ", " << isNegative2 << "\n";
    std::cout << num1 << "\n";
    std::cout << num2 << "\n";

    // Case 3: Both numbers are negative
    if (isNegative1 && isNegative2) {
        BigInt absThis(num1);
        BigInt absI2(num2);

        cout << "this ran" << "\n";
        

        return absThis.sub(absI2); // Swap and compute absolute subtraction
    }

    // case1: subtracting a negative number (A - (-B))
    if (isNegative2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        return (BigInt(num1).sum(BigInt(num2)).to_string());
    }

    // case2: subtracting from a negative (-A - B) = -(A + B)
    if (isNegative1 && !isNegative2) {

    reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        return BigInt("-" + (BigInt(num1).sum(i2)).digits); 
    }


    // Case 4: Both numbers are positive (normal subtraction)
    if (*this < i2) {
        swap(num1, num2);
        resultNegative = true;
    }

    for (size_t i = 0; i < num1.size(); i++) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < num2.size()) ? num2[i] - '0' : 0;

        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1; // Borrow from the next higher digit
        } else {
            borrow = 0; // No borrow needed
        }

        result.push_back(diff + '0');
    }

    while (borrow > 0 && result.size() > 0) {
        int lastDigit = result.back() - '0';
        result.pop_back();
        lastDigit -= borrow;

        if (lastDigit < 0) {
            lastDigit += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(lastDigit + '0');
    }

    // Remove extra zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());

    return BigInt((resultNegative ? "-" : "") + result);
}

BigInt BigInt::sum(const BigInt &i2) const
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

/*
BigInt BigInt::mult(const BigInt& i2) const
{
    BigInt multNum(digits);
    BigInt multTotal("0");

    string multCount = i2.digits;

    while (multCount != '0') {
        multTotal = multTotal + multNum;
        multCount = multCount - '1';
    }

    return multTotal;
}
*/

BigInt BigInt::operator-(const BigInt& i2) const
{
    BigInt sub;

    return sub;
}

BigInt BigInt::operator+(const BigInt& i2) const
{
    BigInt sum;

    return sum;
}
/*
BigInt BigInt::operator*(const BigInt & i2) const
{
    BigInt mult;

    return mult;
}
*/