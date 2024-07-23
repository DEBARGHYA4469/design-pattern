#include "Memento.hpp" 

shared_ptr<Snapshot> Editor::createSnapshot() {
	return make_shared<Snapshot>(this,txt,currx,curry,selectionWidth);
}