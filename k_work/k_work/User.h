#pragma once

#include "DTW.h"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * MFCC sample
 */
struct MFCCSample {
	uint32_t   size;
	double* data;
};

class User {
public:

	User(string text);
	~User();

	const string getText() const { return this->text; }

	void addSample(double* mfcc, uint32_t size);
	const MFCCSample getSamples() const { return this->sample; }

	bool checkVoice(double* mfcc, uint32_t size);


	// friend std::ostream& operator<<(std::ostream& fs, const User& obj);
	// friend std::istream& operator>>(std::istream& fs, User& obj);

private:
	string text;
	MFCCSample sample;
};

