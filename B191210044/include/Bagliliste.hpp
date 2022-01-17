/**
* @file Bagliliste.hpp
* @description Bagliliste.cpp'de kullanacağımız fonksiyonları tanımladık.
* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 5/11/2021
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/

#ifndef Bagliliste_hpp
#define Bagliliste_hpp
#include <exception>
#include <iostream>
#include "Dugum.hpp"

class Bagliliste
{
public:
    Bagliliste();
    ~Bagliliste();
    void ekle(string veri);
    void cikar(int sira);
    void cikar();
    void onuneEkle(int sira,string veri);

    friend ostream& operator<<(ostream& os,Bagliliste& bagliliste);
    Dugum* DugumGetir(int sira);
private:
    
    Dugum* ilk;
};

#endif