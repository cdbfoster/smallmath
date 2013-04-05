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

#ifndef MATH_MATRIX
#define MATH_MATRIX

#include <iostream>

#include "Vector.hpp"

namespace Math
{
	// Note: Matrices are row-major and multiplication with vectors must happen in algebraically
	// correct order: Matrix * Vector.  Also note that matrix stacks are also algebraically correct: First on,
	// last off.  (ZRotation * YRotation * XRotation) * Vector == (ZRotation * (YRotation * (XRotation * Vector))).

	class Matrix2;
	class Matrix3;
	class Matrix4;
	
	class Matrix2
	{
	public:
		Matrix2();
		Matrix2(float _00, float _01,
				float _10, float _11);
		Matrix2(Vector2 const &r0, Vector2 const &r1);
		Matrix2(Matrix3 const &Mat);
		Matrix2(Matrix4 const &Mat);
		
		// General operations
		inline void SetIdentity();
		inline void SetZero();
		float Determinant() const;
		Matrix2 Adjugate() const;
		inline Matrix2 Transpose();
		inline Matrix2 Transposed() const;
		Matrix2 Invert();
		Matrix2 Inverted() const;
		Matrix2 Normalize();
		Matrix2 Normalized() const;
		inline Vector2 XAxis() const;
		inline Vector2 YAxis() const;
		
		// Decomposition operations
		Vector2 ScaleComponent() const;
		Matrix2 RotationComponent() const;
		
		// Access methods
		inline Vector2 GetRow(int Index) const;
		inline void SetRow(int Index, Vector2 const &b);
		inline Vector2 GetColumn(int Index) const;
		inline void SetColumn(int Index, Vector2 const &b);
		
		// Binary and unary multiplication operators
		inline Matrix2 operator*(Matrix2 const &b) const;
		inline Vector2 operator*(Vector2 const &b) const;
		inline Matrix2 operator*(float b) const;
		inline Matrix2 &operator*=(Matrix2 const &b);
		inline Matrix2 &operator*=(float b);
		
		// Binary and unary division operators
		inline Matrix2 operator/(float b) const;
		inline Matrix2 &operator/=(float b);
		
		float m[2][2];
	};	
	
	class Matrix3
	{
	public:
		Matrix3();
		Matrix3(float _00, float _01, float _02,
				float _10, float _11, float _12,
				float _20, float _21, float _22);
		Matrix3(Vector3 const &r0, Vector3 const &r1, Vector3 const &r2);
		Matrix3(Matrix2 const &Mat);
		Matrix3(Matrix4 const &Mat);
		
		// General operations
		inline void SetIdentity();
		inline void SetZero();
		float Determinant() const;
		Matrix3 Adjugate() const;
		inline Matrix3 Transpose();
		inline Matrix3 Transposed() const;
		Matrix3 Invert();
		Matrix3 Inverted() const;
		Matrix3 Normalize();
		Matrix3 Normalized() const;
		inline Vector3 XAxis() const;
		inline Vector3 YAxis() const;
		inline Vector3 ZAxis() const;
		
		// Decomposition operations
		Vector3 ScaleComponent() const;
		Matrix3 RotationComponent() const;
		
		// Access methods
		inline Vector3 GetRow(int Index) const;
		inline void SetRow(int Index, Vector3 const &b);
		inline Vector3 GetColumn(int Index) const;
		inline void SetColumn(int Index, Vector3 const &b);
		
		// Binary and unary multiplication operators
		inline Matrix3 operator*(Matrix3 const &b) const;
		inline Vector3 operator*(Vector3 const &b) const;
		inline Matrix3 operator*(float b) const;
		inline Matrix3 &operator*=(Matrix3 const &b);
		inline Matrix3 &operator*=(float b);
		
		// Binary and unary division operators
		inline Matrix3 operator/(float b) const;
		inline Matrix3 &operator/=(float b);
		
		float m[3][3];
		
	private:
		bool IsNegative() const;
	};

