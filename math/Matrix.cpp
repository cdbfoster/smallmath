/*
* This file is part of SmallMathLib.
*
* SmallMathLib is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SmallMathLib is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with SmallMathLib. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Matrix.hpp"

using namespace Math;

Matrix2::Matrix2()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f;
}

Matrix2::Matrix2(float _00, float _01,
				 float _10, float _11)
{
	m[0][0] = _00; m[0][1] = _01;
	m[1][0] = _10; m[1][1] = _11;
}

Matrix2::Matrix2(Matrix3 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1];
}

Matrix2::Matrix2(Matrix4 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1];
}

Matrix3::Matrix3()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
}

Matrix3::Matrix3(float _00, float _01, float _02,
				 float _10, float _11, float _12,
				 float _20, float _21, float _22)
{
	m[0][0] = _00; m[0][1] = _01; m[0][2] = _02;
	m[1][0] = _10; m[1][1] = _11; m[1][2] = _12;
	m[2][0] = _20; m[2][1] = _21; m[2][2] = _22;
}

Matrix3::Matrix3(Matrix2 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
}

Matrix3::Matrix3(Matrix4 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = Mat.m[0][2];
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = Mat.m[1][2];
	m[2][0] = Mat.m[2][0]; m[2][1] = Mat.m[2][1]; m[2][2] = Mat.m[2][2];
}

Matrix4::Matrix4()
{
	m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

Matrix4::Matrix4(float _00, float _01, float _02, float _03,
				 float _10, float _11, float _12, float _13,
				 float _20, float _21, float _22, float _23,
				 float _30, float _31, float _32, float _33)
{
	m[0][0] = _00; m[0][1] = _01; m[0][2] = _02; m[0][3] = _03;
	m[1][0] = _10; m[1][1] = _11; m[1][2] = _12; m[1][3] = _13;
	m[2][0] = _20; m[2][1] = _21; m[2][2] = _22; m[2][3] = _23;
	m[3][0] = _30; m[3][1] = _31; m[3][2] = _32; m[3][3] = _33;
}

Matrix4::Matrix4(Matrix2 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = 0.0f; m[2][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[2][3] = 1.0f;
}

Matrix4::Matrix4(Matrix3 const &Mat)
{
	m[0][0] = Mat.m[0][0]; m[0][1] = Mat.m[0][1]; m[0][2] = Mat.m[0][2]; m[0][3] = 0.0f;
	m[1][0] = Mat.m[1][0]; m[1][1] = Mat.m[1][1]; m[1][2] = Mat.m[1][2]; m[2][3] = 0.0f;
	m[2][0] = Mat.m[2][0]; m[2][1] = Mat.m[2][1]; m[2][2] = Mat.m[2][2]; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[2][3] = 1.0f;
}

// General operations =====================================

float Matrix2::Determinant() const
{
	return (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
}

Matrix2 Matrix2::Adjugate() const
{
	return Matrix2(m[1][1], -m[0][1],
				   -m[1][0], m[0][0]);
}

Matrix2 Matrix2::Invert()
{
	*this = this->Inverted();
	return *this;
}

Matrix2 Matrix2::Inverted() const
{
	float d = this->Determinant();
	
	if (std::abs(d) < std::numeric_limits<float>::epsilon())
		return Matrix2(); // The matrix is uninvertible
	
	return this->Adjugate() / d;
}

float Matrix3::Determinant() const
{
	return (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
			m[0][1] * (m[1][0] * m[2][2] - m[2][0] * m[1][2]) +
			m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]));
}

Matrix3 Matrix3::Adjugate() const
{
	Matrix3 a;
	
	a.m[0][0] =  (m[1][1] * m[2][2] - m[2][1] * m[1][2]);
	a.m[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
	a.m[2][0] =  (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
	
	a.m[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
	a.m[1][1] =  (m[0][0] * m[2][2] - m[2][0] * m[0][2]);
	a.m[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
	
	a.m[0][2] =  (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
	a.m[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
	a.m[2][2] =  (m[0][0] * m[1][1] - m[1][0] * m[0][1]);
	
	return a;
}

Matrix3 Matrix3::Invert()
{
	*this = this->Inverted();
	return *this;
}

Matrix3 Matrix3::Inverted() const
{
	float d = this->Determinant();
	
	if (std::abs(d) < std::numeric_limits<float>::epsilon())
		return Matrix2(); // The matrix is uninvertible
	
	return this->Adjugate() / d;
}

float Matrix4::Determinant() const
{
	return (m[0][0] * Matrix3(m[1][1], m[1][2], m[1][3],
							  m[2][1], m[2][2], m[2][3],
							  m[3][1], m[3][2], m[3][3]).Determinant() -
			m[0][1] * Matrix3(m[1][0], m[1][2], m[1][3],
							  m[2][0], m[2][2], m[2][3],
							  m[3][0], m[3][2], m[3][3]).Determinant() +
			m[0][2] * Matrix3(m[1][0], m[1][1], m[1][3],
							  m[2][0], m[2][1], m[2][3],
							  m[3][0], m[3][1], m[3][3]).Determinant() -
			m[0][3] * Matrix3(m[1][0], m[1][1], m[1][2],
							  m[2][0], m[2][1], m[2][2],
							  m[3][0], m[3][1], m[3][2]).Determinant());
}

Matrix4 Matrix4::Adjugate() const
{
	Matrix4 a;
	
	a.m[0][0] =  Matrix3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]).Determinant()
	a.m[1][0] = -Matrix3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]).Determinant()
	a.m[2][0] =  Matrix3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]).Determinant()
	a.m[3][0] = -Matrix3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]).Determinant()
	
	a.m[0][1] = -Matrix3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]).Determinant()
	a.m[1][1] =  Matrix3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]).Determinant()
	a.m[2][1] = -Matrix3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]).Determinant()
	a.m[3][1] =  Matrix3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]).Determinant()
	
	a.m[0][2] =  Matrix3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]).Determinant()
	a.m[1][2] = -Matrix3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]).Determinant()
	a.m[2][2] =  Matrix3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]).Determinant()
	a.m[3][2] = -Matrix3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]).Determinant()
	
	a.m[0][3] = -Matrix3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]).Determinant()
	a.m[1][3] =  Matrix3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]).Determinant()
	a.m[2][3] = -Matrix3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]).Determinant()
	a.m[3][3] =  Matrix3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]).Determinant()
	
	return a;
}

Matrix4 Matrix4::Invert()
{
	*this = this->Inverted();
	return *this;
}

// This routine is adapted from Blender's invert_m4_m4().  Presumably faster than Adj/Det?
Matrix4 Matrix4::Inverted() const
{
	Matrix4 r, Temp;

	Temp = *this;

	// Effectively, we shrink the matrix with each iteration by ignoring an additional row and column.
	for (short FirstColumn = 0; FirstColumn < 4; FirstColumn++)
	{
		short &FirstRow = FirstColumn; // For ease of reading in different contexts
		float Max = std::fabs(Temp.m[FirstRow][FirstColumn]);
		short MaxRow = FirstColumn; // This will contain the Row in this Column that contains the maximum.

		for (short Row = FirstColumn + 1; Row < 4; Row++)
		{
			if (std::fabs(Temp.m[Row][FirstColumn]) > Max)
			{
				Max = std::fabs(Temp.m[Row][FirstColumn]);
				MaxRow = Row;
			}
		}

		if (std::abs(Max) < std::numeric_limits<float>::epsilon())
			return Matrix4(); // The matrix is uninvertible

		// If the max was not in the first row, swap its row with the first.
		if (MaxRow != FirstRow)
		{
			for (short Index = 0; Index < 4; Index++)
			{
				std::swap(Temp.m[MaxRow][Index], Temp.m[FirstRow][Index]);
				std::swap(r.m[MaxRow][Index], r.m[FirstRow][Index]);
			}
		}

		float SignedMax = Temp.m[FirstRow][FirstColumn];
		for (short Index = 0; Index < 4; Index++)
		{
			Temp.m[FirstRow][Index] /= SignedMax;
			r.m[FirstRow][Index] /= SignedMax;
		}

		for (short Row = 0; Row < 4; Row++)
		{
			if (Row != FirstRow)
			{
				float RowValue = Temp.m[Row][FirstColumn];
				for (short Index = 0; Index < 4; Index++)
				{
					Temp.m[Row][Index] -= Temp.m[FirstRow][Index] * RowValue;
					r.m[Row][Index] -= r.m[FirstRow][Index] * RowValue;
				}
			}
		}
	}

	return r;
}
