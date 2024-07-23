#include "Memento.hpp" 

TEST (MementoTest, test) {
	Editor editor;
	Command command (&editor);
	editor.setTxt ("Hello");
	editor.setCursor (10,20);
	editor.setselectionWidth (3);

	command.makebackup();

	editor.setTxt ("New Text"); 
	command.undo ();	

	ASSERT_EQ (editor.get_txt(), "Hello");
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}