	class Matrix4
	{
	public:
		Matrix4();
		Matrix4(float _00, float _01, float _02, float _03,
				float _10, float _11, float _12, float _13,
				float _20, float _21, float _22, float _23,
				float _30, float _31, float _32, float _33);
		Matrix4(Vector4 const &r0, Vector4 const &r1, Vector4 const &r2, Vector4 const &r3);
		Matrix4(Matrix2 const &Mat);
		Matrix4(Matrix3 const &Mat);

		// General operations
		inline void SetIdentity();
		inline void SetZero();
		float Determinant() const;
		Matrix4 Adjugate() const;
		inline Matrix4 Transpose();
		inline Matrix4 Transposed() const;
		Matrix4 Invert();
		Matrix4 Inverted() const;
		Matrix4 Normalize();
		Matrix4 Normalized() const;
		inline Vector3 XAxis() const;
		inline Vector3 YAxis() const;
		inline Vector3 ZAxis() const;
		
		// Decomposition operations
		Vector3 ScaleComponent() const;
		Matrix3 RotationComponent() const;
		Vector3 TranslationComponent() const;
		
		// Access methods
		inline Vector4 GetRow(int Index) const;
		inline void SetRow(int Index, Vector4 const &b);
		inline Vector4 GetColumn(int Index) const;
		inline void SetColumn(int Index, Vector4 const &b);

		// Binary and unary multiplication operators
		inline Matrix4 operator*(Matrix4 const &b) const;
		inline Vector4 operator*(Vector4 const &b) const;
		inline Matrix4 operator*(float b) const;
		inline Matrix4 &operator*=(Matrix4 const &b);
		inline Matrix4 &operator*=(float b);
		
		// Binary and unary division operators
		inline Matrix4 operator/(float b) const;
		inline Matrix4 &operator/=(float b);

		float m[4][4];

		// Utility functions
	};

	// Stream print =======================================
	
	inline std::ostream &operator<<(std::ostream &a, Matrix2 const &b)
	{
		a << "[ " << b.m[0][0] << ", " << b.m[0][1] << " ]\n";
		a << "[ " << b.m[1][0] << ", " << b.m[1][1] << " ]\n";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Matrix3 const &b)
	{
		a << "[ " << b.m[0][0] << ", " << b.m[0][1] << ", " << b.m[0][2] << " ]\n";
		a << "[ " << b.m[1][0] << ", " << b.m[1][1] << ", " << b.m[1][2] << " ]\n";
		a << "[ " << b.m[2][0] << ", " << b.m[2][1] << ", " << b.m[2][2] << " ]\n";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Matrix4 const &b)
	{
		a << "[ " << b.m[0][0] << ", " << b.m[0][1] << ", " << b.m[0][2] << ", " << b.m[0][3] << " ]\n";
		a << "[ " << b.m[1][0] << ", " << b.m[1][1] << ", " << b.m[1][2] << ", " << b.m[1][3] << " ]\n";
		a << "[ " << b.m[2][0] << ", " << b.m[2][1] << ", " << b.m[2][2] << ", " << b.m[2][3] << " ]\n";
		a << "[ " << b.m[3][0] << ", " << b.m[3][1] << ", " << b.m[3][2] << ", " << b.m[3][3] << " ]";
		return a;
	}

	// General operations =================================

	inline void Matrix2::SetIdentity()
	{
		m[0][0] = 1.0f; m[0][1] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 1.0f;
	}
	
	inline void Matrix2::SetZero()
	{
		m[0][0] = 0.0f; m[0][1] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 0.0f;
	}

	inline Matrix2 Matrix2::Transpose()
	{
		*this = this->Transposed();
		return *this;
	}

	inline Matrix2 Matrix2::Transposed() const
	{
		Matrix2 r;

		r.m[0][0] = m[0][0]; r.m[0][1] = m[1][0];
		r.m[1][0] = m[0][1]; r.m[1][1] = m[1][1];

		return r;
	}
	
	inline void Matrix3::SetIdentity()
	{
		m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
	}
	
	inline void Matrix3::SetZero()
	{
		m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f;
	}

