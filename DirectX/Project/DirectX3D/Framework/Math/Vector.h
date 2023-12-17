#pragma once

using namespace std;

struct Vector2
{
public:
	Vector2() {}
	Vector2(double N) : X(N), Y(N) {}
	Vector2(double X, double Y) : X(X), Y(Y) {}
	Vector2(float N) : X(N), Y(N) {}
	Vector2(float X, float Y) : X(X), Y(Y) {}

	//////////////////////////////////////////////////////////////////////////////
	// operator overloading
	//////////////////////////////////////////////////////////////////////////////
	const bool operator==(const Vector2& Value) const
	{
		return (X == Value.X) && (Y == Value.Y);
	}
	const bool operator!=(const Vector2& Value) const
	{
		return (X != Value.X) || (Y != Value.Y);
	}

	Vector2 operator+(const double& Value) const
	{
		return Vector2(X + Value, Y + Value);
	}
	Vector2 operator-(const double& Value) const
	{
		return Vector2(X - Value, Y - Value);
	}
	Vector2 operator*(const double& Value) const
	{
		return Vector2(X * Value, Y * Value);
	}
	Vector2 operator/(const double& Value) const
	{
		return Vector2(X / Value, Y / Value);
	}
	Vector2 operator+(const Vector2& Value) const
	{
		return Vector2(X + Value.X, Y + Value.Y);
	}
	Vector2 operator-(const Vector2& Value) const
	{
		return Vector2(X - Value.X, Y - Value.Y);
	}

	Vector2& operator+=(const double& Value)
	{
		X += Value;
		Y += Value;

		return *this;
	}
	Vector2& operator-=(const double& Value)
	{
		X -= Value;
		Y -= Value;

		return *this;
	}
	Vector2& operator*=(const double& Value)
	{
		X *= Value;
		Y *= Value;

		return *this;
	}
	Vector2& operator/=(const double& Value)
	{
		X /= Value;
		Y /= Value;

		return *this;
	}
	Vector2& operator+=(const Vector2& Value)
	{
		X += Value.X;
		Y += Value.Y;

		return *this;
	}
	Vector2& operator-=(const Vector2& Value)
	{
		X -= Value.X;
		Y -= Value.Y;

		return *this;
	}
	//////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////////
	// functions
	//////////////////////////////////////////////////////////////////////////////
	const double Length() const
	{
		return sqrt(X * X + Y * Y);
	}

	Vector2 GetNormalize() const
	{ 
		double length = Length();
		return Vector2(X / length, Y / length);
	}

	void Normalize()
	{
		double length = Length();
		X /= length;
		Y /= length;
	}

	const double Angle() const
	{
		return atan2(Y, X);
	}

	static const Vector2 ZeroVector() { return Vector2(0.0, 0.0); }

	string ToString()
	{
		return ("X : " + to_string(X) + ", Y : " + to_string(Y));
	}
	//////////////////////////////////////////////////////////////////////////////

public:
	double X = 0.0;
	double Y = 0.0;
};

struct Vector3
{
public:
	Vector3() {}
	Vector3(double N) : X(N), Y(N), Z(N) {}
	Vector3(double X, double Y, double Z) : X(X), Y(Y), Z(Z) {}
	Vector3(XMVECTOR Value)
	{
		X = XMVectorGetX(Value);
		Y = XMVectorGetY(Value);
		Z = XMVectorGetZ(Value);
	}

	//////////////////////////////////////////////////////////////////////////////
	// operator overloading
	//////////////////////////////////////////////////////////////////////////////
	const bool operator==(const Vector3& Value)
	{
		return (X == Value.X && Y == Value.Y && Z == Value.Z);
	}
	const bool operator!=(const Vector3& Value)
	{
		return (X != Value.X || Y != Value.Y || Z != Value.Z);
	}

	Vector3& operator=(const Float3& Value)
	{
		X = Value.x;
		Y = Value.y;
		Z = Value.z;

		return *this;
	}

	const Vector3 operator+(const double& Value) const { return Vector3(X + Value, Y + Value, Z + Value); }
	const Vector3 operator-(const double& Value) const { return Vector3(X - Value, Y - Value, Z - Value); }
	const Vector3 operator+(const Vector3& Value) const { return Vector3(X + Value.X, Y + Value.Y, Z + Value.Z); }
	const Vector3 operator-(const Vector3& Value) const { return Vector3(X - Value.X, Y - Value.Y, Z - Value.Z); }
	const Vector3 operator*(const double& Value) const { return Vector3(X * Value, Y * Value, Z * Value); }
	const Vector3 operator/(const double& Value) const { return Vector3(X / Value, Y / Value, Z / Value); }

	Vector3& operator+=(const double& Value)
	{
		X += Value;
		Y += Value;
		Z += Value;

		return *this;
	}
	Vector3& operator-=(const double& Value)
	{
		X -= Value;
		Y -= Value;
		Z -= Value;

		return *this;
	}
	Vector3& operator+=(const Vector3& Value)
	{
		X += Value.X;
		Y += Value.Y;
		Z += Value.Z;

		return *this;
	}
	Vector3& operator-=(const Vector3 & Value)
	{
		X -= Value.X;
		Y -= Value.Y;
		Z -= Value.Z;

		return *this;
	}
	Vector3& operator*=(const double& Value)
	{
		X *= Value;
		Y *= Value;
		Z *= Value;

		return *this;
	}
	Vector3& operator/=(const double& Value)
	{
		X /= Value;
		Y /= Value;
		Z /= Value;

		return *this;
	}
	//////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////
	// functions
	//////////////////////////////////////////////////////////////////////////////
	const double Length() const { return sqrt(X * X + Y * Y + Z * Z); }

	Vector3 GetNormalize() const
	{
		double length = Length();
		return Vector3(X / length, Y / length, Z / length);
	}

	void Nornalize()
	{
		double length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}

	static const Vector3 ZeroVector() { return Vector3(0.0, 0.0, 0.0); }
	static const Vector3 Right() { return Vector3(1.0, 0.0, 0.0); }
	static const Vector3 Up() { return Vector3(0.0, 1.0, 0.0); }
	static const Vector3 Forward() { return Vector3(0.0, 0.0, 1.0); }

	string ToString() const
	{
		return ("X : " + to_string(X) + ", Y : " + to_string(Y) + ", Z : " + to_string(Z));
	}
	//////////////////////////////////////////////////////////////////////////////

	XMVECTOR GetValue() { return XMVectorSet((float)X, (float)Y, (float)Z, 0.0); }

public:
	double X = 0.0;
	double Y = 0.0;
	double Z = 0.0;
};