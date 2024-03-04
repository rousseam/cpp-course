#include "damierexc.h"

DamierExc::DamierExc(int m, int n, int value) {
    damier = NULL;
    Redim(m, n);
    Init(value);
}

DamierExc::DamierExc(const DamierExc &dam) {
    damier = NULL;
    Redim(dam.nb_lignes, dam.nb_colonnes);
    for (int i=0; i<nb_lignes; i++) {
        for (int j=0; j<nb_colonnes; j++) {
            damier[i][j] = dam.damier[i][j];
        }
    }
}

DamierExc& DamierExc::operator=(const DamierExc &dam) {
    if (this != &dam) { // auto-référence
        delete [] damier;
        Redim(dam.nb_lignes, dam.nb_colonnes);
        for (int i=0; i<nb_lignes; i++) {
            for (int j=0; j<nb_colonnes; j++) {
                damier[i][j] = dam.damier[i][j];
            }
        }
    }
    return *this;
}

DamierExc& DamierExc::operator+(const  DamierExc &dam) {
    if((nb_lignes != dam.nb_lignes) || (nb_colonnes != dam.nb_colonnes)) {
        std::cout << "Erreur : les deux damiers ne sont pas de la même taille" << std::endl;
    }
    else {
        for (int i=0; i<nb_lignes; i++) {
            for (int j=0; j<nb_colonnes; j++) {
                damier[i][j] += dam.damier[i][j];
            }
        }
    }
    return *this;
}

DamierExc& DamierExc::operator+=(const  int &value) {
    for (int i=0; i<nb_lignes; i++) {
        for (int j=0; j<nb_colonnes; j++) {
            damier[i][j] += value;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream &sortie, const DamierExc &dam) {
    for (int i=0; i<dam.nb_lignes; i++) {
        sortie << '[';
        for (int j=0; j<dam.nb_colonnes; j++) {
            sortie << dam.damier[i][j] << ' ';
        }
        sortie << ']' << std::endl;
    }
    sortie << std::endl;
    return sortie;
}

DamierExc::~DamierExc() {
    if (damier != NULL) {
        for (int i=0; i<nb_lignes; i++) {
            delete [] damier[i];
        }
        delete [] damier;
    }
    damier = NULL;
}

void DamierExc::Init(int value) {
    for (int i=0; i<nb_lignes; i++) {
        for (int j=0; j<nb_colonnes; j++) {
            damier[i][j] = value;
        }
    }
}

void DamierExc::Set(int lign, int column, int value) {
    if (lign>=0 && lign<nb_lignes && column>=0 && column<nb_colonnes) {
        damier[lign][column] = value;
    }
    else
        std::cout << "Erreur: indices en dehors de la plage adressable" << std::endl;
}

void DamierExc::Print() {
    for (int i=0; i<nb_lignes; i++) {
        std::cout << '[';
        for (int j=0; j<nb_colonnes; j++) {
            std::cout << damier[i][j] << ' ';
        }
        std::cout << ']' << std::endl;
    }
    std::cout << std::endl;
}

void DamierExc::Redim(int m, int n) {
    if (damier != 0) {
        for (int i=0; i<nb_lignes; i++) {
            delete [] damier[i];
        }
        delete [] damier;
    }

    nb_lignes = m;
    nb_colonnes = n;

    damier = new int*[nb_lignes];

    for (int i=0; i<nb_lignes; i++) {
        damier[i] = new int[nb_colonnes];
    }
    Init(0);
}
