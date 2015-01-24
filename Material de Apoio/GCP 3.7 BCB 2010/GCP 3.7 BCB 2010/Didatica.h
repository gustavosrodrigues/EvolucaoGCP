//---------------------------------------------------------------------------

#ifndef DidaticaH
#define DidaticaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ValEdit.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormDidatica : public TForm
{
__published:	// IDE-managed Components
        TButton *Button7;
        TMainMenu *MainMenu1;
        TMenuItem *Atas1;
        TMenuItem *Atadesorteiodopontodaprovadidtica1;
        TMenuItem *Ataderealizaodaprovadidtica1;
        TMenuItem *Listas1;
        TMenuItem *Listadepontosparaprovadidtica1;
        TMenuItem *Listadepresenanosorteiodopontoparaprovadidtica1;
        TMenuItem *Listadepresenanaapresentaodaprovadidtica1;
        TMenuItem *Listadecritriosdeavaliaodaprovadidtica1;
        TMenuItem *Geraodeplanilhas1;
        TMenuItem *Planilhadenotas1;
        TMenuItem *Configurao1;
        TMenuItem *Configurarcandidatosaptosaestaetapadoconcurso1;
        TMenuItem *Ajuda1;
        TMenuItem *Dicas1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TScrollBox *ScrollBox1;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TShape *Shape6;
        TShape *Shape7;
        TLabel *Label11;
        TLabel *Label12;
        TShape *Shape8;
        TButton *Button1;
        TTabSheet *TabSheet2;
        TLabel *Label5;
        TLabel *Label1;
        TEdit *Edit4;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TCheckListBox *ListBox1;
        TButton *Button2;
        TButton *Button3;
        TTabSheet *TabSheet3;
        TLabel *Label20;
        TValueListEditor *ValueListEditor1;
        TLabel *Label17;
        TLabel *Label22;
        TButton *Button4123;
        TTabSheet *TabSheet4;
        TLabel *Label18;
        TEdit *Edit1;
        TButton *Button4;
        TTabSheet *TabSheet5;
        TLabel *Label14;
        TLabel *Label15;
        TListBox *ListBox2;
        TListBox *ListBox3;
        TButton *Button5;
        TTabSheet *TabSheet6;
        TLabel *Label19;
        TEdit *Edit2;
        TButton *Button6;
        TButton *Button4221;
        TTabSheet *TabSheet7;
        TButton *Button8776;
        TLabel *Label13;
        TEdit *Edit3;
        TLabel *Label16;
        TDateTimePicker *DateTimePicker2;
        TLabel *Label27;
	TButton *Button8;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ListBox1ClickCheck(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
		void __fastcall Button8Click(TObject *Sender);
		void __fastcall Button8Click2(TObject *Sender);
		void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall AtualizaPontos();
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Dicas1Click(TObject *Sender);
        void __fastcall Button4123Click(TObject *Sender);
        void __fastcall Button4221Click(TObject *Sender);
        void __fastcall Button8776Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormDidatica(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDidatica *FormDidatica;
using namespace std;
extern vector<TLabel*> lab;
extern vector<TDateTimePicker*> dat_sor;
extern vector<TDateTimePicker*> hor_sor;
extern vector<TDateTimePicker*> dat_apr;
extern vector<TDateTimePicker*> hor_apr;
extern vector<TCheckBox*> comp_sor;
extern vector<TCheckBox*> comp_apr;
extern vector<TComboBox*> ponto;

//---------------------------------------------------------------------------
#endif
