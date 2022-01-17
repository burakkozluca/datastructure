/**
* @file main.cpp
* @description Dosya okuma ve okunan veriyi uygun şekilde ekrana yazdırma.
* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 5/11/2021
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Bagliliste.hpp"
#include "Dugum.hpp"

using namespace std;

void DosyaSatirOku()
{   
    Bagliliste* bagliliste = new Bagliliste();
    ifstream DosyaSatirOku("Veri.txt",ios::in);
    string satir;

    while(getline(DosyaSatirOku, satir))
    {   
        if(satir.find("E") == 0)
        {
            int x = stoi(satir.substr(satir.find("(")+1,satir.find("#")));
    
            if(satir.find("#")== 3)
            {
                string isim = satir.substr(satir.find("#")+1,satir.find(")")-4);
                bagliliste->onuneEkle(x,isim);
            }
            if(satir.find("#")== 4)
            {
                string isim = satir.substr(satir.find("#")+1,satir.find(")")-5);
                bagliliste->onuneEkle(x,isim);
            }
            if(satir.find("#")==5)
            {
                string isim = satir.substr(satir.find("#")+1,satir.find(")")-6);
                bagliliste->onuneEkle(x,isim);
            }
            if(satir.find("#")==6)
            {
                string isim = satir.substr(satir.find("#")+1,satir.find(")")-7);
                bagliliste->onuneEkle(x,isim);
            }
            if(satir.find("#")==7)
            {
                string isim = satir.substr(satir.find("#")+1,satir.find(")")-8);
                bagliliste->onuneEkle(x,isim);
            }
        }
        else
        {
            int x = stoi(satir.substr(satir.find("(")+1,satir.find(")")));
            bagliliste->cikar(x);
        }      
            
    }
    cout<<*bagliliste;
    delete bagliliste;       
}
int main()
{      
    DosyaSatirOku();
}