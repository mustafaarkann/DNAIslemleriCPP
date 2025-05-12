/*     
* @file  dna.hpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#ifndef DNA_HPP
#define DNA_HPP

#include "kromozom.hpp"

class DNA {
private:
    Kromozom* head;
    Kromozom* tail;
    int size;

public:
    DNA();  // Yapıcı
    ~DNA();  // Yıkıcı

    void addKromozom(Kromozom* kromozom);  // Yeni kromozom ekle
    void printDNA() const;  // DNA'yı yazdır
     Kromozom* getKromozom(int index);  // Kromozom alma fonksiyonu
     void ekleKromozom(Kromozom* yeniKromozom); // Yeni kromozom eklemek için fonksiyon bildirimi
    //void saveToFile(const std::string& filename);
};

#endif
