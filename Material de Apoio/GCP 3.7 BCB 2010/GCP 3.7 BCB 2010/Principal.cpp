// ---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include <vector>
using namespace std;

#include "stdio.h"
#include "Principal.h"
#include "Log.h"
#include "Configuracao.h"
#include "Atas.h"
#include "Titulos.h"
#include "Escrita.h"
#include "Didatica.h"
#include "DefesaProjeto.h"
#include "Resultado.h"
#include "SplashScreen.h"
#include "Cabecalho.h"
#include "Abertura.h"
// #include "Listagem.h"
#include "Dicas.h"
#include "DefesaProjeto_candidatos.h"
#include "Didatica_candidatos.h"
#include "Entrevista_candidatos.h"
#include "Entrevista.h"
#include "PegaData.h"
#include "Atualizar.h"
// #include "ListaDocumentos.h"


#include <iostream>
#include  <fstream>
#include <ios>

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

tipo_projeto projeto;
int linha_atual = 1;

tipo_examinador examinador[3];

String arquivo_regras[20]; // Suporta ate 20 arquivos de regras

vector<tipo_candidato>candidato;
vector<tipo_ponto>ponto_escrita;
vector<tipo_ponto>ponto_didatica;

vector<String>arquivos_recentes; // vetor de arquivos recentes
// vector<float> notas;

// Retirado a partir da versao 3.5
// TEdit* Edit_pontuacao[53];    // nao precisa salvar
// TEdit* Edit_quantidade[53];   // nao precisa salvar
// TEdit* Edit_total[53];        // nao precisa salvar
// TStaticText* Texto_item[53];  // nao precisa salvar

String nome_arq_abrir; // arquivo a ser aberto selecionado pelos ListView e StringGrid. Nao precisa ser salvo.
int nro_ata = 1;
int nro_lista = 1;
TDate DataG; // nao precisa salvar
bool Startup1 = true;

// ******** VARIÁVEIS DE VERSÃO DO GCP  -  ESCOPO GLOBAL  ********
AnsiString versao = "3.7";
AnsiString normativa = "Erro"; // incluido arq regras
AnsiString data_compilacao = "23/02/2014";
AnsiString artigo_prazo_recursal_escrita = "Erro"; // incluido arq regras
AnsiString artigo_prazo_recursal_didatica = "Erro"; // incluido arq regras
// ********                                               ********

