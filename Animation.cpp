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


Animation::~Animation() {
	for (Frame* frame : this->frames) {
		delete frame;
	}
}

/****************************************************************************
Function Name:	EditFrame
Purpose:	Edits a specific Frame
In Parameters:	N/A
Out Parameters:	N/A
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

void Animation::EditFrame() {
	string name;
	string type;
	double size;
	forward_list<Frame*>::iterator i;
	int count = 0;
	int position;
	Frame* oldFrame;
	cout << "Edit a Frame in the Animation\n";
	if (frames.empty()) {
		cout << "There is no frame inside the Animation. Please add a frame first!\n";
		return;
	}
	for (i = frames.begin(); i != frames.end(); i++) {
		count++;
	}
	cout << "There are " << count << " Frame(s) in the list. Please specify the index (<= " << count - 1 << ") to edit at: ";
	cin >> position;
	if (cin.fail()) {
		cout << "Please enter a valid integer\n";
		cin.clear();
		cin.ignore(500, '\n');
		return;
	}
	if (position < 0) {
		cout << "Please enter a positive integer\n";
		return;
	}
	if (position > (count - 1)) {
		cout << "The index is not available in the linked list!\n";
		return;
	}
	count = 0;
	for (i = frames.begin(); i != frames.end(); i++) {
		if (count == position) {
			oldFrame = *i;
			cout << "The name and size of this Frame are " << *(Frame*)oldFrame << endl;
			cout << "Please enter the Frame frameName: ";
			cin >> name;
			cout << "Please enter the Frame size(MB): ";
			cin >> size;
			if (cin.fail()) {
				cout << "Please enter a valid decimal\n";
				cin.clear();
				cin.ignore(500, '\n');
				return;
			}
			cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
			cin >> type;
			if (type != "A" && type != "V") {
				cout << "Please enter the right type, either A or V!" << endl;
				return;
			}
			delete oldFrame;
			if (type == "A") {
				AudioFrame* tempFrame = new AudioFrame(name, size);
				*i = tempFrame;
			}
			else {
				VideoFrame* tempFrame = new VideoFrame(name, size);
				*i = tempFrame;
			}
			cout << "Frame " << count << " edit completed\n";
			break;
		}
		count++;
	}
}

/****************************************************************************
Function Name:	DeleteFrame
Purpose:	Deletes the first Frame in the Animation
In Parameters:	N/A
Out Parameters:	N/A
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

void Animation::DeleteFrame() {
	if (this->frames.empty()) {
		cout << "There are no Frames in the Animation" << endl;
		return;
	}
	delete* this->frames.begin();
	this->frames.pop_front();
	cout << "First frame deleted" << endl;
}

/****************************************************************************
Function Name:	operator>>
Purpose:	Adds a frame to the Animation
In Parameters:	istream& stream, Animation& a
Out Parameters:	istream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

istream& operator>>(istream& stream, Animation& a) {
	string frameName;
	double size;
	char frameType;
	Frame* frame(NULL);
	cout << "Insert a Frame in the Animation" << endl << "Please the Frame frameName: " << endl;
	cin >> frameName;
	cout << "Please enter the Frame size(MB): ";
	cin >> size;
	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): " << endl;
	cin >> frameType;
	switch (frameType) {
	case 'A':
	case 'a':
		frame = new AudioFrame(frameName, size);
		a.frames.push_front(frame);
		break;
	case 'V':
	case 'v':
		frame = new VideoFrame(frameName, size);
		a.frames.push_front(frame);
		break;
	default:
		cout << "Invalid Option" << endl;
		return stream;
	}
	cout << "Frame " << frameName << " added at the front of frames" << endl;
	return stream;
}

/****************************************************************************
Function Name:	operator<<
Purpose:	Outputs the frames in the Animation
In Parameters:	ostream& stream, Animation& a
Out Parameters:	ostream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

ostream& operator<<(ostream& stream, Animation& a) {
	int counter = 0;
	cout << "Animation name is " << a.animationName << endl;
	cout << "\tReport the Animation" << endl;
	if(a.frames.empty()) {
		cout << "No frames in the Animation" << endl;
		return stream;
	}
	for (Frame* frame : a.frames) {
		stream << "Frame #" << counter << endl;
		stream << (*frame) << endl;
		(*frame).CalculateFrameResource();
		counter++;
	}
	return stream;
}