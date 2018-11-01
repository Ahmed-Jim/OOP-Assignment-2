#include "Matrix.h"

Matrix::Matrix(){
    this->row = 0;
    this->col = 0;
    this->data =  valarray<int>();
}
Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;
    this->data =  valarray<int>();
}
Matrix::Matrix(int row,int col,int *data) {
    this->row = row;
    this->col = col;
    this->data =  valarray<int>(data, row*col);
}
int Matrix::get(int row, int col) {
    return this->data[row*this->col + col];
}
void Matrix::set(int row, int col, int x) {
    this->data[row*this->col + col] = x;
}
Matrix Matrix::operator*(int x) {
    int tmp[this->row* this->col];
    for (int i = 0; i < this->row*this->col; ++i) {
        tmp[i] = this->data[i]*x;
    }
    return Matrix(row,col,tmp);
}
Matrix Matrix::operator*=(int x) {
    for (int i = 0; i < this->row*this->col; ++i) {
         this->data[i]*=x;
    }
    return *(this);
}
Matrix Matrix::operator*(Matrix mat) {
    if(this->col != mat.row)
        throw "Error in MultiPlying: Matrix[1].colm != Matrix[2].row";
    int tmp[this->row* mat.col];
    int sum;
    for (int row = 0; row < this->row; ++row) {
        for (int colm = 0; colm < mat.col; ++colm) {
            sum = 0;
            for (int k = 0; k < this->col; ++k) {
                sum += this->get(row,k) * mat.get(k,colm);
            }
            tmp[row*mat.col + colm] = sum;
        }
    }
    return Matrix(row,col,tmp);
}

Matrix Matrix::operator*=(Matrix mat) {
    *this = *this * mat;
    return *this;
}

Matrix Matrix::operator+(int x) {
    int tmp[this->row* this->col];
    for (int i = 0; i < this->row*this->col; ++i) {
        tmp[i] = this->data[i]+x;
    }
    return Matrix(row,col,tmp);
}
Matrix Matrix::operator+(Matrix mat) {
    if(this->row != mat.row
        or this->col != mat.col)
        throw "Error in adding: Matrix[1]'s dimensions mismatch Matrix[2]'s";
    int tmp[this->row* this->col];
    for (int i = 0; i < this->row*this->col; ++i) {
        tmp[i] = this->data[i] + mat.data[i];
    }
    return Matrix(row,col,tmp);
}
Matrix Matrix::operator++() {
    for (int i = 0; i < this->row * this->col; ++i) {
        this->data[i] += 1;
    }
    return *this;
}

Matrix Matrix::operator+=(int x) {
    *this = *this + x;
    return *this;
}
Matrix Matrix::operator+=(Matrix mat) {
    *this = *this + mat;
    return *this;
}

Matrix Matrix::operator-(int x) {
    int tmp[this->row* this->col];
    for (int i = 0; i < this->row*this->col; ++i) {
        tmp[i] = this->data[i]-x;
    }
    return Matrix(row,col,tmp);
}
Matrix Matrix::operator-(Matrix mat) {
    if(this->row != mat.row
       or this->col != mat.col)
        throw "Error in subtracting: Matrix[1]'s dimensions mismatch Matrix[2]'s";
    int tmp[this->row* this->col];
    for (int i = 0; i < this->row*this->col; ++i) {
        tmp[i] = this->data[i] - mat.data[i];
    }
    return Matrix(row,col,tmp);
}

Matrix Matrix::operator--() {
    for (int i = 0; i < this->row * this->col; ++i) {
        this->data[i] -= 1;
    }
    return *this;
}

Matrix Matrix::operator-=(int x) {
    *this = *this - x;
    return *this;
}
Matrix Matrix::operator-=(Matrix mat) {
    *this = *this - mat;
    return *this;
}

bool Matrix::operator==(Matrix mat) {
    if(this->row != mat.getRow()
        or this->col != mat.getCol())
        return false;
    for (int i = 0; i < mat.getCol()*mat.getRow(); ++i) {
        if(this->data[i] != mat.data[i]) return false;
    }
    return true;
}

bool Matrix::operator!=(Matrix matrix) {
    return not(*this == matrix);
}

bool Matrix::isSquare() {
    return this->row == this->col;
}
bool Matrix::isSymetric() {
    if(not isSquare()) return false;
    for (int row = 0; row < this->row; ++row) {
        for(int col = 0; col < this->col; ++col){
            if( this->get(row,col)
                != this->get(col,row))
                return false;
        }
    }
    return true;
}

bool Matrix::isIdentity() {
    if(not isSquare())
        return false;
    for (int row = 0; row <this->row; ++row) {
        for (int col = 0; col < this->col; ++col) {
            if(row == col and
                this->get(row,col) != 1)
                return false;
            else if(row != col and
                this->get(row,col)!=0)
                return false;
        }
    }
    return true;
}
Matrix Matrix::transpose() {
    Matrix mat = Matrix(this->col,this->row);
    for (int row = 0; row < this->row; ++row) {
        for (int col = 0; col < this->col; ++col) {
            mat.set(col,row,this->get(row,col));
        }
    }
    return mat;
}
ostream &operator<< (ostream& out, Matrix& mat){
    for (int row = 0; row < mat.getRow(); ++row) {
        for (int colm = 0; colm < mat.getCol(); ++colm) {
            out<<mat.get(row,colm)<<" ";
        }
        out<<endl;
    }
    return out;
}

istream &operator>>(istream& in,Matrix& matrix){
    int rows,cols,*data,x;
    cout<<"Please Enter number of Rows"<<endl;
    cin>>rows;
    cout<<"Please Enter number of colms"<<endl;
    cin>> cols;
    cout<<"Now Enter the"<<rows*cols<<"one by one"<<endl;
    data = new int [rows * cols];
    for (int row = 0; row < rows; ++row) {
        for (int colm = 0; colm < cols; ++colm) {
            in>>x;
            data[row*rows+colm] = x;
        }
    }
    matrix = Matrix(rows,cols,data);
    delete data;
    return in;
}