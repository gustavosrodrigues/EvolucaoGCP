//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Log.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLog *FormLog;
//---------------------------------------------------------------------------
__fastcall TFormLog::TFormLog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormLog::Button1Click(TObject *Sender)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormLog::Memo1Change(TObject *Sender)
{
	String file = ChangeFileExt(Application->ExeName, ".LOG");
	Memo1->Lines->SaveToFile(file.c_str());
}
//---------------------------------------------------------------------------
