//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <vector>
#include "Principal.h"
#include "Entrevista.h"
#include "Atas.h"
#include "Entrevista_candidatos.h"
#include "Dicas.h"
#include "PegaData.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEntrevista *FormEntrevista;

vector<TLabel*> lab_ent;
vector<TDateTimePicker*> dat_ent;
vector<TDateTimePicker*> hor_ent;
vector<TCheckBox*> comp_ent;


//---------------------------------------------------------------------------
__fastcall TFormEntrevista::TFormEntrevista(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEntrevista::Button1Click(TObject *Sender)
{

		for (unsigned int i=0; i<lab_ent.size(); i++)
		{

		delete lab_ent[i];
		delete dat_ent[i];
		delete hor_ent[i];
		delete comp_ent[i];
		}




		lab_ent.clear();
		dat_ent.clear();
		hor_ent.clear();
		comp_ent.clear();

		lab_ent.resize(ListBox2->Items->Count);
		dat_ent.resize(ListBox2->Items->Count);
		hor_ent.resize(ListBox2->Items->Count);
		comp_ent.resize(ListBox2->Items->Count);

        int s1 = Shape1->Left;
        int s2 = Shape2->Left;
        int s3 = Shape3->Left;
        int s4 = Shape4->Left;

        int z = Shape1->Top;

        int deltay = 25;

		for (int i = 0; i<ListBox2->Items->Count; i++)
        {
				lab_ent[i] = new TLabel(this);
				lab_ent[i]->Left = s1;
				lab_ent[i]->Top = z + (i)*deltay;
				lab_ent[i]->Parent = ScrollBox1;
				lab_ent[i]->Visible = true;
				lab_ent[i]->Caption = ListBox2->Items->Strings[i];

				dat_ent[i] = new TDateTimePicker(this);
				dat_ent[i]->Left = s2;
				dat_ent[i]->Top = z + (i)*deltay;
				dat_ent[i]->Parent = ScrollBox1;
				dat_ent[i]->Visible = true;
				dat_ent[i]->Kind = dtkDate;
				dat_ent[i]->Width = 105;

				hor_ent[i] = new TDateTimePicker(this);
				hor_ent[i]->Left = s3;
				hor_ent[i]->Top = z + (i)*deltay;
				hor_ent[i]->Parent = ScrollBox1;
				hor_ent[i]->Visible = true;
				hor_ent[i]->Kind = dtkTime;
				hor_ent[i]->Format = "HH:mm";
				hor_ent[i]->Width = 105;

				comp_ent[i] = new TCheckBox(this);
				comp_ent[i]->Left = s4;
				comp_ent[i]->Top = z + (i)*deltay;
				comp_ent[i]->Parent = ScrollBox1;
				comp_ent[i]->Visible = true;
				comp_ent[i]->Width = 105;
				comp_ent[i]->Checked = true;
				comp_ent[i]->Caption = "";

		}



}
//---------------------------------------------------------------------------


void __fastcall TFormEntrevista::Button4Click(TObject *Sender)
{
		if (hor_ent.size()>0)
		{
				SelData->ShowModal();
				FormAtas->Button38Click(this);
		}
		else
				Application->MessageBox(L"Configure candidatos aptos.",L"Aten��o",0);
}
//---------------------------------------------------------------------------

void __fastcall TFormEntrevista::Button8Click(TObject *Sender)
{

		if (hor_ent.size()>0)
		{
				SelData->ShowModal();
				FormAtas->Button39Click(this);
		}
		else
				Application->MessageBox(L"Configure candidatos aptos.",L"Aten��o",0);
}
//---------------------------------------------------------------------------

void __fastcall TFormEntrevista::Button2Click(TObject *Sender)
{
		FormAtas->Button20Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEntrevista::Button6Click(TObject *Sender)
{
 if (ListBox2->ItemIndex>=0 && ListBox3->ItemIndex>=0)
 {
				SelData->ShowModal();
				FormAtas->Button40Click(this);
 }
		else
				Application->MessageBox(L"Selecione o candidato e o examinador.", L"Erro", 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormEntrevista::Button3Click(TObject *Sender)
{
		FormEntrevista_candidatos->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormEntrevista::Button5Click(TObject *Sender)
{
		Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEntrevista::Button7Click(TObject *Sender)
{
		FormDicas->PageControl1->ActivePage = FormDicas->TabEntrevista;
		FormDicas->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFormEntrevista::Button2Click2(TObject *Sender)
{
	// Imprime todas as planilhas de avaliacao da prova entrevista

		// Grava a selecao atual dos ListBox
		int atual2=ListBox2->ItemIndex;
		int atual3=ListBox3->ItemIndex;

		for (int i=0; i<ListBox2->Items->Count; i++)
		{
			for (int j = 0; j<ListBox3->Items->Count; j++)
			{
				  ListBox2->ItemIndex = i;
				  ListBox3->ItemIndex = j;
				  FormAtas->Button40Click(this);
			}
		}

		// Retorna a selecao anterior
		ListBox2->ItemIndex = atual2;
		ListBox3->ItemIndex = atual3;
}
