//---------------------------------------------------------------------------

#ifndef LogH
#define LogH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormLog : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormLog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLog *FormLog;
//---------------------------------------------------------------------------
#endif