/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/





#include "SayilarListesi.hpp"

SayiListesi::SayiListesi() : ilkDugum(nullptr) {}

SayiListesi::~SayiListesi() {
    Dugum* gec = ilkDugum;
        while (gec != nullptr)
        {
            Dugum* sil = gec;
            gec = gec->sonraki;
            delete sil;
        }
}

void SayiListesi::ekleDugumSon(Sayi* sayiDegeri) {
     Dugum* yeniDugum = new Dugum(sayiDegeri);
        if (this->ilkDugum == nullptr) {
            this->ilkDugum = yeniDugum;
        }
        else {
            Dugum* temp = this->ilkDugum;
            while (temp->sonraki != nullptr) {
                temp = temp->sonraki;
            }
            temp->sonraki = yeniDugum;
        }
}