#include <windows.h>
#include "imge_bmp.h"
#include <iostream>
#include <atlstr.h>
#include <string>
#include <cmath>
#define PI 3.14159265

using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace DataVisualization::Charting;

double tempAngle;
long size, newpos, newpos2;
int width, height, otsuValue;
int tempValue;
BYTE* buffer;
BYTE* otsubuf;
BYTE* taggedArray;
BYTE* erosionArray;
BYTE* raw_intensity;
BYTE* dilationArray;
BYTE* dilationerosionArray;
BYTE* erosiondilationArray;
int* tempArray;
int* NonMaxSupArray;
int* histogramTaked;
BYTE* BinaryImageArray;
int* GradientMagnitude;
int* GradientDirection;
int* GaussianPixelArray;
int* HoughTransformArray;

void OpenImage(PictureBox^ picOriginal)
{
	LPCTSTR input;
	CString str;
	OpenFileDialog^ openfd = gcnew OpenFileDialog;
	openfd->DefaultExt = ".bmp";
	openfd->Filter = "ımage files*.bmp|*.bmp";
	if (openfd->ShowDialog() == DialogResult::OK) {
		str = openfd->FileName;
		input = (LPCTSTR)str;
		buffer = LoadBMP(width, height, size, input);
		picOriginal->ImageLocation = openfd->FileName;
	}
}
void SaveImage(PictureBox^ picSave)
{
	SaveFileDialog^ savefd = gcnew SaveFileDialog;
	savefd->DefaultExt = ".bmp";
	savefd->Filter = "Image Files*.BMP|*.BMP";
	if (savefd->ShowDialog() == DialogResult::OK)
		picSave->Image->Save(savefd->FileName);
}
void SetImage(BYTE* im_buffer, PictureBox^ convertedPic)
{
	Color color;
	Bitmap^ surface = gcnew Bitmap(width, height);
	convertedPic->Image = surface;
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++) {
			newpos = x * width + y;
			color = Color::FromArgb(*(im_buffer + newpos), *(im_buffer + newpos), *(im_buffer + newpos));
			surface->SetPixel(y, x, color);
		}
}
int* BuildHistogram(BYTE* im_buffer, int maskSize = 0)
{
	histogramTaked = new int[256];
	for (int i = 0; i < 256; i++)
	{
		histogramTaked[i] = 0;
	}
	for (int x = maskSize; x < height - (maskSize); x++)
		for (int y = maskSize; y < width - (maskSize); y++) {
			newpos = x * width + y;
			histogramTaked[(im_buffer[newpos])]++;
		}
	return histogramTaked;
}
void DrawHistogram(BYTE* im_buffer, Chart^ chart, ListBox^ listHist, int maskSize = 0)
{
	histogramTaked = BuildHistogram(im_buffer, maskSize);
	listHist->Items->Clear();
	chart->Series["hist"]->Points->Clear();
	for (int i = 0; i < 256; i++)
	{
		chart->Series["hist"]->Points->AddXY(i, histogramTaked[i]);
		listHist->Items->Add("Color: " + i + " = " + histogramTaked[i]);
	}
}
// First Work
BYTE* BuildGrayImage()
{
	raw_intensity = ConvertBMPToIntensity(buffer, width, height);
	return raw_intensity;
}
BYTE* BuildOtsuThresholdImage()
{
	otsubuf = new BYTE[width * height];
	raw_intensity = BuildGrayImage();
	histogramTaked = BuildHistogram(raw_intensity);
	double fmax = 0;
	double m1, m2, S, toplam1 = 0.0, toplam2 = 0.0;
	int nTop = 0, n1 = 0, n2;
	for (int i = 0; i < 256; i++)
	{
		toplam1 += (double)i * (double)histogramTaked[i];
		nTop += histogramTaked[i];
	}
	for (int i = 0; i < 256; i++)
	{
		n1 += histogramTaked[i];
		if (n1 == 0)
			continue;
		n2 = nTop - n1;
		if (n2 == 0)
			break;
		toplam2 += (double)i * (double)histogramTaked[i];
		m1 = toplam2 / n1;
		m2 = (toplam1 - toplam2) / n2;
		S = (double)n1 * (double)n2 * (m1 - m2) * (m1 - m2);
		if (S > fmax)
		{
			fmax = S;
			otsuValue = i;
		}
	}
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
		{
			newpos = x * width + y;
			if (raw_intensity[newpos] < otsuValue)
				otsubuf[newpos] = 255;
			else
				otsubuf[newpos] = 0;
		}
	return otsubuf;
}
BYTE* BUildKMeansThresholdImage()
{
	float t1 = 0, t2 = 255, t11 = -1, t22 = -1;
	double sum1 = 0, sum2 = 0;
	double division1 = 0, division2 = 0;

	raw_intensity = BuildGrayImage();
	int* histogram_array = new int[256];
	histogram_array = BuildHistogram(raw_intensity);

	while (true)
	{
		for (int i = 0; i < 256; i++)
		{
			if (fabs(i - t1) < fabs(i - t2))
			{
				sum1 += (i * histogram_array[i]);
				division1 += histogram_array[i];
			}
			else
			{
				sum2 += (i * histogram_array[i]);
				division2 += histogram_array[i];
			}
		}

		t11 = sum1 / division1;
		t22 = sum2 / division2;

		if (t1 == t11 && t2 == t22)
			break;

		t1 = t11;
		t2 = t22;
	}

	BYTE* k_means_buffer = new BYTE[width * height];
	k_means_buffer = raw_intensity;
	for (int i = 0; i < width * height; i++)
	{
		if (fabs(k_means_buffer[i] - t11) < fabs(k_means_buffer[i] - t22))
			k_means_buffer[i] = 255;
		else
			k_means_buffer[i] = 0;
	}

	return k_means_buffer;
}
BYTE* BuildDilationImage(BYTE* im_buffer)
{
	dilationArray = new BYTE[width * height];
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
		{
			newpos = x * width + y;
			if (x != 0 && y != 0 && y != width - 1 && x != height - 1)
			{
				int frameArray[9] = { im_buffer[newpos - width - 1], im_buffer[newpos - width], im_buffer[newpos - width + 1], im_buffer[newpos - 1], im_buffer[newpos], im_buffer[newpos + 1], im_buffer[newpos + width - 1], im_buffer[newpos + width], im_buffer[newpos + width + 1] };
				if ((frameArray[0] || frameArray[1] || frameArray[2] || frameArray[3] || frameArray[4] || frameArray[5] || frameArray[6] || frameArray[7] || frameArray[8]))
					dilationArray[newpos] = 255;
				else
					dilationArray[newpos] = 0;
			}
			else
				dilationArray[newpos] = 0;
		}
	return dilationArray;
}
BYTE* BuildErosionImage(BYTE* im_buffer)
{
	erosionArray = new BYTE[width * height];
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
		{
			newpos = x * width + y;
			if (x != 0 && y != 0 && y != width - 1 && x != height - 1)
			{
				int frameArray[9] = { im_buffer[newpos - width - 1], im_buffer[newpos - width], im_buffer[newpos - width + 1], im_buffer[newpos - 1], im_buffer[newpos], im_buffer[newpos + 1], im_buffer[newpos + width - 1], im_buffer[newpos + width], im_buffer[newpos + width + 1] };
				if ((frameArray[0] && frameArray[1] && frameArray[2] && frameArray[3] && frameArray[4] && frameArray[5] && frameArray[6] && frameArray[7] && frameArray[8]))
					erosionArray[newpos] = 255;
				else
					erosionArray[newpos] = 0;
			}
			else
				erosionArray[newpos] = 0;
		}
	return erosionArray;
}
BYTE* BuildDilationErosionImage(BYTE* im_buffer)
{
	dilationArray = BuildDilationImage(im_buffer);
	dilationerosionArray = BuildErosionImage(dilationArray);
	return dilationerosionArray;
}
BYTE* BuildErosionDilationImage(BYTE* im_buffer)
{
	erosionArray = BuildErosionImage(im_buffer);
	erosiondilationArray = BuildDilationImage(erosionArray);
	return erosiondilationArray;
}
BYTE* BuildTaggedArray(BYTE* im_buffer)
{
	taggedArray = new BYTE[width * height];
	taggedArray = im_buffer;;
	tempArray = new int[(width * height) / 4];
	int labelValue = 0;
	tempValue = 0;
	int index = 1;
	int temp;
	// 0-255 Again
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
		{
			newpos = x * width + y;
			if (taggedArray[newpos] != 0)
				taggedArray[newpos] = 255;
			else
				taggedArray[newpos] = 0;
		}
	// Frame --> 0
	for (int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
		{
			newpos = x * width + y;
			if (x == 0 || y == 0 || x == height - 1 || y == width - 1)
				taggedArray[newpos] = 0;
		}
	// Fill tempArray 
	for (int i = 0; i < width * height / 4; i++)
		tempArray[i] = i;
	// Pass 1
	for (int x = 1; x < height; x++)
		for (int y = 1; y < width; y++)
		{
			newpos = x * width + y;
			if (taggedArray[newpos] > 0)
			{
				int frameArray[2] = { taggedArray[newpos - width], taggedArray[newpos - 1] };
				int topFrame = frameArray[0];
				int leftFrame = frameArray[1];


				if (topFrame == leftFrame)
				{
					// tum komsulari 0 ise
					if (topFrame == 0)
					{
						taggedArray[newpos] = ++labelValue;  // Yeni Etiket
					}
					else
						taggedArray[newpos] = topFrame;
				}
				else
				{
					if (topFrame == 0)
						taggedArray[newpos] = leftFrame;
					else if (leftFrame == 0)
						taggedArray[newpos] = topFrame;
					else
					{
						taggedArray[newpos] = min(topFrame, leftFrame);
						tempArray[topFrame] = taggedArray[newpos];
						tempArray[leftFrame] = taggedArray[newpos];
					}
				}
			}
		}
	// Pass 2
	for (int x = height - 2; x >= 0; x--)
		for (int y = width - 2; y >= 0; y--)
		{
			newpos = x * width + y;
			if (taggedArray[newpos] > 0)
			{
				int frameArray[2] = { taggedArray[newpos + 1],taggedArray[newpos + width] };
				int rightFrame = frameArray[0];
				int bottomFrame = frameArray[1];
				if (rightFrame == bottomFrame && rightFrame == 0)
					continue;
				else if (rightFrame == 0 || bottomFrame == 0)
				{
					if (taggedArray[newpos] == rightFrame || taggedArray[newpos] == bottomFrame)
						continue;
				}
				if (rightFrame != bottomFrame)
				{
					if (rightFrame == 0)
					{
						temp = min(bottomFrame, taggedArray[newpos]);
						tempArray[bottomFrame] = temp;
						tempArray[taggedArray[newpos]] = temp;
						taggedArray[newpos] = temp;
					}
					else if (bottomFrame == 0)
					{
						temp = min(rightFrame, taggedArray[newpos]);
						tempArray[rightFrame] = temp;
						tempArray[taggedArray[newpos]] = temp;
						taggedArray[newpos] = temp;
					}
					else
					{
						temp = min(rightFrame, bottomFrame);
						temp = min(temp, taggedArray[newpos]);
						tempArray[rightFrame] = temp;
						tempArray[taggedArray[newpos]] = temp;
						tempArray[bottomFrame] = temp;
						taggedArray[newpos] = temp;
					}
				}
				else
				{
					if (rightFrame != 0)
					{
						temp = min(rightFrame, bottomFrame);
						temp = min(temp, taggedArray[newpos]);
						tempArray[rightFrame] = temp;
						tempArray[taggedArray[newpos]] = temp;
						tempArray[bottomFrame] = temp;
						taggedArray[newpos] = temp;
					}
				}
			}
		}
	// Sort tempArray	
	while (index <= labelValue)
	{
		if (tempArray[index] == index)
		{
			tempValue++;
			tempArray[index] = tempValue;
		}
		else
			tempArray[index] = tempArray[tempArray[index]];
		index++;
	}
	// Change taggedArray
	for (int x = 1; x < height; x++)
		for (int y = 1; y < width; y++)
		{
			newpos = x * width + y;
			if (taggedArray[newpos] > 0)
			{
				taggedArray[newpos] = tempArray[taggedArray[newpos]];
			}
		}
	return taggedArray;
}
// Second Work
int* BuildSmoothImage(int maskSize = 0)
{
	GaussianPixelArray = new int[width * height];
	raw_intensity = BuildGrayImage();
	int maskGauss[] = { 1,4,7,4,1,4,16,26,16,4,7,26,41,26,7,4,16,26,16,4,1,4,7,4,1 };     //--273--//
	//int maskGauss[] = { 1,4,6,4,1,4,16,24,16,4,6,24,36,24,6,4,16,24,16,4,1,4,6,4,1 };   //--256--//
	// Noise Reduction
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			int maskTop = 0;
			int k = 0;
			for (int i = -maskSize; i <= maskSize; i++)
				for (int j = -maskSize; j <= maskSize; j++)
				{
					newpos = (x + i) * width + (y + j);
					maskTop += raw_intensity[newpos] * maskGauss[k];
					k++;
				}
			newpos = x * width + y;
			GaussianPixelArray[newpos] = maskTop / 273;
		}
	return GaussianPixelArray;
}
int* BuildGradientImage(int maskSize = 0)
{
	GradientMagnitude = new int[width * height];
	GradientDirection = new int[width * height];
	GaussianPixelArray = BuildSmoothImage(2);
	int maskSobelX[] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	int maskSobelY[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
	int pixSobelX, pixSobelY;
	// Gradient Calculation
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			pixSobelX = 0;
			pixSobelY = 0;
			int k = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					newpos = ((x + i) * (width)+(y + j));
					pixSobelX += GaussianPixelArray[newpos] * maskSobelX[k];
					pixSobelY += GaussianPixelArray[newpos] * maskSobelY[k];
					k++;
				}
			}
			pixSobelX == 0 ? pixSobelX += 1 : pixSobelX;
			newpos = x * width + y;
			GradientDirection[newpos] = atan(pixSobelY / pixSobelX);
			//GradientMagnitude[newpos] = abs(pixSobelX) + abs(pixSobelY);
			GradientMagnitude[newpos] = (int)(sqrt(pixSobelX * pixSobelX + pixSobelY * pixSobelY));
		}
	return GradientMagnitude;
}
int* BuildNonMaxSupImage(int maskSize = 0)
{
	int a, b = 0;
	NonMaxSupArray = new int[width * height];
	GradientMagnitude = BuildGradientImage(3);
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			tempAngle = GradientDirection[newpos] * 180.0 / PI;
			tempAngle < 0 ? tempAngle += 180 : tempAngle;
			// if angle 135 
			if (isless(22.5, tempAngle) && islessequal(tempAngle, 67.5))
			{
				if ((x == maskSize && y == width - maskSize - 1) || (x == height - maskSize - 1 && y == maskSize))
					continue;
				else if (x == maskSize || y == maskSize)
					a = GradientMagnitude[newpos + width + 1];
				else if (x == height - maskSize - 1 || y == width - maskSize - 1)
					a = GradientMagnitude[newpos - width - 1];
				else
				{
					a = GradientMagnitude[newpos + width + 1];
					b = GradientMagnitude[newpos - width - 1];
				}
			}
			// if angle 90 
			else if (isless(67.5, tempAngle) && islessequal(tempAngle, 112.5))
			{
				if (x == maskSize)
					a = GradientMagnitude[newpos + width];
				else if (x == height - maskSize - 1)
					a = GradientMagnitude[newpos - width];
				else
				{
					a = GradientMagnitude[newpos - width];
					b = GradientMagnitude[newpos + width];
				}
			}
			//if angle 45 
			else if (isless(112.5, tempAngle) && islessequal(tempAngle, 157.5))
			{
				if ((x == maskSize && y == maskSize) || (x == height - maskSize - 1 && y == width - maskSize - 1))
					continue;
				else if (x == height - maskSize - 1 || y == maskSize)
					a = GradientMagnitude[newpos - width + 1];
				else if (x == maskSize || y == width - maskSize - 1)
					a = GradientMagnitude[newpos + width - 1];
				else
				{
					a = GradientMagnitude[newpos + width - 1];
					b = GradientMagnitude[newpos - width + 1];
				}
			}
			// if angle 0 
			else
			{
				if (y == maskSize)
					a = GradientMagnitude[newpos + 1];
				else if (y == width - maskSize - 1)
					a = GradientMagnitude[newpos - 1];
				else
				{
					a = GradientMagnitude[newpos - 1];
					b = GradientMagnitude[newpos + 1];
				}
			}
			if (GradientMagnitude[newpos] >= a && GradientMagnitude[newpos] >= b)
				NonMaxSupArray[newpos] = GradientMagnitude[newpos];
			else
				NonMaxSupArray[newpos] = 0;
		}
	return NonMaxSupArray;
}
int EdgeTrackingHysteresis(int x, int y, long newpos, int* NonMaxSupArray, int maskSize = 0)
{
	int a, b = 1;
	long a1, b1;
	if (islessequal((maskSize * width) + maskSize, newpos) && islessequal(newpos, (height - maskSize - 1) * width + (width - maskSize - 1)))
	{
		if (NonMaxSupArray[newpos] == 2)
		{
			tempAngle = GradientDirection[newpos] * 180.0 / PI;
			tempAngle < 0 ? tempAngle += 180 : tempAngle;
			// if angle 135 
			if (islessequal(22.5, tempAngle) && isless(tempAngle, 67.5))
			{
				if (x == height - maskSize - 1 || y == maskSize)
					a = NonMaxSupArray[newpos - width + 1];
				else if (x == maskSize || y == width - maskSize - 1)
					a = NonMaxSupArray[newpos + width - 1];
				else
				{
					a = NonMaxSupArray[newpos + width - 1];
					a1 = newpos + width - 1;
					b = NonMaxSupArray[newpos - width + 1];
					b1 = newpos - width + 1;
				}
			}
			// if angle 90 
			else if (islessequal(67.5, tempAngle) && isless(tempAngle, 112.5))
			{
				if (y == maskSize)
					a = NonMaxSupArray[newpos + 1];
				else if (y == width - maskSize - 1)
					a = NonMaxSupArray[newpos - 1];
				else
				{
					a = NonMaxSupArray[newpos + 1];
					a1 = newpos + 1;
					b = NonMaxSupArray[newpos - 1];
					b1 = newpos - 1;
				}
			}
			//if angle 45 
			else if (islessequal(112.5, tempAngle) && isless(tempAngle, 157.5))
			{
				if (x == maskSize || y == maskSize)
					a = NonMaxSupArray[newpos + width + 1];
				else if (x == height - maskSize - 1 || y == width - maskSize - 1)
					a = NonMaxSupArray[newpos - width - 1];
				else
				{
					a = NonMaxSupArray[newpos - width - 1];
					a1 = newpos - width - 1;
					b = NonMaxSupArray[newpos + width + 1];
					b1 = newpos + width + 1;
				}
			}
			// if angle 0
			else
			{
				if (x == maskSize)
					a = NonMaxSupArray[newpos + width];
				else if (x == height - maskSize - 1)
					a = NonMaxSupArray[newpos - width];
				else
				{
					a = NonMaxSupArray[newpos - width];
					a1 = newpos - width;
					b = NonMaxSupArray[newpos + width];
					b1 = newpos + width;
				}
			}
			if (a == 1 && b == 1)
				return 1;
			/*else if (a == 2 && b == 1)
				return EdgeTrackingHysteresis(x, y, a1, NonMaxSupArray, maskSize);
			else if (a == 1 && b == 2)
				return EdgeTrackingHysteresis(x, y, b1, NonMaxSupArray, maskSize);
			else if (a == 2 && b == 2)
			{
				a = EdgeTrackingHysteresis(x, y, a1, NonMaxSupArray, maskSize);
				b = EdgeTrackingHysteresis(x, y, b1, NonMaxSupArray, maskSize);
				if (a == 1 && b == 1)
					return 1;
				else if (a == 2 && b == 1)
					return EdgeTrackingHysteresis(x, y, a1, NonMaxSupArray, maskSize);
				else if (a == 1 && b == 2)
					return EdgeTrackingHysteresis(x, y, b1, NonMaxSupArray, maskSize);
				else
					return 0;
			}*/
			else  // 00 01 02 10 12 20 21 22 
				return 0;
		}
		else if (NonMaxSupArray[newpos] == 1)
			return 1;
		else if (NonMaxSupArray[newpos] == 0)
			return 0;
	}
	else
		return 0;
}
BYTE* BuildBinaryEdgeImage(int maskSize = 0)
{
	BinaryImageArray = new BYTE[width * height];
	NonMaxSupArray = BuildNonMaxSupImage(3);
	int maxPix = 0;
	// Max Pixel
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			if (maxPix < NonMaxSupArray[newpos])
				maxPix = NonMaxSupArray[newpos];
		}
	// Double Threshold
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			double lowThres = 0.3;
			double highThres = 0.15;
			highThres = maxPix * highThres;
			lowThres = highThres * lowThres;
			if (NonMaxSupArray[newpos] < lowThres)
				NonMaxSupArray[newpos] = 0;
			else if (NonMaxSupArray[newpos] >= highThres)
				NonMaxSupArray[newpos] = 1;
		}
	// Set Intermediate Value
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			if (NonMaxSupArray[newpos] > 1)
				NonMaxSupArray[newpos] = 2;
		}
	// Edge Tracking by Hysteresis
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			BinaryImageArray[newpos] = EdgeTrackingHysteresis(x, y, newpos, NonMaxSupArray, maskSize);
		}
	// 0 --- 255 //
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			if (BinaryImageArray[newpos] == 0)
				BinaryImageArray[newpos] = 0;
			else
				BinaryImageArray[newpos] = 255;
		}
	return BinaryImageArray;
}
// Get First Work Images
void GetErosionImage(PictureBox^ convertedPic)
{
	otsubuf = BUildKMeansThresholdImage();
	erosionArray = BuildErosionImage(otsubuf);
	SetImage(erosionArray, convertedPic);
}
void GetDilationImage(PictureBox^ convertedPic)
{
	otsubuf = BUildKMeansThresholdImage();
	dilationArray = BuildDilationImage(otsubuf);
	SetImage(dilationArray, convertedPic);
}
void GetDilationErosionImage(PictureBox^ convertedPic)
{
	otsubuf = BUildKMeansThresholdImage();
	dilationerosionArray = BuildDilationErosionImage(otsubuf);
	SetImage(dilationerosionArray, convertedPic);
}
void GetErosionDilationImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listEdge)
{
	otsubuf = BUildKMeansThresholdImage();
	erosiondilationArray = BuildErosionDilationImage(otsubuf);
	SetImage(erosiondilationArray, convertedPic);
}
void GetTaggedImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listEdge)
{
	otsubuf = BUildKMeansThresholdImage();
	erosiondilationArray = BuildErosionDilationImage(otsubuf);
	taggedArray = BuildTaggedArray(erosiondilationArray);
	DrawHistogram(taggedArray, chart, listEdge);
	SetImage(taggedArray, convertedPic);
	//MessageBox::Show("Eşik Değer: " + tempValue.ToString(), " ", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
// Get Second Work Images
void GetGrayOtsuImage(PictureBox^ convertedPic)
{
	otsubuf = BuildOtsuThresholdImage();
	SetImage(otsubuf, convertedPic);
	MessageBox::Show("Eşik Değer: " + otsuValue.ToString(), " ", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
void GetGrayImage(PictureBox^ picGray, Chart^ chart, ListBox^ listGray)
{
	raw_intensity = BuildGrayImage();
	DrawHistogram(raw_intensity, chart, listGray);
	SetImage(raw_intensity, picGray);
}
void GetSmoothImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listGauss)
{
	int maskSize = 2;
	BYTE* exSmoothImage = new BYTE[width * height];
	GaussianPixelArray = BuildSmoothImage(2);
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			exSmoothImage[newpos] = GaussianPixelArray[newpos];
		}
	DrawHistogram(exSmoothImage, chart, listGauss, maskSize);
	SetImage(exSmoothImage, convertedPic);
}
void GetGradientImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listEdge)
{
	int maskSize = 3;
	BYTE* exGradientImage = new BYTE[width * height];
	GradientMagnitude = BuildGradientImage(3);
	int top = 0;
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			if (top < GradientMagnitude[newpos])
				top = GradientMagnitude[newpos];
		}
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			exGradientImage[newpos] = GradientMagnitude[newpos] * 255 / top;
		}
	DrawHistogram(exGradientImage, chart, listEdge, maskSize);
	SetImage(exGradientImage, convertedPic);
}
void GetNonMaxSupImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listEdge)
{
	int maskSize = 3;
	BYTE* exNonMaxImage = new BYTE[width * height];
	NonMaxSupArray = BuildNonMaxSupImage(3);
	int top = 0;
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			if (top < NonMaxSupArray[newpos])
				top = NonMaxSupArray[newpos];
		}
	for (int x = maskSize; x < height - maskSize; x++)
		for (int y = maskSize; y < width - maskSize; y++)
		{
			newpos = x * width + y;
			exNonMaxImage[newpos] = NonMaxSupArray[newpos] * 255 / top;
		}
	DrawHistogram(exNonMaxImage, chart, listEdge, maskSize);
	SetImage(exNonMaxImage, convertedPic);
}
void GetBinaryEdgeImage(PictureBox^ convertedPic, Chart^ chart, ListBox^ listEdge)
{
	BinaryImageArray = BuildBinaryEdgeImage(3);
	DrawHistogram(BinaryImageArray, chart, listEdge, 3);
	SetImage(BinaryImageArray, convertedPic);
}