/****************************************************************************
Matt Idone-York
040912497
Assignment 3: Animation in C++ with Inheritance
20W_CST8219 C++ Programming
Lab section 302
Professor's name
Due: April 6th 2020
Submitted: April 6th 2020
Source and Header files: ass0.c

Version number: 1.0
Description: It is a console application that has an AnimationManager that holds a vector template of Animation objects each of which
holds aforward_list template of Frames. Allows user to Add an Animation, Delete an Animation, Edit an Animation (which allows the user to add,
delete, and edit frames within the animation) and View the Animation list.
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

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

void AudioFrame::CalculateFrameResource() {
	cout << "MP3 Lossy Compression" << endl;
	cout << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "bitrate (kbits/s): " << "\t|" << this->BITRATE[0] << "\t|" << this->BITRATE[1] << "\t|" << this->BITRATE[2] << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB) : \t";
	for (int i = 0; i < 3; i++) {
		cout << "\t|" << fixed << setprecision(2) << this->size / this->COMPRESSION_RATIO[i];
	}
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
}

/****************************************************************************
Function Name:	operator<<
Purpose:	Outputs the frames in the Animation
In Parameters:	ostream& stream, AudioFrame& af
Out Parameters:	ostream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

ostream& operator<<(ostream& stream, AudioFrame& af) {
	stream << "Audio Frame: ";
	return stream;
}