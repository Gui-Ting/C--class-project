//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("..\20141016\main.cpp", MainForm);
USEFORM("..\20141016\childwin.cpp", MDIChild);
USEFORM("..\20141016\about.cpp", AboutBox);
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();

	return 0;
}
//---------------------------------------------------------------------
