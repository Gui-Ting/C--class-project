//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CreateMDIChild(String Name)
{
	TMDIChild *Child;

	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = Name;
	Child->Image1->Picture->LoadFromFile(Name);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
	//CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
	if (OpenPictureDialog1->Execute())
		CreateMDIChild(OpenPictureDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButton3Click(TObject *Sender)
{
Graphics::TBitmap *TheBitmap;
Byte *ptr;
TMDIChild *TheChild;
if (ActiveMDIChild)
{
TheChild=(TMDIChild*)ActiveMDIChild;
TheBitmap=TheChild->Image1->Picture->Bitmap;
for (int y=0;y<TheBitmap->Height;y++)
{
ptr = (Byte*)TheBitmap->ScanLine[y];
for(int x=0;x<TheBitmap->Width;x++)
ptr[x]=(Byte)(255-ptr[x]);
}
TheChild->Repaint();
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ToolButton5Click(TObject *Sender)
{
TMDIChild *TheChild;
if (ActiveMDIChild)
{
TheChild=(TMDIChild*)ActiveMDIChild;
if (SavePictureDialog1->Execute())
{
TheChild->Image1->Picture->SaveToFile(SavePictureDialog1->FileName+".bmp");
}
}
}
//---------------------------------------------------------------------------
