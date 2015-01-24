//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Atas.h"
#include "stdio.h"
#include "Principal.h"
#include "Configuracao.h"
#include "Titulos.h"
#include "Escrita.h"
#include "Didatica.h"
#include "DefesaProjeto.h"
#include "Entrevista.h"
#include "Resultado.h"
#include "Dialogo.h"
#include "Cabecalho.h"
#include "Abertura.h"
#include "ListaDocumentos.h"

#include <iostream>
#include  <fstream>
#include <ios>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAtas *FormAtas;
//---------------------------------------------------------------------------
__fastcall TFormAtas::TFormAtas(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAtas::Button1Click(TObject *Sender)
{
		// Esta m�todo n�o � mais usado!!!


		


}
//---------------------------------------------------------------------------
void __fastcall TFormAtas::Button2Click(TObject *Sender)
{
		// ---------------
        // Planilha demonstrativa de prova de t�tulos - por candidato e por examinador - id=2_ic_ie

		// Alterado versao 3.4 - uma unica planilha para todos os examinadores

		int ic = FormTitulos->ComboBox1->ItemIndex;
		//int ie = FormTitulos->ComboBox2->ItemIndex;
		int ie=1; // examinador nao eh mais usado neste metodo a partir da versao 3.4

		AnsiString nome_arq1 = "titulos_planilha_c" + IntToStr(ic) + "_e" + IntToStr(ie) + ".rtf";

		String identificador = "2_" + IntToStr(ic) + "_" + IntToStr(ie);
		String titulo = "Planilha demonstrativa - prova de t�tulos - " + FormTitulos->ComboBox1->Items->Strings[ic] + " - " + examinador[ie].nome;
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  nome_arq1;
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}


				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						// int nro_documento = 0;
		String pesoI1, pesoI2, pesoI3;
		pesoI1 = (FormTitulos->Edit2->Text);
		pesoI2 = (FormTitulos->Edit3->Text);
		pesoI3 = (FormTitulos->Edit4->Text);

		String pont_refI1 = (FormTitulos->Edit14->Text);
		String pont_refI2 = (FormTitulos->Edit15->Text);
		String pont_refI3 = (FormTitulos->Edit16->Text);

		// ---------------

		//;; ********** Obs: esta fun��o imprime o que est� mostrado no FormTitulos!!
		//Application->MessageBox("Esta funcao imprime o que esta na tela de FormTitulos","Atencao",0);

		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);

		GeraCabecalho(nome_arq);

		int nro_items1 = FormTitulos->TabelaClasse2->Tag;
		int nro_items2 = FormTitulos->TabelaClasse3->Tag;
		int nro_items_total = nro_items2+FormTitulos->TabelaClasse3->RowCount-1;

		//if (ic>=0 && ie>=0)
		{
			 FILE* arq = fopen(AnsiString(nome_arq).c_str(), "a+t"); // abre no modo append

			 // T�tulo
			 fprintf(arq, "\\pard \n \\par \\par \\par\n");
			 fprintf(arq, "\\qc \\b PLANILHA DE AVALIA��O DE PROVA DE T�TULOS \\b0 \n");
			 fprintf(arq, "\\par \\qc Conforme %s\n", projeto.normativa.c_str());

			 // Nome do candidato
			 fprintf(arq, "\\par \n \\pard \\par \\par\n");
			 fprintf(arq, "\\b Candidato: %s \\b0\n\n", candidato[ic].nome);

			 // Alterado versao 3.4
			 //fprintf(arq, "\\pard \n \\par \\par \n");
			 //fprintf(arq, "\\b Examinador: %s \\b0\n\n", examinador[ie].nome_completo);

			 // ------------ Classe I.1 -----------------------
			 AnsiString tituloclasse = FormTitulos->StaticText5->Caption;
			 //fprintf(arq, "\\pard \\par \\par \\par \\qr \\b Classe I.1 Forma��o e Aperfei�oamento Acad�mico \\b0 \n" );
			 fprintf(arq, "\\pard \\par \\par \\par \\qr \\b %s \\b0 \n", tituloclasse.c_str() );
			 fprintf(arq, "\\pard  \\par Peso da classe: %s  \n", AnsiString(pesoI1).c_str());
			 if (projeto.pontuacao_maxima_classe1) {
				 fprintf(arq, "\\pard  \\par Pontua��o m�xima na classe: %s  \n", AnsiString(FormatFloat("0.0", projeto.valor_pontuacao_maxima_classe1)));
			 }
			 fprintf(arq, "\\pard  \\par Nota de refer�ncia (nota do melhor candidato na classe): %s  \n", AnsiString(FormTitulos->Edit8->Text).c_str());
			 fprintf(arq, "\\pard  \\par Pontua��o de refer�ncia (pontua��o do melhor candidato na classe): %s  \n", AnsiString(pont_refI1).c_str());
			 fprintf(arq, "\\pard  \\par \\par  \n");
			 // Inicio da tabela

			 // Primeira linha

             fprintf(arq, "\\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
             // Configuracao das celulas
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc1);
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc2);
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc3);
             //fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc4); aqui
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc5);
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc6);

             // Primeira celula
              fprintf(arq, "\\pard \\intbl \\qc Item \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc Discrimina��o \\cell\n");
              // Terceira celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o por unidade \\cell\n");
              // Quarta celula
              fprintf(arq, "\\pard \\intbl \\qc Quantidade \\cell\n");
              // Quinta celula
              //fprintf(arq, "\\pard \\intbl \\qc Quantidade (em �rea afim) \\cell\n");  aqui
              // Quinta celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o \\cell\n");
			  // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \\pard \n");

              // Imprime os itens e as notas
			  // I.1
			  // Items 0 a 8
			  //for (int i=0; i<=8; i++)
			  for (int i = 0; i < nro_items1; i++)
			  {
                     fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
                     // Configuracao das celulas
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc1);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc2);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc3);
                     //fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc4); aqui
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);

                     // Primeira celula
                     fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i+1 );
					 // Segunda celula
					 //fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(Texto_item[i]->Caption).c_str());
					 fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(FormTitulos->TabelaClasse1->Cells[1][i+1]).c_str());
					 // Terceira celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_pontuacao[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse1->Cells[2][i+1]).c_str());
					 // Quarta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_quantidade[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse1->Cells[3][i+1]).c_str());
					 // Quinta celula
					 //fprintf(arq, "\\pard \\intbl \\qc - \\cell\n"); aqui
					 // Sexta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_total[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse1->Cells[4][i+1]).c_str());
					 // Fim da linha
                      fprintf(arq, "\\pard \\intbl \\row \n");
              }

          /* aqui    // Items 4 a 9
			  int r = 4;
              for (int i=4; i<=6; i++)
              {
                     fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
                     // Configuracao das celulas
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc1);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc2);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc3);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc4);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);

                     // Primeira celula
                     fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i+1 );
                     // Segunda celula
					 fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(Texto_item[i]->Caption).c_str());
					 // Terceira celula
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_pontuacao[r]->Text).c_str());
					 // Quarta celula
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_quantidade[r]->Text).c_str());
					 r = r+1;
					 // Quinta celula
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_quantidade[r]->Text).c_str());
					 // Sexta celula
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormatFloat("0.00", StrToFloat(Edit_total[r]->Text)+StrToFloat(Edit_total[r-1]->Text))).c_str());
					 // Fim da linha
                     fprintf(arq, "\\pard \\intbl \\row \n");
					 r = r+1;
              }
              */

              // Subtotal geral
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Pontua��o total na classe   \\cell \n" );
              // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit22->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");

              // Nota no item
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
			  fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Nota na classe   \\cell \n" );
			  // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit11->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");


              // Subtotal ponderado
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Nota ponderada na classe   \\cell \n" );
              // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit5->Text).c_str());
			  // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");
			  // Nota rodape
			  AnsiString rodape = FormTitulos->StaticText2->Caption;
			  fprintf(arq, "\\pard %s  \n", rodape.c_str() );


			  // ------------ Classe I.2 -----------------------
			 tituloclasse = FormTitulos->StaticText3->Caption;
			 fprintf(arq, "\\pard \\par \\par \\par \\qr \\b %s \\b0 \n", tituloclasse.c_str() );
			 //fprintf(arq, "\\pard \\par \\pagebb \\par \\qr \\b Classe I.2 Produ��o Cient�fica, Tecnol�gica, Art�stica e Cultural (considerando os �ltimos 5 anos) \\b0  \n" );
			 fprintf(arq, "\\pard  \\par Peso da classe: %s  \n", AnsiString(pesoI2).c_str());
			 if (projeto.pontuacao_maxima_classe2) {
				 fprintf(arq, "\\pard  \\par Pontua��o m�xima na classe: %s  \n", AnsiString(FormatFloat("0.0", projeto.valor_pontuacao_maxima_classe2)));
			 }
			 fprintf(arq, "\\pard  \\par Nota de refer�ncia (nota do melhor candidato na classe): %s  \n", AnsiString(FormTitulos->Edit9->Text).c_str());
			 fprintf(arq, "\\pard  \\par Pontua��o de refer�ncia (pontua��o do melhor candidato na classe): %s  \n", AnsiString(pont_refI2).c_str());
			 fprintf(arq, "\\pard  \\par \\par  \n");
			 // Inicio da tabela

			 // Primeira linha

			 fprintf(arq, "\\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
			 // Configuracao das celulas
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc1);
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc2);
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc3);
			 //fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc4); aqui
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc5);
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc6);

			 // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qc Item \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc Discrimina��o \\cell\n");
              // Terceira celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o por unidade \\cell\n");
              // Quarta celula
              fprintf(arq, "\\pard \\intbl \\qc Quantidade \\cell\n");
              // Quinta celula
              //fprintf(arq, "\\pard \\intbl \\qc Quantidade (em �rea afim) \\cell\n"); aqui
			  // Quinta celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o \\cell\n");
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \\pard \n");

              // Imprime os itens e as notas
              // I.2

              // Items 9 a 29
			 // r = 10;
			  //for (int i=9; i<=29; i++)
			  for (int i = 0; i<nro_items2-nro_items1; i++)
			  {
                     fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
                     // Configuracao das celulas
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc1);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc2);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc3);
                     //fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc4); aqui
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);

					 // Primeira celula
					 //fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i-8 );
					 fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i+1 );
					// Segunda celula
					 //fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(Texto_item[i]->Caption).c_str());
					 fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(FormTitulos->TabelaClasse2->Cells[1][i+1]).c_str());
					 // Terceira celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_pontuacao[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse2->Cells[2][i+1]).c_str());
					 // Quarta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_quantidade[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse2->Cells[3][i+1]).c_str());
					 // Quinta celula
					 //fprintf(arq, "\\pard \\intbl \\qc - \\cell\n"); aqui
					 // Sexta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_total[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse2->Cells[4][i+1]).c_str());
					 // Fim da linha
					 fprintf(arq, "\\pard \\intbl \\row \n");
                     //r = r+1;
			  }
              // Subtotal
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Pontua��o total na classe   \\cell \n" );
              // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit47->Text).c_str());
              // Fim da linha
			  fprintf(arq, "\\pard \\intbl \\row \n");

              // Nota no item
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
			  // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Nota na classe   \\cell \n" );
              // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit12->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");


              // Subtotal ponderado
			  fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Nota ponderada na classe   \\cell \n" );
              // Segunda celula
			  fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit6->Text).c_str());
			  // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");
              // Nota rodape
			  rodape = FormTitulos->StaticText9->Caption;
			  fprintf(arq, "\\pard %s  \n", rodape.c_str() );

			  // ------------ Classe I.3 -----------------------
			 tituloclasse = FormTitulos->StaticText6->Caption;
			 fprintf(arq, "\\pard \\par \\par \\par \\qr \\b %s \\b0 \n", tituloclasse.c_str() );
			// fprintf(arq, "\\pard \\par \\pagebb \\par \\qr \\b I.3. Atividades de Pesquisa, Ensino e Extens�o (considerando os �ltimos 5 anos) \\b0 \n" );
			 //fprintf(arq, "\\pard \\par \\par \\qr \\b I.3. Atividades de Pesquisa, Ensino e Extens�o (considerando os �ltimos 5 anos) \\b0 \n" );
			 fprintf(arq, "\\pard  \\par Peso da classe: %s  \n", AnsiString(pesoI3).c_str());
			 if (projeto.pontuacao_maxima_classe3) {
				 fprintf(arq, "\\pard  \\par Pontua��o m�xima na classe: %s  \n", AnsiString(FormatFloat("0.0", projeto.valor_pontuacao_maxima_classe3)));
			 }
			 fprintf(arq, "\\pard  \\par Nota de refer�ncia (nota do melhor candidato na classe): %s  \n", AnsiString(FormTitulos->Edit10->Text).c_str());
			 fprintf(arq, "\\pard  \\par Pontua��o de refer�ncia (pontua��o do melhor candidato na classe): %s  \n", AnsiString(pont_refI3).c_str());
             fprintf(arq, "\\pard  \\par \\par  \n");
             // Inicio da tabela

             // Primeira linha

             fprintf(arq, "\\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
             // Configuracao das celulas
			 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc1);
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc2);
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc3);
			// fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc4); aqui
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc5);
             fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx%i\n", tc6);

             // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qc Item \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc Discrimina��o \\cell\n");
              // Terceira celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o por unidade \\cell\n");
              // Quarta celula
              fprintf(arq, "\\pard \\intbl \\qc Quantidade \\cell\n");
              // Quinta celula
		//	  fprintf(arq, "\\pard \\intbl \\qc Quantidade (em �rea afim) \\cell\n"); aqui
              // Quinta celula
              fprintf(arq, "\\pard \\intbl \\qc Pontua��o \\cell\n");
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \\pard \n");

              // Imprime os itens e as notas
              // I.2

              // Items 30 a 52
              //r = 42;
			  //for (int i=30; i<=52; i++)
			  for (int i = 0; i<nro_items_total - nro_items2; i++)
			  {
                     fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
					 // Configuracao das celulas
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc1);
					 fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc2);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc3);
                     //fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc4);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
                     fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);

                     // Primeira celula
					 //fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i-29 );
					 fprintf(arq, "\\pard  \\intbl \\qc %i \\cell \n", i+1 );


                    // Segunda celula
					 //fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(Texto_item[i]->Caption).c_str());
					 fprintf(arq, "\\pard \\intbl \\ql %s \\cell\n", AnsiString(FormTitulos->TabelaClasse3->Cells[1][i+1]).c_str());
					 // Terceira celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_pontuacao[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse3->Cells[2][i+1]).c_str());
					 // Quarta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_quantidade[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse3->Cells[3][i+1]).c_str());
					 // Quinta celula
					 //fprintf(arq, "\\pard \\intbl \\qc - \\cell\n"); aqui
					 // Sexta celula
					 //fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(Edit_total[i]->Text).c_str());
					 fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->TabelaClasse3->Cells[4][i+1]).c_str());
					 // Fim da linha
					 fprintf(arq, "\\pard \\intbl \\row \n");
                     //r = r+1;
              }
              // Subtotal
			  fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
			  // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Pontua��o total na classe   \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit144->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");

              // Nota no item
			  fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
			  fprintf(arq, "\\pard  \\intbl \\qr Nota na classe   \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit13->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");


			  // Subtotal ponderado
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
			  fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
              fprintf(arq, "\\pard  \\intbl \\qr Nota ponderada na classe   \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc %s \\cell\n", AnsiString(FormTitulos->Edit7->Text).c_str());
              // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");
              // Nota rodape
			  rodape = FormTitulos->StaticText8->Caption;
			  fprintf(arq, "\\pard %s  \n", rodape.c_str() );

              //fprintf(arq, "\\pard \\par \\par");
              fprintf(arq, "\\pard \\par \\par \\par");

              // Total geral
              fprintf(arq, "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql\n");
              // Configuracao das celulas
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc5);
              fprintf(arq, "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx%i\n", tc6);
              // Primeira celula
              fprintf(arq, "\\pard  \\intbl \\qr \\b NOTA FINAL   \\b0 \\cell \n" );
              // Segunda celula
              fprintf(arq, "\\pard \\intbl \\qc \\b %s \\b0 \\cell\n", AnsiString(FormTitulos->Edit96->Text).c_str());
			  // Fim da linha
              fprintf(arq, "\\pard \\intbl \\row \n");

			 /* // Data e Assinatura
              unsigned short ano, mes, dia;
                //FormTitulos->DateTimePicker1->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
                DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
                ComboBox2->ItemIndex = mes-1;
                ComboBox3->ItemIndex = ano % 100;
                //fprintf(arq, "\\pard  \\par  \\par \\par \n");
				//fprintf(arq, "\\pard  \\par \n");
				fprintf(arq, "\\pard \n");
				fprintf(arq, "\\qr \\par %s, %s de %s de %s.\n\n", projeto.campus.c_str(), AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str(), AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str(), AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str());
                 */

				fclose(arq);

				Assinaturas(nome_arq, DataG);
				//FechaRTF(nome_arq);

		/*
				// Inicio da area para assinaturas

				//fprintf(arq, "\\par  \\pard  \\par \\par\n");
				fprintf(arq, "\\par  \\pard \\par \\par  \n");

				fprintf(arq, "\\par \\trowd \\trgaph0 \\trqc \\cellx3636\n");
				fprintf(arq, "\\qc ______________________________ \\cell \\pard \\intbl \\row\n");
				fprintf(arq, "\\trowd \\trgaph0 \\trqc \\cellx3636\n");
				fprintf(arq, "\\qc %s \\cell \\pard \\intbl \\row\n", examinador[ie].nome_completo);
				fprintf(arq, "\\pard\n");


			 fclose(arq);
		  */


		}

		FechaRTF(nome_arq);

		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);



        //nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------


