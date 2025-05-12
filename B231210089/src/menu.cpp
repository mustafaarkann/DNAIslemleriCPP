/*     
* @file  menu.cpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#include "menu.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "dna.hpp"
#include "kromozom.hpp"

using namespace std;

void otomatikIslemler(const string& dosyaAdi, DNA& dna) {
    ifstream file(dosyaAdi);  // Dosyayı açıyoruz
    string line;

    if (!file.is_open()) {
        cout << "Islemler dosyası açılamadı!" << endl;
        return;
    }

    // Dosyadaki her bir satırı işliyoruz
    while (getline(file, line)) {
        if (line[0] == 'C') {  // Çaprazlama işlemi
            int kromozomIndex1 = line[1] - '0';  // Çaprazlama yapılacak ilk kromozomun indeksi
            int kromozomIndex2 = line[2] - '0';  // Çaprazlama yapılacak ikinci kromozomun indeksi

            Kromozom* kromozom1 = dna.getKromozom(kromozomIndex1);
            Kromozom* kromozom2 = dna.getKromozom(kromozomIndex2);

            if (kromozom1 && kromozom2) {
                kromozom1->crossover(*kromozom2);  // Çaprazlama işlemi
                cout << "Çaprazlama işlemi: Kromozom " << kromozomIndex1 << " ve Kromozom " << kromozomIndex2 << endl;
            } else {
                cout << "Geçersiz kromozomlar!" << endl;
            }

        } else if (line[0] == 'M') {  // Mutasyon işlemi
            int kromozomIndex = line[1] - '0';  // Mutasyon yapılacak kromozom
            int geneIndex = line[2] - '0';  // Mutasyon yapılacak genin indeksi

            Kromozom* kromozom = dna.getKromozom(kromozomIndex);
            if (kromozom) {
                kromozom->mutate(geneIndex);  // Mutasyon işlemi
                cout << "Mutasyon işlemi: Kromozom " << kromozomIndex << " ve Gen " << geneIndex << endl;
            } else {
                cout << "Geçersiz kromozom!" << endl;
            }
        }
    }

    file.close();  // Dosyayı kapatıyoruz
}



// Menü ekranını gösteren fonksiyon
void menuyuGoster() {
    cout << "=== Menü ===" << endl;
    cout << "1 - Çaprazlama" << endl;
    cout << "2 - Mutasyon" << endl;
    cout << "3 - Otomatik İşlemler" << endl;
    cout << "4 - Ekrana Yaz" << endl;
    cout << "5 - Çıkış" << endl;
    cout << "Seçiminizi yapın: ";
}

// Kullanıcı seçimine göre işlemi yapan fonksiyon
void secimIsle(int secim, DNA& dna) {
    int kromozomIndex1, kromozomIndex2;
    Kromozom* kromozom1 = nullptr;
    Kromozom* kromozom2 = nullptr;

    // Kromozom ve gen indekslerini tanımlıyoruz
    int kromozomIndex, geneIndex;
    Kromozom* selectedKromozom = nullptr;  // Seçilen kromozomu tutmak için bir işaretçi

    switch (secim) {
        case 1:  // Çaprazlama işlemi
            cout << "İlk kromozomun indeksini girin: ";
            cin >> kromozomIndex1;
            cout << "İkinci kromozomun indeksini girin: ";
            cin >> kromozomIndex2;

            kromozom1 = dna.getKromozom(kromozomIndex1);
            kromozom2 = dna.getKromozom(kromozomIndex2);

            if (kromozom1 && kromozom2) {
                kromozom1->crossover(*kromozom2); // Çaprazlama işlemi yapılacak
                cout << "Çaprazlama işlemi başarıyla tamamlandı." << endl;
            } else {
                cout << "Geçersiz kromozomlar." << endl;
            }
            break;

        case 2:  // Mutasyon işlemi
            cout << "Mutasyon işlemi seçildi." << endl;
            // Mutasyon işlemi yapılacak

             // Kullanıcıdan kromozom indeksini alıyoruz
            cout << "Mutasyona uğratılacak kromozomun indeksini girin: ";
            cin >> kromozomIndex;
            selectedKromozom = dna.getKromozom(kromozomIndex);  // Kromozom seçimi

            if (selectedKromozom) {
                // Kullanıcıdan gen indeksini alıyoruz
                cout << "Mutasyona uğratılacak genin indeksini girin: ";
                cin >> geneIndex;
                selectedKromozom->mutate(geneIndex);  // Mutasyon işlemini gerçekleştir
            } else {
                cout << "Geçersiz kromozom!" << endl;
            }

            break;

        case 3:  // Otomatik İşlemler
             cout << "Otomatik işlemler başlatılıyor..." << endl;
            otomatikIslemler("Islemler.txt", dna);  // Dosyadaki işlemleri uyguluyoruz
            break;

        case 4:  // Ekrana yazma işlemi
            cout << "Ekrana yaz işlemi seçildi." << endl;
            dna.printDNA();  // DNA'yı yazdır
            break;

        case 5:  // Çıkış
            cout << "Çıkış yapılıyor..." << endl;
            break;

        default:
            cout << "Geçersiz seçim, lütfen tekrar deneyin." << endl;
            break;
    }
}
