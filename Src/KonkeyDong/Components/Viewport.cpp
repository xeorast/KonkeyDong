#include "Viewport.hpp"

using namespace kd::math;


Viewport::Viewport(float aspectRatio, float renderWidth, float virtualWidth)
	:
	aspectRatio(aspectRatio),
	renderWidth(renderWidth),
	virtualWidth(virtualWidth)
{
	virtualHeight = virtualWidth / aspectRatio;
	renderHeight = renderWidth / aspectRatio;
	renderToVirtualScale = renderWidth / virtualWidth;
}

float Viewport::VirtualToScreenspaceSize(float virtualSize) const
{
	return virtualSize * renderToVirtualScale;
}

kd::math::PositionF2 Viewport::VirtualToScreenspacePos(kd::math::PositionF2 virtualPosition) const
{
	return virtualPosition * renderToVirtualScale;
}

void Viewport::SetVirtualWidth(float width)
{
	virtualWidth = width;
	virtualHeight = width / aspectRatio;
	renderToVirtualScale = renderWidth / virtualWidth;
}

void Viewport::SetRenderWidth(float width)
{
	renderWidth = width;
	renderHeight = width / aspectRatio;
	renderToVirtualScale = renderWidth / virtualWidth;
}

void Viewport::SetAspectRatio(float ratio)
{
	aspectRatio = ratio;
	virtualHeight = virtualWidth / aspectRatio;
	renderHeight = renderWidth / aspectRatio;
}
