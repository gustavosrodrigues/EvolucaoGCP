//---------------------------------------------------------------------------

#ifndef AberturaH
#define AberturaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAbertura : public TForm
{
__published:	// IDE-managed Components
        TButton *Button2;
        TButton *Button5;
        TButton *Button6;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TTabSheet *TabSheet2;
        TStringGrid *StringGrid1;
        TLabel *Label7;
        TLabel *Label8;
        TDateTimePicker *DateTimePicker3;
        TTabSheet *TabSheet3;
        TCheckListBox *CheckListBox1;
        TLabel *Label1;
        TButton *Button111;
        TButton *Button10;
        TButton *Button13;
        TLabel *Label9;
        TDateTimePicker *DateTimePicker4;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
	TTabSheet *TabSheet4;
	TEdit *Edit10;
	TLabel *Label13;
	TLabel *Label14;
	TEdit *Edit12;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *Edit11;
	TEdit *Edit13;
	TEdit *Edit14;
	TLabel *Label19;
	TButton *Button1;
	TLabel *Label20;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
        void __fastcall Button3Click(TObject *Sender);
		void __fastcall Button1Click(TObject *Sender);
		void __fastcall Button1Click2(TObject *Sender);
		void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Gerarrecibodadocumentaodocandidatoselecionado1Click(
          TObject *Sender);
        void __fastcall Button111Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormAbertura(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbertura *FormAbertura;
//---------------------------------------------------------------------------
#endif