//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PegaData.h"
#include "Principal.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelData *SelData;
//---------------------------------------------------------------------------
__fastcall TSelData::TSelData(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSelData::Button1Click(TObject *Sender)
{
        DataG = MonthCalendar1->Date;
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------