	inline Matrix3 Matrix3::Transpose()
	{
		*this = this->Transposed();
		return *this;
	}

	inline Matrix3 Matrix3::Transposed() const
	{
		Matrix3 r;

		r.m[0][0] = m[0][0]; r.m[0][1] = m[1][0]; r.m[0][2] = m[2][0];
		r.m[1][0] = m[0][1]; r.m[1][1] = m[1][1]; r.m[1][2] = m[2][1];
		r.m[2][0] = m[0][2]; r.m[2][1] = m[1][2]; r.m[2][2] = m[2][2];

		return r;
	}
	
	inline void Matrix4::SetIdentity()
	{
		m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
		m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	}
	
	inline void Matrix4::SetZero()
	{
		m[0][0] = 0.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 0.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 0.0f; m[2][3] = 0.0f;
		m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 0.0f;
	}

	inline Matrix4 Matrix4::Transpose()
	{
		*this = this->Transposed();
		return *this;
	}

	inline Matrix4 Matrix4::Transposed() const
	{
		Matrix4 r;

		r.m[0][0] = m[0][0]; r.m[0][1] = m[1][0]; r.m[0][2] = m[2][0]; r.m[0][3] = m[3][0];
		r.m[1][0] = m[0][1]; r.m[1][1] = m[1][1]; r.m[1][2] = m[2][1]; r.m[1][3] = m[3][1];
		r.m[2][0] = m[0][2]; r.m[2][1] = m[1][2]; r.m[2][2] = m[2][2]; r.m[2][3] = m[3][2];
		r.m[3][0] = m[0][3]; r.m[3][1] = m[1][3]; r.m[3][2] = m[2][3]; r.m[3][3] = m[3][3];

		return r;
	}
	
	inline Vector2 Matrix2::XAxis() const
	{
		return Vector2(m[0][0], m[0][1]);
	}

	inline Vector2 Matrix2::YAxis() const
	{
		return Vector2(m[1][0], m[1][1]);
	}
	
	inline Vector3 Matrix3::XAxis() const
	{
		return Vector3(m[0][0], m[0][1], m[0][2]);
	}

	inline Vector3 Matrix3::YAxis() const
	{
		return Vector3(m[1][0], m[1][1], m[1][2]);
	}

	inline Vector3 Matrix3::ZAxis() const
	{
		return Vector3(m[2][0], m[2][1], m[2][2]);
	}

	inline Vector3 Matrix4::XAxis() const
	{
		return Vector3(m[0][0], m[0][1], m[0][2]);
	}

	inline Vector3 Matrix4::YAxis() const
	{
		return Vector3(m[1][0], m[1][1], m[1][2]);
	}

	inline Vector3 Matrix4::ZAxis() const
	{
		return Vector3(m[2][0], m[2][1], m[2][2]);
	}
	
	// Access methods =====================================
	
	inline Vector2 Matrix2::GetRow(int Index) const
	{
		return Vector2(m[Index][0], m[Index][1]);
	}
	
	inline void Matrix2::SetRow(int Index, Vector2 const &b)
	{
		m[Index][0] = b.x;
		m[Index][1] = b.y;
	}
	
	inline Vector2 Matrix2::GetColumn(int Index) const
	{
		return Vector2(m[0][Index], m[1][Index]);
	}
	
	inline void Matrix2::SetColumn(int Index, Vector2 const &b)
	{
		m[0][Index] = b.x;
		m[1][Index] = b.y;
	}
	
	inline Vector3 Matrix3::GetRow(int Index) const
	{
		return Vector3(m[Index][0], m[Index][1], m[Index][2]);
	}
	
	inline void Matrix3::SetRow(int Index, Vector3 const &b)
	{
		m[Index][0] = b.x;
		m[Index][1] = b.y;
		m[Index][2] = b.z;
	}
	
	inline Vector3 Matrix3::GetColumn(int Index) const
	{
		return Vector3(m[0][Index], m[1][Index], m[2][Index]);
	}
	
