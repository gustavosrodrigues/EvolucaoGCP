//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SplashScreen.h"
#include "Atualizar.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSplash *FormSplash;
int tempo = 0;
//---------------------------------------------------------------------------
__fastcall TFormSplash::TFormSplash(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSplash::Timer1Timer(TObject *Sender)
{
       if (Startup1)
       {
        tempo = tempo + 1;
        ProgressBar1->Position = tempo;
        if (tempo == 100)
        {
                   ModalResult = mrOk;
                   Startup1 = false;
        }
       }
       // Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSplash::Button1Click(TObject *Sender)
{
		Startup1 = false;
		ModalResult = mrOk;



        //Form1->Show();
        //Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormSplash::FormCreate(TObject *Sender)
{

    //Memo1->Lines->Clear();
    //Memo1->Lines->Add("Vers�o 0.9");
    FormSplash->Width = 406;

}
//---------------------------------------------------------------------------



void __fastcall TFormSplash::Label6MouseEnter(TObject *Sender)
{
          Label6->Font->Size = 12;
}
//---------------------------------------------------------------------------

void __fastcall TFormSplash::Label6MouseLeave(TObject *Sender)
{
        Label6->Font->Size = 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormSplash::Label6Click(TObject *Sender)
{
        //FormSplash->Width = 695;
        Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormSplash::Timer2Timer(TObject *Sender)
{
        if (FormSplash->Width < 685)
        {
           FormSplash->Width++;
           FormSplash->Left = FormSplash->Left - FormSplash->Width%2;
        }
        else
           Timer2->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormSplash::FormShow(TObject *Sender)
{
	Label2->Caption = "Vers�o " + versao + ". Compilado em " + data_compilacao + ".";
	//Label7->Caption = normativa;

}
//---------------------------------------------------------------------------
void __fastcall TFormSplash::Label8Click(TObject *Sender)
{
	FormAtualizar->ShowModal();
	Button1Click(this);
}
//---------------------------------------------------------------------------

