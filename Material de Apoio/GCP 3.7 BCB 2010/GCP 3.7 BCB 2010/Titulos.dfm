object FormTitulos: TFormTitulos
  Left = 274
  Top = 0
  Width = 940
  Height = 740
  AutoScroll = True
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Prova de t'#237'tulos'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  OnCreate = FormCreate
  DesignSize = (
    932
    706)
  PixelsPerInch = 96
  TextHeight = 16
  object Label6: TLabel
    Left = 16
    Top = 24
    Width = 69
    Height = 16
    Caption = 'Candidato:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 8
    Top = 56
    Width = 81
    Height = 16
    Caption = 'Examinador:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label57: TLabel
    Left = 928
    Top = 248
    Width = 80
    Height = 16
    Caption = 'Pode apagar'
    Visible = False
  end
  object Label40: TLabel
    Left = 8
    Top = 78
    Width = 195
    Height = 16
    Caption = 'Pontua'#231#227'o de acordo com a ...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clTeal
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 829
    Top = 54
    Width = 76
    Height = 27
    Caption = 'Calcular'
    TabOrder = 0
    Visible = False
    OnClick = Button1Click
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 103
    Width = 932
    Height = 603
    VertScrollBar.ButtonSize = 1
    VertScrollBar.Smooth = True
    VertScrollBar.Tracking = True
    Anchors = [akLeft, akTop, akBottom]
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 911
      Height = 2000
      ActivePage = TabSheet1
      Align = alBottom
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = PageControl1Change
      object TabSheet1: TTabSheet
        Caption = 'I.1. Forma'#231#227'o acad'#234'mica'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label5: TLabel
          Left = 696
          Top = 16
          Width = 56
          Height = 16
          Caption = 'Sub-total:'
        end
        object Edit22: TEdit
          Left = 776
          Top = 8
          Width = 65
          Height = 24
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = '0'
        end
        object TabelaClasse1: TStringGrid
          Left = 16
          Top = 96
          Width = 839
          Height = 347
          DefaultRowHeight = 65
          FixedCols = 0
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs]
          TabOrder = 1
          OnDrawCell = TabelaClasse1DrawCell
          OnSelectCell = TabelaClasse1SelectCell
          OnSetEditText = TabelaClasse1SetEditText
          ColWidths = (
            44
            550
            73
            78
            72)
        end
        object StaticText2: TStaticText
          Left = 18
          Top = 399
          Width = 70
          Height = 20
          Caption = 'StaticText2'
          TabOrder = 2
        end
        object StaticText5: TStaticText
          Left = 16
          Top = 14
          Width = 657
          Height = 76
          AutoSize = False
          Caption = 'Titulo Classe 1'
          Constraints.MaxWidth = 657
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object StaticText7: TStaticText
          Left = 16
          Top = 70
          Width = 70
          Height = 20
          Caption = 'StaticText7'
          TabOrder = 4
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'I.2. Produ'#231#227'o cient'#237'fica'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label12: TLabel
          Left = 696
          Top = 16
          Width = 56
          Height = 16
          Caption = 'Sub-total:'
        end
        object Label95: TLabel
          Left = 40
          Top = 1600
          Width = 3
          Height = 16
        end
        object Edit47: TEdit
          Left = 776
          Top = 8
          Width = 65
          Height = 24
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = '0'
        end
        object StaticText9: TStaticText
          Left = 16
          Top = 1639
          Width = 817
          Height = 33
          AutoSize = False
          Caption = 
            'Neste caso, indique as quantidades de maneira proporcional. Ex: ' +
            'se o candidato possui 2 artigos na '#225'rea e 1 em '#225'rea afim, indiqu' +
            'e "2,5" no campo "quantidade" do item.'
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 1
        end
        object TabelaClasse2: TStringGrid
          Left = 16
          Top = 96
          Width = 839
          Height = 1845
          DefaultRowHeight = 65
          FixedCols = 0
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs]
          TabOrder = 2
          OnDrawCell = TabelaClasse1DrawCell
          OnSelectCell = TabelaClasse1SelectCell
          OnSetEditText = TabelaClasse1SetEditText
          ColWidths = (
            44
            550
            73
            78
            72)
        end
        object StaticText3: TStaticText
          Left = 16
          Top = 14
          Width = 657
          Height = 76
          AutoSize = False
          Caption = 'Titulo Classe 2'
          Constraints.MaxWidth = 657
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object StaticText10: TStaticText
          Left = 16
          Top = 70
          Width = 77
          Height = 20
          Caption = 'StaticText10'
          TabOrder = 4
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'I.3. Atividades de pesquisa, ensino e extens'#227'o'
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label17: TLabel
          Left = 696
          Top = 16
          Width = 56
          Height = 16
          Caption = 'Sub-total:'
        end
        object Edit144: TEdit
          Left = 776
          Top = 8
          Width = 65
          Height = 24
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Text = '0'
        end
        object StaticText8: TStaticText
          Left = 16
          Top = 1767
          Width = 817
          Height = 33
          AutoSize = False
          Caption = 
            'Neste caso, indique as quantidades de maneira proporcional. Ex: ' +
            'se o candidato possui duas orienta'#231#245'es como orientador principal' +
            ' e uma como co-orientador, indique "2,5" no campo "quantidade" d' +
            'o item.'
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 1
        end
        object TabelaClasse3: TStringGrid
          Left = 16
          Top = 96
          Width = 839
          Height = 1845
          DefaultRowHeight = 65
          FixedCols = 0
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs]
          TabOrder = 2
          OnDrawCell = TabelaClasse1DrawCell
          OnSelectCell = TabelaClasse1SelectCell
          OnSetEditText = TabelaClasse1SetEditText
          ColWidths = (
            44
            550
            73
            78
            72)
        end
        object StaticText6: TStaticText
          Left = 16
          Top = 14
          Width = 657
          Height = 76
          AutoSize = False
          Caption = 'Titulo Classe 2'
          Constraints.MaxWidth = 657
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object StaticText11: TStaticText
          Left = 16
          Top = 70
          Width = 77
          Height = 20
          Caption = 'StaticText11'
          TabOrder = 4
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'Resumo'
        ImageIndex = 3
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Shape15: TShape
          Left = 24
          Top = 16
          Width = 545
          Height = 265
          Brush.Color = clMoneyGreen
          Shape = stRoundRect
        end
        object Label52: TLabel
          Left = 31
          Top = 112
          Width = 115
          Height = 16
          Caption = 'Sub-total classe I.1:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label53: TLabel
          Left = 31
          Top = 144
          Width = 115
          Height = 16
          Caption = 'Sub-total classe I.2:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label54: TLabel
          Left = 31
          Top = 176
          Width = 115
          Height = 16
          Caption = 'Sub-total classe I.3:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label55: TLabel
          Left = 280
          Top = 224
          Width = 93
          Height = 16
          Caption = 'NOTA FINAL:'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object Label62: TLabel
          Left = 368
          Top = 90
          Width = 163
          Height = 16
          Caption = 'Nota ponderada na classe:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label63: TLabel
          Left = 112
          Top = 90
          Width = 129
          Height = 16
          Caption = 'Pontua'#231#227'o na classe:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label64: TLabel
          Left = 263
          Top = 90
          Width = 93
          Height = 16
          Caption = 'Nota na classe:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label65: TLabel
          Left = 128
          Top = 48
          Width = 156
          Height = 20
          Caption = 'Nome do candidato'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object Label69: TLabel
          Left = 48
          Top = 48
          Width = 65
          Height = 16
          Caption = 'Candidato:'
          Color = clMoneyGreen
          ParentColor = False
        end
        object Label70: TLabel
          Left = 136
          Top = 312
          Width = 247
          Height = 16
          Caption = 'Resumo das pontua'#231#245'es dos candidatos'
        end
        object Edit93: TEdit
          Left = 152
          Top = 112
          Width = 57
          Height = 24
          TabOrder = 0
          Text = '0,00'
        end
        object Edit94: TEdit
          Left = 152
          Top = 144
          Width = 57
          Height = 24
          TabOrder = 1
          Text = '0,00'
        end
        object Edit95: TEdit
          Left = 152
          Top = 176
          Width = 57
          Height = 24
          TabOrder = 2
          Text = '0,00'
        end
        object Edit96: TEdit
          Left = 392
          Top = 216
          Width = 57
          Height = 24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          Text = '0,00'
        end
        object Edit5: TEdit
          Left = 392
          Top = 112
          Width = 57
          Height = 24
          TabOrder = 4
          Text = '0,00'
        end
        object Edit6: TEdit
          Left = 392
          Top = 144
          Width = 57
          Height = 24
          TabOrder = 5
          Text = '0,00'
        end
        object Edit7: TEdit
          Left = 392
          Top = 176
          Width = 57
          Height = 24
          TabOrder = 6
          Text = '0,00'
        end
        object Memo1: TMemo
          Left = 608
          Top = 21
          Width = 249
          Height = 948
          Lines.Strings = (
            'COMO A NOTA DA PROVA DE '
            'T'#205'TULOS '#201' CALCULADA:'
            ''
            ''
            'Cada candidato possui uma '
            'pontua'#231#227'o relativa '#224' sua titula'#231#227'o nas '
            'classes I.1, I.2 e I.3, dadas por P1, P2 '
            'e P3, respectivamente.'
            ''
            'De todos os candidatos, a maior '
            'pontua'#231#227'o em cada classe '#233' '
            'calculada '
            '(P1max, P2max, P3max).'
            ''
            'O avaliador atribui notas de '
            'refer'#234'ncia a cada classe: NR1, NR2, '
            'NR3'
            ''
            'Essas notas de refer'#234'ncia ser'#227'o as '
            'notas das pontua'#231#245'es m'#225'ximas. As '
            'demais notas ser'#227'o calculadas '
            'proporcionalmente.'
            ''
            'Exemplo:'
            ''
            'Dados 2 candidatos com as '
            'seguintes pontua'#231#245'es:'
            ''
            '                  P1         P2       P3'
            'Cand. 1      3,0        15,0    12,0'
            'Cand. 2      6,0        12,0    16,0'
            ''
            'Se os avaliadores atribuirem as '
            'seguintes notas de refer'#234'ncia:'
            'NR1 = 10,0'
            'NR2 =   9,0'
            'NR3 =   8,0'
            ''
            'Ent'#227'o os candidatos ter'#227'o as '
            'seguintes notas nas classes:'
            ''
            '                    N1           N2     N3'
            'Cand. 1        5,0          9,0     6,0'
            'Cand. 2      10,0          7,2     8,0'
            ''
            'Ap'#243's, a nota final de cada candidato '
            #233' calculada de acordo com os pesos '
            'atribu'#237'dos para cada classe:'
            ''
            'NOTA_FINAL = N1*PESO1 + '
            'N2*PESO2 + '
            'N3*PESO3'
            ''
            'Caso a banca deseje calcular a nota '
            'final utilizando crit'#233'rios diferentes, '
            'basta editar os valores na planilha '
            'gerada.')
          ScrollBars = ssVertical
          TabOrder = 7
        end
        object Edit11: TEdit
          Left = 280
          Top = 112
          Width = 57
          Height = 24
          TabOrder = 8
          Text = '0,00'
        end
        object Edit12: TEdit
          Left = 280
          Top = 144
          Width = 57
          Height = 24
          TabOrder = 9
          Text = '0,00'
        end
        object Edit13: TEdit
          Left = 280
          Top = 176
          Width = 57
          Height = 24
          TabOrder = 10
          Text = '0,00'
        end
        object StringGrid1: TStringGrid
          Left = 24
          Top = 328
          Width = 569
          Height = 641
          ColCount = 4
          FixedCols = 0
          ScrollBars = ssVertical
          TabOrder = 11
          OnDrawCell = StringGrid1DrawCell
          ColWidths = (
            367
            51
            47
            41)
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Ata'
        ImageIndex = 4
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label56: TLabel
          Left = 40
          Top = 56
          Width = 145
          Height = 16
          Caption = 'Local de julgamento:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label58: TLabel
          Left = 128
          Top = 96
          Width = 57
          Height = 16
          Caption = 'Hor'#225'rio:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label74: TLabel
          Left = 40
          Top = 24
          Width = 259
          Height = 16
          Caption = 'Ata de julgamento da prova de t'#237'tulos'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold, fsUnderline]
          ParentFont = False
        end
        object Label96: TLabel
          Left = 40
          Top = 218
          Width = 203
          Height = 16
          Caption = 'Tabela regras m'#225'xima pontua'#231#227'o'
          Visible = False
        end
        object Label97: TLabel
          Left = 294
          Top = 218
          Width = 217
          Height = 16
          Caption = 'Tabela regras itens n'#227'o cumulativos'
          Visible = False
        end
        object Edit1: TEdit
          Left = 200
          Top = 56
          Width = 297
          Height = 24
          Hint = 'Exemplo: sala centro e doze do Centro de Tecnologia de Alegrete'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object DateTimePicker2: TDateTimePicker
          Left = 200
          Top = 96
          Width = 97
          Height = 24
          Date = 39615.000000000000000000
          Format = 'HH:mm'
          Time = 39615.000000000000000000
          Kind = dtkTime
          TabOrder = 1
        end
        object Button2: TButton
          Left = 64
          Top = 152
          Width = 361
          Height = 25
          Caption = 'Criar ata de julgamento da prova de t'#237'tulos'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Button2Click
        end
        object TabelaRegrasMaxPont: TStringGrid
          Left = 40
          Top = 240
          Width = 219
          Height = 297
          ColCount = 2
          DefaultColWidth = 100
          FixedCols = 0
          FixedRows = 0
          TabOrder = 3
          Visible = False
        end
        object TabelaRegrasCumulativo: TStringGrid
          Left = 296
          Top = 240
          Width = 219
          Height = 297
          ColCount = 2
          DefaultColWidth = 100
          FixedCols = 0
          FixedRows = 0
          TabOrder = 4
          Visible = False
        end
      end
    end
  end
  object ComboBox1: TComboBox
    Left = 96
    Top = 16
    Width = 249
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Text = 'Selecione...'
    OnChange = ComboBox1Change
  end
  object Button4: TButton
    Left = 832
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Fechar'
    ModalResult = 1
    TabOrder = 3
    OnClick = Button4Click
  end
  object ComboBox2: TComboBox
    Left = 96
    Top = 48
    Width = 249
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    Text = 'Selecione...'
    Visible = False
    OnChange = ComboBox1Change
  end
  object DateTimePicker1: TDateTimePicker
    Left = 928
    Top = 272
    Width = 97
    Height = 24
    Date = 39615.613742106500000000
    Time = 39615.613742106500000000
    TabOrder = 5
    Visible = False
  end
  object GroupBox1: TGroupBox
    Left = 520
    Top = 8
    Width = 129
    Height = 89
    Caption = 'Pesos das classes:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    object Label59: TLabel
      Left = 5
      Top = 24
      Width = 49
      Height = 13
      Caption = 'Classe I.1:'
    end
    object Label60: TLabel
      Left = 5
      Top = 48
      Width = 49
      Height = 13
      Caption = 'Classe I.2:'
    end
    object Label61: TLabel
      Left = 5
      Top = 72
      Width = 49
      Height = 13
      Caption = 'Classe I.3:'
    end
    object Edit2: TEdit
      Tag = 100
      Left = 64
      Top = 16
      Width = 57
      Height = 21
      TabOrder = 0
      Text = '0,0'
      OnExit = Edit2Exit
    end
    object Edit3: TEdit
      Tag = 101
      Left = 64
      Top = 41
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '0,0'
      OnExit = Edit2Exit
    end
    object Edit4: TEdit
      Tag = 102
      Left = 64
      Top = 65
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '0,0'
      OnExit = Edit2Exit
    end
  end
  object GroupBox2: TGroupBox
    Left = 664
    Top = 8
    Width = 145
    Height = 89
    Hint = 
      #201' a nota que ser'#225' atribu'#237'da ao candidato com maior pontua'#231#227'o na ' +
      'classe.'
    Caption = 'Nota de refer'#234'ncia'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    object Label66: TLabel
      Left = 5
      Top = 24
      Width = 49
      Height = 13
      Caption = 'Classe I.1:'
    end
    object Label67: TLabel
      Left = 5
      Top = 48
      Width = 49
      Height = 13
      Caption = 'Classe I.2:'
    end
    object Label68: TLabel
      Left = 5
      Top = 72
      Width = 49
      Height = 13
      Caption = 'Classe I.3:'
    end
    object Edit8: TEdit
      Tag = 200
      Left = 56
      Top = 17
      Width = 57
      Height = 21
      TabOrder = 0
      Text = '10,0'
      OnExit = Edit2Exit
    end
    object Edit9: TEdit
      Tag = 200
      Left = 56
      Top = 41
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '10,0'
      OnExit = Edit2Exit
    end
    object Edit10: TEdit
      Tag = 200
      Left = 56
      Top = 65
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '10,0'
      OnExit = Edit2Exit
    end
  end
  object GroupBox3: TGroupBox
    Left = 928
    Top = 145
    Width = 145
    Height = 97
    Caption = 'Pontua'#231#227'o de refer'#234'ncia'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Visible = False
    object Label71: TLabel
      Left = 5
      Top = 24
      Width = 38
      Height = 13
      Caption = 'Item I.1:'
    end
    object Label72: TLabel
      Left = 5
      Top = 48
      Width = 38
      Height = 13
      Caption = 'Item I.2:'
    end
    object Label73: TLabel
      Left = 5
      Top = 72
      Width = 38
      Height = 13
      Caption = 'Item I.3:'
    end
    object Edit14: TEdit
      Left = 56
      Top = 17
      Width = 57
      Height = 21
      TabOrder = 0
      Text = '10,0'
      OnExit = Edit2Exit
    end
    object Edit15: TEdit
      Left = 56
      Top = 41
      Width = 57
      Height = 21
      TabOrder = 1
      Text = '10,0'
      OnExit = Edit2Exit
    end
    object Edit16: TEdit
      Left = 56
      Top = 65
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '10,0'
      OnExit = Edit2Exit
    end
    object StaticText4: TStaticText
      Left = -512
      Top = 14
      Width = 657
      Height = 76
      AutoSize = False
      Caption = 'Titulo Classe 2'
      Constraints.MaxWidth = 657
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
    end
  end
  object StaticText1: TStaticText
    Left = 352
    Top = 8
    Width = 145
    Height = 57
    AutoSize = False
    Caption = 
      'Selecione o candidato ao lado e clique no bot'#227'o abaixo para impr' +
      'imir a planilha.'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 10
  end
  object Button3: TButton
    Left = 408
    Top = 51
    Width = 97
    Height = 25
    Caption = 'Gerar planilha'
    TabOrder = 9
    OnClick = Button3Click
  end
end
