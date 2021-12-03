#include "header.h"
#include "MyImage.h"

#include "ImageManager.h"
#include "DrawingSurface.h"
#include "BaseEngine.h"


// Standard constructor taking a pointer to the image which is being used
MyImage::MyImage(std::shared_ptr<RawImageData> theData)
	: theData(theData)
	, m_pRescaleSurface(nullptr)
	, m_iTransparencyColour(-1)
{
}

void MyImage::renderImageMirror(DrawingSurface* pTarget, int iXSource, int iYSource, int iXTarget, int iYTarget, int iWidth, int iHeight) const
{

	int iXS, iYS = iYSource + iHeight, iXT, iYT = iYTarget;

	for (int iYOffset = 0; iYOffset < iHeight; iYOffset++)
	{
		iXS = iXSource;
		iXT = iXTarget;
		for (int iXOffset = 0; iXOffset < iWidth; iXOffset++)
		{
			// Draw pixel unless it matches the transparency colour
			if ((m_iTransparencyColour == -1) || (theData->getRawPixelColour(iXS, iYS) != m_iTransparencyColour))
				pTarget->setPixel(iXT, iYT, theData->getRawPixelColour(iXS, iYS));
			iXS++;
			iXT++;
		}
		iYS--;
		iYT++;
	}
}

void MyImage::renderImage(DrawingSurface* pTarget, int iXSource, int iYSource, int iXTarget, int iYTarget, int iWidth, int iHeight) const
{

	int iXS, iYS = iYSource, iXT, iYT = iYTarget;

	for (int iYOffset = 0; iYOffset < iHeight; iYOffset++)
	{
		iXS = iXSource;
		iXT = iXTarget;
		for (int iXOffset = 0; iXOffset < iWidth; iXOffset++)
		{
			// Draw pixel unless it matches the transparency colour
			if ((m_iTransparencyColour == -1) || (theData->getRawPixelColour(iXS, iYS) != m_iTransparencyColour))
				pTarget->setPixel(iXT, iYT, theData->getRawPixelColour(iXS, iYS));
			
			iXS++;
			iXT++;
		}
		iYS++;
		iYT++;
	}
}



