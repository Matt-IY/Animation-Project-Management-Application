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
Function Name:	EditAnimation
Purpose:	Edits a specific Animation by allowing user to add a new frame,
			delete, or edit a pre-existing one.
In Parameters:	N/A
Out Parameters:	N/A
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/


void AnimationManager::EditAnimation() {
	vector<Animation>::iterator i;
	int index;
	int counter = 0;
	char choice;
	bool loop = true;
	if (animations.empty()) {
		cout << "There are no Animations" << endl;
		return;
	}
	for (i = animations.begin(); i != animations.end(); i++) {
		counter++;
	}
	cout << "Which animation do you wish to edit? Please give the index (from 0 to " << (counter - 1) << ")" << endl;
	cin >> index;
	if (cin.fail()) {
		cout << "Invalid integer\n";
		cin.clear();
		cin.ignore(500, '\n');
		return;
	}
	if (index < 0) {
		cout << "Not within range\n";
		return;
	}
	if (index > (counter - 1)) {
		cout << "Not within range\n";
		return;
	}
	counter = 0;
	cout << "Editing Animation #" << index << endl;
	while (loop) {
		cout << "MENU" << endl << "1. Insert a Frame at front" << endl << "2. Delete first frame" << endl << "3. Edit a frame" << endl << "4. Quit" << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			cin >> this->animations.at(index);
			break;
		case '2':
			this->animations.at(index).DeleteFrame();
			break;
		case '3':
			this->animations.at(index).EditFrame();
			break;
		case '4':
			loop = false;
			cout << "Animation #" << index << " edit complete" << endl;
			break;
		default:
			cout << "Invalid Option" << endl;
		}
	}
}

/****************************************************************************
Function Name:	DeleteAnimation
Purpose:	Deletes a specific Animation
In Parameters:	N/A
Out Parameters:	N/A
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

void AnimationManager::DeleteAnimation() {
	if (this->animations.size() == 0) {
		cout << "No Animations to delete" << endl;
		return;
	}
	cout << "Animation at end has been deleted" << endl;
	this->animations.erase(this->animations.end() - 1);
}

/****************************************************************************
Function Name:	operator>>
Purpose:	overwrites and adds a new Animation
In Parameters:	istream& stream, AnimationManager& am
Out Parameters:	istream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

istream& operator>>(istream& stream, AnimationManager& am) {
	string animationName;
	cout << "Add an Animation to the Animation Manager" << endl << "Please enter the Animation Name: " << endl;
	cin >> animationName;
	Animation animation(animationName);
	if (am.animations.empty()) {
		am.animations.reserve(32);
	}
	am.animations.push_back(animation);
	cout << "Animation " << animationName << " added at the back of animations" << endl;
	return stream;
}

/****************************************************************************
Function Name:	operator<<
Purpose:	outputs the animations
In Parameters:	ostream& stream, AnimationManager& am
Out Parameters:	ostream& stream
Version:	1.0
Author:	Matt Idone-York
****************************************************************************/

ostream& operator<<(ostream& stream, AnimationManager& M) {
	stream << "AnimationManager: " << M.managerName << endl;
	int count = 0;
	vector<Animation>::iterator i;
	if (M.animations.empty()) {
		stream << "There is no animation inside the list\n";
		return stream;
	}
	for (i = M.animations.begin(); i != M.animations.end(); i++) {
		stream << "Animation: " << count << endl;
		stream << "\t" << *i;
		count++;
	}
	return stream;
}