//---------------------------------------------------------------------------

#ifndef ConfiguracaoH
#define ConfiguracaoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "cdiroutl.h"
#include <Dialogs.hpp>
#include <Grids.hpp>
#include <Outline.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TFormConfiguracao : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *Pag1;
        TGroupBox *GroupBox5;
        TLabel *Label6;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit6;
        TLabeledEdit *LabeledEdit7;
        TLabeledEdit *LabeledEdit8;
        TDateTimePicker *DateTimePicker1;
        TRadioGroup *RadioGroup4;
        TTabSheet *Pag3;
        TGroupBox *GroupBox1;
        TTabSheet *Pag4;
        TGroupBox *GroupBox2;
        TCheckListBox *List_Candidatos;
        TButton *Button6;
        TButton *Button7;
        TButton *Button1;
        TTabSheet *Pag2;
        TButton *Button3;
        TButton *Button8;
        TButton *Button9;
        TGroupBox *GroupBox3;
        TDirectoryListBox *DirectoryListBox1;
        TEdit *Edit4;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TButton *Button16;
        TEdit *Edit5;
        TLabel *Label5;
        TGroupBox *GroupBox4;
        TEdit *Edit1;
        TLabel *Label1;
        TRadioGroup *RadioGroup1;
        TRadioGroup *RadioGroup2;
        TGroupBox *GroupBox6;
        TLabel *Label2;
        TEdit *Edit2;
        TRadioGroup *RadioGroup5;
        TRadioGroup *RadioGroup6;
        TGroupBox *GroupBox7;
        TLabel *Label7;
        TEdit *Edit6;
        TRadioGroup *RadioGroup7;
        TRadioGroup *RadioGroup8;
        TCheckListBox *List_Banca;
        TMemo *Memo1;
        TPanel *Panel1;
        TLabel *Label3;
        TEdit *Edit3;
        TRadioGroup *RadioGroup3;
        TLabel *Label4;
        TDateTimePicker *DateTimePicker2;
        TButton *Button2;
        TButton *Button4;
        TMemo *Memo2;
        TDriveComboBox *DriveComboBox1;
        TLabeledEdit *LabeledEdit3;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TListBox *ListBox1;
	TLabel *Label8;
	TFileListBox *FileListBox1;
	TLabel *Label13;
	TLabel *Label14;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall List_BancaClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall List_CandidatosClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall DirectoryListBox1Change(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Pag2Show(TObject *Sender);
        void __fastcall DirectoryListBox1Click(TObject *Sender);
        void __fastcall HabilitaPanel1(int op);
        void __fastcall Pag4Show(TObject *Sender);
		void __fastcall DriveComboBox1Change(TObject *Sender);

	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFormConfiguracao(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConfiguracao *FormConfiguracao;
//---------------------------------------------------------------------------
#endif