#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>

// Shape class
class CShape
{
public:
    int color;
    virtual void draw(int x, int y, HDC device_context) = 0;
};

// Line class
class CLine : public CShape
{
private:
    int length;
public:
    void draw(int x, int y, HDC device_context);

    CLine(int length, int color);
};
// Circle class
class CCircle : public CShape
{
private:
    int radium;
public:
    void draw(int x, int y, HDC device_context);

    CCircle(int radium, int color);
};

// Rectangle class
class CRectangle : public CShape
{
protected:
    int width, height;
public:
    void draw(int x, int y, HDC device_context);

    CRectangle() {};
    CRectangle(int width, int height, int color);
};

// Square class
class CSquare : public CRectangle
{
public:
    CSquare(int a, int color);
};

// Picture class
class CPicture
{
public:
    CShape* Arr_ptr[4]; 

};