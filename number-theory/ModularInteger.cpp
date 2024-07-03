//
//  ModularInteger.cpp
//  IntensiveCamp 2 2024
//
//  Created by Ali AlSalman on 25/05/2024.
//

#include <bits/stdc++.h>

template<typename T = int, T base = 998244353, typename U = long long>
/// A Modular Integer type, that supports normal Integer functionality while guaranteeing the Integer being Modded
///
/// - parameter T: Template argument specifing the underlaying Integer type.
/// - parameter base: The base for Modulo operation, must be of type; and fit into T.
/// - parameter U: A larger Integer type to up-cast to in case of possible overflow, it must be a type that can fit `(base - 1)^2`.
struct ModularInteger {
private:
    T value;
    
public:
    typedef ModularInteger<T, base, U> Self;
    
    ModularInteger() : value(0) {}
    ModularInteger(T val) : value(val % base) {}
    
    // MARK: - Factory methods
    static Self New(T val) {
        return ModularInteger(val);
    }
    
    static Self NewUnchecked(T val) {
        Self ModInt = ModularInteger(); ModInt.value = val;
        return ModInt;
    }
    

    // MARK: - Casting
    explicit operator T() { return value; }
    
    
    // MARK: - Assignments
    Self operator=(Self rhs) {
        return Self::NewUnchecked(this->value = rhs.value);
    }
    Self operator=(T val) {
        return Self::NewUnchecked(this->value = (val % base));
    }
    
    
    // MARK: - Comparisons
     bool operator==(Self &rhs) const { return value == rhs.value; }
     bool operator< (Self &rhs) const { return value <  rhs.value; }
     bool operator<=(Self &rhs) const { return value <= rhs.value; }
     bool operator> (Self &rhs) const { return value >  rhs.value; }
     bool operator>=(Self &rhs) const { return value >= rhs.value; }

    
    // MARK: - Arithmatic Assignments
    Self operator+=(Self rhs) {
        value += rhs.value;
        return Self::NewUnchecked(value %= base);
    }
    
    Self operator-=(Self rhs) {
        value -= rhs.value - base;
        return Self::NewUnchecked(value %= base);
    }
    
    Self operator*=(Self rhs) {
        value *= rhs.value;
        return Self::NewUnchecked(value %= base);
    }
    
    // MARK: - Arithmatic Operations with Self
    Self operator+(Self rhs) const {
        return Self::NewUnchecked((value + rhs.value) % base);
    }
    
    Self operator-(Self rhs) const {
        return Self::NewUnchecked((value - rhs.value + base) % base);
    }
    
    Self operator*(Self rhs) const {
        return Self::NewUnchecked((value * rhs.value) % base);
    }
    
    
    // MARK: - Arithmatic Operations with Integers
    Self operator+(T rhs) const {
        return Self::NewUnchecked((value + (rhs % base)) % base);
    }
    
    Self operator-(T rhs) const {
        return Self::NewUnchecked((value - (rhs % base) + base) % base);
    }
    
    Self operator*(T rhs) const {
        return Self::NewUnchecked((value * (rhs % base)) % base);
    }
    
    
    // MARK: - Increment/Decrement Operations
    Self operator++(int) {
        return Self::NewUnchecked(value++ % base);
    }
    
    Self operator++() {
        return Self::NewUnchecked(++value % base);
    }
    
    Self operator--(int) {
        return Self::NewUnchecked((value-- + base) % base);
    }
    
    Self operator--() {
        return Self::NewUnchecked((--value + base) % base);
    }
};

/// `ModularInteger` inputting.
template<typename T, T base, typename U>
std::istream& operator>>(std::istream &is, ModularInteger<T, base, U> &MInt) {
    T num; is>>num;
    MInt = ModularInteger<T, base, U>(num);
    return is;
}

/// `ModularInteger` outputting.
template<typename T, T base, typename U>
std::ostream& operator<<(std::ostream &os, ModularInteger<T, base, U> MInt) {
    return os<<(T) MInt;
}

