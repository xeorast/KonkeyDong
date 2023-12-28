#pragma once

#include <cmath>

namespace kd::math {
	struct Vec2 {
		Vec2(float x, float y) :X(x), Y(y) {};
		float X;
		float Y;

		Vec2 operator+(const Vec2& other) const {
			return Vec2(X + other.X, Y + other.Y);
		}

		Vec2& operator+=(const Vec2& other) {
			X += other.X;
			Y += other.Y;
			return *this;
		}

		Vec2 operator-(const Vec2& other) const {
			return Vec2(X - other.X, Y - other.Y);
		}

		Vec2& operator-=(const Vec2& other) {
			X -= other.X;
			Y -= other.Y;
			return *this;
		}

		Vec2 operator*(float scalar) const {
			return Vec2(X * scalar, Y * scalar);
		}

		Vec2& operator*=(float scalar) {
			X *= scalar;
			Y *= scalar;
			return *this;
		}

		Vec2 operator/(float scalar) const {
			return Vec2(X / scalar, Y / scalar);
		}

		Vec2& operator/=(float scalar) {
			X /= scalar;
			Y /= scalar;
			return *this;
		}

		float magnitude() const {
			return std::sqrt(X * X + Y * Y);
		}

		Vec2 normalize() const {
			float mag = magnitude();
			if (mag != 0.0f) {
				return *this / mag;
			}
			else {
				return *this;	// Avoid division by zero
			}
		}

		float dot(const Vec2& other) const {
			return X * other.X + Y * other.Y;
		}

		float cross(const Vec2& other) const {
			return X * other.Y - Y * other.X;
		}

	};

	typedef Vec2 SizeF2;
	typedef Vec2 PositionF2;
}
