//
// Created by spac on 4/23/23.
//

#include "UI.h"

UI::UI() {

};

UI::~UI() {

};

void UI::adauga(char v[6][100]) {
    int suma = 0;
    for(int i =  0; i < strlen(v[1]); i++)
        suma = suma*10 + int(v[1][i] - '0');
    service.adauga(suma, v[2], v[3]);
}

int UI::inInt(char v[100]) {
    int nr = 0;
    for(int i =  0; i < strlen(v); i++)
        nr = nr*10 + int(v[i] - '0');
    return nr;
}

void UI::insereaza(char v[6][100]) {
    int suma = inInt(v[2]), zi = inInt(v[1]);
    service.inserare(suma, zi, v[3],v[4]);
}

void UI::delZiua(char v[6][100]) {
    int zi = inInt(v[1]);
    service.delZiua(zi);
}

void UI::delTip(char v[6][100]) {
    service.delTip(v[1]);
}

void UI::delZiua2(char v[6][100]) {
    int zi1 = inInt(v[1]), zi2 = inInt(v[3]);
    service.delZiua(zi1,zi2);
}

void UI::modify(char v[6][100]) {
    int suma = inInt(v[5]), zi = inInt(v[1]);
    service.modify(suma,zi, v[2], v[3]);
}

void UI::afisare(Tranzactie* a, int nr) {
    for(int i = 0; i < nr; i++)
        cout << endl << "ziua: " << a[i].getZiua() << " suma:  " << a[i].getSuma() << " tip: " << a[i].geTip() << " descriere: " << a[i].getDescriere();
}

void UI::GetByTip(char v[6][100]) {

    std::vector<Tranzactie> out = service.getByTip(v[1]);
    for(int i = 0; i < out.size(); i++)
        cout << endl << "ziua: " << out[i].getZiua() << " suma:  " << out[i].getSuma() << " tip: " << out[i].geTip() << " descriere: " << out[i].getDescriere();
}

void UI::GetByTipandSum(char v[6][100]) {
    int suma = inInt(v[2]);
    std::vector<Tranzactie> out = service.getByTipandSum(v[1], suma);
    for(int i = 0; i < out.size(); i++)
        cout << endl << "ziua: " << out[i].getZiua() << " suma:  " << out[i].getSuma() << " tip: " << out[i].geTip() << " descriere: " << out[i].getDescriere();
}

void UI::getGreaterSuma(char v[6][100]) {
    int suma = inInt(v[2]);
    std::vector<Tranzactie> out = service.getGreaterSuma(suma);
    for(int i = 0; i < out.size(); i++)
        cout << endl << "ziua: " << out[i].getZiua() << " suma:  " << out[i].getSuma() << " tip: " << out[i].geTip() << " descriere: " << out[i].getDescriere();
}

void UI::getBellowSuma(char v[6][100]) {
    int suma = inInt(v[2]);
    std::vector<Tranzactie> out = service.getBellowSuma(suma);
    for(int i = 0; i < out.size(); i++)
        cout << endl << "ziua: " << out[i].getZiua() << " suma:  " << out[i].getSuma() << " tip: " << out[i].geTip() << " descriere: " << out[i].getDescriere();

}

void UI::getBySuma(char v[6][100]) {
    int suma = inInt(v[2]);
    std::vector<Tranzactie> out = service.getBySuma(suma);
    for(int i = 0; i < out.size(); i++)
        cout << endl << "ziua: " << out[i].getZiua() << " suma:  " << out[i].getSuma() << " tip: " << out[i].geTip() << " descriere: " << out[i].getDescriere();

}

void UI::getSold(char v[6][100]) {
    int zi = inInt(v[2]);
    cout << "sold: " << service.getSold(zi);
}

void UI::getSumaByTip(char v[6][100]) {
    cout << "suma: "<< service.getSumaByTip(v[1]);
}

void UI::getMax(char v[6][100]) {
    int zi = inInt(v[2]);
    cout << "suma: " << service.maxim(v[1],zi);
}

void UI::getMin(char v[6][100]) {
    int zi = inInt(v[2]);
    cout << "suma: " << service.minim(v[1],zi);
}

void UI::filtrareTip(char v[6][100]) {
    service.filtrareTip(v[1]);
}

void UI::filtrareTipSuma(char v[6][100]) {
    int suma = inInt(v[2]);
    service.filtrareTipSuma(v[1], suma);
}

void UI::menu() {
    while(true)
    {
        cout << endl << "Introduceti comanda: ";
        char s[100], v[7][100];
        cin.getline(s, 100);
        int nr = 0;
        char* p = strtok(s, " ");
        while(p != NULL)
        {
            strcpy(v[nr++],p);
            p = strtok(NULL, " ");
        }
        if(strcmp(v[0], "adauga") == 0) {
            adauga(v);
        }
        else if(strcmp(v[0], "insereaza") == 0) {
            insereaza(v);
        }
        else if(strcmp(v[0], "eliminare") == 0) {
            if(nr == 2){
                if(isdigit(v[1][0])) {
                    delZiua(v);
                }
                else
                    delTip(v);
            }
            else
                if(nr == 4) {
                    delZiua2(v);
                }
        }
        else if(strcmp(v[0], "inlocuire") == 0)
                modify(v);
        else if(strcmp(v[0], "listeaza") == 0){
            if(nr == 1) {
                afisare(service.getAll(),service.getSize());
            }
            else if(nr == 2) {
                GetByTip(v);
            }
            else if(strcmp(v[1],">") == 0) {
                getGreaterSuma(v);
            }
            else if(strcmp(v[1],"<") == 0) {
                getBellowSuma(v);
            }
            else if(strcmp(v[1],"sol") == 0) {
                getSold(v);
            }
        }
        else if(strcmp(v[0], "sum") == 0)
        {
            getSumaByTip(v);
        }
        else if(strcmp(v[0], "max") == 0)
        {
            getMax(v);
        }
        else if(strcmp(v[0], "min") == 0)
        {
            getMin(v);
        }
        else if(strcmp(v[0], "filtru") == 0)
        {
            if(nr == 2)
                GetByTip(v);
            else if(nr == 3)
                GetByTipandSum(v);
        }
        else if(strcmp(v[0], "undo") == 0)
        {
            service.Getundo();
        }
        else
            cout << "comanda invalida";
    }
}



