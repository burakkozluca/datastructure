/**
* @file Dugum.cpp
* @description Dugum'u oluşturduk.
* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 5/11/2021
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(string veri)
{
    this->veri = veri;

    onceki = sonraki = 0;
}
Dugum::~Dugum()
{

}