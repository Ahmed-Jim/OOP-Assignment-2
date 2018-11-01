#include <iostream>
#include "BigDecimal.h"
using  namespace std;

void testBigDecimal(){
    BigDecimal bigDecimal= BigDecimal(1213);
    BigDecimal bigDecimal2= BigDecimal(1312);
    BigDecimal bigDecimal3= bigDecimal + bigDecimal2;
    cout<<"firstNumber: "<<bigDecimal<<"\tsecondNumber: "<<bigDecimal2<<"\nexpected: 2525\t";
    cout<<"result: "<<bigDecimal3<<"\t[Sum]"<<endl;
    cout<<"===============================================\n";
    bigDecimal =BigDecimal("2002");
    bigDecimal2 = BigDecimal("-1000");
    bigDecimal3 = bigDecimal + bigDecimal2;
    cout<<"firstNumber: "<<bigDecimal<<"\tsecondNumber: "<<bigDecimal2<<"\nexpected: 1002\t";
    cout<<"result: "<<bigDecimal3<<"\t[Sum]"<<endl;
    cout<<"===============================================\n";
    bigDecimal =BigDecimal("-2002");
    bigDecimal2 = BigDecimal("-1000");
    bigDecimal3 = bigDecimal + bigDecimal2;
    cout<<"firstNumber: "<<bigDecimal<<"\tsecondNumber: "<<bigDecimal2<<"\nexpected: -3002\t";
    cout<<"result: "<<bigDecimal3<<"\t[Sum]"<<endl;
    cout<<"===============================================\n";
    bigDecimal =BigDecimal("-2002");
    bigDecimal2 = BigDecimal("-1000");
    bigDecimal3 = bigDecimal - bigDecimal2;
    cout<<"firstNumber: "<<bigDecimal<<"\tsecondNumber: "<<bigDecimal2<<"\nexpected: -1002\t";
    cout<<"result: "<<bigDecimal3<<"\t[Sub]"<<endl;
    cout<<"===============================================\n";
    bigDecimal =  BigDecimal("1122112211221122");
    bigDecimal2 = BigDecimal("-1122112211221120");
    bigDecimal3 = bigDecimal - bigDecimal2;
    cout<<"firstNumber: "<<bigDecimal<<"\tsecondNumber: "<<bigDecimal2<<"\nexpected: 2244224422442242\t";
    cout<<"result: "<<bigDecimal3<<"\t[Sub]"<<endl;
}

int main() {
    testBigDecimal();
    return 0;
}