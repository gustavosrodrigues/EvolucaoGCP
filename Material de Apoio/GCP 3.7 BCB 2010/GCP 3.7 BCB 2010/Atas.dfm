object FormAtas: TFormAtas
  Left = 296
  Top = 236
  Caption = 'FormAtas'
  ClientHeight = 444
  ClientWidth = 957
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 8
    Width = 913
    Height = 425
    ActivePage = TabSheet7
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      object Label1: TLabel
        Left = 32
        Top = 104
        Width = 84
        Height = 13
        Caption = 'Nome do arquivo:'
      end
      object Label2: TLabel
        Left = 80
        Top = 152
        Width = 31
        Height = 13
        Caption = 'T'#237'tulo:'
      end
      object Label3: TLabel
        Left = 88
        Top = 128
        Width = 20
        Height = 13
        Caption = 'Nro:'
      end
      object Button1: TButton
        Left = 54
        Top = 40
        Width = 75
        Height = 25
        Caption = 'Gerar RTF'
        TabOrder = 0
        OnClick = Button1Click
      end
      object RichEdit1: TRichEdit
        Left = 472
        Top = 12
        Width = 337
        Height = 369
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Lines.Strings = (
          'Aos cinco dias do m'#234's de novembro do '
          'ano de dois mil e sete, '#224's oito horas e '
          'trinta minutos, na sala n'#250'mero cento e '
          'doze do pr'#233'dio do Centro de Tecnologia '
          'de Alegrete da Universidade Federal do '
          'Pampa (Unipampa/UFSM), reuniram-se '
          'os professores Bernardete Trindade, '
          'Almir Barros da Silva Santos Neto e '
          'Alessandro Gon'#231'alves Girardi, para a '
          'instala'#231#227'o da Comiss'#227'o Examinadora do '
          'Concurso P'#250'blico de T'#237'tulos e Provas '
          'para Professor Adjunto para o Centro de '
          'Tecnologia de Alegrete, na '#225'rea de '
          'Desenho, conforme portaria 010/2007 '
          'da Dire'#231#227'o do Centro de Tecnologia de '
          'Alegrete e anexada ao presente '
          'processo.  Nesta reuni'#227'o foram '
          'discutidos e aprovados os crit'#233'rios de '
          'avalia'#231#227'o da prova escrita, os crit'#233'rios '
          'de avalia'#231#227'o da prova did'#225'tica e os sub-'
          'crit'#233'rios para a avalia'#231#227'o da prova de '
          't'#237'tulos (baseados na Resolu'#231#227'o 16/84 '
          'da Comiss'#227'o Permanente de Pessoal '
          'Docente da UFSM). Tamb'#233'm foram '
          'definidos os pontos para as provas '
          'escrita e did'#225'tica. Al'#233'm disso, tamb'#233'm '
          'foram tomadas delibera'#231#245'es e '
          'provid'#234'ncias de ordem geral a fim de '
          'viabilizar o bom desenvolvimento do '
          'concurso. Nada mais havendo a tratar, '
          'lavrou-se a presente ata, assinada por '
          'todos os membros efetivos da Comiss'#227'o '
          'Examinadora.')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 1
      end
      object Edit1: TEdit
        Left = 128
        Top = 96
        Width = 121
        Height = 21
        TabOrder = 2
        Text = 'c:\teste.rtf'
      end
      object Edit2: TEdit
        Left = 128
        Top = 152
        Width = 281
        Height = 21
        TabOrder = 3
        Text = 'Instala'#231#227'o da Comiss'#227'o Examinadora'
      end
      object Edit3: TEdit
        Left = 128
        Top = 120
        Width = 121
        Height = 21
        TabOrder = 4
        Text = '01'
      end
      object ComboBox1: TComboBox
        Left = 64
        Top = 208
        Width = 97
        Height = 21
        ItemIndex = 0
        TabOrder = 5
        Text = '01'
        Visible = False
        Items.Strings = (
          '01'
          '02'
          '03'
          '04'
          '05'
          '06'
          '07'
          '08'
          '09'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24'
          '25'
          '26'
          '27'
          '28'
          '29'
          '30'
          '31')
      end
      object ComboBox2: TComboBox
        Left = 168
        Top = 208
        Width = 105
        Height = 21
        ItemIndex = 0
        TabOrder = 6
        Text = 'janeiro'
        Visible = False
        Items.Strings = (
          'janeiro'
          'fevereiro'
          'mar'#231'o'
          'abril'
          'maio'
          'junho'
          'nulho'
          'agosto'
          'setembro'
          'outubro'
          'novembro'
          'dezembro')
      end
      object ComboBox3: TComboBox
        Left = 280
        Top = 208
        Width = 97
        Height = 21
        TabOrder = 7
        Text = '2008'
        Visible = False
        Items.Strings = (
          '2000'
          '2001'
          '2002'
          '2003'
          '2004'
          '2005'
          '2006'
          '2007'
          '2008'
          '2009'
          '2010'
          '2011'
          '2012'
          '2013'
          '2014'
          '2015'
          '2016'
          '2017'
          '2018'
          '2019'
          '2020'
          '2021'
          '2022'
          '2023'
          '2024'
          '2025'
          '2026'
          '2027'
          '2028'
          '2029'
          '2030')
      end
      object DateTimePicker1: TDateTimePicker
        Left = 72
        Top = 240
        Width = 305
        Height = 21
        Date = 39566.365571099500000000
        Time = 39566.365571099500000000
        DateFormat = dfLong
        TabOrder = 8
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prova t'#237'tulos'
      ImageIndex = 1
      OnShow = TabSheet2Show
      object Label7: TLabel
        Left = 576
        Top = 128
        Width = 147
        Height = 13
        Caption = 'Larguras das c'#233'lulas da tabela:'
        Visible = False
      end
      object Button2: TButton
        Left = 24
        Top = 32
        Width = 217
        Height = 25
        Caption = 'Imprimir demonstrativo de notas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button2Click
      end
      object Edit5: TEdit
        Left = 576
        Top = 152
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '500'
        Visible = False
      end
      object Edit6: TEdit
        Left = 576
        Top = 176
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '5000'
        Visible = False
      end
      object Edit7: TEdit
        Left = 576
        Top = 200
        Width = 121
        Height = 21
        TabOrder = 3
        Text = '6500'
        Visible = False
      end
      object Edit8: TEdit
        Left = 576
        Top = 224
        Width = 121
        Height = 21
        TabOrder = 4
        Text = '7000'
        Visible = False
      end
      object Edit9: TEdit
        Left = 576
        Top = 248
        Width = 121
        Height = 21
        TabOrder = 5
        Text = '7900'
        Visible = False
      end
      object Edit10: TEdit
        Left = 576
        Top = 272
        Width = 121
        Height = 21
        TabOrder = 6
        Text = '9000'
        Visible = False
      end
      object Button29: TButton
        Left = 24
        Top = 80
        Width = 265
        Height = 25
        Caption = 'Gerar ata de julgamento da prova de t'#237'tulos'
        TabOrder = 7
        OnClick = Button29Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Prova escrita'
      ImageIndex = 2
      object Label8: TLabel
        Left = 16
        Top = 128
        Width = 84
        Height = 13
        Caption = 'Nome do arquivo:'
      end
      object Label9: TLabel
        Left = 16
        Top = 8
        Width = 50
        Height = 13
        Caption = 'Nro da ata'
      end
      object Label13: TLabel
        Left = 16
        Top = 72
        Width = 115
        Height = 13
        Caption = 'Nro da lista de presen'#231'a'
      end
      object Button3: TButton
        Left = 16
        Top = 168
        Width = 129
        Height = 25
        Caption = 'Gera Ata realizacao'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 704
        Top = 160
        Width = 121
        Height = 25
        Caption = 'Gera ata leitura'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button4Click
      end
      object Edit13: TEdit
        Left = 704
        Top = 136
        Width = 121
        Height = 21
        TabOrder = 2
        Text = 'escrita_leitura.rtf'
      end
      object Button5: TButton
        Left = 16
        Top = 200
        Width = 313
        Height = 25
        Caption = 'Gera planilha de nota por candidato e por examinador'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 16
        Top = 232
        Width = 313
        Height = 25
        Caption = 'Gera crit'#233'rios de avalia'#231#227'o da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 16
        Top = 320
        Width = 257
        Height = 25
        Caption = 'Gera relacao de pontos para prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 320
        Top = 320
        Width = 289
        Height = 25
        Caption = 'Gera lista de presen'#231'a realiza'#231#227'o prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button8Click
      end
      object Edit18: TEdit
        Left = 320
        Top = 296
        Width = 225
        Height = 21
        TabOrder = 7
        Text = 'escrita_lista_realizacao.rtf'
      end
      object Button10: TButton
        Left = 16
        Top = 280
        Width = 257
        Height = 25
        Caption = 'Imprime ata de julgamento de prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 8
        OnClick = Button10Click
      end
      object Edit20: TEdit
        Left = 16
        Top = 264
        Width = 121
        Height = 21
        TabOrder = 9
        Text = 'escrita_julgamento.rtf'
      end
      object Edit11: TEdit
        Left = 16
        Top = 144
        Width = 121
        Height = 21
        TabOrder = 10
        Text = 'escrita_realizacao.rtf'
      end
      object Edit12: TEdit
        Left = 16
        Top = 24
        Width = 121
        Height = 21
        TabOrder = 11
        Text = '3'
      end
      object Edit17: TEdit
        Left = 24
        Top = 88
        Width = 121
        Height = 21
        TabOrder = 12
        Text = 'Edit17'
      end
      object Edit4: TEdit
        Left = 344
        Top = 96
        Width = 225
        Height = 21
        TabOrder = 13
        Text = 'escrita_lista_leitura.rtf'
      end
      object Button35: TButton
        Left = 344
        Top = 120
        Width = 289
        Height = 25
        Caption = 'Gera lista de presen'#231'a na leitura da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 14
        OnClick = Button35Click
      end
      object Button36: TButton
        Left = 272
        Top = 40
        Width = 465
        Height = 25
        Caption = 'Gera termo de desist'#234'ncia de prazo recursal - prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 15
        OnClick = Button36Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Prova did'#225'tica'
      ImageIndex = 3
      object Button11: TButton
        Left = 112
        Top = 80
        Width = 289
        Height = 25
        Caption = 'Gerar ata de sorteio do ponto - prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button11Click
      end
      object Edit21: TEdit
        Left = 112
        Top = 56
        Width = 121
        Height = 21
        TabOrder = 1
        Text = 'didatica_sorteio.rtf'
      end
      object Button12: TButton
        Left = 104
        Top = 160
        Width = 257
        Height = 25
        Caption = 'Gerar ata de realizacao - prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button12Click
      end
      object Edit22: TEdit
        Left = 104
        Top = 136
        Width = 121
        Height = 21
        TabOrder = 3
        Text = 'didatica_realizacao.rtf'
      end
      object Edit23: TEdit
        Left = 504
        Top = 88
        Width = 121
        Height = 21
        TabOrder = 4
        Text = 'didatica_pontos.rtf'
      end
      object Button13: TButton
        Left = 504
        Top = 112
        Width = 257
        Height = 25
        Caption = 'Gera relacao de pontos para prova didatica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 464
        Top = 200
        Width = 313
        Height = 25
        Caption = 'Gera planilha de nota por candidato e por examinador'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button14Click
      end
      object Button15: TButton
        Left = 120
        Top = 272
        Width = 305
        Height = 25
        Caption = 'Gera lista de presen'#231'a realiza'#231#227'o prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
        OnClick = Button15Click
      end
      object Edit25: TEdit
        Left = 120
        Top = 248
        Width = 225
        Height = 21
        TabOrder = 8
        Text = 'didatica_lista_realizacao.rtf'
      end
      object Button16: TButton
        Left = 120
        Top = 344
        Width = 249
        Height = 25
        Caption = 'Gera lista de presen'#231'a sorteio prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
        OnClick = Button16Click
      end
      object Edit26: TEdit
        Left = 120
        Top = 320
        Width = 225
        Height = 21
        TabOrder = 10
        Text = 'didatica_lista_sorteio.rtf'
      end
      object Button21: TButton
        Left = 472
        Top = 296
        Width = 313
        Height = 25
        Caption = 'Gera crit'#233'rios de avalia'#231#227'o da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 11
        OnClick = Button21Click
      end
      object Edit31: TEdit
        Left = 472
        Top = 272
        Width = 121
        Height = 21
        TabOrder = 12
        Text = 'didatica_criterios.rtf'
      end
      object Button37: TButton
        Left = 416
        Top = 40
        Width = 385
        Height = 25
        Caption = 'Gerar termo de desist'#234'ncia de prazo recursal da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 13
        OnClick = Button37Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Defesa de memorial acad'#234'mico'
      ImageIndex = 4
      object Button17: TButton
        Left = 48
        Top = 80
        Width = 257
        Height = 25
        Caption = 'Gerar ata de realizacao - prova defesa'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button17Click
      end
      object Edit27: TEdit
        Left = 48
        Top = 56
        Width = 145
        Height = 21
        TabOrder = 1
        Text = 'defesa_realizacao.rtf'
      end
      object Button18: TButton
        Left = 40
        Top = 160
        Width = 393
        Height = 25
        Caption = 
          'Gera lista de presen'#231'a realiza'#231#227'o prova defesa de projeto acad'#234'm' +
          'ico'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button18Click
      end
      object Edit28: TEdit
        Left = 40
        Top = 136
        Width = 225
        Height = 21
        TabOrder = 3
        Text = 'defesa_lista_realizacao.rtf'
      end
      object Button19: TButton
        Left = 40
        Top = 248
        Width = 313
        Height = 25
        Caption = 'Gera planilha de nota por candidato e por examinador'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button19Click
      end
      object Button20: TButton
        Left = 48
        Top = 344
        Width = 313
        Height = 25
        Caption = 'Gera crit'#233'rios de avalia'#231#227'o da prova defesa projeto'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button20Click
      end
      object Edit30: TEdit
        Left = 48
        Top = 320
        Width = 121
        Height = 21
        TabOrder = 6
        Text = 'defesa_criterios.rtf'
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Divulga'#231#227'o do resultado'
      ImageIndex = 5
      object Button22: TButton
        Left = 48
        Top = 80
        Width = 329
        Height = 25
        Caption = 'Gerar planilha demonstrativa por candidato - resultado'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button22Click
      end
      object Button27: TButton
        Left = 48
        Top = 152
        Width = 313
        Height = 25
        Caption = 'Gerar parecer final da banca'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button27Click
      end
      object Button30: TButton
        Left = 64
        Top = 224
        Width = 401
        Height = 25
        Caption = 'Gerar ata de divulga'#231#227'o do resultado final'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button30Click
      end
      object Button31: TButton
        Left = 464
        Top = 80
        Width = 369
        Height = 25
        Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o da nota da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button31Click
      end
      object Button32: TButton
        Left = 464
        Top = 152
        Width = 353
        Height = 25
        Caption = 'Gerar ata de divulga'#231#227'o da nota da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button32Click
      end
      object Button33: TButton
        Left = 520
        Top = 216
        Width = 313
        Height = 25
        Caption = 'Gerar listagem de notas da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button33Click
      end
      object Button34: TButton
        Left = 512
        Top = 248
        Width = 329
        Height = 25
        Caption = 'Gerar listagem de notas da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button34Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Abertura'
      ImageIndex = 6
      object Button23: TButton
        Left = 96
        Top = 112
        Width = 289
        Height = 25
        Caption = 'Ata de instala'#231#227'o da comiss'#227'o examinadora'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button23Click
      end
      object Button24: TButton
        Left = 112
        Top = 176
        Width = 553
        Height = 25
        Caption = 
          'Gerar ata de recep'#231#227'o dos candidatos e recep'#231#227'o da documenta'#231#227'o ' +
          'para prova de t'#237'tulos'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button24Click
      end
      object Button25: TButton
        Left = 112
        Top = 252
        Width = 321
        Height = 25
        Caption = 'Gerar lista de presen'#231'a na sess'#227'o de abertura'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button25Click
      end
      object Button26: TButton
        Left = 112
        Top = 212
        Width = 233
        Height = 25
        Caption = 'Gerar recibo de documenta'#231#227'o'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button26Click
      end
      object Button28: TButton
        Left = 136
        Top = 320
        Width = 177
        Height = 25
        Caption = 'Gerar cronograma'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button28Click
      end
      object Button9: TButton
        Left = 408
        Top = 56
        Width = 353
        Height = 25
        Caption = 'Declara'#231#227'o de n'#227'o impedimento da banca examinadora'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button9Click
      end
      object Button42: TButton
        Left = 384
        Top = 207
        Width = 281
        Height = 25
        Caption = 'Gerar recibo de devolu'#231#227'o de documenta'#231#227'o'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button42Click
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'Entrevista'
      ImageIndex = 7
      object Button38: TButton
        Left = 48
        Top = 80
        Width = 257
        Height = 25
        Caption = 'Gerar ata de realizacao - prova entrevista'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button38Click
      end
      object Edit14: TEdit
        Left = 48
        Top = 56
        Width = 145
        Height = 21
        TabOrder = 1
        Text = 'entrevista_realizacao.rtf'
      end
      object Button39: TButton
        Left = 40
        Top = 160
        Width = 393
        Height = 25
        Caption = 'Gera lista de presen'#231'a realiza'#231#227'o prova de entrevista'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button39Click
      end
      object Edit15: TEdit
        Left = 40
        Top = 136
        Width = 225
        Height = 21
        TabOrder = 3
        Text = 'entrevista_lista_realizacao.rtf'
      end
      object Button40: TButton
        Left = 40
        Top = 248
        Width = 313
        Height = 25
        Caption = 
          'Gera planilha de nota por candidato e por examinador - entrevist' +
          'a'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button40Click
      end
      object Button41: TButton
        Left = 48
        Top = 344
        Width = 313
        Height = 25
        Caption = 'Gera crit'#233'rios de avalia'#231#227'o da prova entrevista'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button41Click
      end
      object Edit16: TEdit
        Left = 48
        Top = 320
        Width = 121
        Height = 21
        TabOrder = 6
        Text = 'entrevista_criterios.rtf'
      end
    end
  end
end
