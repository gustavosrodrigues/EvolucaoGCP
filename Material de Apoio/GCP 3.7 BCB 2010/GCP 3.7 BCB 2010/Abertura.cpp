//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal.h"
#include "Abertura.h"
#include "Atas.h"
#include "PegaData.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbertura *FormAbertura;
//---------------------------------------------------------------------------
__fastcall TFormAbertura::TFormAbertura(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAbertura::Button3Click(TObject *Sender)
{
        FormAtas->Button23Click(FormAbertura);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button1Click(TObject *Sender)
{
	   FormAtas->Button24Click(FormAbertura);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::FormCreate(TObject *Sender)
{
        StringGrid1->Cells[0][0] = "Atividade";
        StringGrid1->Cells[1][0] = "Data";
        StringGrid1->Cells[2][0] = "Hor�rio";
        StringGrid1->Cells[3][0] = "Local";
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button5Click(TObject *Sender)
{
        FormAtas->Button28Click(FormAbertura);        
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button4Click(TObject *Sender)
{
        FormAtas->Button25Click(FormAbertura);
}
//---------------------------------------------------------------------------




void __fastcall TFormAbertura::Gerarrecibodadocumentaodocandidatoselecionado1Click(
      TObject *Sender)
{
        FormAtas->Button26Click(FormAbertura);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button111Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button23Click(FormAbertura);

}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button6Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button10Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button28Click(FormAbertura);
}
//---------------------------------------------------------------------------


void __fastcall TFormAbertura::Button13Click(TObject *Sender)
{
		SelData->ShowModal();
		FormAtas->Button24Click(FormAbertura);
}
//---------------------------------------------------------------------------

void __fastcall TFormAbertura::Button1Click2(TObject *Sender)
{
	   projeto.peso_didatica_final = StrToFloat(Edit11->Text)/10;
	   projeto.peso_escrita_final = StrToFloat(Edit10->Text)/10;
	   projeto.peso_memorial_final = StrToFloat(Edit14->Text)/10;
	   projeto.peso_titulos_final = StrToFloat(Edit13->Text)/10;
	   projeto.peso_entrevista_final = StrToFloat(Edit12->Text)/10;
	   Close();
}

