/*     
* @file  kromozom.hpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#ifndef KROMOZOM_H
#define KROMOZOM_H
#include "gen.hpp"



// Node sınıfı, bağlı listedeki her elemanı temsil eder
// Node sınıfı, her bir genin tutulduğu düğüm olacak
class Node {
public:
    Gen gen;  // Gen nesnesi
    Node* next;

    Node(const Gen& geneValue);  // Node yapıcı
    ~Node();  // Node destrüktörü
};


class Kromozom {
public:
    Node* head;
    Node* tail;
    int size;



     Kromozom* next;   // Sonraki kromozomu işaret eden gösterici

    Kromozom();  // Yapıcı
    ~Kromozom();  // Destrüktör

    void addGen(const Gen& value);  // Gen ekleme fonksiyonu
    int getSize() const;  // Kromozom boyutu
    void printKromozom() const;  // Kromozomu yazdıran fonksiyon
    void mutate(int index);  // Mutasyon fonksiyonu
    void crossover(Kromozom& other);  // Çaprazlama fonksiyonu
    void splitAndMerge(Kromozom* kromozom1, Kromozom* kromozom2, Kromozom* newKromozom, int mid1, int mid2);  // Yardımcı fonksiyon
     Node* getHead() const { return head; }
    //void addKromozomToList(Kromozom& other);

};

#endif
