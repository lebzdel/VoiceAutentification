#include "Word.h"
#include <cstdint>
#include <string>


	Word::Word(uint32_t id) {
		this->id = id;

		this->mfccSize = 0;
		this->mfcc = 0;
	}

	Word::~Word() {
		if (NULL != mfcc) {
			delete[] mfcc;
		}
	}