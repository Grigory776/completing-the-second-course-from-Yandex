#include "phone_number.h"
#include <sstream>
#include<iostream>

bool PrNumberStr( string str) {
    stringstream ss;
    ss << str;
    unsigned long long int numb;
    if (ss >> numb) return true;
    else return false;
}

PhoneNumber::PhoneNumber(const string& international_number) {
    stringstream ss;
    ss << international_number;

    if (international_number.size() == 0) throw invalid_argument("invalid_argument");
    if (international_number[0] != '+') throw invalid_argument("invalid_argument");
    char kost;
    ss >> kost;

    if (getline(ss, country_code_, '-')) {
        if (!PrNumberStr(country_code_)) {
            country_code_ = "";
            throw invalid_argument("invalid_argument");
        }
    }
    else throw invalid_argument("invalid_argument");

    if (getline(ss, city_code_, '-')) {
        if (!PrNumberStr(city_code_)) {
            city_code_ = "";
            throw invalid_argument("invalid_argument");
        }
    }
    else throw invalid_argument("invalid_argument");

    if (!getline(ss, local_number_)) throw invalid_argument("invalid_argument");

}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}
string PhoneNumber::GetCityCode() const {
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
    return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}