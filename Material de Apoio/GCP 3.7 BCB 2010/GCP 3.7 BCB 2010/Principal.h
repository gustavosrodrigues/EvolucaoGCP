//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>

#include <vector>
using namespace std;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button3;
		TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn9;
        TBitBtn *BitBtn10;
        TStatusBar *StatusBar1;
        TButton *Button2;
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *Arquivo1;
        TMenuItem *Abrir1;
        TMenuItem *Salvar1;
        TMenuItem *Salvarcomo1;
        TMenuItem *Sair1;
        TMenuItem *Ajuda1;
        TMenuItem *Ajuda2;
        TMenuItem *Sobre1;
        TToolButton *ToolButton1;
        TImageList *ImageList1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton5;
		TMenuItem *Novo1;
        TBitBtn *BitBtn7;
        TMenuItem *Configuraes1;
        TMenuItem *Configuraes2;
        TMenuItem *Cabealho1;
        TToolButton *ToolButton6;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *DiretrioAtual1;
        TMenuItem *Abrir2;
        TScrollBox *ScrollBox1;
        TPanel *Panel3;
        TShape *Shape4;
        TLabel *Label3;
        TCheckBox *CB42;
        TButton *Button13;
        TCheckBox *CB44;
        TButton *Button35;
        TCheckBox *CB46;
        TButton *Button37;
        TCheckBox *CB47;
        TButton *Button39;
        TCheckBox *CB48;
        TButton *Button41;
        TCheckBox *CB49;
        TButton *Button43;
        TCheckBox *CB411;
		TButton *Button45;
        TCheckBox *CB413;
        TButton *Button47;
        TCheckBox *CB414;
        TButton *Button49;
        TCheckBox *CB41;
        TButton *Button69;
        TCheckBox *CB43;
        TButton *Button155;
        TCheckBox *CB45;
        TButton *Button12651;
        TCheckBox *CB410;
        TButton *Button12234;
        TCheckBox *CB412;
        TButton *Button1;
        TPanel *Panel4;
        TShape *Shape5;
        TLabel *Label4;
        TCheckBox *CB52;
        TButton *Button51;
        TCheckBox *CB54;
        TButton *Button53;
        TCheckBox *CB55;
        TButton *Button55;
        TCheckBox *CB57;
        TButton *Button57;
        TCheckBox *CB51;
		TButton *Button71;
        TCheckBox *CB53;
        TButton *Button80;
        TCheckBox *CB56;
        TButton *Button82;
        TPanel *Panel5;
        TShape *Shape6;
        TLabel *Label5;
        TCheckBox *CB62;
        TButton *Button59;
        TCheckBox *CB63;
        TButton *Button61;
        TCheckBox *CB64;
        TButton *Button63;
        TCheckBox *CB61;
        TButton *Button84;
        TPanel *Panel6;
        TShape *Shape3;
        TLabel *Label6;
        TCheckBox *CB31;
        TButton *Button65;
        TCheckBox *CB32;
        TButton *Button67;
        TPanel *Panel2;
        TShape *Shape2;
        TLabel *Label2;
        TCheckBox *CB22;
		TButton *Button15;
        TCheckBox *CB23;
        TButton *Button17;
        TCheckBox *CB25;
        TButton *Button19;
        TCheckBox *CB26;
        TButton *Button21;
        TCheckBox *CB27;
        TButton *Button23;
        TCheckBox *CB28;
        TButton *Button25;
        TCheckBox *CB29;
        TButton *Button27;
        TCheckBox *CB210;
        TButton *Button29;
        TCheckBox *CB213;
        TButton *Button33;
        TCheckBox *CB212;
        TButton *Button31;
        TCheckBox *CB21;
        TButton *Button109;
        TCheckBox *CB24;
        TButton *Button187;
        TCheckBox *CB211;
        TButton *Button176;
        TPanel *Panel1;
        TShape *Shape1;
		TLabel *Label1;
        TCheckBox *CB11;
        TButton *Button1111;
        TCheckBox *CB12;
        TButton *Button5;
        TCheckBox *CB14;
        TButton *Button7;
        TCheckBox *CB16;
        TButton *Button9;
        TCheckBox *CB13;
        TButton *Button11;
        TLabel *Label7;
        TListView *ListView2;
        TLabel *Label8;
        TLabel *Label9;
        TListView *ListView3;
        TLabel *Label10;
        TMenuItem *Janelas1;
        TMenuItem *Provaescrita1;
        TMenuItem *Provadidtica1;
        TMenuItem *Provadettulos1;
        TMenuItem *Provadedefesadememorial1;
        TMenuItem *Sessodeabertura1;
        TMenuItem *Resultado1;
        TMenuItem *N1;
        TMenuItem *Arquivosrecentes1;
		TMenuItem *aa1;
        TMenuItem *aa2;
        TMenuItem *aa3;
        TMenuItem *aa4;
        TTimer *Timer1;
        TLabel *Label11;
	//TCheckBox *CB16;
	//TButton *Button4;
	//TCheckBox *CB214;
	//TButton *Button6;
	TListView *ListView1;
        TCheckBox *CB17;
        TButton *Button4;
        TCheckBox *CB214;
        TButton *Button6;
        TCheckBox *CB415;
        TButton *Button8;
        TCheckBox *CB15;
        TButton *Button10;
	TButton *Button12;
	TCheckBox *CB10;
	TButton *Button14;
	TPanel *Panel7;
	TShape *Shape7;
	TLabel *Label12;
	TCheckBox *CB72;
	TButton *Button16;
	TCheckBox *CB74;
	TButton *Button18;
	TCheckBox *CB75;
	TButton *Button20;
	TCheckBox *CB77;
	TButton *Button22;
	TCheckBox *CB71;
	TButton *Button24;
	TCheckBox *CB73;
	TButton *Button26;
	TCheckBox *CB76;
	TButton *Button28;
	TBitBtn *BitBtn11;
	TButton *Button30;
	TMenuItem *Verificaratualizao1;
	TCheckBox *CB33;
	TButton *Button32;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid1DblClick(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Configuraes2Click(TObject *Sender);
        void __fastcall Cabealho1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        String __fastcall ConverteLiteral(int n, int sexo);    // 1- masc  0 - fem
        String __fastcall RetiraNumero(String s);
		String __fastcall ConverteLiteralFloat(float n, int sexo);
		String __fastcall HoraExtenso (int hora, int minuto, int maiuscula);
		String __fastcall DataExtenso (int dia, int mes, int ano, int maiuscula);
        void __fastcall Listagemdedocumentosagerar1Click(TObject *Sender);
        void __fastcall Ajuda2Click(TObject *Sender);
        //void __fastcall Salvar1Click(TObject *Sender);
        void __fastcall Salvar2Click(TObject *Sender);
        //void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall Abrir(TObject *Sender);
        void __fastcall Novo1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Sair1Click(TObject *Sender);
        void __fastcall Salvar(String nome_arq);
        void __fastcall Salvarcomo1Click(TObject *Sender);
        void __fastcall DiretrioAtual1Click(TObject *Sender);
        void __fastcall Adicionarlinhastabeladedocumentosgerados1Click(
          TObject *Sender);
		void __fastcall Button1111Click(TObject *Sender);
		void __fastcall Button1112Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
		void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button109Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button187Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
		void __fastcall Button27Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button176Click(TObject *Sender);
        void __fastcall Button31Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button65Click(TObject *Sender);
        void __fastcall Button67Click(TObject *Sender);
        void __fastcall Button69Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button155Click(TObject *Sender);
        void __fastcall Button35Click(TObject *Sender);
        void __fastcall Button37Click(TObject *Sender);
        void __fastcall Button12651Click(TObject *Sender);
        void __fastcall Button39Click(TObject *Sender);
        void __fastcall Button41Click(TObject *Sender);
        void __fastcall Button43Click(TObject *Sender);
        void __fastcall Button12234Click(TObject *Sender);
        void __fastcall Button45Click(TObject *Sender);
        void __fastcall Button47Click(TObject *Sender);
        void __fastcall Button49Click(TObject *Sender);
        void __fastcall Button71Click(TObject *Sender);
        void __fastcall Shape2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Button51Click(TObject *Sender);
        void __fastcall Button80Click(TObject *Sender);
        void __fastcall Limpa(TObject *Sender);
		void __fastcall Button53Click(TObject *Sender);
        void __fastcall Button55Click(TObject *Sender);
        void __fastcall Button82Click(TObject *Sender);
        void __fastcall Button57Click(TObject *Sender);
        void __fastcall Button84Click(TObject *Sender);
        void __fastcall Button63Click(TObject *Sender);
        void __fastcall Button59Click(TObject *Sender);
        void __fastcall Button61Click(TObject *Sender);
        void __fastcall Button86Click(TObject *Sender);
        void __fastcall ListView3SelectItem(TObject *Sender,
          TListItem *Item, bool Selected);
        void __fastcall Provaescrita1Click(TObject *Sender);
        void __fastcall Provadidtica1Click(TObject *Sender);
        void __fastcall Provadettulos1Click(TObject *Sender);
        void __fastcall Provadedefesadememorial1Click(TObject *Sender);
        void __fastcall Sessodeabertura1Click(TObject *Sender);
        void __fastcall Resultado1Click(TObject *Sender);
		void __fastcall AbrirGC3(String nome_arq);
		void __fastcall AbrirRegrasGCR(String nome_arq) ;
        void __fastcall AtualizaArquivosRecentes();
        void __fastcall aa1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button28Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall BitBtn11Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall Verificaratualizao1Click(TObject *Sender);
	void __fastcall Button32Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall TForm1::ShowHint(TObject *Sender);

};

