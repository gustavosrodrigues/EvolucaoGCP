// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal.h"
#include "Resultado.h"
#include "Atas.h"
#include "Dicas.h"
#include "PegaData.h"

#include <vector>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormResultado *FormResultado;
vector<TTabSheet*>pagina;
vector<TStringGrid*>tabela;
vector<TLabel*>nota_final;
vector<float>media_titulos;
vector<float>media_escrita;
vector<float>media_defesa;
vector<float>media_didatica;
vector<float>media_entrevista;

// float peso_escrita = 0.2;
// float peso_didatica = 0.3;
// float peso_defesa = 0.2;
// float peso_titulos = 0.3;

// ---------------------------------------------------------------------------
__fastcall TFormResultado::TFormResultado(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TFormResultado::Button1Click(TObject *Sender) {
	// Gera uma nova p�gina para cada candidato

	int aa = pagina.size();
	int bb = nota_final.size();
	int cc = tabela.size();
	for (unsigned int i = 0; i < pagina.size(); i++) {
		delete pagina[i];
		// delete (TStringGrid*) tabela[i];  N�o precisa deletar, pois a tabela pertence � p�gina
		// delete nota_final[i];             Mesmo caso anterior
	}

	pagina.clear();
	tabela.clear();
	nota_final.clear();
	media_titulos.clear();
	media_didatica.clear();
	media_escrita.clear();
	media_defesa.clear();
	media_entrevista.clear();

	pagina.resize(candidato.size());
	tabela.resize(candidato.size());
	nota_final.resize(candidato.size());
	media_titulos.resize(candidato.size());
	media_didatica.resize(candidato.size());
	media_escrita.resize(candidato.size());
	media_defesa.resize(candidato.size());
	media_entrevista.resize(candidato.size());

	StringGrid1->RowCount = 1;
	/* DONE : Verificar o c�lculo da nota da prova de t�tulos */
	for (unsigned int i = 0; i < candidato.size(); i++) {
		// Nova pagina
		pagina[i] = new TTabSheet(this);
		pagina[i]->PageControl = PageControl1;
		pagina[i]->Caption = candidato[i].nome;

		// Nova tabela
		tabela[i] = new TStringGrid(this);
		tabela[i]->Parent = pagina[i];
		tabela[i]->ColCount = 6;   // adicionada uma coluna para a prova entrevista
		tabela[i]->RowCount = 3 + 3;
		tabela[i]->Left = 40;
		tabela[i]->Top = 64;
		tabela[i]->Font->Size = 14;
		tabela[i]->Font->Style = TFontStyles() << fsBold;
		tabela[i]->Options = TGridOptions() << goEditing << goTabs <<
		goColMoving << goHorzLine << goVertLine << goFixedVertLine <<
		goFixedHorzLine;
		tabela[i]->Width = 900;
		tabela[i]->Height = 340;
		tabela[i]->FixedColor = clMoneyGreen;
		tabela[i]->EditorMode = true;
		tabela[i]->OnDrawCell = StringGrid1DrawCell;
		tabela[i]->OnExit = StringGrid1Exit;
		tabela[i]->OnSelectCell = StringGrid1SelectCell;
		// tabela[i]->OnGetEditMask = StringGrid1GetEditMask;     Comentado por AGG em 11/02/12 para compatibilidade com BCB2010

		// -- Configuracao das linhas
		for (int j = 0; j < tabela[i]->RowCount; j++) {
			tabela[i]->RowHeights[j] = 50;
		}
		for (int e = 0; e < 3; e++)
			tabela[i]->Cells[0][e + 1] = examinador[e].nome;
		tabela[i]->Cells[0][tabela[i]->RowCount - 2] = "M�DIA";
		tabela[i]->Cells[0][tabela[i]->RowCount - 1] = "M�DIA PONDERADA";
		// -- Configuracao das colunas
		tabela[i]->ColWidths[0] = 350; // Coluna do Nome do examinador - original 265
		for (int c = 1; c < tabela[i]->ColCount; c++)
			tabela[i]->ColWidths[c] = 130; // Demais colunas
		tabela[i]->Cells[0][0] = "Examinador";
		tabela[i]->Cells[1][0] = "T�tulos";
		tabela[i]->Cells[2][0] = "Escrita";
		tabela[i]->Cells[3][0] = "Did�tica";
		tabela[i]->Cells[4][0] = "Memorial";
		tabela[i]->Cells[5][0] = "Entrevista";

		// Determina a largura das linhas
		if (!projeto.habilita_prova_didatica) {
			  tabela[i]->ColWidths[3] = 0;
		}
		if (!projeto.habilita_prova_escrita) {
			  tabela[i]->ColWidths[2] = 0;
		}
		if (!projeto.habilita_prova_titulos) {
			  tabela[i]->ColWidths[1] = 0;
		}
		if (!projeto.habilita_prova_memorial) {
			  tabela[i]->ColWidths[4] = 0;
		}
		if (!projeto.habilita_prova_entrevista) {
			  tabela[i]->ColWidths[5] = 0;
		}
		tabela[i]->ColWidths[5];

		// Novo label  do nome do candiato
		TLabel* lab1 = new TLabel(this);
		lab1->Top = 24;
		lab1->Left = 40;
		lab1->Font->Size = 16;
		lab1->Font->Style = TFontStyles() << fsBold;
		lab1->Font->Color = clBlue;
		lab1->Caption = "Candidato: " + candidato[i].nome;
		lab1->Parent = pagina[i];
		lab1->AutoSize = true;

		// Novo label  da nota final
		TLabel* lab2 = new TLabel(this);
		lab2->Top = tabela[i]->Height + tabela[i]->Top + 25; ;
		lab2->Left = 40;
		lab2->Font->Size = 16;
		lab2->Font->Style = TFontStyles() << fsBold;
		lab2->Font->Color = clRed;
		lab2->Caption = "NOTA FINAL: ";
		lab2->Parent = pagina[i];
		lab2->AutoSize = true;

		// Novo label da nota final
		nota_final[i] = new TLabel(this);
		nota_final[i]->Top = tabela[i]->Height + tabela[i]->Top + 20;
		nota_final[i]->Left = 200;
		nota_final[i]->Font->Size = 20;
		nota_final[i]->Font->Style = TFontStyles() << fsBold;
		nota_final[i]->Font->Color = clRed;
		nota_final[i]->Caption = "";
		nota_final[i]->Parent = pagina[i];
		nota_final[i]->AutoSize = true;

		// StringGrid1 (resumo)
		StringGrid1->RowCount++;
		StringGrid1->FixedRows = 1;
		StringGrid1->Cells[0][0] = "NOME";
		StringGrid1->Cells[1][0] = "M�DIA";
		StringGrid1->Cells[2][0] = "POSI��O";

		StringGrid1->Cells[0][i + 1] = candidato[i].nome;
	}
	// Atualiza o ListBox1
	ListBox1->Items->Clear();
	ListBox1->Items->Add("Resumo");
	for (int i = 0; i < candidato.size(); i++)
		ListBox1->Items->Add(pagina[i]->Caption);
	ListBox1->ItemIndex = PageControl1->ActivePageIndex;
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::StringGrid1GetEditText(TObject *Sender,
	int ACol, int ARow, AnsiString &Value) {
	// Value = AnsiLowerCase(Value);
	/*
	TStringGrid *temp = (TStringGrid *)Sender;
	String valor = temp->Cells[ACol][ARow];
	//TEdit *temp = (TEdit *)Sender;
	double a;
	if (valor != "")
	{
	if (!(TryStrToFloat(valor, a)))
	{

	Application->MessageBox("Valor n�o num�rico", "Erro", 0);
	temp->Cells[ACol][ARow] = "0,00";
	}
	else
	{
	temp->Cells[ACol][ARow] = FormatFloat("0.00", StrToFloat(valor));
	}
	}

	 */

}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button2Click(TObject *Sender) {
	// Calcula as medias

	int linha_media = 3 + 1;
	int linha_ponderada = linha_media + 1;

	// float media_titulos, media_escrita, media_didatica, media_defesa;

	vector<float>nota_titulos;
	nota_titulos.resize(candidato.size());

	for (unsigned int i = 0; i < candidato.size(); i++) {
		float soma_titulos = 0;
		float soma_escrita = 0;
		float soma_didatica = 0;
		float soma_defesa = 0;
		float soma_entrevista = 0;
		float nv_titulos = 0;
		float nv_escrita = 0;
		float nv_didatica = 0;
		float nv_defesa = 0;
		float nv_entrevista = 0;

		int e;
		for (e = 0; e < 3; e++) {
			// Media da prova escrita
			if (Trim(tabela[i]->Cells[1][e + 1]) != "") {
				soma_titulos = soma_titulos + StrToFloat
					(tabela[i]->Cells[1][e + 1]);
				nv_titulos++;
			}
			if (Trim(tabela[i]->Cells[2][e + 1]) != "") {
				soma_escrita = soma_escrita + StrToFloat
					(tabela[i]->Cells[2][e + 1]);
				nv_escrita++;
			}
			if (Trim(tabela[i]->Cells[3][e + 1]) != "") {
				soma_didatica = soma_didatica + StrToFloat
					(tabela[i]->Cells[3][e + 1]);
				nv_didatica++;
			}
			if (Trim(tabela[i]->Cells[4][e + 1]) != "") {
				soma_defesa = soma_defesa + StrToFloat
					(tabela[i]->Cells[4][e + 1]);
				nv_defesa++;
			}
			if (Trim(tabela[i]->Cells[5][e + 1]) != "") {
				soma_entrevista = soma_entrevista + StrToFloat
					(tabela[i]->Cells[5][e + 1]);
				nv_entrevista++;
			}

		}

		if (nv_titulos != 0) {
			media_titulos[i] = soma_titulos / nv_titulos;
			tabela[i]->Cells[1][linha_media] = FormatFloat("0.00",
				media_titulos[i]);
		}
		else {
			media_titulos[i] = 0;
			tabela[i]->Cells[1][linha_media] = "0,00";
		}
		// nota_titulos[i] = media_titulos[i];

		if (nv_escrita != 0) {
			media_escrita[i] = soma_escrita / nv_escrita;
			tabela[i]->Cells[2][linha_media] = FormatFloat("0.00",
				media_escrita[i]);
		}
		else {
			media_escrita[i] = 0;
			tabela[i]->Cells[2][linha_media] = "0,00";
		}

		if (nv_didatica != 0) {
			media_didatica[i] = soma_didatica / nv_didatica;
			tabela[i]->Cells[3][linha_media] = FormatFloat("0.00",
				media_didatica[i]);
		}
		else {
			media_didatica[i] = 0;
			tabela[i]->Cells[3][linha_media] = "0,00";
		}

		if (nv_defesa != 0) {
			media_defesa[i] = soma_defesa / nv_defesa;
			tabela[i]->Cells[4][linha_media] = FormatFloat("0.00",
				media_defesa[i]);
		}
		else {
			media_defesa[i] = 0;
			tabela[i]->Cells[4][linha_media] = "0,00";
		}

		if (nv_entrevista != 0) {
			media_entrevista[i] = soma_entrevista / nv_entrevista;
			tabela[i]->Cells[5][linha_media] = FormatFloat("0.00",
				media_entrevista[i]);
		}
		else {
			media_entrevista[i] = 0;
			tabela[i]->Cells[5][linha_media] = "0,00";
		}

		// Nota final (media ponderada)
		tabela[i]->Cells[2][linha_ponderada] = FormatFloat("0.00",
			media_escrita[i] * projeto.peso_escrita_final);
		tabela[i]->Cells[3][linha_ponderada] = FormatFloat("0.00",
			media_didatica[i] * projeto.peso_didatica_final);
		tabela[i]->Cells[4][linha_ponderada] = FormatFloat("0.00",
			media_defesa[i] * projeto.peso_memorial_final);
		tabela[i]->Cells[1][linha_ponderada] = FormatFloat("0.00",
			media_titulos[i] * projeto.peso_titulos_final);
		tabela[i]->Cells[5][linha_ponderada] = FormatFloat("0.00",
			media_entrevista[i] * projeto.peso_entrevista_final);

	}
	/* // Retirado por causa da IN-6
	// Calculo da nota final da prova de titulos
	float maior = 0;
	for (unsigned int i = 0; i<candidato.size(); i++)
	{
	// Procura a maior media
	if (media_titulos[i]>maior)
	maior = media_titulos[i];
	}
	for (unsigned int i = 0; i<candidato.size(); i++)
	{
	if (maior!=0)
	tabela[i]->Cells[1][linha_ponderada] = FormatFloat("0.00", 10*media_titulos[i]*peso_titulos/maior);
	else
	tabela[i]->Cells[1][linha_ponderada] = "0,00";
	}
	 */
	// Calculo da media final do candiato
	nota_final.resize(candidato.size());
	for (unsigned int i = 0; i < candidato.size(); i++) {

		float n_tit = StrToFloat(Trim(tabela[i]->Cells[1][linha_ponderada]));
		float n_esc = StrToFloat(Trim(tabela[i]->Cells[2][linha_ponderada]));
		float n_did = StrToFloat(Trim(tabela[i]->Cells[3][linha_ponderada]));
		float n_def = StrToFloat(Trim(tabela[i]->Cells[4][linha_ponderada]));
		float n_ent = StrToFloat(Trim(tabela[i]->Cells[5][linha_ponderada]));
		float n_final = n_tit + n_esc + n_did + n_def + n_ent;

		nota_final[i]->Caption = FormatFloat("0.00", n_final);
		StringGrid1->Cells[1][i + 1] = nota_final[i]->Caption;
	}

	// Calculo das posicoes
	int colocacao = 1;
	vector<int>pos;
	vector<bool>pronto;
	pos.resize(candidato.size());
	pronto.resize(candidato.size());
	for (unsigned int i = 0; i < candidato.size(); i++) {
		pronto[i] = false;
	}

	bool existe = true;
	while (existe) {
		float maior = -1;
		int indice_maior = -1;
		for (unsigned int i = 0; i < candidato.size(); i++) {
			if (!pronto[i]) {
				String ttemp = StringGrid1->Cells[1][i + 1];
				float nota = StrToFloat(StringGrid1->Cells[1][i + 1]);
				// if (nota == maior)   // Verifica o empate
				if (nota - maior < 0.001 && nota - maior > -0.001)
				// Verifica o empate
				{
					if (indice_maior >= 0) {
						float n_tit = StrToFloat
							(Trim(tabela[i]->Cells[1][linha_ponderada]));
						float n_esc = StrToFloat
							(Trim(tabela[i]->Cells[2][linha_ponderada]));
						float n_did = StrToFloat
							(Trim(tabela[i]->Cells[3][linha_ponderada]));
						float n_tit_maior = StrToFloat
							(Trim(tabela[indice_maior]->Cells[1]
								[linha_ponderada]));
						float n_esc_maior = StrToFloat
							(Trim(tabela[indice_maior]->Cells[2]
								[linha_ponderada]));
						float n_did_maior = StrToFloat
							(Trim(tabela[indice_maior]->Cells[3]
								[linha_ponderada]));

						if (n_tit > n_tit_maior)
							indice_maior = i;
						else if (n_tit == n_tit_maior)
							if (n_did > n_did_maior)
								indice_maior = i;
							else if (n_did == n_did_maior)
								if (n_esc > n_esc_maior)
									indice_maior = i;
								else if (n_esc == n_esc_maior)
									if
										(candidato[i].nascimento < candidato
										[indice_maior].nascimento)
										indice_maior = i;
					}
					else {
						indice_maior = i;
						maior = nota;
					}
				}
				if (nota > maior) {
					indice_maior = i;
					maior = nota;
				}

			}
		}
		if (indice_maior >= 0) {
			float m_esc = StrToFloat
				(Trim(tabela[indice_maior]->Cells[2][linha_media]));
			float m_did = StrToFloat
				(Trim(tabela[indice_maior]->Cells[3][linha_media]));
			float m_mem = StrToFloat
				(Trim(tabela[indice_maior]->Cells[4][linha_media]));
			float m_tit = StrToFloat
				(Trim(tabela[indice_maior]->Cells[1][linha_media]));
			float m_ent = StrToFloat
				(Trim(tabela[indice_maior]->Cells[5][linha_media]));
			float nota = StrToFloat(StringGrid1->Cells[1][indice_maior + 1]);
			// float m_fin = StrToFloat(Trim(tabela[indice_maior]->Cells[3][linha_media]));

			/* if (m_esc >= 7 && m_did >= 7 && nota >= 7)
			// **** Modificado RES 01/2010 ****
			{
			pos[indice_maior] = colocacao;
			colocacao++;
			}
			 */
			bool classificado = true;
			// Verifica escrita
			if (projeto.escrita_eliminatoria && projeto.habilita_prova_escrita) {
				if (m_esc < projeto.nota_minima_escrita) {
					classificado = false;
				}
			}
			// Verifica didatica
			if (projeto.didatica_eliminatoria && projeto.habilita_prova_didatica) {
				if (m_did < projeto.nota_minima_didatica) {
					classificado = false;
				}
			}
			// Verifica memorial
			if (projeto.memorial_eliminatoria && projeto.habilita_prova_memorial) {
				if (m_mem < projeto.nota_minima_memorial) {
					classificado = false;
				}
			}
			// Verifica titulos
			if (projeto.titulos_eliminatoria && projeto.habilita_prova_titulos) {
				if (m_tit < projeto.nota_minima_titulos) {
					classificado = false;
				}
			}
			// Verifica entrevista
			if (projeto.entrevista_eliminatoria && projeto.habilita_prova_entrevista) {
				if (m_ent < projeto.nota_minima_entrevista) {
					classificado = false;
				}
			}
			// Verifica nota final
			if (projeto.nota_final_eliminatoria) {
				if (nota < projeto.nota_minima_geral) {
					classificado = false;
				}
			}
			if (classificado) {
				pos[indice_maior] = colocacao;
				colocacao++;
			}

			pronto[indice_maior] = true;

		}
		// Verifica se ainda existe algu�m n�o colocado
		existe = false;
		for (unsigned int i = 0; i < candidato.size(); i++) {
			if (!pronto[i])
				existe = true;
		}
	}

	// Coloca a posi��o no StringGrid
	for (unsigned int i = 0; i < candidato.size(); i++) {

		float m_ent = StrToFloat(Trim(tabela[i]->Cells[5][linha_media]));
		float m_mem = StrToFloat(Trim(tabela[i]->Cells[4][linha_media]));
		float m_tit = StrToFloat(Trim(tabela[i]->Cells[1][linha_media]));
		float m_esc = StrToFloat(Trim(tabela[i]->Cells[2][linha_media]));
		float m_did = StrToFloat(Trim(tabela[i]->Cells[3][linha_media]));
		float nota = StrToFloat(StringGrid1->Cells[1][i + 1]);
		// if (StrToFloat(StringGrid1->Cells[1][i+1]) >=6)
		/* if (m_esc >= 7 && m_did >= 7 && nota >= 7)
		// **** Modificado RES 01/2010 ****
		StringGrid1->Cells[2][i + 1] = FormatFloat("0", pos[i]) + "�";
		else
		StringGrid1->Cells[2][i + 1] = "Eliminado";
		 */
		bool classificado = true;
		// Verifica escrita
		if (projeto.escrita_eliminatoria && projeto.habilita_prova_escrita) {
			if (m_esc < projeto.nota_minima_escrita) {
				classificado = false;
			}
		}
		// Verifica didatica
		if (projeto.didatica_eliminatoria && projeto.habilita_prova_didatica) {
			if (m_did < projeto.nota_minima_didatica) {
				classificado = false;
			}
		}
		// Verifica memorial
		if (projeto.memorial_eliminatoria && projeto.habilita_prova_memorial) {
			if (m_mem < projeto.nota_minima_memorial) {
				classificado = false;
			}
		}
		// Verifica titulos
		if (projeto.titulos_eliminatoria && projeto.habilita_prova_titulos) {
			if (m_tit < projeto.nota_minima_titulos) {
				classificado = false;
			}
		}
		// Verifica entrevista
		if (projeto.entrevista_eliminatoria && projeto.habilita_prova_entrevista) {
			if (m_ent < projeto.nota_minima_entrevista) {
				classificado = false;
			}
		}
		// Verifica nota final
		if (projeto.nota_final_eliminatoria) {
			if (nota < projeto.nota_minima_geral) {
				classificado = false;
			}
		}
		if (classificado)
			StringGrid1->Cells[2][i + 1] = FormatFloat("0", pos[i]) + "�";
		else
			StringGrid1->Cells[2][i + 1] = "Eliminado";

	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::StringGrid1DrawCell(TObject *Sender, int ACol,
	int ARow, const TRect &Rect, TGridDrawState State) {

	DecimalSeparator = ',';
	TStringGrid *temp = (TStringGrid*)Sender;

	if (Trim(temp->Cells[ACol][ARow]) != "")
		if (ARow > 0)
			if (ACol > 0) {
				float a;
				if (!(TryStrToFloat(temp->Cells[ACol][ARow], a))) {
					Application->MessageBox(L"Valor n�o num�rico", L"Erro", 0);
					temp->Cells[ACol][ARow] = "0,00";
				}
				else {
					// temp->Cells[ACol][ARow] = FormatFloat("0.00", StrToFloat(temp->Cells[ACol][ARow]));
					float nota_vermelha = 0;
					if (ACol == 1) { // titulos
						if (projeto.titulos_eliminatoria) {
							nota_vermelha = projeto.nota_minima_titulos;
						}
					}
					if (ACol == 2) { // escrita
						if (projeto.escrita_eliminatoria) {
							nota_vermelha = projeto.nota_minima_escrita;
						}
					}
					if (ACol == 3) { // didatica
						if (projeto.didatica_eliminatoria) {
							nota_vermelha = projeto.nota_minima_didatica;
						}
					}
					if (ACol == 4) { // memorial
						if (projeto.memorial_eliminatoria) {
							nota_vermelha = projeto.nota_minima_memorial;
						}
					}
					if (ACol == 5) { // entrevista
						if (projeto.entrevista_eliminatoria) {
							nota_vermelha = projeto.nota_minima_entrevista;
						}
					}

					if (ARow < temp->RowCount - 1) {
						if (StrToFloat(temp->Cells[ACol][ARow]) < nota_vermelha)
						// **** Modificado IN-6 - OK RES 01/2010****
						{
							temp->Canvas->Font->Color = clRed;
							temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top,
								temp->Cells[ACol][ARow]);
							// temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top, FormatFloat("0.00", StrToFloat(temp->Cells[ACol][ARow])));
						}
						else {
							temp->Canvas->Font->Color = clBlack;
							// temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top, FormatFloat("0.00", StrToFloat(temp->Cells[ACol][ARow]))); // adicionado
						}
					}
					else {
						temp->Canvas->Font->Color = clBlue;
						temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top,
							temp->Cells[ACol][ARow]);
						// temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top, FormatFloat("0.00", StrToFloat(temp->Cells[ACol][ARow])));
					}
				}
			}
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::StringGrid1GetEditMask(TObject *Sender,
	int ACol, int ARow, AnsiString &Value)

{

	/* DecimalSeparator = ',';
	TStringGrid *temp = (TStringGrid *)Sender;
	//if (Trim(temp->Cells[ACol][ARow]) != "")

	float a;
	if ((TryStrToFloat(temp->Cells[ACol][ARow], a)))
	if (ARow>0)
	if (ACol>0)
	//Value = "0,00;1;0";
	temp->Cells[ACol][ARow] = FormatFloat("0.00", StrToFloat(temp->Cells[ACol][ARow]));

	 */
}

// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TFormResultado::StringGrid1Exit(TObject *Sender) {
	Button2Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::StringGrid1SelectCell(TObject *Sender,
	int ACol, int ARow, bool &CanSelect) {
	Button2Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button5Click(TObject *Sender) {
	FormAtas->Button27Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button3Click(TObject *Sender) {

	FormDicas->PageControl1->ActivePage = FormDicas->TabResultado;
	FormDicas->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::PageControl1Change(TObject *Sender) {
	if (PageControl1->ActivePageIndex > 0) {
		Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1->Enabled =
			true; // Botao de geracao da planilha demonstrativa deste candidato
		ListBox1->ItemIndex = PageControl1->ActivePageIndex;
	}
	else {
		Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1->Enabled =
			false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button6Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button4Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button30Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button7Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button31Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button8Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button32Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button9Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button33Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::Button10Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button34Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::FormShow(TObject *Sender) {
	// Atualiza o ListBox

	Button2Click(FormResultado);
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::
	Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1Click
	(TObject *Sender) {
	if (FormResultado->PageControl1->ActivePageIndex != 0) {
		SelData->ShowModal();
		FormAtas->Button22Click(FormResultado);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::ListBox1Click(TObject *Sender) {
	PageControl1->ActivePageIndex = ListBox1->ItemIndex;
}
// ---------------------------------------------------------------------------

void __fastcall TFormResultado::
	Gerarplanilhademonstrativadasnotasfinaisdetodososcandidatos1Click
	(TObject *Sender)

{
	SelData->ShowModal();
	int indiceatual = FormResultado->PageControl1->ActivePageIndex;
	for (int i = 1; i < FormResultado->PageControl1->PageCount; i++) {
		FormResultado->PageControl1->ActivePageIndex = i;
		FormAtas->Button22Click(FormResultado);
	}
	FormResultado->PageControl1->ActivePageIndex = indiceatual;

}
// ---------------------------------------------------------------------------
