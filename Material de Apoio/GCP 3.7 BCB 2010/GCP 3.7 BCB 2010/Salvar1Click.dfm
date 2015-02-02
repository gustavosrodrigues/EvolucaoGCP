Salvar versão antiga (nao é válida a partir da versão 3)


void __fastcall TForm1::Salvar1Click(TObject *Sender)
{
        // !!!! Salvamento antigo - náo eh mais valido a partir da versao 3 !!!!!!!!!!

        // Salva todas as informações


        String nome_arq1 = projeto.nome + ".gcp";
        //String nome_arq = projeto.diretorio + "\\" + ExtractFileName(nome_arq1);
        String nome_arq = ExtractFileName(nome_arq1);

        FILE* arq_teste;
        arq_teste = fopen(nome_arq.c_str(), "at");
        if (!arq_teste)
        {
                Application->MessageBox("Não foi possível gerar o arquivo. Verifique se ele já está aberto.\nCaso esteja, feche-o e tente novamente", "Erro", 0);
                fclose(arq_teste);
        }
        else
        {
                fclose(arq_teste);


                using namespace std;
                fstream arq;
                //arq.open (nome_arq.c_str(), fstream::out | fstream::app);
                arq.open (nome_arq.c_str(), fstream::out);


                // ================ Variáveis externas =========================
                // ------------ Principal.h ---------------------
                // Variável projeto  -  tipo_projeto
                arq << projeto.diretorio.c_str() << endl;              // String
                arq << projeto.nome.c_str() << endl;           // String
                arq << projeto.ministerio.c_str() << endl;     // String
                arq << projeto.universidade.c_str() << endl;   // String
                arq << projeto.centro.c_str() << endl;          // String
                arq << projeto.departamento.c_str() << endl;    // String
                arq << projeto.campus.c_str() << endl;         // String
                arq << projeto.area.c_str() << endl;                   // String
                arq << projeto.classe << endl;                  // int
                arq << projeto.data_inicio.DateString().c_str() << endl;  // TDate

                // Variável linha_atual - int
                arq << linha_atual << endl;

                // Variável examinador  - tipo_examinador    (são sempre 3)
                for (int i=0; i<3; i++)
                {
                        arq << examinador[i].nome.c_str() << endl;  // String
                        //arq << examinador[i].instituicao.c_str() << endl; // String
                        arq << examinador[i].classe << endl;     // int
                        //arq << examinador[i].presidente << endl;  // bool
                        //arq << examinador[i].nome_completo.c_str() << endl; // String
                        arq << examinador[i].sexo << endl; // int
                }

                // Variável candidato - tipo_candidato
                arq << candidato.size() << endl;      // Nro de candidatos, int
                for (unsigned int i=0; i<candidato.size(); i++)
                {
                        arq << candidato[i].nome.c_str() << endl;  // String
                        arq << candidato[i].sexo << endl;  // int


                        //bool aprovado;
                        //bool desistente;   // Candidato desistiu durante o concurso
                        //bool ausente;   // Candidato não compareceu no concurso
                        //bool compareceu_realizacao_prova_escrita;
                        //bool compareceu_leitura_prova_escrita;
                        //bool compareceu_sorteio_prova_didatica;
                        //bool compareceu_realizacao_prova_didatica;
                        //bool compareceu_realizacao_prova_defesa;
                        //bool compareceu_realizacao_prova_titulos;

                        //for (int h=0; h<=4; h++)
                                for (int j=0; j<64; j++)
                                       arq << FormatFloat("0.00", candidato[i].nota_titulos[j]).c_str() << endl; // float

                        arq << candidato[i].nascimento.DateString().c_str() << endl;  // TDate


                }
                // Variavel ponto_escrita
                arq << ponto_escrita.size() << endl;  // Nro de pontos escrita
                for (unsigned int i=0; i<ponto_escrita.size(); i++)
                {
                        arq << ponto_escrita[i].texto.c_str() << endl;  // String
                        //arq << ponto_escrita[i].valido << endl; // bool
                }
                // Variavel ponto_didatica
                arq << ponto_didatica.size() << endl;  // Nro de pontos didatica
                for (unsigned int i=0; i<ponto_didatica.size(); i++)
                {
                        arq << ponto_didatica[i].texto.c_str() << endl;  // String
                        //arq << ponto_didatica[i].valido << endl; // bool
                }

                // vetores de TEdits das notas
                /*
                extern TEdit* Edit_pontuacao[64];
                extern TEdit* Edit_quantidade[64];
                extern TEdit* Edit_total[64];
                extern TStaticText* Texto_item[34]  */ // Nao precisa salvar

                // Lista de pontos - didatica.cpp
                arq << FormDidatica->ListBox1->Count << endl;
                for (int i=0; i<FormDidatica->ListBox1->Count; i++)
                {
                        arq <<  FormDidatica->ListBox1->Items->Strings[i].c_str() << endl;
                }
                // ------------------- DefesaprojetoCandidatos.cpp ----------------
                arq << FormDefesaProjeto_candidatos->ListBox2->Count << endl;
                for (int i=0; i<FormDefesaProjeto_candidatos->ListBox2->Count; i++)
                {
                        arq <<  FormDefesaProjeto_candidatos->ListBox2->Items->Strings[i].c_str() << endl;
                }
                arq << FormDefesaProjeto_candidatos->ListBox1->Count << endl;
                for (int i=0; i<FormDefesaProjeto_candidatos->ListBox1->Count; i++)
                {
                        arq <<  FormDefesaProjeto_candidatos->ListBox1->Items->Strings[i].c_str() << endl;
                }

                // ------------------- DidaticaCandidatos.cpp ----------------
                arq << FormDidaticaCandidatos->ListBox2->Count << endl;
                for (int i=0; i<FormDidaticaCandidatos->ListBox2->Count; i++)
                {
                        arq <<  FormDidaticaCandidatos->ListBox2->Items->Strings[i].c_str() << endl;
                }
                arq << FormDidaticaCandidatos->ListBox1->Count << endl;
                for (int i=0; i<FormDidaticaCandidatos->ListBox1->Count; i++)
                {
                        arq <<  FormDidaticaCandidatos->ListBox1->Items->Strings[i].c_str() << endl;
                }
                // Variavel nro_ata
                arq << nro_ata << endl;   // int

                // Variavel nro_lista
                arq << nro_lista << endl;   // int

                //extern vector<TLabel*> lab_def;   / Nao precisa salvar - na hora de abrir atualizar os objetos

                // Variavel dat_def - vector<TDateTimePicker>
                arq << dat_def.size() << endl;
                for (unsigned int i = 0; i< dat_def.size() ; i++)
                {
                     arq << dat_def[i]->Date.DateString().c_str() << endl;
                }

                // Variavel hor_def vector<TDateTimePicker*>
                arq << hor_def.size() << endl;
                for (unsigned int i=0; i<hor_def.size(); i++)
                {
                        arq << hor_def[i]->Time.TimeString().c_str() << endl;
                }

                // Variavel comp_def vector<TCheckBox*>
                arq << comp_def.size() << endl;
                for (unsigned int i=0; i<comp_def.size(); i++)
                {
                        arq << comp_def[i]->Checked << endl;
                }




                // ------------ Didatica.h ---------------------
                // extern vector<TLabel*> lab;  // nao precisa, atualiza quando gerar listagem

                // Variavel dat_sor - vector<TDateTimePicker>
                arq << dat_sor.size() << endl;
                for (unsigned int i = 0; i< dat_sor.size() ; i++)
                {
                     arq << dat_sor[i]->Date.DateString().c_str() << endl;
                }

                 // Variavel hor_sor vector<TDateTimePicker*>
                arq << hor_sor.size() << endl;
                for (unsigned int i=0; i<hor_sor.size(); i++)
                {
                        arq << hor_sor[i]->Time.TimeString().c_str() << endl;
                }

                // Variavel dat_apr - vector<TDateTimePicker>
                arq << dat_apr.size() << endl;
                for (unsigned int i = 0; i< dat_apr.size() ; i++)
                {
                     arq << dat_apr[i]->Date.DateString().c_str() << endl;
                }

                 // Variavel hor_apr vector<TDateTimePicker*>
                arq << hor_apr.size() << endl;
                for (unsigned int i=0; i<hor_apr.size(); i++)
                {
                        arq << hor_apr[i]->Time.TimeString().c_str() << endl;
                }

                // Variavel comp_sor vector<TCheckBox*>
                arq << comp_sor.size() << endl;
                for (unsigned int i=0; i<comp_sor.size(); i++)
                {
                        arq << comp_sor[i]->Checked << endl;
                }
                // Variavel comp_apr vector<TCheckBox*>
                arq << comp_apr.size() << endl;
                for (unsigned int i=0; i<comp_apr.size(); i++)
                {
                        arq << comp_apr[i]->Checked << endl;
                }

                // Variavel  ponto vector<TComboBox*>
                arq << ponto.size() << endl;
                for (unsigned int i=0; i<ponto.size(); i++)
                {
                        arq << ponto[i]->ItemIndex << endl;
                }


                // ================ Conteúdo dos objetos =========================

                // ---------- Principal.cpp ---------------------
                // StringGrid1
                arq << StringGrid1->ColCount << endl;
                arq << StringGrid1->RowCount << endl;
                for (int col =0; col<StringGrid1->ColCount; col++)
                        for (int lin=0; lin<StringGrid1->RowCount; lin++)
                        {
                                arq << StringGrid1->Cells[col][lin].c_str() << endl;
                        }


                // ---------- Configuracao.cpp ---------------------
                // - Pag1
                arq << FormConfiguracao->LabeledEdit1->Text.c_str() << endl;
                arq << FormConfiguracao->LabeledEdit5->Text.c_str() << endl;
                arq << FormConfiguracao->LabeledEdit6->Text.c_str() << endl;
                arq << FormConfiguracao->LabeledEdit7->Text.c_str() << endl;
                arq << FormConfiguracao->LabeledEdit8->Text.c_str() << endl;
                arq << FormConfiguracao->LabeledEdit2->Text.c_str() << endl;
                arq << FormConfiguracao->DateTimePicker1->Date.DateString().c_str() << endl;
                arq << FormConfiguracao->RadioGroup4->ItemIndex << endl;
                // - Pag2
                arq << FormConfiguracao->DirectoryListBox1->Directory.c_str() << endl;
                arq << FormConfiguracao->Edit4->Text.c_str() << endl;
                arq << FormConfiguracao->Edit5->Text.c_str() << endl;
                // - Pag3
                arq << FormConfiguracao->Edit1->Text.c_str() << endl;
                arq << FormConfiguracao->Edit2->Text.c_str() << endl;
                arq << FormConfiguracao->Edit6->Text.c_str() << endl;
                arq << FormConfiguracao->RadioGroup1->ItemIndex << endl;
                arq << FormConfiguracao->RadioGroup2->ItemIndex << endl;
                arq << FormConfiguracao->RadioGroup5->ItemIndex << endl;
                arq << FormConfiguracao->RadioGroup6->ItemIndex << endl;
                arq << FormConfiguracao->RadioGroup7->ItemIndex << endl;
                arq << FormConfiguracao->RadioGroup8->ItemIndex << endl;
                // List_Banca -- nao precisa
                // - Pag4
                arq << FormConfiguracao->List_Candidatos->Count << endl;
                for (int i=0; i<FormConfiguracao->List_Candidatos->Count; i++)
                {
                        arq << FormConfiguracao->List_Candidatos->Items->Strings[i].c_str() << endl;
                }
                //arq << FormConfiguracao->Edit3->Text.c_str() << endl;     // nao precisa
                //arq << FormConfiguracao->RadioGroup3->ItemIndex << endl;  // nao precisa

                // ----------------- DefesaProjeto.cpp -------------------------
                arq << FormDefesaProjeto->Edit1->Text.c_str() << endl;
                arq << FormDefesaProjeto->ListBox2->Count << endl;
                for (int i=0; i<FormDefesaProjeto->ListBox2->Count; i++)
                {
                        arq <<  FormDefesaProjeto->ListBox2->Items->Strings[i].c_str() << endl;
                }
                arq << FormDefesaProjeto->ListBox3->Count << endl;
                for (int i=0; i<FormDefesaProjeto->ListBox3->Count; i++)
                {
                        arq <<  FormDefesaProjeto->ListBox3->Items->Strings[i].c_str() << endl;
                }
                arq << FormDefesaProjeto->ValueListEditor1->Strings->Count << endl;
                for (int i=0; i<FormDefesaProjeto->ValueListEditor1->Strings->Count; i++)
                {
                        arq <<  FormDefesaProjeto->ValueListEditor1->Strings->Strings[i].c_str() << endl;
                }

                // ----------------- Didatica.cpp -------------------------
                arq << FormDidatica->Edit1->Text.c_str() << endl;
                arq << FormDidatica->Edit2->Text.c_str() << endl;
                arq << FormDidatica->ListBox2->Count << endl;
                for (int i=0; i<FormDidatica->ListBox2->Count; i++)
                {
                        arq <<  FormDidatica->ListBox2->Items->Strings[i].c_str() << endl;
                }
                arq << FormDidatica->ListBox3->Count << endl;
                for (int i=0; i<FormDidatica->ListBox3->Count; i++)
                {
                        arq <<  FormDidatica->ListBox3->Items->Strings[i].c_str() << endl;
                }

                arq << FormDidatica->ValueListEditor1->Strings->Count << endl;
                for (int i=0; i<FormDidatica->ValueListEditor1->Strings->Count; i++)
                {
                        arq <<  FormDidatica->ValueListEditor1->Strings->Strings[i].c_str() << endl;
                }

                // ----------------- escrita.cpp -------------------------
                arq << FormEscrita->Edit2->Text.c_str() << endl;
                arq << FormEscrita->ListBox2->Count << endl;
                for (int i=0; i<FormEscrita->ListBox2->Count; i++)
                {
                        arq <<  FormEscrita->ListBox2->Items->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->ListBox3->Count << endl;
                for (int i=0; i<FormEscrita->ListBox3->Count; i++)
                {
                        arq <<  FormEscrita->ListBox3->Items->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->ValueListEditor1->Strings->Count << endl;
                for (int i=0; i<FormEscrita->ValueListEditor1->Strings->Count; i++)
                {
                        arq <<  FormEscrita->ValueListEditor1->Strings->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->ListBox1->Count << endl;
                for (int i=0; i<FormEscrita->ListBox1->Count; i++)
                {
                        arq <<  FormEscrita->ListBox1->Items->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->ListBox4->Count << endl;
                for (int i=0; i<FormEscrita->ListBox4->Count; i++)
                {
                        arq <<  FormEscrita->ListBox4->Items->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->CheckListBox1->Count << endl;
                for (int i=0; i<FormEscrita->CheckListBox1->Count; i++)
                {
                        arq <<  FormEscrita->CheckListBox1->Items->Strings[i].c_str() << endl;
                }
                arq << FormEscrita->Edit2->Text.c_str() << endl;
                arq << FormEscrita->DateTimePicker3->Date.DateString().c_str() << endl;
                arq << FormEscrita->DateTimePicker6->Date.DateString().c_str() << endl;
                arq << FormEscrita->DateTimePicker1->Time.TimeString().c_str() << endl;
                arq << FormEscrita->DateTimePicker2->Time.TimeString().c_str() << endl;
                arq << FormEscrita->CSpinEdit1->Value << endl;
                arq << FormEscrita->DateTimePicker8->Time.TimeString().c_str() << endl;
                arq << FormEscrita->DateTimePicker7->Time.TimeString().c_str() << endl;
                arq << FormEscrita->Edit3->Text.c_str() << endl;

                arq << FormEscrita->DateTimePicker4->Date.DateString().c_str() << endl;
                arq << FormEscrita->DateTimePicker5->Time.TimeString().c_str() << endl;
                arq << FormEscrita->Edit1->Text.c_str() << endl;

                // ----------------- titulos.cpp -------------------------
                arq << FormTitulos->DateTimePicker1->Date.DateString().c_str() << endl;
                arq << FormTitulos->DateTimePicker2->Time.TimeString().c_str() << endl;
                arq << FormTitulos->Edit1->Text.c_str() << endl;
                /*
                for (int i=0; i<64; i++)
                {
                        arq << Edit_quantidade[i]->Text.c_str() << endl;
                }
                    */
                arq << FormTitulos->ComboBox1->Items->Count << endl;
                for (int i=0; i<FormTitulos->ComboBox1->Items->Count; i++)
                {
                        arq <<  FormTitulos->ComboBox1->Items->Strings[i].c_str() << endl;
                }
                arq << FormTitulos->ComboBox2->Items->Count << endl;
                for (int i=0; i<FormTitulos->ComboBox2->Items->Count; i++)
                {
                        arq <<  FormTitulos->ComboBox2->Items->Strings[i].c_str() << endl;
                }      

                arq << FormTitulos->Edit2->Text.c_str() << endl;
                arq << FormTitulos->Edit3->Text.c_str() << endl;
                arq << FormTitulos->Edit4->Text.c_str() << endl;
                arq << FormTitulos->Edit8->Text.c_str() << endl;
                arq << FormTitulos->Edit9->Text.c_str() << endl;
                arq << FormTitulos->Edit10->Text.c_str() << endl;

                // ------------------- Cabeçalho.cpp ----------------------------
                arq << FormCabecalho->RichEdit1->Lines->Count << endl;
                for (int i=0; i<FormCabecalho->RichEdit1->Lines->Count; i++)
                {
                       arq <<  FormCabecalho->RichEdit1->Lines->Strings[i].c_str() << endl;
                }




                // --------------------- Abertura.cpp -------------------------
                arq << FormAbertura->CheckListBox1->Count << endl;
                for (int i=0; i<FormAbertura->CheckListBox1->Count; i++)
                {
                        arq <<  FormAbertura->CheckListBox1->Items->Strings[i].c_str() << endl;
                }
                arq << FormAbertura->DateTimePicker1->Date.DateString().c_str() << endl;
                arq << FormAbertura->DateTimePicker2->Time.TimeString().c_str() << endl;
                arq << FormAbertura->Edit1->Text.c_str() << endl;
                arq << FormAbertura->Edit2->Text.c_str() << endl;
                arq << FormAbertura->Edit3->Text.c_str() << endl;
                arq << FormAbertura->DateTimePicker3->Date.DateString().c_str() << endl;
                arq << FormAbertura->StringGrid1->ColCount << endl;
                arq << FormAbertura->StringGrid1->RowCount << endl;
                for (int col = 0; col < FormAbertura->StringGrid1->ColCount; col++)
                        for (int row=0; row <  FormAbertura->StringGrid1->RowCount; row++)
                        {
                                arq << FormAbertura->StringGrid1->Cells[col][row].c_str() << endl;
                        }

                // -------------------- Resultado.cpp ----------------------------
                arq << FormResultado->DateTimePicker1->Date.DateString().c_str() << endl;
                arq << FormResultado->DateTimePicker2->Time.TimeString().c_str() << endl;
                arq << FormResultado->Edit1->Text.c_str() << endl;

                // vector<TTabSheet*> pagina;  // nao precisa

                // -- vector<TStringGrid*> tabela
                arq << tabela.size() << endl;
                for (int i=0; i<tabela.size(); i++)
                {
                        arq << tabela[i]->RowCount << endl;
                        arq << tabela[i]->ColCount << endl;
                        for (int col = 0; col<tabela[i]->ColCount; col++)
                                for (int row = 0;  row < tabela[i]->RowCount; row++)
                                        arq << tabela[i]->Cells[col][row].c_str() << endl;
                }
                // vector<TLabel*> nota_final;
                arq << nota_final.size() << endl;
                for (int i=0; i<nota_final.size(); i++)
                {
                        arq << nota_final[i]->Caption.c_str() << endl;
                }

                // vector<float> media_titulos;          ^// nao precisa
                // vector<float> media_escrita;
                // vector<float> media_defesa;
                // extern vector<float> media_didatica;

                // ------- Listagem.cpp ----------------------
               /* arq << FormListagem->CheckBox1->Checked << endl;
                arq << FormListagem->CheckBox2->Checked << endl;
                arq << FormListagem->CheckBox3->Checked << endl;
                arq << FormListagem->CheckBox4->Checked << endl;
                arq << FormListagem->CheckBox5->Checked << endl;
                arq << FormListagem->CheckBox6->Checked << endl;
                arq << FormListagem->CheckBox7->Checked << endl;
                arq << FormListagem->CheckBox8->Checked << endl;
                arq << FormListagem->CheckBox9->Checked << endl;
                arq << FormListagem->CheckBox10->Checked << endl;
                arq << FormListagem->CheckBox11->Checked << endl;
                arq << FormListagem->CheckBox12->Checked << endl;
                arq << FormListagem->CheckBox13->Checked << endl;
                arq << FormListagem->CheckBox14->Checked << endl;
                arq << FormListagem->CheckBox15->Checked << endl;
                arq << FormListagem->CheckBox16->Checked << endl;
                arq << FormListagem->CheckBox17->Checked << endl;
                arq << FormListagem->CheckBox18->Checked << endl;
                arq << FormListagem->CheckBox19->Checked << endl;
                arq << FormListagem->CheckBox20->Checked << endl;
                arq << FormListagem->CheckBox21->Checked << endl;
                arq << FormListagem->CheckBox22->Checked << endl;
                arq << FormListagem->CheckBox23->Checked << endl;
                arq << FormListagem->CheckBox24->Checked << endl;
                arq << FormListagem->CheckBox25->Checked << endl;
                arq << FormListagem->CheckBox26->Checked << endl;
                arq << FormListagem->CheckBox27->Checked << endl;
                arq << FormListagem->CheckBox28->Checked << endl;
                arq << FormListagem->CheckBox29->Checked << endl;
                arq << FormListagem->CheckBox30->Checked << endl;
                */
                arq.close();

                String mess = "Arquivo " + nome_arq + " salvo com sucesso.";
                Application->MessageBox(mess.c_str(), "Aviso", 0);
        }

}
