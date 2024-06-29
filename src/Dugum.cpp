/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/



#include "Dugum.hpp"

Dugum::Dugum() : sayi(nullptr), sonraki(nullptr) {}

Dugum::Dugum(Sayi* sayiDegeri) : sayi(sayiDegeri), sonraki(nullptr) {}

