//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cabecalho.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCabecalho *FormCabecalho;

//---------------------------------------------------------------------------
__fastcall TFormCabecalho::TFormCabecalho(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCabecalho::FormShow(TObject *Sender)
{
        lines_temp->Lines = RichEdit1->Lines;
}
//---------------------------------------------------------------------------
void __fastcall TFormCabecalho::Button1Click(TObject *Sender)
{
        // Caso cancelar
        RichEdit1->Lines = lines_temp->Lines;
}
//---------------------------------------------------------------------------
