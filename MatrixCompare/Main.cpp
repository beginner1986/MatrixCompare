#include <iostream>
#include <cmath>
#include "Matrix.h"

Matrix* readFromFile(std::string matrixName);
bool compareMartices(const Matrix& A, const Matrix& B, float eps);

constexpr auto EPS = 0.001f;

int main()
{
	// polish language support
	setlocale(LC_ALL, "polish");

	// read the matrices to multiply
	Matrix* A = readFromFile("A");
	Matrix* B = readFromFile("B");

	// compare the matrices
	bool areEqual = compareMartices(*A, *B, EPS);
	// std::cout << "Macierze A i B" << (areEqual ? " " : " nie ") << "s¹ równe" << std::endl;
	if (areEqual)
		std::cout << "Macierze s¹ równe" << std::endl;
	else
		std::cout << "Macierze s¹ ró¿ne" << std::endl;

	// free the memory
	delete A, B;

	// hold the screen
	std::cin.get();
	return 0;
}

Matrix* readFromFile(std::string matrixName)
{
	// get file name
	std::string fileName;
	std::cout << "Podaj nazwê pliku z macierz¹ " << matrixName << ": ";
	std::cin >> fileName;

	// create the matrix and return it
	Matrix* result = new Matrix(fileName);

	// success info
	std::cout << "Macierz " << matrixName << " zosta³a poprawnie wczytana." << std::endl;

	return result;
}

bool compareMartices(const Matrix& A, const Matrix& B, float eps)
{
	if (A.getM() != B.getM() || A.getN() != B.getN())
	{
		return false;
	}

	for (size_t i = 0; i < A.getM(); i++)
	{
		for (size_t j = 0; j < A.getN(); j++)
		{
			if (fabs(fabs(A.getAt(i, j)) - fabs(B.getAt(i, j))) > eps)
			{
				return false;
			}
		}
	}

	return true;
}
