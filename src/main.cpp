/**
* B221210064
* @description baglı listeler ile basamak ve sayi islemleri yapan kodlar
* @course 1-C
* @assignment 1. odev
*  13.11.2023
*  Tugra YAVUZ tugrayavuz258@gmail.com / tugra.yavuz@ogr.sakarya.edu.tr
*/




#include <iostream>
#include <fstream>
#include <sstream>
#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void yazdirSayiListesiDetayliYeni(SayiListesi* sayiListesi) {
    Dugum* tempDugum = sayiListesi->ilkDugum;

    while (tempDugum != nullptr) {
        cout << "###########" << endl;
        Basamak* tempBasamak = tempDugum->sayi->ilkBasamak;


        cout << "#";
        cout << tempDugum->sayi << "#" << "     ";

        tempBasamak = tempDugum->sayi->ilkBasamak;
        while (tempBasamak != nullptr) {
            uintptr_t basamakAdres = reinterpret_cast<uintptr_t>(tempBasamak);
            cout << "*" << (basamakAdres % 1000) << "*" << " ";
            tempBasamak = tempBasamak->sonraki;
        }
        cout << endl;

        cout << "###########" << "     ";

        tempBasamak = tempDugum->sayi->ilkBasamak;
        while (tempBasamak != nullptr) {

            cout << "***** ";
            tempBasamak = tempBasamak->sonraki;
        }
        cout << endl;

        tempBasamak = tempDugum->sayi->ilkBasamak;
        cout << "#---------#" << "     ";

        while (tempBasamak != nullptr) {

            cout << "***** ";
            tempBasamak = tempBasamak->sonraki;
        }
        cout << endl;

        tempBasamak = tempDugum->sayi->ilkBasamak;
        cout << "# ";
        while (tempBasamak != nullptr) {
            cout << tempBasamak->deger;
            tempBasamak = tempBasamak->sonraki;
        }
        cout << " #" << "         ";

        tempBasamak = tempDugum->sayi->ilkBasamak;
        while (tempBasamak != nullptr) {
            cout << "* " << tempBasamak->deger << " * ";
            tempBasamak = tempBasamak->sonraki;
        }
        cout << endl;

        tempDugum = tempDugum->sonraki;
        cout << endl;
    }
}



void tekBasamaklariBasaAl(SayiListesi* sayiListesi) {
    Dugum* tempDugum = sayiListesi->ilkDugum;
    while (tempDugum != nullptr) {
        Basamak* tempBasamak = tempDugum->sayi->ilkBasamak;
        Basamak* basaEklenecek = nullptr;
        Basamak* sonaEklenecek = nullptr;
        Basamak* tempTek = nullptr;
        Basamak* tempCift = nullptr;

        while (tempBasamak != nullptr) {
            Basamak* tempSonraki = tempBasamak->sonraki;
            if (tempBasamak->deger % 2 == 0) {
                if (sonaEklenecek == nullptr) {
                    sonaEklenecek = tempBasamak;
                    tempCift = sonaEklenecek;
                }
                else {
                    tempCift->sonraki = tempBasamak;
                    tempCift = tempCift->sonraki;
                }
            }
            else {
                if (basaEklenecek == nullptr) {
                    basaEklenecek = tempBasamak;
                    tempTek = basaEklenecek;
                }
                else {
                    tempTek->sonraki = tempBasamak;
                    tempTek = tempTek->sonraki;
                }
            }
            tempBasamak = tempSonraki;
        }

        if (tempTek != nullptr) {
            tempTek->sonraki = sonaEklenecek;
            if (tempCift != nullptr) {
                tempCift->sonraki = nullptr;
            }
            tempDugum->sayi->ilkBasamak = basaEklenecek;
        }
        else {
            tempDugum->sayi->ilkBasamak = sonaEklenecek;
        }
        tempDugum = tempDugum->sonraki;
    }
}

void basamaklariTersCevir(SayiListesi* sayiListesi) {
    Dugum* tempDugum = sayiListesi->ilkDugum;
    while (tempDugum != nullptr) {
        Basamak* prev = nullptr;
        Basamak* current = tempDugum->sayi->ilkBasamak;
        Basamak* next = nullptr;
        while (current != nullptr) {
            next = current->sonraki;
            current->sonraki = prev;
            prev = current;
            current = next;
        }
        tempDugum->sayi->ilkBasamak = prev;
        tempDugum = tempDugum->sonraki;
    }
}