void __fastcall TFormAtas::GeraCabecalho(String nome_arq)
{
		//
        // Esta fun��o cria o arquivo nome_arq e gera a tabela do cabe�alho
        //

		FILE* arq = fopen(AnsiString(nome_arq).c_str(), "wt");

		fprintf(arq, "\{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1046{\\fonttbl{\\f0\\fswiss\\fcharset0 Arial;\}}\n");
		fprintf(arq, "\{\\colortbl ;\\red255\\green0\\blue0;\}\n");
		fprintf(arq, "\\viewkind4\\uc1\\pard\\f0\\fs20\\par\n\n");
		fprintf(arq, "\\paperw11906\\paperh16838\\margl1701\\margr1701\\margt1417\\margb1417\n\n");

		// Espaco para rubrica no header - adicionado em 11/02/12
		fprintf(arq, "\{\\header{\\fonttbl{\\f0\\fswiss\\fcharset0 Arial;\}}\n");
		fprintf(arq, "\{\\colortbl ;\\red255\\green0\\blue0;\}\n");
		fprintf(arq, "\\pard \\qr \\f0\\fs20  Folha n�: ________\\par \\qr Rubrica: ________ \\par \\qr \\fs10 Uso exclusivo Divis�o de Concursos \\par \}\n\n");

		// Construcao da tabela do cabecalho
		fprintf(arq, "\\trowd \\trgaph0 \\trqc\n");
        fprintf(arq, "\\cellx3636 \\cellx10000\n");
		fprintf(arq, "\\qc\n");

        // Carrega o logotipo
        TStringList *logo = new TStringList;
        String arq_logo = ExtractFilePath(Application->ExeName) + ExtractFileName("logo.fig");
        logo->LoadFromFile(arq_logo);
        for (int i=0; i<logo->Count; i++)
        {
			   fprintf(arq, AnsiString(logo->Strings[i]).c_str());
        }

        // Carrega demais informacoes do cabecalho
        //fprintf(arq, "\\cell \\pard \\intbl ", AnsiUpperCase(projeto.ministerio));
		fprintf(arq, "\\cell \\pard \\intbl %s\n", AnsiString(FormCabecalho->RichEdit1->Lines->Strings[0]).c_str());
        for (int i=1; i<FormCabecalho->RichEdit1->Lines->Count; i++)
        {
			 fprintf(arq, "\\par %s\n", AnsiString(FormCabecalho->RichEdit1->Lines->Strings[i]).c_str());
        }

	   /* // Ministerio
        fprintf(arq, "\\cell \\pard \\intbl %s\n", AnsiUpperCase(projeto.ministerio));

        // Universidade
        //if (FormConfiguracao->CheckBox7->Checked)
                fprintf(arq, "\\par %s\n", AnsiUpperCase(projeto.universidade));

        // Centro
        //if (FormConfiguracao->CheckBox8->Checked)
				fprintf(arq, "\\par %s\n", AnsiUpperCase(projeto.centro));

        // Campus
        //if (FormConfiguracao->CheckBox9->Checked)
                fprintf(arq, "\\par CAMPUS %s\n", AnsiUpperCase(projeto.campus));

        // Departamento
        //if (FormConfiguracao->CheckBox10->Checked)
                fprintf(arq, "\\par %s\n", AnsiUpperCase(projeto.departamento));
        */
//		String categoria;
//		switch (projeto.classe)
//		{
//				case 0: categoria = "ADJUNTO";
//                        break;
//				case 1: categoria = "ASSISTENTE";
//                        break;
//				case 2: categoria = "AUXILIAR";
//						break;
//				default: categoria = "?????";
//						break;
//        }
        // Classe
		//fprintf(arq, "\\par CONCURSO P�BLICO PARA PROFESSOR %s\n", categoria);

        // �rea
        //if (FormConfiguracao->CheckBox4->Checked)
        //        fprintf(arq, "\\par �REA: %s\n", AnsiUpperCase(projeto.area));

        // Sub-�rea
        //if (FormConfiguracao->CheckBox5->Checked)
        //        fprintf(arq, "\\par SUB-�REA: %s\n", AnsiUpperCase(FormConfiguracao->LabeledEdit3->Text));

        fprintf(arq, "\\cell \\pard \\intbl \\row\n");

        fclose(arq);
}


//---------------------------------------------------------------------------


void __fastcall TFormAtas::FechaRTF(String nome_arq)
{
        //
        // Esta fun��o finaliza o arquivo nome_arq adicionando o } no final
        //
        using namespace std;

        fstream arq;

        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);
        arq << '}' << endl;
        arq.close();

}
//---------------------------------------------------------------------------


void __fastcall TFormAtas::Assinaturas(String nome_arq, TDate data_ata)
{
        //
        // Esta fun��o inclui as assinaturas da banca no final da ata
        //

		FILE* arq = fopen(AnsiString(nome_arq).c_str(), "a+t");

        // Data e Assinatura
              unsigned short ano, mes, dia;
				data_ata.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				fprintf(arq, "\\pard  \\par  \\par \\par \n");
				fprintf(arq, "\\qr \\par %s, %s de %s de %s.\n\n", AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str(), AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str(), AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str(), AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str());

			  fprintf(arq, "\\par  \\pard  \\par \\par \\par \\par \n");

		fprintf(arq, "\\trowd \\trgaph0 \\trqc\n");
		fprintf(arq, "\\cellx3636 \\cellx7236 \\celx10836\n");
		fprintf(arq, "\\qc ______________________________ \\cell \\pard \\intbl \\qc ______________________________ \\cell \\pard \\intbl \\row\n");
		fprintf(arq, "\\trowd \\trgaph0 \\trqc\n");
		fprintf(arq, "\\cellx3636 \\cellx7236 \\celx10836\n");
		fprintf(arq, "\\qc %s \\cell \\pard \\intbl \\qc %s \\cell \\pard \\intbl \\row\n", examinador[0].nome_completo.c_str(), examinador[1].nome_completo.c_str());

		fprintf(arq, "\\trowd \\trgaph0 \\trqc\n");
		fprintf(arq, "\\cellx3636 \\cellx7236 \\celx10836\n");
		fprintf(arq, "\\qc - presidente - \\cell \\pard \\intbl \\qc  \\cell \\pard \\intbl \\row\n");


		fprintf(arq, "\\pard  \\par \\par \\par \\par\n");
		fprintf(arq, "\\par \\trowd \\trgaph0 \\trqc \\cellx3636\n");
		fprintf(arq, "\\qc ______________________________ \\cell \\pard \\intbl \\row\n");
		fprintf(arq, "\\trowd \\trgaph0 \\trqc \\cellx3636\n");
		fprintf(arq, "\\qc %s \\cell \\pard \\intbl \\row\n", examinador[2].nome_completo.c_str());
		fprintf(arq, "\\pard\n");


		fclose(arq);



}



void __fastcall TFormAtas::TabSheet2Show(TObject *Sender)
{
		//ComboBox4->Items = FormConfiguracao->List_Candidatos->Items;
		//ComboBox4->ItemIndex = -1;
		//ComboBox5->Items = FormConfiguracao->List_Banca->Items;
		//ComboBox5->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button3Click(TObject *Sender)
{
		// ---------------
		// Ata de realizacao da prova escrita - id=1

		String identificador = "1";
		String titulo = "Realiza��o da prova escrita";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit11->Text);
		AnsiString nome_arq =  ExtractFileName(Edit11->Text);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView1->Items->Delete(indice_item);
								nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 NroDlg->Nro->Text = IntToStr(nro_ata);
						 int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
						 else
								return;

		// ---------------

		GeraCabecalho(nome_arq);

		int ip = FormEscrita->CSpinEdit1->Value;
		String texto_ponto_sorteado = Form1->RetiraNumero(FormEscrita->ListBox1->Items->Strings[ip-1]);
		unsigned short dia, mes, ano;
		DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
		ComboBox2->ItemIndex = mes-1;
		//ComboBox3->ItemIndex = ano % 100;
		//String nome_dia = ComboBox1->Items->Strings[dia-1];
		String nome_mes = ComboBox2->Items->Strings[mes-1];
		//String nome_ano = ComboBox3->Items->Strings[ano % 100];
		unsigned short hora, minuto, segundo, milisegundo;
		FormEscrita->DateTimePicker1->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo); // Hora do sorteio do ponto


			 FILE* arq = fopen(nome_arq.c_str(), "a+t"); // abre no modo append

			 // T�tulo
			 fprintf(arq, "\\pard \n \\par \\par \\par\n");
			 fprintf(arq, "\\ql \\b Ata Nro %i - %s \\b0 \n", nro_documento, AnsiString(titulo).c_str());


			 fprintf(arq, "\\par \n \\pard \\par \\par\n\\qj ");

		// Alterado em 11/02/12
		fprintf(arq, "%s, ", AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)));
		fprintf(arq, "%s", AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)));

		/*

		if (dia==1)
			fprintf(arq, "Ao %s dia do m�s de %s de %s, ", AnsiString(Form1->ConverteLiteral((int)dia, 3)).c_str(), AnsiString(nome_mes).c_str(), AnsiString(Form1->ConverteLiteral((int)ano,1)).c_str());
		else
			fprintf(arq, "Aos %s dias do m�s de %s de %s, ", AnsiString(Form1->ConverteLiteral((int)dia, 1)).c_str(), AnsiString(nome_mes).c_str(), AnsiString(Form1->ConverteLiteral((int)ano,1)).c_str());

		if (hora==1 || hora==0)
			fprintf(arq, "� %s hora", AnsiString(Form1->ConverteLiteral((int)hora, 0)).c_str());
		else
			fprintf(arq, "�s %s horas", AnsiString(Form1->ConverteLiteral((int)hora, 0)).c_str());
		if (int(minuto)!=0)
		{
			if (int(minuto==1))
				fprintf(arq, " e %s minuto", AnsiString(Form1->ConverteLiteral((int)minuto, 1)).c_str());
			else
				fprintf(arq, " e %s minutos", AnsiString(Form1->ConverteLiteral((int)minuto, 1)).c_str());
		}
		// --
		 */
		fprintf(arq, ", na %s, ", AnsiString(FormEscrita->Edit2->Text).c_str(), AnsiString(FormConfiguracao->LabeledEdit6->Text).c_str());


