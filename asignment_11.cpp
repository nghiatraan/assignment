#include "asignment_11.h"

using namespace std;

//**********************************************************
// Name:		CLine
// Description:	Constructor of CLine class
// Arguments:	input_length: length of the line
//              input_color: color of the line
// Return:		Object CLine.
//**********************************************************
CLine::CLine(int input_length, int input_color)
{

    length = input_length;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a line
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CLine::draw(int x, int y, HDC device_context)
{

    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    MoveToEx(device_context, x, y, (LPPOINT)NULL);
    LineTo(device_context, x + length, y);
}

//**********************************************************
// Name:		CCircle
// Description:	Constructor of CCircle class
// Arguments:	input_radium: Radium of the circle
//              input_color: color of the circle
// Return:		Object CCircle.
//**********************************************************
CCircle::CCircle(int input_radium, int input_color)
{
    radium = input_radium;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a circle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CCircle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}

//**********************************************************
// Name:		CRectangle
// Description:	Constructor of CRectangle class
// Arguments:	input_width: width of the rectangle
//              input_height: height of the rectangle
//              input_color: color of the rectangle
// Return:		Object CRectangle.
//**********************************************************
CRectangle::CRectangle(int input_width, int input_height, int input_color)
{
    width = input_width;
    height = input_height;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a Rectangle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CRectangle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    Rectangle(device_context, x, y, x + width, y + height);
}

//**********************************************************
// Name:		CSquare
// Description:	Constructor of CSquare class
// Arguments:	length_side: length of the line
//              input_color: color of the line
// Return:		Object CSquare.
//**********************************************************
CSquare::CSquare(int length_side, int input_color)
{
    width = length_side;
    height = length_side;
    color = input_color;
}
int main()
{
    //Use the pointer array of the CPicture class to initialize the shapes
    CPicture Picture;
    Picture.Arr_ptr[0] = new CLine(20, 1000);
    Picture.Arr_ptr[1] = new CCircle(10, 1000);
    Picture.Arr_ptr[2] = new CRectangle(20, 10, 1000);
    Picture.Arr_ptr[3] = new CSquare(20, 1000);
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
    int k[4], i1, i2, i3, i4;
    int y = 30;
    for (i1 = 0; i1 < 4; ++i1)
        for (i2 = 0; i2 < 4; ++i2)
            if (i2 != i1)
                for (i3 = 0; i3 < 4; ++i3)
                    if (i3 != i2 && i3 != i1)
                        for (i4 = 0; i4 < 4; ++i4)
                            if (i4 != i3 && i4 != i2 && i4 != i1)
                            {
                                k[0] = i1;
                                k[1] = i2;
                                k[2] = i3;
                                k[3] = i4;
                                y = y + 30;
                                for (int i = 0; i < 4; i++) {
                                    Picture.Arr_ptr[k[i]]->draw(10 + i * 30, y, device_context);
                                }

                            }
    ReleaseDC(console_handle, device_context);
    return 0;
}