#ifndef BASIC_MATH_H_
#define BASIC_MATH_H_

#include "Audio.h"
#include <stdint.h>

using namespace std;

	class Basic {
	public:
		static double rms(const raw_t* source, uint32_t start, uint32_t finish);

		static double entropy(const double* source, uint32_t start, uint32_t finish,
			uint8_t binsCount, double minRaw, double maxRaw);
	};

#endif