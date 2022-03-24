#include "Task1.h"
Matrix::Matrix(const int num_rows, const int num_columns) {
    if(num_columns>=0 && num_rows>=0) {
        rows = num_rows;
        columns = num_columns;
    }
    else{
        throw std::out_of_range("rows and columns must be more or equal to 0");
    }
}

int Matrix::GetNumColumns() {
    return columns;
}

int Matrix::GetNumRows() {
    return rows;
}

void Matrix::Reset(const int num_rows, const int num_columns) {
    if(num_columns >=0 && num_rows>=0) {
        rows = num_rows;
        columns = num_columns;
        val.resize(rows);
        for(int i = 0 ; i < rows;++i) {
            val[i].resize(columns);
        }
    }
    else{
        throw std::out_of_range("rows and columns must be more or equal to 0");
    }
}

int &Matrix::At(const int num_rows, const int num_columns) {
    if(num_columns < columns && num_rows< rows && num_columns>=0 && num_rows>=0) {

        return val[num_rows][num_columns];
    }
    else {throw std::out_of_range("index of rows and columns must be in range");}
}

int Matrix::At(const int num_rows, const int num_columns) const {
    if(num_columns < columns && num_rows< rows && num_columns>=0 && num_rows>=0) {

        return val[num_rows][num_columns];
    }
    else {throw std::out_of_range("index of rows and columns must be in range");}
}
