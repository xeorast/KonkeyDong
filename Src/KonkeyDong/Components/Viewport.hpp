#pragma once

#include "../Data/Vec2.hpp"

class Viewport
{
public:
	Viewport(float aspectRatio, float renderWidth, float virtualWidth);
	Viewport(const Viewport&) = delete;
	Viewport& operator=(const Viewport&) = delete;

	float VirtualToScreenspaceSize(float virtualSize) const;
	kd::math::PositionF2 VirtualToScreenspacePos(kd::math::PositionF2 virtualPosition) const;

	float GetVirtualWidth() const { return virtualWidth; }
	float GetVirtualHeight() const { return virtualHeight; }

	float GetRenderWidth() const { return renderWidth; }
	float GetRenderHeight() const { return renderHeight; }

	float GetAspectRatio() const { return aspectRatio; }

	void SetVirtualWidth(float width);
	void SetRenderWidth(float width);
	void SetAspectRatio(float ratio);

private:
	float aspectRatio;
	float renderToVirtualScale;

	float virtualWidth;
	float virtualHeight;
	float renderWidth;
	float renderHeight;
};
