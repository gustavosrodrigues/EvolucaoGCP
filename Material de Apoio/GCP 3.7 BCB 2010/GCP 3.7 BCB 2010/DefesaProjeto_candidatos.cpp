//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DefesaProjeto_candidatos.h"
#include "DefesaProjeto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDefesaProjeto_candidatos *FormDefesaProjeto_candidatos;
bool houve_modificacao_memorial=false;
//---------------------------------------------------------------------------
__fastcall TFormDefesaProjeto_candidatos::TFormDefesaProjeto_candidatos(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDefesaProjeto_candidatos::Button1Click(TObject *Sender)
{
	if (houve_modificacao_memorial) {
		if (Application->MessageBoxA(L"Esta alteração irá apagar qualquer outra configuração de candidatos para a prova de Defesa de Memorial de Trajetória Acadêmica. Deseja continuar?",L"Atenção", MB_YESNO )==ID_YES) {
		FormDefesaProjeto->ListBox2->Items = ListBox2->Items;
		FormDefesaProjeto->Button1Click(FormDefesaProjeto_candidatos);
		houve_modificacao_memorial=false;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDefesaProjeto_candidatos::Button6Click(
      TObject *Sender)
{
		if (ListBox1->ItemIndex>=0)
        {
                ListBox2->Items->Add(ListBox1->Items->Strings[ListBox1->ItemIndex]);
				ListBox1->Items->Delete(ListBox1->ItemIndex);
				houve_modificacao_memorial=true;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormDefesaProjeto_candidatos::Button17Click(
      TObject *Sender)
{
        if (ListBox2->ItemIndex>=0)
        {
                ListBox1->Items->Add(ListBox2->Items->Strings[ListBox2->ItemIndex]);
				ListBox2->Items->Delete(ListBox2->ItemIndex);
				houve_modificacao_memorial=true;
		}

}
//---------------------------------------------------------------------------
void __fastcall TFormDefesaProjeto_candidatos::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

