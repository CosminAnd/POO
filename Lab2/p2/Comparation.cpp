#include "Comparation.h"
#include "Students.h"
#include <cstring>

int CompareNumbers(float xa, float xb) {
	if (xa > xb)
		return 1;
	if (xa < xb)
		return -1;
	return 0;

}

int CmpName(const Student a, const Student b) {
	return strcmp(a.GetName(), b.GetName());
}

int CmpMat(const Student a, const Student b) {
	return CompareNumbers(a.GetMat(), b.GetMat());
}

int CmpEng(const Student a, const Student b) {
	return CompareNumbers(a.GetEng(), b.GetEng());
}

int CmpIst(const Student a, const Student b) {
	return CompareNumbers(a.GetIst(), b.GetIst());
}

int CmpAvg(const Student a, const Student b) {
	return CompareNumbers(a.GetAvg(), b.GetAvg());
}