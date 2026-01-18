#include <iostream>

class Multiarray 
{
public:
    int arr1[100][100];
    int arr2[100][100];
    int result[100][100];
    int rows1, cols1, rows2, cols2;

public:
    void get() {
        std::cout << "Enter dimensions of the first array (rows columns): ";
        std::cin >> rows1 >> cols1;

        std::cout << "Enter elements of the first array:\n";
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                std::cin >> arr1[i][j];
            }
        }

        std::cout << "Enter dimensions of the second array (rows columns): ";
        std::cin >> rows2 >> cols2;

        std::cout << "Enter elements of the second array:\n";
        for (int i = 0; i < rows2; ++i) {
            for (int j = 0; j < cols2; ++j) {
                std::cin >> arr2[i][j];
            }
        }
    }

    void display() {
        std::cout << "First array:\n";
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols1; ++j) {
                std::cout << arr1[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "Second array:\n";
        for (int i = 0; i < rows2; ++i) {
            for (int j = 0; j < cols2; ++j) {
                std::cout << arr2[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void multiply() {
        if (cols1 != rows2) {
            std::cout << "Matrix multiplication not possible due to invalid dimensions.\n";
            return;
        }

        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < cols1; ++k) {
                    result[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        std::cout << "Matrix multiplication result:\n";
        for (int i = 0; i < rows1; ++i) {
            for (int j = 0; j < cols2; ++j) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void transpose(int arr[100][100], int rows, int cols)
	 {
        int transposed[100][100];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed[j][i] = arr[i][j];
            }
        }

        std::cout << "Transposed array:\n";
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                std::cout << transposed[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::cout<<"Harpreet, 2210997092\n\n";
    Multiarray multiArray;

    multiArray.get();

    std::cout << "Arrays entered:\n";
    multiArray.display();

    std::cout << "Performing matrix multiplication:\n";
    multiArray.multiply();

    std::cout << "Transposing first array:\n";
    multiArray.transpose(multiArray.arr1, multiArray.rows1, multiArray.cols1);

    std::cout << "Transposing second array:\n";
    multiArray.transpose(multiArray.arr2, multiArray.rows2, multiArray.cols2);

    return 0;
}

