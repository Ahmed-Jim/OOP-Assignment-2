//
// Created by zizo on 01/11/18.
//

#ifndef A2_T3_BIGDECIMAL_H
#define A2_T3_BIGDECIMAL_H


#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
class BigDecimal {
private:
    vector<int> Num; // most left cell is the sign  [- => 1][+ => 0]
    void Convert(string);
    void Convert(int);
    bool meBigger(BigDecimal &obj);
    BigDecimal addSamSign(BigDecimal &obj2);
    BigDecimal addDiffSign(BigDecimal &obj);
public:
    BigDecimal();
    BigDecimal(int x);
    BigDecimal(string);
    vector<int> getNum() ;
    void setNum(const vector<int> &Num);
    BigDecimal operator+ (BigDecimal &obj);
    BigDecimal operator- (BigDecimal &obj);
    friend ostream & operator << (ostream& out, BigDecimal &obj);
};



#endif //A2_T3_BIGDECIMAL_H
