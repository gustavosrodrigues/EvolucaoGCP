// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>

#include "Titulos.h"
#include "Principal.h"
#include "Atas.h"
#include "Dicas.h"
#include "PegaData.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTitulos *FormTitulos;

// ---------------------------------------------------------------------------
__fastcall TFormTitulos::TFormTitulos(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::E001Exit(TObject *Sender) {
	/*
	TEdit *temp = (TEdit*)Sender;
	double a;
	if (!(TryStrToFloat(temp->Text, a))) {
		Application->MessageBox(L"Valor n�o num�rico", L"Erro", 0);
		temp->Text = "0";
	}

	// Item I.1.7 a I.1.9 - n�o cumulativos    - ok RES 01/2010
	if (temp->Tag == 6 || temp->Tag == 7 || temp->Tag == 8) {
		int cont = 0;
		if (StrToFloat(temp->Text) > 1) {
			Application->MessageBox(
				L"Items 7 a 9 n�o s�o cumulativos! Verifique as quantidades!",
				L"Aten��o", 0);
			temp->Text = "1";
		}
	}

	// Item I.1.7 n�o cumulativo com os itens 1 ou 2  - ok RES 01/2010
	if (temp->Tag == 6) {
		if (Edit_quantidade[0]->Text != "0" || Edit_quantidade[1]->Text != 0) {
			Application->MessageBox(
				L"Item 7 n�o � cumulativo com �tens 1 ou 2! Verifique as quantidades!"
				, L"Aten��o", 0);
			temp->Text = "0";
		}
	}

	// Item I.3. 1 - maximo 8 pontos  - ok RES 01/2010
	if (temp->Tag == 30) {
		float z = StrToFloat(Edit_quantidade[temp->Tag]->Text);
		if (z > 8) {
			Application->MessageBox(L"M�ximo 8 pontos no item I.3.1", L"Erro",
				0);
			temp->Text = "0";
		}
	}

	// Item I.3.6 - maximo 10 orientados  - ok RES 01/2010
	if (temp->Tag == 35) {
		float z = StrToFloat(Edit_quantidade[temp->Tag]->Text);
		if (z > 10) {
			Application->MessageBox(L"M�ximo 10 orienta��es no item I.3.6",
				L"Erro", 0);
			temp->Text = "0";
		}
	}

	// Item I.3.7 - maximo 20 orientados  - ok RES 01/2010
	if (temp->Tag == 36) {
		float z = StrToFloat(Edit_quantidade[temp->Tag]->Text);
		if (z > 20) {
			Application->MessageBox(L"M�ximo 20 orienta��es no item I.3.7",
				L"Erro", 0);
			temp->Text = "0";
		}
	}

	int ic = ComboBox1->ItemIndex;

	float nota = StrToFloat(temp->Text);
	int itag = temp->Tag;

	if (ic >= 0)
		candidato[ic].nota_titulos[itag] = nota;

	Button1Click(FormTitulos); */
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Button1Click(TObject *Sender) {

	int candidato_atual = ComboBox1->ItemIndex;

	StringGrid1->RowCount = 1;

	int linha = 1;

	for (int k = 0; k < ComboBox1->Items->Count; k++) {
		StringGrid1->RowCount++;
		ComboBox1->ItemIndex = k;

		// Carrega as notas nos TEdit
		// for (int i = 0; i<=63; i++)
		// {
		// Edit_quantidade[i]->Text = FormatFloat("0.#",candidato[k].nota_titulos[i]);
		// }

		CalculaPontuacaoTotal(k, candidato_atual);

		// Atualiza StringGrid
		StringGrid1->Cells[0][linha] = candidato[k].nome;
		StringGrid1->Cells[1][linha] = FormatFloat("0.00",
			candidato[k].pontuacao_I1);
		StringGrid1->Cells[2][linha] = FormatFloat("0.00",
			candidato[k].pontuacao_I2);
		StringGrid1->Cells[3][linha] = FormatFloat("0.00",
			candidato[k].pontuacao_I3);
		linha++;

	}
	StringGrid1->Cells[0][0] = "Candidato";
	StringGrid1->Cells[1][0] = "I.1";
	StringGrid1->Cells[2][0] = "I.2";
	StringGrid1->Cells[3][0] = "I.3";
	StringGrid1->FixedRows = 1;

	ComboBox1->ItemIndex = candidato_atual;
	// Recarrega as notas nos TEdit
	// for (int i = 0; i<=63; i++)
	// {
	// Edit_quantidade[i]->Text = FormatFloat("0.#",candidato[candidato_atual].nota_titulos[i]);
	// }

	// ------------- Calculo da nota final ------------
	float peso_I1, peso_I2, peso_I3;
	peso_I1 = StrToFloat(Edit2->Text);
	peso_I2 = StrToFloat(Edit3->Text);
	peso_I3 = StrToFloat(Edit4->Text);

	float ref_I1, ref_I2, ref_I3;
	ref_I1 = StrToFloat(Edit8->Text);
	ref_I2 = StrToFloat(Edit9->Text);
	ref_I3 = StrToFloat(Edit10->Text);

	// Determina a maior pontuacao I1
	float maior_I1 = 0;
	for (int lin = 1; lin < StringGrid1->RowCount; lin++) {
		float m = StrToFloat(StringGrid1->Cells[1][lin]);
		if (m > maior_I1)
			maior_I1 = m;
	}
	// Determina a maior pontuacao I2
	float maior_I2 = 0;
	for (int lin = 1; lin < StringGrid1->RowCount; lin++) {
		float m = StrToFloat(StringGrid1->Cells[2][lin]);
		if (m > maior_I2)
			maior_I2 = m;
	}
	// Determina a maior pontuacao I1
	float maior_I3 = 0;
	for (int lin = 1; lin < StringGrid1->RowCount; lin++) {
		float m = StrToFloat(StringGrid1->Cells[3][lin]);
		if (m > maior_I3)
			maior_I3 = m;
	}

	float pontuacao_I1, pontuacao_I2, pontuacao_I3;
	pontuacao_I1 = StrToFloat(Edit93->Text);
	pontuacao_I2 = StrToFloat(Edit94->Text);
	pontuacao_I3 = StrToFloat(Edit95->Text);

	// Nota no item
	float nota_I1 = 0;
	float nota_I2 = 0;
	float nota_I3 = 0;
	float nota_pond_I1 = 0;
	float nota_pond_I2 = 0;
	float nota_pond_I3 = 0;

	if (maior_I1 > 0) {
		nota_I1 = pontuacao_I1 * ref_I1 / maior_I1;
		Edit11->Text = FormatFloat("0.00", nota_I1);
		nota_pond_I1 = nota_I1 * peso_I1;
		Edit5->Text = FormatFloat("0.00", nota_pond_I1);
	}
	else {
		Edit11->Text = "0.00";
		Edit5->Text = "0.00";
	}

	if (maior_I2 > 0) {
		nota_I2 = pontuacao_I2 * ref_I2 / maior_I2;
		Edit12->Text = FormatFloat("0.00", nota_I2);
		nota_pond_I2 = nota_I2 * peso_I2;
		Edit6->Text = FormatFloat("0.00", nota_pond_I2);
	}
	else {
		Edit12->Text = "0.00";
		Edit6->Text = "0.00";
	}

	if (maior_I3 > 0) {
		nota_I3 = pontuacao_I3 * ref_I3 / maior_I3;
		Edit13->Text = FormatFloat("0.00", nota_I3);
		nota_pond_I3 = nota_I3 * peso_I3;
		Edit7->Text = FormatFloat("0.00", nota_pond_I3);
	}
	else {
		Edit13->Text = "0.00";
		Edit7->Text = "0.00";
	}

	// Nota final
	float total = nota_pond_I1 + nota_pond_I2 + nota_pond_I3;
	Edit96->Text = FormatFloat("0.00", total);

	// Calcula a pontua��o de refer�ncia de cada item (escondido)
	Edit14->Text = FormatFloat("0.00", ((10 * maior_I1) / ref_I1));
	Edit15->Text = FormatFloat("0.00", ((10 * maior_I2) / ref_I2));
	Edit16->Text = FormatFloat("0.00", ((10 * maior_I3) / ref_I3));
}

void __fastcall TFormTitulos::CalculaPontuacaoTotal(int ic,
	int candidato_atual) {
	// ic = indice do candidato

	// Calculo do sub-totais e total final

	float a, b;
	float soma;

	int nro_items1 = TabelaClasse2->Tag;
	int nro_items2 = TabelaClasse3->Tag;
	int nro_items_total = nro_items2+TabelaClasse3->RowCount-1;
	// --------------- Secao I.1 ---------------    OK Verificado Res 01/2010
	soma = 0;

	for (int i = 0; i < nro_items1; i++) {
		//a = StrToFloat(Edit_pontuacao[i]->Text);
		a = StrToFloat(TabelaClasse1->Cells[2][i+1]);     // Modificado 3.5
		b = candidato[ic].nota_titulos[i];
		// b = StrToFloat(Edit_quantidade[i]->Text);
		soma = soma + a * b;
		//if (ic == candidato_atual)
		//	Edit_total[i]->Text = FormatFloat("0.00", a * b);

	}

	if (projeto.pontuacao_maxima_classe1) {              // inserido 3.6
			if (soma>projeto.valor_pontuacao_maxima_classe1) {
				   soma = projeto.valor_pontuacao_maxima_classe1;
			}
	}
	float sub_tot_1 = soma;

	if (ic == candidato_atual) {
		Edit22->Text = FormatFloat("0.00", soma);
		Edit93->Text = Edit22->Text;
	}

	// --------------- Secao I.2 ---------------  OK Verificado Res 01/2010
	soma = 0;
	for (int i = 1; i <= nro_items2-nro_items1; i++) {
		a = StrToFloat(TabelaClasse2->Cells[2][i]);       // Modificado 3.5
		//a = StrToFloat(Edit_pontuacao[i]->Text);
		b = candidato[ic].nota_titulos[i+nro_items1-1];
		// b = StrToFloat(Edit_quantidade[i]->Text);
		soma = soma + a * b;
		//if (ic == candidato_atual)
		//	Edit_total[i]->Text = FormatFloat("0.00", a * b);

	}
	if (projeto.pontuacao_maxima_classe2) {              // inserido 3.6
			if (soma>projeto.valor_pontuacao_maxima_classe2) {
				   soma = projeto.valor_pontuacao_maxima_classe2;
			}
	}
	float sub_tot_2 = soma;
	if (ic == candidato_atual) {
		Edit47->Text = FormatFloat("0.00", soma);
		Edit94->Text = Edit47->Text;
	}

	// --------------- Secao I.3 --------------- OK Verificado Res 01/2010

	soma = 0;
	for (int i = 1; i <=nro_items_total - nro_items2; i++) {
		a = StrToFloat(TabelaClasse3->Cells[2][i]);       // Modificado 3.5
		//a = StrToFloat(Edit_pontuacao[i]->Text);
		b = candidato[ic].nota_titulos[i+nro_items2-1];
		// b = StrToFloat(Edit_quantidade[i]->Text);
		soma = soma + a * b;
		//if (ic == candidato_atual)
		//	Edit_total[i]->Text = FormatFloat("0.00", a * b);

	}
	/* DONE : Inserir os pesos das classes em salvar e carregar */
	if (projeto.pontuacao_maxima_classe3) {              // inserido 3.6
			if (soma>projeto.valor_pontuacao_maxima_classe3) {
				   soma = projeto.valor_pontuacao_maxima_classe3;
			}
	}
	float sub_tot_3 = soma;
	if (ic == candidato_atual) {
		Edit144->Text = FormatFloat("0.00", soma);
		Edit95->Text = Edit144->Text;
	}

	candidato[ic].pontuacao_I1 = sub_tot_1;
	candidato[ic].pontuacao_I2 = sub_tot_2;
	candidato[ic].pontuacao_I3 = sub_tot_3;
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::ComboBox1Change(TObject *Sender) {
	int i_c = ComboBox1->ItemIndex; // candidato selecionado

	// Obs. usando i_e indice examinador = 0
	if (i_c >= 0) {
		// Habilita os campos quantidade
		//for (int i = 0; i <= 52; i++)
		//	Edit_quantidade[i]->Enabled = true;

		// Habilita tabelas
		TabelaClasse1->Enabled=true;
		TabelaClasse2->Enabled=true;
		TabelaClasse3->Enabled=true;

		// --- Modificado 3.5
		// Carrega as notas nos TEdit
		int nro_items1 = TabelaClasse2->Tag;
		int nro_items2 = TabelaClasse3->Tag;
		int nro_items_total = nro_items2+TabelaClasse3->RowCount-1;
		for (int i = 0; i < nro_items1; i++) {
			TabelaClasse1->Cells[3][i+1] = FormatFloat("0.#",
				candidato[i_c].nota_titulos[i]);
			//Edit_quantidade[i]->Text = FormatFloat("0.#",
			 //	candidato[i_c].nota_titulos[i]);
		}
		for (int i = 1; i<=nro_items2-nro_items1; i++) {
			TabelaClasse2->Cells[3][i] = FormatFloat("0.#",
				candidato[i_c].nota_titulos[i+nro_items1-1]);
			//Edit_quantidade[i]->Text = FormatFloat("0.#",
			//	candidato[i_c].nota_titulos[i]);
		}
		for (int i = 1; i<=nro_items_total - nro_items2; i++) {
			TabelaClasse3->Cells[3][i] = FormatFloat("0.#",
				candidato[i_c].nota_titulos[i+nro_items2-1]);
			//Edit_quantidade[i]->Text = FormatFloat("0.#",
			//	candidato[i_c].nota_titulos[i]);
		}

		//for (int i = 11; i <= 52; i++) {
		//	Edit_quantidade[i]->Text = FormatFloat("0.#",
		//		candidato[i_c].nota_titulos[i]);
		//}
		// ---
		MultiplicaLinhas(TabelaClasse1);
		MultiplicaLinhas(TabelaClasse2);
		MultiplicaLinhas(TabelaClasse3);

		// Atualiza o nome do candidato no resumo
		Label65->Caption = candidato[i_c].nome;

		Button1Click(ComboBox1); // Calcula os totais novamente
	}
	else {
		// Desabilita os campos quantidade
		//for (int i = 0; i <= 52; i++)
		//	Edit_quantidade[i]->Enabled = false;

		// Desabilita tabelas
		TabelaClasse1->Enabled=false;
		TabelaClasse2->Enabled=false;
		TabelaClasse3->Enabled=false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::FormCreate(TObject *Sender) {

	// FUN��O OK - RES. 01/2010
	/*
	// Classe I.1      - ok Res 01/2010
	Edit_pontuacao[0] = E000;
	Edit_quantidade[0] = E001;
	Edit_total[0] = E002;

	Edit_pontuacao[1] = E010;
	Edit_quantidade[1] = E011;
	Edit_total[1] = E012;

	Edit_pontuacao[2] = E020;
	Edit_quantidade[2] = E021;
	Edit_total[2] = E022;

	Edit_pontuacao[3] = E030;
	Edit_quantidade[3] = E031;
	Edit_total[3] = E032;

	Edit_pontuacao[4] = E040;
	Edit_quantidade[4] = E041;
	Edit_total[4] = E042;

	Edit_pontuacao[5] = E060;
	Edit_quantidade[5] = E061;
	Edit_total[5] = E062;

	Edit_pontuacao[6] = E080;
	Edit_quantidade[6] = E081;
	Edit_total[6] = E082;

	Edit_pontuacao[7] = E650;
	Edit_quantidade[7] = E651;
	Edit_total[7] = E652;

	Edit_pontuacao[8] = E660;
	Edit_quantidade[8] = E661;
	Edit_total[8] = E662;
	//

	// Classe I.2  - OK REL 01/2010
	Edit_pontuacao[9] = E100;
	Edit_quantidade[9] = E101;
	Edit_total[9] = E102;

	Edit_pontuacao[10] = E120;
	Edit_quantidade[10] = E121;
	Edit_total[10] = E122;

	Edit_pontuacao[11] = E140;
	Edit_quantidade[11] = E141;
	Edit_total[11] = E142;

	Edit_pontuacao[12] = E160;
	Edit_quantidade[12] = E161;
	Edit_total[12] = E162;

	Edit_pontuacao[13] = E180;
	Edit_quantidade[13] = E181;
	Edit_total[13] = E182;

	Edit_pontuacao[14] = E200;
	Edit_quantidade[14] = E201;
	Edit_total[14] = E202;

	Edit_pontuacao[15] = E220;
	Edit_quantidade[15] = E221;
	Edit_total[15] = E222;

	Edit_pontuacao[16] = E240;
	Edit_quantidade[16] = E241;
	Edit_total[16] = E242;

	Edit_pontuacao[17] = E260;
	Edit_quantidade[17] = E261;
	Edit_total[17] = E262;

	Edit_pontuacao[18] = E280;
	Edit_quantidade[18] = E281;
	Edit_total[18] = E282;

	Edit_pontuacao[19] = E300;
	Edit_quantidade[19] = E301;
	Edit_total[19] = E302;

	Edit_pontuacao[20] = E320;
	Edit_quantidade[20] = E321;
	Edit_total[20] = E322;

	Edit_pontuacao[21] = E340;
	Edit_quantidade[21] = E341;
	Edit_total[21] = E342;

	Edit_pontuacao[22] = E360;
	Edit_quantidade[22] = E361;
	Edit_total[22] = E362;

	Edit_pontuacao[23] = E380;
	Edit_quantidade[23] = E381;
	Edit_total[23] = E382;

	Edit_pontuacao[24] = E670;
	Edit_quantidade[24] = E671;
	Edit_total[24] = E672;

	Edit_pontuacao[25] = E680;
	Edit_quantidade[25] = E681;
	Edit_total[25] = E682;

	Edit_pontuacao[26] = E690;
	Edit_quantidade[26] = E691;
	Edit_total[26] = E692;

	Edit_pontuacao[27] = E700;
	Edit_quantidade[27] = E701;
	Edit_total[27] = E702;

	Edit_pontuacao[28] = E710;
	Edit_quantidade[28] = E711;
	Edit_total[28] = E712;

	Edit_pontuacao[29] = E720;
	Edit_quantidade[29] = E721;
	Edit_total[29] = E722;
	//

	// Classe I.3 - OK RES 01/2010
	Edit_pontuacao[30] = E420;
	Edit_quantidade[30] = E421;
	Edit_total[30] = E422;

	Edit_pontuacao[31] = E440;
	Edit_quantidade[31] = E441;
	Edit_total[31] = E442;

	Edit_pontuacao[32] = E460;
	Edit_quantidade[32] = E461;
	Edit_total[32] = E462;

	Edit_pontuacao[33] = E480;
	Edit_quantidade[33] = E481;
	Edit_total[33] = E482;

	Edit_pontuacao[34] = E500;
	Edit_quantidade[34] = E501;
	Edit_total[34] = E502;

	Edit_pontuacao[35] = E520;
	Edit_quantidade[35] = E521;
	Edit_total[35] = E522;

	Edit_pontuacao[36] = E540;
	Edit_quantidade[36] = E541;
	Edit_total[36] = E542;

	Edit_pontuacao[37] = E560;
	Edit_quantidade[37] = E561;
	Edit_total[37] = E562;

	Edit_pontuacao[38] = E580;
	Edit_quantidade[38] = E581;
	Edit_total[38] = E582;

	Edit_pontuacao[39] = E600;
	Edit_quantidade[39] = E601;
	Edit_total[39] = E602;

	Edit_pontuacao[40] = E620;
	Edit_quantidade[40] = E621;
	Edit_total[40] = E622;

	Edit_pontuacao[41] = E730;
	Edit_quantidade[41] = E731;
	Edit_total[41] = E732;

	Edit_pontuacao[42] = E740;
	Edit_quantidade[42] = E741;
	Edit_total[42] = E742;

	Edit_pontuacao[43] = E750;
	Edit_quantidade[43] = E751;
	Edit_total[43] = E752;

	Edit_pontuacao[44] = E760;
	Edit_quantidade[44] = E761;
	Edit_total[44] = E762;

	Edit_pontuacao[45] = E770;
	Edit_quantidade[45] = E771;
	Edit_total[45] = E772;

	Edit_pontuacao[46] = E780;
	Edit_quantidade[46] = E781;
	Edit_total[46] = E782;

	Edit_pontuacao[47] = E790;
	Edit_quantidade[47] = E791;
	Edit_total[47] = E792;

	Edit_pontuacao[48] = E800;
	Edit_quantidade[48] = E801;
	Edit_total[48] = E802;

	Edit_pontuacao[49] = E810;
	Edit_quantidade[49] = E811;
	Edit_total[49] = E812;

	Edit_pontuacao[50] = E820;
	Edit_quantidade[50] = E821;
	Edit_total[50] = E822;

	Edit_pontuacao[51] = E830;
	Edit_quantidade[51] = E831;
	Edit_total[51] = E832;

	Edit_pontuacao[52] = E840;
	Edit_quantidade[52] = E841;
	Edit_total[52] = E842;
	//

	// Classe I.1 - OK RES. 01/2010
	Texto_item[0] = S00;
	Texto_item[1] = S01;
	Texto_item[2] = S02;
	Texto_item[3] = S03;
	Texto_item[4] = S04;
	Texto_item[5] = S05;
	Texto_item[6] = S06;
	Texto_item[7] = S65;
	Texto_item[8] = S66;
	//

	// Classe I.2  - ok RES 01/2010
	Texto_item[9] = S07;
	Texto_item[10] = S08;
	Texto_item[11] = S09;
	Texto_item[12] = S10;
	Texto_item[13] = S11;
	Texto_item[14] = S12;
	Texto_item[15] = S13;
	Texto_item[16] = S14;
	Texto_item[17] = S15;
	Texto_item[18] = S16;
	Texto_item[19] = S17;
	Texto_item[20] = S18;
	Texto_item[21] = S19;
	Texto_item[22] = S20;
	Texto_item[23] = S21;
	Texto_item[24] = S70;
	Texto_item[25] = S71;
	Texto_item[26] = S72;
	Texto_item[27] = S73;
	Texto_item[28] = S74;
	Texto_item[29] = S75;

	// Classe I.3      - OK RES 01/2010
	Texto_item[30] = S23;
	Texto_item[31] = S24;
	Texto_item[32] = S25;
	Texto_item[33] = S26;
	Texto_item[34] = S27;
	Texto_item[35] = S28;
	Texto_item[36] = S29;
	Texto_item[37] = S30;
	Texto_item[38] = S31;
	Texto_item[39] = S32;
	Texto_item[40] = S33;
	Texto_item[41] = S76;
	Texto_item[42] = S77;
	Texto_item[43] = S78;
	Texto_item[44] = S79;
	Texto_item[45] = S80;
	Texto_item[46] = S81;
	Texto_item[47] = S82;
	Texto_item[48] = S83;
	Texto_item[49] = S84;
	Texto_item[50] = S85;
	Texto_item[51] = S86;
	Texto_item[52] = S87;
	*/
	Label40->Caption = "Pontua��o de acordo com " + projeto.normativa;

}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Button3Click(TObject *Sender) {
	// if(ComboBox1->ItemIndex>=0 && ComboBox2->ItemIndex>=0)    retirado examinador na versao 3.4
	if (ComboBox1->ItemIndex >= 0) {
		SelData->ShowModal();
		FormAtas->Button2Click(FormTitulos);
	}
	else {
		Application->MessageBox
			(L"Selecione o candidato para gerar a planilha.", L"Erro", 0);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Button2Click(TObject *Sender) {
	SelData->ShowModal();
	FormAtas->Button29Click(FormTitulos);
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Dicas1Click(TObject *Sender) {
	FormDicas->PageControl1->ActivePage = FormDicas->TabTitulos;
	FormDicas->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Edit2Exit(TObject *Sender) {
	// -- OK - RES 01/2010

	if (candidato.size() > 0) {
		TEdit *temp = (TEdit*)Sender;
		double a;
		if (!(TryStrToFloat(temp->Text, a))) {
			Application->MessageBox(L"Valor n�o num�rico", L"Erro", 0);
			temp->Text = "0,3";
		}
		else {
			// Peso Item I.1
			if (temp->Tag == 100) {
				float z = StrToFloat(Edit2->Text);
				if (z < projeto.pesominclasse1 || z > projeto.pesomaxclasse1) {
					String strtemp = "Peso da classe deve estar entre " + FormatFloat("0.00", projeto.pesominclasse1) + " e " + FormatFloat("0.00", projeto.pesomaxclasse1) + ".";
					Application->MessageBox(
						strtemp.c_str(),
						L"Erro", 0);
					temp->Text = FormatFloat("0.00",projeto.pesominclasse1);
				}
			}
			// Peso Item I.2
			if (temp->Tag == 101) {
				float z = StrToFloat(Edit3->Text);
				if (z < projeto.pesominclasse2 || z > projeto.pesomaxclasse2) {
					String strtemp = "Peso da classe deve estar entre " + FormatFloat("0.00", projeto.pesominclasse2) + " e " + FormatFloat("0.00", projeto.pesomaxclasse2) + ".";
					Application->MessageBox(
						strtemp.c_str(),
						L"Erro", 0);
					temp->Text = FormatFloat("0.00",projeto.pesominclasse2);
				}
			}
			// Peso Item I.3
			if (temp->Tag == 102) {
				float z = StrToFloat(Edit4->Text);
				if (z < projeto.pesominclasse3 || z > projeto.pesomaxclasse3) {
					String strtemp = "Peso da classe deve estar entre " + FormatFloat("0.00", projeto.pesominclasse3) + " e " + FormatFloat("0.00", projeto.pesomaxclasse3) + ".";
					Application->MessageBox(
						strtemp.c_str(),
						L"Erro", 0);
					temp->Text = FormatFloat("0.00",projeto.pesominclasse3);
				}

			}

			// Notas de refer�ncia
			if (temp->Tag == 200) {
				float z = StrToFloat(temp->Text);
				if (z <= 0 || z > 10.001) {
					Application->MessageBox(
						L"Nota de refer�ncia deve ser entre zero e 10",
						L"Erro", 0);
					temp->Text = "10,0";
				}
			}

			Button1Click(FormTitulos);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::Button4Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::PageControl1Change(TObject *Sender) {
	ScrollBox1->VertScrollBar->Position = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::FormActivate(TObject *Sender) {
	// Carrega arquivo de regras
   //	String yy = "Edital52.gcr";
   //	String aa = GetCurrentDir();

	//String nome_arq = aa + "\\" + yy;
	//TIniFile *iniregras = new TIniFile(nome_arq);
	// Le itens da prova de titulos
	//String string1 = iniregras->ReadString("ClasseI1", "Disc1", "Erro");
	//FormTitulos->S00->Caption = string1;
	//float float1 = iniregras->ReadFloat("ClasseI1", "Pont1", 0);
	//FormTitulos->E000->Text = FormatFloat("0.00", float1);

	//delete iniregras;
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::TabelaClasse1DrawCell(TObject *Sender, int ACol,
	int ARow, TRect &Rect, TGridDrawState State) {

	TStringGrid *temp = (TStringGrid*)Sender;

	if (ARow > 0)
		if (ARow % 2 == 1) // linhas impares
		{
			temp->Canvas->Brush->Color = clMoneyGreen;

		}
		else {
			temp->Canvas->Brush->Color = clSkyBlue;
		}

	temp->Canvas->TextRect(Rect, Rect.Left, Rect.Top, temp->Cells[ACol][ARow]);

	if (ACol != 1) {

		TStringGrid* StringGrid = static_cast<TStringGrid*>(Sender);
		assert(StringGrid != NULL);
		StringGrid->Canvas->FillRect(Rect);

		AnsiString text(StringGrid->Cells[ACol][ARow]);
		RECT RText = static_cast<RECT>(Rect);
		InflateRect(&RText, -3, -3);

		DrawText(StringGrid->Canvas->Handle, text.c_str(), text.Length(),
			&RText, DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	}

	if (ACol == 1) {

		TStringGrid* StringGrid = static_cast<TStringGrid*>(Sender);
		assert(StringGrid != NULL);
		StringGrid->Canvas->FillRect(Rect);

		AnsiString text(StringGrid->Cells[ACol][ARow]);
		RECT RText = static_cast<RECT>(Rect);
		// InflateRect(&RText, -3, -3);

		DrawText(StringGrid->Canvas->Handle, text.c_str(), text.Length(),
			&RText, DT_LEFT | DT_WORDBREAK);
	}

	if (ARow == 0) {
		temp->Canvas->FillRect(Rect);
		AnsiString text(temp->Cells[ACol][ARow]);
		RECT RText = static_cast<RECT>(Rect);

		DrawText(temp->Canvas->Handle, text.c_str(), text.Length(), &RText,
			DT_CENTER | DT_VCENTER);
	}

}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::TabelaClasse1SetEditText(TObject *Sender,
	int ACol, int ARow, const UnicodeString Value) {

	// somente calcula se a celula modificada esta na coluna 3 (quantidade)
	if (ACol == 3) {

		DecimalSeparator = ',';
		TStringGrid *temp = (TStringGrid*)Sender;

		if (Trim(temp->Cells[ACol][ARow]) != "") {
			if (ARow > 0)
				if (ACol > 0) {
					float a;
					if (!(TryStrToFloat(temp->Cells[ACol][ARow], a))) {
						Application->MessageBox(L"Valor n�o num�rico", L"Erro",
							0);
						temp->Cells[ACol][ARow] = "0";
					}
					else {

						float quant = StrToFloat(temp->Cells[3][ARow]);
						float pont = StrToFloat(temp->Cells[2][ARow]);
						float total = quant * pont;
						temp->Cells[4][ARow] = FormatFloat("0.00", total);
					}
				}
		}

		else
			temp->Cells[4][ARow] = "0,00";

		if (Trim(temp->Cells[ACol][ARow]) != "") {
			int ic = ComboBox1->ItemIndex;

			float nota = StrToFloat(temp->Cells[3][ARow]);
			int itag = temp->Tag;


			if (ic >= 0)
			candidato[ic].nota_titulos[itag+ARow-1] = nota;

			Button1Click(FormTitulos);
			VerificaRegras(temp, ARow);
        }

	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::TabelaClasse1SelectCell(TObject *Sender,
	int ACol, int ARow, bool &CanSelect) {
	TStringGrid *temp = (TStringGrid*)Sender;
	if (ACol == 3) {

		temp->Options << goEditing;
	}
	else
		temp->Options >> goEditing;

}
// ---------------------------------------------------------------------------


void __fastcall TFormTitulos::MultiplicaLinhas(TObject *Sender) {

	TStringGrid *temp = (TStringGrid*)Sender;

	// Zera as linhas da coluna quantidade que est�o em branco



	for (int i = 1; i < temp->RowCount; i++) {
		if (Trim(temp->Cells[3][i])=="") {
		   temp->Cells[3][i] = "0";
		}
		float a = StrToFloat(temp->Cells[2][i]);
		float b = StrToFloat(temp->Cells[3][i]);
		float c = a*b;
		temp->Cells[4][i] = FormatFloat("0.00", c);
	}

}

// ---------------------------------------------------------------------------

void __fastcall TFormTitulos::VerificaRegras(TObject *Sender, int ARow) {

	TStringGrid *temp = (TStringGrid*)Sender;

	int indiceglobal = temp->Tag + ARow - 1;  // indice da variavel candidato[ic].notatitulos

	int ic = ComboBox1->ItemIndex;
	if (ic >= 0) {

		// Regras de maxima pontuacao no item
		for (int i = 1; i < TabelaRegrasMaxPont->RowCount; i++) {
			int indice = StrToInt(TabelaRegrasMaxPont->Cells[0][i]);
			float quantmax = StrToFloat(TabelaRegrasMaxPont->Cells[1][i]);
			float quant = StrToFloat(temp->Cells[4][ARow]);

			// float xxx = candidato[ic].nota_titulos[indice];
			if (indice == indiceglobal) {

				if (quant > quantmax) {
					String tempstr = "M�xima pontua��o no item � " +
						TabelaRegrasMaxPont->Cells[1][i] + ".";

					Application->MessageBox(tempstr.c_str(),
						L"Verifique a pontua��o", 0);

				}
			}
		}

		// Regras de itens nao cumulativos
		for (int i = 1; i < TabelaRegrasCumulativo->RowCount; i++) {
			int indice1 = StrToInt(TabelaRegrasCumulativo->Cells[0][i]);
			int indice2 = StrToInt(TabelaRegrasCumulativo->Cells[1][i]);

			if (candidato[ic].nota_titulos[indice1] > 0 && candidato[ic]
				.nota_titulos[indice2] > 0) {
				if (indiceglobal == indice1 || indiceglobal == indice2) {

					int item1, item2;
					int nro_items1 = TabelaClasse2->Tag;
					int nro_items2 = TabelaClasse3->Tag;

					if (indice1 < nro_items1) { // Classe 1
						item1 = indice1 + 1;
						item2 = indice2 + 1;
					}
					if (indice1 >= nro_items1 && indice1 < nro_items2) {
						// Classe 2
						item1 = indice1 - nro_items1 + 1;
						item2 = indice2 - nro_items1 + 1;
					}
					if (indice1 > nro_items2) { // Classe 3
						item1 = indice1 - nro_items2 + 1;
						item2 = indice2 - nro_items2 + 1;
					}

					String tempstr = "Itens " + IntToStr(item1)
						+ " e " + IntToStr(item2) + " n�o s�o cumulativos.";

					Application->MessageBox(tempstr.c_str(),
						L"Verifique a pontua��o", 0);

				}
			}
		}

	}
}
void __fastcall TFormTitulos::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
	// Alinha a esquerda
	if (ACol != 0) {

		TStringGrid* StringGrid = static_cast<TStringGrid*>(Sender);
		assert(StringGrid != NULL);
		StringGrid->Canvas->FillRect(Rect);

		AnsiString text(StringGrid->Cells[ACol][ARow]);
		RECT RText = static_cast<RECT>(Rect);
		InflateRect(&RText, -3, -3);

		DrawText(StringGrid->Canvas->Handle, text.c_str(), text.Length(),
			&RText, DT_RIGHT | DT_SINGLELINE );
	}
}
//---------------------------------------------------------------------------
