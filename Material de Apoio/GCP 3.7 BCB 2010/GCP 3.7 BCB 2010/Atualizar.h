//---------------------------------------------------------------------------

#ifndef AtualizarH
#define AtualizarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAtualizar : public TForm
{
__published:	// IDE-managed Components
	TIdHTTP *IdHTTP1;
	TEdit *Edit1;
	TButton *Button1;
	TProgressBar *ProgressBar1;
	TButton *Button2;
	TMemo *Memo1;
	TButton *Button3;
	TLabel *Label1;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall IdHTTP1WorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormAtualizar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAtualizar *FormAtualizar;
//---------------------------------------------------------------------------
#endif
