//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "listagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormListagem *FormListagem;
//---------------------------------------------------------------------------
__fastcall TFormListagem::TFormListagem(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
   /* DONE :
Salvar e abrir a listagem de documentos (será que já não foi feita?)
Se foi, adicionar os itens da sessão de leitura da prova escrita (2 itens) */

void __fastcall TFormListagem::Button1Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
