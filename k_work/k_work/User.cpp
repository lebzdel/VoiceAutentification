#include "User.h"

#include <stddef.h>
#include <cstdint>
#include <iostream>
#include <iterator>

using namespace std;

	User::User(string text) :
		text(text) {
		this->sample = *new MFCCSample();
	}

	User::~User() {
	}

	void User::addSample(double* mfcc, uint32_t size) {
		MFCCSample buf_sample = { size, mfcc };
		this->sample = buf_sample;
	}

	bool User::checkVoice(double* mfcc, uint32_t size) {
		double distance = DTW::calcDistance(this->sample.data, this->sample.size, mfcc, size);

		return distance < 5;
	}

	/*
	ostream& operator<<(ostream& fs, const User& obj) {

		fs.write((char*)&obj.id, sizeof(uint32_t));

		size_t textSize = obj.text.size();
		fs.write((char*)&textSize, sizeof(size_t));
		fs.write(&obj.text[0], sizeof(char) * textSize);

		size_t samplesCnt = obj.sample->size();
		fs.write((char*)&samplesCnt, sizeof(size_t));

		for (vector<MFCCSample>::const_iterator sample = obj.sample;
			sample != obj.samples->end(); ++sample) {
			MFCCSample theSample = *sample;

			fs.write((char*)(&theSample.size), sizeof(uint32_t));
			fs.write(reinterpret_cast<char*>(theSample.data),
				streamsize(theSample.size * sizeof(double)));
		}

		return fs;
	}

	istream& operator>>(istream& fs, User& obj) {

		fs.read((char*)(&obj.id), sizeof(uint32_t));

		size_t textSize;
		fs.read((char*)&textSize, sizeof(size_t));

		
		char* text = new char[textSize + 1];
		fs.read(text, sizeof(char) * textSize);
		text[textSize] = '\0';
		string textString(text);
		obj.text = textString;

		size_t samplesCnt;
		fs.read((char*)&samplesCnt, sizeof(uint32_t));

		MFCCSample sample;
		for (size_t i = 0; i < samplesCnt; i++) {

			fs.read((char*)(&sample.size), sizeof(uint32_t));

			sample.data = new double[sample.size];
			fs.read(reinterpret_cast<char*>(sample.data),
				streamsize(sample.size * sizeof(double)));

			obj.addSample(sample.data, sample.size);
		}

		return fs;
	}
	*/