//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//		}
		fprintf(arq, "reuniu-se a Comiss�o Examinadora do %s para Professor %s ",  projeto.tipo_concurso.c_str(), projeto.categoria.c_str());
		fprintf(arq, "para o campus %s na �rea de %s, ", projeto.campus, projeto.area);
		fprintf(arq, "e os candidatos presentes conforme lista de presen�a em anexo, para realiza��o da Prova Escrita do referido %s. A prova foi iniciada com o sorteio do ponto a ser desenvolvido pelos candidatos, de uma lista de %s pontos ", projeto.tipo_concurso.c_str(), AnsiString(Form1->ConverteLiteral(FormEscrita->ListBox1->Items->Count, 1)).c_str());
		fprintf(arq, "previamente elaborados pela Comiss�o Examinadora e anexada ao processo.  O ponto sorteado foi o de n�mero %s ", AnsiString(Form1->ConverteLiteral(FormEscrita->CSpinEdit1->Value, 1)).c_str());
		fprintf(arq, "com o seguinte teor: \\b %s \\b0. ", AnsiString(Form1->RetiraNumero(FormEscrita->ListBox1->Items->Strings[FormEscrita->CSpinEdit1->Value-1])).c_str());
		FormEscrita->DateTimePicker6->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

		// Alterado em 15/02/2012
		fprintf(arq, "%s", AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 1)));
		//fprintf(arq, "�s %s horas e %s minutos foi iniciada a contagem do prazo de dura��o da prova, que teve o seu encerramento �s ", AnsiString(Form1->ConverteLiteral(hora, 0)).c_str(), AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str());
		fprintf(arq, " foi iniciada a contagem do prazo de dura��o da prova, que teve o seu encerramento ", AnsiString(Form1->ConverteLiteral(hora, 0)).c_str(), AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str());


		FormEscrita->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
		fprintf(arq, "%s", AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)));

		fprintf(arq, ". A prova escrita de cada um dos candidatos foi acondicionada em um envelope individual, devidamente lacrado e rubricado pelo candidato e pela Comiss�o Examinadora. Encerrada a prova, que transcorreu sem anormalidades, foi lavrada a presente ata.", AnsiString(Form1->ConverteLiteral(hora, 0)).c_str(), AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str());

		fprintf(arq, "\\par \n \\pard \\par \n");

		fclose(arq);

		Assinaturas(nome_arq, DataG);
		FechaRTF(nome_arq);

		// Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;

        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button4Click(TObject *Sender)
{
        // ---------------
		// Ata de leitura da prova escrita - id=42

		// conferido versao 3.4

		String identificador = "42";
        String titulo = "Ata de Leitura da prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit11->Text);
		String nome_arq =  ExtractFileName(Edit13->Text);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
								return;

        // ---------------

		GeraCabecalho(nome_arq);

        //int ip = FormEscrita->CSpinEdit1->Value;
        //String texto_ponto_sorteado = Form1->RetiraNumero(FormEscrita->ListBox1->Items->Strings[ip-1]);
        unsigned short dia, mes, ano;
		DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
        //String nome_dia = ComboBox1->Items->Strings[dia-1];
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        //String nome_ano = ComboBox3->Items->Strings[ano % 100];
        unsigned short hora, minuto, segundo, milisegundo;
        FormEscrita->DateTimePicker5->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo); // Hora do inicio da sessao


			 FILE* arq = fopen(AnsiString(nome_arq).c_str(), "a+t"); // abre no modo append

             // T�tulo
             fprintf(arq, "\\pard \n \\par \\par \\par\n");
			 fprintf(arq, "\\ql \\b Ata Nro %i - %s \\b0 \n", nro_documento, AnsiString(titulo).c_str());



				 fprintf(arq, "\\par \n \\pard \\par \\par\n\\qj ");

		// Alterado em 11/02/12
		fprintf(arq, "%s, ", AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)));
		fprintf(arq, "%s", AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)));


		//fprintf(arq, "\\qj Aos %s dias do m�s de %s de %s, ", AnsiString(Form1->ConverteLiteral((int)dia, 1)).c_str(), AnsiString(nome_mes).c_str(), AnsiString(Form1->ConverteLiteral((int)ano,1)).c_str());
		//fprintf(arq, "�s %s horas e %s minutos, ", AnsiString(Form1->ConverteLiteral((int)hora, 0)).c_str(), AnsiString(Form1->ConverteLiteral((int)minuto, 1)).c_str());
		fprintf(arq, ", na %s, ", AnsiString(FormEscrita->Edit1->Text).c_str(), AnsiString(FormConfiguracao->LabeledEdit6->Text).c_str());

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//		}
		fprintf(arq, "reuniu-se a Comiss�o Examinadora do %s para Professor %s ", projeto.tipo_concurso.c_str(), projeto.categoria.c_str());
		fprintf(arq, "para o campus %s na �rea de %s, ", projeto.campus, projeto.area);
		fprintf(arq, "e os candidatos presentes conforme lista de presen�a em anexo, para realiza��o da Leitura da Prova Escrita do referido %s. ", projeto.tipo_concurso.c_str());
		fprintf(arq, "Para cada candidato, foi feita a abertura do envelope que continha a sua prova e entregues as c�pias reprogr�ficas aos membros da Comiss�o Examinadora para que pudessem acompanhar a leitura dos originais. ");
        fprintf(arq, "Os candidatos procederam a leitura e as provas foram novamente acondicionadas nos envelopes");



        // Verifica se algum candidato est� ausente
        int ha_ausente = 0;
        vector<String> ausentes;
        for (int i=0; i<FormEscrita->CheckListBox2->Items->Count; i++)
		{
                if (!FormEscrita->CheckListBox2->Checked[i])
                {
                        ha_ausente++;
                        ausentes.push_back(FormEscrita->CheckListBox2->Items->Strings[i]);
				}
        }
        if (ha_ausente>0)
        {
                String plural;
                if (ha_ausente>1) plural = "s";
                else plural = "";
                                fprintf(arq, ". Registra-se a aus�ncia do%s candidato%s ", AnsiString(plural).c_str(), AnsiString(plural).c_str());
				//arq << "Registra-se a aus�ncia do" << AnsiString(plural).c_str() << " candidato" << AnsiString(plural).c_str() << " ";
                for (unsigned int j=ausentes.size(); j>0; j--)
                {
                        fprintf(arq, "%s", AnsiString(ausentes[j-1]).c_str());
                        //arq << AnsiString(ausentes[j-1]).c_str();
                        if (j == 2)
                                fprintf(arq, " e ");
                                //arq << " e ";
                        else
                                if (j>2)
                                        fprintf(arq, ", ");
                                        //arq << ", ";
                                //else
                                //        arq << ".";
                }
        }




        fprintf(arq, ". Encerrada a sess�o, que transcorreu sem anormalidades, foi lavrada a presente ata.");

        fprintf(arq, "\\par \n \\pard \\par \n");

        fclose(arq);

        Assinaturas(nome_arq, DataG);
        FechaRTF(nome_arq);

       // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;

		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------


}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button5Click(TObject *Sender)
{

		// ---------------
		// Planilha demonstrativa de prova escrita - por candidato e por examinador - id=2_ic_ie
		int ic = FormEscrita->ListBox2->ItemIndex;
		int ie = FormEscrita->ListBox3->ItemIndex;
		String nome_arq1 = "escrita_planilha_c" + IntToStr(ic) + "_e" + IntToStr(ie) + ".rtf";

		String identificador = "3_" + IntToStr(ic) + "_" + IntToStr(ie);
		String titulo = "Planilha de notas - prova escrita - " + FormEscrita->ListBox2->Items->Strings[ic] + " - " + examinador[ie].nome;
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------

		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);

		int ie = FormEscrita->ListBox3->ItemIndex;
		int ic = FormEscrita->ListBox2->ItemIndex;

		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b AVALIA��O INDIVIDUAL DA PROVA ESCRITA \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\ql \\b CANDIDATO: " << AnsiString(FormEscrita->ListBox2->Items->Strings[ic]).c_str() << " \\b0 \\par \\par" << endl;
		arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome_completo.c_str() << " \\b0 " << endl;
		arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		// Primeira celula
		arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
		// Segunda celula
		arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
		arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
		// Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

		for (int i=1; i<=FormEscrita->ValueListEditor1->Strings->Count; i++)
		{
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				// Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormEscrita->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
				// Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormEscrita->ValueListEditor1->Values[FormEscrita->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
				// Terceira celula (vazia)
				arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
				// Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

		 }
		 // Subtotal
		 arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		  // Configuracao das celulas
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		  // Primeira celula
		  arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
		  // Segunda celula   (vazia)
		  arq << "\\pard \\intbl \\qc  \\cell" << endl;
		  // Fim da linha
		  arq << "\\pard \\intbl \\row" << endl;





		// Assinatura do examinador

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << examinador[ie].nome_completo.c_str() << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);


		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "0";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);

		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------


}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button6Click(TObject *Sender)
{


		// Planilha demonstrativa de prova escrita - criterios de avaliacao id = 4

		String nome_arq1 = "escrita_criterios.rtf";

		String identificador = "4";
		String titulo = "Crit�rios de avalia��o - prova escrita";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------
        //;; ********** Obs: esta fun��o imprime o que est� mostrado no FormEscrita!!

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b CRIT�RIOS DE AVALIA��O DA PROVA ESCRITA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        //arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=1; i<=FormEscrita->ValueListEditor1->Strings->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormEscrita->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormEscrita->ValueListEditor1->Values[FormEscrita->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
                //arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }
         // Subtotal
         arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
          // Configuracao das celulas
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
          // Primeira celula
          arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
          // Segunda celula   (vazia)
          arq << "\\pard \\intbl \\qc 10 \\cell" << endl;
          // Fim da linha
          arq << "\\pard \\intbl \\row" << endl;



        arq.close();

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker7->Date);
		Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "0";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        //nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button7Click(TObject *Sender)
{

        // Planilha demonstrativa de prova escrita - rela��o de pontos id = 4

        String nome_arq1 = "escrita_pontos.rtf";

        String identificador = "6";
        String titulo = "Rela��o de pontos - prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =   ExtractFileName(nome_arq1);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b RELA��O DE PONTOS PARA A PROVA ESCRITA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Especifica��es do ponto \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        //arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=0; i<FormEscrita->ListBox1->Items->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql " << i+1 << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\ql " << AnsiString(Form1->RetiraNumero(FormEscrita->ListBox1->Items->Strings[i])).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
                //arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "0";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        //nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button8Click(TObject *Sender)
{
        // ---------------
		// Lista de presenca realizacao da prova escrita - id=7

		String identificador = "7";
		String titulo = "Lista de presen�a na realiza��o da prova escrita";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit18->Text);
        String nome_arq =   ExtractFileName(Edit18->Text);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
				for (int i=0; i<Form1->ListView2->Items->Count; i++)
                {
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_lista);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
								return;

        // ---------------


        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        //int nro_lista = StrToInt(Edit17->Text);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Realiza��o da Prova Escrita \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=0; i<FormEscrita->CheckListBox1->Items->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(FormEscrita->CheckListBox1->Items->Strings[i]).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView2->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_lista++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------


void __fastcall TFormAtas::Button10Click(TObject *Sender)
{
        // ---------------
		// Ata de julgamento da prova escrita - id=5
		// Conferido versao 3.4

        String identificador = "5";
        String titulo = "Julgamento da prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit20->Text);
        String nome_arq =  ExtractFileName(Edit20->Text);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
		}
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {

						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

				if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia, 1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
		String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
		FormEscrita->DateTimePicker8->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Julgamento da prova escrita \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;


		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " <<AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormEscrita->Edit3->Text).c_str();

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//        {
//				case 0: categoria = "Adjunto";
//						break;
//                case 1: categoria = "Assistente";
//						break;
//                case 2: categoria = "Auxiliar";
//                        break;
//				default: categoria = "?????";
//						break;
//		}

		arq << ", reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
        arq << " para realizar o Julgamento da Prova Escrita do referido " <<  projeto.tipo_concurso.c_str() << ". ";
        arq << "As notas da prova de cada candidato, concedidas por cada um dos examinadores, foram acondicionadas em envelopes lacrados, ";
        arq << "para serem abertas somente na Sess�o P�blica para Divulga��o dos Resultados. Encerrados os trabalhos e nada mais havendo a tratar, lavrou-se a presente ata.";
        arq << "\\par \\pard \\par" << endl;

        arq.close();

        Assinaturas(nome_arq, DataG);
        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button11Click(TObject *Sender)
{
        // ---------------
		// Ata de sorteio do ponto - prova didatica - id=10
		// Conferido versao 3.4

        String identificador = "10";
        String titulo = "Sorteio do ponto da prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit21->Text);
        String nome_arq =  ExtractFileName(Edit21->Text);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
		{
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
						 NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------

        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        // Obs.: nao esta implementado o caso em que os sorteios acontecem em mais de um dia
        // A data dos sorteios consideradas sao  a data do primeiro sorteio
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
		String nome_dia = Form1->ConverteLiteral(dia, 1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
        //hor_sor[0]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Sorteio dos Pontos para a Prova Did�tica \\b0" << endl;

		//arq << "\\par \\pard \\par \\par" << endl;


		arq << "\\par \\pard \\par \\par \\qj" << endl;


		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		//arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " <<AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

		//arq << " �s " << hora << " horas e " << minuto << " minutos, ";
		arq <<", na " << AnsiString(FormDidatica->Edit1->Text).c_str() << ",";

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//		}
		arq << " reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
        arq << " para a realiza��o do Sorteio dos Pontos para a Prova Did�tica do referido " <<  projeto.tipo_concurso.c_str() << ". ";

        for (unsigned int i=0; i<lab.size(); i++)
        {
                hor_sor[i]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
                String artigo;
                int sex=PegaSexo(lab[i]->Caption);
                if (sex==0) artigo = "o";
                else artigo = "a";

                if (comp_sor[i]->Checked)
                {
                        int p = ponto[i]->ItemIndex;
                        String nome_p = Form1->RetiraNumero(ponto[i]->Items->Strings[p]);

						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab[i]->Caption).c_str() << " compareceu " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
						arq << " e sorteou o ponto de n�mero " << AnsiString(Form1->ConverteLiteral(p+1, 1)).c_str();
						arq << " com o seguinte t�tulo: " << AnsiString(nome_p).c_str() << ". ";
                }
                else
                {
                        arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab[i]->Caption).c_str() << " n�o compareceu. ";
                }
		}

        arq << "Encerrados os trabalhos e nada mais havendo a tratar, lavrou-se a presente ata." << endl;
        arq << "\\par \\pard \\par" << endl;


        arq.close();

        Assinaturas(nome_arq, DataG);
        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button12Click(TObject *Sender)
{
                // ---------------
        // Ata de realizacao da prova didatica - id=11
		// Conferido versao 3.4

        String identificador = "11";
        String titulo = "Realiza��o da prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit22->Text);
        String nome_arq =  ExtractFileName(Edit22->Text);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------

        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        // Obs.: nao esta implementado o caso em que os sorteios acontecem em mais de um dia
        // A data dos sorteios consideradas sao  a data do primeiro sorteio
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia,1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano,1);
        unsigned short hora, minuto, segundo, milisegundo;
        //hor_sor[0]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\ql \\b Ata Nro " << nro_documento << " - Realiza��o da Prova Did�tica \\b0" << endl;

		//arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;


		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		//arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();


		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

        //arq << " �s " << hora << " horas e " << minuto << " minutos, ";
		arq <<", na " << AnsiString(FormDidatica->Edit2->Text).c_str() << ",";

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//		}
		arq << " reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
		arq << " para a realiza��o da Avalia��o da Prova Did�tica do referido " <<  projeto.tipo_concurso.c_str() << ". ";

		for (unsigned int i=0; i<lab.size(); i++)
		{
				hor_apr[i]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
				String artigo;
				int sex = PegaSexo(lab[i]->Caption);
				if (sex==0) artigo = "o";
				else artigo = "a";
				if (comp_apr[i]->Checked)
				{
						int p = ponto[i]->ItemIndex;
						String nome_p = Form1->RetiraNumero(ponto[i]->Items->Strings[p]);

						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab[i]->Caption).c_str() << " compareceu " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
						arq << " e apresentou o ponto de n�mero " << AnsiString(Form1->ConverteLiteral(p+1,1)).c_str();
						arq << " com o seguinte t�tulo: " << AnsiString(nome_p).c_str() << ". ";
                }
                else
                {
						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab[i]->Caption).c_str() << " n�o compareceu. ";
                }
        }

        arq << "Durante a apresenta��o de cada candidato, os examinadores fizeram o seu julgamento individual ";
        arq << "segundo crit�rios previamente estabelecidos e anexados ao presente processo. ";
        arq << "As planilhas com as notas dos candidatos foram acondicionadas em envelopes individuais, ";
        arq << "por examinador. Os envelopes foram guardados para serem abertos somente na Sess�o P�blica para Divulga��o dos Resultados do " <<  projeto.tipo_concurso.c_str() << ". ";
        arq << "As apresenta��es de cada candidato foram gravadas e as grava��es foram anexadas ao processo do " <<  projeto.tipo_concurso.c_str() << ". " << endl;
        arq << "Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata. " << endl;
        arq << "\\par \\pard \\par" << endl;


        arq.close();

        Assinaturas(nome_arq, DataG);
        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button13Click(TObject *Sender)
{
		// Planilha demonstrativa de prova didatica - rela��o de pontos id = 16

        String nome_arq1 = "didatica_pontos.rtf";

        String identificador = "16";
        String titulo = "Rela��o de pontos - prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
								indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

		// ---------------

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b RELA��O DE PONTOS PARA A PROVA DID�TICA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		// Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Especifica��es do ponto \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        //arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=0; i<FormDidatica->ListBox1->Items->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql " << i+1 << " \\cell" << endl;
                // Segunda celula
                		arq << "\\pard \\intbl \\ql " << AnsiString(Form1->RetiraNumero(FormDidatica->ListBox1->Items->Strings[i])).c_str() << " \\cell\n" << endl;
				// Terceira celula (vazia)
                //arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);


        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "0";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------




}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button14Click(TObject *Sender)
{
        // ---------------
        // Planilha demonstrativa de prova didatica - por candidato e por examinador - id=14_ic_ie
        int ic = FormDidatica->ListBox2->ItemIndex;
        int ie = FormDidatica->ListBox3->ItemIndex;
        String nome_arq1 = "didatica_planilha_c" + IntToStr(ic) + "_e" + IntToStr(ie) + ".rtf";

        String identificador = "14_" + IntToStr(ic) + "_" + IntToStr(ie);
        String titulo = "Planilha de notas - prova did�tica - " + FormDidatica->ListBox2->Items->Strings[ic] + " - " + examinador[ie].nome;
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq = ExtractFileName(nome_arq1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);

        using namespace std;


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b AVALIA��O INDIVIDUAL DA PROVA DID�TICA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        arq << "\\ql \\b CANDIDATO: " << AnsiString(FormDidatica->ListBox2->Items->Strings[ic]).c_str() << " \\b0 \\par \\par" << endl;
		arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome_completo.c_str() << " \\b0 " << endl;
        arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=1; i<=FormDidatica->ValueListEditor1->Strings->Count; i++)
        {
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormDidatica->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormDidatica->ValueListEditor1->Values[FormDidatica->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }
         // Subtotal
         arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
          // Configuracao das celulas
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
          // Primeira celula
          arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
          // Segunda celula   (vazia)
          arq << "\\pard \\intbl \\qc  \\cell" << endl;
          // Fim da linha
          arq << "\\pard \\intbl \\row" << endl;





        // Assinatura do examinador

        arq << "\\pard  \\par \\par \\par \\par" << endl;
        arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
        arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
        arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << examinador[ie].nome_completo.c_str() << " \\cell \\pard \\intbl \\row" << endl;
        arq << "\\pard" << endl;

        //Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
        arq.close();

        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
		} // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------


}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button15Click(TObject *Sender)
{
                // ---------------
        // Lista de presenca realizacao da prova didatica - id=12

        String identificador = "12";
        String titulo = "Lista de presen�a na realiza��o da prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit25->Text);
        String nome_arq =  ExtractFileName(Edit25->Text);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
		{
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView2->Items->Count; i++)
                {
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
								continua = true;
                        }
                }

                if (continua)
                {
						 NroDlg->Nro->Text = IntToStr(nro_lista);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);


		// T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Realiza��o da Prova Did�tica \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

		//arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (unsigned int i=0; i<lab.size(); i++)
		{
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
				// Segunda celula
                arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(lab[i]->Caption).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView2->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        nro_lista++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button16Click(TObject *Sender)
{
                // ---------------
		// Lista de presenca no sorteio da prova didatica - id=13

        String identificador = "13";
        String titulo = "Lista de presen�a no sorteio da prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit26->Text);
        String nome_arq =  ExtractFileName(Edit26->Text);
		FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView2->Items->Count; i++)
                {
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
						}
                }
                if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
								Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_lista);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = 6000; //StrToInt(Edit7->Text);
	int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos no Sorteio do Ponto da Prova Did�tica \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
		// Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
        // Terceira celula
        arq << "\\pard \\intbl \\qc \\b Data \\b0 \\cell\n" << endl;
        // Quarta celula
        arq << "\\pard \\intbl \\qc \\b Hor�rio \\b0 \\cell\n" << endl;
        // Quinta celula
        arq << "\\pard \\intbl \\qc \\b Ponto sorteado \\b0 \\cell\n" << endl;
        // Sexta celula
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (unsigned int i=0; i<lab.size(); i++)
        {
                unsigned short hora, minuto, segundo, milisegundo;
                hor_sor[i]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
                unsigned short dia, mes, ano;
                dat_sor[i]->Date.DecodeDate(&ano, &mes, &dia);

				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc3 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc4 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;

                // Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
                // Segunda celula
                arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(lab[i]->Caption).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula
                arq << "\\pard \\intbl \\qc \\fs20 " << dia << "/" << mes << "/" << ano << " \\cell\n" << endl;
                // Terceira celula
                arq << "\\pard \\intbl \\qc \\fs20 " << hora << ":" << minuto << "h" << " \\cell\n" << endl;
                // Quarta celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Quinta celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

		arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

		// Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView2->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_lista++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button17Click(TObject *Sender)
{
                        // ---------------
        // Ata de realizacao da defesa de memorial - id=17
		// Conferido versao 3.4

        String identificador = "17";
		String titulo = "Realiza��o da defesa de memorial de trajet�ria acad�mico";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit27->Text);
        String nome_arq =  ExtractFileName(Edit27->Text);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
						{
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
				{
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        GeraCabecalho(nome_arq);

        using namespace std;


		unsigned short dia, mes, ano;
        // Obs.: nao esta implementado o caso em que os sorteios acontecem em mais de um dia
        // A data dos sorteios consideradas sao  a data do primeiro sorteio
        dat_def[0]->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia, 1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
        //hor_sor[0]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\ql \\b Ata Nro " << nro_documento << " - Realiza��o da Prova de Defesa de Memorial de Trajet�ria Acad�mica \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;

		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		//arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();


		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

        //arq << " �s " << hora << " horas e " << minuto << " minutos, ";
		arq <<", na " << AnsiString(FormDefesaProjeto->Edit1->Text).c_str() << ",";

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }
		arq << " reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
        arq << " para a realiza��o da Prova de Defesa de Memorial de Trajet�ria Acad�mica do referido " <<  projeto.tipo_concurso.c_str() << ". ";

		for (unsigned int i=0; i<lab_def.size(); i++)
        {
				hor_def[i]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
				//int p = ponto[i]->ItemIndex;
                //String nome_p = ponto[i]->Items->Strings[p];
                String artigo;
                        if(PegaSexo(lab_def[i]->Caption) == 0) artigo = "o";    // modificado
                        else artigo = "a";
                if (comp_def[i]->Checked)
				{

						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab_def[i]->Caption).c_str() << " compareceu " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
						arq << " e apresentou o seu memorial de trajet�ria acad�mica. " ;
                }
                else
                {
						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab_def[i]->Caption).c_str() << " n�o compareceu. ";
                }
        }

        arq << "Ap�s a apresenta��o de cada candidato, os examinadores fizeram os questionamentos e  ";
        arq << "realizaram a avalia��o segundo crit�rios previamente estabelecidos e anexados ao presente processo. ";
        arq << "As planilhas com as notas dos candidatos foram acondicionadas em envelopes individuais, ";
		arq << "por examinador. Os envelopes foram guardados para serem abertos somente na Sess�o P�blica para Divulga��o dos Resultados do " <<  projeto.tipo_concurso.c_str() << ". ";
        arq << "As apresenta��es de cada candidato foram gravadas e as grava��es foram anexadas ao processo do " <<  projeto.tipo_concurso.c_str() << ". " << endl;
        arq << "Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata. " << endl;
        arq << "\\par \\pard \\par" << endl;


        arq.close();

        Assinaturas(nome_arq, dat_def[0]->Date);
        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
		ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button18Click(TObject *Sender)
{
				// ---------------
		// Lista de presenca realizacao da defesa de memorial - id=18

        String identificador = "18";
        String titulo = "Lista de presen�a na realiza��o da defesa de memorial de trajet�ria acad�mica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit28->Text);
        String nome_arq =  ExtractFileName(Edit28->Text);
		FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
		else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView2->Items->Count; i++)
                {
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
								continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
								Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
                                continua = true;
                        }
                }

                if (continua)
				{
                         NroDlg->Nro->Text = IntToStr(nro_lista);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


		GeraCabecalho(nome_arq);


        using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);


        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Realiza��o da Prova de Defesa de Memorial de Trajet�ria Acad�mica \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
		// Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

		for (unsigned int i=0; i<lab_def.size(); i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
                // Segunda celula
                arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(lab_def[i]->Caption).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula (vazia)
				arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView2->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_lista++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button19Click(TObject *Sender)
{
        // ---------------
		// Planilha demonstrativa de prova defesa memorial - por candidato e por examinador - id=20_ic_ie
        int ic = FormDefesaProjeto->ListBox2->ItemIndex;
        int ie = FormDefesaProjeto->ListBox3->ItemIndex;
        String nome_arq1 = "defesa_planilha_c" + IntToStr(ic) + "_e" + IntToStr(ie) + ".rtf";

        String identificador = "20_" + IntToStr(ic) + "_" + IntToStr(ie);
        String titulo = "Planilha de notas - prova defesa memorial - " + FormDefesaProjeto->ListBox2->Items->Strings[ic] + " - " + examinador[ie].nome;
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
		{
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
				bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
						}
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
						 int nro_documento = 0;

        // ---------------

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);

        using namespace std;


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b AVALIA��O INDIVIDUAL DA PROVA DE DEFESA DE MEMORIAL DE TRAJET�RIA ACAD�MICA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\ql \\b CANDIDATO: " << AnsiString(FormDefesaProjeto->ListBox2->Items->Strings[ic]).c_str() << " \\b0 \\par \\par" << endl;
		arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome_completo.c_str() << " \\b0 " << endl;
        arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

		for (int i=1; i<=FormDefesaProjeto->ValueListEditor1->Strings->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormDefesaProjeto->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
                // Segunda celula
                arq << "\\pard \\intbl \\qc " << AnsiString(FormDefesaProjeto->ValueListEditor1->Values[FormDefesaProjeto->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

         }
         // Subtotal
         arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
          // Configuracao das celulas
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
          // Primeira celula
          arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
          // Segunda celula   (vazia)
          arq << "\\pard \\intbl \\qc  \\cell" << endl;
		  // Fim da linha
          arq << "\\pard \\intbl \\row" << endl;





		// Assinatura do examinador

        arq << "\\pard  \\par \\par \\par \\par" << endl;
        arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
        arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
        arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << examinador[ie].nome_completo.c_str() << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

        //Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
        arq.close();

        FechaRTF(nome_arq);
        // Atualiza o ListView
		TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button20Click(TObject *Sender)
{


        // Planilha demonstrativa de defesa de memorial - criterios de avaliacao id = 19

        String nome_arq1 = Edit30->Text;

		String identificador = "19";
        String titulo = "Crit�rios de avalia��o - prova defesa de memorial acad�mico";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
		{
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------


		int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


        GeraCabecalho(nome_arq);


        using namespace std;
		fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b CRIT�RIOS DE AVALIA��O DA PROVA DE DEFESA DE MEMORIAL DE TRAJET�RIA ACAD�MICA \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
		// Segunda celula
        arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        //arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

        for (int i=1; i<=FormDefesaProjeto->ValueListEditor1->Strings->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormDefesaProjeto->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
                // Segunda celula
                arq << "\\pard \\intbl \\qc " << AnsiString(FormDefesaProjeto->ValueListEditor1->Values[FormDefesaProjeto->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
				//arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }
         // Subtotal
         arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		  // Configuracao das celulas
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
          // Primeira celula
          arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
		  // Segunda celula   (vazia)
          arq << "\\pard \\intbl \\qc 10 \\cell" << endl;
          // Fim da linha
          arq << "\\pard \\intbl \\row" << endl;



		arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        //nro_ata++;

		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button21Click(TObject *Sender)
{


        // Planilha demonstrativa de prova didatica - criterios de avaliacao id = 15

        String nome_arq1 = "didatica_criterios.rtf";

		String identificador = "15";
        String titulo = "Crit�rios de avalia��o - prova did�tica";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
		{
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
		{
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
						}
                }

                if (continua)
                {
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------

        int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b CRIT�RIOS DE AVALIA��O DA PROVA DID�TICA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

		//arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
        //arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=1; i<=FormDidatica->ValueListEditor1->Strings->Count; i++)
        {
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                //arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormDidatica->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormDidatica->ValueListEditor1->Values[FormDidatica->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
                // Terceira celula (vazia)
                //arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
                // Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

         }
         // Subtotal
         arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
          // Configuracao das celulas
          arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
          // Primeira celula
          arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
          // Segunda celula   (vazia)
          arq << "\\pard \\intbl \\qc 10 \\cell" << endl;
          // Fim da linha
          arq << "\\pard \\intbl \\row" << endl;



        arq.close();

		Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

       // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------


}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button22Click(TObject *Sender)
{
        // ---------------
        // Planilha demonstrativa do resultado final - por candidato e por examinador - id=21_ic
        int ic = FormResultado->PageControl1->ActivePageIndex-1;
        String nome_arq1 = "resultado_planilha_c" + IntToStr(ic) + ".rtf";

		String identificador = "21_" + IntToStr(ic);
        String titulo = "Planilha de notas - resultado - " + candidato[ic].nome;
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
		{
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
				bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
                {
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
						}
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
						 int nro_documento = 0;

        // ---------------
       /*
        int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);
		*/
		int tc1 = StrToInt(Edit5->Text);
		int tc2, tc3, tc4, tc5, tc6, tc7;
		int tcinicio = 3000;
		int tcdelta = 1500;
		int tc = tcinicio;
		tc2 = tc;
		if (projeto.habilita_prova_titulos) {
			 tc = tc+tcdelta;
		}
		tc3 = tc;
		if (projeto.habilita_prova_escrita) {
			 tc = tc+tcdelta;
		}
		tc4 = tc;
		if (projeto.habilita_prova_didatica) {
			 tc = tc+tcdelta;
		}
		tc5 = tc;
		if (projeto.habilita_prova_memorial) {
			 tc = tc+tcdelta;
		}
		tc6 = tc;
		if (projeto.habilita_prova_entrevista) {
			 tc = tc+tcdelta;
		}
		tc7 = tc;

//		int tc2 = 3000; //StrToInt(Edit6->Text);
//		int tc3 = 4500; //StrToInt(Edit7->Text);
//		int tc4 = 6000; // StrToInt(Edit8->Text);
//		int tc5 = 7500; // StrToInt(Edit9->Text);
//		int tc6 = 9000; //StrToInt(Edit10->Text);
//		int tc7 =
//		//int ie = FormDidatica->ListBox3->ItemIndex;


		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b PLANILHA DEMONSTRATIVA DE RESULTADO FINAL - POR CANDIDATO \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
		arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
		if (projeto.habilita_prova_titulos)
			arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
		if (projeto.habilita_prova_escrita)
			arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		if (projeto.habilita_prova_didatica)
			arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		if (projeto.habilita_prova_memorial)
			arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		if (projeto.habilita_prova_entrevista)
			arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc7 << endl;

		// Primeira celula
		arq << "\\pard  \\intbl \\qc \\b Examinador \\b0 \\cell" << endl;
		// Segunda celula
		if (projeto.habilita_prova_titulos)
			arq << "\\pard \\intbl \\qc \\b T�tulos \\b0 \\cell\n" << endl;
		// Terceira celula
		if (projeto.habilita_prova_escrita)
			arq << "\\pard \\intbl \\qc \\b Escrita \\b0 \\cell\n" << endl;
		// Quarta celula
		if (projeto.habilita_prova_didatica)
			arq << "\\pard \\intbl \\qc \\b Did�tica \\b0 \\cell\n" << endl;
		// Quinta celula
		if (projeto.habilita_prova_memorial)
			arq << "\\pard \\intbl \\qc \\b Memorial \\b0 \\cell\n" << endl;
		// Sexta celula
		if (projeto.habilita_prova_entrevista)
			arq << "\\pard \\intbl \\qc \\b Entrevista \\b0 \\cell\n" << endl;
		// Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

		for (int i=1; i<tabela[ic]->RowCount; i++)
		{
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				// Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
				if (projeto.habilita_prova_titulos)
					arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
				if (projeto.habilita_prova_escrita)
					arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
				if (projeto.habilita_prova_didatica)
					arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
				if (projeto.habilita_prova_memorial)
					arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				if (projeto.habilita_prova_entrevista)
					arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc7 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(tabela[ic]->Cells[0][i]).c_str() << " \\cell" << endl;
				// Segunda celula
				if (projeto.habilita_prova_titulos)
					arq << "\\pard \\intbl \\qc " << AnsiString(tabela[ic]->Cells[1][i]).c_str() << " \\cell\n" << endl;
				// Terceira celula
				if (projeto.habilita_prova_escrita)
					arq << "\\pard \\intbl \\qc " << AnsiString(tabela[ic]->Cells[2][i]).c_str() << " \\cell\n" << endl;
				// Quarta celula
				if (projeto.habilita_prova_didatica)
					arq << "\\pard \\intbl \\qc " << AnsiString(tabela[ic]->Cells[3][i]).c_str() << " \\cell\n" << endl;
				// Quinta celula
				if (projeto.habilita_prova_memorial)
					arq << "\\pard \\intbl \\qc " << AnsiString(tabela[ic]->Cells[4][i]).c_str() << " \\cell\n" << endl;
				// Sexta celula
				if (projeto.habilita_prova_entrevista)
					arq << "\\pard \\intbl \\qc " << AnsiString(tabela[ic]->Cells[5][i]).c_str() << " \\cell\n" << endl;

				// Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

		 }
		 // Nota final
		 arq << "\\pard  \\par \\par \\par" << endl;
		 arq << "NOTA FINAL: " << AnsiString(nota_final[ic]->Caption).c_str();

		arq.close();

		Assinaturas(nome_arq, DataG);
		//Assinaturas(nome_arq, FormResultado->DateTimePicker1->Date);

		FechaRTF(nome_arq);
		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);

		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------




void __fastcall TFormAtas::Button23Click(TObject *Sender)
{
		// ---------------
        // Ata de instala��o da comiss�o organizadora - id=22
		// Conferido versao 3.4

		String identificador = "22";
		String titulo = "Instala��o da comiss�o examinadora";
        String arquivo1 = "abertura_instalacao.rtf";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(arquivo1);
        String nome_arq =  arquivo1;
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
				fclose(arq_teste);
                bool continua = true;

                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
						}
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
								nro_ata--;
                                continua = true;
                        }
                }



				if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------

        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        //FormAbertura->DateTimePicker1->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
		AnsiString nome_dia = Form1->ConverteLiteral(dia, 1);
		AnsiString nome_mes = ComboBox2->Items->Strings[mes-1];
		AnsiString nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
		FormAbertura->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Instala��o da Comiss�o Examinadora \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;

		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();


		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto,1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormAbertura->Edit1->Text).c_str() << ", ";

//        AnsiString categoria;
//		switch (projeto.classe)
//        {
//				case 0: categoria = "Adjunto";
//						break;
//                case 1: categoria = "Assistente";
//                        break;
//                case 2: categoria = "Auxiliar";
//                        break;
//                default: categoria = "?????";
//						break;
//        }

        arq << "reuniram-se os professores ";
        for (int i=0; i<3; i++)
		{
				arq << examinador[i].nome.c_str();
                if (i == 3 - 3)
                        arq << " (presidente), ";
                if (i == 3 - 2)
                        arq << " e " ;
		}

		arq << " para a instala��o da Comiss�o Examinadora do " << projeto.tipo_concurso.c_str();
		arq << " para Professor " << projeto.categoria.c_str() << " para o campus " << projeto.campus.c_str() << " na �rea de ";
		arq << projeto.area.c_str() << ", conforme portaria " << AnsiString(FormAbertura->Edit2->Text).c_str() << " da " << AnsiString(FormAbertura->Edit3->Text).c_str();
		arq << ", anexada ao presente processo.  Nesta reuni�o foram discutidos e aprovados os crit�rios de avalia��o das provas ";
		arq << " \(baseados na " << projeto.normativa.c_str() << " da " << projeto.universidade.c_str() << "\). ";
		arq << "Al�m disso, tamb�m foram tomadas delibera��es e provid�ncias de ordem geral ";
		arq << "a fim de viabilizar o bom desenvolvimento do " <<  projeto.tipo_concurso.c_str() << ". Nada mais havendo a tratar, lavrou-se a presente ata, assinada por todos os membros efetivos da Comiss�o Examinadora.";

        arq << "\\par \\pard \\par" << endl;


        arq.close();

		Assinaturas(nome_arq, DataG);
        FechaRTF(nome_arq);

       // Atualiza o ListView
        TListItem  *ListItem;
		ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button24Click(TObject *Sender)
{
        // ---------------
        // Ata de recep��o dos candidatos e entrega de documentos da prova de t�tulos - id=23
		// Conferido - versao 3.4

        String identificador = "23";
        String titulo = "Recep��o dos candidatos e entrega de documentos para prova de t�tulos";
        String arquivo1 = "abertura_recepcao.rtf";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(arquivo1);
		String nome_arq =  ExtractFileName(arquivo1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
		}
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
                {
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
						}
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
                        }
                }

				if (continua)
                {
                        NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
								return;

        // ---------------

        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        //FormAbertura->DateTimePicker1->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia, 1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
		FormAbertura->DateTimePicker4->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Recep��o dos candidatos e entrega de documentos \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;

		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();

		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora,0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto,1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormAbertura->Edit1->Text).c_str() << ", ";

//        String categoria;
//        switch (projeto.classe)
//        {
//				case 0: categoria = "Adjunto";
//                        break;
//                case 1: categoria = "Assistente";
//                        break;
//                case 2: categoria = "Auxiliar";
//                        break;
//				default: categoria = "?????";
//						break;
//        }



		arq << "reuniu-se a Comiss�o Examinadora do " << projeto.tipo_concurso.c_str();
		arq << " para Professor " << projeto.categoria.c_str() << " para o campus " <<
		projeto.campus.c_str() << " na �rea de ";
		arq << projeto.area.c_str() << " para a sess�o de recep��o aos candidatos inscritos no referido " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "Inicialmente, foi realizada a identifica��o dos candidatos presentes conforme lista de presen�a em anexo";

		// Verifica se algum candidato est� ausente
		int ha_ausente = 0;
		vector<String> ausentes;
		for (int i=0; i<FormAbertura->CheckListBox1->Items->Count; i++)
		{
				if (!FormAbertura->CheckListBox1->Checked[i])
				{
						ha_ausente++;
						ausentes.push_back(FormAbertura->CheckListBox1->Items->Strings[i]);
				}
		}
		if (ha_ausente>0)
		{
				String plural;
				if (ha_ausente>1) plural = "s";
				else plural = "";
				arq << " na qual consta a aus�ncia do" << AnsiString(plural).c_str() << " candidato" << AnsiString(plural).c_str() << " ";
				for (unsigned int j=ausentes.size(); j>0; j--)
				{
						arq << AnsiString(ausentes[j-1]).c_str();
						if (j == 2)
								arq << " e ";
						else
								if (j>2)
										arq << ", ";
								//else
								//        arq << ".";
				}
		}

		arq << ". A seguir, foi exposto o cronograma do " <<  projeto.tipo_concurso.c_str() << " e detalhes sobre os procedimentos. ";
		arq << "Em seguida, os candidatos procederam a entrega da documenta��o comprobat�ria do seu Curriculum Vitae";
		if (projeto.habilita_prova_memorial) {
			arq << " e as tr�s c�pias do Projeto de Memorial Acad�mico.";
		}
		else
			arq << ".";

		arq << " A entrega dos documentos foi feita contra recibo assinado pelo presidente da Comiss�o Examinadora. ";
		arq << "C�pias de documentos n�o autenticadas em cart�rio foram autenticadas pela Comiss�o Examinadora na presen�a dos originais. ";
		arq << "Nada mais havendo a tratar, lavrou-se a presente ata.";

		arq << "\\par \\pard \\par" << endl;


		arq.close();

		Assinaturas(nome_arq, DataG);
		FechaRTF(nome_arq);

	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView1->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
		ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button27Click(TObject *Sender)
{
		// Baseia-se nos dados da tabela de FormResultado
		// Parecer final da banca - id=24
		// Conferido versao 3.4

		int ic = FormResultado->PageControl1->ActivePageIndex;
		String nome_arq1 = "parecer_final.rtf";

		String identificador = "24";
		String titulo = "Parecer final da comiss�o avaliadora";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------

		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);

		//int ie = FormDidatica->ListBox3->ItemIndex;


        GeraCabecalho(nome_arq);

        using namespace std;


        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        unsigned short ano, mes, dia;
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
//		String categoria;
//		switch (projeto.classe)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//		}




        unsigned short hora, minuto, segundo, milisegundo;
		FormResultado->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);



        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b PARECER DA COMISS�O EXAMINADORA \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;


		arq << "\\qj Encerradas as provas e divulgados os resultados em Sess�o P�blica ";
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 0)).c_str();
		//arq << AnsiString(Form1->ConverteLiteral(dia, 1)).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << endl;
		//arq << " de " << AnsiString(Form1->ConverteLiteral(ano, 1)).c_str() << ", " << endl;
		// Alterado em 11/02/12
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//		arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, " << endl;
		arq << ", na " << AnsiString(FormResultado->Edit1->Text).c_str();
		arq << ", a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " ";
		arq << "para Professor " << projeto.categoria.c_str() << " para o campus " << projeto.campus.c_str() << " na �rea de ";
		arq << projeto.area.c_str();

		arq << ", composta pelos professores " << examinador[0].nome.c_str() << ", ";
		arq << examinador[1].nome.c_str() << " e " << examinador[2].nome.c_str() << ", emite ";
        bool ha = false;
        for (int i=1; i<FormResultado->StringGrid1->RowCount; i++)
        {
                String g = FormResultado->StringGrid1->Cells[2][i];
                if (g!="Eliminado")
						ha = true;
        }
        if (ha)
        {
        arq << "parecer pela habilita��o dos seguintes candidatos: ";


		arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Candidato \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b M�dia Final \\b0 \\cell\n" << endl;
		// Terceira celula
        arq << "\\pard \\intbl \\qc \\b Classifica��o \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        int cc = 1;
        bool existe = true;
		while (existe)
        {
        existe = false;
        for (int i=1; i<FormResultado->StringGrid1->RowCount; i++)
        {
                String g = FormResultado->StringGrid1->Cells[2][i];
                if (g!="Eliminado")
				{
                String j =  g.SubString(1, g.Length()-1);
                if (StrToInt(j) == cc)
                {

                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormResultado->StringGrid1->Cells[0][i]).c_str() << " \\cell" << endl;
				// Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormResultado->StringGrid1->Cells[1][i]).c_str() << " \\cell\n" << endl;
				// Terceira celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormResultado->StringGrid1->Cells[2][i]).c_str() << " \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

				cc++;
                existe = true;
                }
                }
         }
         }
         }
		 else
         {
                arq << "o seguinte parecer: nenhum candidato aprovado.";
                arq << "\\par \\pard" << endl;
         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
		TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        //nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

int __fastcall TFormAtas::PegaSexo(String nome)
{
        // Localiza o sexo do candidato a partir do seu nome no vetor "candidato"
		// Retorna -1 se o nome n�o foi encontrado
        // Obs.: caso existam dois candidatos com o mesmo nome, retorna o sexo do �ltimo do vetor
        int sexo = -1;
        for (unsigned int i=0; i<candidato.size(); i++)
        {
				if (candidato[i].nome == nome)
                        sexo = candidato[i].sexo;

        }
        return sexo;
}

void __fastcall TFormAtas::Button28Click(TObject *Sender)
{


        // Cronograma do concurso id = 25

        String nome_arq1 = "cronograma.rtf";

        String identificador = "25";
		AnsiString titulo = "Cronograma do " +  AnsiString(projeto.tipo_concurso);
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
		else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
				}
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
								continua = true;
                        }
                }

                if (continua)
				{
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------
        //;; ********** Obs: esta fun��o imprime o que est� mostrado no FormEscrita!!

        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);


        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;

		arq << "\\qc \\b Cronograma do " <<  projeto.tipo_concurso.c_str() << " \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;



        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Atividade \\b0 \\cell" << endl;
		// Segunda celula
        arq << "\\pard \\intbl \\qc \\b Data \\b0 \\cell\n" << endl;
        // Terceira celula
        arq << "\\pard \\intbl \\qc \\b Hor�rio \\b0 \\cell\n" << endl;
        // Quarta celula
        arq << "\\pard \\intbl \\qc \\b Local \\b0 \\cell\n" << endl;
        // Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

        int lin = 1;
        bool existe = true;
        while (existe)
		{
                if (Trim(FormAbertura->StringGrid1->Cells[0][lin]) != "")
                {
                        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                        // Configuracao das celulas
                        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
						arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;

                        // Primeira celula
						arq << "\\pard  \\intbl \\ql " << AnsiString(FormAbertura->StringGrid1->Cells[0][lin]).c_str() << " \\cell" << endl;
						// Segunda celula
						arq << "\\pard \\intbl \\qc " << AnsiString(FormAbertura->StringGrid1->Cells[1][lin]).c_str() << " \\cell\n" << endl;
						// Terceira celula
						arq << "\\pard  \\intbl \\qc " << AnsiString(FormAbertura->StringGrid1->Cells[2][lin]).c_str() << " \\cell" << endl;
						// Quarta celula
						arq << "\\pard \\intbl \\ql " << AnsiString(FormAbertura->StringGrid1->Cells[3][lin]).c_str() << " \\cell\n" << endl;
                        // Fim da linha
                        arq << "\\pard \\intbl \\row" << endl;
                        lin++;
				   }
                   else
                        existe = false;
         }


        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);

		// Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}

