/****************************************************************************
Description: It is a console application that has an AnimationManager that holds a vector template of Animation objects each of which
holds aforward_list template of Frames. Allows user to Add an Animation, Delete an Animation, Edit an Animation (which allows the user to add,
delete, and edit frames within the animation) and View the Animation list.
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define	_CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <iostream>
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
Function Name:	operator<<
Purpose:	prints out frames
In Parameters:	ostream& stream, Frame& frame
Out Parameters:	ostream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

ostream& operator<<(ostream& stream, Frame& frame) {
	try {
		AudioFrame& audioFrame = dynamic_cast<AudioFrame&>(frame);
		stream << audioFrame;
	} catch (const bad_cast & e){}
	try {
		VideoFrame& videoFrame = dynamic_cast<VideoFrame&>(frame);
	} catch(const bad_cast & e){}
	stream << "frameName = " << frame.frameName;
	return stream;
}