extern String arquivo_entrada;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	// TCheckBox* a = new TCheckBox(this);
	// StringGrid1->Objects[1][1] = a;
	/*
	// Cabecalho da tabela
	StringGrid1->Cells[0][0] = "ID";
	StringGrid1->Cells[1][0] = "Documento";
	StringGrid1->Cells[2][0] = "Tipo";
	StringGrid1->Cells[3][0] = "Nro";
	StringGrid1->Cells[4][0] = "Arquivo";
	StringGrid1->Cells[5][0] = "Observação";
	StringGrid1->Cells[6][0] = "Impresso?";
	StringGrid1->Cells[7][0] = "Assinado?"; */

	Form1->Position = poScreenCenter;
	ScrollBox1->VertScrollBar->Position = 0;
	// ShellExecute(Handle, "open", "c:\\escrita.rtf", 0, 0, SW_NORMAL);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	FormAtas->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	// FormTitulos->ShowModal();
	SelData->ShowModal();
	FormAtas->Button9Click(FormAbertura);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender) {
	FormEscrita->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	DecimalSeparator = ',';
	// Startup1 = true;
	Application->ShowHint = true;
	// Application->OnHint = ShowHint;
	Button2Click(Form1);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn9Click(TObject *Sender) {
	FormDidatica->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender) {
	FormDefesaProjeto->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender) {
	FormResultado->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender) {
	if (Startup1) {
		// Form1->Visible = true;
		Startup1 = false;
		FormSplash->ShowModal();
		// FormConfiguracao->ShowModal();
		// Application->MessageBox(arquivo_entrada.c_str(), "0", 0);

//        Verifica atualizações
		FormAtualizar->Button5Click(this);

		SelData->MonthCalendar1->Date = Date(); // Data de hoje

		// Le o gcp.ini
		String xx = ChangeFileExt(Application->ExeName, ".INI");
		TIniFile *ini = new TIniFile(xx);
		// Lê os arquivos recentes
		arquivos_recentes.clear();
		String arq1, arq2, arq3, arq4;
		arq1 = ini->ReadString("Recentes", "arq1", "");
		arquivos_recentes.push_back(arq1);
		arq2 = ini->ReadString("Recentes", "arq2", "");
		arquivos_recentes.push_back(arq2);
		arq3 = ini->ReadString("Recentes", "arq3", "");
		arquivos_recentes.push_back(arq3);
		arq4 = ini->ReadString("Recentes", "arq4", "");
		arquivos_recentes.push_back(arq4);
		delete ini;

		AtualizaArquivosRecentes();

		// if (Trim(arquivo_entrada)!="")
		if ((arquivo_entrada) != "")
			AbrirGC3(arquivo_entrada);
	}

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::AtualizaArquivosRecentes() {
	// Insere os ultimos arquivos abertos no menu e grava eles em gcp.ini

	// TMenuItem *NewItem1 = new TMenuItem(MainMenu1); // create the new item
	// TMenuItem *NewItem2 = new TMenuItem(MainMenu1); // create the new item
	// TMenuItem *NewItem3 = new TMenuItem(MainMenu1); // create the new item
	// TMenuItem *NewItem4 = new TMenuItem(MainMenu1); // create the new item
	// NewItem1->Caption = arquivos_recentes[0];
	// NewItem2->Caption = arquivos_recentes[1];
	// NewItem3->Caption = arquivos_recentes[2];
	// NewItem4->Caption = arquivos_recentes[3];
	// MainMenu1->Items->Items[0]->Items[1]->Clear();
	// MainMenu1->Items->Items[0]->Items[1]->Add(NewItem1);// add it to the Popupmenu
	// MainMenu1->Items->Items[0]->Items[1]->Add(NewItem2);// add it to the Popupmenu
	// MainMenu1->Items->Items[0]->Items[1]->Add(NewItem3);// add it to the Popupmenu
	// MainMenu1->Items->Items[0]->Items[1]->Add(NewItem4);// add it to the Popupmenu

	FormLog->Memo1->Lines->Add("Iniciando atualização dos arquivos recentes");
	MainMenu1->Items->Items[0]->Items[1]->Items[0]->Caption = arquivos_recentes
		[0];
	MainMenu1->Items->Items[0]->Items[1]->Items[1]->Caption = arquivos_recentes
		[1];
	MainMenu1->Items->Items[0]->Items[1]->Items[2]->Caption = arquivos_recentes
		[2];
	MainMenu1->Items->Items[0]->Items[1]->Items[3]->Caption = arquivos_recentes
		[3];

	TIniFile *ini = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
	ini->WriteString("Recentes", "arq1", arquivos_recentes[0]);
	ini->WriteString("Recentes", "arq2", arquivos_recentes[1]);
	ini->WriteString("Recentes", "arq3", arquivos_recentes[2]);
	ini->WriteString("Recentes", "arq4", arquivos_recentes[3]);
	delete ini;
	FormLog->Memo1->Lines->Add("Fim da atualização dos arquivos recentes");
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	FormSplash->Timer1->Enabled = false;
	FormSplash->Timer2->Enabled = true;
	FormSplash->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ShowHint(TObject *Sender) {
	// StatusBar1->SimpleText = Application->Hint;
	TPoint p;
	GetCursorPos(&p);
	Application->ActivateHint(p);
}

void __fastcall TForm1::BitBtn2Click(TObject *Sender) {
	FormConfiguracao->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
	int ARow, bool &CanSelect) {

	/* if (ARow>0)
	{
	nome_arq_abrir =  StringGrid1->Cells[4][ARow];
	//String nome_arq = StringGrid1->Cells[3][ARow];
	//ShellExecute(Handle, "open", nome_arq.c_str(), 0, 0, SW_NORMAL);
	if (ACol==6)
	{
	if (StringGrid1->Cells[ACol][ARow] == "Não")
	StringGrid1->Cells[ACol][ARow] == "Sim";
	else
	StringGrid1->Cells[ACol][ARow] == "Não";
	}
	if (ACol==7)
	{
	if (StringGrid1->Cells[ACol][ARow] == "Não")
	StringGrid1->Cells[ACol][ARow] == "Sim";
	else
	StringGrid1->Cells[ACol][ARow] == "Não";
	}
	} */

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DblClick(TObject *Sender) {
	if (Trim(nome_arq_abrir) != "")
		ShellExecute(Handle, "open", AnsiString(nome_arq_abrir).c_str(), 0, 0,
		SW_NORMAL);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
	int ARow, TRect &Rect, TGridDrawState State) {
	/* if (ARow != 0)
	if (ACol == 5)  // CheckBox
	{

	if (StringGrid1->Objects[ACol][ARow] != NULL)
	{

	{
	StringGrid1->Canvas->Brush->Color = StringGrid1->Color;
	//StringGrid1->Canvas->FillRect(Rect);

	TCheckBox(StringGrid1->Objects[ACol][ARow]).Parent = this;
	TCheckBox(StringGrid1->Objects[ACol][ARow]).Top  = Rect.Top ;
	TCheckBox(StringGrid1->Objects[ACol][ARow]).Left = Rect.Left;
	TCheckBox(StringGrid1->Objects[ACol][ARow]).Visible = true;
	}

	}
	} */
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Configuraes2Click(TObject *Sender) {

	FormConfiguracao->PageControl1->ActivePage = FormConfiguracao->Pag1;
	FormConfiguracao->Show();

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Cabealho1Click(TObject *Sender) {
	FormCabecalho->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender) {
	FormAbertura->ShowModal();
}

// ---------------------------------------------------------------------------
String __fastcall TForm1::DataExtenso(int dia, int mes, int ano, int maiuscula)
{
	// Retorna a data por extenso para as atas
	// maiuscula = 1 - primeira letra maiuscula
	// maiuscula = 0 - primeira letra minuscula
	String extenso;
	// FormAtas->ComboBox2->ItemIndex = mes-1;

	String nome_mes = FormAtas->ComboBox2->Items->Strings[mes - 1];
	String primeira_letra;
	if (maiuscula == 1)
		primeira_letra = "A";
	else
		primeira_letra = "a";

	if (dia == 1)
		extenso = primeira_letra + "o " + Form1->ConverteLiteral((int)dia, 3)
			+ " dia do mês de " + AnsiString(nome_mes) + " de " + AnsiString
			(Form1->ConverteLiteral((int)ano, 1));
	else
		extenso = primeira_letra + "os " + Form1->ConverteLiteral((int)dia, 1)
			+ " dias do mês de " + AnsiString(nome_mes) + " de " + AnsiString
			(Form1->ConverteLiteral((int)ano, 1));

	return extenso;
}

String __fastcall TForm1::HoraExtenso(int hora, int minuto, int maiuscula) {
	// Retorna a hora por extenso para as atas
	// maiuscula = 1 - primeira letra maiuscula
	// maiuscula = 0 - primeira letra minuscula

	String extenso;

	String primeira_letra;
	if (maiuscula == 1)
		primeira_letra = "À";
	else
		primeira_letra = "à";

	if (hora == 1 || hora == 0)
		extenso = primeira_letra + " " + AnsiString
			(Form1->ConverteLiteral((int)hora, 0)) + " hora";
	// fprintf(arq, "à %s hora", AnsiString(Form1->ConverteLiteral((int)hora, 0)).c_str());
	else
		extenso = primeira_letra + "s " + AnsiString
			(Form1->ConverteLiteral((int)hora, 0)) + " horas";
	// fprintf(arq, "às %s horas", AnsiString(Form1->ConverteLiteral((int)hora, 0)).c_str());
	if (int(minuto) != 0) {
		if (int(minuto == 1))
			extenso = extenso + " e " + AnsiString
				(Form1->ConverteLiteral((int)minuto, 1)) + " minuto";
		// fprintf(arq, " e %s minuto", AnsiString(Form1->ConverteLiteral((int)minuto, 1)).c_str());
		else
			extenso = extenso + " e " + AnsiString
				(Form1->ConverteLiteral((int)minuto, 1)) + " minutos";
		// fprintf(arq, " e %s minutos", AnsiString(Form1->ConverteLiteral((int)minuto, 1)).c_str());
	}

	return extenso;

}

String __fastcall TForm1::ConverteLiteral(int n, int sexo) {
	// sexo:  0 - feminino, 1 - masculino, 2 - ordinal feminino, 3 - ordinal masculino
	// Obs.: implementado cardinal de 0 a 99, 2008 a 2022 e ordinal de 1
	// Caso não seja um desses valores, retorna o próprio número
	String literal;

	switch(n) {
	case 0:
		literal = "zero";
		break;
	case 1:
		switch(sexo) {
		case 0:
			literal = "uma";
			break;
		case 1:
			literal = "um";
			break;
		case 2:
			literal = "primeira";
			break;
		case 3:
			literal = "primeiro";
			break;
		default:
			literal = "uma";
			break;
		}
		break;
	case 2:
		if (sexo == 1)
			literal = "dois";
		else
			literal = "duas";
		break;
	case 3:
		literal = "três";
		break;
	case 4:
		literal = "quatro";
		break;
	case 5:
		literal = "cinco";
		break;
	case 6:
		literal = "seis";
		break;
	case 7:
		literal = "sete";
		break;
	case 8:
		literal = "oito";
		break;
	case 9:
		literal = "nove";
		break;
	case 10:
		literal = "dez";
		break;
	case 11:
		literal = "onze";
		break;
	case 12:
		literal = "doze";
		break;
	case 13:
		literal = "treze";
		break;
	case 14:
		literal = "quatorze";
		break;
	case 15:
		literal = "quinze";
		break;
	case 16:
		literal = "dezesseis";
		break;
	case 17:
		literal = "dezessete";
		break;
	case 18:
		literal = "dezoito";
		break;
	case 19:
		literal = "dezenove";
		break;
	case 20:
		literal = "vinte";
		break;
	case 21:
		if (sexo == 1)
			literal = "vinte e um";
		else
			literal = "vinte e uma";
		break;
	case 22:
		if (sexo == 1)
			literal = "vinte e dois";
		else
			literal = "vinte e duas";
		break;
	case 23:
		literal = "vinte e três";
		break;
	case 24:
		literal = "vinte e quatro";
		break;
	case 25:
		literal = "vinte e cinco";
		break;
	case 26:
		literal = "vinte e seis";
		break;
	case 27:
		literal = "vinte e sete";
		break;
	case 28:
		literal = "vinte e oito";
		break;
	case 29:
		literal = "vinte e nove";
		break;
	case 30:
		literal = "trinta";
		break;
	case 31:
		if (sexo == 1)
			literal = "trinta e um";
		else
			literal = "trinta e uma";
		break;
	case 32:
		if (sexo == 1)
			literal = "trinta e dois";
		else
			literal = "trinta e duas";
		break;
	case 33:
		literal = "trinta e três";
		break;
	case 34:
		literal = "trinta e quatro";
		break;
	case 35:
		literal = "trinta e cinco";
		break;
	case 36:
		literal = "trinta e seis";
		break;
	case 37:
		literal = "trinta e sete";
		break;
	case 38:
		literal = "trinta e oito";
		break;
	case 39:
		literal = "trinta e nove";
		break;
	case 40:
		literal = "quarenta";
		break;
	case 41:
		if (sexo == 1)
			literal = "quarenta e um";
		else
			literal = "quarenta e uma";
		break;
	case 42:
		if (sexo == 1)
			literal = "quarenta e dois";
		else
			literal = "quarenta e duas";
		break;
	case 43:
		literal = "quarenta e três";
		break;
	case 44:
		literal = "quarenta e quatro";
		break;
	case 45:
		literal = "quarenta e cinco";
		break;
	case 46:
		literal = "quarenta e seis";
		break;
	case 47:
		literal = "quarenta e sete";
		break;
	case 48:
		literal = "quarenta e oito";
		break;
	case 49:
		literal = "quarenta e nove";
		break;
	case 50:
		literal = "cinquenta";
		break;
	case 51:
		if (sexo == 1)
			literal = "cinquenta e um";
		else
			literal = "cinquenta e uma";
		break;
	case 52:
		if (sexo == 1)
			literal = "cinquenta e dois";
		else
			literal = "cinquenta e duas";
		break;
	case 53:
		literal = "cinquenta e três";
		break;
	case 54:
		literal = "cinquenta e quatro";
		break;
	case 55:
		literal = "cinquenta e cinco";
		break;
	case 56:
		literal = "cinquenta e seis";
		break;
	case 57:
		literal = "cinquenta e sete";
		break;
	case 58:
		literal = "cinquenta e oito";
		break;
	case 59:
		literal = "cinquenta e nove";
		break;
	case 60:
		literal = "sessenta";
		break;
	case 61:
		if (sexo == 1)
			literal = "sessenta e um";
		else
			literal = "sessenta e uma";
		break;
	case 62:
		if (sexo == 1)
			literal = "sessenta e dois";
		else
			literal = "sessenta e duas";
		break;
	case 63:
		literal = "sessenta e três";
		break;
	case 64:
		literal = "sessenta e quatro";
		break;
	case 65:
		literal = "sessenta e cinco";
		break;
	case 66:
		literal = "sessenta e seis";
		break;
	case 67:
		literal = "sessenta e sete";
		break;
	case 68:
		literal = "sessenta e oito";
		break;
	case 69:
		literal = "sessenta e nove";
		break;

	case 70:
		literal = "setenta";
		break;
	case 71:
		if (sexo == 1)
			literal = "setenta e um";
		else
			literal = "setenta e uma";
		break;
	case 72:
		if (sexo == 1)
			literal = "setenta e dois";
		else
			literal = "setenta e duas";
		break;
	case 73:
		literal = "setenta e três";
		break;
	case 74:
		literal = "setenta e quatro";
		break;
	case 75:
		literal = "setenta e cinco";
		break;
	case 76:
		literal = "setenta e seis";
		break;
	case 77:
		literal = "setenta e sete";
		break;
	case 78:
		literal = "setenta e oito";
		break;
	case 79:
		literal = "setenta e nove";
		break;
	case 80:
		literal = "oitenta";
		break;
	case 81:
		if (sexo == 1)
			literal = "oitenta e um";
		else
			literal = "oitenta e uma";
		break;
	case 82:
		if (sexo == 1)
			literal = "oitenta e dois";
		else
			literal = "oitenta e duas";
		break;
	case 83:
		literal = "oitenta e três";
		break;
	case 84:
		literal = "oitenta e quatro";
		break;
	case 85:
		literal = "oitenta e cinco";
		break;
	case 86:
		literal = "oitenta e seis";
		break;
	case 87:
		literal = "oitenta e sete";
		break;
	case 88:
		literal = "oitenta e oito";
		break;
	case 89:
		literal = "oitenta e nove";
		break;

	case 90:
		literal = "noventa";
		break;
	case 91:
		if (sexo == 1)
			literal = "noventa e um";
		else
			literal = "noventa e uma";
		break;
	case 92:
		if (sexo == 1)
			literal = "noventa e dois";
		else
			literal = "noventa e duas";
		break;
	case 93:
		literal = "noventa e três";
		break;
	case 94:
		literal = "noventa e quatro";
		break;
	case 95:
		literal = "noventa e cinco";
		break;
	case 96:
		literal = "noventa e seis";
		break;
	case 97:
		literal = "noventa e sete";
		break;
	case 98:
		literal = "noventa e oito";
		break;
	case 99:
		literal = "noventa e nove";
		break;
	case 2008:
		literal = "dois mil e oito";
		break;
	case 2009:
		literal = "dois mil e nove";
		break;
	case 2010:
		literal = "dois mil e dez";
		break;
	case 2011:
		literal = "dois mil e onze";
		break;
	case 2012:
		literal = "dois mil e doze";
		break;
	case 2013:
		literal = "dois mil e treze";
		break;
	case 2014:
		literal = "dois mil e quatorze";
		break;
	case 2015:
		literal = "dois mil e quinze";
		break;
	case 2016:
		literal = "dois mil e dezesseis";
		break;
	case 2017:
		literal = "dois mil e dezessete";
		break;
	case 2018:
		literal = "dois mil e dezoito";
		break;
	case 2019:
		literal = "dois mil e dezenove";
		break;
	case 2020:
		literal = "dois mil e vinte";
		break;
	case 2021:
		literal = "dois mil e vinte e um";
		break;
	case 2022:
		literal = "dois mil e vinte e dois";
		break;
	case 2023:
		literal = "dois mil e vinte e três";
		break;
	case 2024:
		literal = "dois mil e vinte e quatro";
		break;
	case 2025:
		literal = "dois mil e vinte e cinco";
		break;
	case 2026:
		literal = "dois mil e vinte e seis";
		break;

	default:
		literal = IntToStr(n);

	}
	return literal;

}

// ---------------------------------------------------------------------------
String __fastcall TForm1::RetiraNumero(String s) {
	// Dado o texto do ponto, retirar o número inicial
	AnsiString s1 = s;
	int posicao = s1.AnsiPos("- ");
	return s1.SubString(posicao + 2, s1.Length() - 2);
}
// ---------------------------------------------------------------------------

String __fastcall TForm1::ConverteLiteralFloat(float n, int sexo) {
	// sexo = 1 - masc
	// sexo = 0 - fem

	// Separa em parte inteira e parte fracionária
	String nros = FormatFloat("0.00", n);
	int pos_virg = nros.Pos(",");

	String p_inteira = nros.SubString(1, pos_virg - 1);
	String p_frac = nros.SubString(pos_virg + 1, nros.Length() - pos_virg);

	int p_inteira_int = StrToInt(p_inteira);
	int p_inteira_frac = StrToInt(p_frac);

	String literal_p_inteira = ConverteLiteral(p_inteira_int, sexo);
	String literal_p_frac = ConverteLiteral(p_inteira_frac, sexo);

	if (p_inteira_frac < 10 && p_inteira_frac > 0)
		literal_p_frac = "zero " + literal_p_frac;

	String resposta = literal_p_inteira + " vírgula " + literal_p_frac;
	return resposta;
}

void __fastcall TForm1::Listagemdedocumentosagerar1Click(TObject *Sender) {
	// FormListagem->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Ajuda2Click(TObject *Sender) {
	FormDicas->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Salvar2Click(TObject *Sender) {
	FormLog->Memo1->Lines->Add("Iniciando Salvar2Click");
	if (Trim(projeto.nome) != "") {
		// Renomeia o arquivo atual para *.bak
		char szFileName[MAXFILE];

		String nome_arq1 = projeto.nome + ".gc3";
		String nome_arq = ExtractFileName(nome_arq1);
		String aa = GetCurrentDir();

		nome_arq = aa + "\\" + nome_arq;

		if (FileExists(nome_arq)) {
			fnsplit(AnsiString(nome_arq).c_str(), 0, 0, szFileName, 0);
			strcat(szFileName, ".bak");
			// Apaga o arquivo .bak anterior
			DeleteFile(szFileName);
			bool t = RenameFile(nome_arq, szFileName);
		}

		Salvar(nome_arq);
	}
	FormLog->Memo1->Lines->Add("Fim de Salvar2Click");
}

void __fastcall TForm1::Salvar(String nome_arq) {
	// Salva o arquivo - (a partir da versao 3)
	FormLog->Memo1->Lines->Add("Iniciando o método Salvar");
	// Arquivos recentes
	bool encontrou = false;
	int indice_encontrou;
	for (int i = 0; i < 4; i++) {
		if (arquivos_recentes[i] == nome_arq) {
			encontrou = true;
			indice_encontrou = i;
		}
	}
	if (!encontrou) {
		arquivos_recentes.insert(arquivos_recentes.begin(), nome_arq);
		arquivos_recentes.erase(arquivos_recentes.begin() + 4);
	}
	else {
		arquivos_recentes.insert(arquivos_recentes.begin(), nome_arq);
		arquivos_recentes.erase
			(arquivos_recentes.begin() + indice_encontrou + 1);
	}
	AtualizaArquivosRecentes();

	TIniFile *arq;
	arq = new TIniFile(nome_arq);

	// ****************** Principal ****************

	// Versao
	arq->WriteString("Principal", "Versao", versao);

	// CheckBoxes
	arq->WriteBool("Principal", "CB10", CB10->Checked);
	arq->WriteBool("Principal", "CB11", CB11->Checked);
	arq->WriteBool("Principal", "CB12", CB12->Checked);
	arq->WriteBool("Principal", "CB13", CB13->Checked);
	arq->WriteBool("Principal", "CB14", CB14->Checked);
	arq->WriteBool("Principal", "CB15", CB15->Checked);
	arq->WriteBool("Principal", "CB16", CB16->Checked);
	arq->WriteBool("Principal", "CB17", CB17->Checked);

	arq->WriteBool("Principal", "CB21", CB21->Checked);
	arq->WriteBool("Principal", "CB22", CB22->Checked);
	arq->WriteBool("Principal", "CB23", CB23->Checked);
	arq->WriteBool("Principal", "CB24", CB24->Checked);
	arq->WriteBool("Principal", "CB25", CB25->Checked);
	arq->WriteBool("Principal", "CB26", CB26->Checked);
	arq->WriteBool("Principal", "CB27", CB27->Checked);
	arq->WriteBool("Principal", "CB28", CB28->Checked);
	arq->WriteBool("Principal", "CB29", CB29->Checked);
	arq->WriteBool("Principal", "CB210", CB210->Checked);
	arq->WriteBool("Principal", "CB211", CB211->Checked);
	arq->WriteBool("Principal", "CB212", CB212->Checked);
	arq->WriteBool("Principal", "CB213", CB213->Checked);
	arq->WriteBool("Principal", "CB214", CB214->Checked);

	arq->WriteBool("Principal", "CB31", CB31->Checked);
	arq->WriteBool("Principal", "CB32", CB32->Checked);
	arq->WriteBool("Principal", "CB33", CB33->Checked);

	arq->WriteBool("Principal", "CB41", CB41->Checked);
	arq->WriteBool("Principal", "CB42", CB42->Checked);
	arq->WriteBool("Principal", "CB43", CB43->Checked);
	arq->WriteBool("Principal", "CB44", CB44->Checked);
	arq->WriteBool("Principal", "CB45", CB45->Checked);
	arq->WriteBool("Principal", "CB46", CB46->Checked);
	arq->WriteBool("Principal", "CB47", CB47->Checked);
	arq->WriteBool("Principal", "CB48", CB48->Checked);
	arq->WriteBool("Principal", "CB49", CB49->Checked);
	arq->WriteBool("Principal", "CB410", CB410->Checked);
	arq->WriteBool("Principal", "CB411", CB411->Checked);
	arq->WriteBool("Principal", "CB412", CB412->Checked);
	arq->WriteBool("Principal", "CB413", CB413->Checked);
	arq->WriteBool("Principal", "CB414", CB414->Checked);
	arq->WriteBool("Principal", "CB415", CB415->Checked);

	arq->WriteBool("Principal", "CB51", CB51->Checked);
	arq->WriteBool("Principal", "CB52", CB52->Checked);
	arq->WriteBool("Principal", "CB53", CB53->Checked);
	arq->WriteBool("Principal", "CB54", CB54->Checked);
	arq->WriteBool("Principal", "CB55", CB55->Checked);
	arq->WriteBool("Principal", "CB56", CB56->Checked);
	arq->WriteBool("Principal", "CB57", CB57->Checked);

	arq->WriteBool("Principal", "CB61", CB61->Checked);
	arq->WriteBool("Principal", "CB62", CB62->Checked);
	arq->WriteBool("Principal", "CB63", CB63->Checked);
	arq->WriteBool("Principal", "CB64", CB64->Checked);

	arq->WriteBool("Principal", "CB71", CB71->Checked);
	arq->WriteBool("Principal", "CB72", CB72->Checked);
	arq->WriteBool("Principal", "CB73", CB73->Checked);
	arq->WriteBool("Principal", "CB74", CB74->Checked);
	arq->WriteBool("Principal", "CB75", CB75->Checked);
	arq->WriteBool("Principal", "CB76", CB76->Checked);
	arq->WriteBool("Principal", "CB77", CB77->Checked);

	// Panels
	arq->WriteInteger("Principal", "Panel2Top", Panel2->Top);
	arq->WriteBool("Principal", "Panel2Visible", Panel2->Visible);
	arq->WriteInteger("Principal", "Panel6Top", Panel6->Top);
	arq->WriteBool("Principal", "Panel6Visible", Panel6->Visible);
	arq->WriteInteger("Principal", "Panel3Top", Panel3->Top);
	arq->WriteBool("Principal", "Panel3Visible", Panel3->Visible);
	arq->WriteInteger("Principal", "Panel4Top", Panel4->Top);
	arq->WriteBool("Principal", "Panel4Visible", Panel4->Visible);
	arq->WriteInteger("Principal", "Panel7Top", Panel7->Top);
	arq->WriteBool("Principal", "Panel7Visible", Panel7->Visible);
	arq->WriteInteger("Principal", "Panel5Top", Panel5->Top);
	arq->WriteBool("Principal", "Panel5Visible", Panel5->Visible);

	// ScrollBox1
	arq->WriteInteger("Principal", "ScrollBox1Pos",
		ScrollBox1->VertScrollBar->Position);

	// ListView1
	arq->WriteInteger("ListView1", "nro_sec", ListView1->Items->Count);
	for (int i = 0; i < ListView1->Items->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("ListView1", "sec" + in,
			ListView1->Items->Item[i]->Caption);
		arq->WriteInteger("ListView1", "nro_subsec" + in,
			ListView1->Items->Item[i]->SubItems->Count);
		for (int j = 0; j < ListView1->Items->Item[i]->SubItems->Count; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			arq->WriteString("ListView1", subsec,
				ListView1->Items->Item[i]->SubItems->Strings[j]);
		}
	}

	// ListView2
	arq->WriteInteger("ListView2", "nro_sec", ListView2->Items->Count);
	for (int i = 0; i < ListView2->Items->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("ListView2", "sec" + in,
			ListView2->Items->Item[i]->Caption);
		arq->WriteInteger("ListView2", "nro_subsec" + in,
			ListView2->Items->Item[i]->SubItems->Count);
		for (int j = 0; j < ListView2->Items->Item[i]->SubItems->Count; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			arq->WriteString("ListView2", subsec,
				ListView2->Items->Item[i]->SubItems->Strings[j]);
		}
	}

	// ListView3
	arq->WriteInteger("ListView3", "nro_sec", ListView3->Items->Count);
	for (int i = 0; i < ListView3->Items->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("ListView3", "sec" + in,
			ListView3->Items->Item[i]->Caption);
		arq->WriteInteger("ListView3", "nro_subsec" + in,
			ListView3->Items->Item[i]->SubItems->Count);
		for (int j = 0; j < ListView3->Items->Item[i]->SubItems->Count; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			arq->WriteString("ListView3", subsec,
				ListView3->Items->Item[i]->SubItems->Strings[j]);
		}
	}

	// Variavel candidato
	arq->WriteInteger("candidato", "size", candidato.size());
	for (int i = 0; i < candidato.size(); i++) {
		String in = IntToStr(i);

		arq->WriteString("Candidato", "Nome" + in, candidato[i].nome);
		arq->WriteInteger("Candidato", "Sexo" + in, candidato[i].sexo);
		for (int j = 0; j < 100; j++) {
			String jn = IntToStr(j);
			String subsec = "Nota_titulos_" + in + "_" + jn;
			arq->WriteFloat("Candidato", subsec, candidato[i].nota_titulos[j]);
		}
		arq->WriteDate("Candidato", "Nascimento" + in, candidato[i].nascimento);
	}

	// Variavel examinador
	for (int i = 0; i < 3; i++) {
		String in = IntToStr(i);

		arq->WriteString("Examinador", "nome" + in, examinador[i].nome);
		arq->WriteInteger("Examinador", "classe" + in, examinador[i].classe);
		arq->WriteString("Examinador", "nome_completo" + in,
			examinador[i].nome_completo);
		arq->WriteInteger("Examinador", "sexo" + in, examinador[i].sexo);
	}

	// Variavel projeto
	arq->WriteString("Projeto", "diretorio", projeto.diretorio);
	arq->WriteString("Projeto", "nome", projeto.nome);
	arq->WriteString("Projeto", "ministerio", projeto.ministerio);
	arq->WriteString("Projeto", "universidade", projeto.universidade);
	arq->WriteString("Projeto", "centro", projeto.centro);
	arq->WriteString("Projeto", "departamento", projeto.departamento);
	arq->WriteString("Projeto", "campus", projeto.campus);
	arq->WriteString("Projeto", "area", projeto.area);
	arq->WriteString("Projeto", "edital", projeto.edital);
	arq->WriteInteger("Projeto", "classe", projeto.classe);
	arq->WriteDate("Projeto", "data_inicio", projeto.data_inicio);
	arq->WriteString("Projeto", "arq_regras", projeto.arq_regras);
	arq->WriteString("Projeto", "categoria", projeto.categoria);
	arq->WriteFloat("Projeto", "peso_didatica", projeto.peso_didatica_final);
	arq->WriteFloat("Projeto", "peso_titulos", projeto.peso_titulos_final);
	arq->WriteFloat("Projeto", "peso_entrevista", projeto.peso_entrevista_final);
	arq->WriteFloat("Projeto", "peso_escrita", projeto.peso_escrita_final);
	arq->WriteFloat("Projeto", "peso_memorial", projeto.peso_memorial_final);
	arq->WriteBool("Projeto", "habilita_prova_escrita", projeto.habilita_prova_escrita);
	arq->WriteBool("Projeto", "habilita_prova_didatica", projeto.habilita_prova_didatica);
	arq->WriteBool("Projeto", "habilita_prova_memorial", projeto.habilita_prova_memorial);
	arq->WriteBool("Projeto", "habilita_prova_titulos", projeto.habilita_prova_titulos);
	arq->WriteBool("Projeto", "habilita_prova_entrevista", projeto.habilita_prova_entrevista);

	// Variavel ponto_escrita
	arq->WriteInteger("ponto_escrita", "size", ponto_escrita.size());
	for (int i = 0; i < ponto_escrita.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("ponto_escrita", "texto" + in, ponto_escrita[i].texto);
		arq->WriteBool("ponto_escrita", "valido" + in, ponto_escrita[i].valido);
	}

	// Variavel ponto_didatica
	arq->WriteInteger("ponto_didatica", "size", ponto_didatica.size());
	for (int i = 0; i < ponto_didatica.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("ponto_didatica", "texto" + in,
			ponto_didatica[i].texto);
		arq->WriteBool("ponto_didatica", "valido" + in,
			ponto_didatica[i].valido);
	}

	// Variavel nro_ata
	arq->WriteInteger("Principal", "nro_ata", nro_ata);

	// Variavel nro_lista
	arq->WriteInteger("Principal", "nro_lista", nro_lista);

	// Variavel lab_def
	arq->WriteInteger("lab_def", "size", lab_def.size());
	for (int i = 0; i < lab_def.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("lab_def", "caption" + in, lab_def[i]->Caption);
	}

	// Variavel dat_def
	arq->WriteInteger("dat_def", "size", dat_def.size());
	for (int i = 0; i < dat_def.size(); i++) {
		String in = IntToStr(i);
		arq->WriteDate("dat_def", "date" + in, dat_def[i]->Date);
	}

	// Variavel hor_def
	arq->WriteInteger("hor_def", "size", hor_def.size());
	for (int i = 0; i < hor_def.size(); i++) {
		String in = IntToStr(i);
		arq->WriteTime("hor_def", "time" + in, hor_def[i]->Time);
	}

	// Variavel comp_def
	arq->WriteInteger("comp_def", "size", comp_def.size());
	for (int i = 0; i < comp_def.size(); i++) {
		String in = IntToStr(i);
		arq->WriteBool("comp_def", "checked" + in, comp_def[i]->Checked);
	}

	// Variavel lab_ent
	arq->WriteInteger("lab_ent", "size", lab_ent.size());
	for (int i = 0; i < lab_ent.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("lab_ent", "caption" + in, lab_ent[i]->Caption);
	}

	// Variavel dat_ent
	arq->WriteInteger("dat_ent", "size", dat_ent.size());
	for (int i = 0; i < dat_ent.size(); i++) {
		String in = IntToStr(i);
		arq->WriteDate("dat_ent", "date" + in, dat_ent[i]->Date);
	}

	// Variavel hor_ent
	arq->WriteInteger("hor_ent", "size", hor_ent.size());
	for (int i = 0; i < hor_ent.size(); i++) {
		String in = IntToStr(i);
		arq->WriteTime("hor_ent", "time" + in, hor_ent[i]->Time);
	}

	// Variavel comp_ent
	arq->WriteInteger("comp_ent", "size", comp_ent.size());
	for (int i = 0; i < comp_ent.size(); i++) {
		String in = IntToStr(i);
		arq->WriteBool("comp_ent", "checked" + in, comp_ent[i]->Checked);
	}


	// Variavel lab
	arq->WriteInteger("lab", "size", lab.size());
	for (int i = 0; i < lab.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("lab", "caption" + in, lab[i]->Caption);
	}

	// Variavel dat_sor
	arq->WriteInteger("dat_sor", "size", dat_sor.size());
	for (int i = 0; i < dat_sor.size(); i++) {
		String in = IntToStr(i);
		arq->WriteDate("dat_sor", "date" + in, dat_sor[i]->Date);
	}

	// Variavel dat_apr
	arq->WriteInteger("dat_apr", "size", dat_apr.size());
	for (int i = 0; i < dat_apr.size(); i++) {
		String in = IntToStr(i);
		arq->WriteDate("dat_apr", "date" + in, dat_apr[i]->Date);
	}

	// Variavel hor_sor
	arq->WriteInteger("hor_sor", "size", hor_sor.size());
	for (int i = 0; i < hor_sor.size(); i++) {
		String in = IntToStr(i);
		arq->WriteTime("hor_sor", "time" + in, hor_sor[i]->Time);
	}

	// Variavel hor_apr
	arq->WriteInteger("hor_apr", "size", hor_apr.size());
	for (int i = 0; i < hor_apr.size(); i++) {
		String in = IntToStr(i);
		arq->WriteTime("hor_apr", "time" + in, hor_apr[i]->Time);
	}

	// Variavel comp_sor
	arq->WriteInteger("comp_sor", "size", comp_sor.size());
	for (int i = 0; i < comp_sor.size(); i++) {
		String in = IntToStr(i);
		arq->WriteBool("comp_sor", "checked" + in, comp_sor[i]->Checked);
	}

	// Variavel comp_apr
	arq->WriteInteger("comp_apr", "size", comp_apr.size());
	for (int i = 0; i < comp_apr.size(); i++) {
		String in = IntToStr(i);
		arq->WriteBool("comp_apr", "checked" + in, comp_apr[i]->Checked);
	}

	// Variavel ponto
	arq->WriteInteger("ponto", "size", ponto.size());
	for (int i = 0; i < ponto.size(); i++) {
		String in = IntToStr(i);
		arq->WriteInteger("ponto", "itemindex" + in, ponto[i]->ItemIndex);
		arq->WriteInteger("ponto", "size" + in, ponto[i]->Items->Count);
		for (int j = 0; j < ponto[i]->Items->Count; j++) {
			String jn = IntToStr(j);
			arq->WriteString("ponto", "item" + in + "_" + jn,
				ponto[i]->Items->Strings[j]);
		}
	}

	// ****************** Abertura ****************

	// Instalação
	arq->WriteTime("Abertura", "DateTimePicker2",
		FormAbertura->DateTimePicker2->Time);
	arq->WriteString("Abertura", "Edit1", FormAbertura->Edit1->Text);
	arq->WriteString("Abertura", "Edit2", FormAbertura->Edit2->Text);
	arq->WriteString("Abertura", "Edit3", FormAbertura->Edit3->Text);

	// Cronograma
	arq->WriteInteger("Abertura", "StringGrid1Col",
		FormAbertura->StringGrid1->ColCount);
	arq->WriteInteger("Abertura", "StringGrid1Row",
		FormAbertura->StringGrid1->RowCount);
	for (int i = 0; i < FormAbertura->StringGrid1->ColCount; i++) {
		for (int j = 0; j < FormAbertura->StringGrid1->RowCount; j++) {
			arq->WriteString("Abertura",
				"Cell" + IntToStr(i) + "_" + IntToStr(j),
				FormAbertura->StringGrid1->Cells[i][j]);
		}
	}
	// Abertura
	arq->WriteInteger("Abertura", "CheckListBox1_cout",
		FormAbertura->CheckListBox1->Items->Count);
	for (int i = 0; i < FormAbertura->CheckListBox1->Items->Count; i++) {
		arq->WriteString("Abertura", "CheckListBox1_Item" + IntToStr(i),
			FormAbertura->CheckListBox1->Items->Strings[i]);
		arq->WriteBool("Abertura", "CheckListBox1_Checked" + IntToStr(i),
			FormAbertura->CheckListBox1->Checked[i]);
	}
	arq->WriteTime("Abertura", "DateTimePicker4",
		FormAbertura->DateTimePicker4->Time);

	// Pesos
	arq->WriteString("Abertura", "Edit10Text",
		FormAbertura->Edit10->Text);
	arq->WriteBool("Abertura", "Edit10Visible",
		FormAbertura->Edit10->Visible);
	arq->WriteBool("Abertura", "Edit10Enabled",
		FormAbertura->Edit10->Enabled);
	arq->WriteString("Abertura", "Edit11Text",
		FormAbertura->Edit11->Text);
	arq->WriteBool("Abertura", "Edit11Visible",
		FormAbertura->Edit11->Visible);
	arq->WriteBool("Abertura", "Edit11Enabled",
		FormAbertura->Edit11->Enabled);
	arq->WriteString("Abertura", "Edit12Text",
		FormAbertura->Edit12->Text);
	arq->WriteBool("Abertura", "Edit12Visible",
		FormAbertura->Edit12->Visible);
	arq->WriteBool("Abertura", "Edit12Enabled",
		FormAbertura->Edit12->Enabled);
	arq->WriteString("Abertura", "Edit13Text",
		FormAbertura->Edit13->Text);
	arq->WriteBool("Abertura", "Edit13Visible",
		FormAbertura->Edit13->Visible);
	arq->WriteBool("Abertura", "Edit13Enabled",
		FormAbertura->Edit13->Enabled);
	arq->WriteString("Abertura", "Edit14Text",
		FormAbertura->Edit14->Text);
	arq->WriteBool("Abertura", "Edit14Visible",
		FormAbertura->Edit14->Visible);
	arq->WriteBool("Abertura", "Edit14Enabled",
		FormAbertura->Edit14->Enabled);

	// ****************** Configuracao ****************
	// Dados gerais
	arq->WriteString("Configuracao", "LabeledEdit1",
		FormConfiguracao->LabeledEdit1->Text);
	arq->WriteString("Configuracao", "LabeledEdit5",
		FormConfiguracao->LabeledEdit5->Text);
	arq->WriteString("Configuracao", "LabeledEdit6",
		FormConfiguracao->LabeledEdit6->Text);
	arq->WriteString("Configuracao", "LabeledEdit7",
		FormConfiguracao->LabeledEdit7->Text);
	arq->WriteString("Configuracao", "LabeledEdit8",
		FormConfiguracao->LabeledEdit8->Text);
	arq->WriteString("Configuracao", "LabeledEdit2",
		FormConfiguracao->LabeledEdit2->Text);
	arq->WriteString("Configuracao", "LabeledEdit3",
		FormConfiguracao->LabeledEdit3->Text);
	arq->WriteDate("Configuracao", "DateTimePicker1",
		FormConfiguracao->DateTimePicker1->Date);
	arq->WriteInteger("Configuracao", "RadioGroup4",
		FormConfiguracao->RadioGroup4->ItemIndex);

	// Diretório
	arq->WriteString("Configuracao", "DirectoryListBox1",
		FormConfiguracao->DirectoryListBox1->Directory);
	arq->WriteString("Configuracao", "Edit4", FormConfiguracao->Edit4->Text);
	arq->WriteString("Configuracao", "Edit5", FormConfiguracao->Edit5->Text);

	// Banca
	arq->WriteString("Configuracao", "Edit1", FormConfiguracao->Edit1->Text);
	arq->WriteString("Configuracao", "Edit2", FormConfiguracao->Edit2->Text);
	arq->WriteString("Configuracao", "Edit6", FormConfiguracao->Edit6->Text);
	arq->WriteString("Configuracao", "Edit7", FormConfiguracao->Edit7->Text);
	arq->WriteString("Configuracao", "Edit8", FormConfiguracao->Edit8->Text);
	arq->WriteString("Configuracao", "Edit9", FormConfiguracao->Edit9->Text);

	arq->WriteInteger("Configuracao", "RadioGroup2",
		FormConfiguracao->RadioGroup2->ItemIndex);
	arq->WriteInteger("Configuracao", "RadioGroup6",
		FormConfiguracao->RadioGroup6->ItemIndex);
	arq->WriteInteger("Configuracao", "RadioGroup8",
		FormConfiguracao->RadioGroup8->ItemIndex);
	arq->WriteInteger("Configuracao", "RadioGroup1",
		FormConfiguracao->RadioGroup1->ItemIndex);
	arq->WriteInteger("Configuracao", "RadioGroup5",
		FormConfiguracao->RadioGroup5->ItemIndex);
	arq->WriteInteger("Configuracao", "RadioGroup7",
		FormConfiguracao->RadioGroup7->ItemIndex);

	// Candidatos inscritos
	arq->WriteInteger("Configuracao", "List_Candidatos_cout",
		FormConfiguracao->List_Candidatos->Items->Count);
	for (int i = 0; i < FormConfiguracao->List_Candidatos->Items->Count; i++) {
		arq->WriteString("Configuracao", "List_Candidatos_Item" + IntToStr(i),
			FormConfiguracao->List_Candidatos->Items->Strings[i]);
		arq->WriteBool("Configuracao", "List_Candidatos_Checked" + IntToStr(i),
			FormConfiguracao->List_Candidatos->Checked[i]);
	}

	// ****************** Escrita ****************
	// Realizaçao
	arq->WriteInteger("Escrita", "CSpinEdit1", FormEscrita->CSpinEdit1->Value);
	arq->WriteTime("Escrita", "DateTimePicker1",
		FormEscrita->DateTimePicker1->Time);
	arq->WriteTime("Escrita", "DateTimePicker6",
		FormEscrita->DateTimePicker6->Time);
	arq->WriteTime("Escrita", "DateTimePicker2",
		FormEscrita->DateTimePicker2->Time);
	arq->WriteString("Escrita", "Edit2", FormEscrita->Edit2->Text);

	// Leitura
	arq->WriteInteger("Escrita", "CheckListBox2_cout",
		FormEscrita->CheckListBox2->Items->Count);
	for (int i = 0; i < FormEscrita->CheckListBox2->Items->Count; i++) {
		arq->WriteString("Escrita", "CheckListBox2_Item" + IntToStr(i),
			FormEscrita->CheckListBox2->Items->Strings[i]);
		arq->WriteBool("Escrita", "CheckListBox2_Checked" + IntToStr(i),
			FormEscrita->CheckListBox2->Checked[i]);
	}
	arq->WriteTime("Escrita", "DateTimePicker5",
		FormEscrita->DateTimePicker5->Time);
	arq->WriteString("Escrita", "Edit1", FormEscrita->Edit1->Text);

	// Criterios
	// arq->WriteInteger("Escrita", "ValueListEditor1_Rows", FormEscrita->ValueListEditor1->RowCount);
	// for (int i=0; i<FormEscrita->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormEscrita->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	///               String in = IntToStr(i);
	// String jn = IntToStr(j);
	// arq->WriteString("Escrita","Cells"+jn+"_"+in, FormEscrita->ValueListEditor1->Cells[j][i]);
	// }
	// }
	arq->WriteInteger("Escrita", "ValueListEditor1_count",
		FormEscrita->ValueListEditor1->Strings->Count);
	for (int i = 0; i < FormEscrita->ValueListEditor1->Strings->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("Escrita", "String" + in,
			FormEscrita->ValueListEditor1->Strings->Strings[i]);
	}

	// Julgamento
	arq->WriteTime("Escrita", "DateTimePicker8",
		FormEscrita->DateTimePicker8->Time);
	arq->WriteString("Escrita", "Edit3", FormEscrita->Edit3->Text);

	// Configuracao
	arq->WriteInteger("Escrita", "CheckListBox1_cout",
		FormEscrita->CheckListBox1->Items->Count);
	for (int i = 0; i < FormEscrita->CheckListBox1->Items->Count; i++) {
		arq->WriteString("Escrita", "CheckListBox1_Item" + IntToStr(i),
			FormEscrita->CheckListBox1->Items->Strings[i]);
		arq->WriteBool("Escrita", "CheckListBox1_Checked" + IntToStr(i),
			FormEscrita->CheckListBox1->Checked[i]);
	}
	arq->WriteInteger("Escrita", "ListBox4_cout",
		FormEscrita->ListBox4->Items->Count);
	for (int i = 0; i < FormEscrita->ListBox4->Items->Count; i++) {
		arq->WriteString("Escrita", "ListBox4_Item" + IntToStr(i),
			FormEscrita->ListBox4->Items->Strings[i]);
	}

	// Pontos
	arq->WriteInteger("Escrita", "ListBox1_cout",
		FormEscrita->ListBox1->Items->Count);
	for (int i = 0; i < FormEscrita->ListBox1->Items->Count; i++) {
		arq->WriteString("Escrita", "ListBox1_Item" + IntToStr(i),
			FormEscrita->ListBox1->Items->Strings[i]);
	}

	// Planilhas
	arq->WriteInteger("Escrita", "ListBox2_cout",
		FormEscrita->ListBox2->Items->Count);
	for (int i = 0; i < FormEscrita->ListBox2->Items->Count; i++) {
		arq->WriteString("Escrita", "ListBox2_Item" + IntToStr(i),
			FormEscrita->ListBox2->Items->Strings[i]);
	}
	arq->WriteInteger("Escrita", "ListBox3_cout",
		FormEscrita->ListBox3->Items->Count);
	for (int i = 0; i < FormEscrita->ListBox3->Items->Count; i++) {
		arq->WriteString("Escrita", "ListBox3_Item" + IntToStr(i),
			FormEscrita->ListBox3->Items->Strings[i]);
	}

	// Resultado
	arq->WriteTime("Escrita", "DateTimePicker9",
		FormEscrita->DateTimePicker9->Time);
	arq->WriteString("Escrita", "Edit5", FormEscrita->Edit5->Text);

	// ****************** Didatica ****************

	// Candidatos - nada a salvar

	// Pontos
	arq->WriteInteger("Didatica", "ListBox1_cout",
		FormDidatica->ListBox1->Items->Count);
	for (int i = 0; i < FormDidatica->ListBox1->Items->Count; i++) {
		arq->WriteString("Didatica", "ListBox1_Item" + IntToStr(i),
			FormDidatica->ListBox1->Items->Strings[i]);
	}

	// Criterios
	// arq->WriteInteger("Didatica", "ValueListEditor1_Rows", FormDidatica->ValueListEditor1->RowCount);
	// for (int i=0; i<FormDidatica->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDidatica->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// arq->WriteString("Didatica","Cells"+jn+"_"+in, FormDidatica->ValueListEditor1->Cells[j][i]);
	// }
	// }
	arq->WriteInteger("Didatica", "ValueListEditor1_count",
		FormDidatica->ValueListEditor1->Strings->Count);
	for (int i = 0; i < FormDidatica->ValueListEditor1->Strings->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("Didatica", "String" + in,
			FormDidatica->ValueListEditor1->Strings->Strings[i]);
	}

	// Ata sorteio
	arq->WriteString("Didatica", "Edit1", FormDidatica->Edit1->Text);

	// Planilhas
	arq->WriteInteger("Didatica", "ListBox2_cout",
		FormDidatica->ListBox2->Items->Count);
	for (int i = 0; i < FormDidatica->ListBox2->Items->Count; i++) {
		arq->WriteString("Didatica", "ListBox2_Item" + IntToStr(i),
			FormDidatica->ListBox2->Items->Strings[i]);
	}
	arq->WriteInteger("Didatica", "ListBox3_cout",
		FormDidatica->ListBox3->Items->Count);
	for (int i = 0; i < FormDidatica->ListBox3->Items->Count; i++) {
		arq->WriteString("Didatica", "ListBox3_Item" + IntToStr(i),
			FormDidatica->ListBox3->Items->Strings[i]);
	}

	// Ata realizacao
	arq->WriteString("Didatica", "Edit2", FormDidatica->Edit2->Text);

	// Ata resultado
	arq->WriteString("Didatica", "Edit3", FormDidatica->Edit3->Text);
	arq->WriteTime("Didatica", "DateTimePicker2",
		FormDidatica->DateTimePicker2->Time);

	// ****************** Titulos ****************
	arq->WriteInteger("Titulos", "ComboBox1_cout",
		FormTitulos->ComboBox1->Items->Count);
	for (int i = 0; i < FormTitulos->ComboBox1->Items->Count; i++) {
		arq->WriteString("Titulos", "ComboBox1_Item" + IntToStr(i),
			FormTitulos->ComboBox1->Items->Strings[i]);
	}
	arq->WriteInteger("Titulos", "ComboBox2_cout",
		FormTitulos->ComboBox2->Items->Count);
	for (int i = 0; i < FormTitulos->ComboBox2->Items->Count; i++) {
		arq->WriteString("Titulos", "ComboBox2_Item" + IntToStr(i),
			FormTitulos->ComboBox2->Items->Strings[i]);
	}
	arq->WriteString("Titulos", "Edit2", FormTitulos->Edit2->Text);
	arq->WriteString("Titulos", "Edit3", FormTitulos->Edit3->Text);
	arq->WriteString("Titulos", "Edit4", FormTitulos->Edit4->Text);
	arq->WriteString("Titulos", "Edit8", FormTitulos->Edit8->Text);
	arq->WriteString("Titulos", "Edit9", FormTitulos->Edit9->Text);
	arq->WriteString("Titulos", "Edit10", FormTitulos->Edit10->Text);
	arq->WriteString("Titulos", "Edit1", FormTitulos->Edit1->Text);
	arq->WriteTime("Titulos", "DateTimePicker2",
		FormTitulos->DateTimePicker2->Time);

	// ****************** Memorial ****************

	// Planilhas
	arq->WriteInteger("Memorial", "ListBox2_cout",
		FormDefesaProjeto->ListBox2->Items->Count);
	for (int i = 0; i < FormDefesaProjeto->ListBox2->Items->Count; i++) {
		arq->WriteString("Memorial", "ListBox2_Item" + IntToStr(i),
			FormDefesaProjeto->ListBox2->Items->Strings[i]);
	}
	arq->WriteInteger("Memorial", "ListBox3_cout",
		FormDefesaProjeto->ListBox3->Items->Count);
	for (int i = 0; i < FormDefesaProjeto->ListBox3->Items->Count; i++) {
		arq->WriteString("Memorial", "ListBox3_Item" + IntToStr(i),
			FormDefesaProjeto->ListBox3->Items->Strings[i]);
	}

	// Realizacao - nada a salvar

	// Criterios
	// arq->WriteInteger("Memorial", "ValueListEditor1_Rows", FormDefesaProjeto->ValueListEditor1->RowCount);
	// for (int i=0; i<FormDefesaProjeto->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDefesaProjeto->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// arq->WriteString("Memorial","Cells"+jn+"_"+in, FormDefesaProjeto->ValueListEditor1->Cells[j][i]);
	// }
	// }
	// arq->WriteString("Memorial", "ValueListEditor1", FormDefesaProjeto->ValueListEditor1->Strings->CommaText);
	arq->WriteInteger("Memorial", "ValueListEditor1_count",
		FormDefesaProjeto->ValueListEditor1->Strings->Count);
	for (int i = 0; i < FormDefesaProjeto->ValueListEditor1->Strings->Count;
		i++) {
		String in = IntToStr(i);
		arq->WriteString("Memorial", "String" + in,
			FormDefesaProjeto->ValueListEditor1->Strings->Strings[i]);
	}

	// Ata
	arq->WriteString("Memorial", "Edit1", FormDefesaProjeto->Edit1->Text);


	// ****************** Entrevista ****************

	// Planilhas
	arq->WriteInteger("Entrevista", "ListBox2_cout",
		FormEntrevista->ListBox2->Items->Count);
	for (int i = 0; i < FormEntrevista->ListBox2->Items->Count; i++) {
		arq->WriteString("Entrevista", "ListBox2_Item" + IntToStr(i),
			FormEntrevista->ListBox2->Items->Strings[i]);
	}
	arq->WriteInteger("Entrevista", "ListBox3_cout",
		FormEntrevista->ListBox3->Items->Count);
	for (int i = 0; i < FormEntrevista->ListBox3->Items->Count; i++) {
		arq->WriteString("Entrevista", "ListBox3_Item" + IntToStr(i),
			FormEntrevista->ListBox3->Items->Strings[i]);
	}

	// Realizacao - nada a salvar

	// Criterios
	// arq->WriteInteger("Memorial", "ValueListEditor1_Rows", FormDefesaProjeto->ValueListEditor1->RowCount);
	// for (int i=0; i<FormDefesaProjeto->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDefesaProjeto->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// arq->WriteString("Memorial","Cells"+jn+"_"+in, FormDefesaProjeto->ValueListEditor1->Cells[j][i]);
	// }
	// }
	// arq->WriteString("Memorial", "ValueListEditor1", FormDefesaProjeto->ValueListEditor1->Strings->CommaText);
	arq->WriteInteger("Entrevista", "ValueListEditor1_count",
		FormEntrevista->ValueListEditor1->Strings->Count);
	for (int i = 0; i < FormEntrevista->ValueListEditor1->Strings->Count;
		i++) {
		String in = IntToStr(i);
		arq->WriteString("Entrevista", "String" + in,
			FormEntrevista->ValueListEditor1->Strings->Strings[i]);
	}

	// Ata
	arq->WriteString("Entrevista", "Edit1", FormEntrevista->Edit1->Text);

	// ****************** Resultado ****************

	arq->WriteString("Resultado", "Edit1", FormResultado->Edit1->Text);
	arq->WriteTime("Resultado", "DateTimePicker2",
		FormResultado->DateTimePicker2->Time);

	arq->WriteInteger("Resultado", "tabela_size", tabela.size());
	for (int i = 0; i < tabela.size(); i++) {
		String in = IntToStr(i);
		arq->WriteInteger("Resultado", "Rowcount" + in, tabela[i]->RowCount);
		arq->WriteInteger("Resultado", "Colcount" + in, tabela[i]->ColCount);
		for (int col = 0; col < tabela[i]->ColCount; col++)
			for (int row = 0; row < tabela[i]->RowCount; row++)
				arq->WriteString("Resultado",
				"Cell" + in + "_" + IntToStr(col) + "_" + IntToStr(row),
				tabela[i]->Cells[col][row]);
	}
	arq->WriteInteger("Resultado", "nota_final_size", nota_final.size());
	for (int i = 0; i < nota_final.size(); i++) {
		String in = IntToStr(i);
		arq->WriteString("Resultao", "nota_final" + in, nota_final[i]->Caption);
	}

	// ****************** DefesaProjetoCandidatos ****************
	arq->WriteInteger("Memorial_candidatos", "ListBox1_cout",
		FormDefesaProjeto_candidatos->ListBox1->Items->Count);
	for (int i = 0; i < FormDefesaProjeto_candidatos->ListBox1->Items->Count;
		i++) {
		arq->WriteString("Memorial_candidatos", "ListBox1_Item" + IntToStr(i),
			FormDefesaProjeto_candidatos->ListBox1->Items->Strings[i]);
	}
	arq->WriteInteger("Memorial_candidatos", "ListBox2_cout",
		FormDefesaProjeto_candidatos->ListBox2->Items->Count);
	for (int i = 0; i < FormDefesaProjeto_candidatos->ListBox2->Items->Count;
		i++) {
		arq->WriteString("Memorial_candidatos", "ListBox2_Item" + IntToStr(i),
			FormDefesaProjeto_candidatos->ListBox2->Items->Strings[i]);
	}

	// ****************** EntrevistaCandidatos ****************
	arq->WriteInteger("Entrevista_candidatos", "ListBox1_cout",
		FormEntrevista_candidatos->ListBox1->Items->Count);
	for (int i = 0; i < FormEntrevista_candidatos->ListBox1->Items->Count;
		i++) {
		arq->WriteString("Entrevista_candidatos", "ListBox1_Item" + IntToStr(i),
			FormEntrevista_candidatos->ListBox1->Items->Strings[i]);
	}
	arq->WriteInteger("Entrevista_candidatos", "ListBox2_cout",
		FormEntrevista_candidatos->ListBox2->Items->Count);
	for (int i = 0; i < FormEntrevista_candidatos->ListBox2->Items->Count;
		i++) {
		arq->WriteString("Entrevista_candidatos", "ListBox2_Item" + IntToStr(i),
			FormEntrevista_candidatos->ListBox2->Items->Strings[i]);
	}

	// ****************** DidaticaCandidatos ****************
	arq->WriteInteger("Didatica_candidatos", "ListBox1_cout",
		FormDidaticaCandidatos->ListBox1->Items->Count);
	for (int i = 0; i < FormDidaticaCandidatos->ListBox1->Items->Count; i++) {
		arq->WriteString("Didatica_candidatos", "ListBox1_Item" + IntToStr(i),
			FormDidaticaCandidatos->ListBox1->Items->Strings[i]);
	}
	arq->WriteInteger("Didatica_candidatos", "ListBox2_cout",
		FormDidaticaCandidatos->ListBox2->Items->Count);
	for (int i = 0; i < FormDidaticaCandidatos->ListBox2->Items->Count; i++) {
		arq->WriteString("Didatica_candidatos", "ListBox2_Item" + IntToStr(i),
			FormDidaticaCandidatos->ListBox2->Items->Strings[i]);
	}

	// ****************** Cabecalho ****************

	// arq->WriteString("Cabecalho", "RichEdit1", FormCabecalho->RichEdit1->Lines->CommaText);
	arq->WriteInteger("Cabecalho", "count",
		FormCabecalho->RichEdit1->Lines->Count);
	for (int i = 0; i < FormCabecalho->RichEdit1->Lines->Count; i++) {
		String in = IntToStr(i);
		arq->WriteString("Cabecalho", "String" + in,
			FormCabecalho->RichEdit1->Lines->Strings[i]);
	}
	delete arq;

	String mess = "Arquivo " + nome_arq + " salvo com sucesso.";
	Application->MessageBox(mess.c_str(), L"Aviso", 0);

	FormLog->Memo1->Lines->Add("Fim do método Salvar");

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Abrir(TObject *Sender) {

	FormLog->Memo1->Lines->Add("Iniciando o método Abrir.");
	// Abre o projeto selecionado - a partir da versáo 3.0
	String dir_anterior = GetCurrentDir();
	if (OpenDialog1->Execute()) {

		String nome_arq = OpenDialog1->FileName;
		SetCurrentDir(dir_anterior);
		AbrirGC3(nome_arq);

	}
	FormLog->Memo1->Lines->Add("Fim do método Abrir.");
}

void __fastcall TForm1::AbrirRegrasGCR(String nome_arq) {

	FormLog->Memo1->Lines->Add("Iniciando Método AbrirRegrasGCR.");

	TIniFile *iniregras = new TIniFile(nome_arq);

	// Le informacoes gerais
	projeto.normativa = iniregras->ReadString("Principal", "normativa", "Erro");
	Label10->Caption = "Fluxo do concurso - de acordo com " + projeto.normativa;
	projeto.tipo_concurso = iniregras->ReadString("Principal", "tipo_concurso", "Concurso Público");
	FormTitulos->Label40->Caption = "Pontuação de acordo com " + projeto.normativa;

	projeto.ha_prova_didatica = iniregras->ReadInteger("Principal", "ha_prova_didatica", 1);
	projeto.ha_prova_escrita = iniregras->ReadInteger("Principal", "ha_prova_escrita", 1);
	projeto.ha_prova_memorial = iniregras->ReadInteger("Principal", "ha_prova_memorial", 1);
	projeto.ha_prova_titulos = iniregras->ReadInteger("Principal", "ha_prova_titulos", 1);
	projeto.ha_prova_entrevista = iniregras->ReadInteger("Principal", "ha_prova_entrevista", 0);

	projeto.peso_escrita_fixo = iniregras->ReadBool("Principal",
		"peso_escrita_fixo", false);
	projeto.peso_didatica_fixo = iniregras->ReadBool("Principal",
		"peso_didatica_fixo", false);
	projeto.peso_memorial_fixo = iniregras->ReadBool("Principal",
		"peso_memorial_fixo", false);
	projeto.peso_titulos_fixo = iniregras->ReadBool("Principal",
		"peso_titulos_fixo", false);
	projeto.peso_entrevista_fixo = iniregras->ReadBool("Principal",
		"peso_entrevista_fixo", false);
	projeto.peso_didatica = iniregras->ReadFloat("Principal", "peso_didatica",
		0);
	projeto.peso_escrita = iniregras->ReadFloat("Principal", "peso_escrita", 0);
	projeto.peso_memorial = iniregras->ReadFloat("Principal", "peso_memorial",
		0);
	projeto.peso_titulos = iniregras->ReadFloat("Principal", "peso_titulos", 0);
	projeto.peso_entrevista = iniregras->ReadFloat("Principal", "peso_entrevista", 0);
	projeto.nota_final_eliminatoria = iniregras->ReadBool("Principal",
		"eliminatoria", false);
	projeto.nota_minima_geral = iniregras->ReadFloat("Principal",
		"nota_minima", 0);




	// Le informacoes prova didatica
	projeto.didatica_eliminatoria = iniregras->ReadBool("Didatica",
		"eliminatoria", false);
	projeto.nota_minima_didatica = iniregras->ReadFloat("Didatica",
		"nota_minima", 0);
	CB412->Enabled = projeto.didatica_eliminatoria;
	CB413->Enabled = projeto.didatica_eliminatoria;
	CB414->Enabled = projeto.didatica_eliminatoria;
	Button1->Enabled = projeto.didatica_eliminatoria;
	Button47->Enabled = projeto.didatica_eliminatoria;
	Button49->Enabled = projeto.didatica_eliminatoria;
	projeto.pode_desistir_recurso_didatica = iniregras->ReadBool("Didatica",
		"pode_desistir_recurso", 1);
	if (projeto.didatica_eliminatoria &&
		projeto.pode_desistir_recurso_didatica) {
		Button8->Enabled = true;
		CB415->Enabled = true;
	}
	else {
		Button8->Enabled = false;
		CB415->Enabled = false;
	}
	artigo_prazo_recursal_didatica = iniregras->ReadString("Didatica",
		"artigo_prazo_recursal", "Erro");
	FormDidatica->ValueListEditor1->Strings->Clear();
	int c = iniregras->ReadInteger("Didatica", "nro_criterios_avaliacao", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i+1);
		FormDidatica->ValueListEditor1->Strings->Add(iniregras->ReadString("Didatica",
				"criterio_didatica_" + in, "Erro"));
	}

	// Le informacoes prova escrita
	projeto.escrita_eliminatoria = iniregras->ReadBool("Escrita",
		"eliminatoria", false);
	projeto.nota_minima_escrita = iniregras->ReadFloat("Escrita",
		"nota_minima", 0);
	CB211->Enabled = projeto.escrita_eliminatoria;
	CB212->Enabled = projeto.escrita_eliminatoria;
	CB213->Enabled = projeto.escrita_eliminatoria;
	// CB214->Enabled = projeto.escrita_eliminatoria;
	Button176->Enabled = projeto.escrita_eliminatoria;
	Button31->Enabled = projeto.escrita_eliminatoria;
	Button33->Enabled = projeto.escrita_eliminatoria;
	// Button6->Enabled = projeto.escrita_eliminatoria;

	projeto.pode_desistir_recurso_escrita = iniregras->ReadBool("Escrita",
		"pode_desistir_recurso", 1);
	if (projeto.escrita_eliminatoria && projeto.pode_desistir_recurso_escrita) {
		Button6->Enabled = true;
		CB214->Enabled = true;
	}
	else {
		Button6->Enabled = false;
		CB214->Enabled = false;
	}
	artigo_prazo_recursal_escrita = iniregras->ReadString("Escrita",
		"artigo_prazo_recursal", "Erro");

    FormEscrita->ValueListEditor1->Strings->Clear();
	c = iniregras->ReadInteger("Escrita", "nro_criterios_avaliacao", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i+1);
		FormEscrita->ValueListEditor1->Strings->Add(iniregras->ReadString("Escrita",
				"criterio_escrita_" + in, "Erro"));
	}


	// Le informacoes prova memorial
	projeto.memorial_eliminatoria = iniregras->ReadBool("Memorial",
		"eliminatoria", false);
	projeto.nota_minima_memorial = iniregras->ReadFloat("Memorial",
		"nota_minima", 0);
	FormDefesaProjeto->ValueListEditor1->Strings->Clear();
	c = iniregras->ReadInteger("Memorial", "nro_criterios_avaliacao", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i+1);
		FormDefesaProjeto->ValueListEditor1->Strings->Add(iniregras->ReadString("Memorial",
				"criterio_memorial_" + in, "Erro"));
	}

	// Le informacoes prova entrevista
	projeto.entrevista_eliminatoria = iniregras->ReadBool("Entrevista",
		"eliminatoria", false);
	projeto.nota_minima_entrevista = iniregras->ReadFloat("Entrevista",
		"nota_minima", 0);
	FormEntrevista->ValueListEditor1->Strings->Clear();
	c = iniregras->ReadInteger("Entrevista", "nro_criterios_avaliacao", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i+1);
		FormEntrevista->ValueListEditor1->Strings->Add(iniregras->ReadString("Entrevista",
				"criterio_entrevista_" + in, "Erro"));
	}

	// Le itens da prova de titulos
	projeto.titulos_eliminatoria = iniregras->ReadBool("Titulos",
		"eliminatoria", false);
	projeto.nota_minima_titulos = iniregras->ReadFloat("Titulos",
		"nota_minima", 0);

	int nro_items1 = iniregras->ReadInteger("Classe1", "nro_items", 0);
	int nro_items2 = iniregras->ReadInteger("Classe2", "nro_items", 0);
	int nro_items3 = iniregras->ReadInteger("Classe3", "nro_items", 0);

	int a1 = 300+(nro_items1+1)*FormTitulos->TabelaClasse1->DefaultRowHeight;
	int a2 = 300+(nro_items2+1)*FormTitulos->TabelaClasse2->DefaultRowHeight;
	int a3 = 300+(nro_items3+1)*FormTitulos->TabelaClasse3->DefaultRowHeight;
	int a_maior;
	if (a1>a2) {
		  a_maior=a1;
	}
	else
		  a_maior=a2;
	if (a3> a_maior) {
		  a_maior=a3;
	}
	FormTitulos->PageControl1->Height = a_maior;

	FormTitulos->TabelaClasse1->Tag = 0;
	FormTitulos->TabelaClasse2->Tag = nro_items1;
	FormTitulos->TabelaClasse3->Tag = nro_items1 + nro_items2;
	FormTitulos->TabelaClasse1->RowCount = nro_items1 + 1;
	FormTitulos->TabelaClasse2->RowCount = nro_items2 + 1;
	FormTitulos->TabelaClasse3->RowCount = nro_items3 + 1;


	// Classe 1
	projeto.pesominclasse1 = iniregras->ReadFloat("Classe1", "Pesomin", 0);
	projeto.pesomaxclasse1 = iniregras->ReadFloat("Classe1", "Pesomax", 0);
	projeto.pontuacao_maxima_classe1 = iniregras->ReadBool("Classe1", "Pontuacao_maxima", 0);
	projeto.valor_pontuacao_maxima_classe1 = iniregras->ReadFloat("Classe1", "Valor_pontuacao_maxima", 0);
	FormTitulos->Edit2->Text = FormatFloat("0.00", projeto.pesominclasse1);
	FormTitulos->StaticText5->Caption = iniregras->ReadString("Classe1",
		"Titulo", "Erro");
	FormTitulos->StaticText2->Caption = iniregras->ReadString("Classe1",
		"Rodape", "Erro");
	FormTitulos->StaticText7->Caption = iniregras->ReadString("Classe1",
		"Subtitulo", "");
	FormTitulos->TabelaClasse1->Height =
		(FormTitulos->TabelaClasse1->RowCount + 1)
		* FormTitulos->TabelaClasse1->DefaultRowHeight;
	FormTitulos->StaticText2->Top = FormTitulos->TabelaClasse1->Top +
		FormTitulos->TabelaClasse1->Height + 24;
	for (int i = 1; i <= nro_items1; i++) {
		FormTitulos->TabelaClasse1->Cells[0][i] = IntToStr(i);
		String disc = "Disc" + IntToStr(i);
		String string1 = iniregras->ReadString("Classe1", disc, "Erro");
		FormTitulos->TabelaClasse1->Cells[1][i] = string1;
		String pont = "Pont" + IntToStr(i);
		float float1 = iniregras->ReadFloat("Classe1", pont, 0);
		FormTitulos->TabelaClasse1->Cells[2][i] = FormatFloat("0.00", float1);
	}
	// Classe 2
	FormTitulos->StaticText3->Caption = iniregras->ReadString("Classe2",
		"Titulo", "Erro");
	projeto.pesominclasse2 = iniregras->ReadFloat("Classe2", "Pesomin", 0);
	projeto.pesomaxclasse2 = iniregras->ReadFloat("Classe2", "Pesomax", 0);
	projeto.pontuacao_maxima_classe2 = iniregras->ReadBool("Classe2", "Pontuacao_maxima", 0);
	projeto.valor_pontuacao_maxima_classe2 = iniregras->ReadFloat("Classe2", "Valor_pontuacao_maxima", 0);
	FormTitulos->Edit3->Text = FormatFloat("0.00", projeto.pesominclasse2);
	FormTitulos->StaticText9->Caption = iniregras->ReadString("Classe2",
		"Rodape", "Erro");
	FormTitulos->StaticText10->Caption = iniregras->ReadString("Classe2",
		"Subtitulo", "");
	FormTitulos->TabelaClasse2->Height =
		(FormTitulos->TabelaClasse2->RowCount + 1)
		* FormTitulos->TabelaClasse1->DefaultRowHeight;
	FormTitulos->StaticText9->Top = FormTitulos->TabelaClasse2->Top +
		FormTitulos->TabelaClasse2->Height + 24;

	for (int i = 1; i <= nro_items2; i++) {
		FormTitulos->TabelaClasse2->Cells[0][i] = IntToStr(i);
		String disc = "Disc" + IntToStr(i);
		String string1 = iniregras->ReadString("Classe2", disc, "Erro");
		FormTitulos->TabelaClasse2->Cells[1][i] = string1;
		String pont = "Pont" + IntToStr(i);
		float float1 = iniregras->ReadFloat("Classe2", pont, 0);
		FormTitulos->TabelaClasse2->Cells[2][i] = FormatFloat("0.00", float1);
	}
	// Classe 3
	FormTitulos->StaticText6->Caption = iniregras->ReadString("Classe3",
		"Titulo", "Erro");
	projeto.pesominclasse3 = iniregras->ReadFloat("Classe3", "Pesomin", 0);
	projeto.pesomaxclasse3 = iniregras->ReadFloat("Classe3", "Pesomax", 0);
	projeto.pontuacao_maxima_classe3 = iniregras->ReadBool("Classe3", "Pontuacao_maxima", 0);
	projeto.valor_pontuacao_maxima_classe3 = iniregras->ReadFloat("Classe3", "Valor_pontuacao_maxima", 0);

	FormTitulos->Edit4->Text = FormatFloat("0.00", projeto.pesominclasse3);
	FormTitulos->StaticText8->Caption = iniregras->ReadString("Classe3",
		"Rodape", "Erro");
    FormTitulos->StaticText11->Caption = iniregras->ReadString("Classe3",
		"Subtitulo", "");
	FormTitulos->TabelaClasse3->Height =
		(FormTitulos->TabelaClasse3->RowCount + 1)
		* FormTitulos->TabelaClasse1->DefaultRowHeight;
	FormTitulos->StaticText8->Top = FormTitulos->TabelaClasse3->Top +
		FormTitulos->TabelaClasse3->Height + 24;

	for (int i = 1; i <= nro_items3; i++) {
		FormTitulos->TabelaClasse3->Cells[0][i] = IntToStr(i);
		String disc = "Disc" + IntToStr(i);
		String string1 = iniregras->ReadString("Classe3", disc, "Erro");
		FormTitulos->TabelaClasse3->Cells[1][i] = string1;
		String pont = "Pont" + IntToStr(i);
		float float1 = iniregras->ReadFloat("Classe3", pont, 0);
		FormTitulos->TabelaClasse3->Cells[2][i] = FormatFloat("0.00", float1);
	}

    // Titulos das colunas
	FormTitulos->TabelaClasse1->Cells[0][0] = iniregras->ReadString("Titulos",
		"titulo_col1", "Erro");
	FormTitulos->TabelaClasse1->Cells[1][0] = iniregras->ReadString("Titulos",
		"titulo_col2", "Erro");
	FormTitulos->TabelaClasse1->Cells[2][0] = iniregras->ReadString("Titulos",
		"titulo_col3", "Erro");
	FormTitulos->TabelaClasse1->Cells[3][0] = iniregras->ReadString("Titulos",
		"titulo_col4", "Erro");
	FormTitulos->TabelaClasse1->Cells[4][0] = iniregras->ReadString("Titulos",
		"titulo_col5", "Erro");
	FormTitulos->TabelaClasse2->Cells[0][0] = iniregras->ReadString("Titulos",
		"titulo_col1", "Erro");
	FormTitulos->TabelaClasse2->Cells[1][0] = iniregras->ReadString("Titulos",
		"titulo_col2", "Erro");
	FormTitulos->TabelaClasse2->Cells[2][0] = iniregras->ReadString("Titulos",
		"titulo_col3", "Erro");
	FormTitulos->TabelaClasse2->Cells[3][0] = iniregras->ReadString("Titulos",
		"titulo_col4", "Erro");
	FormTitulos->TabelaClasse2->Cells[4][0] = iniregras->ReadString("Titulos",
		"titulo_col5", "Erro");
	FormTitulos->TabelaClasse3->Cells[0][0] = iniregras->ReadString("Titulos",
		"titulo_col1", "Erro");
	FormTitulos->TabelaClasse3->Cells[1][0] = iniregras->ReadString("Titulos",
		"titulo_col2", "Erro");
	FormTitulos->TabelaClasse3->Cells[2][0] = iniregras->ReadString("Titulos",
		"titulo_col3", "Erro");
	FormTitulos->TabelaClasse3->Cells[3][0] = iniregras->ReadString("Titulos",
		"titulo_col4", "Erro");
	FormTitulos->TabelaClasse3->Cells[4][0] = iniregras->ReadString("Titulos",
		"titulo_col5", "Erro");


	// Regras
	FormTitulos->TabelaRegrasMaxPont->RowCount = 1;
	FormTitulos->TabelaRegrasMaxPont->Cells[0][0] = "Indice";
	FormTitulos->TabelaRegrasMaxPont->Cells[1][0] = "Quantidade";
	FormTitulos->TabelaRegrasCumulativo->RowCount = 1;
	FormTitulos->TabelaRegrasCumulativo->Cells[0][0] = "Indice1";
	FormTitulos->TabelaRegrasCumulativo->Cells[1][0] = "Indice2";

	int nro_regras = iniregras->ReadInteger("Titulos", "nro_regras", 0);
	for (int i = 0; i < nro_regras; i++) {
		String regra = "Regra" + IntToStr(i + 1);
		String string1 = iniregras->ReadString("Titulos", regra, "Erro");
		int pos1 = string1.Pos("_");
		String tipo = string1.SubString(1, pos1 - 1);

		if (tipo == "MAXPONT") {
			int classe = StrToInt(string1.SubString(pos1 + 8, 1));
			int item = StrToInt(string1.SubString(pos1 + 15, 2));
			// numero do item com 2 digitos
			//int quant = StrToInt(string1.SubString(pos1 + 24, 3));
			float quant = StrToFloat(string1.SubString(pos1 + 24, 5)); // alterado 3.5 para numeros float
			// quantidade com 3 digitos
			int indice = 0;
			if (classe == 1) {
				indice = item - 1;
			}
			if (classe == 2) {
				indice = item + nro_items1 - 1;
			}
			if (classe == 3) {
				indice = item + nro_items1 + nro_items2 - 1;
			}
			FormTitulos->TabelaRegrasMaxPont->RowCount++;
			FormTitulos->TabelaRegrasMaxPont->Cells[0]
				[FormTitulos->TabelaRegrasMaxPont->RowCount - 1] = IntToStr
				(indice);
			FormTitulos->TabelaRegrasMaxPont->Cells[1]
				[FormTitulos->TabelaRegrasMaxPont->RowCount - 1] = FormatFloat("0.0", quant);
		}

		if (tipo == "CUMULATIVO") {
			int classe = StrToInt(string1.SubString(pos1 + 8, 1));
			// numero do item com 2 digitos
			int item1 = StrToInt(string1.SubString(pos1 + 15, 2));
			int item2 = StrToInt(string1.SubString(pos1 + 23, 2));
			int indice1 = 0;
			int indice2 = 0;
			if (classe == 1) {
				indice1 = item1 - 1;
				indice2 = item2 - 1;
			}
			if (classe == 2) {
				indice1 = item1 + nro_items1 - 1;
				indice2 = item2 + nro_items1 - 1;
			}
			if (classe == 3) {
				indice1 = item1 + nro_items1 + nro_items2 - 1;
				indice2 = item2 + nro_items1 + nro_items2 - 1;
			}
			FormTitulos->TabelaRegrasCumulativo->RowCount++;
			FormTitulos->TabelaRegrasCumulativo->Cells[0]
				[FormTitulos->TabelaRegrasCumulativo->RowCount - 1] = IntToStr
				(indice1);
			FormTitulos->TabelaRegrasCumulativo->Cells[1]
				[FormTitulos->TabelaRegrasCumulativo->RowCount - 1] = IntToStr
				(indice2);
		}

	}

	delete iniregras;
	FormLog->Memo1->Lines->Add("Fim do método AbrirRegrasGCR");
}

void __fastcall TForm1::AbrirGC3(String nome_arq) {

	FormLog->Memo1->Lines->Add("Iniciando método AbrirGC3");

	nome_arq = AnsiDequotedStr((AnsiString)nome_arq, '\"');
	// String nome_arq = OpenDialog1->FileName;

	String temp = ExtractFileDir(nome_arq);

	String xxxx = GetCurrentDir();

	TIniFile *arq;
	arq = new TIniFile(nome_arq);

	String ver = arq->ReadString("Principal", "Versao", "1.0");

	if (StrToInt(ver.SubString(1, 1)) < 2) {
		Application->MessageBox(
			L"GCP não pode abrir este arquivo.\nVerifique a versão do sistema."
			, L"Erro", 0);
		return;
	}

	// arquivos_recentes.insert(
	bool encontrou = false;
	int indice_encontrou;
	for (int i = 0; i < 4; i++) {
		if (arquivos_recentes[i] == nome_arq) {
			encontrou = true;
			indice_encontrou = i;
		}
	}
	if (!encontrou) {
		arquivos_recentes.insert(arquivos_recentes.begin(), nome_arq);
		arquivos_recentes.erase(arquivos_recentes.begin() + 4);
	}
	else {
		arquivos_recentes.insert(arquivos_recentes.begin(), nome_arq);
		arquivos_recentes.erase
			(arquivos_recentes.begin() + indice_encontrou + 1);
	}
	AtualizaArquivosRecentes();

	String infor = "Deseja salvar as informações do concurso " + projeto.nome +
		"?";
	if (Trim(projeto.nome) != "")
		if (Application->MessageBox(infor.c_str(), L"Atenção",
				MB_YESNO) == ID_YES) {
			Salvar2Click(Form1);
		}

	String xxxa = ExtractFileDir(nome_arq);
	// SetCurrentDir(ExtractFileDir(nome_arq));

	// Limpa tudo
	Limpa(Form1);

	projeto.arq_regras = arq->ReadString("Projeto", "arq_regras", "Erro");
	// Carrega arquivo de regras
	// String yy = "edital52.gcr";
//	String exeFile = Application->ExeName;
//	String exePath = ExtractFilePath(exeFile);
//	String nome_arq2 = exePath + "regras\\" + projeto.arq_regras;
//	AbrirRegrasGCR(nome_arq2);
	//
//	 ------------ Modificado a partir da versao 3.7, a qual procura as regras em diretório superior ao da aplicação
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
	exePath = exePath.SubString(1,exePath.Length()-2);
	String GCPPath = ExtractFilePath(exePath);
	String nome_arq2 = GCPPath + "regras\\" + projeto.arq_regras;
	AbrirRegrasGCR(nome_arq2);

	// bool foi= SetCurrentDir(temp);
	Form1->Caption = "Gerenciador de Concursos Públicos - UNIPAMPA - " +
		ExtractFileName(nome_arq);

	// CheckBoxes
	CB10->Checked = arq->ReadBool("Principal", "CB10", 0);
	CB11->Checked = arq->ReadBool("Principal", "CB11", 0);
	CB12->Checked = arq->ReadBool("Principal", "CB12", 0);
	CB13->Checked = arq->ReadBool("Principal", "CB13", 0);
	CB14->Checked = arq->ReadBool("Principal", "CB14", 0);
	CB15->Checked = arq->ReadBool("Principal", "CB15", 0);
	CB16->Checked = arq->ReadBool("Principal", "CB16", 0);
	CB17->Checked = arq->ReadBool("Principal", "CB17", 0);

	CB21->Checked = arq->ReadBool("Principal", "CB21", 0);
	CB22->Checked = arq->ReadBool("Principal", "CB22", 0);
	CB23->Checked = arq->ReadBool("Principal", "CB23", 0);
	CB24->Checked = arq->ReadBool("Principal", "CB24", 0);
	CB25->Checked = arq->ReadBool("Principal", "CB25", 0);
	CB26->Checked = arq->ReadBool("Principal", "CB26", 0);
	CB27->Checked = arq->ReadBool("Principal", "CB27", 0);
	CB28->Checked = arq->ReadBool("Principal", "CB28", 0);
	CB29->Checked = arq->ReadBool("Principal", "CB29", 0);
	CB210->Checked = arq->ReadBool("Principal", "CB210", 0);
	CB211->Checked = arq->ReadBool("Principal", "CB211", 0);
	CB212->Checked = arq->ReadBool("Principal", "CB212", 0);
	CB213->Checked = arq->ReadBool("Principal", "CB213", 0);
	CB214->Checked = arq->ReadBool("Principal", "CB214", 0);

	CB31->Checked = arq->ReadBool("Principal", "CB31", 0);
	CB32->Checked = arq->ReadBool("Principal", "CB32", 0);
	CB33->Checked = arq->ReadBool("Principal", "CB33", 0);

	CB41->Checked = arq->ReadBool("Principal", "CB41", 0);
	CB42->Checked = arq->ReadBool("Principal", "CB42", 0);
	CB43->Checked = arq->ReadBool("Principal", "CB43", 0);
	CB44->Checked = arq->ReadBool("Principal", "CB44", 0);
	CB45->Checked = arq->ReadBool("Principal", "CB45", 0);
	CB46->Checked = arq->ReadBool("Principal", "CB46", 0);
	CB47->Checked = arq->ReadBool("Principal", "CB47", 0);
	CB48->Checked = arq->ReadBool("Principal", "CB48", 0);
	CB49->Checked = arq->ReadBool("Principal", "CB49", 0);
	CB410->Checked = arq->ReadBool("Principal", "CB410", 0);
	CB411->Checked = arq->ReadBool("Principal", "CB411", 0);
	CB412->Checked = arq->ReadBool("Principal", "CB412", 0);
	CB413->Checked = arq->ReadBool("Principal", "CB413", 0);
	CB414->Checked = arq->ReadBool("Principal", "CB414", 0);
	CB415->Checked = arq->ReadBool("Principal", "CB415", 0);

	CB51->Checked = arq->ReadBool("Principal", "CB51", 0);
	CB52->Checked = arq->ReadBool("Principal", "CB52", 0);
	CB53->Checked = arq->ReadBool("Principal", "CB53", 0);
	CB54->Checked = arq->ReadBool("Principal", "CB54", 0);
	CB55->Checked = arq->ReadBool("Principal", "CB55", 0);
	CB56->Checked = arq->ReadBool("Principal", "CB56", 0);
	CB57->Checked = arq->ReadBool("Principal", "CB57", 0);

	CB61->Checked = arq->ReadBool("Principal", "CB61", 0);
	CB62->Checked = arq->ReadBool("Principal", "CB62", 0);
	CB63->Checked = arq->ReadBool("Principal", "CB63", 0);
	CB64->Checked = arq->ReadBool("Principal", "CB64", 0);

	CB71->Checked = arq->ReadBool("Principal", "CB71", 0);
	CB72->Checked = arq->ReadBool("Principal", "CB72", 0);
	CB73->Checked = arq->ReadBool("Principal", "CB73", 0);
	CB74->Checked = arq->ReadBool("Principal", "CB74", 0);
	CB75->Checked = arq->ReadBool("Principal", "CB75", 0);
	CB76->Checked = arq->ReadBool("Principal", "CB76", 0);
	CB77->Checked = arq->ReadBool("Principal", "CB77", 0);

	// Panels

	Panel2->Top = arq->ReadInteger("Principal", "Panel2Top", 0);
	Panel2->Visible = arq->ReadBool("Principal", "Panel2Visible", 0);
	Panel6->Top = arq->ReadInteger("Principal", "Panel6Top", 0);
	Panel6->Visible = arq->ReadBool("Principal", "Panel6Visible", 0);
	Panel3->Top = arq->ReadInteger("Principal", "Panel3Top", 0);
	Panel3->Visible = arq->ReadBool("Principal", "Panel3Visible", 0);
	Panel4->Top = arq->ReadInteger("Principal", "Panel4Top", 0);
	Panel4->Visible = arq->ReadBool("Principal", "Panel4Visible", 0);
	Panel7->Top = arq->ReadInteger("Principal", "Panel7Top", 0);
	Panel7->Visible = arq->ReadBool("Principal", "Panel7Visible", 0);
	Panel5->Top = arq->ReadInteger("Principal", "Panel5Top", 0);
	Panel5->Visible = arq->ReadBool("Principal", "Panel5Visible", 0);

	// ScrollBox1
	ScrollBox1->VertScrollBar->Position = arq->ReadInteger("Principal",
		"ScrollBox1Pos", 0);

	// ListView1
	int c = arq->ReadInteger("ListView1", "nro_sec", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		TListItem *ListItem;
		ListItem = Form1->ListView1->Items->Add();
		ListItem->Caption = arq->ReadString("ListView1", "sec" + in, "");
		int s = arq->ReadInteger("ListView1", "nro_subsec" + in, 0);
		for (int j = 0; j < s; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			String subi = arq->ReadString("ListView1", subsec, "");
			ListItem->SubItems->Add(subi);
		}
	}

	// ListView2
	c = arq->ReadInteger("ListView2", "nro_sec", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		TListItem *ListItem;
		ListItem = Form1->ListView2->Items->Add();
		ListItem->Caption = arq->ReadString("ListView2", "sec" + in, "");
		int s = arq->ReadInteger("ListView2", "nro_subsec" + in, 0);
		for (int j = 0; j < s; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			String subi = arq->ReadString("ListView2", subsec, "");
			ListItem->SubItems->Add(subi);
		}
	}

	// ListView3
	c = arq->ReadInteger("ListView3", "nro_sec", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		TListItem *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = arq->ReadString("ListView3", "sec" + in, "");
		int s = arq->ReadInteger("ListView3", "nro_subsec" + in, 0);
		for (int j = 0; j < s; j++) {
			String subsec = "SubItem" + IntToStr(i) + "_" + IntToStr(j);
			String subi = arq->ReadString("ListView3", subsec, "");
			ListItem->SubItems->Add(subi);
		}
	}

	// Variavel candidato
	c = arq->ReadInteger("candidato", "size", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);

		tipo_candidato can;
		can.nome = arq->ReadString("Candidato", "Nome" + in, "");
		can.sexo = arq->ReadInteger("Candidato", "Sexo" + in, 0);
		for (int j = 0; j < 100; j++) {
			String jn = IntToStr(j);
			String subsec = "Nota_titulos_" + in + "_" + jn;
			can.nota_titulos[j] = arq->ReadFloat("Candidato", subsec, 0);
		}
		can.nascimento = arq->ReadDate("Candidato", "Nascimento" + in,
			(TDate)"1/1/2000");
		candidato.push_back(can);
	}

	// Variavel examinador
	for (int i = 0; i < 3; i++) {
		String in = IntToStr(i);

		examinador[i].nome = arq->ReadString("Examinador", "nome" + in, "");
		examinador[i].classe = arq->ReadInteger("Examinador", "classe" + in, 0);
		examinador[i].nome_completo = arq->ReadString("Examinador",
			"nome_completo" + in, "");
		examinador[i].sexo = arq->ReadInteger("Examinador", "sexo" + in, 0);
	}

	// Variavel projeto
	// projeto.diretorio = arq->ReadString("Projeto", "diretorio", "");
	projeto.diretorio = ExtractFileDir(nome_arq);

	projeto.nome = arq->ReadString("Projeto", "nome", "");
	projeto.ministerio = arq->ReadString("Projeto", "ministerio", "");
	projeto.universidade = arq->ReadString("Projeto", "universidade", "");
	projeto.centro = arq->ReadString("Projeto", "centro", "");
	projeto.departamento = arq->ReadString("Projeto", "departamento", "");
	projeto.campus = arq->ReadString("Projeto", "campus", "");
	projeto.edital = arq->ReadString("Projeto", "edital", "");
	projeto.area = arq->ReadString("Projeto", "area", "");
	projeto.classe = arq->ReadInteger("Projeto", "classe", 0);
	projeto.categoria = arq->ReadString("Projeto", "categoria", "");
	projeto.data_inicio = arq->ReadDate("Projeto", "data_inicio",
		(TDate)"1/1/2000");
	projeto.peso_didatica_final = arq->ReadFloat("Projeto", "peso_didatica", 0);
	projeto.peso_escrita_final = arq->ReadFloat("Projeto", "peso_escrita", 0);
	projeto.peso_memorial_final = arq->ReadFloat("Projeto", "peso_memorial", 0);
	projeto.peso_titulos_final = arq->ReadFloat("Projeto", "peso_titulos", 0);
	projeto.peso_entrevista_final = arq->ReadFloat("Projeto", "peso_entrevista", 0);
	projeto.habilita_prova_escrita = arq->ReadBool("Projeto", "habilita_prova_escrita",1);
	projeto.habilita_prova_didatica = arq->ReadBool("Projeto", "habilita_prova_didatica",1);
	projeto.habilita_prova_memorial = arq->ReadBool("Projeto", "habilita_prova_memorial",1);
	projeto.habilita_prova_titulos = arq->ReadBool("Projeto", "habilita_prova_titulos",1);
	projeto.habilita_prova_entrevista = arq->ReadBool("Projeto", "habilita_prova_entrevista", 0);
    Form1->CB15->Enabled = projeto.habilita_prova_titulos;
	Form1->Button10->Enabled = projeto.habilita_prova_titulos;

	// Variavel ponto_escrita
	c = arq->ReadInteger("ponto_escrita", "size", 0);
	for (int i = 0; i < c; i++) {
		tipo_ponto pt;
		String in = IntToStr(i);
		pt.texto = arq->ReadString("ponto_escrita", "texto" + in, "");
		pt.valido = arq->ReadBool("ponto_escrita", "valido" + in, 0);
		ponto_escrita.push_back(pt);
	}

	// Variavel ponto_didatica
	c = arq->ReadInteger("ponto_didatica", "size", 0);
	for (int i = 0; i < c; i++) {
		tipo_ponto pt;
		String in = IntToStr(i);
		pt.texto = arq->ReadString("ponto_didatica", "texto" + in, "");
		pt.valido = arq->ReadBool("ponto_didatica", "valido" + in, 0);
		ponto_didatica.push_back(pt);
	}

	// Variavel nro_ata
	nro_ata = arq->ReadInteger("Principal", "nro_ata", 1);

	// Variavel nro_lista
	nro_lista = arq->ReadInteger("Principal", "nro_lista", 1);

	// Variavel lab_def
	// c = arq->ReadInteger("lab_def","size", 0);
	// for (int i=0; i<c; i++)
	// {
	// TLabel *la;
	// String in = IntToStr(i);
	// la->Caption = arq->ReadString("lab_def", "caption"+in, "");
	// lab_def.push_back(la);
	// }

	// ****************** DefesaProjetoCandidatos ****************
	c = arq->ReadInteger("Memorial_candidatos", "ListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDefesaProjeto_candidatos->ListBox1->Items->Add
			(arq->ReadString("Memorial_candidatos",
				"ListBox1_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Memorial_candidatos", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDefesaProjeto_candidatos->ListBox2->Items->Add
			(arq->ReadString("Memorial_candidatos",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	// ****************** EntrevistaCandidatos ****************
	c = arq->ReadInteger("Entrevista_candidatos", "ListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEntrevista_candidatos->ListBox1->Items->Add
			(arq->ReadString("Entrevista_candidatos",
				"ListBox1_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Entrevista_candidatos", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEntrevista_candidatos->ListBox2->Items->Add
			(arq->ReadString("Entrevista_candidatos",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	// ****************** DidaticaCandidatos ****************
	c = arq->ReadInteger("Didatica_candidatos", "ListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDidaticaCandidatos->ListBox1->Items->Add
			(arq->ReadString("Didatica_candidatos",
				"ListBox1_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Didatica_candidatos", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDidaticaCandidatos->ListBox2->Items->Add
			(arq->ReadString("Didatica_candidatos",
				"ListBox2_Item" + IntToStr(i), ""));
	}

	// ****************** Didatica ****************

	// Candidatos - nada a abrir

	// Pontos
	c = arq->ReadInteger("Didatica", "ListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDidatica->ListBox1->Items->Add(arq->ReadString("Didatica",
				"ListBox1_Item" + IntToStr(i), ""));
	}

	// Criterios
	// arq->WriteInteger("Didatica", "ValueListEditor1_Rows", FormDidatica->ValueListEditor1->RowCount);
	// for (int i=0; i<FormDidatica->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDidatica->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// FormDidatica->ValueListEditor1->Cells[j][i] = arq->ReadString("Didatica","Cells"+jn+"_"+in, "");
	// }
	// }
	// FormDidatica->ValueListEditor1->Strings->CommaText = arq->ReadString("Didatica", "ValueListEditor1", "");
    FormDidatica->ValueListEditor1->Strings->Clear();
	c = arq->ReadInteger("Didatica", "ValueListEditor1_count", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		FormDidatica->ValueListEditor1->Strings->Add
			(arq->ReadString("Didatica", "String" + in, ""));
	}

	// Ata sorteio
	FormDidatica->Edit1->Text = arq->ReadString("Didatica", "Edit1", "");

	// Planilhas
	c = arq->ReadInteger("Didatica", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDidatica->ListBox2->Items->Add(arq->ReadString("Didatica",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Didatica", "ListBox3_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDidatica->ListBox3->Items->Add(arq->ReadString("Didatica",
				"ListBox3_Item" + IntToStr(i), ""));
	}

	// Ata realizacao
	FormDidatica->Edit2->Text = arq->ReadString("Didatica", "Edit2", "");

	// Ata resultado
	FormDidatica->Edit3->Text = arq->ReadString("Didatica", "Edit3", "");
	FormDidatica->DateTimePicker2->Time = arq->ReadTime("Didatica",
		"DateTimePicker2", (TTime)"00:00:00");

	// ****************** Memorial ****************

	// Planilhas
	c = arq->ReadInteger("Memorial", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDefesaProjeto->ListBox2->Items->Add(arq->ReadString("Memorial",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Memorial", "ListBox3_cout", 0);
	for (int i = 0; i < c; i++) {
		FormDefesaProjeto->ListBox3->Items->Add(arq->ReadString("Memorial",
				"ListBox3_Item" + IntToStr(i), ""));
	}

	// Realizacao - nada a salvar

	// Criterios
	// c = arq->ReadInteger("Memorial", "ValueListEditor1_Rows", 0);
	// for (int i=0; i<FormDefesaProjeto->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDefesaProjeto->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// FormDefesaProjeto->ValueListEditor1->Cells[j][i] = arq->ReadString("Memorial","Cells"+jn+"_"+in, "");
	// }
	// }
	// FormDefesaProjeto->ValueListEditor1->Strings->CommaText = arq->ReadString("Memorial", "ValueListEditor1", "");
    FormDefesaProjeto->ValueListEditor1->Strings->Clear();
	c = arq->ReadInteger("Memorial", "ValueListEditor1_count", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		FormDefesaProjeto->ValueListEditor1->Strings->Add
			(arq->ReadString("Memorial", "String" + in, ""));
	}

	// Ata
	FormDefesaProjeto->Edit1->Text = arq->ReadString("Memorial", "Edit1", "");

	// ****************** Entrevista ****************

	// Planilhas
	c = arq->ReadInteger("Entrevista", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEntrevista->ListBox2->Items->Add(arq->ReadString("Entrevista",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Entrevista", "ListBox3_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEntrevista->ListBox3->Items->Add(arq->ReadString("Entrevista",
				"ListBox3_Item" + IntToStr(i), ""));
	}

	// Realizacao - nada a salvar

	// Criterios
	// c = arq->ReadInteger("Memorial", "ValueListEditor1_Rows", 0);
	// for (int i=0; i<FormDefesaProjeto->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormDefesaProjeto->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// FormDefesaProjeto->ValueListEditor1->Cells[j][i] = arq->ReadString("Memorial","Cells"+jn+"_"+in, "");
	// }
	// }
	// FormDefesaProjeto->ValueListEditor1->Strings->CommaText = arq->ReadString("Memorial", "ValueListEditor1", "");
	FormEntrevista->ValueListEditor1->Strings->Clear();
	c = arq->ReadInteger("Entrevista", "ValueListEditor1_count", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		FormEntrevista->ValueListEditor1->Strings->Add
			(arq->ReadString("Entrevista", "String" + in, ""));
	}

	// Ata
	FormEntrevista->Edit1->Text = arq->ReadString("Entrevista", "Edit1", "");


	// Gera os candidatos na prova didatica
//	FormDidaticaCandidatos->Button1Click(Form1);
	FormDidatica->ListBox2->Items = FormDidaticaCandidatos->ListBox2->Items;
	FormDidatica->Button1Click(FormDidaticaCandidatos);

//    Gera os candidatos da prova memorial
//	FormDefesaProjeto_candidatos->Button1Click(Form1);
	FormDefesaProjeto->ListBox2->Items = FormDefesaProjeto_candidatos->ListBox2->Items;
	FormDefesaProjeto->Button1Click(FormDefesaProjeto_candidatos);

//	Gera os candidatos da prova entrevista
//	FormEntrevista_candidatos->Button1Click(Form1);
	FormEntrevista->ListBox2->Items = FormEntrevista_candidatos->ListBox2->Items;
	FormEntrevista->Button1Click(FormEntrevista_candidatos);

	// Variavel dat_def
	c = arq->ReadInteger("dat_def", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da;
		String in = IntToStr(i);
		dat_def[i]->Date = arq->ReadDate("dat_def", "date" + in,
			(TDate)"1/1/2000");
		// dat_def.push_back(da);
	}

	// Variavel hor_def
	c = arq->ReadInteger("hor_def", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da;
		String in = IntToStr(i);
		hor_def[i]->Time = arq->ReadTime("hor_def", "time" + in,
			(TTime)"00:00:00");
		// hor_def.push_back(da);
	}

	// Variavel comp_def
	c = arq->ReadInteger("comp_def", "size", 0);
	for (int i = 0; i < c; i++) {
		// TCheckBox* co;
		String in = IntToStr(i);
		comp_def[i]->Checked = arq->ReadBool("comp_def", "checked" + in, 0);
		// comp_def.push_back(co);
	}

	// Variavel dat_ent
	c = arq->ReadInteger("dat_ent", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da;
		String in = IntToStr(i);
		dat_ent[i]->Date = arq->ReadDate("dat_ent", "date" + in,
			(TDate)"1/1/2000");
		// dat_def.push_back(da);
	}

	// Variavel hor_ent
	c = arq->ReadInteger("hor_ent", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da;
		String in = IntToStr(i);
		hor_ent[i]->Time = arq->ReadTime("hor_ent", "time" + in,
			(TTime)"00:00:00");
		// hor_def.push_back(da);
	}

	// Variavel comp_ent
	c = arq->ReadInteger("comp_ent", "size", 0);
	for (int i = 0; i < c; i++) {
		// TCheckBox* co;
		String in = IntToStr(i);
		comp_ent[i]->Checked = arq->ReadBool("comp_ent", "checked" + in, 0);
		// comp_def.push_back(co);
	}

	// Variavel lab
	// c = arq->ReadInteger("lab","size", 0);
	// for (int i=0; i<c; i++)
	// {
	// TLabel *la;
	// String in = IntToStr(i);
	// la->Caption = arq->ReadString("lab", "caption"+in, "");
	// lab.push_back(la);
	// }

	// Variavel dat_sor
	c = arq->ReadInteger("dat_sor", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da = new TDateTimePicker(this);
		String in = IntToStr(i);
		dat_sor[i]->Date = arq->ReadDate("dat_sor", "date" + in,
			(TDate)"1/1/2000");
		// dat_sor.push_back(da);
		// delete da;
	}

	// Variavel dat_apr
	c = arq->ReadInteger("dat_apr", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da = new TDateTimePicker(this);
		String in = IntToStr(i);
		dat_apr[i]->Date = arq->ReadDate("dat_apr", "date" + in,
			(TDate)"1/1/2000");
		// dat_apr.push_back(da);
		// delete da;
	}

	// Variavel hor_sor
	c = arq->ReadInteger("hor_sor", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da = new TDateTimePicker(this);
		String in = IntToStr(i);
		hor_sor[i]->Time = arq->ReadTime("hor_sor", "time" + in,
			(TTime)"00:00:00");
		// hor_sor.push_back(da);
		// delete da;
	}

	// Variavel hor_apr
	c = arq->ReadInteger("hor_apr", "size", 0);
	for (int i = 0; i < c; i++) {
		// TDateTimePicker* da = new TDateTimePicker(this);
		String in = IntToStr(i);
		hor_apr[i]->Time = arq->ReadTime("hor_apr", "time" + in,
			(TTime)"00:00:00");
		// hor_apr.push_back(da);
		// delete da;
	}

	// Variavel comp_sor
	c = arq->ReadInteger("comp_sor", "size", 0);
	for (int i = 0; i < c; i++) {
		// TCheckBox* co = new TCheckBox(this);
		String in = IntToStr(i);
		comp_sor[i]->Checked = arq->ReadBool("comp_sor", "checked" + in, 0);
		// comp_sor.push_back(co);
		// delete co;
	}

	// Variavel comp_apr
	c = arq->ReadInteger("comp_apr", "size", 0);
	for (int i = 0; i < c; i++) {
		// TCheckBox* co = new TCheckBox(this);
		String in = IntToStr(i);
		comp_apr[i]->Checked = arq->ReadBool("comp_apr", "checked" + in, 0);
		// comp_apr.push_back(co);
		// delete co;
	}

	// Variavel ponto
	c = arq->ReadInteger("ponto", "size", 0);
	for (int i = 0; i < c; i++) {
		// TComboBox* co = new TComboBox(this);
		String in = IntToStr(i);

		// int c2 = arq->ReadInteger("ponto", "size"+in, 0);
		// for (int j=0; j<c2; j++)
		// {
		// String jn = IntToStr(j);
		// co->Items->Add(arq->ReadString("ponto", "item"+in+"_"+jn, ""));
		// }

		ponto[i]->ItemIndex = arq->ReadInteger("ponto", "itemindex" + in, -1);
		// ponto.push_back(co);
		// delete co;
	}

	// ****************** Abertura ****************

	// Instalação
	FormAbertura->DateTimePicker2->Time = arq->ReadTime("Abertura",
		"DateTimePicker2", (TTime)"00:00:00");
	FormAbertura->Edit1->Text = arq->ReadString("Abertura", "Edit1", "");
	FormAbertura->Edit2->Text = arq->ReadString("Abertura", "Edit2", "");
	FormAbertura->Edit3->Text = arq->ReadString("Abertura", "Edit3", "");

	// Cronograma
	FormAbertura->StringGrid1->ColCount = arq->ReadInteger("Abertura",
		"StringGrid1Col", 0);
	FormAbertura->StringGrid1->RowCount = arq->ReadInteger("Abertura",
		"StringGrid1Row", 0);
	for (int i = 0; i < FormAbertura->StringGrid1->ColCount; i++) {
		for (int j = 0; j < FormAbertura->StringGrid1->RowCount; j++) {
			FormAbertura->StringGrid1->Cells[i][j] = arq->ReadString
				("Abertura", "Cell" + IntToStr(i) + "_" + IntToStr(j), "");
		}
	}
	if (FormAbertura->StringGrid1->RowCount > 1)
		FormAbertura->StringGrid1->FixedRows = 1;

	// Abertura
	c = arq->ReadInteger("Abertura", "CheckListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormAbertura->CheckListBox1->Items->Add(arq->ReadString("Abertura",
				"CheckListBox1_Item" + IntToStr(i), ""));
		FormAbertura->CheckListBox1->Checked[i] = arq->ReadBool("Abertura",
			"CheckListBox1_Checked" + IntToStr(i), 0);
	}
	FormAbertura->DateTimePicker4->Time = arq->ReadTime("Abertura",
		"DateTimePicker4", (TTime)"00:00:00");

	// Pesos
	FormAbertura->Edit10->Text = arq->ReadString("Abertura",
		"Edit10Text", "");
	FormAbertura->Edit10->Visible =  arq->ReadBool("Abertura",
		"Edit10Visible", true);
	FormAbertura->Edit10->Enabled =  arq->ReadBool("Abertura",
		"Edit10Enabled", true);
	FormAbertura->Edit11->Text = arq->ReadString("Abertura",
		"Edit11Text", "");
	FormAbertura->Edit11->Visible =  arq->ReadBool("Abertura",
		"Edit11Visible", true);
	FormAbertura->Edit11->Enabled =  arq->ReadBool("Abertura",
		"Edit11Enabled", true);
	FormAbertura->Edit12->Text = arq->ReadString("Abertura",
		"Edit12Text", "");
	FormAbertura->Edit12->Visible =  arq->ReadBool("Abertura",
		"Edit12Visible", true);
	FormAbertura->Edit12->Enabled =  arq->ReadBool("Abertura",
		"Edit12Enabled", true);
	FormAbertura->Edit13->Text = arq->ReadString("Abertura",
		"Edit13Text", "");
	FormAbertura->Edit13->Visible =  arq->ReadBool("Abertura",
		"Edit13Visible", true);
	FormAbertura->Edit13->Enabled =  arq->ReadBool("Abertura",
		"Edit13Enabled", true);
	FormAbertura->Edit14->Text = arq->ReadString("Abertura",
		"Edit14Text", "");
	FormAbertura->Edit14->Visible =  arq->ReadBool("Abertura",
		"Edit14Visible", true);
	FormAbertura->Edit14->Enabled =  arq->ReadBool("Abertura",
		"Edit14Enabled", true);
	// ****************** Configuracao ****************
	// Dados gerais
	FormConfiguracao->LabeledEdit1->Text = arq->ReadString("Configuracao",
		"LabeledEdit1", "");
	FormConfiguracao->LabeledEdit5->Text = arq->ReadString("Configuracao",
		"LabeledEdit5", "");
	FormConfiguracao->LabeledEdit6->Text = arq->ReadString("Configuracao",
		"LabeledEdit6", "");
	FormConfiguracao->LabeledEdit7->Text = arq->ReadString("Configuracao",
		"LabeledEdit7", "");
	FormConfiguracao->LabeledEdit8->Text = arq->ReadString("Configuracao",
		"LabeledEdit8", "");
	FormConfiguracao->LabeledEdit2->Text = arq->ReadString("Configuracao",
		"LabeledEdit2", "");
	FormConfiguracao->LabeledEdit3->Text = arq->ReadString("Configuracao",
		"LabeledEdit3", "");
	FormConfiguracao->DateTimePicker1->Date = arq->ReadDate("Configuracao",
		"DateTimePicker1", (TDate)"1/1/2000");
	FormConfiguracao->RadioGroup4->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup4", 0);

	// Diretório
	// FormConfiguracao->DirectoryListBox1->Directory = arq->ReadString("Configuracao", "DirectoryListBox1", "");
	FormConfiguracao->Edit4->Text = arq->ReadString("Configuracao", "Edit4",
		"");
	FormConfiguracao->Edit5->Text = arq->ReadString("Configuracao", "Edit5",
		"");

	// Banca
	FormConfiguracao->Edit1->Text = arq->ReadString("Configuracao", "Edit1",
		"");
	FormConfiguracao->Edit2->Text = arq->ReadString("Configuracao", "Edit2",
		"");
	FormConfiguracao->Edit6->Text = arq->ReadString("Configuracao", "Edit6",
		"");
	FormConfiguracao->Edit7->Text = arq->ReadString("Configuracao", "Edit7",
		"");
	FormConfiguracao->Edit8->Text = arq->ReadString("Configuracao", "Edit8",
		"");
	FormConfiguracao->Edit9->Text = arq->ReadString("Configuracao", "Edit9",
		"");

	FormConfiguracao->RadioGroup2->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup2", 0);
	FormConfiguracao->RadioGroup6->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup6", 0);
	FormConfiguracao->RadioGroup8->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup8", 0);
	FormConfiguracao->RadioGroup1->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup1", 0);
	FormConfiguracao->RadioGroup5->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup5", 0);
	FormConfiguracao->RadioGroup7->ItemIndex = arq->ReadInteger("Configuracao",
		"RadioGroup7", 0);

	// Candidatos inscritos
	c = arq->ReadInteger("Configuracao", "List_Candidatos_cout", 0);
	for (int i = 0; i < c; i++) {
		FormConfiguracao->List_Candidatos->Items->Add
			(arq->ReadString("Configuracao",
				"List_Candidatos_Item" + IntToStr(i), ""));
		FormConfiguracao->List_Candidatos->Checked[i] = arq->ReadBool
			("Configuracao", "List_Candidatos_Checked" + IntToStr(i), 0);
	}

	// ****************** Escrita ****************
	// Realizaçao
	FormEscrita->CSpinEdit1->Value = arq->ReadInteger("Escrita", "CSpinEdit1",
		0);
	FormEscrita->DateTimePicker1->Time = arq->ReadTime("Escrita",
		"DateTimePicker1", (TTime)"00:00:00");
	FormEscrita->DateTimePicker6->Time = arq->ReadTime("Escrita",
		"DateTimePicker6", (TTime)"00:00:00");
	FormEscrita->DateTimePicker2->Time = arq->ReadTime("Escrita",
		"DateTimePicker2", (TTime)"00:00:00");
	FormEscrita->Edit2->Text = arq->ReadString("Escrita", "Edit2", "");

	// Leitura
	c = arq->ReadInteger("Escrita", "CheckListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->CheckListBox2->Items->Add(arq->ReadString("Escrita",
				"CheckListBox2_Item" + IntToStr(i), ""));
		FormEscrita->CheckListBox2->Checked[i] = arq->ReadBool("Escrita",
			"CheckListBox2_Checked" + IntToStr(i), 0);
	}
	FormEscrita->DateTimePicker5->Time = arq->ReadTime("Escrita",
		"DateTimePicker5", (TTime)"00:00:00");
	FormEscrita->Edit1->Text = arq->ReadString("Escrita", "Edit1", "");

	// Criterios
	// FormEscrita->ValueListEditor1->RowCount = arq->ReadInteger("Escrita", "ValueListEditor1_Rows", 0);
	// for (int i=0; i<FormEscrita->ValueListEditor1->RowCount; i++)
	// {
	// for (int j=0; j<FormEscrita->ValueListEditor1->ColCount; j++) // sao sempre 2 colunas
	// {
	// String in = IntToStr(i);
	// String jn = IntToStr(j);
	// FormEscrita->ValueListEditor1->Cells[j][i] = arq->ReadString("Escrita","Cells"+jn+"_"+in, "");
	// }
	// }

	// FormEscrita->ValueListEditor1->Strings->CommaText = arq->ReadString("Escrita", "ValueListEditor1", "");
	FormEscrita->ValueListEditor1->Strings->Clear();
	c = arq->ReadInteger("Escrita", "ValueListEditor1_count", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		FormEscrita->ValueListEditor1->Strings->Add(arq->ReadString("Escrita",
				"String" + in, ""));
	}

	// Julgamento
	FormEscrita->DateTimePicker8->Time = arq->ReadTime("Escrita",
		"DateTimePicker8", (TTime)"00:00:00");
	FormEscrita->Edit3->Text = arq->ReadString("Escrita", "Edit3", "");

	// Configuracao
	c = arq->ReadInteger("Escrita", "CheckListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->CheckListBox1->Items->Add(arq->ReadString("Escrita",
				"CheckListBox1_Item" + IntToStr(i), ""));
		FormEscrita->CheckListBox1->Checked[i] = arq->ReadBool("Escrita",
			"CheckListBox1_Checked" + IntToStr(i), 0);
	}
	c = arq->ReadInteger("Escrita", "ListBox4_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->ListBox4->Items->Add(arq->ReadString("Escrita",
				"ListBox4_Item" + IntToStr(i), ""));
	}

	// Pontos
	c = arq->ReadInteger("Escrita", "ListBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->ListBox1->Items->Add(arq->ReadString("Escrita",
				"ListBox1_Item" + IntToStr(i), ""));
	}

	// Planilhas
	c = arq->ReadInteger("Escrita", "ListBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->ListBox2->Items->Add(arq->ReadString("Escrita",
				"ListBox2_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Escrita", "ListBox3_cout", 0);
	for (int i = 0; i < c; i++) {
		FormEscrita->ListBox3->Items->Add(arq->ReadString("Escrita",
				"ListBox3_Item" + IntToStr(i), ""));
	}

	// Resultado
	FormEscrita->DateTimePicker9->Time = arq->ReadTime("Escrita",
		"DateTimePicker9", (TTime)"00:00:00");
	FormEscrita->Edit5->Text = arq->ReadString("Escrita", "Edit5", "");

	// ****************** Titulos ****************
	c = arq->ReadInteger("Titulos", "ComboBox1_cout", 0);
	for (int i = 0; i < c; i++) {
		FormTitulos->ComboBox1->Items->Add(arq->ReadString("Titulos",
				"ComboBox1_Item" + IntToStr(i), ""));
	}
	c = arq->ReadInteger("Titulos", "ComboBox2_cout", 0);
	for (int i = 0; i < c; i++) {
		FormTitulos->ComboBox2->Items->Add(arq->ReadString("Titulos",
				"ComboBox2_Item" + IntToStr(i), ""));
	}
	FormTitulos->Edit2->Text = arq->ReadString("Titulos", "Edit2", "");
	FormTitulos->Edit3->Text = arq->ReadString("Titulos", "Edit3", "");
	FormTitulos->Edit4->Text = arq->ReadString("Titulos", "Edit4", "");
	FormTitulos->Edit8->Text = arq->ReadString("Titulos", "Edit8", "");
	FormTitulos->Edit9->Text = arq->ReadString("Titulos", "Edit9", "");
	FormTitulos->Edit10->Text = arq->ReadString("Titulos", "Edit10", "");
	FormTitulos->Edit1->Text = arq->ReadString("Titulos", "Edit1", "");
	FormTitulos->DateTimePicker2->Time = arq->ReadTime("Titulos",
		"DateTimePicker2", (TTime)"00:00:00");

	// ****************** Resultado ****************
	FormResultado->Button1Click(Form1); // Gera as tabelas

	FormResultado->Edit1->Text = arq->ReadString("Resultado", "Edit1", "");
	FormResultado->DateTimePicker2->Time = arq->ReadTime("Resultado",
		"DateTimePicker2", (TTime)"00:00:00");

	c = arq->ReadInteger("Resultado", "tabela_size", 0);
	for (int i = 0; i < c; i++) {
		// TStringGrid* tt;
		String in = IntToStr(i);
		tabela[i]->RowCount = arq->ReadInteger("Resultado", "Rowcount" + in, 0);
		tabela[i]->ColCount = arq->ReadInteger("Resultado", "Colcount" + in, 0);
		for (int col = 0; col < tabela[i]->ColCount; col++)
			for (int row = 0; row < tabela[i]->RowCount; row++)
				tabela[i]->Cells[col][row] = arq->ReadString("Resultado",
				"Cell" + in + "_" + IntToStr(col) + "_" + IntToStr(row),
				"");
		// tabela.push_back(tt);
	}

	c = arq->ReadInteger("Resultado", "nota_final_size", 0);
	for (int i = 0; i < c; i++) {
		// TLabel* la;
		String in = IntToStr(i);
		nota_final[i]->Caption = arq->ReadString("Resultao", "nota_final" + in,
			"");
		// nota_final.push_back(la);
	}
	FormResultado->Button2Click(Form1); // Calcula em FormResultado

	// ****************** Cabecalho ****************
	// String kkkl= arq->ReadString("Cabecalho", "RichEdit1", "");
	// FormCabecalho->RichEdit1->Lines->CommaText=kkkl;
	c = arq->ReadInteger("Cabecalho", "count", 0);
	for (int i = 0; i < c; i++) {
		String in = IntToStr(i);
		FormCabecalho->RichEdit1->Lines->Add(arq->ReadString("Cabecalho",
				"String" + in, ""));
	}

	delete arq;


	// --- Verifica a existencia das provas e configura tela principal ---

		int xtopo = Form1->Panel1->Top + Form1->Panel1->Height;
		int xtopo1 = Form1->BitBtn1->Top + Form1->BitBtn1->Height;

		// -- Prova escrita ---
		FormAbertura->Edit10->Visible=false;
		Form1->Panel2->Visible = false;
		Form1->BitBtn4->Visible = false;
		if (projeto.habilita_prova_escrita) {
		   Form1->Panel2->Visible = true;
		   Form1->Panel2->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel2->Height;
		   Form1->BitBtn4->Visible = true;
		   Form1->BitBtn4->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn4->Height;
		   FormAbertura->Edit10->Visible=true;
		   if (projeto.peso_escrita_fixo) {
				 FormAbertura->Edit10->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit10->Enabled=true;
		   }
		}
		// -- Prova titulos ---
		FormAbertura->Edit13->Visible=false;
		Form1->Panel6->Visible = false;
		Form1->BitBtn3->Visible = false;
		if (projeto.habilita_prova_titulos) {
		   Form1->Panel6->Visible = true;
		   Form1->Panel6->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel6->Height;
		   Form1->BitBtn3->Visible = true;
		   Form1->BitBtn3->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn3->Height;
		   FormAbertura->Edit13->Visible=true;
		   if (projeto.peso_titulos_fixo) {
				 FormAbertura->Edit13->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit13->Enabled=true;
		   }
		}
        // -- Prova didatica ---
		FormAbertura->Edit11->Visible=false;
		Form1->Panel3->Visible = false;
		Form1->BitBtn9->Visible = false;
		if (projeto.habilita_prova_didatica) {
		   Form1->Panel3->Visible = true;
		   Form1->Panel3->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel3->Height;
		   Form1->BitBtn9->Visible = true;
		   Form1->BitBtn9->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn9->Height;
		   FormAbertura->Edit11->Visible=true;
		   if (projeto.peso_didatica_fixo) {
				 FormAbertura->Edit11->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit11->Enabled=true;
		   }
		}
		// -- Prova memorial ---
		FormAbertura->Edit14->Visible=false;
		Form1->Panel4->Visible = false;
		Form1->BitBtn5->Visible = false;
		if (projeto.habilita_prova_memorial) {
		   Form1->Panel4->Visible = true;
		   Form1->Panel4->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel4->Height;
		   Form1->BitBtn5->Visible = true;
		   Form1->BitBtn5->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn5->Height;
		   FormAbertura->Edit14->Visible=true;
		   if (projeto.peso_memorial_fixo) {
				 FormAbertura->Edit14->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit14->Enabled=true;
		   }
		}
		// -- Prova entrevista ---
		FormAbertura->Edit12->Visible=false;
		Form1->Panel7->Visible = false;
		Form1->BitBtn11->Visible = false;
		if (projeto.habilita_prova_entrevista) {
		   Form1->Panel7->Visible = true;
		   Form1->Panel7->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel7->Height;
		   Form1->BitBtn11->Visible = true;
		   Form1->BitBtn11->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn11->Height;
		   FormAbertura->Edit12->Visible=true;
		   if (projeto.peso_entrevista_fixo) {
				 FormAbertura->Edit12->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit12->Enabled=true;
		   }
		}

		Form1->Panel5->Top = xtopo + 2;
		Form1->BitBtn6->Top = xtopo1 + 5;

        Form1->CB13->Enabled = projeto.habilita_prova_titulos;
		Form1->Button11->Enabled = projeto.habilita_prova_titulos;

		if (projeto.pesomaxclasse1 == projeto.pesominclasse1 && projeto.pesomaxclasse2
			== projeto.pesominclasse2 && projeto.pesomaxclasse3==projeto.pesominclasse3
			&& projeto.habilita_prova_titulos) {
			 CB15->Enabled=false;
			 Button10->Enabled=false;
		}
		else {
			CB15->Enabled=projeto.habilita_prova_titulos;
			Button10->Enabled=projeto.habilita_prova_titulos;
		}

	Form1->ScrollBox1->Enabled = true;
	Form1->ListView1->Enabled = true;
	Form1->ListView2->Enabled = true;
	Form1->ListView3->Enabled = true;
	Form1->BitBtn1->Enabled = true;
	Form1->BitBtn5->Enabled = true;
	Form1->BitBtn9->Enabled = true;
	Form1->BitBtn3->Enabled = true;
	Form1->BitBtn4->Enabled = true;
	Form1->BitBtn11->Enabled = true;
	Form1->BitBtn6->Enabled = true;

	SetCurrentDir(projeto.diretorio);

	FormLog->Memo1->Lines->Add("Fim do método AbrirGC3");
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Limpa(TObject *Sender) {

	FormLog->Memo1->Lines->Add("Iniciando Método Limpa");

	// Apaga e recria os forms
	Form1->Caption = "Gerenciador de Concursos Públicos - UNIPAMPA";
	projeto.nome = "";
	
	delete FormConfiguracao;
	Application->CreateForm(__classid(TFormConfiguracao), &FormConfiguracao);
	delete FormTitulos;
	Application->CreateForm(__classid(TFormTitulos), &FormTitulos);
	delete FormDidatica;
	Application->CreateForm(__classid(TFormDidatica), &FormDidatica);
	delete FormEscrita;
	Application->CreateForm(__classid(TFormEscrita), &FormEscrita);
	delete FormResultado;
	Application->CreateForm(__classid(TFormResultado), &FormResultado);
	delete FormDefesaProjeto;
	Application->CreateForm(__classid(TFormDefesaProjeto), &FormDefesaProjeto);
	delete FormEntrevista;
	Application->CreateForm(__classid(TFormEntrevista), &FormEntrevista);
	delete FormAbertura;
	Application->CreateForm(__classid(TFormAbertura), &FormAbertura);
	delete FormCabecalho;
	Application->CreateForm(__classid(TFormCabecalho), &FormCabecalho);
	delete FormDidaticaCandidatos;
	Application->CreateForm(__classid(TFormDidaticaCandidatos),
		&FormDidaticaCandidatos);
	delete FormDefesaProjeto_candidatos;
	Application->CreateForm(__classid(TFormDefesaProjeto_candidatos),
		&FormDefesaProjeto_candidatos);
	delete FormEntrevista_candidatos;
	Application->CreateForm(__classid(TFormEntrevista_candidatos),
		&FormEntrevista_candidatos);

	// CheckBoxes
    CB10->Checked = false;
	CB11->Checked = false;
	CB12->Checked = false;
	CB13->Checked = false;
	CB14->Checked = false;
	CB15->Checked = false;

	CB21->Checked = false;
	CB22->Checked = false;
	CB23->Checked = false;
	CB24->Checked = false;
	CB25->Checked = false;
	CB26->Checked = false;
	CB27->Checked = false;
	CB28->Checked = false;
	CB29->Checked = false;
	CB210->Checked = false;
	CB211->Checked = false;
	CB212->Checked = false;
	CB213->Checked = false;

	CB31->Checked = false;
	CB32->Checked = false;
	CB33->Checked = false;

	CB41->Checked = false;
	CB42->Checked = false;
	CB43->Checked = false;
	CB44->Checked = false;
	CB45->Checked = false;
	CB46->Checked = false;
	CB47->Checked = false;
	CB48->Checked = false;
	CB49->Checked = false;
	CB410->Checked = false;
	CB411->Checked = false;
	CB412->Checked = false;
	CB413->Checked = false;
	CB414->Checked = false;

	CB51->Checked = false;
	CB52->Checked = false;
	CB53->Checked = false;
	CB54->Checked = false;
	CB55->Checked = false;
	CB56->Checked = false;
	CB57->Checked = false;

	CB61->Checked = false;
	CB62->Checked = false;
	CB63->Checked = false;
	CB64->Checked = false;

	CB71->Checked = false;
	CB72->Checked = false;
	CB73->Checked = false;
	CB74->Checked = false;
	CB75->Checked = false;
	CB76->Checked = false;
	CB77->Checked = false;

	ListView1->Items->Clear();
	ListView2->Items->Clear();
	ListView3->Items->Clear();

	ScrollBox1->Enabled = false;
	ListView1->Enabled = false;
	ListView2->Enabled = false;
	ListView3->Enabled = false;

	pagina.clear();
	nota_final.clear();
	media_titulos.clear();
	media_didatica.clear();
	media_escrita.clear();
	media_defesa.clear();

	tabela.clear();
	nota_final.clear();
	candidato.clear();
	ponto_didatica.clear();
	ponto_escrita.clear();

	lab_def.clear();
	dat_def.clear();
	hor_def.clear();
	comp_def.clear();

	lab_ent.clear();
	dat_ent.clear();
	hor_ent.clear();
	comp_ent.clear();

	lab.clear();
	dat_sor.clear();
	hor_sor.clear();
	dat_apr.clear();
	hor_apr.clear();
	comp_sor.clear();
	comp_apr.clear();
	ponto.clear();

	nro_ata = 1;
	nro_lista = 1;

	// Seta os DateTimePicker com a data atual

	FormConfiguracao->DateTimePicker1->Date = Date();

	FormLog->Memo1->Lines->Add("Fim do método Limpa");
}

void __fastcall TForm1::Novo1Click(TObject *Sender) {
	FormLog->Memo1->Lines->Add("Iniciando Método Novo1Click");

	if (Application->MessageBox(L"Deseja criar um novo concurso?", L"Atenção",
			MB_YESNO) == ID_YES) {
		String infor = "Deseja salvar as informações do concurso " +
			projeto.nome + "?";
		if (Trim(projeto.nome) != "")
			if (Application->MessageBox(infor.c_str(), L"Atenção",
					MB_YESNO) == ID_YES) {
				Salvar2Click(Form1);
			}

		Limpa(Form1);

		FormConfiguracao->PageControl1->ActivePage = FormConfiguracao->Pag1;
		FormConfiguracao->Show();

		/*
		FormConfiguracao->LabeledEdit1->Text = "Ministério da Educação";
		FormConfiguracao->LabeledEdit5->Text = "Fundação Universidade Federal do Pampa";
		FormConfiguracao->LabeledEdit6->Text = "";
		FormConfiguracao->LabeledEdit7->Text = "";
		FormConfiguracao->LabeledEdit8->Text = "";
		FormConfiguracao->LabeledEdit2->Text = "";
		// - Pag2
		FormConfiguracao->Edit4->Text = FormConfiguracao->DirectoryListBox1->Directory;
		FormConfiguracao->Edit5->Text = "";
		// - Pag3
		FormConfiguracao->Edit1->Text = "";
		FormConfiguracao->Edit2->Text = "";
		FormConfiguracao->Edit6->Text = "";
		// List_Banca -- nao precisa
		// - Pag4
		FormConfiguracao->List_Candidatos->Clear();

		// ----------------- DefesaProjeto.cpp -------------------------
		FormDefesaProjeto->Edit1->Text = "";
		FormDefesaProjeto->ListBox2->Clear();
		FormDefesaProjeto->ListBox3->Clear();
		FormDefesaProjeto->ValueListEditor1->Strings->Clear();

		// ----------------- Didatica.cpp -------------------------
		FormDidatica->Edit1->Text = "";
		FormDidatica->Edit2->Text = "";
		FormDidatica->ListBox2->Clear();
		FormDidatica->ListBox3->Clear();
		FormDidatica->ValueListEditor1->Strings->Clear();

		// ----------------- escrita.cpp -------------------------
		FormEscrita->Edit2->Text = "";
		FormEscrita->ListBox2->Clear();
		FormEscrita->ListBox3->Clear();
		FormEscrita->ValueListEditor1->Strings->Clear();
		FormEscrita->ListBox1->Clear();
		FormEscrita->ListBox4->Clear();
		FormEscrita->CheckListBox1->Clear();
		FormEscrita->CheckListBox2->Clear();
		FormEscrita->Edit2->Text ="" ;
		FormEscrita->Edit1->Text ="" ;
		FormEscrita->CSpinEdit1->MaxValue = FormEscrita->ListBox1->Items->Count;
		FormEscrita->CSpinEdit1->Value = 0;
		FormEscrita->Edit3->Text = "";

		// ----------------- titulos.cpp -------------------------
		FormTitulos->Edit1->Text = "";
		FormTitulos->ComboBox1->Items->Clear();
		FormTitulos->ComboBox2->Items->Clear();

		// ------------------- Cabeçalho.cpp ----------------------------
		FormCabecalho->RichEdit1->Lines->Clear();

		// --------------------- Abertura.cpp -------------------------
		FormAbertura->CheckListBox1->Clear();
		FormAbertura->Edit1->Text = "";
		FormAbertura->Edit2->Text = "";
		FormAbertura->Edit3->Text = "";
		for (int col = 0; col < FormAbertura->StringGrid1->ColCount; col++)
		for (int row=1; row <  FormAbertura->StringGrid1->RowCount; row++) // NAO APAGA A PRIMEIRA LINHA
		{
		FormAbertura->StringGrid1->Cells[col][row] = "";
		}

		// -------------------- Resultado.cpp ----------------------------
		FormResultado->Edit1->Text = "";
		FormResultado->StringGrid1->RowCount = 1;

		// vector<TTabSheet*> pagina;  // nao precisa

		tabela.clear();
		//FormResultado->Button1Click(Form1); // Gera as tabelas em FormResultado
		//FormResultado->Button1Click(Form1); // Calcula em FormResultado

		nota_final.clear();

		// ------- Listagem.cpp ----------------------
		FormListagem->CheckBox1->Checked = false;
		FormListagem->CheckBox2->Checked = false;
		FormListagem->CheckBox3->Checked = false;
		FormListagem->CheckBox4->Checked = false;
		FormListagem->CheckBox5->Checked = false;
		FormListagem->CheckBox6->Checked = false;
		FormListagem->CheckBox7->Checked = false;
		FormListagem->CheckBox8->Checked = false;
		FormListagem->CheckBox9->Checked = false;
		FormListagem->CheckBox10->Checked = false;
		FormListagem->CheckBox11->Checked = false;
		FormListagem->CheckBox12->Checked = false;
		FormListagem->CheckBox13->Checked = false;
		FormListagem->CheckBox14->Checked = false;
		FormListagem->CheckBox15->Checked = false;
		FormListagem->CheckBox16->Checked = false;
		FormListagem->CheckBox17->Checked = false;
		FormListagem->CheckBox18->Checked = false;
		FormListagem->CheckBox19->Checked = false;
		FormListagem->CheckBox20->Checked = false;
		FormListagem->CheckBox21->Checked = false;
		FormListagem->CheckBox22->Checked = false;
		FormListagem->CheckBox23->Checked = false;
		FormListagem->CheckBox24->Checked = false;
		FormListagem->CheckBox25->Checked = false;
		FormListagem->CheckBox26->Checked = false;
		FormListagem->CheckBox27->Checked = false;
		FormListagem->CheckBox28->Checked = false;
		FormListagem->CheckBox29->Checked = false;
		FormListagem->CheckBox30->Checked = false;

		// ------------------- DefesaprojetoCandidatos.cpp ----------------

		FormDefesaProjeto_candidatos->ListBox2->Clear();
		FormDefesaProjeto_candidatos->ListBox1->Clear();

		// ------------------- DidaticaCandidatos.cpp ----------------
		FormDidaticaCandidatos->ListBox2->Clear();
		FormDidaticaCandidatos->ListBox1->Clear();

		candidato.clear();
		ponto_escrita.clear();
		ponto_didatica.clear();

		nro_ata=1;
		nro_lista=1;


		lab_def.clear();
		dat_def.clear();
		hor_def.clear();
		comp_def.clear();


		FormConfiguracao->PageControl1->ActivePage = FormConfiguracao->Pag1;
		FormConfiguracao->Show();
		 */
	}
	FormLog->Memo1->Lines->Add("Fim do método Novo1Click");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
	String infor = "Deseja salvar as informações do concurso " + projeto.nome +
		"?";
	if (Application->MessageBox(L"Deseja realmente fechar o programa?",
			L"Atenção", MB_YESNO) == ID_YES) {
		if (Trim(projeto.nome) != "")
			if (Application->MessageBox(infor.c_str(), L"Atenção",
					MB_YESNO) == ID_YES) {
				Salvar2Click(Form1);
			}
		Action = caFree;

	}
	else
		Action = caNone;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Sair1Click(TObject *Sender) {
	Form1->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Salvarcomo1Click(TObject *Sender) {
	// if (SaveDialog1->Execute())
	// {
	// projeto.nome = SaveDialog1->FileName;
	// }
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DiretrioAtual1Click(TObject *Sender) {
	String aa = GetCurrentDir();
	aa = "O diretório atual é " + aa;
	Application->MessageBox(aa.c_str(), L"Informação", 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Adicionarlinhastabeladedocumentosgerados1Click
	(TObject *Sender) {
	// StringGrid1->RowCount++;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1111Click(TObject *Sender) {
	FormAbertura->PageControl1->ActivePageIndex = 3;
	FormAbertura->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1112Click(TObject *Sender) {
	FormAbertura->PageControl1->ActivePageIndex = 0;
	FormAbertura->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) {
	FormAbertura->PageControl1->ActivePageIndex = 1;
	FormAbertura->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button25Click(FormAbertura);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender) {
	FormAbertura->PageControl1->ActivePageIndex = 2;
	FormAbertura->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button26Click(FormAbertura);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button8Click(FormEscrita);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button109Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 4;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button6Click(FormEscrita);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button187Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 2;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 0;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button35Click(FormEscrita);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 1;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 6;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 3;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button176Click(TObject *Sender) {
	FormResultado->PageControl1->ActivePageIndex = 0;
	FormResultado->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 7;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button33Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender) {
	FormEscrita->PageControl1->ActivePageIndex = 5;
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button65Click(TObject *Sender) {
	FormTitulos->PageControl1->ActivePageIndex = 0;
	FormTitulos->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button67Click(TObject *Sender) {
	FormTitulos->PageControl1->ActivePageIndex = 4;
	FormTitulos->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button69Click(TObject *Sender) {
	FormDidaticaCandidatos->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 1;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button155Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 2;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button21Click(FormDidatica);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender) {
	FormDidatica->Button9Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button12651Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 0;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button39Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 3;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 4;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender) {
	FormDidatica->Button8Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button12234Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 0;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button45Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 5;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button47Click(TObject *Sender) {
	FormDidatica->PageControl1->ActivePageIndex = 6;
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button49Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button34Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button71Click(TObject *Sender) {
	FormDefesaProjeto_candidatos->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Shape2MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
//	if (Panel2->Height == Shape2->Height)
//		Panel2->Height = 345;
//	else
//		Panel2->Height = Shape2->Height;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button51Click(TObject *Sender) {
	FormDefesaProjeto->Button8Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button80Click(TObject *Sender) {
	FormDefesaProjeto->PageControl1->ActivePageIndex = 2;
	FormDefesaProjeto->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button53Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button20Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button55Click(TObject *Sender) {
	FormDefesaProjeto->PageControl1->ActivePageIndex = 0;
	FormDefesaProjeto->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button82Click(TObject *Sender) {
	FormDefesaProjeto->PageControl1->ActivePageIndex = 1;
	FormDefesaProjeto->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button57Click(TObject *Sender) {
	FormDefesaProjeto->PageControl1->ActivePageIndex = 3;
	FormDefesaProjeto->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button84Click(TObject *Sender) {
	FormResultado->PageControl1->ActivePageIndex = 0;
	FormResultado->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button63Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button27Click(Form1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button59Click(TObject *Sender) {
	FormResultado->Show();
	Application->MessageBox(
		L"Entre com o local e o horário da divulgação do resultado\n e depois vá no menu \"Atas\" para gerar a Ata.", L"Aviso", 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button61Click(TObject *Sender) {
	FormResultado->Show();
	Application->MessageBox(
		L"Visualize a planilha de notas do candidato desejado\n e depois vá no menu \"Planilhas\" para gerar a planilha demonstrativa deste candidato.", L"Aviso", 0);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button86Click(TObject *Sender) {
	// FormLista->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ListView3SelectItem(TObject *Sender, TListItem *Item,
	bool Selected) {
	// Procura pelo nome do arquivo

	if (Item->SubItems->Count > 1)
		nome_arq_abrir = Item->SubItems->Strings[1];
	else
		nome_arq_abrir = "";

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Provaescrita1Click(TObject *Sender) {
	FormEscrita->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Provadidtica1Click(TObject *Sender) {
	FormDidatica->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Provadettulos1Click(TObject *Sender) {
	FormTitulos->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Provadedefesadememorial1Click(TObject *Sender) {
	FormDefesaProjeto->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Sessodeabertura1Click(TObject *Sender) {
	FormAbertura->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Resultado1Click(TObject *Sender) {
	FormResultado->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::aa1Click(TObject *Sender) {
	TMenuItem* a = (TMenuItem*)Sender;
	int xxx = a->Tag;

	if (arquivos_recentes[xxx] != "")
		AbrirGC3(arquivos_recentes[xxx]);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	Label11->Caption = GetCurrentDir();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender) {
	FormTitulos->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button36Click(FormAbertura);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button37Click(FormAbertura);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender) {
	Application->MessageBox(
		L"Defina os pesos das classes da prova de títulos\nna próxima tela e, após, clique em Fechar.\nInforme os pesos aos candidatos.", L"Atenção", 0);
	FormTitulos->ShowModal();
}
// ---------------------------------------------------------------------------



void __fastcall TForm1::Button24Click(TObject *Sender)
{
	FormEntrevista_candidatos->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	FormEntrevista->Button8Click(Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
	FormEntrevista->PageControl1->ActivePageIndex = 2;
	FormEntrevista->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	SelData->ShowModal();
	FormAtas->Button41Click(Form1);	  // aqui -------------------------
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	FormEntrevista->PageControl1->ActivePageIndex = 0;
	FormEntrevista->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
	FormEntrevista->PageControl1->ActivePageIndex = 1;
	FormEntrevista->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
	FormEntrevista->PageControl1->ActivePageIndex = 3;
	FormEntrevista->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn11Click(TObject *Sender)
{
	FormEntrevista->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
	FormAtualizar->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Verificaratualizao1Click(TObject *Sender)
{
	FormAtualizar->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
	FormAtas->Button42Click(this);
}
//---------------------------------------------------------------------------

