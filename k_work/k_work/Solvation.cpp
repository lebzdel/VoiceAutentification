#include "Solvation.h"
#include "MFCC.h"
#include "Word.h"
#include "Processor.h"
#include <iterator>
#include <List>

double difference(double* arr1, uint32_t size1, double* arr2, uint32_t size2) {
	double max = abs(arr1[0] - arr2[0]);
	for (int i = 1; i < min(size1, size2); i++) {
		if (max < abs(arr1[0] - arr2[0])) {
			max = abs(arr1[0] - arr2[0]);
		}
	}

	return max;
}

int Solvation::RegisterNewUser(string name, const std::string& file) {
	for (list<User>::iterator user = user_list.begin(); user != user_list.end(); user++) {
		if (user->getText() == name) {
			return 0;
		}
	}

	WavData* wavFile;
	Word* word;

	try {
		// WAV_HEADER wavHeader;
		wavFile = WavData::readFromFile(file);

		Processor* processor = new Processor(wavFile);
		processor->init();
		word = processor->getAsWholeWord();
		processor->initMfcc(*word);
	}
	catch (const exception& e) {
		string exc = e.what();
		if (exc == "file not found") {
			return 2;
		}
		else if (exc == "file is not fit") {
			return 3;
		}
	}


	User buf(name);
	buf.addSample(word->getMfcc(), word->getMfccSize());
	user_list.push_back(buf);

	return 1;
}

int Solvation::CheckUser(string name, const std::string& file) {
	bool is_exist = false;
	bool is_voice = false;
	list<User>::iterator user;
	for (user = user_list.begin(); user != user_list.end(); user++) {
		if (user->getText() == name) {
			is_exist = true;
			break;
		}
	}
	if (!is_exist) {
		return 0;
	}
	else {
		try {
			WavData* wavFile = WavData::readFromFile(file);

			Processor* processor = new Processor(wavFile);
			processor->init();
			Word* word = processor->getAsWholeWord();
			processor->initMfcc(*word);

			//is_voice = user->checkVoice(word->getMfcc(), word->getMfccSize());
			is_voice = abs(difference(user->getSamples().data, user->getSamples().size, word->getMfcc(), word->getMfccSize())) < 0.5;
		}
		catch (const exception& e) {
			string exc = e.what();
			if (exc == "file not found") {
				return 3;
			}
			else if (exc == "file is not fit") {
				return 4;
			}
		}
	}

	if (is_voice) {
		return 1;
	}
	else {
		return 2;
	}
}
