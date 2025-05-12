/*     
* @file  kromozom.cpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#include "kromozom.hpp"
#include <iostream>
#include "dna.hpp"
using namespace std;

extern DNA dna;

// Node yapıcı fonksiyonu
Node::Node(const Gen& geneValue) : gen(geneValue), next(nullptr) {}

Node::~Node() {
    // Node sınıfında ek bir bellek yönetimi gerekmez
}

// Yapıcı
Kromozom::Kromozom() : head(nullptr), tail(nullptr), size(0) {}

// Destrüktör
Kromozom::~Kromozom() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void Kromozom::addGen(const Gen& value) {
    // Eğer gen değeri boş değilse ekle
    if (value.getValue() != ' ') {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;  // İlk eleman, head ve tail aynı olur
        } else {
            tail->next = newNode;   // Son elemana yeni node ekleriz
            tail = newNode;         // Tail güncellenir
        }
        size++;
    }
    // Boş genler eklenmeyecek, bu yüzden burada işlem yapılmaz
}

// Kromozomdaki gen sayısını döndürür
int Kromozom::getSize() const {
    return size;
}

// Kromozomu yazdıran fonksiyon
void Kromozom::printKromozom() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->gen.getValue() << " ";
        current = current->next;
    }
    cout << endl;
}





void Kromozom::crossover(Kromozom& other) {
    int size1 = getSize();
    int size2 = other.getSize();
    
    // Ortada bir gen varsa atlanması için index hesaplamaları
    int mid1 = size1 / 2;
    int mid2 = size2 / 2;

    // Yeni kromozomu oluşturuyoruz
    Kromozom* newKromozom = new Kromozom();
    
    // Eğer gen sayısı tekse, ortadaki gen atlanacak
    if (size1 % 2 != 0) {
        mid1 = mid1 + 1;
    }

    if (size2 % 2 != 0) {
        mid2 = mid2 + 1;
    }

    // Çaprazlama işlemi
    splitAndMerge(this, &other, newKromozom, mid1, mid2);
    
    //this->addKromozomToList(newKromozom);

    // Yeni kromozomu DNA'ya eklemek istenirse, aşağıdaki kod kullanılabilir:
    
     dna.addKromozom(newKromozom); // dna, DNA sınıfına ait bir nesne olmalı
      // Yeni kromozomları dosyaya kaydediyoruz
    //dna.saveToFile("dna.txt");  // Yeni kromozomlar 'dna.txt' dosyasına kaydedilir
    cout << "Yeni kromozom başarıyla eklendi." << endl;
}

void Kromozom::splitAndMerge(Kromozom* kromozom1, Kromozom* kromozom2, Kromozom* newKromozom, int mid1, int mid2) {
    // İlk kromozomun sol yarısını ekleyin
    Node* current1 = kromozom1->head;
    for (int i = 0; i < mid1; ++i) {
        newKromozom->addGen(current1->gen);
        current1 = current1->next;
    }

    // İkinci kromozomun sağ yarısını ekleyin
    Node* current2 = kromozom2->head;
    for (int i = mid2; i < kromozom2->getSize(); ++i) {
        newKromozom->addGen(current2->gen);
        current2 = current2->next;
    }
}

void Kromozom::mutate(int index) {
    // Hatalı indeks kontrolü
    if (index < 0 || index >= size) {
        cout << "Geçersiz indeks!" << endl;
        return;
    }

    // Seçilen genin bulunduğu node'a ulaşalım
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;  // İstenilen indisteki node'a ulaşana kadar ilerleyelim
    }

    // Mutasyon işlemi: Seçilen genin değerini 'X' ile değiştiriyoruz
    current->gen.setValue('X');  // Genin değerini 'X' yapıyoruz

     //this->addKromozomToList(*this);  // Mevcut kromozomu tekrar ekliyoruz
    
    cout << "Mutasyon işlemi gerçekleşti. Seçilen gen: X" << endl;
}


