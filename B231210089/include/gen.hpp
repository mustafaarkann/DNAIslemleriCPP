/*     
* @file  gen.hpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/



#ifndef GEN_HPP
#define GEN_HPP

#include <string>

class Gen {
private:
    char value;  // Gen'in değeri (char türünde)

public:
    Gen(char geneValue);  // Yapıcı
    char getValue() const;  // Gen değerini al
    void setValue(char newValue);  // Gen değerini değiştir
};

#endif
