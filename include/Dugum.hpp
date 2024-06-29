/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/


#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;
    Dugum();
    Dugum(Sayi* sayiDegeri);
    
};

#endif // DUGUM_HPP