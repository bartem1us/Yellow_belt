//
// Created by bartem1us on 23.03.2022.
//

#ifndef YELLOW_BELT_TASK1_H
#define YELLOW_BELT_TASK1_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <type_traits>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> val;
    int columns;
    int rows;
public:
    Matrix() : columns(0), rows(0) {};

    Matrix(int num_rows, int num_columns);

    void Reset(int num_rows, int num_columns);

    int &At(int num_rows, int num_columns);

    [[nodiscard]] int At(int num_rows, int num_columns) const;

    int GetNumRows();

    int GetNumColumns();

};

[[maybe_unused]]static std::ostream &operator<<(std::ostream &out, Matrix &m) {
    out << m.GetNumRows() << " " << m.GetNumColumns() << std::endl;

    return out;
}

[[maybe_unused]]static std::istream &operator>>(std::istream &in, Matrix &m) {
    int columns = 0;
    int rows = 0;
    in >> rows >> columns;
    if (columns >= 0 && rows >= 0) {
        m.Reset(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                in >> m.At(i, j);
            }
        }
    } else { throw std::invalid_argument("columns and rows must be more or equal to 0"); }
    return in;
}

[[maybe_unused]]static bool operator==(Matrix &one, Matrix &two) {
    if (one.GetNumRows() == two.GetNumRows() && one.GetNumColumns() == two.GetNumColumns()) {
        for (int i = 0; i < one.GetNumRows(); ++i) {
            for (int j = 0; j < one.GetNumColumns(); ++j) {
                if (one.At(i, j) != two.At(i, j)) {
                    return false;
                }
            }
        }
        return true;
    } else { return false; }
}

[[maybe_unused]]static Matrix operator+(Matrix &one, Matrix &two) {
    Matrix _new;
    if (one.GetNumRows() == two.GetNumRows() && one.GetNumColumns() == two.GetNumColumns()) {
        _new.Reset(one.GetNumRows(), one.GetNumColumns());
        for (int i = 0; i < one.GetNumRows(); ++i) {
            for (int j = 0; j < one.GetNumColumns(); ++j) {
                _new.At(i, j) = one.At(i, j) + two.At(i, j);
            }
        }
    } else {
        throw std::invalid_argument("in operator + columns and rows of two matrix must be equal");
    }
    return _new;
}

#endif //YELLOW_BELT_TASK1_H
