//---------------------------------------------------------------------------

#ifndef Entrevista_candidatosH
#define Entrevista_candidatosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormEntrevista_candidatos : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
		TLabel *Label2;
        TLabel *Label3;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TButton *Button6;
        TButton *Button17;
        TButton *Button1;
	TLabel *Label4;
	TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormEntrevista_candidatos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEntrevista_candidatos *FormEntrevista_candidatos;
//---------------------------------------------------------------------------
#endif