/*     
* @file  gen.cpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#include "gen.hpp"

// Yapıcı
Gen::Gen(char geneValue) : value(geneValue) {}

// Gen değerini al
char Gen::getValue() const {
    return value;
}

// Gen değerini değiştir
void Gen::setValue(char newValue) {
    value = newValue;
}
