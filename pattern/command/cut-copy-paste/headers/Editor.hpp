#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Editor {
	string text_field;
	string get_selection () { cout << "text selected \n";return text_field; }
	void delete_selection () { cout << "selected text deleted \n"; text_field = ""; }
	void replace_selection (string text) { cout << "text replaced \n"; text_field = text; }
};