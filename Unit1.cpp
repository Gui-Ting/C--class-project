//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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


void __fastcall TForm1::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
Form1->Image1->AutoSize=true;
Form1->Image1->Picture->LoadFromFile(OpenDialog1->FileName);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StatusBar1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
StatusBar1->SimplePanel=true;
StatusBar1->SimpleText=IntToStr(101001466)+" X="+IntToStr(X)+" Y="+IntToStr(Y)+"�F�Q��";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Graphics::TBitmap *BM;
Byte *ptr;
BM=Image1->Picture->Bitmap;
for (int y=0;y<BM->Height;y++)
{
        ptr=(Byte*)BM->ScanLine[y];
        for(int x=0;x<BM->Width;x++)
        ptr[x]=(Byte)(255-ptr[x]);
}
Form1->Repaint();
}
//---------------------------------------------------------------------------

