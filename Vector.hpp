// LGPL here

#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>
#include <iostream>
#include <limits>

namespace Math
{
	class Vector2;
	class Vector3;
	class Vector4;

	class Vector2
	{
	public:
		Vector2() : x(0.0f), y(0.0f) { }
		Vector2(float x, float y) : x(x), y(y) { }
		Vector2(Vector3 const &Vec);
		Vector2(Vector4 const &Vec);

		// General operations
		inline float Dot(Vector2 const &b) const;
		inline float Length() const;
		inline float LengthSquared() const;
		inline Vector2 Normalize();
		inline Vector2 Normalize(float l);
		inline Vector2 Normalized() const;
		inline Vector2 Normalized(float l) const;
		inline bool IsZero() const;

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector2 operator+(Vector2 const &b) const;
		inline Vector2 operator+(float b) const;
		inline Vector2 &operator+=(Vector2 const &b);
		inline Vector2 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector2 operator-(Vector2 const &b) const;
		inline Vector2 operator-(float b) const;
		inline Vector2 &operator-=(Vector2 const &b);
		inline Vector2 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector2 operator*(float b) const;
		inline Vector2 &operator*=(float b);

		// Binary and unary division operators
		inline Vector2 operator/(float b) const;
		inline Vector2 &operator/=(float b);

		float x, y;
	};

	class Vector3
	{
	public:
		Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
		Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
		Vector3(Vector2 const &Vec, float z = 0.0f) : x(Vec.x), y(Vec.y), z(z) { }
		Vector3(Vector4 const &Vec);

		// General operations
		inline float Dot(Vector2 const &b) const;
		inline float Dot(Vector3 const &b) const;
		inline float Dot(Vector4 const &b) const;
		inline Vector3 Cross(Vector3 const &b) const;
		inline Vector3 Cross(Vector4 const &b) const;
		inline float Length() const;
		inline float LengthSquared() const;
		inline Vector3 Normalize();
		inline Vector3 Normalize(float l);
		inline Vector3 Normalized() const;
		inline Vector3 Normalized(float l) const;
		inline bool IsZero() const;

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector3 operator+(Vector3 const &b) const;
		inline Vector3 operator+(Vector4 const &b) const;
		inline Vector3 operator+(float b) const;
		inline Vector3 &operator+=(Vector3 const &b);
		inline Vector3 &operator+=(Vector4 const &b);
		inline Vector3 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector3 operator-(Vector3 const &b) const;
		inline Vector3 operator-(Vector4 const &b) const;
		inline Vector3 operator-(float b) const;
		inline Vector3 &operator-=(Vector3 const &b);
		inline Vector3 &operator-=(Vector4 const &b);
		inline Vector3 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector3 operator*(float b) const;
		inline Vector3 &operator*=(float b);

		// Binary and unary division operators
		inline Vector3 operator/(float b) const;
		inline Vector3 &operator/=(float b);
		
		float x, y, z;
	};
	
