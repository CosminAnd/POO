#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height) 
{

	this->w = width;
	this->h = height;

	for (int i = 0; i <= height; i++)
		this->c[i][0] = this->c[i][width + 1] = '.';

	for (int i = 0; i <= width; i++)
		this->c[0][i] = this->c[height + 1][i] = '.';

	this->c[0][0] = '.';
	this->c[height + 1][0] = '.';
	this->c[0][width + 1] = '.';
	this->c[width + 1][height + 1] = '.';

	for (int i = 1; i <= width; i++)
		for (int j = 1; j <= height; j++)
			this->c[j][i] = ' ';

}

bool Canvas::IsInside(int x, int y) 
{

	if ((x >= 1 && x <= this->w) && (y >= 1 && y <= this->h))
		return 1;
	return 0;

}

void Canvas::SetPoint(int x, int y, char ch) 
{

	if (this->IsInside(x, y))
		this->c[x][y] = ch;

}

void Canvas::DrawCircle(int x, int y, int ray, char ch) 
{
	
	int i, j;
	i = x;
	x = y;
	y = i;
	for (i = x - ray; i <= x + ray; i++)
		for (j = y - ray; j <= y + ray; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) >= (ray * ray) && ((i - x) * (i - x) + (j - y) * (j - y)) <= ((ray+1) * (ray+1)))
				this->SetPoint(i, j, ch);
}

void Canvas::FillCircle(int x, int y, int ray, char ch) 
{
	int i, j;
	i = x;
	x = y;
	y = i;
	for (i = x - ray; i <= x + ray; i++)
		for (j = y - ray; j <= y + ray; j++)
			if (((i - x) * (i - x) + (j - y) * (j - y)) <= (ray * ray))
				this->SetPoint(i, j, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) 
{	
	if (left >= right || top >= bottom)
		return;


	for (int i = left; i <= right; i++) 
	{
		this->SetPoint(top, i, ch);
		this->SetPoint(bottom, i, ch);
	}

	for (int i = top; i <= bottom; i++) 
	{
		this->SetPoint(i, left, ch);
		this->SetPoint(i, right, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {

	if (left >= right || top >= bottom)
		return;

	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			this->SetPoint(i, j, ch);

}


void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) 
{	
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;

	while (x < x2) 
	{
		if (p >= 0) 
		{
			this->SetPoint(x, y, ch);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
			else 
			{
				this->SetPoint(x, y, ch);
				p = p + 2 * dy;
			}
		x++;
	}

}

void Canvas::Print() 
{

	for (int i = 0; i <= this->h + 1; i++) 
	{
		for (int j = 0; j <= this->w + 1; j++) 
		{
			cout << this->c[i][j];
			if (j < this->w) 
			{
			
					cout << ' ';
			}
		}
		cout << "\n";
	}

}

void Canvas::Clear() 
{

	for (int i = 1; i <= this->h; i++)
		for (int j = 1; j <= this->w; j++)
			this->c[i][j]=' ';

}
