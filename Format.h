#pragma once
#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <compare>

static_assert(__cplusplus >= 202002L, "This header must be included in a C++20 or later file");
namespace std {
    class FormatString {
    public:
        FormatString() {}
        FormatString(int right) : s(to_string(right)) {}
        FormatString(const string& right) : s(right) {}
        FormatString(double right) : s(to_string(right)) {}
        FormatString(long long right) : s(to_string(right)) {}
        FormatString(char right) : s(1, right) {}

        operator int() const { return stoi(s); }
        operator string() const { return s; }
        operator double() const { return stod(s); }
        operator long long() const { return stoll(s); }

        strong_ordering operator<=>(const FormatString& right) const {
            return s <=> right.s;
        }

        FormatString operator+(const FormatString& right) const {
            return FormatString(s + right.s);
        }
        FormatString operator+(int right) const {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(const string& right) const {
            return FormatString(s + right);
        }
        FormatString operator+(double right) const {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(long long right) const {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(char right) const {
            return FormatString(s + string(1, right));
        }

        friend ostream& operator<<(ostream& os, const FormatString& fs) {
            os << fs.s;
            return os;
        }
        friend istream& operator>>(istream& is, FormatString& fs) {
            is >> fs.s;
            return is;
        }

    private:
        string s;
    };

    void print(const FormatString& _format) {
        cout << _format;
    }

    void println(const FormatString& _format) {
        cout << _format << endl;
    }

    FormatString input() {
        FormatString fs;
        cin >> fs;
        return fs;
    }
    typedef FormatString fs;
}
#endif