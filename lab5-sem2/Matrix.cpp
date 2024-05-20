#include "Matrix.h"
#include <random>

Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols) {
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int* Matrix::operator[](unsigned int i)
{
    return data[i];
}

void Matrix::fillRandom()
{
    // Наверное, не самый лучший способ генерировать случайные числа.
    // Однако, упрощает работу пользователю, т.к. последнему не придётся передавать генератор случайных чисел
    // при каждом вызове функции.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 9);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = dis(gen); // Генерация случайного числа от 0 до 9
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix& Matrix::operator+=(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Размеры матриц не совпадают!");
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] += operand.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Размеры матриц не совпадают!");
    }

    Matrix result(m, n); // Создаем новую матрицу для хранения результата

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + operand.data[i][j];
        }
    }

    return result;
}

Matrix& Matrix::operator-=(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Размеры матриц не совпадают для вычитания!");
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] -= operand.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator-(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Размеры матриц не совпадают для вычитания!");
    }

    Matrix result(m, n); // Создаем новую матрицу для хранения результата

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] - operand.data[i][j];
        }
    }

    return result;
}


Matrix Matrix::operator*(const Matrix& operand)
{
    if (n != operand.m) {
        throw std::invalid_argument("Количество столбцов первой матрицы не совпадает с количеством строк второй матрицы!");
    }

    Matrix result(m, operand.n); // Создаем новую матрицу для хранения результата

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < operand.n; ++j) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < n; ++k) {
                result.data[i][j] += data[i][k] * operand.data[k][j];
            }
        }
    }

    return result;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

bool Matrix::operator==(const Matrix& other) const
{
    if (m != other.m || n != other.n) {
        return false;
    }

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}


