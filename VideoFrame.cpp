/****************************************************************************
Description: It is a console application that has an AnimationManager that holds a vector template of Animation objects each of which
holds aforward_list template of Frames. Allows user to Add an Animation, Delete an Animation, Edit an Animation (which allows the user to add,
delete, and edit frames within the animation) and View the Animation list.
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define	_CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/****************************************************************************
Function Name:	CalculateFrameResource
Purpose:	Calculates the size of the frame
In Parameters:	N/A
Out Parameters:	N/A
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

void VideoFrame::CalculateFrameResource() {
	cout << "Lempel-Ziv-Welch Lossless Compression" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "colours: " << "\t\t|" << this->BITS / 2 << "\t|" << this->BITS / 1 << "\t|" << this->BITS * 2 << "\t|" << this->BITS * 4 << "\t|" << this->BITS * 8 << "\t|" << this->BITS * 16 << "\t|" << this->BITS * 64 << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB) : \t";
	for (int i = 0; i < 8; i++) {
		cout << "\t|" << fixed << setprecision(2) << this->size / (this->COMPRESSION_RATIO * this->BITDEPTH_FACTOR[i]);
	}
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
}

/****************************************************************************
Function Name:	operator<<
Purpose:	Outputs the frames in the Animation
In Parameters:	ostream& stream, VideoFrame& vf
Out Parameters:	ostream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

ostream& operator<<(ostream& stream, VideoFrame& vf) {
	stream << "Video Frame: ";
	return stream;
}