#include "Command.hpp"
#include "Button.hpp"
#include "Editor.hpp"
#include "NotesApplication.hpp"

using namespace std;

TEST (CommandTest, test) {
	try{
		NoteApp* app = new NoteApp();
		app->write ("Hello world");
		app->copy->onClick();
		app->paste->onClick();
		app->cut->onClick();
		app->undo->onClick();
	} catch(std::exception& ex) {
		cout << "Exception : " << ex.what() << endl;
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}