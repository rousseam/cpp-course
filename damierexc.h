#ifndef DAMIEREXC_H
#define DAMIEREXC_H
#include <iostream>

class DamierExc
{
public:
    DamierExc(int m, int n, int value);
    DamierExc(const DamierExc &dam);

    DamierExc& operator=(const DamierExc &dam);
    DamierExc& operator+=(const DamierExc &dam);
    DamierExc& operator+=(const int &value);
    DamierExc& operator+(const DamierExc &dam);
    DamierExc& operator+(const int &value);
    friend std::ostream& operator<<(std::ostream &sortie, const DamierExc &dam);

    ~DamierExc();

    void Redim(int m, int n);
    void Init(int value);
    void Set(int lign, int column, int value);
    void Print();

private:
    int nb_lignes, nb_colonnes, borne;
    int **damier;
};

#endif // DAMIEREXC_H