void enBuyuguSil(SayiListesi* sayiListesi) {
    Dugum* tempDugum = sayiListesi->ilkDugum;
    Dugum* enBuyukDugum = tempDugum;
    long enBuyuk = 0;

    // En büyük sayıyı ve onun olduğu düğümü bulma
    while (tempDugum != nullptr) {
        Basamak* tempBasamak = tempDugum->sayi->ilkBasamak;
        long value = 0;
        while (tempBasamak != nullptr) {
            value = value * 10 + tempBasamak->deger;
            tempBasamak = tempBasamak->sonraki;
        }
        if (value > enBuyuk) {
            enBuyuk = value;
            enBuyukDugum = tempDugum;
        }
        tempDugum = tempDugum->sonraki;
    }

    // En büyük sayıyı silme işlemi
    if (enBuyukDugum == sayiListesi->ilkDugum) {
        sayiListesi->ilkDugum = enBuyukDugum->sonraki;
        delete enBuyukDugum->sayi;
        delete enBuyukDugum;
    }
    else {
        tempDugum = sayiListesi->ilkDugum;
        while (tempDugum->sonraki != enBuyukDugum) {
            tempDugum = tempDugum->sonraki;
        }
        tempDugum->sonraki = enBuyukDugum->sonraki;
        delete enBuyukDugum->sayi;
        delete enBuyukDugum;
    }
}



int main() {


    SayiListesi* sayiListesiMain = new SayiListesi();

    ifstream okumaDosyasi("sayilar.txt");
    if (!okumaDosyasi) {
        cout << "sasa" << endl;
        cerr << "Dosya acilamadi.";
        exit(1);
    }


    string line;


    while (getline(okumaDosyasi, line)) {
        istringstream ss(line);
        string token;
        while (ss >> token) {
            try {
                long sayiInt = stoll(token);
                if (sayiInt == 0) {
                    continue;
                }
                if (sayiInt >= 2000000000)
                {
                    continue;
                }
                Sayi* sayiNesneleri = new Sayi();
                sayiNesneleri->ekle(sayiInt);
                sayiListesiMain->ekleDugumSon(sayiNesneleri);
            }
            catch (const std::out_of_range& e) {
                cerr << "Hata: " << e.what() << " - " << token << " çok büyük sayi" << endl;
            }
        }
    }
    okumaDosyasi.close();

    yazdirSayiListesiDetayliYeni(sayiListesiMain);
    cout << endl << endl << endl << endl << endl;

    int baskaIslemYapmakIstiyorMusunuz = 0;
    do {
        int menuSecimDegiskeni;
        do {
            cout << "Lutfen yapmak istediginiz islemi seciniz" << endl;
            cout << "1- Tek basamaklari basa al" << endl;
            cout << "2- Sayilarin basamak dugumlerini sondan basa getir (reverse)" << endl;
            cout << "3- Sayilar listesi icindeki en buyuk sayiyi listeden sil" << endl;
            cin >> menuSecimDegiskeni;
        } while (!(menuSecimDegiskeni == 1 || menuSecimDegiskeni == 2 || menuSecimDegiskeni == 3));
        cout << "Yapmak istediginiz islem basariyla alindi" << endl;

        if (menuSecimDegiskeni == 1) {
            tekBasamaklariBasaAl(sayiListesiMain);
            yazdirSayiListesiDetayliYeni(sayiListesiMain);
        }
        else if (menuSecimDegiskeni == 2) {
            basamaklariTersCevir(sayiListesiMain);
            yazdirSayiListesiDetayliYeni(sayiListesiMain);
        }
        else if (menuSecimDegiskeni == 3) {
            enBuyuguSil(sayiListesiMain);
            yazdirSayiListesiDetayliYeni(sayiListesiMain);
        }

        do {
            cout << "Baska islem yapmak istiyor musunuz? (1 - Evet, 0 - Hayir)" << endl;
            cin >> baskaIslemYapmakIstiyorMusunuz;
        } while (!(baskaIslemYapmakIstiyorMusunuz == 0 || baskaIslemYapmakIstiyorMusunuz == 1));
        cout << "Tercihiniz alindi" << endl;
    } while (baskaIslemYapmakIstiyorMusunuz == 1);
    if (sayiListesiMain->ilkDugum != nullptr)
    {
        Dugum* gec = sayiListesiMain->ilkDugum;
        while (gec != nullptr)
        {
            delete gec->sayi;
            gec = gec->sonraki;
        }


    }
    delete sayiListesiMain;

    return 0;
}

