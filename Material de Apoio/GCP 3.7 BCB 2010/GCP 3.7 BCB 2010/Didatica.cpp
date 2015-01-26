//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "Didatica.h"
#include "Principal.h"
#include "Atas.h"
#include "Escrita.h"
#include "Didatica_Candidatos.h"
#include "Dicas.h"
#include "PegaData.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDidatica *FormDidatica;

vector<TLabel*> lab;
vector<TDateTimePicker*> dat_sor;
vector<TDateTimePicker*> hor_sor;
vector<TDateTimePicker*> dat_apr;
vector<TDateTimePicker*> hor_apr;
vector<TCheckBox*> comp_sor;
vector<TCheckBox*> comp_apr;
vector<TComboBox*> ponto;

//---------------------------------------------------------------------------
__fastcall TFormDidatica::TFormDidatica(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDidatica::Button1Click(TObject *Sender)
{
        // Esta fun��o utiliza apenas os dados de ListBox2



        for (unsigned int i=0; i<lab.size(); i++)
           delete lab[i];

        for (unsigned int i=0; i<dat_sor.size(); i++)
                delete dat_sor[i];

        for (unsigned int i=0; i<hor_sor.size(); i++)
                delete hor_sor[i];

        for (unsigned int i=0; i<dat_apr.size(); i++)
                delete dat_apr[i];

        for (unsigned int i=0; i<hor_apr.size(); i++)
                delete hor_apr[i];

        for (unsigned int i=0; i<comp_apr.size(); i++)
                delete comp_apr[i];

        for (unsigned int i=0; i<comp_sor.size(); i++)
                delete comp_sor[i];

        for (unsigned int i=0; i<ponto.size(); i++)
                delete ponto[i];






        lab.clear();
        dat_sor.clear();
        hor_sor.clear();
        dat_apr.clear();
        hor_apr.clear();
        comp_apr.clear();
        comp_sor.clear();
        ponto.clear();

        lab.resize(ListBox2->Items->Count);
        dat_sor.resize(ListBox2->Items->Count);
        hor_sor.resize(ListBox2->Items->Count);
        dat_apr.resize(ListBox2->Items->Count);
        hor_apr.resize(ListBox2->Items->Count);
        comp_apr.resize(ListBox2->Items->Count);
        comp_sor.resize(ListBox2->Items->Count);
        ponto.resize(ListBox2->Items->Count);

        int s1 = Shape1->Left;
        int s2 = Shape2->Left;
        int s3 = Shape3->Left;
        int s4 = Shape4->Left;
        int s5 = Shape5->Left;
        int s6 = Shape6->Left;
        int s7 = Shape7->Left;
        int s8 = Shape8->Left;
        int z = Shape1->Top;

        int deltay = 25;


        for (int i = 0; i<ListBox2->Items->Count; i++)
        {
                lab[i] = new TLabel(this);
                lab[i]->Left = s1;
                lab[i]->Top = z + (i)*deltay;
                lab[i]->Parent = ScrollBox1;
                lab[i]->Visible = true;
                lab[i]->Caption = ListBox2->Items->Strings[i];

                dat_sor[i] = new TDateTimePicker(this);
                dat_sor[i]->Left = s2;
                dat_sor[i]->Top = z + (i)*deltay;
                dat_sor[i]->Parent = ScrollBox1;
                dat_sor[i]->Visible = true;
                dat_sor[i]->Kind = dtkDate;
                dat_sor[i]->Width = 105;

                hor_sor[i] = new TDateTimePicker(this);
                hor_sor[i]->Left = s3;
                hor_sor[i]->Top = z + (i)*deltay;
                hor_sor[i]->Parent = ScrollBox1;
                hor_sor[i]->Visible = true;
                hor_sor[i]->Kind = dtkTime;
                hor_sor[i]->Format = "HH:mm";
                hor_sor[i]->Width = 105;

                dat_apr[i] = new TDateTimePicker(this);
                dat_apr[i]->Left = s4;
                dat_apr[i]->Top = z + (i)*deltay;
                dat_apr[i]->Parent = ScrollBox1;
                dat_apr[i]->Visible = true;
                dat_apr[i]->Kind = dtkDate;
                dat_apr[i]->Width = 105;

                hor_apr[i] = new TDateTimePicker(this);
                hor_apr[i]->Left = s5;
                hor_apr[i]->Top = z + (i)*deltay;
                hor_apr[i]->Parent = ScrollBox1;
                hor_apr[i]->Visible = true;
                hor_apr[i]->Kind = dtkTime;
                hor_apr[i]->Format = "HH:mm";
                hor_apr[i]->Width = 105;

                comp_sor[i] = new TCheckBox(this);
                comp_sor[i]->Left = s6;
                comp_sor[i]->Top = z + (i)*deltay;
                comp_sor[i]->Parent = ScrollBox1;
                comp_sor[i]->Visible = true;
                comp_sor[i]->Width = 105;
                comp_sor[i]->Checked = true;
                comp_sor[i]->Caption = "";

                ponto[i] = new TComboBox(this);
                ponto[i]->Left = s7;
                ponto[i]->Top = z + (i)*deltay;
                ponto[i]->Parent = ScrollBox1;
                ponto[i]->Visible = true;
                //ponto[i]->Width = 105;
                ponto[i]->Items = ListBox1->Items;
                //ponto[i]->Caption = "Selecione...";

                comp_apr[i] = new TCheckBox(this);
                comp_apr[i]->Left = s8;
                comp_apr[i]->Top = z + (i)*deltay;
                comp_apr[i]->Parent = ScrollBox1;
                comp_apr[i]->Visible = true;
                comp_apr[i]->Width = 105;
                comp_apr[i]->Checked = true;
                comp_apr[i]->Caption = "";
        }
        AtualizaPontos();
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button13Click(TObject *Sender)
{
        String a;
        int i = ListBox1->Items->Count;
        a = IntToStr(i+1);
        a = a + " - " + Edit4->Text;
        ListBox1->Items->Add(a);
        ListBox1->Checked[i] = true;

        tipo_ponto ex_ponto;

        ex_ponto.texto = Edit4->Text;
        ex_ponto.valido = true;

        //ponto_escrita.push_back(ex_ponto);
        ponto_didatica.push_back(ex_ponto);

        ListBox1 -> ItemIndex = ListBox1->Items->Count - 1;
        AtualizaPontos();
        ListBox1Click(FormDidatica);

}
//---------------------------------------------------------------------------


void __fastcall TFormDidatica::AtualizaPontos()
{
      for (unsigned int i=0; i<ponto.size(); i++)
      {
          ponto[i]->Items->Clear();
          ponto[i]->Items = ListBox1->Items;
      }
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button14Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;

        if (i >=0)
        {
        //ponto_escrita.erase(ponto_escrita.begin() + i);
        ponto_didatica.erase(ponto_didatica.begin() + i);

        ListBox1->Items->Clear();

        //for (unsigned int j=0; j<ponto_escrita.size() ; j++)
        for (unsigned int j=0; j<ponto_didatica.size() ; j++)
        {
               // ListBox1->Items->Add(ponto_escrita[j].texto);

                String a;
				a = IntToStr((int)j+1);
                //a = a + " - " + ponto_escrita[j].texto;
                a = a + " - " + ponto_didatica[j].texto;
                ListBox1->Items->Add(a);
                //ListBox1->Checked[j] = ponto_escrita[j].valido;
                ListBox1->Checked[j] = ponto_didatica[j].valido;
        }
        if (ListBox1->Items->Count > 0)
        {
                ListBox1->ItemIndex = 0;
                ListBox1Click(FormDidatica);
        }
        AtualizaPontos();
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button15Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;

        if (i >= 0)
        {
        //ponto_escrita[i].texto = Edit4->Text;
        ponto_didatica[i].texto = Edit4->Text;
        //ponto_escrita[i].valido = CheckBox3->Checked;


        // Atualiza a lista
        ListBox1->Items->Clear();
        //for (unsigned int j=0; j<ponto_escrita.size() ; j++)
        for (unsigned int j=0; j<ponto_didatica.size() ; j++)
        {
                String a;
				a = IntToStr((int)j+1);
                //a = a + " - " + ponto_escrita[j].texto;
                a = a + " - " + ponto_didatica[j].texto;
                ListBox1->Items->Add(a);
                //ListBox1->Checked[j] = ponto_escrita[j].valido    ;
                ListBox1->Checked[j] = ponto_didatica[j].valido    ;
                //ListBox1->Checked[j] = CheckBox3->Checked;

        }
        if (ListBox1->Items->Count > 0)
                ListBox1->ItemIndex = i;
                ListBox1Click(FormDidatica);

        AtualizaPontos();
        }

}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::ListBox1Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;

        int hhh = ponto_didatica.size();
        //Edit4->Text = ponto_escrita[i].texto;
        Edit4->Text = ponto_didatica[i].texto;

}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::ListBox1ClickCheck(TObject *Sender)
{
        int i = ListBox1->ItemIndex;
        //ponto_escrita[i].valido = ListBox1->Checked[i];
        ponto_didatica[i].valido = ListBox1->Checked[i];
        ListBox1Click(FormDidatica);

}
//---------------------------------------------------------------------------







void __fastcall TFormDidatica::Button3Click(TObject *Sender)
{

        if (hor_sor.size()>0)
        {

        bool falta = false;
        for (unsigned int i=0; i<ponto.size(); i++)
                if (comp_sor[i] && ponto[i]->ItemIndex<0)
                        falta = true;
		if (falta)
				Application->MessageBox(L"Selecione o ponto sorteado de todos os candidatos que compareceram.", L"Erro", 0);
		else
           {
                 SelData->ShowModal();
                 FormAtas->Button11Click(FormDidatica);
           }
        }
        else
				Application->MessageBox(L"Configure candidatos aptos (Item 4.1).",L"Aten��o",0);
}
//---------------------------------------------------------------------------



void __fastcall TFormDidatica::Button4Click(TObject *Sender)
{
       if (hor_sor.size()>0)
        {
               SelData->ShowModal();
               FormAtas->Button12Click(FormDidatica);
        }
        else
				Application->MessageBox(L"Configure candidatos aptos (Item 4.1).",L"Aten��o",0);

}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button5Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button13Click(FormDidatica);
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button8Click(TObject *Sender)
{
        if (hor_sor.size()>0)
        {

              SelData->ShowModal();
              FormAtas->Button15Click(FormDidatica);
        }
        else
				Application->MessageBox(L"Configure candidatos aptos (Item 4.1).",L"Aten��o",0);

}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button9Click(TObject *Sender)
{

        if (hor_sor.size()>0)
        {

                SelData->ShowModal();
                FormAtas->Button16Click(FormDidatica);
        }
        else
				Application->MessageBox(L"Configure candidatos aptos (Item 4.1).",L"Aten��o",0);

}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button10Click(TObject *Sender)
{
        FormAtas->Button21Click(FormDidatica);
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button6Click(TObject *Sender)
{
		if (ListBox2->ItemIndex>=0 && ListBox3->ItemIndex>=0)
				FormAtas->Button14Click(FormDidatica);
		else
				Application->MessageBox(L"Selecione o candidato e o examinador.", L"Erro", 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button2Click(TObject *Sender)
{
		if (Application->MessageBox(L"Isso apagar� todos os pontos j� digitados.\nDeseja continuar?", L"Aten��o", MB_YESNO) == IDYES)
        {
                ListBox1->Items->Clear();
                ListBox1->Items = FormEscrita->ListBox1->Items;
                ponto_didatica.clear();
				ponto_didatica = ponto_escrita;
				AtualizaPontos();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormDidatica::Button7Click(TObject *Sender)
{
        FormDidaticaCandidatos->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFormDidatica::Dicas1Click(TObject *Sender)
{
        FormDicas->PageControl1->ActivePage = FormDicas->TabDidatica;
        FormDicas->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button4123Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button4221Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button8776Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button32Click(FormDidatica);
}
//---------------------------------------------------------------------------

void __fastcall TFormDidatica::Button8Click2(TObject *Sender)
{
		// Imprime todas as planilhas de avaliacao da prova didatica

		// Grava a selecao atual dos ListBox
		int atual2=ListBox2->ItemIndex;
		int atual3=ListBox3->ItemIndex;

		for (int i=0; i<ListBox2->Items->Count; i++)
		{
			for (int j = 0; j<ListBox3->Items->Count; j++)
			{
				  ListBox2->ItemIndex = i;
				  ListBox3->ItemIndex = j;
				  FormAtas->Button14Click(FormDidatica);
			}
		}

		// Retorna a selecao anterior
		ListBox2->ItemIndex = atual2;
		ListBox3->ItemIndex = atual3;
}