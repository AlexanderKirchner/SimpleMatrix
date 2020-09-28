#include "Matrix.h"

using namespace mx;

MatrixSize::MatrixSize()
{
	this->x = 0;
	this->y = 0;
}

MatrixSize::MatrixSize(int x, int y)
{
	this->x = x;
	this->y = y;
}

Matrix::Matrix(MatrixSize size) :
	size(size),
	matrix(new float[size.x * size.y])
{

}

//Copy constructor // Can probably be done easier
Matrix::Matrix(const Matrix& obj) :
	size(obj.size),
	matrix(new float[size.x * size.y])
{
	for (int i = 0; i < (size.x * size.y); i++) {
		matrix[i] = obj.matrix[i];
	}
}


Matrix::~Matrix() {
	delete[]matrix;
}

/**
 * If sizes are not "multiplyable" => returns Matrix with size 0 0
**/
Matrix Matrix::multiply(Matrix m)
{
	if (m.size.x != size.y)return Matrix(MatrixSize(0,0));
	Matrix mNew(MatrixSize(size.x, m.size.y));

	for (int x = 0; x < mNew.size.x; x++) {
		for (int y = 0; y < mNew.size.y; y++) {
			float v = 0;
			for (int i = 0; i < size.y; i++) {
				v += (matrix[i * size.x + x] * m.matrix[y * m.size.x + i]);
			}
			mNew.matrix[y * mNew.size.x + x] = v;
		}
	}

	return mNew;
}

/**
 * If sizes are not "multiplyable" => returns Matrix with size 0 0
**/
Matrix Matrix::add(Matrix m)
{
	if (m.size.x != size.x || m.size.y != size.y)return Matrix(MatrixSize(0, 0));
	Matrix mNew(MatrixSize(size.x, size.y));

	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			mNew.matrix[y * size.x + x] = matrix[y * size.x + x] + m.matrix[y * size.x + x];
		}
	}
	return mNew;
}

void Matrix::fillRandom()
{
	for (int i = 0; i < (size.x * size.y); i++) {
		matrix[i] = float(rand() % 4);
	}
}

void Matrix::cout() {
	std::cout << "Matrix[size = (" << size.x << ", " << size.y << ") " << std::endl;
	for (int y = 0; y < size.y; y++) {
		std::cout << "    ";
		for (int x = 0; x < size.x; x++) {
			std::cout << matrix[y * size.x + x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "]" << std::endl;
}

mx::Vector::Vector(int size) :
	Matrix(MatrixSize(1, size))
{}

mx::Vector::Vector(const Vector & v) :
	Matrix(v)
{}

void mx::Vector::cout()
{
	std::cout << "Vector[size = (" << size.x << ", " << size.y << "): ( ";
	for (int i = 0; i < size.y; i++) {
		std::cout << matrix[i] << " ";
	}
	std::cout << ")]" << std::endl;
}
