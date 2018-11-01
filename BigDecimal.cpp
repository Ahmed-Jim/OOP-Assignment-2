//
// Created by zizo on 01/11/18.
//

#include <sstream>
#include "BigDecimal.h"


BigDecimal::BigDecimal(){
    this->Num = vector<int>();
}
BigDecimal::BigDecimal(string x){
    this->Num = vector<int>();
    Convert(x);
}
BigDecimal::BigDecimal(int x){
    this->Num = vector<int>();
    Convert(x);
}
void BigDecimal::Convert(string x) {

    if(x[0] == '-'){
        Num.push_back(1);
    } else{
        Num.push_back(0);
    }
    string  c;
    for (int i = 0; i <x.length() ; ++i) {
        if (x[i] == '+' || x[i] == '-') continue;
        c =x[i];
        Num.push_back(atoi(c.c_str()));
    }
}
void BigDecimal::Convert(int x) {
    if(x<0){
        this->Num.push_back(1);
        x *=-1;
    } else{
        this->Num.push_back(0);
    }
    string tmp;
    stringstream ss;
    ss << x;
    tmp = ss.str();
    for (int i = 0; tmp[i] != '\0'; i++) {
        this -> Num.push_back(tmp[i]-'0');
    }
}
vector<int> BigDecimal::getNum() {
    return Num;
}
BigDecimal BigDecimal::addSamSign(BigDecimal &obj2) {
    BigDecimal result = BigDecimal();
    vector<int> tmpV = obj2.getNum(), resV;
    int size1 = this->Num.size(), size2 = tmpV.size(), sum, carry = 0;
    if (size1 >= size2) {
        int tmp =size1 -size2;
        resV.resize(size1);
        resV[0] = tmpV[0];
        for (int i = size1-1; i > 0; --i) {
            sum = this->Num[i] +( (i-tmp <= 0) ? 0 : tmpV[i-tmp]) + carry;
            carry = sum / 10;
            resV[i] = sum % 10;
        }
    } else {
        int tmp = size2-size1;
        resV.resize(size2);
        resV[0] = tmpV[0];
        for (int i = size2-1; i > 0; --i) {
            sum = tmpV[i] + ((i-tmp <= 0) ? 0 : this->Num[i-tmp]) + carry;
            carry = sum / 10;
            resV[i] = sum % 10;
        }
    }
    result.setNum(resV);
    return result;
}
BigDecimal BigDecimal::addDiffSign(BigDecimal &obj){
    BigDecimal result = BigDecimal();
    vector <int> resV= vector<int>(),meV= this->Num,objV =obj.getNum();
    int sub ,loan=0,tmp;
    if (this->meBigger(obj)){
        tmp = meV.size() - objV.size();
        resV.resize(meV.size());
        resV[0] =meV[0];
        for (int i = meV.size()-1; i>0 ; --i) {
            sub =meV[i] - ((i-tmp <= 0) ? 0 : objV[i-tmp]) - loan;
            if (sub < 0){
                sub += 10;
                loan = 1;
            } else{
                loan =0;
            }
            resV[i] = sub;
        }
    }else{
        tmp =  objV.size() - meV.size() ;
        resV.resize(objV.size());
        resV[0] =objV[0];
        for (int i = objV.size()-1; i >0 ; --i) {
            sub =objV[i] - ((i-tmp <= 0) ? 0 : meV[i-tmp]) - loan;
            if (sub < 0){
                sub += 10;
                loan = 1;
            } else{
                loan =0;
            }

            resV[i] = sub;
        }
    }

    result.setNum(resV);
    return result;
}
bool BigDecimal::meBigger(BigDecimal &obj){
    vector<int> tmpV = obj.getNum();
    int size1 = this->Num.size(), size2 = tmpV.size();
    if ( size1>size2 ){
        return true;
    }else if (size1 < size2){
        return false;
    }else{
        bool result = true;
        for (int i = 1; i <size1 ; ++i) {
            if (this->Num[i] < tmpV[i]) return false;
        }
        return true;
    }
}
BigDecimal BigDecimal::operator+(BigDecimal &obj) {
    BigDecimal result;
    if (this->Num[0] == obj.getNum()[0]){
        result= this->addSamSign(obj);
    }else{
        result = this->addDiffSign(obj);
    }

    return result;
}
BigDecimal BigDecimal::operator-(BigDecimal &obj) {
    vector <int> tmp= obj.getNum();
    tmp[0] =(tmp[0] == 0)? 1 :0 ;
    obj.setNum(tmp);
    BigDecimal result;
    if (this->Num[0] == obj.getNum()[0]){
        result= this->addSamSign(obj);
    }else{
        result = this->addDiffSign(obj);
    }
    tmp= obj.getNum();
    tmp[0] =(tmp[0] == 0)? 1 :0 ;
    obj.setNum(tmp);
    return result;
}
ostream & operator << (ostream& out, BigDecimal &obj) {
    vector<int>Num =obj.getNum();
    if(Num[0]!=0)
        out<<"-";
    bool start=false;
    for (int i = 1; i <Num.size() ; ++i) {
        if(Num[i] != 0 or start) {
            start =true;
            out<<Num[i];
        }
    }
    return out;
}
void BigDecimal::setNum(const vector<int> &Num) {
    BigDecimal::Num = Num;
}

