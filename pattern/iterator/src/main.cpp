#include "List.hpp" 

using namespace std;

TEST (ListIterator, test) {
	List<long>* list = new List<long>(); 
	list->insert (1);
	list->insert (2); 
	list->insert (4); 
	list->insert (8);
	list->insert (16); 

	List<long>::iterator it (list);
	for (it.First();it.hasNext();it.next()){
		it.printcurr();
	}
	cout << endl;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
