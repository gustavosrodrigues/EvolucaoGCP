//---------------------------------------------------------------------------

#ifndef TitulosH
#define TitulosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormTitulos : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TScrollBox *ScrollBox1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TEdit *Edit22;
        TLabel *Label5;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TComboBox *ComboBox1;
        TLabel *Label6;
        TEdit *Edit144;
        TLabel *Label17;
        TEdit *Edit93;
        TLabel *Label52;
        TLabel *Label53;
        TEdit *Edit94;
        TLabel *Label54;
        TEdit *Edit95;
        TLabel *Label55;
        TEdit *Edit96;
        TShape *Shape15;
        TButton *Button4;
        TComboBox *ComboBox2;
        TLabel *Label7;
        TDateTimePicker *DateTimePicker1;
        TLabel *Label57;
        TLabel *Label62;
        TEdit *Edit5;
        TLabel *Label63;
        TEdit *Edit6;
        TEdit *Edit7;
        TGroupBox *GroupBox1;
        TEdit *Edit2;
        TLabel *Label59;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label60;
        TLabel *Label61;
        TGroupBox *GroupBox2;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TLabel *Label66;
        TLabel *Label67;
        TLabel *Label68;
        TMemo *Memo1;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TLabel *Label64;
        TLabel *Label65;
        TLabel *Label69;
        TStringGrid *StringGrid1;
        TLabel *Label70;
        TGroupBox *GroupBox3;
        TLabel *Label71;
        TLabel *Label72;
        TLabel *Label73;
        TEdit *Edit14;
        TEdit *Edit15;
        TEdit *Edit16;
        TTabSheet *TabSheet5;
        TLabel *Label56;
        TEdit *Edit1;
        TLabel *Label58;
        TDateTimePicker *DateTimePicker2;
        TButton *Button2;
        TLabel *Label74;
        TTabSheet *TabSheet2;
        TLabel *Label12;
        TEdit *Edit47;
        TLabel *Label40;
	TLabel *Label95;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
        TButton *Button3;
        TStaticText *StaticText1;
	TStringGrid *TabelaClasse1;
	TStringGrid *TabelaClasse2;
	TStringGrid *TabelaClasse3;
	TStringGrid *TabelaRegrasMaxPont;
	TStringGrid *TabelaRegrasCumulativo;
	TLabel *Label96;
	TLabel *Label97;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TStaticText *StaticText4;
	TStaticText *StaticText5;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TStaticText *StaticText10;
	TStaticText *StaticText11;
        void __fastcall E001Exit(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Dicas1Click(TObject *Sender);
        void __fastcall Edit2Exit(TObject *Sender);
        void __fastcall CalculaPontuacaoTotal(int ic, int candidato_atual);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall TabelaClasse1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall TabelaClasse1SetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall TabelaClasse1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall MultiplicaLinhas(TObject *Sender);
	void __fastcall VerificaRegras(TObject *Sender, int ARow);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);





private:	// User declarations
public:		// User declarations
        __fastcall TFormTitulos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTitulos *FormTitulos;
//---------------------------------------------------------------------------
#endif

