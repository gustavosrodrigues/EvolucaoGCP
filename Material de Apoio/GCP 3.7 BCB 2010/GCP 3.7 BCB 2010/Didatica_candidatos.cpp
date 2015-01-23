//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

using namespace std;
#include <vector>
#include "Didatica_candidatos.h"
#include "Didatica.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDidaticaCandidatos *FormDidaticaCandidatos;
bool houve_modificacao=false;
//---------------------------------------------------------------------------
__fastcall TFormDidaticaCandidatos::TFormDidaticaCandidatos(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDidaticaCandidatos::Button6Click(TObject *Sender)
{
		if (ListBox1->ItemIndex>=0)
        {
                ListBox2->Items->Add(ListBox1->Items->Strings[ListBox1->ItemIndex]);
				ListBox1->Items->Delete(ListBox1->ItemIndex);
				houve_modificacao=true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDidaticaCandidatos::Button17Click(TObject *Sender)
{
        if (ListBox2->ItemIndex>=0)
        {
                ListBox1->Items->Add(ListBox2->Items->Strings[ListBox2->ItemIndex]);
				ListBox2->Items->Delete(ListBox2->ItemIndex);
				houve_modificacao=true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDidaticaCandidatos::Button1Click(TObject *Sender)
{
	if (houve_modificacao) {
		if (Application->MessageBoxA(L"Esta altera��o ir� apagar qualquer outra configura��o de candidatos para a prova D�d�tica. Deseja continuar?",L"Aten��o", MB_YESNO )==ID_YES) {

		FormDidatica->ListBox2->Items = ListBox2->Items;
		FormDidatica->Button1Click(FormDidaticaCandidatos);
		houve_modificacao=false;


		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDidaticaCandidatos::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

