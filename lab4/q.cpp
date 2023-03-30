#using < system.drawing.dll>
using namespace System;
using namespace System::Drawing;
// ...

virtual Void Form1::OnPaint(PaintEventArgs ^ pe) override
{
    Graphics ^ g = pe->Graphics;
    g->Clear(Color::AntiqueWhite);

    Rectangle rect = Form::ClientRectangle;
    Rectangle smallRect;
    smallRect.X = rect.X + rect.Width / 4;
    smallRect.Y = rect.Y + rect.Height / 4;
    smallRect.Width = rect.Width / 2;
    smallRect.Height = rect.Height / 2;

    Pen ^ redPen = gcnew Pen(Color::Red);
    redPen->Width = 4;
    g->DrawLine(redPen, 0, 0, rect.Width, rect.Height);

    Pen ^ bluePen = gcnew Pen(Color::Blue);
    bluePen->Width = 10;
    g->DrawArc(bluePen, smallRect, 90, 270);
}