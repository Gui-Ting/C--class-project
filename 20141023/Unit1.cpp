//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "ChildWin.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
int Binary;
Binary = (int)TrackBar1->Position;
Edit1->Text=IntToStr(Binary);
Graphics::TBitmap *TheBitmap,*TempBitmap;
Byte *ptr=NULL,*tptr=NULL;
TheBitmap=MainForm->CurrentChild->Image1->Picture->Bitmap;
TempBitmap=MainForm->CurrentChild->Image2->Picture->Bitmap;
int x,y;
for (y=0;y<TheBitmap->Height;y++){
ptr=(Byte*)TheBitmap->ScanLine[y];
tptr=(Byte*)TempBitmap->ScanLine[y];
for (x=0;x<TheBitmap->Width;x++) {
if(tptr[x]<Binary)
ptr[x]=0;
else
ptr[x]=255;
}
}
MainForm->CurrentChild->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
int value;
value=StrToInt(Edit1->Text);
if (value<0||value>255)
{
MessageBox(NULL,"Dont't Over Range 0~255 !!","Stupid",MB_ICONERROR);
Edit1->Text="0";
}
TrackBar1->Position=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
MainForm->CurrentChild->Image1->Picture->Bitmap->Assign(MainForm->CurrentChild->
Image2->Picture->Bitmap);
}
//---------------------------------------------------------------------------
