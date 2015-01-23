//---------------------------------------------------------------------------

#ifndef Didatica_candidatosH
#define Didatica_candidatosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormDidaticaCandidatos : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TListBox *ListBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button6;
        TButton *Button17;
        TButton *Button1;
        TLabel *Label4;
	TButton *Button2;
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormDidaticaCandidatos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDidaticaCandidatos *FormDidaticaCandidatos;
//---------------------------------------------------------------------------
#endif