extern bool Startup1;
typedef struct {
AnsiString nome;
//String instituicao;
int classe;
//bool presidente;
AnsiString nome_completo;
//bool suplente;
int sexo;       // 0-Masculino, 1-Feminino
} tipo_examinador;

typedef struct {
AnsiString nome;
int sexo;    // 0-Masculino, 1-Feminino
//bool aprovado;
//bool desistente;   // Candidato desistiu durante o concurso
//bool ausente;   // Candidato n�o compareceu no concurso
//bool compareceu_realizacao_prova_escrita;
//bool compareceu_leitura_prova_escrita;
//bool compareceu_sorteio_prova_didatica;
//bool compareceu_realizacao_prova_didatica;
//bool compareceu_realizacao_prova_defesa;
//bool compareceu_realizacao_prova_titulos;
float nota_titulos[100];   // No maximo 100 notas na prova de titulos
float pontuacao_I1;  // esse campo nao precisa ser salvo
float pontuacao_I2;  // esse campo nao precisa ser salvo
float pontuacao_I3;  // esse campo nao precisa ser salvo
TDate nascimento;
} tipo_candidato;

typedef struct {
String texto;
bool valido;
} tipo_ponto;

typedef struct {
AnsiString diretorio;
AnsiString nome;
AnsiString ministerio;
AnsiString universidade;
AnsiString centro;
AnsiString departamento;
AnsiString campus;
AnsiString area;
AnsiString edital;
AnsiString tipo_concurso;   // nao salva, vem do arquivo de regras
AnsiString categoria;
AnsiString normativa;    // nao salva
int classe;
TDate data_inicio;
String arq_regras;
float pesominclasse1; // nao salva
float pesominclasse2; // nao salva
float pesominclasse3; // nao salva
float pesomaxclasse1; // nao salva
float pesomaxclasse2; // nao salva
float pesomaxclasse3; // nao salva
float peso_escrita;   // nao salva
float peso_didatica;   // nao salva
float peso_memorial;   // nao salva
float peso_titulos;     // nao salva
float peso_entrevista;   // nao salva
float peso_escrita_final;   // este � o peso para o c�lculo da m�dia
float peso_didatica_final;   // este � o peso para o c�lculo da m�dia
float peso_memorial_final;   // este � o peso para o c�lculo da m�dia
float peso_titulos_final;    // este � o peso para o c�lculo da m�dia
float peso_entrevista_final;  // este � o peso para o c�lculo da m�dia
bool peso_escrita_fixo;   // nao salva
bool peso_didatica_fixo;   // nao salva
bool peso_memorial_fixo;   // nao salva
bool peso_titulos_fixo;   // nao salva
bool peso_entrevista_fixo;   // nao salva
bool titulos_eliminatoria;  // nao salva
bool escrita_eliminatoria;  // nao salva
bool memorial_eliminatoria;  // nao salva
bool didatica_eliminatoria;  // nao salva
bool entrevista_eliminatoria; // nao salva
bool nota_final_eliminatoria; // nao salva
float nota_minima_escrita;    // nao salva
float nota_minima_didatica;   // nao salva
float nota_minima_memorial;  // nao salva
float nota_minima_titulos;  // nao salva
float nota_minima_entrevista;  // nao salva
float nota_minima_geral;   // nao salva
bool pode_desistir_recurso_escrita;    // nao salva
bool pode_desistir_recurso_didatica;   // nao salva
bool pontuacao_maxima_classe1;
bool pontuacao_maxima_classe2;
bool pontuacao_maxima_classe3;
float valor_pontuacao_maxima_classe1;
float valor_pontuacao_maxima_classe2;
float valor_pontuacao_maxima_classe3;
int ha_prova_escrita;         // nao salva
int ha_prova_didatica;        // nao salva
int ha_prova_memorial;        // nao salva
int ha_prova_titulos;         // nao salva
int ha_prova_entrevista;      // nao salva
bool habilita_prova_escrita;
bool habilita_prova_didatica;
bool habilita_prova_memorial;
bool habilita_prova_titulos;
bool habilita_prova_entrevista;


} tipo_projeto;

