#pragma once
#include <iostream>

template<typename T>
class Matrix {
    T** matrix;
    unsigned length;
    unsigned width;
    bool transposed;
    void free();
    void copyFrom(const Matrix<T>& _matrix);
    void moveFrom(Matrix<T>&& _matrix);
    bool isCorrect(unsigned indexX, unsigned indexY) const;
    void swap(unsigned& ind1, unsigned& ind2) const;
public:
    Matrix();
    Matrix(unsigned length, unsigned width);
    Matrix(const Matrix<T>& matrix);
    Matrix(Matrix<T>&& matrix);
    Matrix& operator=(const Matrix<T>& matrix);
    Matrix& operator=(Matrix<T>&& matrix);
    void setAt(unsigned x, unsigned y, const T& elem);
    const T& getAt(unsigned x, unsigned y) const;
    void transpose();
    ~Matrix();
};

template<typename T>
void Matrix<T>::transpose() {
    transposed = !transposed;
}

template<typename T>
void Matrix<T>::swap(unsigned int& ind1, unsigned int& ind2) const {
    unsigned temp = ind1;
    ind1 = ind2;
    ind2 = temp;
}

template<typename T>
bool Matrix<T>::isCorrect(unsigned indexX, unsigned indexY) const {
    return indexX <= width && indexY <= length;
}

template<typename T>
void Matrix<T>::free() {
    for (int i = 0; i < width; ++i) {
        delete matrix[i];
    }
    delete[] matrix;
}

template<typename T>
void Matrix<T>::copyFrom(const Matrix<T>& _matrix) {
    width = _matrix.width;
    length = _matrix.length;
    transposed = _matrix.transposed;
    matrix = new T*[width];
    for (int i = 0; i < width; ++i) {
        matrix = new T[length];
        for (int j = 0; j < length; ++j)
            matrix[i][j] = _matrix[i][j];
    }
}

template<typename T>
void Matrix<T>::moveFrom(Matrix<T> &&_matrix) {
    width = _matrix.width;
    length = _matrix.length;
    _matrix.length = _matrix.width = _matrix.transposed = 0;
    matrix = _matrix.matrix;
    _matrix.matrix = nullptr;
    transposed = _matrix.transposed;
}

template<typename T>
Matrix<T>::Matrix(unsigned _length, unsigned _width) : length(_length), width(_width) {
    matrix = new T*[width];
    for (int i = 0; i < width; ++i)
        matrix[i] = new T[length];
}

template<typename T>
Matrix<T>::Matrix() : Matrix(2, 2) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &matrix) {
    copyFrom(matrix);
}

template<typename T>
Matrix<T>::Matrix(Matrix<T> &&matrix) {
    moveFrom(std::move(matrix));
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&matrix) {
    if (this != &matrix) {
        free();
        copyFrom(std::move(matrix));
    }
    return *this;
}


template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
    if (this != &matrix) {
        free();
        copyFrom(matrix);
    }
    return *this;
}


template<typename T>
void Matrix<T>::setAt(unsigned x, unsigned y, const T &elem) {
    if (!isCorrect(x, y))
        throw std::out_of_range("Out of bounds!");
    if (transposed)
        swap(x, y);
    matrix[x - 1][y - 1] = elem;
}

template<typename T>
const T &Matrix<T>::getAt(unsigned x, unsigned y) const {
    if (!isCorrect(x, y))
        throw std::out_of_range("Out of bounds!");
    if (transposed)
        swap(x, y);
    return matrix[x - 1][y - 1];
}

template<typename T>
Matrix<T>::~Matrix() {
    free();
}

