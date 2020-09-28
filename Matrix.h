#pragma once

#include <iostream>

namespace mx {

	struct MatrixSize {
		int x;
		int y;
		MatrixSize();
		MatrixSize(int, int);
	};

	class Matrix
	{
	public:
		Matrix(MatrixSize size);
		Matrix(const Matrix& m);
		~Matrix();
		
		Matrix multiply(Matrix m);
		Matrix add(Matrix m);

		void fillRandom();
		void cout();

		MatrixSize size;  // don't change order!
		float* matrix;
	};

}
