#include "Entity.hpp"
#include "../Utils.h"

Entity::Entity(kd::math::PositionF2 position, kd::math::SizeF2 size, Texture* pTexture)
	:
	position(position),
	size(size),
	pTexture(pTexture)
{
}

void Entity::Draw(Graphics* pGfx)
{
	SDL_FRect dest = CreateCenterFRect(position.X, position.Y, size.X, size.Y);
	pGfx->DrawTexture(pTexture, NULL, &dest);
}

void Entity::Move(kd::math::Vec2 distance)
{
	position += distance;
}
