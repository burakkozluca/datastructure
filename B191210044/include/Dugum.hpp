/**
* @file Dugum.hpp
* @description Dugum.cpp'de kullanacağımız fonksiyonları tanımladık.
* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 5/11/2021
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;

class Dugum
{
public:
    Dugum(string veri);
    ~Dugum();
    string veri;
    Dugum* sonraki;
    Dugum* onceki;
};

#endif