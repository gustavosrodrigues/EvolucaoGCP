//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escrita.h"
#include "Principal.h"
#include "Atas.h"
#include "Didatica.h"
#include "PegaData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormEscrita *FormEscrita;
//---------------------------------------------------------------------------
__fastcall TFormEscrita::TFormEscrita(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEscrita::Button8Click(TObject *Sender)
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

        ponto_escrita.push_back(ex_ponto);

        ListBox1 -> ItemIndex = ListBox1->Items->Count - 1;
        CSpinEdit1->MaxValue = ListBox1->Items->Count;
        ListBox1Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button9Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;

        if (i >=0)
        {
        ponto_escrita.erase(ponto_escrita.begin() + i);

        ListBox1->Items->Clear();

        for (unsigned int j=0; j<ponto_escrita.size() ; j++)
        {
               // ListBox1->Items->Add(ponto_escrita[j].texto);

				String a;
				a = IntToStr(int(j+1));
                a = a + " - " + ponto_escrita[j].texto;
                ListBox1->Items->Add(a);
                ListBox1->Checked[j] = ponto_escrita[j].valido;
        }
        if (ListBox1->Items->Count > 0)
        {
                ListBox1->ItemIndex = 0;
                ListBox1Click(FormEscrita);
        }
        }
        CSpinEdit1->MaxValue = ListBox1->Items->Count;
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button10Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;

        if (i >= 0)
        {
        ponto_escrita[i].texto = Edit4->Text;
        //ponto_escrita[i].valido = CheckBox3->Checked;


        // Atualiza a lista
        ListBox1->Items->Clear();
        for (unsigned int j=0; j<ponto_escrita.size() ; j++)
        {
                String a;
				a = Sysutils::IntToStr((int)j+1);
                a = a + " - " + ponto_escrita[j].texto;
                ListBox1->Items->Add(a);
                ListBox1->Checked[j] = ponto_escrita[j].valido    ;
                //ListBox1->Checked[j] = CheckBox3->Checked;

        }
        if (ListBox1->Items->Count > 0)
                ListBox1->ItemIndex = i;
                ListBox1Click(FormEscrita);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::ListBox1Click(TObject *Sender)
{
        int i = ListBox1->ItemIndex;


        Edit4->Text = ponto_escrita[i].texto;
        //CheckBox3->Checked = ponto_escrita[i].valido;

}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::ListBox1ClickCheck(TObject *Sender)
{
        int i = ListBox1->ItemIndex;
        ponto_escrita[i].valido = ListBox1->Checked[i];
        ListBox1Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button14Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button6Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button4Click(TObject *Sender)
{
		if (ListBox2->ItemIndex >= 0 && ListBox3->ItemIndex >= 0)
				FormAtas->Button5Click(FormEscrita);
		else
				Application->MessageBox(L"Selecione o candidato e o examinador para gerar a planilha", L"Erro",0);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button33Click(TObject *Sender)
{
      FormAtas->Button4Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button13Click(TObject *Sender)
{
      //  FormAtas->Button9Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button15Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button7Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button2Click(TObject *Sender)
{
       if (ListBox1->Items->Count > 0)
             if (CSpinEdit1->Value > 0)
             {
                  SelData->ShowModal();
                  FormAtas->Button3Click(FormEscrita);

             }
             else
				Application->MessageBox(L"Selecione o ponto sorteado!\nArquivo não pode ser gerado.", L"Erro", 0);
	   else
			 Application->MessageBox(L"Lista de pontos está vazia!\nArquivo não pode ser gerado.", L"Erro", 0);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button7Click(TObject *Sender)
{
        FormAtas->Button8Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button16Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button10Click(FormEscrita);
}
//---------------------------------------------------------------------------



void __fastcall TFormEscrita::Button1Click(TObject *Sender)
{
		if (Application->MessageBox(L"Isso apagará todos os pontos já digitados.\nDeseja continuar?", L"Atenção", MB_YESNO) == IDYES)
        {
                ListBox1->Items->Clear();
                ListBox1->Items = FormDidatica->ListBox1->Items;
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormEscrita::Button6Click(TObject *Sender)
{
        if (ListBox4->ItemIndex>=0)            /* DONE : Atualizar o CheckList2 ao abrir */
        {
                CheckListBox1->Items->Add(ListBox4->Items->Strings[ListBox4->ItemIndex]);
                CheckListBox2->Items->Add(ListBox4->Items->Strings[ListBox4->ItemIndex]);

                ListBox2->Items->Add(ListBox4->Items->Strings[ListBox4->ItemIndex]);
                ListBox4->Items->Delete(ListBox4->ItemIndex);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button17Click(TObject *Sender)
{
        if (CheckListBox1->ItemIndex>=0)
        {
                ListBox4->Items->Add(CheckListBox1->Items->Strings[CheckListBox1->ItemIndex]);
                ListBox2->Items->Delete(CheckListBox1->ItemIndex);
                CheckListBox2->Items->Delete(CheckListBox1->ItemIndex);
                CheckListBox1->Items->Delete(CheckListBox1->ItemIndex);
                
        }
}
//---------------------------------------------------------------------------

 /* DONE : Salvar e abrir  a aba "Leitura da prova escrita" */
          /* DONE :  Verificar o cálculo da média final com a nova média 7. */

void __fastcall TFormEscrita::Button34Click(TObject *Sender)
{
        FormAtas->Button35Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button11Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button4Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button3Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button5Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------



void __fastcall TFormEscrita::Button72Click(TObject *Sender)
{
        SelData->ShowModal();
        FormAtas->Button31Click(FormEscrita);
}
//---------------------------------------------------------------------------

void __fastcall TFormEscrita::Button1Click2(TObject *Sender)
{
		// Imprime todas as planilhas de avaliacao da prova escrita

		// Grava a selecao atual dos ListBox
		int atual2=ListBox2->ItemIndex;
		int atual3=ListBox3->ItemIndex;

		for (int i=0; i<ListBox2->Items->Count; i++)
		{
			for (int j = 0; j<ListBox3->Items->Count; j++)
			{
				  ListBox2->ItemIndex = i;
				  ListBox3->ItemIndex = j;
				  FormAtas->Button5Click(FormEscrita);
			}
		}

		// Retorna a selecao anterior
		ListBox2->ItemIndex = atual2;
		ListBox3->ItemIndex = atual3;

}
