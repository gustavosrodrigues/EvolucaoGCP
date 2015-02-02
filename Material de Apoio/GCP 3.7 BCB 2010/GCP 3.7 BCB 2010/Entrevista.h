//---------------------------------------------------------------------------

#ifndef EntrevistaH
#define EntrevistaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TFormEntrevista : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button3;
        TButton *Button5;
        TButton *Button7;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TLabel *Label14;
        TLabel *Label15;
        TListBox *ListBox2;
        TListBox *ListBox3;
        TButton *Button6;
        TTabSheet *TabSheet2;
        TScrollBox *ScrollBox1;
        TLabel *Label3;
        TShape *Shape1;
        TShape *Shape2;
        TLabel *Label4;
        TLabel *Label5;
        TShape *Shape3;
        TShape *Shape4;
        TLabel *Label10;
        TTabSheet *TabSheet3;
        TLabel *Label17;
        TLabel *Label16;
        TValueListEditor *ValueListEditor1;
        TTabSheet *TabSheet4;
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button4;
        TLabel *Label2;
	TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
		void __fastcall Button2Click(TObject *Sender);
		void __fastcall Button2Click2(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormEntrevista(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEntrevista *FormEntrevista;
using namespace std;


//---------------------------------------------------------------------------
#endif
