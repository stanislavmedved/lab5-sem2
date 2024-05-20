#pragma once
#include <iostream>

class Matrix {
private:
    unsigned int m;
    unsigned int n;
    int** data;

public:
    // Конструктор и деструктор
    Matrix(unsigned int rows, unsigned int cols);
    ~Matrix();
    // Оператор обращения по индексу
    int* operator[](unsigned int i);
    // Метод заполнения случайными числами
    void fillRandom();
    // Оператор <<
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    // Операторы сложения/вычитания/умножения
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    // Операторы сравнения
    bool operator!=(const Matrix& other) const;
    bool operator==(const Matrix& other) const;
};