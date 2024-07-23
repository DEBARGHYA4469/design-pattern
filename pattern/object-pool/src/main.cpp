#include "ObjectPool.hpp" 

TEST (ObjectPooltest, test) {
	ConnectionPool pool(2);
	
	auto conn1 = pool.acquire ();
	if (conn1) conn1->connect ();

	auto conn2 = pool.acquire ();
	if (conn2) conn2->connect (); 

	auto conn3 = pool.acquire ();
	if (conn3) conn3->connect ();
	else cout << "connection refused" << endl;

	pool.release(conn2);

	conn3 = pool.acquire ();
	if (conn3) conn3->connect ();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}