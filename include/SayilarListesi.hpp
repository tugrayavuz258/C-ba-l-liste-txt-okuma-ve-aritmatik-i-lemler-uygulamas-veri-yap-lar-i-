/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/




#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"

class SayiListesi {
public:
    Dugum* ilkDugum;
    SayiListesi();
    ~SayiListesi();
    void ekleDugumSon(Sayi* sayiDegeri);
};

#endif // SAYILARLISTESI_HPP