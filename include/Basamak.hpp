/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/



#ifndef BASAMAK_HPP
#define BASAMAK_HPP

class Basamak {
public:
    int deger;
    Basamak* sonraki;
    Basamak();
    Basamak(int veri);
    
};

#endif // BASAMAK_HPP