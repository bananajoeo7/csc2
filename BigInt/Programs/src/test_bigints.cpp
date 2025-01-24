#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "BigInt.h"
using namespace std;

TEST_CASE("Test can create and render BigInts") {
    BigInt bi;
    CHECK(bi.to_string() == "0");
    BigInt bi2(42);
    CHECK(bi2.to_string() == "42");
    BigInt bi3(-42);
    CHECK(bi3.to_string() == "-42");
    BigInt bi4("123456789012345678901234567890");
    CHECK(bi4.to_string() == "123456789012345678901234567890");
    BigInt bi5("-923456789012345678901234567890");
    CHECK(bi5.to_string() == "-923456789012345678901234567890");
}

TEST_CASE("Test can compare BigInts for equality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 == i5) == true);
    CHECK((i1 == i2) == false);
    CHECK((i1 == i3) == false);
    CHECK((i2 == i6) == false);
}

TEST_CASE("Test can compare BigInts for inequality") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i2 > i5) == false);
    CHECK((i2 > i1) == true);
    CHECK((i4 > i1) == false);
    CHECK((i6 > i4) == true);
}

TEST_CASE("Test can compare BigInts with !=, <=, <, and <=") {
    BigInt i1("12345");
    BigInt i2("54321");
    BigInt i3("123456");
    BigInt i4("-654321");
    BigInt i5("54321");
    BigInt i6("-54321");
    CHECK((i4 != i1) == true);
    CHECK((i2 <= i5) == true);
    CHECK((i2 < i1) == false);
    CHECK((i6 >= i4) == true);
}

TEST_CASE("Test helper function to add BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("222");
    BigInt i4("888");
    BigInt i5("119");
    BigInt i6("361736761273");
    CHECK((i1.sum(i2)).to_string() == "444");
    CHECK((i1.sum(i1)).to_string() == "246");
    CHECK((i1.sum(i3)).to_string() == "345");
    CHECK((i1.sum(i5)).to_string() == "242");
    CHECK((i1.sum(i4)).to_string() == "1011");
    CHECK((i1.sum(i6)).to_string() == "361736761396");
}

TEST_CASE("Test helper function to add BigInts with negatives") {
    BigInt i1("123");
    BigInt i2("-321");
    BigInt i3("-222");
    BigInt i4("-888");
    BigInt i5("119");
    BigInt i6("-361736761273");
    BigInt i7("361736761273");

    CHECK((i1.sum(i2)).to_string() == "-198");
    CHECK((i1.sum(i3)).to_string() == "-99");
    CHECK((i1.sum(i4)).to_string() == "-765");
    CHECK((i2.sum(i3)).to_string() == "-543");
    CHECK((i5.sum(i2)).to_string() == "-202");
    CHECK((i4.sum(i6)).to_string() == "-361737650161");
    CHECK((i7.sum(i6)).to_string() == "0");
    CHECK((i7.sum(i1)).to_string() == "361736761396");
}


/*
TEST_CASE("Test helper function to multiply BigInts") {
    BigInt i1("123");
    BigInt i2("321");
    BigInt i3("222");
    BigInt i4("888");
    BigInt i5("119");
    CHECK((i1.mult(i2)).to_string() == "39483");
    CHECK((i1.mult(i1)).to_string() == "15129");
    CHECK((i1.mult(i3)).to_string() == "27306");
    CHECK((i1.mult(i5)).to_string() == "14637");
    CHECK((i1.mult(i4)).to_string() == "109224");
}*/