#include "Command.hpp"
#include "NotesApplication.hpp"

bool CutCommand::execute () {
	cout << "cut command initiated ... \n";
	this->save_backup();
	app->set_clipboard (editor->text_field);
	editor->delete_selection();
	return true;
} 

bool CopyCommand::execute () {
	cout << "cut command initiated ... \n";
	app->set_clipboard (editor->text_field);
	return true;
} 

bool PasteCommand::execute () {
	cout << "paste command initiated ... \n";
	this->save_backup();
	editor->replace_selection (app->clipboard);
	return true;	
} 

bool UndoCommand::execute () {
	cout << "undo command initiated ... \n";
	this->app->_undo();
	return true;	
} 