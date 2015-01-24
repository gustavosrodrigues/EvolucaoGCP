//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Entrevista_candidatos.h"
#include "Entrevista.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEntrevista_candidatos *FormEntrevista_candidatos;
bool houve_modificacao_entrevista=false;
//---------------------------------------------------------------------------
__fastcall TFormEntrevista_candidatos::TFormEntrevista_candidatos(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEntrevista_candidatos::Button1Click(TObject *Sender)
{
	if (houve_modificacao_entrevista) {
		if (Application->MessageBoxA(L"Esta alteração irá apagar qualquer outra configuração de candidatos para a prova de Entrevista. Deseja continuar?",L"Atenção", MB_YESNO )==ID_YES) {

		FormEntrevista->ListBox2->Items = ListBox2->Items;
		FormEntrevista->Button1Click(FormEntrevista_candidatos);
		houve_modificacao_entrevista=false;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormEntrevista_candidatos::Button6Click(
	  TObject *Sender)
{
		if (ListBox1->ItemIndex>=0)
		{
				ListBox2->Items->Add(ListBox1->Items->Strings[ListBox1->ItemIndex]);
				ListBox1->Items->Delete(ListBox1->ItemIndex);
				houve_modificacao_entrevista=true;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormEntrevista_candidatos::Button17Click(
	  TObject *Sender)
{
		if (ListBox2->ItemIndex>=0)
		{
				ListBox1->Items->Add(ListBox2->Items->Strings[ListBox2->ItemIndex]);
				ListBox2->Items->Delete(ListBox2->ItemIndex);
				houve_modificacao_entrevista=true;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormEntrevista_candidatos::Button2Click(TObject *Sender)
{
	Close();

}
//---------------------------------------------------------------------------