//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button25Click(TObject *Sender)
{
        // ---------------
		// Lista de presenca na sess�o de abertura do concurso - id=26

        String identificador = "26";
		String titulo = "Lista de presen�a na sess�o de abertura";
        //String nome_arq =  (projeto.diretorio) + "\\" + "lista_presenca_abertura.rtf";
        String nome_arq =  "lista_presenca_abertura.rtf";
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
				fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView2->Items->Count; i++)
				{
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
				}
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
								continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_lista);
						 int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
        int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
        int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


		using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        //int nro_lista = StrToInt(Edit17->Text);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Sess�o de Abertura do " <<  projeto.tipo_concurso.c_str() << " \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

		//arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=0; i<FormAbertura->CheckListBox1->Items->Count; i++)
        {
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
                // Segunda celula
                arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(FormAbertura->CheckListBox1->Items->Strings[i]).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        //Assinaturas(nome_arq, FormAbertura->DateTimePicker1->Date);
		Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView2->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
		ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_lista++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button29Click(TObject *Sender)
{
        // ---------------
        // Ata de julgamento da prova de t�tulos - id=27
		// Conferido - versao 3.4

		String identificador = "27";
        String titulo = "Julgamento da prova de t�tulos";
        //String nome_arq =  (projeto.diretorio) + "\\" + "titulos_julgamento.rtf";
        String nome_arq =  "titulos_julgamento.rtf";
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
		else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
                        if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
				}
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
								continua = true;
                        }
                }

                if (continua)
				{
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------
        

        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        //FormTitulos->DateTimePicker1->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
		//ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia, 1);
        String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
		FormTitulos->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Julgamento da prova de t�tulos \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;
		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormTitulos->Edit1->Text).c_str();

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }

		arq << ", reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
        arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
        arq << " para realizar o Julgamento da Prova de T�tulos do referido " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "As notas da prova de cada candidato, concedidas pelos examinadores, foram acondicionadas em envelopes lacrados, ";
		arq << "para serem abertos somente na Sess�o P�blica para Divulga��o dos Resultados. Encerrados os trabalhos e nada mais havendo a tratar, lavrou-se a presente ata.";
        arq << "\\par \\pard \\par" << endl;

        arq.close();

        Assinaturas(nome_arq, DataG);
        //Assinaturas(nome_arq, FormTitulos->DateTimePicker1->Date);
		FechaRTF(nome_arq);

        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);

        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button26Click(TObject *Sender)
{
		// ---------------
		// Recibo da documenta��o da prova de t�tulos e do memorial acad�mico
		//int ic = FormAbertura->CheckListBox1->ItemIndex;
		//int ie = FormEscrita->ListBox3->ItemIndex;
		String nome_arq1 = "titulos_recibo.rtf";

		String identificador = "28";
		String titulo = "Recibo de documenta��o - ";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------



		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b RECIBO DE DOCUMENTA��O \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\qj Recebi do candidato(a) _______________________________________ documenta��o comprobat�ria da prova de t�tulos " << endl;
		arq << "composta por _____________________________________________________________________________________________" << endl;
		if (projeto.habilita_prova_memorial) {
			arq << ", al�m de __________ c�pias do Memorial de Trajet�ria Acad�mica." << endl;
		}
		else
			arq << "." << endl;

		//arq << "\\ql \\b EXAMINADOR: " << examinador[0].nome_completo.c_str() << " \\b0 " << endl;


		arq << "\\par \\pard \\par \\par" << endl;

		// Data
		// Data e Assinatura
			  unsigned short ano, mes, dia;
				DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				arq << "\\pard  \\par  \\par \\par \n";
				arq << "\\qr \\par " << AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str() << ", " <<  AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << " de " << AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str() << ".\n\n";

			  arq << "\\par  \\pard  \\par \\par \\par \\par \n";

		// Assinatura do presidente da banca

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << examinador[0].nome_completo.c_str() << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button30Click(TObject *Sender)
{
			 // ---------------
		// Ata da sess�o de divulga��o do resultado final - id=29
		// Conferido - versao 3.4
		String identificador = "29";
		String titulo = "Divulga��o do resultado final";
		//String nome_arq =  (projeto.diretorio) + "\\" + "resultado_final.rtf";
		String nome_arq =  "resultado_final.rtf";
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView1->Items->Delete(indice_item);
								nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 NroDlg->Nro->Text = IntToStr(nro_ata);
						 int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
						 else
								return;

		// ---------------


		GeraCabecalho(nome_arq);

		using namespace std;


		unsigned short dia, mes, ano;
		//FormResultado->DateTimePicker1->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
		ComboBox2->ItemIndex = mes-1;
		//ComboBox3->ItemIndex = ano % 100;
		String nome_dia = Form1->ConverteLiteral(dia, 1);
		String nome_mes = ComboBox2->Items->Strings[mes-1];
		String nome_ano = Form1->ConverteLiteral(ano, 1);
		unsigned short hora, minuto, segundo, milisegundo;
		FormResultado->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\ql \\b Ata Nro " << nro_documento << " - Sess�o p�blica de divulga��o do resultado final \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;
		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormResultado->Edit1->Text).c_str();

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }

		arq << ", reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
		arq << " para a sess�o publica de divulga��o do resultado final do " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "Iniciada a Sess�o, o presidente da Comiss�o Examinadora explicou os procedimentos que seriam adotados para a divulga��o dos resultados. ";
		arq << "A seguir, cada examinador fez a abertura dos envelopes lacrados e rubricados que continham as notas de cada candidato. ";
		arq << "As notas dos candidatos foram lidas e lan�adas em uma planilha eletr�nica demonstrativa, para o c�lculo das m�dias ponderadas por examinador e da nota final. ";
		arq << "Essa planilha podia ser vista por todos os presentes atrav�s de equipamento �udio-visual. O c�lculo das m�dias obedeceu a " << projeto.normativa.c_str() << ". ";
		arq << "Completadas todas as planilhas demonstrativas, constatou-se ";

	 /*		bool ha = false;
		for (int i=1; i<FormResultado->StringGrid1->RowCount; i++)
		{
				String g = FormResultado->StringGrid1->Cells[2][i];
				if (g!="Eliminado")
						ha = true;
		}
		if (ha)
		{
		arq << "a aprova��o dos seguintes candidatos: ";
	   */
		int ha = 0;
		for (int i=1; i<FormResultado->StringGrid1->RowCount; i++)
		{
				String g = FormResultado->StringGrid1->Cells[2][i];
				if (g!="Eliminado")
						ha++;
		}
		if (ha>0)

	   {
		if (ha>1)
				arq << "a aprova��o dos seguintes candidatos: ";
        else
                arq << "a aprova��o do seguinte candidato: ";




		int cc = 1;
        bool existe = true;
        while (existe)
        {
        existe = false;
		for (int i=1; i<FormResultado->StringGrid1->RowCount; i++)
        {
                String g = FormResultado->StringGrid1->Cells[2][i];
                if (g!="Eliminado")
                {
                String j =  g.SubString(1, g.Length()-1);
                if (StrToInt(j) == cc)
				{

                //arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				arq << AnsiString(FormResultado->StringGrid1->Cells[0][i]).c_str();
                arq << ", com nota igual a " << AnsiString(FormResultado->StringGrid1->Cells[1][i]).c_str() << " (" << AnsiString(Form1->ConverteLiteralFloat(StrToFloat(FormResultado->StringGrid1->Cells[1][i]), 1)).c_str() << ")";

                cc++;
				existe = true;


                if (ha>2)
                        arq << ", ";
                else if (ha==2)
                        arq << " e ";
                     else
                        arq << ". ";
                ha--;

                }
                }
         }
         }
         }
         else
		 {
                arq << "que nenhum candidato foi aprovado. ";

         }







		arq << "Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata.";
        arq << "\\par \\pard" << endl;
        arq.close();

        Assinaturas(nome_arq, DataG);
        //Assinaturas(nome_arq, FormResultado->DateTimePicker1->Date);

		FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button31Click(TObject *Sender)
{
     // ---------------
        // Ata da sess�o de divulga��o da nota da prova escrita - id=30
		// Conferido - versao 3.4

		String identificador = "30";
        String titulo = "Divulga��o da nota da prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + "resultado_escrita.rtf";
        String nome_arq =  "resultado_escrita.rtf";
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
		{
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
				bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView1->Items->Delete(indice_item);
                                nro_ata--;
                                continua = true;
						}
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_ata);
                         int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

		// ---------------


        GeraCabecalho(nome_arq);

        using namespace std;


        unsigned short dia, mes, ano;
        DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
        //ComboBox1->ItemIndex = dia-1;
        ComboBox2->ItemIndex = mes-1;
        //ComboBox3->ItemIndex = ano % 100;
        String nome_dia = Form1->ConverteLiteral(dia, 1);
		String nome_mes = ComboBox2->Items->Strings[mes-1];
        String nome_ano = Form1->ConverteLiteral(ano, 1);
        unsigned short hora, minuto, segundo, milisegundo;
        FormEscrita->DateTimePicker9->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\ql \\b Ata Nro " << nro_documento << " - Sess�o p�blica de divulga��o da nota da prova escrita \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;
		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();

		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormEscrita->Edit5->Text).c_str();

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }

		arq << ", reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
		arq << " para a sess�o p�blica de divulga��o da nota da prova escrita do " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "Iniciada a Sess�o, o presidente da Comiss�o Examinadora explicou os procedimentos que seriam adotados para a divulga��o das notas. ";
		arq << "A seguir, cada examinador fez a abertura dos envelopes lacrados e rubricados que continham as notas de cada candidato. ";
		arq << "As notas dos candidatos foram lidas e lan�adas em uma planilha eletr�nica demonstrativa. ";
		arq << "Essa planilha podia ser vista por todos os presentes atrav�s de equipamento �udio-visual. O c�lculo das m�dias obedeceu a " << projeto.normativa.c_str() << ". ";
		arq << "Completadas todas as planilhas demonstrativas, constatou-se ";

		int ha = 0;
		for (unsigned int i=0; i<candidato.size(); i++)
		{
				String g = tabela[i]->Cells[2][4];
			//if (StrToFloat(g) >= 7)
			if (StrToFloat(g) >= projeto.nota_minima_escrita)
						ha++;
		}
		if (ha>0)

	   {
		AnsiString mediaextenso = Form1->ConverteLiteralFloat(projeto.nota_minima_escrita, 1);
		if (ha>1)
				arq << "a classifica��o dos seguintes candidatos, com m�dia maior ou igual a " << mediaextenso.c_str() << ": ";
		else
				arq << "a classifica��o do seguinte candidato, com m�dia maior ou igual a " << mediaextenso.c_str() << ": ";


		for (unsigned int i=0; i<candidato.size(); i++)
		{
				String g = tabela[i]->Cells[2][4];
				//if (StrToFloat(g) >= 7)
				if (StrToFloat(g) >= projeto.nota_minima_escrita)
		{

				//arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				arq << candidato[i].nome.c_str();
		arq << ", com nota igual a " << AnsiString(g).c_str() << " (" << AnsiString(Form1->ConverteLiteralFloat(StrToFloat(g), 1)).c_str() << ")";
				if (ha>2)
						arq << ", ";
				else if (ha==2)
						arq << " e ";
					 else
						arq << ".";
				ha--;
				}


		 }
		 }

		 else
		 {
				arq << "que nenhum candidato foi aprovado.";

		 }

		arq << " Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata.";
		arq << "\\par \\pard" << endl;
		arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
		TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button32Click(TObject *Sender)
{
	 // ---------------
		// Ata da sess�o de divulga��o da nota da prova did�tica - id=31
		// Conferido - versao 3.4

		String identificador = "31";
		String titulo = "Divulga��o da nota da prova did�tica";
		//String nome_arq =  (projeto.diretorio) + "\\" + "resultado_didatica.rtf";
		String nome_arq =  "resultado_didatica.rtf";
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView1->Items->Delete(indice_item);
								nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 NroDlg->Nro->Text = IntToStr(nro_ata);
						 int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
						 else
								return;

		// ---------------


		GeraCabecalho(nome_arq);

		using namespace std;


		unsigned short dia, mes, ano;
		DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
		ComboBox2->ItemIndex = mes-1;
		//ComboBox3->ItemIndex = ano % 100;
		String nome_dia = Form1->ConverteLiteral(dia, 1);
		String nome_mes = ComboBox2->Items->Strings[mes-1];
		String nome_ano = Form1->ConverteLiteral(ano, 1);
		unsigned short hora, minuto, segundo, milisegundo;
		FormDidatica->DateTimePicker2->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\ql \\b Ata Nro " << nro_documento << " - Sess�o p�blica de divulga��o da nota da prova did�tica \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;
		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";
		//arq << " �s " << AnsiString(Form1->ConverteLiteral(hora, 0)).c_str() << " horas e " << AnsiString(Form1->ConverteLiteral(minuto, 1)).c_str() << " minutos, ";
		arq <<", na " << AnsiString(FormDidatica->Edit3->Text).c_str();

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }

		arq << ", reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
		arq << " para a sess�o publica de divulga��o da nota da prova did�tica do " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "Iniciada a Sess�o, o presidente da Comiss�o Examinadora explicou os procedimentos que seriam adotados para a divulga��o das notas. ";
		arq << "A seguir, cada examinador fez a abertura dos envelopes lacrados e rubricados que continham as notas de cada candidato. ";
		arq << "As notas dos candidatos foram lidas e lan�adas em uma planilha eletr�nica demonstrativa. ";
		arq << "Essa planilha podia ser vista por todos os presentes atrav�s de equipamento �udio-visual. O c�lculo das m�dias obedeceu a " << projeto.normativa.c_str() << ". ";
		arq << "Completadas todas as planilhas demonstrativas, constatou-se ";

		/*
		bool ha = false;
		for (unsigned int i=0; i<candidato.size(); i++)
		{
				String g = tabela[i]->Cells[3][4];
				if (StrToFloat(g) >= 7)
						ha = true;
		}
		if (ha)
		{
		arq << "a aprova��o dos seguintes candidatos, com m�dia maior ou igual a sete: ";




		for (unsigned int i=0; i<candidato.size(); i++)
		{
				String g = tabela[i]->Cells[3][4];
				if (StrToFloat(g) >= 7)
				{

				//arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				arq << candidato[i].nome.c_str();
				arq << ", com nota igual a " << AnsiString(g).c_str() << " (" << AnsiString(Form1->ConverteLiteralFloat(StrToFloat(g), 1)).c_str() << "), ";


				}

		 }
		 }

		 else
		 {
				arq << "que nenhum candidato foi aprovado. ";

		 }

		 */


		 int ha = 0;
		for (unsigned int i=0; i<candidato.size(); i++)
		{
				String g = tabela[i]->Cells[3][4];
			//if (StrToFloat(g) >= 7)
			if (StrToFloat(g) >= projeto.nota_minima_didatica)
						ha++;
		}
		if (ha>0)

	   {

		AnsiString mediaextenso = Form1->ConverteLiteralFloat(projeto.nota_minima_didatica, 1);
		if (ha>1)
				arq << "a classifica��o dos seguintes candidatos, com m�dia maior ou igual a " << mediaextenso.c_str() << ": ";
		else
				arq << "a classifica��o do seguinte candidato, com m�dia maior ou igual a " << mediaextenso.c_str() << ": ";

		/*
		if (ha>1)
				arq << "a aprova��o dos seguintes candidatos, com m�dia maior ou igual a sete: ";
		else
				arq << "a aprova��o do seguinte candidato, com m�dia maior ou igual a sete: ";

		*/

        for (unsigned int i=0; i<candidato.size(); i++)
        {
                String g = tabela[i]->Cells[3][4];
				//if (StrToFloat(g) >= 7)
				if (StrToFloat(g) >= projeto.nota_minima_didatica)
		{

                //arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                arq << candidato[i].nome.c_str();
		arq << ", com nota igual a " << AnsiString(g).c_str() << " (" << AnsiString(Form1->ConverteLiteralFloat(StrToFloat(g), 1)).c_str() << ")";
                if (ha>2)
                        arq << ", ";
                else if (ha==2)
                        arq << " e ";
                     else
                        arq << ". ";
                ha--;
                }


         }
         }

		 else
         {
                arq << "que nenhum candidato foi aprovado. ";

         }




        arq << "Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata.";
		arq << "\\par \\pard" << endl;
        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView1->Items->Add();
        ListItem->Caption = IntToStr(nro_documento);
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------


}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button33Click(TObject *Sender)
{
        // ---------------
        // Planilha demonstrativa do resultado da prova escrita - 32
        int ic = FormResultado->PageControl1->ActivePageIndex-1;
        String nome_arq1 = "resultado_planilha_escrita.rtf";

        String identificador = "32";
        String titulo = "Planilha de notas - prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
        String nome_arq =  ExtractFileName(nome_arq1);
        FILE* arq_teste;
        arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
                        if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------

		int tc1 = StrToInt(Edit5->Text);
        int tc2 = 3000; //StrToInt(Edit6->Text);
        int tc3 = 4500; //StrToInt(Edit7->Text);
        int tc4 = 6000; // StrToInt(Edit8->Text);
        int tc5 = 7500; // StrToInt(Edit9->Text);
        int tc6 = 9000; //StrToInt(Edit10->Text);

        //int ie = FormDidatica->ListBox3->ItemIndex;


        GeraCabecalho(nome_arq);

        using namespace std;


        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b PLANILHA DEMONSTRATIVA DE NOTAS DA PROVA ESCRITA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Candidato \\b0 \\cell" << endl;
        // Segunda celula
		arq << "\\pard \\intbl \\qc \\b "<< examinador[0].nome.c_str() << " \\b0 \\cell\n" << endl;
		// Terceira celula
		arq << "\\pard \\intbl \\qc \\b "<< examinador[1].nome.c_str() << " \\b0 \\cell\n" << endl;
		// Quarta celula
		arq << "\\pard \\intbl \\qc \\b "<< examinador[2].nome.c_str() << " \\b0 \\cell\n" << endl;
		// Quinta celula
        arq << "\\pard \\intbl \\qc \\b M�dia \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (unsigned int i=0; i<candidato.size(); i++)
        {
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
				arq << "\\pard  \\intbl \\ql " << candidato[i].nome.c_str() << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[2][1]).c_str() << " \\cell\n" << endl;
				// Terceira celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[2][2]).c_str() << " \\cell\n" << endl;
				// Quarta celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[2][3]).c_str() << " \\cell\n" << endl;
				// Quinta celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[2][4]).c_str() << " \\cell\n" << endl;

                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }
         // Nota final
         arq << "\\pard  \\par \\par \\par" << endl;

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button34Click(TObject *Sender)
{
 // ---------------
        // Planilha demonstrativa do resultado da prova did�tica - 33
        int ic = FormResultado->PageControl1->ActivePageIndex-1;
        String nome_arq1 = "resultado_planilha_didatica.rtf";

		String identificador = "33";
		String titulo = "Planilha de notas - prova didatica";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq = ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
                        }
                }
                if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView3->Items->Delete(indice_item);
                                //nro_ata--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         //NroDlg->Nro->Text = IntToStr(nro_ata);
                         //NroDlg->ShowModal();
                         int nro_documento = 0;

        // ---------------

        	int tc1 = StrToInt(Edit5->Text);
        int tc2 = 3000; //StrToInt(Edit6->Text);
        int tc3 = 4500; //StrToInt(Edit7->Text);
        int tc4 = 6000; // StrToInt(Edit8->Text);
        int tc5 = 7500; // StrToInt(Edit9->Text);
        int tc6 = 9000; //StrToInt(Edit10->Text);

        //int ie = FormDidatica->ListBox3->ItemIndex;


        GeraCabecalho(nome_arq);

        using namespace std;


        using namespace std;
        fstream arq;
        arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b PLANILHA DEMONSTRATIVA DE NOTAS DA PROVA DID�TICA \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Candidato \\b0 \\cell" << endl;
        // Segunda celula
		arq << "\\pard \\intbl \\qc \\b "<< examinador[0].nome.c_str() << " \\b0 \\cell\n" << endl;
		// Terceira celula
		arq << "\\pard \\intbl \\qc \\b "<< examinador[1].nome.c_str() << " \\b0 \\cell\n" << endl;
		// Quarta celula
        arq << "\\pard \\intbl \\qc \\b "<< examinador[2].nome.c_str() << " \\b0 \\cell\n" << endl;
        // Quinta celula
        arq << "\\pard \\intbl \\qc \\b M�dia \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (unsigned int i=0; i<candidato.size(); i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc3 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
				arq << "\\pard  \\intbl \\ql " << candidato[i].nome.c_str() << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[3][1]).c_str() << " \\cell\n" << endl;
				// Terceira celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[3][2]).c_str() << " \\cell\n" << endl;
				// Quarta celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[3][3]).c_str() << " \\cell\n" << endl;
				// Quinta celula
				arq << "\\pard \\intbl \\qc " << AnsiString(tabela[i]->Cells[3][4]).c_str() << " \\cell\n" << endl;

                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }
         // Nota final
         arq << "\\pard  \\par \\par \\par" << endl;

        arq.close();

        Assinaturas(nome_arq, DataG);

		FechaRTF(nome_arq);
        // Atualiza o ListView
        TListItem  *ListItem;
        ListItem = Form1->ListView3->Items->Add();
        ListItem->Caption = "";
        ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
        //nro_ata++;
        if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
            ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
        }
        } // fecha o if(continua)
        } // fecha o else da verificacao de abertura do arquivo

        // ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button35Click(TObject *Sender)
{
        // ---------------
        // Lista de presenca na leitura da prova escrita - id=41

		String identificador = "41";
        String titulo = "Lista de presen�a na leitura da prova escrita";
        //String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit18->Text);
		String nome_arq =   ExtractFileName(Edit18->Text);
        FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);
                bool continua = true;
                // Verifica se este arquivo ja foi gerado anteriormente
                int indice_item;
                for (int i=0; i<Form1->ListView2->Items->Count; i++)
                {
                        if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
                        if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
                        {
                                indice_item = i;
                                continua = false;
                        }
                }
				if (continua == false)
                {
                        if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
                        {
                                Form1->ListView2->Items->Delete(indice_item);
                                nro_lista--;
                                continua = true;
                        }
                }

                if (continua)
                {
                         NroDlg->Nro->Text = IntToStr(nro_lista);
                         int nro_documento;
                         if (NroDlg->ShowModal() == mrOk)
                                 nro_documento = StrToInt(NroDlg->Nro->Text);
                         else
                                return;

        // ---------------


        int tc1 = StrToInt(Edit5->Text);
        int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
        int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
        int tc6 = StrToInt(Edit10->Text);

        GeraCabecalho(nome_arq);


        using namespace std;
        fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

        //int nro_lista = StrToInt(Edit17->Text);

        // T�tulo
        arq << "\\pard \\par \\par \\par" << endl;
        arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Sess�o de Leitura da Prova Escrita \\b0 " << endl;

        arq << "\\par \\pard \\par \\par" << endl;

        //arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
        //arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
        //arq << "\\par \\pard \\par \\par" << endl;

        // Cabecalho
        arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
        // Configuracao das celulas
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
        arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
        // Primeira celula
        arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
        // Segunda celula
        arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
        // Terceira celula (vazia)
        arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
        // Fim da linha
        arq << "\\pard \\intbl \\row" << endl;

        for (int i=0; i<FormEscrita->CheckListBox2->Items->Count; i++)
        {
                arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
                // Configuracao das celulas
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
                arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
                // Primeira celula
                arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
                // Segunda celula
				arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(FormEscrita->CheckListBox2->Items->Strings[i]).c_str() << " \\par \\cell\n" << endl;
                // Terceira celula (vazia)
                arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
                // Fim da linha
                arq << "\\pard \\intbl \\row" << endl;

         }

        arq.close();

        Assinaturas(nome_arq, DataG);

        FechaRTF(nome_arq);
        // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView2->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
		ListItem->SubItems->Add(titulo);
        ListItem->SubItems->Add(nome_arq);
        ListItem->SubItems->Add(identificador);
		nro_lista++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
        {
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
        } // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button9Click(TObject *Sender)
{
		// ---------------
		// Declaracao de nao impedimento de membro da banca examinadora - 1.6

		String nome_arq1 = "declaracao_nao_impedimento.rtf";

		String identificador = "43";
		String titulo = "Declara��o de n�o impedimento da banca examinadora";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------



		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b DECLARA��O DE N�O IMPEDIMENTO \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\qj Eu, ___________________________________________________________________, portador da c�dula de identidade n� ________________________, " << endl;
		arq << "expedida pelo _________________________________________, convidado para participar da Comiss�o Examinadora " << endl;
		arq << "do " << projeto.tipo_concurso.c_str() << " na �rea de " << projeto.area.c_str() << ", Edital " << projeto.edital.c_str() << endl;
		arq << " da " << projeto.universidade.c_str() << ", declaro para os devidos fins n�o existir situa��o impeditiva por ser c�njuge de candidato, " << endl;
		arq << "embora separado judicialmente, divorciado ou companheiro; por ter grau de parentesco ascendente ou descendente com os candidatos " << endl;
		arq << "at� segundo grau; por ser s�cio de candidato em atividade profissional; ou por ser ou ter sido orientador ou co-orientador acad�mico " << endl;
		arq << "de candidato (incluindo inicia��o cient�fica, mestrado, doutorado e p�s-doutorado)." << endl;

		//arq << "\\ql \\b EXAMINADOR: " << examinador[0].nome_completo.c_str() << " \\b0 " << endl;


		arq << "\\par \\pard \\par \\par" << endl;

		// Data
		// Data e Assinatura
			  unsigned short ano, mes, dia;
				DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				arq << "\\pard  \\par  \\par \\par \n";
				arq << "\\qr \\par " << AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str() << ", " <<  AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << " de " << AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str() << ".\n\n";

			  arq << "\\par  \\pard  \\par \\par \\par \\par \n";

		// Assinatura do examinador

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << "Assinatura do Membro da Comiss�o" << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nImprima uma c�pia para cada examinador.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button36Click(TObject *Sender)
{
		// ---------------
		// Declaracao de desist�ncia de prazo recursal da prova escrita  - 2.4

		String nome_arq1 = "desistencia_recurso_escrita.rtf";

		String identificador = "44";
		String titulo = "Termo de desist�ncia de prazo recursal da prova escrita";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------



		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);


//                AnsiString categoria;
//                switch (projeto.classe)
//		{
//                case 0: categoria = "Adjunto";
//                        break;
//                case 1: categoria = "Assistente";
//                        break;
//                case 2: categoria = "Auxiliar";
//                        break;
//                default: categoria = "?????";
//                        break;
//				}

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b TERMO DE DESIST�NCIA DO PRAZO RECURSAL DA NOTA FINAL DA PROVA ESCRITA  \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\qj Eu, ___________________________________________________________________, portador da c�dula de identidade n� ________________________, " << endl;
		arq << "expedida pelo _________________________________________, no presente ato e na melhor forma de direito, declaro DESISTIR de qualquer recurso cab�vel, " << endl;
                arq << "conforme Artigo " << artigo_prazo_recursal_escrita.c_str() << " da " << projeto.normativa.c_str() <<  endl;
		arq << ", relativo � Nota Final da Prova Escrita do " << projeto.tipo_concurso.c_str() << " para provimento de cargo de professor " << endl;
				arq << projeto.categoria.c_str() << " na �rea de " << projeto.area.c_str() << ", Edital " << projeto.edital.c_str() << endl;
		arq << " promovido pela " << projeto.universidade.c_str() << "." << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		// Data
		// Data e Assinatura
			  unsigned short ano, mes, dia;
				DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				arq << "\\pard  \\par  \\par \\par \n";
				arq << "\\qr \\par " << AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str() << ", " <<  AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << " de " << AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str() << ".\n\n";

			  arq << "\\par  \\pard  \\par \\par \\par \\par \n";

		// Assinatura do candiato

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << "Assinatura do Candidato" << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nImprima uma c�pia para cada examinador.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button37Click(TObject *Sender)
{
		// ---------------
		// Declaracao de desist�ncia de prazo recursal da prova did�tica  - 4.15

		String nome_arq1 = "desistencia_recurso_didatica.rtf";

		String identificador = "45";
		String titulo = "Termo de desist�ncia de prazo recursal da prova did�tica";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------



		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);


//				AnsiString categoria;
//				switch (projeto.classe)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//				}

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b TERMO DE DESIST�NCIA DO PRAZO RECURSAL DA NOTA FINAL DA PROVA DID�TICA  \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\qj Eu, ___________________________________________________________________, portador da c�dula de identidade n� ________________________, " << endl;
		arq << "expedida pelo _________________________________________, no presente ato e na melhor forma de direito, declaro DESISTIR de qualquer recurso cab�vel, " << endl;
				arq << "conforme Artigo " << artigo_prazo_recursal_didatica.c_str() << " da " << projeto.normativa.c_str() <<  endl;
		arq << ", relativo � Nota Final da Prova Did�tica do " << projeto.tipo_concurso.c_str() << " para provimento de cargo de professor " << endl;
				arq << projeto.categoria.c_str() << " na �rea de " << projeto.area.c_str() << ", Edital " << projeto.edital.c_str() << endl;
		arq << " promovido pela " << projeto.universidade.c_str() << "." << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		// Data
		// Data e Assinatura
			  unsigned short ano, mes, dia;
				DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				arq << "\\pard  \\par  \\par \\par \n";
				arq << "\\qr \\par " << AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str() << ", " <<  AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << " de " << AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str() << ".\n\n";

			  arq << "\\par  \\pard  \\par \\par \\par \\par \n";

		// Assinatura do candiato

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << "Assinatura do Candidato" << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nImprima uma c�pia para cada examinador.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}

//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button38Click(TObject *Sender)
{
						// ---------------
		// Ata de realizacao da entrevista - id=117
		// Conferido versao 3.4

		String identificador = "117";
		String titulo = "Realiza��o da prova de entrevista";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit27->Text);
		String nome_arq =  ExtractFileName(Edit14->Text);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView1->Items->Count; i++)
				{
						if (Form1->ListView1->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView1->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView1->Items->Delete(indice_item);
								nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 NroDlg->Nro->Text = IntToStr(nro_ata);
						 int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
						 else
								return;

		// ---------------


		GeraCabecalho(nome_arq);

		using namespace std;


		unsigned short dia, mes, ano;
		// Obs.: nao esta implementado o caso em que os sorteios acontecem em mais de um dia
		// A data dos sorteios consideradas sao  a data do primeiro sorteio
		dat_ent[0]->Date.DecodeDate(&ano, &mes, &dia);  // Recupera a data
		//ComboBox1->ItemIndex = dia-1;
		ComboBox2->ItemIndex = mes-1;
		//ComboBox3->ItemIndex = ano % 100;
		String nome_dia = Form1->ConverteLiteral(dia, 1);
		String nome_mes = ComboBox2->Items->Strings[mes-1];
		String nome_ano = Form1->ConverteLiteral(ano, 1);
		unsigned short hora, minuto, segundo, milisegundo;
		//hor_sor[0]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);

		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\ql \\b Ata Nro " << nro_documento << " - Realiza��o da Prova de Entrevista \\b0" << endl;

		arq << "\\par \\pard \\par \\par \\qj" << endl;

		// Alterado em 11/02/12
		arq << AnsiString(Form1->DataExtenso((int)dia, (int)mes, (int)ano, 1)).c_str();
		//arq << ", " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();


		//arq << "\\qj Aos " << AnsiString(nome_dia).c_str() << " dias do m�s de " << AnsiString(nome_mes).c_str() << " de " << AnsiString(nome_ano).c_str() << ",";

		//arq << " �s " << hora << " horas e " << minuto << " minutos, ";
		arq <<", na " << AnsiString(FormEntrevista->Edit1->Text).c_str() << ",";

//		String categoria;
//		switch (FormConfiguracao->RadioGroup4->ItemIndex)
//		{
//				case 0: categoria = "Adjunto";
//						break;
//				case 1: categoria = "Assistente";
//						break;
//				case 2: categoria = "Auxiliar";
//						break;
//				default: categoria = "?????";
//						break;
//        }
		arq << " reuniu-se a Comiss�o Examinadora do " <<  projeto.tipo_concurso.c_str() << " para Professor " << projeto.categoria.c_str();
		arq << " para o campus " << projeto.campus.c_str() << " na �rea de " << projeto.area.c_str();
		arq << " para a realiza��o da Prova de Entrevista do referido " <<  projeto.tipo_concurso.c_str() << ". ";

		for (unsigned int i=0; i<lab_ent.size(); i++)
		{
				hor_ent[i]->Time.DecodeTime(&hora, &minuto, &segundo, &milisegundo);
				//int p = ponto[i]->ItemIndex;
				//String nome_p = ponto[i]->Items->Strings[p];
				String artigo;
						if(PegaSexo(lab_ent[i]->Caption) == 0) artigo = "o";    // modificado
						else artigo = "a";
				if (comp_ent[i]->Checked)
				{

						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab_ent[i]->Caption).c_str() << " compareceu " << AnsiString(Form1->HoraExtenso((int)hora, (int)minuto, 0)).c_str();
						arq << " para a realiza��o da sua entrevista. " ;
				}
				else
				{
						arq << AnsiString(AnsiUpperCase(artigo)).c_str() << " candidat" << AnsiString(artigo).c_str() << " " << AnsiString(lab_ent[i]->Caption).c_str() << " n�o compareceu. ";
				}
		}

		arq << "Ap�s a entrevista de cada candidato, os examinadores ";
		arq << "realizaram a avalia��o segundo crit�rios previamente estabelecidos e anexados ao presente processo. ";
		arq << "As planilhas com as notas dos candidatos foram acondicionadas em envelopes individuais, ";
		arq << "por examinador. Os envelopes foram guardados para serem abertos somente na Sess�o P�blica para Divulga��o dos Resultados do " <<  projeto.tipo_concurso.c_str() << ". ";
		arq << "As entrevistas de cada candidato foram gravadas e as grava��es foram anexadas ao processo do " <<  projeto.tipo_concurso.c_str() << ". " << endl;
		arq << "Ap�s o encerramento dos trabalhos, que transcorreram sem anormalidades, lavrou-se a presente ata. " << endl;
		arq << "\\par \\pard \\par" << endl;


		arq.close();

		Assinaturas(nome_arq, dat_ent[0]->Date);
		FechaRTF(nome_arq);
		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView1->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button39Click(TObject *Sender)
{
				// ---------------
		// Lista de presenca realizacao da entrevista - id=118

		String identificador = "118";
		String titulo = "Lista de presen�a na realiza��o da entrevista";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(Edit28->Text);
		String nome_arq =  ExtractFileName(Edit15->Text);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView2->Items->Count; i++)
				{
						if (Form1->ListView2->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView2->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView2->Items->Delete(indice_item);
								nro_lista--;
								continua = true;
						}
				}

				if (continua)
				{
						 NroDlg->Nro->Text = IntToStr(nro_lista);
						 int nro_documento;
						 if (NroDlg->ShowModal() == mrOk)
								 nro_documento = StrToInt(NroDlg->Nro->Text);
						 else
								return;

		// ---------------


		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);


		GeraCabecalho(nome_arq);


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);


		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b LISTA DE PRESEN�A Nro. " << nro_documento << " - Presen�a dos Candidatos na Realiza��o da Prova de Entrevista \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		//arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
		//arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc1 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		// Primeira celula
		arq << "\\pard  \\intbl \\qc \\b Nro \\b0 \\cell" << endl;
		// Segunda celula
		arq << "\\pard \\intbl \\qc \\b Candidato \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
		arq << "\\pard \\intbl \\qc \\b Assinatura \\b0 \\cell\n" << endl;
		// Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

		for (unsigned int i=0; i<lab_ent.size(); i++)
		{
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				// Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\clvertalc \\cellx" << tc1 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc2 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql \\fs20 " << i+1 << " \\cell" << endl;
				// Segunda celula
				arq << "\\pard \\intbl \\ql \\fs28 \\par " << AnsiString(lab_ent[i]->Caption).c_str() << " \\par \\cell\n" << endl;
				// Terceira celula (vazia)
				arq << "\\pard \\intbl \\qc \\fs20 \\cell\n" << endl;
				// Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

		 }

		arq.close();

		Assinaturas(nome_arq, DataG);

		FechaRTF(nome_arq);
		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView2->Items->Add();
		ListItem->Caption = IntToStr(nro_documento);
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		nro_lista++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button40Click(TObject *Sender)
{
              // ---------------
		// Planilha demonstrativa de prova entrevista - por candidato e por examinador - id=120_ic_ie
		int ic = FormEntrevista->ListBox2->ItemIndex;
		int ie = FormEntrevista->ListBox3->ItemIndex;
		String nome_arq1 = "entrevista_planilha_c" + IntToStr(ic) + "_e" + IntToStr(ie) + ".rtf";

		String identificador = "120_" + IntToStr(ic) + "_" + IntToStr(ie);
		String titulo = "Planilha de notas - prova entrevista - " + FormEntrevista->ListBox2->Items->Strings[ic] + " - " + examinador[ie].nome;
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------

		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b AVALIA��O INDIVIDUAL DA PROVA DE ENTREVISTA \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\ql \\b CANDIDATO: " << AnsiString(FormEntrevista->ListBox2->Items->Strings[ic]).c_str() << " \\b0 \\par \\par" << endl;
		arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome_completo.c_str() << " \\b0 " << endl;
		arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		// Primeira celula
		arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
		// Segunda celula
		arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
		arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
		// Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

		for (int i=1; i<=FormEntrevista->ValueListEditor1->Strings->Count; i++)
		{
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				// Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormEntrevista->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
				// Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormEntrevista->ValueListEditor1->Values[FormEntrevista->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
				// Terceira celula (vazia)
				arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
				// Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

		 }
		 // Subtotal
		 arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		  // Configuracao das celulas
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		  // Primeira celula
		  arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
		  // Segunda celula   (vazia)
		  arq << "\\pard \\intbl \\qc  \\cell" << endl;
		  // Fim da linha
		  arq << "\\pard \\intbl \\row" << endl;





		// Assinatura do examinador

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc " << examinador[ie].nome_completo.c_str() << " \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button41Click(TObject *Sender)
{
		// Planilha demonstrativa de entrevista - criterios de avaliacao id = 119

		String nome_arq1 = Edit16->Text;

		String identificador = "119";
		String titulo = "Crit�rios de avalia��o - prova de entrevista";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------


		int tc1 = StrToInt(Edit5->Text);
		int tc2 = StrToInt(Edit6->Text);
		int tc3 = StrToInt(Edit7->Text);
		int tc4 = StrToInt(Edit8->Text);
		int tc5 = StrToInt(Edit9->Text);
		int tc6 = StrToInt(Edit10->Text);


		GeraCabecalho(nome_arq);


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b CRIT�RIOS DE AVALIA��O DA PROVA DE ENTREVISTA \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		//arq << "\\ql \\b CANDIDATO: " << candidato[ic].nome.c_str() << " \\b0 \\par \\par" << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[ie].nome.c_str() << " \\b0 " << endl;
		//arq << "\\par \\pard \\par \\par" << endl;

		// Cabecalho
		arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		// Configuracao das celulas
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		//arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
		// Primeira celula
		arq << "\\pard  \\intbl \\qc \\b Crit�rio \\b0 \\cell" << endl;
		// Segunda celula
		arq << "\\pard \\intbl \\qc \\b Peso \\b0 \\cell\n" << endl;
		// Terceira celula (vazia)
		//arq << "\\pard \\intbl \\qc \\b Nota \\b0 \\cell\n" << endl;
		// Fim da linha
		arq << "\\pard \\intbl \\row" << endl;

		for (int i=1; i<=FormEntrevista->ValueListEditor1->Strings->Count; i++)
		{
				arq <<  "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
				// Configuracao das celulas
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
				arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
				//arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc6 << endl;
				// Primeira celula
				arq << "\\pard  \\intbl \\ql " << AnsiString(FormEntrevista->ValueListEditor1->Keys[i]).c_str() << " \\cell" << endl;
				// Segunda celula
				arq << "\\pard \\intbl \\qc " << AnsiString(FormEntrevista->ValueListEditor1->Values[FormEntrevista->ValueListEditor1->Keys[i]]).c_str() << " \\cell\n" << endl;
				// Terceira celula (vazia)
				//arq << "\\pard \\intbl \\qc   \\cell\n" << endl;
				// Fim da linha
				arq << "\\pard \\intbl \\row" << endl;

		 }
		 // Subtotal
		 arq << "\\pard \\trowd \\trgaph0 \\trbrdrt \\brdrth \\trql" << endl;
		  // Configuracao das celulas
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc4 << endl;
		  arq << "\\clbrdrb \\brdrth \\clbrdrt \\brdrth \\clbrdrl \\brdrth \\clbrdrr \\brdrth \\cellx" << tc5 << endl;
		  // Primeira celula
		  arq <<"\\pard  \\intbl \\qr Total   \\cell" << endl;
		  // Segunda celula   (vazia)
		  arq << "\\pard \\intbl \\qc 10 \\cell" << endl;
		  // Fim da linha
		  arq << "\\pard \\intbl \\row" << endl;



		arq.close();

		Assinaturas(nome_arq, DataG);

		FechaRTF(nome_arq);
		// Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;

		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------
}
//---------------------------------------------------------------------------

void __fastcall TFormAtas::Button42Click(TObject *Sender)
{
			// ---------------
		// Recibo de devolu��o de documentos para os candidatos
		//int ic = FormAbertura->CheckListBox1->ItemIndex;
		//int ie = FormEscrita->ListBox3->ItemIndex;
		String nome_arq1 = "recibo_devolucao.rtf";

		String identificador = "128";
		String titulo = "Recibo de devolu��o de documenta��o - ";
		//String nome_arq =  (projeto.diretorio) + "\\" + ExtractFileName(nome_arq1);
		String nome_arq =  ExtractFileName(nome_arq1);
		FILE* arq_teste;
		arq_teste = fopen(AnsiString(nome_arq).c_str(), "at");
		if (!arq_teste)
		{
				Application->MessageBox(L"N�o foi poss�vel gerar o arquivo. Verifique se ele j� est� aberto.\nCaso esteja, feche-o e tente novamente", L"Erro", 0);
				fclose(arq_teste);
		}
		else
		{
				fclose(arq_teste);
				bool continua = true;
				// Verifica se este arquivo ja foi gerado anteriormente
				int indice_item;
				for (int i=0; i<Form1->ListView3->Items->Count; i++)
				{
						if (Form1->ListView3->Items->Item[i]->SubItems->Count > 2)
						if (identificador == Form1->ListView3->Items->Item[i]->SubItems->Strings[2])
						{
								indice_item = i;
								continua = false;
						}
				}
				if (continua == false)
				{
						if (Application->MessageBox(L"Este arquivo j� foi gerado. Deseja gerar outro?\nCaso positivo, o anterior ser� apagado.", L"Aten��o", MB_OKCANCEL)==ID_OK)
						{
								Form1->ListView3->Items->Delete(indice_item);
								//nro_ata--;
								continua = true;
						}
				}

				if (continua)
				{
						 //NroDlg->Nro->Text = IntToStr(nro_ata);
						 //NroDlg->ShowModal();
						 int nro_documento = 0;

		// ---------------



		//String nome_arq = Edit14->Text;

		GeraCabecalho(nome_arq);

		using namespace std;


		using namespace std;
		fstream arq;
		arq.open (AnsiString(nome_arq).c_str(), fstream::out | fstream::app);

		// T�tulo
		arq << "\\pard \\par \\par \\par" << endl;
		arq << "\\qc \\b RECIBO DE DEVOLU��O DE DOCUMENTA��O \\b0 " << endl;

		arq << "\\par \\pard \\par \\par" << endl;

		arq << "\\qj Recebi da banca examinadora a devolu��o da documenta��o comprobat�ria da minha prova de t�tulos ";
		arq << "composta por _______________________________________________________" << endl;
		arq << "___________________________________________________________________________." << endl;
		//arq << "\\ql \\b EXAMINADOR: " << examinador[0].nome_completo.c_str() << " \\b0 " << endl;


		arq << "\\par \\pard \\par \\par" << endl;

		// Data
		// Data e Assinatura
			  unsigned short ano, mes, dia;
				DataG.DecodeDate(&ano, &mes, &dia);  // Recupera a data
				ComboBox1->ItemIndex = dia-1;
				ComboBox2->ItemIndex = mes-1;
				ComboBox3->ItemIndex = ano % 100;
				arq << "\\pard  \\par  \\par \\par \n";
				arq << "\\qr \\par " << AnsiString(FormConfiguracao->LabeledEdit7->Text).c_str() << ", " <<  AnsiString(ComboBox1->Items->Strings[ComboBox1->ItemIndex]).c_str() << " de " << AnsiString(ComboBox2->Items->Strings[ComboBox2->ItemIndex]).c_str() << " de " << AnsiString(ComboBox3->Items->Strings[ComboBox3->ItemIndex]).c_str() << ".\n\n";

			  arq << "\\par  \\pard  \\par \\par \\par \\par \n";

		// Assinatura do presidente da banca

		arq << "\\pard  \\par \\par \\par \\par" << endl;
		arq << "\\par \\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc ______________________________ \\cell \\pard \\intbl \\row" << endl;
		arq << "\\trowd \\trgaph0 \\trqc \\cellx3636" << endl;
		arq << "\\qc Candidato: \\cell \\pard \\intbl \\row" << endl;
		arq << "\\pard" << endl;

		//Assinaturas(nome_arq, FormEscrita->DateTimePicker5->Date);
		arq.close();

		FechaRTF(nome_arq);
	   // Atualiza o ListView
		TListItem  *ListItem;
		ListItem = Form1->ListView3->Items->Add();
		ListItem->Caption = "";
		ListItem->SubItems->Add(titulo);
		ListItem->SubItems->Add(nome_arq);
		ListItem->SubItems->Add(identificador);
		//nro_ata++;
		if (Application->MessageBox(L"Arquivo gerado com sucesso!\nLeia com aten��o o texto e corrija o que for preciso.\nDeseja visualiz�-lo agora?" , L"Mensagem", MB_OKCANCEL) == IDOK)
		{
			ShellExecute(Handle, "open", AnsiString(nome_arq).c_str(), 0, 0, SW_NORMAL);
		}
		} // fecha o if(continua)
		} // fecha o else da verificacao de abertura do arquivo

		// ------------------------------------

}
//---------------------------------------------------------------------------

