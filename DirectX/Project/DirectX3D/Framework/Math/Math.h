#pragma once

namespace Math
{
	enum class Direction
	{
		NONE, UP, DOWN, LEFT, RIGHT, FRONT, BACK,
	};

	const int Random(const int& Min, const int& Max)
	{
		return rand() % (Max - Min) + Min;
	}
	const float Random(const float& Min, const float& Max)
	{
		float normal = rand() / (float)RAND_MAX;
		return (Max - Min) * normal + Min;
	}
	const double Random(const double& Min, const double& Max)
	{
		double normal = rand() / (double)RAND_MAX;
		return (Max - Min) * normal + Min;
	}
	const Vector2 Random(const Vector2& Min, const Vector2& Max)
	{
		return Vector2(Random(Min.X, Max.X), Random(Min.Y, Max.Y));
	}

	float Clamp(const float& Min, const float& Max, const float Value)
	{
		if (Value < Min)
			return Min;
		if (Value > Max)
			return Max;
		return Value;
	}

	const float Lerp(const float& Start, const float& End, float T)
	{
		T = Clamp(0.0f, 1.0f, T);
		return Start + (End - Start) * T;
	}
	const Vector2 Lerp(const Vector2& Start, const Vector2& End, float T)
	{
		T = Clamp(0.0f, 1.0f, T);
		return Start + (End - Start) * T;
	}
	const Vector3 Lerp(const Vector3& Start, const Vector3& End, float T)
	{
		T = Clamp(0.0f, 1.0f, T);
		return Start + (End - Start) * T;
	}
	// Matric Lerp(const Matrix& Start, const Matrix& End, float T);
	const Vector2 SLerp(const Vector2& Start, const Vector2& End, float T)
	{
		T = Clamp(0.0f, 1.0f, T);
		return Start + (End - Start) * (T * T);
	}
	const Vector3 SLerp(const Vector3& Start, const Vector3& End, float T)
	{
		T = Clamp(0.0f, 1.0f, T);
		return Start + (End - Start) * (T * T);
	}

	const Vector3 Cross(Vector3& Vec1, Vector3& Vec2)
	{
		return Vector3((Vec1.Y * Vec2.Z + Vec1.Z * Vec2.Y),
			(Vec1.X * Vec2.Z + Vec1.Z * Vec2.X),
			(Vec1.Y * Vec2.X + Vec1.X * Vec2.Y));
	}
	const float Dot(Vector3& Vec1, Vector3 Vec2)
	{
		return float((Vec1.X * Vec2.X) + (Vec1.Y * Vec2.Y) + (Vec1.Z * Vec2.Z));
	}

	const float Distance(const Vector2& Vec1, const Vector2& Vec2)
	{
		return float((Vec2 - Vec1).Length());
	}
	const float Distance(const Vector3& Vec1, const Vector3& Vec2)
	{
		return float((Vec2 - Vec1).Length());
	}

	const bool NearyEqual(const float& s1, const float& s2)
	{
		return abs(s1 - s2) < FLT_EPSILON;
	}

	const Vector3 GetNormalFromPolygon(const Vector3& V0, const Vector3& V1, const Vector3& V2)
	{
		Vector3 e0, e1;
		e0 = V1 - V0;
		e1 = V2 - V0;

		return Cross(e0, e1).GetNormalize();
	}
	const Vector3 GetRotFromNormal(const Vector3& Vec)
	{
		Vector3 yAxis(0.0, 1.0, 0.0);
		Vector3 normal = Vec.GetNormalize();
		float angle = Dot(normal, yAxis);
		Vector3 axis = Cross(normal, yAxis);
		if (axis == Vector3::ZeroVector())
			return axis;

		XMVECTOR axisVector = XMVectorSet((float)axis.X, (float)axis.Y, (float)axis.Z, 0.0);
		return XMQuaternionRotationNormal(axisVector, angle) * -1.0f;
	}
	//const Vector3 VectorToRotation(const Vector3& Vec)
	//{
	//	Vector3 yAxis(0.0, 1.0, 0.0);
	//	Vector3 normal = Vec.GetNormalize();
	//	float angle = Dot(normal, yAxis);
	//	Vector3 axis = Cross(normal, yAxis);
	//	if (axis == Vector3::ZeroVector())
	//		return axis;

	//	XMVECTOR axisVector = XMVectorSet(axis.X, axis.Y, axis.Z, 0.0);
	//	return XMQuaternionRotationNormal(axisVector, angle) * -1.0f;
	//}

	const Vector3 ClosestPointOnLine(const Vector3& Start, const Vector3& End, Vector3& point)
	{
		Vector3 line = End - Start;
		Vector3 a = point - Start;

		float X = Dot(line, a);
		float Y = Dot(line, line);

		float T = Clamp(0, 1, X / Y);

		return Start + line * T;
	}

	const double VectorToRadian(const Vector2& DirVector)
	{
		Vector2 dirNormal = DirVector.GetNormalize();
		double angle = atan2(DirVector.Y, DirVector.X);
		angle += XM_PI;
		return angle;
	}
	const double VectorToRadian(const float& X, const float& Y)
	{
		return VectorToRadian(Vector2(X, Y));
	}
	const double VectorToAngle(const Vector2& DirVector)
	{
		Vector2 dirNormal = DirVector.GetNormalize();
		double angle = atan2(dirNormal.Y, dirNormal.X);
		angle = angle * (180.0 / XM_PI);
		angle -= 180.0 + 90.0;
		angle = (int)angle % 360;
		angle *= -1.0;

		return angle;
	}
	const float VectorToAngle(const float& X, const float& Y)
	{
		return (float)VectorToAngle(Vector2(X, Y));
	}

	const float RadianToDegree(const float& Value)
	{
		return Value * (180.0f / XM_PI);
	}
	const float DegreeToRadian(const float& Value)
	{
		return Value * (XM_PI / 180.0f);
	}
}