extern tipo_projeto projeto;
extern int linha_atual;

extern tipo_examinador examinador[3];
extern vector<tipo_candidato> candidato;
extern vector<tipo_ponto> ponto_escrita;
extern vector<tipo_ponto> ponto_didatica;

//extern vector<float> notas;

// vetores de TEdits das notas
extern TEdit* Edit_pontuacao[53];
extern TEdit* Edit_quantidade[53];
extern TEdit* Edit_total[53];
extern TStaticText* Texto_item[53];

extern int nro_ata;
extern int nro_lista;
extern TDate DataG; // nao precisa salvar

extern vector<TLabel*> lab_def;
extern vector<TDateTimePicker*> dat_def;
extern vector<TDateTimePicker*> hor_def;
extern vector<TCheckBox*> comp_def;

extern vector<TLabel*> lab_ent;
extern vector<TDateTimePicker*> dat_ent;
extern vector<TDateTimePicker*> hor_ent;
extern vector<TCheckBox*> comp_ent;

// VARI�VEIS DE VERS�O DO GCP
extern AnsiString versao;
//extern AnsiString normativa;
extern AnsiString data_compilacao;
extern AnsiString artigo_prazo_recursal_escrita;
extern AnsiString artigo_prazo_recursal_didatica;
extern String arquivo_regras[20]; // Suporta ate 20 arquivos de regras



//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

