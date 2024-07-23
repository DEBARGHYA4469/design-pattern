#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Snapshot;

class Editor {
private:
	string txt; 
	int currx, curry;
	int selectionWidth;
public:
	string get_txt() const { 
		return txt; 
	}
	void setTxt (const string& txt) {
		this->txt = txt;
	}
	void setCursor (int x, int y) {
		this->currx = x;
		this->curry = y;
	}
	void setselectionWidth (int width) {
		this->selectionWidth = width;
	}
	shared_ptr <Snapshot> createSnapshot();
};

class Snapshot {
private:
	Editor* editor;
	string txt;
	int currx, curry; 
	int selectionWidth; 
public:
	Snapshot(Editor* editor, const string& txt, int currx, int curry, int selectionWidth){
		this->editor = editor;
		this->txt = txt;
		this->currx = currx;
		this->curry = curry;
		this->selectionWidth = selectionWidth;
	}
	void restore () {
		editor->setTxt(txt);
		editor->setCursor(currx,curry);
		editor->setselectionWidth(selectionWidth);
	} 
};

class Command {
private:
	shared_ptr<Snapshot> backup; 
	Editor* editor;
public:
	Command (Editor* editor) : editor(editor) {} 
	void makebackup (){ backup = editor->createSnapshot(); }
	void undo () {
		if (backup!=nullptr){
			backup->restore();
		}
	}
};