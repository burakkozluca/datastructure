/**
* @file Bagliliste.cpp
* @description Fonksiyonların ne yapacaklarını kodladık. 
* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 5/11/2021
* @author Burak Kozluca burak.kozluca@ogr.sakarya.edu.tr
*/
#include "Bagliliste.hpp"
#include <iomanip>

using namespace std;

Bagliliste::Bagliliste()
{
    ilk = 0;
}
Bagliliste::~Bagliliste()
{
    Dugum* gec = ilk;
    while(gec != 0)
    {
        Dugum* silinecek = gec;
        gec = gec->sonraki;

        delete silinecek;
    }
}
void Bagliliste::ekle(string veri)
{
    Dugum* yeniDugum = new Dugum(veri);
    if(ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        Dugum* gec = ilk;

        while(gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec ->sonraki = yeniDugum;
        yeniDugum ->onceki = gec;
    }
}

void Bagliliste::onuneEkle(int sira,string veri)
{
    Dugum* aktifDugum = DugumGetir(sira);

    if(aktifDugum)
    {
        Dugum* aktifOnceki = aktifDugum->onceki;

        Dugum* yeniDugum = new Dugum(veri);
        aktifDugum-> onceki=yeniDugum;
        yeniDugum->sonraki=aktifDugum;
        yeniDugum->onceki=aktifOnceki;

        if(aktifOnceki)
            aktifOnceki->sonraki = yeniDugum;
        else
        ilk = yeniDugum;
    }
    else
    {
        ekle(veri);
    }
}

void Bagliliste::cikar()
{
    if(ilk==0)
    {
        return;
    }
    if(ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        Dugum* gec = ilk;

        while(gec->sonraki->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        delete gec->sonraki;
        gec ->sonraki = 0;
    }
}

void Bagliliste::cikar(int sira)
{
    Dugum* silinecek = DugumGetir(sira);

    if(silinecek)
    {
        Dugum* silinecekOnceki = silinecek->onceki;
        Dugum* silinecekSonraki = silinecek->sonraki;

        if(silinecekSonraki)
        {
            silinecekSonraki->onceki = silinecekOnceki;  
        }
        if(silinecekOnceki)
        {
            silinecekOnceki->sonraki = silinecekSonraki;
        }
        else
            ilk = silinecekSonraki;
        delete silinecek;
    }
    else
    {
        cikar();
    }
}

Dugum* Bagliliste::DugumGetir(int sira)
{
    Dugum* gec = ilk;

    int sayac = 0;

    while (gec != 0)
    {
        if(sayac==sira)
            return gec;
        gec=gec->sonraki;

        sayac++;
    }
    return 0;
}

ostream& operator<<(ostream& os,Bagliliste& bagliliste)
{
    os<<"Listenin son hali:"<<endl;

    Dugum* gec = bagliliste.ilk;

    while (gec != 0)
    {
        if(gec->sonraki==0)        
            os<<gec->veri;
        else
            os<<gec->veri<<"<-->";
        gec = gec->sonraki;
    }
    return os;   
}