//---------------------------------------------------------------------------

#ifndef EscritaH
#define EscritaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TFormEscrita : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TLabel *Label1;
        TCSpinEdit *CSpinEdit1;
        TDateTimePicker *DateTimePicker1;
        TLabel *Label2;
        TDateTimePicker *DateTimePicker2;
        TLabel *Label3;
        TButton *Button2;
        TDateTimePicker *DateTimePicker3;
        TLabel *Label5;
        TLabel *Label12;
        TEdit *Edit2;
        TTabSheet *TabSheet3;
        TValueListEditor *ValueListEditor1;
        TLabel *Label13;
        TLabel *Label16;
        TDateTimePicker *DateTimePicker6;
        TLabel *Label17;
        TTabSheet *TabSheet4;
        TLabel *Label18;
        TDateTimePicker *DateTimePicker7;
        TDateTimePicker *DateTimePicker8;
        TLabel *Label19;
        TEdit *Edit3;
        TLabel *Label20;
        TButton *Button16;
        TButton *Button5;
        TTabSheet *TabSheet2;
        TCheckListBox *CheckListBox2;
        TLabel *Label7;
        TLabel *Label8;
        TDateTimePicker *DateTimePicker4;
        TLabel *Label9;
        TLabel *Label10;
        TDateTimePicker *DateTimePicker5;
        TEdit *Edit1;
        TLabel *Label24;
        TButton *Button11;
        TTabSheet *TabSheet5;
        TListBox *ListBox4;
        TLabel *Label22;
        TLabel *Label6;
        TCheckListBox *CheckListBox1;
        TButton *Button6;
        TButton *Button17;
        TButton *Button3;
        TLabel *Label11;
        TLabel *Label25;
        TTabSheet *TabSheet6;
        TLabel *Label4;
        TLabel *Label23;
        TCheckListBox *ListBox1;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TEdit *Edit4;
        TButton *Button15;
        TButton *Button14;
        TTabSheet *TabSheet7;
        TListBox *ListBox2;
        TLabel *Label14;
        TLabel *Label15;
        TListBox *ListBox3;
        TButton *Button4;
        TTabSheet *TabSheet8;
        TButton *Button72;
        TLabel *Label21;
        TEdit *Edit5;
        TLabel *Label26;
        TDateTimePicker *DateTimePicker9;
        TLabel *Label27;
        TStaticText *StaticText1;
	TButton *Button1;
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ListBox1ClickCheck(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
		void __fastcall Button1Click(TObject *Sender);
		void __fastcall Button1Click2(TObject *Sender);
		void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button34Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button72Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormEscrita(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEscrita *FormEscrita;
//---------------------------------------------------------------------------
#endif