/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/



#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi {
public:
    Basamak* ilkBasamak;
    Sayi();
    void ekle(long veri);
    ~Sayi();
};

#endif // SAYI_HPP