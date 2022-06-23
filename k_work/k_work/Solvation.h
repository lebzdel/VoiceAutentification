#pragma once
#include "User.h"
#include "Audio.h"
#include <List>

using namespace std;

class Solvation {
public:

	int RegisterNewUser(string name, const std::string& file);

	int CheckUser(string name, const std::string& file);

	void setCurrentFile(const string& file) { current_file = file; };
	string getCurrentFile() { return current_file; };

private:
	list<User> user_list;
	string current_file;
};
