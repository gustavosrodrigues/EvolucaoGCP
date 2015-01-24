//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Dialogo.h"
#include "ListaDocumentos.h"

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TNroDlg *NroDlg;
//---------------------------------------------------------------------
__fastcall TNroDlg::TNroDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TNroDlg::OKBtnClick(TObject *Sender)
{
        int a;
        if (!(TryStrToInt(Nro->Text, a)))
        {
               Label2->Visible = true; //Application->MessageBox("Valor não numérico", "Erro", 0);
        }
        else
        {
                Label2->Visible = false;
                //FormLista->Close();
                ModalResult = mrOk;
        }
}
//---------------------------------------------------------------------------

void __fastcall TNroDlg::CancelBtnClick(TObject *Sender)
{
        //FormLista->Close();
        ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TNroDlg::Button1Click(TObject *Sender)
{
        //FormLista->Close();
        ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TNroDlg::FormShow(TObject *Sender)
{
        //FormLista->Show();
        //SetFocus();
}
//---------------------------------------------------------------------------

