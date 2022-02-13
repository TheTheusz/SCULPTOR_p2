#include "sculptor.h"
#include "FiguraGeometrica.h"
#include "leitor.h"
#include <vector>

int main() {
	
    Sculptor *saturno;
    leitor l;
    vector<FiguraGeometrica*> figuras;

    figuras = l.interpretador("sculptor.txt");

    saturno = new Sculptor(l.getDimx(), l.getDimy(), l.getDimz());

    for (int i = 0; i < figuras.size(); i++) {
        figuras[i]->draw(*saturno);
    }

    saturno->writeOFF((char*)"saturno.off");

    for (int i = 0; i < figuras.size(); i++) { // libera os new dos draw
        delete figuras[i];
    }

    delete saturno;
    return 0;
}