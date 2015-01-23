// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "Configuracao.h"
#include "Principal.h"
#include "Titulos.h"
#include "Escrita.h"
#include "Didatica.h"
#include "DefesaProjeto.h"
#include "Entrevista.h"
#include "Cabecalho.h"
#include "Abertura.h"
#include "Didatica_Candidatos.h"
#include "Resultado.h"
#include "DefesaProjeto_candidatos.h"
#include "Entrevista_candidatos.h"

// extern vector<tipo_examinador> examinador;
// extern vector<tipo_candidato> candidato;
// extern vector<tipo_ponto> ponto_escrita;
// extern vector<tipo_ponto> ponto_didatica;

// vector<float> notas;
String diretorio_temporario;
int candidatos_inscritos_opcao; // Usado somente na aba "Candidatos Inscritos", como op��o "Adiconar"(1) ou "Editar"(2)

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cdiroutl"
#pragma resource "*.dfm"
TFormConfiguracao *FormConfiguracao;

// ---------------------------------------------------------------------------
__fastcall TFormConfiguracao::TFormConfiguracao(TComponent* Owner) : TForm
(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TFormConfiguracao::Button3Click(TObject *Sender) {
	if (Application->MessageBox(
			L"Esta configura��o ir� alterar todos os documentos gerados a partir de agora,\nmas n�o modifica os anteriores. Deseja continuar?", L"Aten��o", MB_OKCANCEL) == IDOK)
	{



		// --- Examinadores
		// Examinador 0 (presidente)
		examinador[0].nome = Edit1->Text;
		examinador[0].sexo = RadioGroup2->ItemIndex;
		examinador[0].classe = RadioGroup1->ItemIndex;
		// examinador[0].presidente = true;
		String cargo;
		// Modificado versao 3.4
		if (examinador[0].sexo==0) {
			switch(examinador[0].classe) {
			case 0:
				cargo = "Prof. Dr.";
				break;
			case 1:
				cargo = "Prof. Me.";
				break;
			case 2:
				cargo = "Prof. Esp.";
				break;
			case 3:
				cargo = "Prof. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}
		else {
			switch(examinador[0].classe) {
			case 0:
				cargo = "Prof�. Dra.";
				break;
			case 1:
				cargo = "Prof�. Ma.";
				break;
			case 2:
				cargo = "Prof�. Esp.";
				break;
			case 3:
				cargo = "Prof�. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}


		examinador[0].nome_completo = cargo + " " + examinador[0].nome;

		// Examinador 1
		examinador[1].nome = Edit2->Text;
		examinador[1].sexo = RadioGroup6->ItemIndex;
		examinador[1].classe = RadioGroup5->ItemIndex;
		// examinador[1].presidente = true;
		// String cargo;
		if (examinador[1].sexo==0) {
			switch(examinador[1].classe) {
			case 0:
				cargo = "Prof. Dr.";
				break;
			case 1:
				cargo = "Prof. Me.";
				break;
			case 2:
				cargo = "Prof. Esp.";
				break;
			case 3:
				cargo = "Prof. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}
		else {
			switch(examinador[1].classe) {
			case 0:
				cargo = "Prof�. Dra.";
				break;
			case 1:
				cargo = "Prof�. Ma.";
				break;
			case 2:
				cargo = "Prof�. Esp.";
				break;
			case 3:
				cargo = "Prof�. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}
		examinador[1].nome_completo = cargo + " " + examinador[1].nome;

		// Examinador 2
		examinador[2].nome = Edit6->Text;
		examinador[2].sexo = RadioGroup8->ItemIndex;
		examinador[2].classe = RadioGroup7->ItemIndex;
		// examinador[2].presidente = true;
		// String cargo;
		if (examinador[2].sexo==0) {
			switch(examinador[2].classe) {
			case 0:
				cargo = "Prof. Dr.";
				break;
			case 1:
				cargo = "Prof. Me.";
				break;
			case 2:
				cargo = "Prof. Esp.";
				break;
			case 3:
				cargo = "Prof. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}
		else {
			switch(examinador[2].classe) {
			case 0:
				cargo = "Prof�. Dra.";
				break;
			case 1:
				cargo = "Prof�. Ma.";
				break;
			case 2:
				cargo = "Prof�. Esp.";
				break;
			case 3:
				cargo = "Prof�. Grad.";
				break;
			case 4:
				cargo = Trim(Edit7->Text);
				break;
			}
		}
		examinador[2].nome_completo = cargo + " " + examinador[2].nome;

		List_Banca->Items->Clear();
		List_Banca->Items->Add(examinador[0].nome);
		List_Banca->Items->Add(examinador[1].nome);
		List_Banca->Items->Add(examinador[2].nome);

		FormTitulos->ComboBox1->Items = List_Candidatos->Items;
		FormTitulos->ComboBox2->Items = List_Banca->Items;
		// FormTitulos->ComboBox2->Items = List_Banca->Items;
		int nro_cand = List_Candidatos->Items->Count;
		int nro_exam = List_Banca->Items->Count;
		// for (int h=0; h<nro_exam; h++)
		for (int j = 0; j < nro_cand; j++)
			for (int i = 0; i < 100; i++)
				candidato[j].nota_titulos[i] = 0;

		// Carrega o nome dos candidatos nos listbox de Escrita.cpp
		// FormEscrita->CheckListBox1->Items = List_Candidatos->Items;
		FormEscrita->ListBox4->Items = List_Candidatos->Items;
		// FormEscrita->CheckListBox2->Items = List_Candidatos->Items;
		// FormEscrita->ListBox2->Items = List_Candidatos->Items;
		FormEscrita->ListBox3->Items = List_Banca->Items;
		FormDidaticaCandidatos->ListBox1->Items = List_Candidatos->Items;
		FormDidatica->ListBox3->Items = List_Banca->Items;
		FormAbertura->CheckListBox1->Items = List_Candidatos->Items;
		FormDefesaProjeto_candidatos->ListBox1->Items = List_Candidatos->Items;
		FormDefesaProjeto->ListBox3->Items = List_Banca->Items;
		FormEntrevista_candidatos->ListBox1->Items = List_Candidatos->Items;
		FormEntrevista->ListBox3->Items = List_Banca->Items;
		for (int i = 0; i < nro_cand; i++) {
			// candidato[i].compareceu_realizacao_prova_escrita = true;
			// FormEscrita->CheckListBox1->Checked[i] = true;
			// candidato[i].compareceu_leitura_prova_escrita = true;
			// FormEscrita->CheckListBox2->Checked[i] = true;
		}



		projeto.diretorio = diretorio_temporario;

		SetCurrentDir(projeto.diretorio);
		String aaa = GetCurrentDir();
		projeto.nome = Edit5->Text;
		Form1->Caption = "Gerenciador de Concursos P�blicos - UNIPAMPA - " +
			projeto.nome + ".gcp";
		projeto.ministerio = LabeledEdit1->Text;
		projeto.universidade = LabeledEdit5->Text;
		projeto.centro = LabeledEdit6->Text;
		projeto.departamento = LabeledEdit8->Text;
		projeto.campus = LabeledEdit7->Text;
		projeto.area = LabeledEdit2->Text;
		projeto.edital = LabeledEdit3->Text;
		projeto.classe = RadioGroup4->ItemIndex;
		projeto.data_inicio = DateTimePicker1->Date;
		projeto.arq_regras = FileListBox1->Items->Strings[ListBox1->ItemIndex];

		// Carrega arquivo de regras
//		String exeFile = Application->ExeName;
//		String exePath = ExtractFilePath(exeFile);
//		String nome_arq2 = exePath + "regras\\" + projeto.arq_regras;
//		Form1->AbrirRegrasGCR(nome_arq2);
		//
        //	 ------------ Modificado a partir da versao 3.7, a qual procura as regras em diret�rio superior ao da aplica��o
		String exeFile = Application->ExeName;
		String exePath = ExtractFilePath(exeFile);
		exePath = exePath.SubString(1,exePath.Length()-2);
		String GCPPath = ExtractFilePath(exePath);
		String nome_arq2 = GCPPath + "regras\\" + projeto.arq_regras;
		Form1->AbrirRegrasGCR(nome_arq2);


		FormCabecalho->RichEdit1->Lines->Clear();
		FormCabecalho->RichEdit1->Lines->Add
			(AnsiUpperCase(LabeledEdit1->Text)); // Ministerio
		FormCabecalho->RichEdit1->Lines->Add
			(AnsiUpperCase(LabeledEdit5->Text)); // Universidade
		// FormCabecalho->RichEdit1->Lines->Add(AnsiUpperCase(LabeledEdit6->Text));  // Centro
		FormCabecalho->RichEdit1->Lines->Add
			("CAMPUS: " + AnsiUpperCase(LabeledEdit7->Text)); // Campus
		// FormCabecalho->RichEdit1->Lines->Add(AnsiUpperCase(LabeledEdit8->Text));  // Departamento

		//String categoria;
		projeto.categoria = RadioGroup4->Items->Strings[projeto.classe];
//		switch(projeto.classe) {
//		case 0:
//			projeto.categoria = "adjunto";
//			break;
//		case 1:
//			projeto.categoria = "";
//			break;
//		case 2:
//			projeto.categoria = "AUXILIAR";
//			break;
//		case 3:
//			projeto.categoria = "SUBSTITUTO";
//			break;
//		case 4:
//			projeto.categoria = "TEMPOR�RIO";
//			break;
//		default:
//			projeto.categoria = "?????";
//			break;
//		}
		FormCabecalho->RichEdit1->Lines->Add
			(AnsiUpperCase(projeto.tipo_concurso) + " PARA PROFESSOR "
			+ AnsiUpperCase(projeto.categoria));
		FormCabecalho->RichEdit1->Lines->Add
			("�REA: " + AnsiUpperCase(LabeledEdit2->Text)); // Area

		FormCabecalho->ShowModal();


	// --- Verifica a existencia das provas e configura tela principal ---

		int xtopo = Form1->Panel1->Top + Form1->Panel1->Height;
		int xtopo1 = Form1->BitBtn1->Top + Form1->BitBtn1->Height;

		// -- Prova escrita ---
		FormAbertura->Edit10->Text = "0,0";
		switch (projeto.ha_prova_escrita) {

		case 0: {
			projeto.habilita_prova_escrita=false;
			FormAbertura->Edit10->Visible=false;
			Form1->Panel2->Visible = false;
			Form1->BitBtn4->Visible = false;
		}
			break;
		case 1: {
		   Form1->Panel2->Visible = true;
		   Form1->Panel2->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel2->Height;
		   Form1->BitBtn4->Visible = true;
		   Form1->BitBtn4->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn4->Height;
		   projeto.habilita_prova_escrita = true;
		   FormAbertura->Edit10->Visible=true;
		   if (projeto.peso_escrita_fixo) {
				 FormAbertura->Edit10->Text = FormatFloat("0.0",projeto.peso_escrita*10);
				 FormAbertura->Edit10->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit10->Text = "0,0";
			   FormAbertura->Edit10->Enabled=true;
		   }
		   }
		   break;
		case 2:  {
			if (Application->MessageBox(L"Este concurso possui prova escrita?", L"Aten��o", MB_YESNO) == IDYES) {
				Form1->Panel2->Visible = true;
				Form1->Panel2->Top = xtopo + 2;
				xtopo = xtopo + 2 + Form1->Panel2->Height;
				Form1->BitBtn4->Visible = true;
				Form1->BitBtn4->Top = xtopo1 + 5;
				xtopo1 = xtopo1 + 5 + Form1->BitBtn4->Height;
				projeto.habilita_prova_escrita = true;
				FormAbertura->Edit10->Visible=true;
				if (projeto.peso_escrita_fixo) {
					FormAbertura->Edit10->Text = FormatFloat("0.0",projeto.peso_escrita*10);
					FormAbertura->Edit10->Enabled=false;
				}
				else {
					FormAbertura->Edit10->Text = "0,0";
					FormAbertura->Edit10->Enabled=true;
				}
			}
			else {
				 Form1->Panel2->Visible=false;
				 Form1->BitBtn4->Visible=false;
				 projeto.habilita_prova_escrita=false;
				 FormAbertura->Edit10->Visible=false;
			}
			}
			break;
		default:  {
			projeto.habilita_prova_escrita=false;
			FormAbertura->Edit10->Visible=false;

		}
			break;
		}

		// -- Prova titulos ---
		FormAbertura->Edit13->Text = "0,0";
		Form1->Panel6->Visible = false;
		Form1->BitBtn3->Visible = false;
		switch (projeto.ha_prova_titulos) {

		case 0: {
			projeto.habilita_prova_titulos=false;
			FormAbertura->Edit13->Visible=false;
		}
			break;
		case 1: {
		   Form1->Panel6->Visible = true;
		   Form1->Panel6->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel6->Height;
		   Form1->BitBtn3->Visible = true;
		   Form1->BitBtn3->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn3->Height;
		   projeto.habilita_prova_titulos = true;
		   FormAbertura->Edit13->Visible=true;
		   if (projeto.peso_titulos_fixo) {
				 FormAbertura->Edit13->Text = FormatFloat("0.0",projeto.peso_titulos*10);
				 FormAbertura->Edit13->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit13->Text = "0,0";
			   FormAbertura->Edit13->Enabled=true;
		   }
		   }
		   break;
		case 2:  {
			if (Application->MessageBox(L"Este concurso possui prova de t�tulos?", L"Aten��o", MB_YESNO) == IDYES) {
				Form1->Panel6->Visible = true;
				Form1->Panel6->Top = xtopo + 2;
				xtopo = xtopo + 2 + Form1->Panel6->Height;
				Form1->BitBtn3->Visible = true;
				Form1->BitBtn3->Top = xtopo1 + 5;
				xtopo1 = xtopo1 + 5 + Form1->BitBtn3->Height;
				projeto.habilita_prova_titulos = true;
				FormAbertura->Edit13->Visible=true;
				if (projeto.peso_titulos_fixo) {
					FormAbertura->Edit13->Text = FormatFloat("0.0",projeto.peso_titulos*10);
					FormAbertura->Edit13->Enabled=false;
				}
				else {
					FormAbertura->Edit13->Text = "0,0";
					FormAbertura->Edit13->Enabled=true;
				}
			}
			else {
				 Form1->Panel6->Visible = false;
				 Form1->BitBtn3->Visible = false;
				 projeto.habilita_prova_titulos=false;
				 FormAbertura->Edit13->Visible=false;
			}
			}
			break;
		default:  {
			projeto.habilita_prova_titulos=false;
			FormAbertura->Edit13->Visible=false;
		}
			break;
		}
		Form1->CB15->Enabled = projeto.habilita_prova_titulos;
		Form1->Button10->Enabled = projeto.habilita_prova_titulos;


		// -- Prova didatica ---
		Form1->Panel3->Visible = false;
		Form1->BitBtn9->Visible = false;
		FormAbertura->Edit11->Text = "0,0";
		switch (projeto.ha_prova_didatica) {

		case 0: {
			projeto.habilita_prova_didatica=false;
			FormAbertura->Edit11->Visible=false;
		}
			break;
		case 1: {
		   Form1->Panel3->Visible = true;
		   Form1->Panel3->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel3->Height;
		   Form1->BitBtn9->Visible = true;
		   Form1->BitBtn9->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn9->Height;
		   projeto.habilita_prova_didatica = true;
		   FormAbertura->Edit11->Visible=true;
		   if (projeto.peso_didatica_fixo) {
				 FormAbertura->Edit11->Text = FormatFloat("0.0",projeto.peso_didatica*10);
				 FormAbertura->Edit11->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit11->Text = "0,0";
			   FormAbertura->Edit11->Enabled=true;
		   }
		   }
		   break;
		case 2:  {
			if (Application->MessageBox(L"Este concurso possui prova did�tica?", L"Aten��o", MB_YESNO) == IDYES) {
				Form1->Panel3->Visible = true;
				Form1->Panel3->Top = xtopo + 2;
				xtopo = xtopo + 2 + Form1->Panel3->Height;
				Form1->BitBtn9->Visible = true;
				Form1->BitBtn9->Top = xtopo1 + 5;
				xtopo1 = xtopo1 + 5 + Form1->BitBtn9->Height;
				projeto.habilita_prova_didatica = true;
				FormAbertura->Edit11->Visible=true;
				if (projeto.peso_didatica_fixo) {
					FormAbertura->Edit11->Text = FormatFloat("0.0",projeto.peso_didatica*10);
					FormAbertura->Edit11->Enabled=false;
				}
				else {
					FormAbertura->Edit11->Text = "0,0";
					FormAbertura->Edit11->Enabled=true;
				}
			}
			else {
				 projeto.habilita_prova_didatica=false;
				 FormAbertura->Edit11->Visible=false;
			}
			}
			break;
		default:  {
			projeto.habilita_prova_didatica=false;
			FormAbertura->Edit11->Visible=false;
		}
			break;
		}


		// -- Prova memorial ---
		FormAbertura->Edit14->Text = "0,0";
		Form1->Panel4->Visible = false;
		 Form1->BitBtn5->Visible = false;
		switch (projeto.ha_prova_memorial) {

		case 0: {
			projeto.habilita_prova_memorial=false;
			FormAbertura->Edit14->Visible=false;
		}
			break;
		case 1: {
		   Form1->Panel4->Visible = true;
		   Form1->Panel4->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel4->Height;
		   Form1->BitBtn5->Visible = true;
		   Form1->BitBtn5->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn5->Height;
		   projeto.habilita_prova_memorial = true;
		   FormAbertura->Edit14->Visible=true;
		   if (projeto.peso_memorial_fixo) {
				 FormAbertura->Edit14->Text = FormatFloat("0.0",projeto.peso_memorial*10);
				 FormAbertura->Edit14->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit14->Text = "0,0";
			   FormAbertura->Edit14->Enabled=true;
		   }
		   }
		   break;
		case 2:  {
			if (Application->MessageBox(L"Este concurso possui prova de defesa de memorial de trajet�ria acad�mica?", L"Aten��o", MB_YESNO) == IDYES) {
				Form1->Panel4->Visible = true;
				Form1->Panel4->Top = xtopo + 2;
				xtopo = xtopo + 2 + Form1->Panel4->Height;
				Form1->BitBtn5->Visible = true;
				Form1->BitBtn5->Top = xtopo1 + 5;
				xtopo1 = xtopo1 + 5 + Form1->BitBtn5->Height;
				projeto.habilita_prova_memorial = true;
				FormAbertura->Edit14->Visible=true;
				if (projeto.peso_memorial_fixo) {
					FormAbertura->Edit14->Text = FormatFloat("0.0",projeto.peso_memorial*10);
					FormAbertura->Edit14->Enabled=false;
				}
				else {
					FormAbertura->Edit14->Text = "0,0";
					FormAbertura->Edit14->Enabled=true;
				}
			}
			else {
				 projeto.habilita_prova_memorial=false;
				 FormAbertura->Edit14->Visible=false;
			}
			}
			break;
		default:  {
			projeto.habilita_prova_memorial=false;
			FormAbertura->Edit14->Visible=false;
		}
			break;
		}

		// -- Prova entrevista ---
		FormAbertura->Edit12->Text = "0,0";
		Form1->Panel7->Visible = false;
		 Form1->BitBtn11->Visible = false;
		switch (projeto.ha_prova_entrevista) {

		case 0: {
			projeto.habilita_prova_entrevista=false;
			FormAbertura->Edit12->Visible=false;
		}
			break;
		case 1: {
		   Form1->Panel7->Visible = true;
		   Form1->Panel7->Top = xtopo + 2;
		   xtopo = xtopo + 2 + Form1->Panel7->Height;
		   Form1->BitBtn11->Visible = true;
		   Form1->BitBtn11->Top = xtopo1 + 5;
		   xtopo1 = xtopo1 + 5 + Form1->BitBtn11->Height;
		   projeto.habilita_prova_entrevista = true;
		   FormAbertura->Edit12->Visible=true;
		   if (projeto.peso_entrevista_fixo) {
				 FormAbertura->Edit12->Text = FormatFloat("0.0",projeto.peso_entrevista*10);
				 FormAbertura->Edit12->Enabled=false;
		   }
		   else {
			   FormAbertura->Edit12->Text = "0,0";
			   FormAbertura->Edit12->Enabled=true;
		   }
		   }
		   break;
		case 2:  {
			if (Application->MessageBox(L"Este concurso possui prova de entrevista?", L"Aten��o", MB_YESNO) == IDYES) {
				Form1->Panel7->Visible = true;
				Form1->Panel7->Top = xtopo + 2;
				xtopo = xtopo + 2 + Form1->Panel7->Height;
				Form1->BitBtn11->Visible = true;
				Form1->BitBtn11->Top = xtopo1 + 5;
				xtopo1 = xtopo1 + 5 + Form1->BitBtn11->Height;
				projeto.habilita_prova_entrevista = true;
				FormAbertura->Edit12->Visible=true;
				if (projeto.peso_entrevista_fixo) {
					FormAbertura->Edit12->Text = FormatFloat("0.0",projeto.peso_entrevista*10);
					FormAbertura->Edit12->Enabled=false;
				}
				else {
					FormAbertura->Edit12->Text = "0,0";
					FormAbertura->Edit12->Enabled=true;
				}
			}
			else {
				 projeto.habilita_prova_entrevista=false;
				 FormAbertura->Edit12->Visible=false;
			}
			}
			break;
		default:  {
			projeto.habilita_prova_entrevista=false;
			FormAbertura->Edit12->Visible=false;
		}
			break;
		}
		Form1->Panel5->Top = xtopo + 2;
		Form1->BitBtn6->Top = xtopo1 + 5;

		Form1->CB13->Enabled = projeto.habilita_prova_titulos;
		Form1->Button11->Enabled = projeto.habilita_prova_titulos;

		if (projeto.pesomaxclasse1 == projeto.pesominclasse1 && projeto.pesomaxclasse2
			== projeto.pesominclasse2 && projeto.pesomaxclasse3==projeto.pesominclasse3
			&& projeto.habilita_prova_titulos) {
			 Form1->CB15->Enabled=false;
			 Form1->Button10->Enabled=false;
		}
		else {
			Form1->CB15->Enabled=projeto.habilita_prova_titulos;
			Form1->Button10->Enabled=projeto.habilita_prova_titulos;
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

//		Atribui os pesos das provas � vari�vel projeto
		FormAbertura->Button1Click2(this);

		FormDidatica->Button1Click(FormAbertura);
		FormDefesaProjeto->Button1Click(FormAbertura);
		FormEntrevista->Button1Click(FormAbertura);
		FormResultado->Button1Click(FormConfiguracao);
		FormConfiguracao->Close();

	}
}


// ---------------------------------------------------------------------------
void __fastcall TFormConfiguracao::Button2Click(TObject *Sender) {

	/*
	candidatos_inscritos_opcao==1 -- Adicionar candidato
	candidatos_inscritos_opcao==2 -- Editar candidato
	outras opcoes -- nada acontece, torna invisivel o Panel1
	 */

	// ****** Adicionar candidato
	if (candidatos_inscritos_opcao == 1) {
		List_Candidatos->Items->Add(Edit3->Text);

		tipo_candidato ex_candidato;

		ex_candidato.nome = Edit3->Text;
		ex_candidato.sexo = RadioGroup3->ItemIndex;
		// ex_candidato.ausente = false;
		// ex_candidato.desistente = false;
		// ex_candidato.aprovado = false;
		ex_candidato.nascimento = DateTimePicker2->Date;

		candidato.push_back(ex_candidato);

		List_Candidatos->ItemIndex = List_Candidatos->Items->Count - 1;
		List_CandidatosClick(FormConfiguracao);

	}

	// ****** Editar candidato
	if (candidatos_inscritos_opcao == 2) {

		int i = List_Candidatos->ItemIndex;

		if (i >= 0) {
			candidato[i].nome = Edit3->Text;
			candidato[i].sexo = RadioGroup3->ItemIndex;
			candidato[i].nascimento = DateTimePicker2->Date;

			// Atualiza a lista
			List_Candidatos->Items->Clear();
			for (unsigned int j = 0; j < candidato.size(); j++) {
				List_Candidatos->Items->Add(candidato[j].nome);
			}
			if (List_Candidatos->Items->Count > 0)
				List_Candidatos->ItemIndex = i;
			List_CandidatosClick(FormConfiguracao);
		}

	}
	HabilitaPanel1(0);
	// Panel1->Enabled = false;
}

// ---------------------------------------------------------------------------
void __fastcall TFormConfiguracao::List_BancaClick(TObject *Sender) {
	/* int i = List_Banca->ItemIndex;

	Edit1->Text = examinador[i].nome;
	Edit2->Text = examinador[i].instituicao;
	RadioGroup1->ItemIndex = examinador[i].classe;
	RadioGroup2->ItemIndex = examinador[i].sexo;
	CheckBox1->Checked = examinador[i].presidente;

	//CheckBox2->Checked = examinador[i].suplente; */
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button5Click(TObject *Sender) {
	/* int i = List_Banca->ItemIndex;

	if (i >= 0)
	{
	examinador[i].nome = Edit1->Text;
	examinador[i].instituicao = Edit2->Text;
	examinador[i].classe = RadioGroup1->ItemIndex;
	examinador[i].sexo = RadioGroup2->ItemIndex;
	examinador[i].presidente = CheckBox1->Checked;
	//examinador[i].suplente = CheckBox2->Checked;
	String cargo;
	switch (RadioGroup1->ItemIndex)
	{
	case 0: cargo = "Prof. Tit. ";
	break;
	case 1: cargo = "Prof. Assoc. ";
	break;
	case 2: cargo = "Prof. Adj. ";
	break;
	case 3: cargo = "Prof. Assist. ";
	break;
	case 4: cargo = "Prof. Aux. ";
	break;
	}
	examinador[i].nome_completo = cargo + examinador[i].nome;
	// Atualiza a lista
	List_Banca->Items->Clear();
	for (int j=0; j<examinador.size() ; j++)
	{
	List_Banca->Items->Add(examinador[j].nome);
	}
	if (List_Banca->Items->Count > 0)
	List_Banca->ItemIndex = i;
	List_BancaClick(FormConfiguracao);
	} */
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button4Click(TObject *Sender) {
	List_CandidatosClick(FormConfiguracao);
	// HabilitaPanel1(0);
	// Panel1->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button1Click(TObject *Sender) {
	Edit3->Text = "";

	RadioGroup3->ItemIndex = 0;
	DateTimePicker2->Date = (TDate)"1/1/1975";

	HabilitaPanel1(1);
	// Panel1->Enabled = true;
	candidatos_inscritos_opcao = 1; // Adicionar

}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::List_CandidatosClick(TObject *Sender) {
	int i = List_Candidatos->ItemIndex;

	if (i >= 0) {
		Edit3->Text = candidato[i].nome;
		RadioGroup3->ItemIndex = candidato[i].sexo;
		DateTimePicker2->Date = candidato[i].nascimento;
	}
	else {
		Edit3->Text = "";
		RadioGroup3->ItemIndex = 0;
		DateTimePicker2->Date = (TDate)"1/1/1975";
	}

	HabilitaPanel1(0);
	// Panel1->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button6Click(TObject *Sender) {
	int i = List_Candidatos->ItemIndex;

	if (i >= 0) {
		candidato.erase(candidato.begin() + i);

		List_Candidatos->Items->Clear();

		for (unsigned int j = 0; j < candidato.size(); j++) {
			List_Candidatos->Items->Add(candidato[j].nome);
		}
		if (List_Candidatos->Items->Count > 0) {
			List_Candidatos->ItemIndex = 0;
			List_CandidatosClick(FormConfiguracao);
		}
	}
	i = List_Candidatos->ItemIndex;
	if (i < 0) {
		Edit3->Text = "";
		RadioGroup3->ItemIndex = 0;
		DateTimePicker2->Date = (TDate)"1/1/1975";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button7Click(TObject *Sender) {
	if (List_Candidatos->ItemIndex >= 0) {
		List_CandidatosClick(FormConfiguracao);
		candidatos_inscritos_opcao = 2;
		HabilitaPanel1(1);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button8Click(TObject *Sender) {
	if (Trim(Edit4->Text) != "") {
		if (!DirectoryExists(Edit4->Text)) {
			if (Application->MessageBox
				(L"Diret�rio n�o existe. Deseja cri�-lo?", L"Aten��o", MB_OKCANCEL) == IDOK)
			{
				if (!CreateDir(Edit4->Text)) {
					throw Exception("N�o foi poss�vel criar o diret�rios.");
				}
				else {
					diretorio_temporario = Edit4->Text;
					if (Trim(Edit5->Text) != "")
						PageControl1->ActivePage = Pag3;
					else
						Application->MessageBox
							(L"Escolha um nome para o projeto.", L"Erro", 0);
				}
			}
			else {
				Edit4->Text = DirectoryListBox1->Directory;
			}
		}
		else {
			diretorio_temporario = Edit4->Text;
			if (Trim(Edit5->Text) != "")
				PageControl1->ActivePage = Pag3;
			else
				Application->MessageBox(L"Escolha um nome para o projeto.",
				L"Erro", 0);

		}
	}
	else {
		Application->MessageBox(
			L"Escolha um diret�rio para gravar os documentos gerados.",
			L"Aten��o", MB_OK);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::DirectoryListBox1Change(TObject *Sender) {
	Edit4->Text = DirectoryListBox1->Directory;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button10Click(TObject *Sender) {
	if (projeto.diretorio != "")
		SetCurrentDir(projeto.diretorio);
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button9Click(TObject *Sender) {

	PageControl1->ActivePage = Pag2;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button12Click(TObject *Sender) {
	PageControl1->ActivePage = Pag1;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button14Click(TObject *Sender) {
	PageControl1->ActivePage = Pag2;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button13Click(TObject *Sender) {
	PageControl1->ActivePage = Pag4;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Button16Click(TObject *Sender) {
	PageControl1->ActivePage = Pag3;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::FormShow(TObject *Sender) {
	PageControl1->ActivePageIndex = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::Pag2Show(TObject *Sender) {
	Edit4->Text = DirectoryListBox1->Directory;
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::DirectoryListBox1Click(TObject *Sender) {
	DirectoryListBox1->OpenCurrent();
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::HabilitaPanel1(int op) {
	// Esta funcao habilita ou desabilita o Panel1
	// op=1 -- habilita
	// op=0 -- desabilita
	// op=outros -- nada acontece

	if (op == 1) {
		Panel1->Color = clBtnFace;
		Edit3->Color = clWindow;
		DateTimePicker2->Color = clWindow;
		Panel1->Enabled = true;
		Button2->Visible = true;
		Button4->Visible = true;
	}

	if (op == 0) {
		Panel1->Color = clMoneyGreen;
		Edit3->Color = clSilver;
		DateTimePicker2->Color = clSilver;
		Panel1->Enabled = false;
		Button2->Visible = false;
		Button4->Visible = false;
	}
}

void __fastcall TFormConfiguracao::Pag4Show(TObject *Sender) {
	List_CandidatosClick(FormConfiguracao);
}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::DriveComboBox1Change(TObject *Sender) {
	DirectoryListBox1->Drive = DriveComboBox1->Drive;

}
// ---------------------------------------------------------------------------

void __fastcall TFormConfiguracao::FormCreate(TObject *Sender) {
	// Verifica as regras disponiveis
//	String exeFile = Application->ExeName;
//	String exePath = ExtractFilePath(exeFile);
//	UnicodeString dir_regras = exePath + "regras";
	//	 ------------ Modificado a partir da versao 3.7, a qual procura as regras em diret�rio superior ao da aplica��o
	String exeFile = Application->ExeName;
	String exePath = ExtractFilePath(exeFile);
	exePath = exePath.SubString(1,exePath.Length()-2);
	String GCPPath = ExtractFilePath(exePath);
	UnicodeString dir_regras = GCPPath + "regras";

	FormConfiguracao->FileListBox1->Directory = dir_regras;
	ListBox1->Items->Clear();
	for (int i = 0; i < FormConfiguracao->FileListBox1->Items->Count; i++) {
		String nome_arq = dir_regras + "\\" +
			FormConfiguracao->FileListBox1->Items->Strings[i];
		TIniFile *iniregras = new TIniFile(nome_arq);
		String descricao = iniregras->ReadString("Principal", "descricao",
			"Erro");
		delete iniregras;
		ListBox1->Items->Add(descricao);
		// arquivo_regras[i]=nome_arq;
	}
	ListBox1->ItemIndex = 0;
}
// ---------------------------------------------------------------------------

