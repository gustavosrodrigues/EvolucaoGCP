Não funciona mais a partir da versão 3.

void __fastcall TForm1::Abrir1Click(TObject *Sender)
{
        // Abre o projeto selecionado
        // Nao funciona mais a partir da versao 3 !!!!!!!!!!!!!!!1

   if (OpenDialog1->Execute())
   {


        String nome_arq = OpenDialog1->FileName;
        Form1->Caption = "Gerenciador de Concursos Públicos - UNIPAMPA - " + ExtractFileName(nome_arq);
        String temp = ExtractFileDir(nome_arq);
        bool foi= SetCurrentDir(temp);

                      using namespace std;
                fstream arq (nome_arq.c_str());
         char p[500];
         int p1;

        // Habilita os botoes principais
        Form1->BitBtn1->Enabled = true;
        Form1->BitBtn3->Enabled = true;
        Form1->BitBtn4->Enabled = true;
        Form1->BitBtn5->Enabled = true;
        Form1->BitBtn6->Enabled = true;
        Form1->BitBtn9->Enabled = true;


        // seek back to the beginning of the file
        arq.seekg(0);

        // extract the first line
        arq.getline(p,500);

                // ================ Variáveis externas =========================
                // ------------ Principal.h ---------------------
                // Variável projeto  -  tipo_projeto
                //projeto.diretorio = p;              // String
                arq.getline(p,500);
                projeto.nome = p;           // String
                arq.getline(p,500);
                projeto.ministerio = p;     // String
                arq.getline(p,500);
                projeto.universidade = p;   // String
                arq.getline(p,500);
                projeto.centro = p;       // String
                arq.getline(p,500);
                projeto.departamento = p;    // String
                arq.getline(p,500);
                projeto.campus = p;         // String
                arq.getline(p,500);
                projeto.area = p;                   // String
                arq.getline(p,500);
                projeto.classe = StrToInt(p);                  // int
                arq.getline(p,500);
                if (!TryStrToDate(p, projeto.data_inicio))  //  = StrToInt(p);
                {
                        projeto.data_inicio = (TDate) "01/01/01";
                        Application->MessageBox("Erro na leitura da variável projeto.data_inicio","Erro",0);
                }
                //projeto.data_inicio = (TDate) p;  // TDate

                // Variável linha_atual - int
                arq.getline(p,500);
                if (!TryStrToInt(p, linha_atual))  //  = StrToInt(p);
                {
                        linha_atual = 1;
                        Application->MessageBox("Erro na leitura da variável linha_atual","Erro",0);
                }
                // Variável examinador  - tipo_examinador    (são sempre 3)
                for (int i=0; i<3; i++)
                {
                        arq.getline(p,500);
                        examinador[i].nome = p;  // String
                        arq.getline(p,500);
                        String nada = p; // String
                        arq.getline(p,500);
                        examinador[i].classe = StrToInt(p);     // int
                        //arq << examinador[i].presidente << endl;  // bool
                        arq.getline(p,500);
                        examinador[i].nome_completo = p; // String
                        arq.getline(p,500);
                        if (!TryStrToInt(p, examinador[i].sexo))  //  = StrToInt(p);
                        {
                                examinador[i].sexo = 0;
                                Application->MessageBox("Erro na leitura da variável examinador.sexo","Erro",0);
                        }
                        //examinador[i].sexo = StrToInt(p); // int
                }

                // Variável candidato - tipo_candidato
                arq.getline(p,500);     // candidato.size()
                candidato.clear();
                candidato.resize(StrToInt(p));

                for (unsigned int i=0; i<candidato.size(); i++)
                {
                        arq.getline(p,500);
                        candidato[i].nome = p;  // String
                        arq.getline(p,500);
                        candidato[i].sexo = StrToInt(p);  // int


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
                                {
                                       arq.getline(p,500);
                                       candidato[i].nota_titulos[j] = StrToFloat(p); // float
                                }
                        arq.getline(p,500);
                        candidato[i].nascimento = (TDate) p;  // TDate


                }
                // Variavel ponto_escrita
                arq.getline(p,500);   // ponto_escrita.size()
                ponto_escrita.clear();
                ponto_escrita.resize(StrToInt(p));

                for (unsigned int i=0; i<ponto_escrita.size(); i++)
                {
                        arq.getline(p,500);
                        ponto_escrita[i].texto = p;  // String
                        //arq << ponto_escrita[i].valido << endl; // bool
                }
                // Variavel ponto_didatica
                arq.getline(p,500);  // pónto_didatica.size()
                ponto_didatica.clear();
                ponto_didatica.resize(StrToInt(p));

                for (unsigned int i=0; i<ponto_didatica.size(); i++)
                {
                        arq.getline(p,500);
                        ponto_didatica[i].texto = p;  // String
                        //arq << ponto_didatica[i].valido << endl; // bool
                }

                // vetores de TEdits das notas
                /*
                extern TEdit* Edit_pontuacao[64];
                extern TEdit* Edit_quantidade[64];
                extern TEdit* Edit_total[64];
                extern TStaticText* Texto_item[34]  */ // Nao precisa salvar

                // Lista de pontos - didatica.cpp
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDidatica->ListBox1->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidatica->ListBox1->Items->Add(p);
                }
                // ------------------- DefesaprojetoCandidatos.cpp ----------------
                arq.getline(p,500);
                FormDefesaProjeto_candidatos->ListBox2->Clear();
                p1 = StrToInt(p);
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDefesaProjeto_candidatos->ListBox2->Items->Add(p);
                }
                arq.getline(p,500);
                FormDefesaProjeto_candidatos->ListBox1->Clear();
                p1 = StrToInt(p);
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDefesaProjeto_candidatos->ListBox1->Items->Add(p);
                }
                FormDefesaProjeto_candidatos->Button1Click(Form1);
                // ------------------- DidaticaCandidatos.cpp ----------------
                arq.getline(p,500);
                FormDidaticaCandidatos->ListBox2->Clear();
                p1 = StrToInt(p);
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidaticaCandidatos->ListBox2->Items->Add(p);
                }
                arq.getline(p,500);
                FormDidaticaCandidatos->ListBox1->Clear();
                p1 = StrToInt(p);
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidaticaCandidatos->ListBox1->Items->Add(p);
                }
                FormDidaticaCandidatos->Button1Click(Form1);

                // Variavel nro_ata
                arq.getline(p,500);
                nro_ata = StrToInt(p);   // int

                // Variavel nro_lista
                arq.getline(p,500);
                nro_lista = StrToInt(p);   // int

                //extern vector<TLabel*> lab_def;   / Nao precisa salvar - na hora de abrir atualizar os objetos

                // Variavel dat_def - vector<TDateTimePicker>
                arq.getline(p,500);  // dat_def.size()
                p1 = StrToInt(p);
                //dat_def.clear();
                //dat_def.resize(StrToInt(p));
                for (unsigned int i = 0; i< p1 ; i++)
                {
                     arq.getline(p,500);
                     dat_def[i]->Date = (TDate) p;
                }

                // Variavel hor_def vector<TDateTimePicker*>
                arq.getline(p,500);   // hor_def.size()
                p1 = StrToInt(p);
                //hor_def.clear();
                //hor_def.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        hor_def[i]->Time = (TTime) p;
                }

                // Variavel comp_def vector<TCheckBox*>
                arq.getline(p,500);   // comp_def.size()
                p1 = StrToInt(p);
                //comp_def.clear();
                //comp_def.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        comp_def[i]->Checked = StrToInt(p);
                }


                // ------------ Didatica.h ---------------------
                // extern vector<TLabel*> lab;  // nao precisa, atualiza quando gerar listagem



                // Variavel dat_sor - vector<TDateTimePicker>
                arq.getline(p,500);   // dat_sor.size()
                p1 = StrToInt(p);
                //dat_sor.clear();
                //dat_sor.resize(StrToInt(p));
                for (unsigned int i = 0; i< p1 ; i++)
                {
                     arq.getline(p,500);
                     dat_sor[i]->Date = (TDate) p;
                }

                 // Variavel hor_sor vector<TDateTimePicker*>
                arq.getline(p,500);  // hor_sor.size()
                p1 = StrToInt(p);
                //hor_sor.clear();
                //hor_sor.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        hor_sor[i]->Time = (TTime) p;
                }

                // Variavel dat_apr - vector<TDateTimePicker>
                arq.getline(p,500);  // dat_apr.size()
                p1 = StrToInt(p);
                //dat_apr.clear();
                //dat_apr.resize(StrToInt(p));
                for (unsigned int i = 0; i< p1 ; i++)
                {
                     arq.getline(p,500);
                     dat_apr[i]->Date = (TDate) p;
                }

                 // Variavel hor_apr vector<TDateTimePicker*>
                arq.getline(p,500);  // hor_apr.size()
                p1 = StrToInt(p);
                //hor_apr.clear();
                //hor_apr.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        hor_apr[i]->Time = (TTime) p;
                }

                // Variavel comp_sor vector<TCheckBox*>
                arq.getline(p,500);  // comp_sor.size()

                p1 = StrToInt(p);//comp_sor.clear();
                //comp_sor.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        comp_sor[i]->Checked = StrToInt(p);
                }
                // Variavel comp_apr vector<TCheckBox*>
                arq.getline(p,500);   // comp_apr.size()
                p1 = StrToInt(p);
                //comp_apr.clear();
                //comp_apr.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        comp_apr[i]->Checked = StrToInt(p);
                }

                // Variavel  ponto vector<TComboBox*>
                arq.getline(p,500);   // ponto.size()
                p1 = StrToInt(p);
                //ponto.clear();
                //ponto.resize(StrToInt(p));
                for (unsigned int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        ponto[i]->ItemIndex = StrToInt(p);
                }


                // ================ Conteúdo dos objetos =========================

                // ---------- Principal.cpp ---------------------
                // StringGrid1
                arq.getline(p,500);    // StringGrid1->ColCount
                int tcol = StrToInt(p);
                arq.getline(p,500);      // StringGrid1->RowCount
                int tlin = StrToInt(p);
                StringGrid1->RowCount = tlin;
                for (int col =0; col<tcol; col++)
                        for (int lin=0; lin<tlin; lin++)
                        {
                                arq.getline(p,500);
                                StringGrid1->Cells[col][lin] = p;
                        }


                // ---------- Configuracao.cpp ---------------------
                // - Pag1
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit1->Text = p;
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit5->Text = p;
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit6->Text = p;
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit7->Text = p;
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit8->Text = p;
                arq.getline(p,500);
                FormConfiguracao->LabeledEdit2->Text = p;
                arq.getline(p,500);
                FormConfiguracao->DateTimePicker1->Date = (TDate) p;
                arq.getline(p,500);
                FormConfiguracao->RadioGroup4->ItemIndex = StrToInt(p);
                // - Pag2
                arq.getline(p,500);
                FormConfiguracao->DirectoryListBox1->Directory = GetCurrentDir();
                arq.getline(p,500);
                FormConfiguracao->Edit4->Text = p;
                arq.getline(p,500);
                FormConfiguracao->Edit5->Text = p;
                // - Pag3
                arq.getline(p,500);
                FormConfiguracao->Edit1->Text = p;
                arq.getline(p,500);
                FormConfiguracao->Edit2->Text = p;
                arq.getline(p,500);
                FormConfiguracao->Edit6->Text = p;
                arq.getline(p,500);
                FormConfiguracao->RadioGroup1->ItemIndex  = StrToInt(p);
                arq.getline(p,500);
                FormConfiguracao->RadioGroup2->ItemIndex = StrToInt(p);
                arq.getline(p,500);
                FormConfiguracao->RadioGroup5->ItemIndex = StrToInt(p);
                arq.getline(p,500);
                FormConfiguracao->RadioGroup6->ItemIndex = StrToInt(p);
                arq.getline(p,500);
                FormConfiguracao->RadioGroup7->ItemIndex = StrToInt(p);
                arq.getline(p,500);
                FormConfiguracao->RadioGroup8->ItemIndex = StrToInt(p);
                // List_Banca -- nao precisa
                // - Pag4
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormConfiguracao->List_Candidatos->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormConfiguracao->List_Candidatos->Items->Add(p);
                }
                //arq << FormConfiguracao->Edit3->Text.c_str() << endl;     // nao precisa
                //arq << FormConfiguracao->RadioGroup3->ItemIndex << endl;  // nao precisa

                // ----------------- DefesaProjeto.cpp -------------------------
                arq.getline(p,500);
                FormDefesaProjeto->Edit1->Text = p;
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDefesaProjeto->ListBox2->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDefesaProjeto->ListBox2->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDefesaProjeto->ListBox3->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDefesaProjeto->ListBox3->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDefesaProjeto->ValueListEditor1->Strings->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDefesaProjeto->ValueListEditor1->Strings->Add(p);
                }

                // ----------------- Didatica.cpp -------------------------
                arq.getline(p,500);
                FormDidatica->Edit1->Text = p;
                arq.getline(p,500);
                FormDidatica->Edit2->Text = p;
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDidatica->ListBox2->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidatica->ListBox2->Items->Strings[i] = p;
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDidatica->ListBox3->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidatica->ListBox3->Items->Add(p);
                }

                arq.getline(p,500);
                p1 = StrToInt(p);
                FormDidatica->ValueListEditor1->Strings->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormDidatica->ValueListEditor1->Strings->Add(p);
                }

                // ----------------- escrita.cpp -------------------------
                arq.getline(p,500);
                FormEscrita->Edit2->Text = p;
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->ListBox2->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->ListBox2->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->ListBox3->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->ListBox3->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->ValueListEditor1->Strings->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->ValueListEditor1->Strings->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->ListBox1->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->ListBox1->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->ListBox4->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->ListBox4->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormEscrita->CheckListBox1->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormEscrita->CheckListBox1->Items->Add(p);
                }
                FormEscrita->CheckListBox2->Clear();
                FormEscrita->CheckListBox2->Items = FormEscrita->CheckListBox1->Items;
                arq.getline(p,500);
                FormEscrita->Edit2->Text = p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker3->Date = (TDate) p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker6->Date = (TDate) p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker1->Time = (TTime) p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker2->Time = (TTime) p;
                arq.getline(p,500);
                if (FormEscrita->ListBox1->Items->Count >= 0)       // Mudei aqui de CheckListBox1 para ListBox1!!!
                        FormEscrita->CSpinEdit1->MaxValue = FormEscrita->ListBox1->Items->Count;
                if (!TryStrToInt(p, FormEscrita->CSpinEdit1->Value))
                {
                       Application->MessageBox("Valor do ponto sorteado para prova escrita não é numérico.","Erro",0);
                }
                //FormEscrita->CSpinEdit1->Value = StrToInt(p);
                arq.getline(p,500);
                FormEscrita->DateTimePicker8->Time = (TTime) p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker7->Time = (TTime) p;
                arq.getline(p,500);
                FormEscrita->Edit3->Text = p;

                arq.getline(p,500);
                FormEscrita->DateTimePicker4->Date = (TDate) p;
                arq.getline(p,500);
                FormEscrita->DateTimePicker5->Time = (TTime) p;
                arq.getline(p,500);
                FormEscrita->Edit1->Text = p;



                // ----------------- titulos.cpp -------------------------
                arq.getline(p,500);
                FormTitulos->DateTimePicker1->Date = (TDate) p;
                arq.getline(p,500);
                FormTitulos->DateTimePicker2->Time = (TTime) p;
                arq.getline(p,500);
                FormTitulos->Edit1->Text = p;
                /*
                for (int i=0; i<64; i++)
                {
                        arq << Edit_quantidade[i]->Text.c_str() << endl;
                }
                */
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormTitulos->ComboBox1->Items->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormTitulos->ComboBox1->Items->Add(p);
                }
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormTitulos->ComboBox2->Items->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormTitulos->ComboBox2->Items->Add(p);
                }


                arq.getline(p,500);
                FormTitulos->Edit2->Text = p;
                arq.getline(p,500);
                FormTitulos->Edit3->Text = p;
                arq.getline(p,500);
                FormTitulos->Edit4->Text = p;
                arq.getline(p,500);
                FormTitulos->Edit8->Text = p;
                arq.getline(p,500);
                FormTitulos->Edit9->Text = p;
                arq.getline(p,500);
                FormTitulos->Edit10->Text = p;

                // ------------------- Cabeçalho.cpp ----------------------------
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormCabecalho->RichEdit1->Lines->Clear();
                for (int i=0; i<p1; i++)
                {
                       arq.getline(p,500);
                       FormCabecalho->RichEdit1->Lines->Add(p);
                }




                // --------------------- Abertura.cpp -------------------------
                arq.getline(p,500);
                p1 = StrToInt(p);
                FormAbertura->CheckListBox1->Clear();
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        FormAbertura->CheckListBox1->Items->Add(p);
                }
                arq.getline(p,500);
                FormAbertura->DateTimePicker1->Date = (TDate) p;
                arq.getline(p,500);
                FormAbertura->DateTimePicker2->Time = (TTime) p;
                arq.getline(p,500);
                FormAbertura->Edit1->Text = p;
                arq.getline(p,500);
                FormAbertura->Edit2->Text = p;
                arq.getline(p,500);
                FormAbertura->Edit3->Text = p;
                arq.getline(p,500);
                FormAbertura->DateTimePicker3->Date = (TDate) p;
                arq.getline(p,500);
                FormAbertura->StringGrid1->ColCount = StrToInt(p);
                arq.getline(p,500);
                FormAbertura->StringGrid1->RowCount = StrToInt(p);
                for (int col = 0; col < FormAbertura->StringGrid1->ColCount; col++)
                        for (int row=0; row <  FormAbertura->StringGrid1->RowCount; row++)
                        {
                                arq.getline(p,500);
                                FormAbertura->StringGrid1->Cells[col][row] = p;
                        }

                // -------------------- Resultado.cpp ----------------------------
                arq.getline(p,500);
                FormResultado->DateTimePicker1->Date = (TDate) p;
                arq.getline(p,500);
                FormResultado->DateTimePicker2->Time = (TTime) p;
                arq.getline(p,500);
                FormResultado->Edit1->Text = p;

                // vector<TTabSheet*> pagina;  // nao precisa

                // -- vector<TStringGrid*> tabela
                arq.getline(p,500);
                p1 = StrToInt(p);
                //tabela.clear();
                FormResultado->Button1Click(Form1); // Gera as tabelas em FormResultado
                //tabela.resize(p1);
                for (int i=0; i<p1; i++)
                {
                        arq.getline(p,500);
                        tabela[i]->RowCount = StrToInt(p);
                        arq.getline(p,500);
                        tabela[i]->ColCount = StrToInt(p);
                        for (int col = 0; col<tabela[i]->ColCount; col++)
                                for (int row = 0;  row < tabela[i]->RowCount; row++)
                                {
                                        arq.getline(p,500);
                                        tabela[i]->Cells[col][row] = p;
                                }
                }

                FormResultado->Button2Click(Form1); // Calcula em FormResultado
                // vector<TLabel*> nota_final;
                arq.getline(p,500);
                p1 = StrToInt(p);
                //nota_final.clear();
                //nota_final.resize(p1);
                for (int i=0; i<p1; i++)
                {
                         arq.getline(p,500);
                        //nota_final[i]->Caption = p;
                }



                // vector<float> media_titulos;          ^// nao precisa
                // vector<float> media_escrita;
                // vector<float> media_defesa;
                // extern vector<float> media_didatica;

                // ------- Listagem.cpp ----------------------
              /*  arq.getline(p,500);
                FormListagem->CheckBox1->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox2->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox3->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox4->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox5->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox6->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox7->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox8->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox9->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox10->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox11->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox12->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox13->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox14->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox15->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox16->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox17->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox18->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox19->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox20->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox21->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox22->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox23->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox24->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox25->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox26->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox27->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox28->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox29->Checked = StrToInt(p);
                arq.getline(p,500);
                FormListagem->CheckBox30->Checked = StrToInt(p);
               */

                arq.close();
        }

}
