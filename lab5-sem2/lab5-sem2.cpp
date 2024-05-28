#include "Matrix.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");

    // Создаем две матрицы
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);

    // Заполняем матрицы случайными числами
    matrix1.fillRandom();
    matrix2.fillRandom();

    // Выводим их на экран
    std::cout << "Матрица 1:\n" << matrix1 << std::endl;
    std::cout << "Матрица 2:\n" << matrix2 << std::endl;

    // Сложение матриц
    Matrix resultAdd = matrix1 + matrix2;
    std::cout << "Сумма матриц:\n" << resultAdd << std::endl;

    // Вычитание матриц
    Matrix resultSubtract = matrix1 - matrix2;
    std::cout << "Разность матриц:\n" << resultSubtract << std::endl;

    // Умножение матриц
    Matrix resultMultiply = matrix1 * matrix2;
    std::cout << "Произведение матриц:\n" << resultMultiply << std::endl;

    // Проверка на равенство и неравенство матриц
    if (matrix1 == matrix2) {
        std::cout << "Матрицы равны.\n";
    }
    else {
        std::cout << "Матрицы не равны.\n";
    }

    if (matrix1 != matrix2) {
        std::cout << "Матрицы не равны.\n";
    }
    else {
        std::cout << "Матрицы равны.\n";
    }

    //copyright by Aiacaxapa & stanislavmedved
    system("start https://www.youtube.com/watch?v=5UVqIg1D3x4");

    return 0;
}
