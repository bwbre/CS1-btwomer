


#pragma once
#include <iostream>

//lab 4 or 5 
template <class T1, class T2>
void getsides(T1& side1, T2& side2) {
    std::cout << "Please enter two side of rect: "
    std::cin >> side1 >> side2

}

template <class T1, class T2>
void calcarea(const T1& side1, const T2& side2, double&);

template <class T1, class T2>
void calcperim(const T1& side1, const T2& side2, const double&, const double&);

template <class T1, class T2>
void printvals(const T1& side1, const T2& side2, const double&, const double&) {


}