	inline void Matrix3::SetColumn(int Index, Vector3 const &b)
	{
		m[0][Index] = b.x;
		m[1][Index] = b.y;
		m[2][Index] = b.z;
	}
	
	inline Vector4 Matrix4::GetRow(int Index) const
	{
		return Vector4(m[Index][0], m[Index][1], m[Index][2], m[Index][3]);
	}
	
	inline void Matrix4::SetRow(int Index, Vector4 const &b)
	{
		m[Index][0] = b.x;
		m[Index][1] = b.y;
		m[Index][2] = b.z;
		m[Index][3] = b.w;
	}
	
	inline Vector4 Matrix4::GetColumn(int Index) const
	{
		return Vector4(m[0][Index], m[1][Index], m[2][Index], m[3][Index]);
	}
	
	inline void Matrix4::SetColumn(int Index, Vector4 const &b)
	{
		m[0][Index] = b.x;
		m[1][Index] = b.y;
		m[2][Index] = b.z;
		m[3][Index] = b.w;
	}

	// Binary and unary multiplication operators ==========
	
	inline Matrix2 Matrix2::operator*(Matrix2 const &b) const
	{
		Matrix2 r;

		r.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0];
		r.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0];

		r.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1];
		r.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1];

		return r;
	}
	
	inline Vector2 Matrix2::operator*(Vector2 const &b) const
	{
		return Vector2(m[0][0] * b.x + m[0][1] * b.y,
					   m[1][0] * b.x + m[1][1] * b.y);
	}
	
	inline Matrix2 Matrix2::operator*(float b) const
	{
		return Matrix2(m[0][0] * b, m[0][1] * b,
					   m[1][0] * b, m[1][1] * b);
	}
	
	inline Matrix2 &Matrix2::operator*=(Matrix2 const &b)
	{
		*this = *this * b;
		return *this;
	}
	
	inline Matrix2 &Matrix2::operator*=(float b)
	{
		m[0][0] *= b; m[0][1] *= b;
		m[1][0] *= b; m[1][1] *= b;
		
		return *this;
	}
	
	inline Matrix3 Matrix3::operator*(Matrix3 const &b) const
	{
		Matrix3 r;

		r.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0] + m[0][2] * b.m[2][0];
		r.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0] + m[1][2] * b.m[2][0];
		r.m[2][0] = m[2][0] * b.m[0][0] + m[2][1] * b.m[1][0] + m[2][2] * b.m[2][0];

		r.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1] + m[0][2] * b.m[2][1];
		r.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1] + m[1][2] * b.m[2][1];
		r.m[2][1] = m[2][0] * b.m[0][1] + m[2][1] * b.m[1][1] + m[2][2] * b.m[2][1];

		r.m[0][2] = m[0][0] * b.m[0][2] + m[0][1] * b.m[1][2] + m[0][2] * b.m[2][2];
		r.m[1][2] = m[1][0] * b.m[0][2] + m[1][1] * b.m[1][2] + m[1][2] * b.m[2][2];
		r.m[2][2] = m[2][0] * b.m[0][2] + m[2][1] * b.m[1][2] + m[2][2] * b.m[2][2];

		return r;
	}
	
	inline Vector3 Matrix3::operator*(Vector3 const &b) const
	{
		return Vector3(m[0][0] * b.x + m[0][1] * b.y + m[0][2] * b.z,
					   m[1][0] * b.x + m[1][1] * b.y + m[1][2] * b.z,
					   m[2][0] * b.x + m[2][1] * b.y + m[2][2] * b.z);
	}
	
	inline Matrix3 Matrix3::operator*(float b) const
	{
		return Matrix3(m[0][0] * b, m[0][1] * b, m[0][2] * b,
					   m[1][0] * b, m[1][1] * b, m[1][2] * b,
					   m[2][0] * b, m[2][1] * b, m[2][2] * b);
	}

	inline Matrix3 &Matrix3::operator*=(Matrix3 const &b)
	{
		*this = *this * b;
		return *this;
	}
	
	inline Matrix3 &Matrix3::operator*=(float b)
	{
		m[0][0] *= b; m[0][1] *= b; m[0][2] *= b;
		m[1][0] *= b; m[1][1] *= b; m[1][2] *= b;
		m[2][0] *= b; m[2][1] *= b; m[2][2] *= b;
		
		return *this;
	}

	inline Matrix4 Matrix4::operator*(Matrix4 const &b) const
	{
		Matrix4 r;

		r.m[0][0] = m[0][0] * b.m[0][0] + m[0][1] * b.m[1][0] + m[0][2] * b.m[2][0] + m[0][3] * b.m[3][0];
		r.m[1][0] = m[1][0] * b.m[0][0] + m[1][1] * b.m[1][0] + m[1][2] * b.m[2][0] + m[1][3] * b.m[3][0];
		r.m[2][0] = m[2][0] * b.m[0][0] + m[2][1] * b.m[1][0] + m[2][2] * b.m[2][0] + m[2][3] * b.m[3][0];
		r.m[3][0] = m[3][0] * b.m[0][0] + m[3][1] * b.m[1][0] + m[3][2] * b.m[2][0] + m[3][3] * b.m[3][0];

		r.m[0][1] = m[0][0] * b.m[0][1] + m[0][1] * b.m[1][1] + m[0][2] * b.m[2][1] + m[0][3] * b.m[3][1];
		r.m[1][1] = m[1][0] * b.m[0][1] + m[1][1] * b.m[1][1] + m[1][2] * b.m[2][1] + m[1][3] * b.m[3][1];
		r.m[2][1] = m[2][0] * b.m[0][1] + m[2][1] * b.m[1][1] + m[2][2] * b.m[2][1] + m[2][3] * b.m[3][1];
		r.m[3][1] = m[3][0] * b.m[0][1] + m[3][1] * b.m[1][1] + m[3][2] * b.m[2][1] + m[3][3] * b.m[3][1];

		r.m[0][2] = m[0][0] * b.m[0][2] + m[0][1] * b.m[1][2] + m[0][2] * b.m[2][2] + m[0][3] * b.m[3][2];
		r.m[1][2] = m[1][0] * b.m[0][2] + m[1][1] * b.m[1][2] + m[1][2] * b.m[2][2] + m[1][3] * b.m[3][2];
		r.m[2][2] = m[2][0] * b.m[0][2] + m[2][1] * b.m[1][2] + m[2][2] * b.m[2][2] + m[2][3] * b.m[3][2];
		r.m[3][2] = m[3][0] * b.m[0][2] + m[3][1] * b.m[1][2] + m[3][2] * b.m[2][2] + m[3][3] * b.m[3][2];

		r.m[0][3] = m[0][0] * b.m[0][3] + m[0][1] * b.m[1][3] + m[0][2] * b.m[2][3] + m[0][3] * b.m[3][3];
		r.m[1][3] = m[1][0] * b.m[0][3] + m[1][1] * b.m[1][3] + m[1][2] * b.m[2][3] + m[1][3] * b.m[3][3];
		r.m[2][3] = m[2][0] * b.m[0][3] + m[2][1] * b.m[1][3] + m[2][2] * b.m[2][3] + m[2][3] * b.m[3][3];
		r.m[3][3] = m[3][0] * b.m[0][3] + m[3][1] * b.m[1][3] + m[3][2] * b.m[2][3] + m[3][3] * b.m[3][3];

		return r;
	}
	
	inline Vector4 Matrix4::operator*(Vector4 const &b) const
	{
		return Vector4(m[0][0] * b.x + m[0][1] * b.y + m[0][2] * b.z + m[0][3] * b.w,
					   m[1][0] * b.x + m[1][1] * b.y + m[1][2] * b.z + m[1][3] * b.w,
					   m[2][0] * b.x + m[2][1] * b.y + m[2][2] * b.z + m[2][3] * b.w,
					   m[3][0] * b.x + m[3][1] * b.y + m[3][2] * b.z + m[3][3] * b.w);
	}
	
	inline Matrix4 Matrix4::operator*(float b) const
	{
		return Matrix4(m[0][0] * b, m[0][1] * b, m[0][2] * b, m[0][3] * b,
					   m[1][0] * b, m[1][1] * b, m[1][2] * b, m[1][3] * b,
					   m[2][0] * b, m[2][1] * b, m[2][2] * b, m[2][3] * b,
					   m[3][0] * b, m[3][1] * b, m[3][2] * b, m[3][3] * b);
	}

	inline Matrix4 &Matrix4::operator*=(Matrix4 const &b)
	{
		*this = *this * b;
		return *this;
	}
	
	inline Matrix4 &Matrix4::operator*=(float b)
	{
		m[0][0] *= b; m[0][1] *= b; m[0][2] *= b; m[0][3] *= b;
		m[1][0] *= b; m[1][1] *= b; m[1][2] *= b; m[1][3] *= b;
		m[2][0] *= b; m[2][1] *= b; m[2][2] *= b; m[2][3] *= b;
		m[3][0] *= b; m[3][1] *= b; m[3][2] *= b; m[3][3] *= b;
		
		return *this;
	}
	
	// Binary and unary division operators ================
	
	inline Matrix2 Matrix2::operator/(float b) const
	{
		return Matrix2(m[0][0] / b, m[0][1] / b,
					   m[1][0] / b, m[1][1] / b);
	}
	
	inline Matrix2 &Matrix2::operator/=(float b)
	{
		m[0][0] /= b; m[0][1] /= b;
		m[1][0] /= b; m[1][1] /= b;
		
		return *this;
	}
	
	inline Matrix3 Matrix3::operator/(float b) const
	{
		return Matrix3(m[0][0] / b, m[0][1] / b, m[0][2] / b,
					   m[1][0] / b, m[1][1] / b, m[1][2] / b,
					   m[2][0] / b, m[2][1] / b, m[2][2] / b);
	}
	
	inline Matrix3 &Matrix3::operator/=(float b)
	{
		m[0][0] /= b; m[0][1] /= b; m[0][2] /= b;
		m[1][0] /= b; m[1][1] /= b; m[1][2] /= b;
		m[2][0] /= b; m[2][1] /= b; m[2][2] /= b;
		
		return *this;
	}
	
	inline Matrix4 Matrix4::operator/(float b) const
	{
		return Matrix4(m[0][0] / b, m[0][1] / b, m[0][2] / b, m[0][3] / b,
					   m[1][0] / b, m[1][1] / b, m[1][2] / b, m[1][3] / b,
					   m[2][0] / b, m[2][1] / b, m[2][2] / b, m[2][3] / b,
					   m[3][0] / b, m[3][1] / b, m[3][2] / b, m[3][3] / b);
	}
	
	inline Matrix4 &Matrix4::operator/=(float b)
	{
		m[0][0] /= b; m[0][1] /= b; m[0][2] /= b; m[0][3] /= b;
		m[1][0] /= b; m[1][1] /= b; m[1][2] /= b; m[1][3] /= b;
		m[2][0] /= b; m[2][1] /= b; m[2][2] /= b; m[2][3] /= b;
		m[3][0] /= b; m[3][1] /= b; m[3][2] /= b; m[3][3] /= b;
		
		return *this;
	}

	// Utility functions ==================================

	/*inline Matrix2 Matrix2::Rotate(float Radians)
	{
		Matrix2 Rotation;

		if (std::abs(Radians) > std::numeric_limits<float>::epsilon())
			Rotation = Matrix2(std::cos(Radians), -std::sin(Radians),
							   std::sin(Radians), std::cos(Radians));

		return Rotation;
	}

	inline Matrix2 Matrix2::Scale(float ScaleX, float ScaleY)
	{
		return Matrix2(ScaleX, 0.0f,
					   0.0f, ScaleY);
	}

	inline Matrix3 Matrix3::RotateXYZ(float RadiansX, float RadiansY, float RadiansZ)
	{
		Matrix3 XRotation, YRotation, ZRotation;

		if (std::abs(RadiansX) > std::numeric_limits<float>::epsilon())
			XRotation = Matrix3(1.0f, 0.0f, 0.0f,
								0.0f, std::cos(RadiansX), -std::sin(RadiansX),
								0.0f, std::sin(RadiansX), std::cos(RadiansX));
		if (std::abs(RadiansY) > std::numeric_limits<float>::epsilon())
			YRotation = Matrix3(std::cos(RadiansY), 0.0f, std::sin(RadiansY),
								0.0f, 1.0f, 0.0f,
								-std::sin(RadiansY), 0.0f, std::cos(RadiansY));
		if (std::abs(RadiansZ) > std::numeric_limits<float>::epsilon())
			ZRotation = Matrix3(std::cos(RadiansZ), -std::sin(RadiansZ), 0.0f,
								std::sin(RadiansZ), std::cos(RadiansZ), 0.0f,
								0.0f, 0.0f, 1.0f);

		return ZRotation * YRotation * XRotation;
	}

	inline Matrix3 Matrix3::Scale(float ScaleX, float ScaleY, float ScaleZ)
	{
		return Matrix3(ScaleX, 0.0f, 0.0f,
					   0.0f, ScaleY, 0.0f,
					   0.0f, 0.0f, ScaleZ);
	}

	inline Matrix4 Matrix4::RotateXYZ(float RadiansX, float RadiansY, float RadiansZ)
	{
		Matrix4 XRotation, YRotation, ZRotation;

		if (std::abs(RadiansX) > std::numeric_limits<float>::epsilon())
			XRotation = Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, std::cos(RadiansX), -std::sin(RadiansX), 0.0f,
								0.0f, std::sin(RadiansX), std::cos(RadiansX), 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f);
		if (std::abs(RadiansY) > std::numeric_limits<float>::epsilon())
			YRotation = Matrix4(std::cos(RadiansY), 0.0f, std::sin(RadiansY), 0.0f,
								0.0f, 1.0f, 0.0f, 0.0f,
								-std::sin(RadiansY), 0.0f, std::cos(RadiansY), 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f);
		if (std::abs(RadiansZ) > std::numeric_limits<float>::epsilon())
			ZRotation = Matrix4(std::cos(RadiansZ), -std::sin(RadiansZ), 0.0f, 0.0f,
								std::sin(RadiansZ), std::cos(RadiansZ), 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f);

		return ZRotation * YRotation * XRotation;
	}

	inline Matrix4 Matrix4::Scale(float ScaleX, float ScaleY, float ScaleZ)
	{
		return Matrix4(ScaleX, 0.0f, 0.0f, 0.0f,
					   0.0f, ScaleY, 0.0f, 0.0f,
					   0.0f, 0.0f, ScaleZ, 0.0f,
					   0.0f, 0.0f, 0.0f, 1.0f);
	}

	inline Matrix4 Matrix4::Translate(float TranslationX, float TranslationY, float TranslationZ)
	{
		return Matrix4(1.0f, 0.0f, 0.0f, TranslationX,
					   0.0f, 1.0f, 0.0f, TranslationY,
					   0.0f, 0.0f, 1.0f, TranslationZ,
					   0.0f, 0.0f, 0.0f, 1.0f);
	}

	// Returns the "world to view" matrix for a child space whose origin is Eye in parent space,
	// whose Z axis is pointing at At in parent space, and whose up-axis is Up in parent space.
	inline Matrix4 Matrix4::LookAt(Vector3 Eye, Vector3 At, Vector3 Up)
	{
		Vector3 ZAxis = (At - Eye).Normalized();
		Vector3 XAxis = (Up.Cross(ZAxis)).Normalized();
		Vector3 YAxis = ZAxis.Cross(XAxis);

		return Math::Matrix4(XAxis.x, XAxis.y, XAxis.z, -XAxis.Dot(Eye),
							 YAxis.x, YAxis.y, YAxis.z, -YAxis.Dot(Eye),
							 ZAxis.x, ZAxis.y, ZAxis.z, -ZAxis.Dot(Eye),
							 0.0f, 0.0f, 0.0f, 1.0f);
	}*/
}

#endif

