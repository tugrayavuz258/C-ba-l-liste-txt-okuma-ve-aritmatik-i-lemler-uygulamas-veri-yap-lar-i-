/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/




#include "Sayi.hpp"

Sayi::Sayi() : ilkBasamak(nullptr) {}

void Sayi::ekle(long veri) {
    Basamak* temp = nullptr;
    Basamak* bas = nullptr;

    while (veri > 0) {
            Basamak* temp = nullptr;

        while (veri > 0) {
            long basamak = veri % 10;
            veri /= 10;
            Basamak* yeniBasamak = new Basamak(basamak);
            yeniBasamak->sonraki = temp;
            temp = yeniBasamak;
        }

        ilkBasamak = temp;  // Liste başına eklendi
    }
}

Sayi::~Sayi() {
     
        Basamak* gec = ilkBasamak;
        while (gec != nullptr)
        {
            Basamak* sil = gec;
            gec = gec->sonraki;
            delete sil;
        }
    
}
