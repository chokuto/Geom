#pragma once
#include <iterator>
#include <limits>
#include <algorithm>
#include "GeomVector.h"

template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type GeometricMean(
	Iterator begin,
	Iterator end)
{
	typedef typename std::iterator_traits<Iterator>::value_type VectorType;

	VectorType result = VectorType::Zero;
	size_t count = 0;
	for (auto i = begin; i != end; ++i) {
		result += *i;
		++count;
	}
	if (count > 0) {
		result /= count;
	}
	return result;
}

template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type GeometricMedian(
	Iterator begin,
	Iterator end,
	double deltaNorm = std::numeric_limits<typename std::iterator_traits<Iterator>::value_type::value_type>::epsilon(),
	int maxIteration = -1)
{
	typedef typename std::iterator_traits<Iterator>::value_type VectorType;

	VectorType median = GeometricMean(begin, end);

	bool converged = false;
	for (int k = 0; (maxIteration < 0 || k < maxIteration) && !converged; ++k) {
		double sumInvDist = 0.0;
		VectorType sumFracX = VectorType::Zero;
		VectorType sumFracXSubMedian = VectorType::Zero;
		double minDist = std::numeric_limits<double>::max();
		int multiplicity = 0;

		for (auto i = begin; i != end; ++i) {
			double dist = (median - *i).Length();
			if (dist < std::numeric_limits<VectorType::value_type>::epsilon()) {
				++multiplicity;
			} else {
				sumInvDist += 1 / dist;
				sumFracX += (*i) / dist;
				sumFracXSubMedian += (1.0 / dist) * (*i - median);
				if (dist < minDist) {
					minDist = dist;
				}
			}
		}
		VectorType tmpMedian;
		if (multiplicity == 0) {
			tmpMedian = sumFracX / sumInvDist;
		} else {
			double normR = sumFracXSubMedian.Length();
			if (normR < std::numeric_limits<VectorType::value_type>::epsilon()) {
				tmpMedian = median;
			} else {
				double t = std::max(
					0.0,
					std::min(
						minDist / 2,
						(normR - multiplicity) / (4 * sumInvDist)));
				tmpMedian = median + sumFracXSubMedian * (t / normR);
			}
		}
		converged = ((tmpMedian - median).Length() < deltaNorm);
		median = tmpMedian;
	}

	return median;
}
