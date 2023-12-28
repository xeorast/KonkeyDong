#pragma once

#include "../Data/Vec2.hpp"
#include "../Components/Texture.hpp"

class Entity
{
public:
	Entity(kd::math::PositionF2 position, kd::math::SizeF2 size, Texture* pTexture);
	Entity(const Entity& entity) = delete;
	Entity& operator=(const Entity&) = delete;

	void Draw(Graphics* pGfx);
	void Move(kd::math::Vec2 distance);

private:
	kd::math::PositionF2 position;
	kd::math::SizeF2 size;
	Texture* pTexture;
};
