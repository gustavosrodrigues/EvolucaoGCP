//---------------------------------------------------------------------------

#ifndef AtasH
#define AtasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAtas : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button1;
        TRichEdit *RichEdit1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TDateTimePicker *DateTimePicker1;
        TTabSheet *TabSheet2;
        TButton *Button2;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TLabel *Label7;
        TTabSheet *TabSheet3;
        TLabel *Label8;
        TButton *Button3;
        TLabel *Label9;
        TButton *Button4;
        TEdit *Edit13;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TLabel *Label13;
        TEdit *Edit18;
        TButton *Button10;
        TEdit *Edit20;
        TTabSheet *TabSheet4;
        TButton *Button11;
        TEdit *Edit21;
        TButton *Button12;
        TEdit *Edit22;
        TEdit *Edit23;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TEdit *Edit25;
        TButton *Button16;
        TEdit *Edit26;
        TTabSheet *TabSheet5;
        TButton *Button17;
        TEdit *Edit27;
        TButton *Button18;
        TEdit *Edit28;
        TButton *Button19;
        TButton *Button20;
        TEdit *Edit30;
        TButton *Button21;
        TEdit *Edit31;
        TTabSheet *TabSheet6;
        TButton *Button22;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit17;
        TTabSheet *TabSheet7;
        TButton *Button23;
        TButton *Button24;
        TButton *Button25;
        TButton *Button26;
        TButton *Button27;
        TButton *Button28;
        TButton *Button29;
        TButton *Button30;
        TButton *Button31;
        TButton *Button32;
        TButton *Button33;
        TButton *Button34;
        TEdit *Edit4;
        TButton *Button35;
        TButton *Button9;
        TButton *Button36;
        TButton *Button37;
	TTabSheet *TabSheet8;
	TButton *Button38;
	TEdit *Edit14;
	TButton *Button39;
	TEdit *Edit15;
	TButton *Button40;
	TButton *Button41;
	TEdit *Edit16;
	TButton *Button42;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall GeraCabecalho(String nome_arq);
        void __fastcall FechaRTF(String nome_arq);
        void __fastcall Assinaturas(String nome_arq, TDate data_ata);
        void __fastcall TabSheet2Show(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Button27Click(TObject *Sender);
        int __fastcall PegaSexo(String nome);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button26Click(TObject *Sender);
        void __fastcall Button30Click(TObject *Sender);
        void __fastcall Button31Click(TObject *Sender);
        void __fastcall Button32Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button34Click(TObject *Sender);
        void __fastcall Button35Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button36Click(TObject *Sender);
        void __fastcall Button37Click(TObject *Sender);
	void __fastcall Button38Click(TObject *Sender);
	void __fastcall Button39Click(TObject *Sender);
	void __fastcall Button40Click(TObject *Sender);
	void __fastcall Button41Click(TObject *Sender);
	void __fastcall Button42Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormAtas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAtas *FormAtas;
//---------------------------------------------------------------------------
#endif
