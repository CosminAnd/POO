#pragma once
#ifndef CANVAS_H
#define CANVAS_H

class Canvas {

	int w, h;
	char c[502][502];

public:

	Canvas(int width, int height);

	bool IsInside(int x, int y);

	void DrawCircle(int x, int y, int ray, char ch);

	void FillCircle(int x, int y, int ray, char ch);

	void DrawRect(int left, int top, int right, int bottom, char ch);

	void FillRect(int left, int top, int right, int bottom, char ch);

	void SetPoint(int y, int x, char ch);

	void DrawLine(int x1, int y1, int x2, int y2, char ch);

	void Print(); // shows what was printed

	void Clear(); // clears the canvas

};

#endif