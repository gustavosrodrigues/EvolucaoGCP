//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <vector>
#include "Principal.h"
#include "DefesaProjeto.h"
#include "Atas.h"
#include "DefesaProjeto_candidatos.h"
#include "Dicas.h"
#include "PegaData.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDefesaProjeto *FormDefesaProjeto;

vector<TLabel*> lab_def;
vector<TDateTimePicker*> dat_def;
vector<TDateTimePicker*> hor_def;
vector<TCheckBox*> comp_def;


//---------------------------------------------------------------------------
__fastcall TFormDefesaProjeto::TFormDefesaProjeto(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDefesaProjeto::Button1Click(TObject *Sender)
{

        for (unsigned int i=0; i<lab_def.size(); i++)
        {

        delete lab_def[i];
        delete dat_def[i];
        delete hor_def[i];
        delete comp_def[i];
        }




        lab_def.clear();
        dat_def.clear();
        hor_def.clear();
        comp_def.clear();

        lab_def.resize(ListBox2->Items->Count);
        dat_def.resize(ListBox2->Items->Count);
        hor_def.resize(ListBox2->Items->Count);
        comp_def.resize(ListBox2->Items->Count);

        int s1 = Shape1->Left;
        int s2 = Shape2->Left;
        int s3 = Shape3->Left;
        int s4 = Shape4->Left;

        int z = Shape1->Top;

        int deltay = 25;

        int aa = ListBox2->Items->Count;
        for (int i = 0; i<ListBox2->Items->Count; i++)
        {
                lab_def[i] = new TLabel(this);
                lab_def[i]->Left = s1;
                lab_def[i]->Top = z + (i)*deltay;
                lab_def[i]->Parent = ScrollBox1;
                lab_def[i]->Visible = true;
                lab_def[i]->Caption = ListBox2->Items->Strings[i];

                dat_def[i] = new TDateTimePicker(this);
                dat_def[i]->Left = s2;
				dat_def[i]->Top = z + (i)*deltay;
                dat_def[i]->Parent = ScrollBox1;
                dat_def[i]->Visible = true;
                dat_def[i]->Kind = dtkDate;
                dat_def[i]->Width = 105;

                hor_def[i] = new TDateTimePicker(this);
                hor_def[i]->Left = s3;
                hor_def[i]->Top = z + (i)*deltay;
                hor_def[i]->Parent = ScrollBox1;
                hor_def[i]->Visible = true;
                hor_def[i]->Kind = dtkTime;
                hor_def[i]->Format = "HH:mm";
                hor_def[i]->Width = 105;

                comp_def[i] = new TCheckBox(this);
                comp_def[i]->Left = s4;
                comp_def[i]->Top = z + (i)*deltay;
                comp_def[i]->Parent = ScrollBox1;
                comp_def[i]->Visible = true;
                comp_def[i]->Width = 105;
                comp_def[i]->Checked = true;
                comp_def[i]->Caption = "";

        }



}
//---------------------------------------------------------------------------


void __fastcall TFormDefesaProjeto::Button4Click(TObject *Sender)
{
        if (hor_def.size()>0)
        {
                SelData->ShowModal();
				FormAtas->Button17Click(FormDefesaProjeto);
        }
        else
				Application->MessageBox(L"Configure candidatos aptos (Item 5.1)",L"Aten��o",0);
}
//---------------------------------------------------------------------------

void __fastcall TFormDefesaProjeto::Button8Click(TObject *Sender)
{

        if (hor_def.size()>0)
		{
                SelData->ShowModal();
                FormAtas->Button18Click(FormDefesaProjeto);
        }
		else
				Application->MessageBox(L"Configure candidatos aptos (Item 5.1).",L"Aten��o",0);
}
//---------------------------------------------------------------------------

void __fastcall TFormDefesaProjeto::Button2Click(TObject *Sender)
{
        FormAtas->Button20Click(FormDefesaProjeto);
}
//---------------------------------------------------------------------------

void __fastcall TFormDefesaProjeto::Button6Click(TObject *Sender)
{
 if (ListBox2->ItemIndex>=0 && ListBox3->ItemIndex>=0)
 {
                SelData->ShowModal();
                FormAtas->Button19Click(FormDefesaProjeto);
 }
        else
                Application->MessageBox(L"Selecione o candidato e o examinador.", L"Erro", 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormDefesaProjeto::Button3Click(TObject *Sender)
{
        FormDefesaProjeto_candidatos->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TFormDefesaProjeto::Button5Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormDefesaProjeto::Button7Click(TObject *Sender)
{
        FormDicas->PageControl1->ActivePage = FormDicas->TabMemorial;
        FormDicas->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFormDefesaProjeto::Button2Click2(TObject *Sender)
{
	// Imprime todas as planilhas de avaliacao da prova defesa memorial

		// Grava a selecao atual dos ListBox
		int atual2=ListBox2->ItemIndex;
		int atual3=ListBox3->ItemIndex;

		for (int i=0; i<ListBox2->Items->Count; i++)
		{
			for (int j = 0; j<ListBox3->Items->Count; j++)
			{
				  ListBox2->ItemIndex = i;
				  ListBox3->ItemIndex = j;
				  FormAtas->Button19Click(FormDefesaProjeto);
			}
		}

		// Retorna a selecao anterior
		ListBox2->ItemIndex = atual2;
		ListBox3->ItemIndex = atual3;
}

