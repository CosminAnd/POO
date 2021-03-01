#pragma once
#define Max 30


class Student
{
	char name[Max];
	float eng, ist, mat;
public:

	Student();
	static bool Check(float x);

	void SetName(const char* s);
	const char* GetName() const;
	void CopyName(char *s, int dim);

	float GetEng() const;
	void SetEng(float x);

	float GetMat() const;
	void SetMat(float x);

	float GetIst() const;
	void SetIst(float x);

	float GetAvg() const;
};