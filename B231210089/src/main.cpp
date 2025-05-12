/*     
* @file  main.cpp
* @description   
* @course  1-B
* @assignment  1.Ödev
* @date  27.11.2024
* @author  Mustafa Arkan - mustafaarkan004@gmail.com
*/


#include <iostream>
#include <fstream>
#include <string>
#include "kromozom.hpp"
#include "gen.hpp"
#include "dna.hpp"
#include "menu.hpp"

using namespace std;
DNA dna;
int main() {
    ifstream file("dna.txt");

    if (!file.is_open()) {
        cout << "Dosya açılamadı!" << endl;
        return 1;
    }

    string line;
    DNA dna;

    while (getline(file, line)) {
        Kromozom* kromozom = new Kromozom();

        for (char geneValue : line) {
            Gen* gen = new Gen(geneValue);
            kromozom->addGen(*gen);
        }

        dna.addKromozom(kromozom);
    }

    file.close();

    //dna.printDNA();

    int secim;
    do {
        menuyuGoster();
        cin >> secim;
        secimIsle(secim, dna);
    } while (secim != 5);

    return 0;
}
