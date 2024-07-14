#pragma once 
#include "Editor.hpp"
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct NoteApp;


/* Abstract Class for any Concrete Command Class*/
struct Command {
	
	NoteApp* app;
	Editor *editor;
	string backup;
	
	Command (NoteApp* app, Editor *editor) : app (app), editor (editor) {}

	void save_backup () {
		backup = editor->text_field;
	}
	
	void undo () {
		editor->text_field = backup;
	
	}
	virtual bool execute () = 0;
}; 

struct CutCommand : Command {
	using Command::Command;
	virtual bool execute ();
};

struct PasteCommand : Command {
	using Command::Command;
	virtual bool execute ();
};


struct CopyCommand : Command {
	using Command::Command;
	virtual bool execute ();
};

struct UndoCommand : Command {
	using Command::Command;
	virtual bool execute ();
};

struct CommandHistory {
	vector<Command*> history;
	CommandHistory () = default;
	void push (Command* c) {
		history.push_back (c);
	}
	Command* pop () {
		if (history.empty()) return nullptr;
		else {
			Command* tmp = history.back();
			history.pop_back();
			return tmp;
		}
	}
};
