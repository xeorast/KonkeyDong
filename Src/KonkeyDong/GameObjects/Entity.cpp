#include "Entity.hpp"
#include "../Utils.h"

Entity::Entity(kd::math::Vec2 position, Texture* pTexture)
	:
	position(position),
	pTexture(pTexture)
{
}

void Entity::Draw(Graphics* pGfx)
{
	SDL_Rect dest = CreateCenterRect(static_cast<int>(position.X), static_cast<int>(position.Y), pTexture->GetWidth(), pTexture->GetHeight());
	pGfx->DrawTexture(pTexture, NULL, &dest);
}

void Entity::Move(kd::math::Vec2 distance)
{
	position += distance;
}
