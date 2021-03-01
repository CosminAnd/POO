#include"Students.h"
#include<cstring>

Student::Student() {
	name[0] = 0;
	mat = ist = eng = 0;

}

void Copy(char* a, int dim, const char* b) {
	if (a == nullptr)
		return;
	if (dim < 1)
		return;
	if (b == nullptr) {
		*a = 0;
		return;
	}

	int i;
	for (i = 0; b[i] != '\0' && (i < dim - 1); i++)
		a[i] = b[i];
	a[i] = '\0';

}

bool Student::Check(float x) {

	if (x > 0 && x < 11)
		return true;
	return false;

}

void Student::SetName(const char* s) {
	Copy(this->name, Max, s);

}
void Student::CopyName(char* s, int dim) {
	Copy(s, dim, this->name);

}

const char* Student::GetName() const {
	return this->name;

}

void Student::SetMat(float x) {
	if (Check(x))
		this->mat = x;
}
float Student::GetMat() const {
	return this->mat;
}

void Student::SetEng(float x) {
	if (Check(x))
		this->eng = x;
}
float Student::GetEng() const {
	return this->eng;
}

void Student::SetIst(float x) {
	if (Check(x))
		this->ist = x;
}
float Student::GetIst() const {
	return this->ist;
}

float Student::GetAvg() const {
	return (this->mat + this->eng + this->ist) / 3;
}