
#pragma once

#include "header.h"
#include <memory>
#include "RawImageData.h"

class DrawingSurface;
class BaseEngine;

class MyImage
{
public:

	// Standard constructor taking a pointer to the image which is being used
	MyImage(std::shared_ptr<RawImageData> theData);

	~MyImage()
	{
		if (m_pRescaleSurface != nullptr)
		{
			SDL_FreeSurface(m_pRescaleSurface);
			m_pRescaleSurface = nullptr;
		}
	}

	// Ask for the width of the image
	int getWidth() const { return theData->getWidth(); }

	// Ask for the height of the image
	int getHeight() const { return theData->getHeight(); }

	// Get the colour of a specified pixel, by x and y position
	int getPixelColour(int x, int y) const { return theData->getRawPixelColour(x, y); }

	// Draw the image to the specified surface - just copying pixel colours with no extra work
	void renderImageMirror(DrawingSurface* pTarget,
		int iXSource, int iYSource,
		int iXTarget, int iYTarget,
		int iWidth, int iHeight) const;

	void renderImage(DrawingSurface* pTarget,
		int iXSource, int iYSource,
		int iXTarget, int iYTarget,
		int iWidth, int iHeight) const;


protected:
	// Shared pointer to the actual image data
	std::shared_ptr<RawImageData> theData;

	// Surface used only for rescaling when using a blit. Cached to avoid continuous recreation.
	SDL_Surface* m_pRescaleSurface;

	int m_iTransparencyColour;
};





