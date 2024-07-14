#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

#include "Button.hpp"
#include "Editor.hpp"
#include "Command.hpp"


using namespace std;

struct NoteApp {
	
	string clipboard;
	vector<Editor> editors;
	Editor* editor;
	CommandHistory* history;

	/* Buttons */
	Button* cut;
	Button* copy;
	Button* paste;
	Button* undo;

	NoteApp () {
		history = new CommandHistory ();
		editor = new Editor(); 
		
		/* Bind buttons to Commands */
		cut = new Button ("Cut Button");
		cut->bindOnClick ([this]()->void {
			execute (new CutCommand (this, editor));
		});
		
		copy = new Button ("Copy Button");
		copy->bindOnClick ([this]()->void {
			execute (new CopyCommand (this, editor));
		});

		paste = new Button ("Paste Button");
		paste->bindOnClick ([this]()->void {
			execute (new PasteCommand (this, editor));
		});

		undo = new Button ("Undo Button");
		undo->bindOnClick ([this]()->void {
			execute (new UndoCommand (this, editor));
		});
	}

	void set_clipboard (string str) {
		cout << str << " is saved in clipboard" << endl;
		this->clipboard = str;
	} 

	void write (string str) {
		editor = new Editor (str);
	}

	void execute (Command* c) {
		if (c->execute()) {
			history->push (c);
		}
	} 

	void _undo () {
		Command* c = history->pop(); 
		if (c) {
			c->undo();
		}
	}
}; 