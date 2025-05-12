/*     
* @file  dna.cpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#include "dna.hpp"
#include <iostream>
#include <fstream>
using namespace std;

// Yapıcı
DNA::DNA() : head(nullptr), tail(nullptr), size(0) {}

// Destrüktör
DNA::~DNA() {
    Kromozom* current = head;
    while (current != nullptr) {
        Kromozom* temp = current;
        current = current->next;
        delete temp;
    }
}

// Kromozom ekleme fonksiyonu
void DNA::addKromozom(Kromozom* kromozom) {
    if (tail == nullptr) {
        head = tail = kromozom;
    } else {
        tail->next = kromozom;
        tail = kromozom;
    }
    size++;
}

// DNA'yı yazdıran fonksiyon
void DNA::printDNA() const
 {
    
    cout << "Bağlı liste testi tamamlandı." << endl;*/

    // Ekrana yazdırma işlemi
    Kromozom* current = head;
    cout << "Kromozom: ";  // Kromozom başlığını ekliyoruz
    while (current != nullptr) {
        Node* currentGen = current->getHead();
        bool firstGenPrinted = false;  // İlk küçük gen yazdırıldığında bunu işaret edecek

        //cout << "Kromozom: ";  // Kromozom başlığını ekliyoruz
        // Sağdan sola doğru giderek küçük gen arama işlemi
        while (currentGen != nullptr) {
            // Eğer daha önce küçük gen yazdırılmamışsa
            if (!firstGenPrinted) {
                // Eğer bu gen, kromozomun ilk geninden küçükse yazdır
                if (currentGen->gen.getValue() < current->getHead()->gen.getValue()) {
                    cout << currentGen->gen.getValue() << " ";
                    firstGenPrinted = true;  // Küçük gen yazdırıldı, artık diğer genler yazdırılmayacak
                }
            }

            // Sağdaki sonrasını kontrol et
            currentGen = currentGen->next;
        }

        // Eğer küçük bir gen bulunmazsa, ilk gen yazdırılacak
        if (!firstGenPrinted) {
            cout << current->getHead()->gen.getValue() << " ";
        }

        cout << " ";  // Her kromozomun ardından bir boşluk bırakıyoruz 
        current = current->next;  // Sonraki kromozoma geçiyoruz
    }
    cout << endl;
}



Kromozom* DNA::getKromozom(int index) {
    if (index < 0 || index >= size) {
        cout << "Geçersiz indeks!" << endl;
        return nullptr;  // Hatalı indeks, nullptr döner
    }

    Kromozom* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;  // Bağlı listeyi takip ederek belirtilen indeksi bul
    }
    return current;  // İstenilen kromozomu döndür
}

void DNA::ekleKromozom(Kromozom* yeniKromozom) {
    if (head == nullptr) {
        head = yeniKromozom;
        tail = yeniKromozom;
    } else {
        tail->next = yeniKromozom;  // setNext yerine doğrudan next işaretçisini ayarlıyoruz
        tail = yeniKromozom; // Tail güncelleniyor
    }
    size++; // DNA boyutunu artırıyoruz
}


