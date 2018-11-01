#ifndef A2_T1_MATRIX_H
#define A2_T1_MATRIX_H

#include <iostream>
#include <valarray>
#include <iomanip>

using namespace std;

class Matrix {
private:
    valarray<int> data;
    int row, col;
public:
    Matrix();
    Matrix(int, int);
    Matrix(int, int,int []);

    int get(int, int);
    void set(int, int, int);
    int getRow(){ return this->row;}
    int getCol(){ return this->col;}

    bool isSquare();
    bool isSymetric();
    bool isIdentity();
    Matrix transpose();

    Matrix operator+  (Matrix);
    Matrix operator-  (Matrix);
    Matrix operator*  (Matrix);
    Matrix operator+  (int);
    Matrix operator-  (int);
    Matrix operator*  (int);
    Matrix operator+=  (Matrix);
    Matrix operator-=  (Matrix);
    Matrix operator*=  (Matrix);
    Matrix operator+=  (int);
    Matrix operator-=  (int);
    Matrix operator*=  (int);
    Matrix operator++();
    Matrix operator--();
    bool operator==(Matrix);
    bool operator!=(Matrix);


    friend ostream &operator<< (ostream&, Matrix&);
    friend istream &operator>>(istream& ,Matrix&);
};


#endif //A2_T1_MATRIX_H