	class Vector4
	{
	public:
		Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }
		Vector4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) { }
		Vector4(Vector2 const &Vec, float z = 0.0f, float w = 1.0f) : x(Vec.x), y(Vec.y), z(z), w(w) { }
		Vector4(Vector3 const &Vec, float w = 1.0f) : x(Vec.x), y(Vec.y), z(Vec.z), w(w) { }

		// General operations
		inline float Dot(Vector2 const &b) const;
		inline float Dot(Vector3 const &b) const;
		inline float Dot(Vector4 const &b) const; 		// Performs 3D dot product
		inline Vector4 Cross(Vector3 const &b) const;
		inline Vector4 Cross(Vector4 const &b) const; 	// Performs 3D cross product
		inline float Length() const; 					// Calculates 3D length
		inline float LengthSquared() const;				// Calculates 3D length squared
		inline Vector4 Normalize();						// Normalizes with 3D length
		inline Vector4 Normalize(float l);				
		inline Vector4 NormalizeW();					// Normalizes with w component
		inline Vector4 Normalized() const;
		inline Vector4 Normalized(float l) const;
		inline Vector4 NormalizedW() const;
		inline bool IsZero() const;						// Checks only 3D components

		// Subscription operators
		inline float operator[](int Index) const;
		inline float &operator[](int Index);

		// Binary and unary addition operators
		inline Vector4 operator+(Vector3 const &b) const;
		inline Vector4 operator+(Vector4 const &b) const;
		inline Vector4 operator+(float b) const;
		inline Vector4 &operator+=(Vector3 const &b);
		inline Vector4 &operator+=(Vector4 const &b);
		inline Vector4 &operator+=(float b);

		// Binary and unary subtraction operators
		inline Vector4 operator-(Vector3 const &b) const;
		inline Vector4 operator-(Vector4 const &b) const;
		inline Vector4 operator-(float b) const;
		inline Vector4 &operator-=(Vector3 const &b);
		inline Vector4 &operator-=(Vector4 const &b);
		inline Vector4 &operator-=(float b);

		// Binary and unary multiplication operators
		inline Vector4 operator*(float b) const;
		inline Vector4 &operator*=(float b);

		// Binary and unary division operators
		inline Vector4 operator/(float b) const;
		inline Vector4 &operator/=(float b);
		
		float x, y, z, w;
	};
	
	Vector2::Vector2(Vector3 const &Vec)
	{
		x = Vec.x;
		y = Vec.y;
	}
	
	Vector2::Vector2(Vector4 const &Vec)
	{
		x = Vec.x;
		y = Vec.y;
	}
	
	Vector3::Vector3(Vector4 const &Vec)
	{
		x = Vec.x;
		y = Vec.y;
		z = Vec.z;
	}

	// Stream print =======================================
	
	inline std::ostream &operator<<(std::ostream &a, Vector2 const &b)
	{
		a << "(" << b.x << ", " << b.y << ")";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Vector3 const &b)
	{
		a << "(" << b.x << ", " << b.y << ", " << b.z << ")";
		return a;
	}
	
	inline std::ostream &operator<<(std::ostream &a, Vector4 const &b)
	{
		a << "(" << b.x << ", " << b.y << ", " << b.z << ", " << b.w << ")";
		return a;
	}

	// General operations =================================
	
	inline float Vector2::Dot(Vector2 const &b) const
	{
		return (x * b.x + y * b.y);
	}

	inline float Vector2::Length() const
	{
		return std::sqrt(x * x + y * y);
	}

	inline float Vector2::LengthSquared() const
	{
		return (x * x + y * y);
	}

	inline Vector2 Vector2::Normalize()
	{
		*this = this->Normalized();
		return *this;
	}

	inline Vector2 Vector2::Normalize(float l)
	{
		*this = this->Normalized(l);
		return *this;
	}

	inline Vector2 Vector2::Normalized() const
	{
		float l = this->Length();

		return Vector2(x / l,
					   y / l);
	}

	inline Vector2 Vector2::Normalized(float l) const
	{
		return Vector2(x / l,
					   y / l);
	}

	inline bool Vector2::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				return true;

		return false;
	}

	inline float Vector3::Dot(Vector2 const &b) const
	{
		return (x * b.x + y * b.y);
	}
	
	inline float Vector3::Dot(Vector3 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
	
	inline float Vector3::Dot(Vector4 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
	
	inline Vector3 Vector3::Cross(Vector3 const &b) const
	{
		return Vector3(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x);
	}
	
	inline Vector3 Vector3::Cross(Vector4 const &b) const
	{
		return Vector4(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x,
					   1.0f);
	}

	inline float Vector3::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	inline float Vector3::LengthSquared() const
	{
		return (x * x + y * y + z * z);
	}

	inline Vector3 Vector3::Normalize()
	{
		*this = this->Normalized();
		return *this;
	}

	inline Vector3 Vector3::Normalize(float l)
	{
		*this = this->Normalized(l);
		return *this;
	}

	inline Vector3 Vector3::Normalized() const
	{
		float l = this->Length();

		return Vector3(x / l,
					   y / l,
					   z / l);
	}

	inline Vector3 Vector3::Normalized(float l) const
	{
		return Vector3(x / l,
					   y / l,
					   z / l);
	}

	inline bool Vector3::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				if (std::abs(z) < Epsilon)
					return true;

		return false;
	}

	inline float Vector4::Dot(Vector2 const &b) const
	{
		return (x * b.x + y * b.y);
	}
	
	inline float Vector4::Dot(Vector3 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
	
	inline float Vector4::Dot(Vector4 const &b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}
		
	inline Vector4 Vector4::Cross(Vector3 const &b) const
	{
		return Vector4(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x);
	}
	
	inline Vector4 Vector4::Cross(Vector4 const &b) const
	{
		return Vector4(y * b.z - z * b.y,
					   z * b.x - x * b.z,
					   x * b.y - y * b.x,
					   1.0f);
	}

	inline float Vector4::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	inline float Vector4::LengthSquared() const
	{
		return (x * x + y * y + z * z);
	}

	inline Vector4 Vector4::Normalize()
	{
		*this = this->Normalized();
		return *this;
	}

	inline Vector4 Vector4::Normalize(float l)
	{
		*this = this->Normalized(l);
		return *this;
	}
	
	inline Vector4 Vector4::NormalizeW()
	{
		*this = this->NormalizedW();
		return *this;
	}
	
	inline Vector4 Vector4::Normalized() const
	{
		float l = this->Length();
		
		return Vector4(x / l,
					   y / l,
					   z / l,
					   1.0f);
	}
	
	inline Vector4 Vector4::Normalized(float l) const
	{
		return Vector4(x / l,
					   y / l,
					   z / l,
					   w / l);
	}
	
	inline Vector4 Vector4::NormalizedW() const
	{
		return Vector4(x / w,
					   y / w,
					   z / w,
					   1.0f);
	}

	inline bool Vector4::IsZero() const
	{
		float const Epsilon = std::numeric_limits<float>::epsilon();

		if (std::abs(x) < Epsilon)
			if (std::abs(y) < Epsilon)
				if (std::abs(z) < Epsilon)
					return true;

		return false;
	}

	// Subscription operators =============================
	
	inline float Vector2::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector2::operator[](int Index)
	{
		return (&x)[Index];
	}

	inline float Vector3::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector3::operator[](int Index)
	{
		return (&x)[Index];
	}
	
	inline float Vector4::operator[](int Index) const
	{
		return (&x)[Index];
	}

	inline float &Vector4::operator[](int Index)
	{
		return (&x)[Index];
	}

	// Binary and unary addition operators ================
	
	inline Vector2 Vector2::operator+(Vector2 const &b) const
	{
		return Vector2(x + b.x, y + b.y);
	}

	inline Vector2 Vector2::operator+(float b) const
	{
		return Vector2(x + b, y + b);
	}

	inline Vector2 &Vector2::operator+=(Vector2 const &b)
	{
		x += b.x;
		y += b.y;
		return *this;
	}

	inline Vector2 &Vector2::operator+=(float b)
	{
		x += b;
		y += b;
		return *this;
	}

	inline Vector3 Vector3::operator+(Vector3 const &b) const
	{
		return Vector3(x + b.x, y + b.y, z + b.z);
	}
	
	inline Vector3 Vector3::operator+(Vector4 const &b) const
	{
		return Vector3(x + b.x, y + b.y, z + b.z);
	}

	inline Vector3 Vector3::operator+(float b) const
	{
		return Vector3(x + b, y + b, z + b);
	}

	inline Vector3 &Vector3::operator+=(Vector3 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}
	
	inline Vector3 &Vector3::operator+=(Vector4 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}

	inline Vector3 &Vector3::operator+=(float b)
	{
		x += b;
		y += b;
		z += b;
		return *this;
	}
	
	inline Vector4 Vector4::operator+(Vector3 const &b) const
	{
		return Vector4(x + b.x, y + b.y, z + b.z, 1.0f);
	}

	inline Vector4 Vector4::operator+(Vector4 const &b) const
	{
		return Vector4(x + b.x, y + b.y, z + b.z, 1.0f);
	}

	inline Vector4 Vector4::operator+(float b) const
	{
		return Vector4(x + b, y + b, z + b, 1.0f);
	}
	
	inline Vector4 &Vector4::operator+=(Vector3 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator+=(Vector4 const &b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator+=(float b)
	{
		x += b;
		y += b;
		z += b;
		return *this;
	}

	// Binary and unary subtraction operators
	
	inline Vector2 Vector2::operator-(Vector2 const &b) const
	{
		return Vector2(x - b.x, y - b.y);
	}

	inline Vector2 Vector2::operator-(float b) const
	{
		return Vector2(x - b, y - b);
	}

	inline Vector2 &Vector2::operator-=(Vector2 const &b)
	{
		x -= b.x;
		y -= b.y;
		return *this;
	}

	inline Vector2 &Vector2::operator-=(float b)
	{
		x -= b;
		y -= b;
		return *this;
	}

	inline Vector3 Vector3::operator-(Vector3 const &b) const
	{
		return Vector3(x - b.x, y - b.y, z - b.z);
	}
	
	inline Vector3 Vector3::operator-(Vector4 const &b) const
	{
		return Vector3(x - b.x, y - b.y, z - b.z);
	}

	inline Vector3 Vector3::operator-(float b) const
	{
		return Vector3(x - b, y - b, z - b);
	}

	inline Vector3 &Vector3::operator-=(Vector3 const &b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}

	inline Vector3 &Vector3::operator-=(float b)
	{
		x -= b;
		y -= b;
		z -= b;
		return *this;
	}
	
	inline Vector4 Vector4::operator-(Vector3 const &b) const
	{
		return Vector4(x - b.x, y - b.y, z - b.z, 1.0f);
	}

	inline Vector4 Vector4::operator-(Vector4 const &b) const
	{
		return Vector4(x - b.x, y - b.y, z - b.z, 1.0f);
	}

	inline Vector4 Vector4::operator-(float b) const
	{
		return Vector4(x - b, y - b, z - b, 1.0f);
	}

	inline Vector4 &Vector4::operator-=(Vector3 const &b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator-=(Vector4 const &b)
	{
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}

	inline Vector4 &Vector4::operator-=(float b)
	{
		x -= b;
		y -= b;
		z -= b;
		return *this;
	}

	// Binary and unary multiplication operators ==========
	
	inline Vector2 Vector2::operator*(float b) const
	{
		return Vector2(x * b, y * b);
	}

	inline Vector2 &Vector2::operator*=(float b)
	{
		x *= b;
		y *= b;
		return *this;
	}

	inline Vector3 Vector3::operator*(float b) const
	{
		return Vector3(x * b, y * b, z * b);
	}

	inline Vector3 &Vector3::operator*=(float b)
	{
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}
	
	inline Vector4 Vector4::operator*(float b) const
	{
		return Vector4(x * b, y * b, z * b, 1.0f);
	}

	inline Vector4 &Vector4::operator*=(float b)
	{
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}

	// Binary and unary division operators ================
	
	inline Vector2 Vector2::operator/(float b) const
	{
		return Vector2(x / b, y / b);
	}

	inline Vector2 &Vector2::operator/=(float b)
	{
		x /= b;
		y /= b;
		return *this;
	}

	inline Vector3 Vector3::operator/(float b) const
	{
		return Vector3(x / b, y / b, z / b);
	}

	inline Vector3 &Vector3::operator/=(float b)
	{
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
	
	inline Vector4 Vector4::operator/(float b) const
	{
		return Vector4(x / b, y / b, z / b, 1.0f);
	}

	inline Vector4 &Vector4::operator/=(float b)
	{
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}
}

#endif

