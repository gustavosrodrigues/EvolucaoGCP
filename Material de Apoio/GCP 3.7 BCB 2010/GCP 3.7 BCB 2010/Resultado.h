//---------------------------------------------------------------------------

#ifndef ResultadoH
#define ResultadoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormResultado : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TPageControl *PageControl1;
        TButton *Button1;
        TButton *Button2;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit1;
        TLabel *Label6;
        TTabSheet *TabSheet1;
        TButton *Button6;
        TMainMenu *MainMenu1;
        TMenuItem *Ats1;
        TMenuItem *Planilhas1;
        TMenuItem *Geraratadasessodedivulgaodoresultadodaprovaescrita1;
        TMenuItem *Geraratadasessodedivulgaodoresultadodaprovadidtica1;
        TMenuItem *Geraratadasessodedivulgaodoresultadofinaldoconcurso1;
        TMenuItem *Parecerfinal1;
        TMenuItem *Gerarlistagemdenotasdaprovaescrita1;
        TMenuItem *Gerarlistagemdenotasdaprovadidtica1;
        TMenuItem *Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1;
        TMenuItem *Gerarparecerfinaldabanca1;
        TButton *Button3;
        TMenuItem *Ajuda1;
        TMenuItem *Dicas1;
        TListBox *ListBox1;
        TLabel *Label2;
	TMenuItem *Gerarplanilhademonstrativadasnotasfinaisdetodososcandidatos1;
	TScrollBox *ScrollBox1;
	TStringGrid *StringGrid1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall StringGrid1GetEditText(TObject *Sender, int ACol,
          int ARow, AnsiString &Value);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, const TRect &Rect, TGridDrawState State);

        void __fastcall StringGrid1Exit(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
		  int ARow, bool &CanSelect);
        void __fastcall StringGrid1GetEditMask(TObject *Sender, int
 ACol, int ARow, AnsiString &Value);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1Click(
          TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall Gerarplanilhademonstrativadasnotasfinaisdetodososcandidatos1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TFormResultado(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormResultado *FormResultado;
extern vector<TTabSheet*> pagina;
extern vector<TStringGrid*> tabela;
extern vector<TLabel*> nota_final;
extern vector<float> media_titulos;
extern vector<float> media_escrita;
extern vector<float> media_defesa;
extern vector<float> media_didatica;

//---------------------------------------------------------------------------
#endif