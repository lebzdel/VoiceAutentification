#include "Frame.h"
#include <cmath>
#include <stdlib.h>
#include "MFCC.h"
#include "Basic.h"


Frame::Frame(uint32_t id) :
	id(id), rms(0), entropy(0), mfcc(0) {
}

Frame::~Frame() {
	delete[] this->mfcc;
}

void Frame::init(const raw_t* source, const double* sourceNormalized,
	uint32_t start, uint32_t finish) {

	this->rms = Basic::rms(source, start, finish);
	this->entropy = Basic::entropy(sourceNormalized, start, finish, ENTROPY_BINS, -1, 1);
}

double* Frame::initMFCC(const double* source, uint32_t start, uint32_t finish,
	uint32_t freq) {

	this->mfcc = MFCC::transform(source, start, finish, MFCC_SIZE, freq,
		MFCC_FREQ_MIN, MFCC_FREQ_MAX);
	return this->mfcc;
}
