object FormAbertura: TFormAbertura
  Left = 491
  Top = 41
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Abertura do concurso e recep'#231#227'o de comprovantes do curr'#237'culo'
  ClientHeight = 620
  ClientWidth = 528
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button2: TButton
    Left = 280
    Top = 616
    Width = 177
    Height = 25
    Caption = 'Gerar recibo de documenta'#231#227'o'
    TabOrder = 0
    Visible = False
  end
  object Button5: TButton
    Left = 80
    Top = 616
    Width = 145
    Height = 25
    Caption = 'Gerar cronograma - ok'
    TabOrder = 1
    Visible = False
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 440
    Top = 576
    Width = 75
    Height = 25
    Caption = 'Fechar'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button6Click
  end
  object PageControl1: TPageControl
    Left = 16
    Top = 8
    Width = 497
    Height = 553
    ActivePage = TabSheet4
    Style = tsButtons
    TabOrder = 3
    TabStop = False
    object TabSheet1: TTabSheet
      Caption = 'Instala'#231#227'o'
      object Label2: TLabel
        Left = 296
        Top = 424
        Width = 186
        Height = 13
        Caption = 'Pode apagar depois que tirar do c'#243'digo'
        Visible = False
      end
      object Label3: TLabel
        Left = 0
        Top = 8
        Width = 376
        Height = 13
        Caption = 'Hora de in'#237'cio da sess'#227'o de instala'#231#227'o da comiss'#227'o examinadora:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 0
        Top = 64
        Width = 322
        Height = 13
        Caption = 'Local da sess'#227'o de instala'#231#227'o da comiss'#227'o examinadora'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 0
        Top = 128
        Width = 186
        Height = 13
        Caption = 'Portaria de nomea'#231#227'o da banca:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 0
        Top = 192
        Width = 250
        Height = 13
        Caption = 'Emissor da portaria de nomea'#231#227'o da banca:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 0
        Top = 208
        Width = 420
        Height = 13
        Caption = 
          'Exemplo: "Reitora da Universidade Federal do Pampa" (esta inform' +
          'a'#231#227'o constar'#225' na ata)'
      end
      object Label11: TLabel
        Left = 0
        Top = 144
        Width = 254
        Height = 13
        Caption = 'Exemplo: 005/2008 (esta informa'#231#227'o constar'#225' na ata)'
      end
      object Label12: TLabel
        Left = 0
        Top = 80
        Width = 228
        Height = 13
        Caption = 'Exemplo: sala cento e doze do Campus Alegrete'
      end
      object DateTimePicker1: TDateTimePicker
        Left = 296
        Top = 440
        Width = 186
        Height = 21
        Date = 39814.583347615700000000
        Time = 39814.583347615700000000
        TabOrder = 0
        Visible = False
      end
      object DateTimePicker2: TDateTimePicker
        Left = 0
        Top = 24
        Width = 186
        Height = 21
        Date = 39581.000000000000000000
        Format = 'HH:mm'
        Time = 39581.000000000000000000
        Kind = dtkTime
        TabOrder = 1
      end
      object Edit1: TEdit
        Left = 0
        Top = 96
        Width = 273
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Campus Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
      end
      object Edit2: TEdit
        Left = 0
        Top = 160
        Width = 121
        Height = 21
        Hint = 'Exemplo: 005/2008 (esta informa'#231#227'o constar'#225' na ata)'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
      object Edit3: TEdit
        Left = 0
        Top = 224
        Width = 281
        Height = 21
        Hint = 
          'Exemplo: "Reitoria da Universidade Federal do Pampa" (esta infor' +
          'ma'#231#227'o constar'#225' na ata)'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
      end
      object Button111: TButton
        Left = 0
        Top = 280
        Width = 481
        Height = 25
        Caption = 'Criar ata de instala'#231#227'o da comiss'#227'o examinadora'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button111Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Cronograma'
      ImageIndex = 1
      object Label7: TLabel
        Left = 8
        Top = 16
        Width = 146
        Height = 13
        Caption = 'Cronograma do concurso:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label8: TLabel
        Left = 8
        Top = 480
        Width = 186
        Height = 13
        Caption = 'Pode apagar depois que tirar do c'#243'digo'
        Visible = False
      end
      object StringGrid1: TStringGrid
        Left = 8
        Top = 32
        Width = 457
        Height = 441
        Hint = 'Descreva aqui o cronograma do concurso'
        ColCount = 4
        FixedCols = 0
        RowCount = 50
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goTabs]
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        ColWidths = (
          166
          70
          64
          117)
      end
      object DateTimePicker3: TDateTimePicker
        Left = 8
        Top = 496
        Width = 186
        Height = 21
        Date = 39615.583347615700000000
        Time = 39615.583347615700000000
        TabOrder = 1
        Visible = False
      end
      object Button10: TButton
        Left = 248
        Top = 496
        Width = 129
        Height = 25
        Caption = 'Criar cronograma'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button10Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Abertura'
      ImageIndex = 2
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 393
        Height = 13
        Caption = 
          'Marque os candidatos presentes na sess'#227'o de abertura do concurso' +
          ':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 16
        Top = 384
        Width = 290
        Height = 13
        Caption = 'Hora de in'#237'cio da sess'#227'o de abertura do concurso:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CheckListBox1: TCheckListBox
        Left = 8
        Top = 24
        Width = 417
        Height = 337
        Hint = 
          'Marque os candidatos que compareceram '#224' sess'#227'o de abertura do co' +
          'ncurso. Isto '#233' importante para a gera'#231#227'o das atas.'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object Button13: TButton
        Left = 8
        Top = 448
        Width = 465
        Height = 25
        Caption = 'Criar ata da sess'#227'o de abertura do concurso'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button13Click
      end
      object DateTimePicker4: TDateTimePicker
        Left = 16
        Top = 400
        Width = 97
        Height = 21
        Date = 39581.000000000000000000
        Format = 'HH:mm'
        Time = 39581.000000000000000000
        Kind = dtkTime
        TabOrder = 2
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Pesos'
      ImageIndex = 3
      object Shape5: TShape
        Left = 32
        Top = 199
        Width = 128
        Height = 33
        Brush.Color = clMoneyGreen
        Pen.Style = psClear
      end
      object Shape4: TShape
        Left = 32
        Top = 166
        Width = 128
        Height = 33
        Brush.Color = clCream
        Pen.Style = psClear
      end
      object Shape3: TShape
        Left = 32
        Top = 133
        Width = 128
        Height = 33
        Brush.Color = clMoneyGreen
        Pen.Style = psClear
      end
      object Shape2: TShape
        Left = 32
        Top = 99
        Width = 128
        Height = 33
        Brush.Color = clCream
        Pen.Style = psClear
      end
      object Shape1: TShape
        Left = 32
        Top = 67
        Width = 128
        Height = 33
        Brush.Color = clMoneyGreen
        Pen.Style = psClear
      end
      object Label13: TLabel
        Left = 32
        Top = 48
        Width = 185
        Height = 13
        Caption = 'Peso das provas (valores entre 0 e 10):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 53
        Top = 80
        Width = 35
        Height = 13
        Caption = 'Escrita:'
        Color = clMoneyGreen
        ParentColor = False
      end
      object Label15: TLabel
        Left = 52
        Top = 176
        Width = 36
        Height = 13
        Caption = 'T'#237'tulos:'
        Color = clCream
        ParentColor = False
      end
      object Label16: TLabel
        Left = 46
        Top = 109
        Width = 42
        Height = 13
        Caption = 'Did'#225'tica:'
        Color = clCream
        ParentColor = False
      end
      object Label17: TLabel
        Left = 38
        Top = 208
        Width = 50
        Height = 13
        Caption = 'Entrevista:'
        Color = clMoneyGreen
        ParentColor = False
      end
      object Label18: TLabel
        Left = 43
        Top = 147
        Width = 45
        Height = 13
        Caption = 'Memorial:'
        Color = clMoneyGreen
        ParentColor = False
      end
      object Label19: TLabel
        Left = 32
        Top = 240
        Width = 229
        Height = 13
        Caption = 'Obs.: o somat'#243'rio dos pesos deve ser igual a 10.'
      end
      object Label20: TLabel
        Left = 3
        Top = 16
        Width = 474
        Height = 13
        Caption = 
          'Determine os pesos das provas, de acordo com o estipulado no edi' +
          'tal do concurso.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit10: TEdit
        Left = 94
        Top = 75
        Width = 49
        Height = 21
        TabOrder = 0
      end
      object Edit12: TEdit
        Left = 94
        Top = 205
        Width = 49
        Height = 21
        TabOrder = 4
      end
      object Edit11: TEdit
        Left = 94
        Top = 106
        Width = 49
        Height = 21
        TabOrder = 1
      end
      object Edit13: TEdit
        Left = 94
        Top = 172
        Width = 49
        Height = 21
        TabOrder = 3
      end
      object Edit14: TEdit
        Left = 94
        Top = 139
        Width = 49
        Height = 21
        TabOrder = 2
      end
      object Button1: TButton
        Left = 182
        Top = 209
        Width = 124
        Height = 25
        Caption = 'Atribuir os pesos'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button1Click2
      end
    end
  end
end