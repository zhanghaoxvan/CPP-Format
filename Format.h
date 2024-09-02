// +-------------------------------+
// |          Format.h             |
// | Copyright (c) zhanghaoxvan.   |
// | All rights reserved.          |
// +-------------------------------+
// | Note:                         |
// | If you use the print function |
// | or the println function and   |
// | the first item is not a       |
// | variable of type FormatString,|
// | add the caster fs() to both   |
// | sides of the first term.      |
// +-------------------------------+
// | Write down your life motto:   |
// |                               |
// |                               |
// |                               |
// |                               |
// |                               |
// |                               |
// |                               |
// |                               |
// +-------------------------------+
#ifdef _MSC_VER
#pragma once
#endif
#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <compare>

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

#if __cplusplus >= 202002L
        strong_ordering operator<=>(const FormatString& right) {
            return s <=> right.s;
        }
#else
        bool operator==(const FormatString& right) {
            return s == right.s;
        }
        bool operator<(const FormatString& right) {
            return s < right.s;
        }
        bool operator>(const FormatString& right) {
            return s > right.s;
        }
        bool operator<=(const FormatString& right) {
            return s <= right.s;
        }
        bool operator>=(const FormatString& right) {
            return s >= right.s;
        }
        bool operator!=(const FormatString& right) {
            return s != right.s;
        }
#endif

        FormatString operator+(const FormatString& right) {
            return FormatString(s + right.s);
        }
        FormatString operator+(int right) {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(const string& right) {
            return FormatString(s + right);
        }
        FormatString operator+(double right) {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(long long right) {
            return FormatString(s + to_string(right));
        }
        FormatString operator+(char right) {
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
#if __cplusplus >= 201703L
    FormatString input(string_view s) {
        cout << s;
        return input();
    }
#else
    FormatString input(const string& s) {
        cout << s;
        return input();
    }
#endif
    typedef FormatString fs;
}
#endif