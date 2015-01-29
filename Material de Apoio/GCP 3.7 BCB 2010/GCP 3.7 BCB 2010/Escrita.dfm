object FormEscrita: TFormEscrita
  Left = 412
  Top = 88
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Prova Escrita'
  ClientHeight = 597
  ClientWidth = 669
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 633
    Height = 545
    ActivePage = TabSheet1
    Style = tsButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Realiza'#231#227'o'
      object Label1: TLabel
        Left = 8
        Top = 24
        Width = 91
        Height = 13
        Caption = 'Ponto sorteado:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 8
        Top = 80
        Width = 146
        Height = 13
        Caption = 'Hora do sorteio do ponto:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 8
        Top = 192
        Width = 169
        Height = 13
        Caption = 'Hora de finaliza'#231#227'o da prova:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 32
        Top = 384
        Width = 61
        Height = 13
        Caption = 'Pode apagar'
        Visible = False
      end
      object Label12: TLabel
        Left = 8
        Top = 256
        Width = 116
        Height = 13
        Caption = 'Local de realiza'#231#227'o:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label16: TLabel
        Left = 8
        Top = 144
        Width = 140
        Height = 13
        Caption = 'Hora do in'#237'cio da prova:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CSpinEdit1: TCSpinEdit
        Left = 8
        Top = 40
        Width = 57
        Height = 22
        TabOrder = 0
      end
      object DateTimePicker1: TDateTimePicker
        Left = 8
        Top = 96
        Width = 186
        Height = 21
        Date = 39570.000000000000000000
        Format = 'HH:mm'
        Time = 39570.000000000000000000
        Kind = dtkTime
        TabOrder = 1
      end
      object DateTimePicker2: TDateTimePicker
        Left = 8
        Top = 208
        Width = 186
        Height = 21
        Date = 39570.000000000000000000
        Format = 'HH:mm'
        Time = 39570.000000000000000000
        Kind = dtkTime
        TabOrder = 3
      end
      object Button2: TButton
        Left = 8
        Top = 320
        Width = 393
        Height = 25
        Hint = 
          'Determine data, hora, local e candidatos que compareceram antes ' +
          'de gerar a ata'
        Caption = 'Criar ata de realiza'#231#227'o da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = Button2Click
      end
      object DateTimePicker3: TDateTimePicker
        Left = 32
        Top = 408
        Width = 186
        Height = 21
        Date = 39615.827393472200000000
        Time = 39615.827393472200000000
        TabOrder = 6
        Visible = False
      end
      object Edit2: TEdit
        Left = 8
        Top = 272
        Width = 289
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
      end
      object DateTimePicker6: TDateTimePicker
        Left = 8
        Top = 160
        Width = 186
        Height = 21
        Date = 39570.000000000000000000
        Format = 'HH:mm'
        Time = 39570.000000000000000000
        Kind = dtkTime
        TabOrder = 2
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Leitura'
      ImageIndex = 3
      object Label7: TLabel
        Left = 8
        Top = 16
        Width = 205
        Height = 13
        Caption = 'Candidatos aptos a realizar a leitura'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label8: TLabel
        Left = 8
        Top = 32
        Width = 175
        Height = 13
        Caption = '(marque aqueles que compareceram)'
      end
      object Label9: TLabel
        Left = 48
        Top = 408
        Width = 61
        Height = 13
        Caption = 'Pode apagar'
        Visible = False
      end
      object Label10: TLabel
        Left = 232
        Top = 48
        Width = 100
        Height = 13
        Caption = 'Hor'#225'rio de in'#237'cio:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label24: TLabel
        Left = 232
        Top = 96
        Width = 116
        Height = 13
        Caption = 'Local de realiza'#231#227'o:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CheckListBox2: TCheckListBox
        Left = 8
        Top = 48
        Width = 217
        Height = 273
        Hint = 
          'A marca'#231#227'o dos candidatos que compareceram '#233' importante para a g' +
          'era'#231#227'o da ata de realiza'#231#227'o da prova escrita.'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object DateTimePicker4: TDateTimePicker
        Left = 48
        Top = 424
        Width = 186
        Height = 21
        Date = 39615.827393472200000000
        Time = 39615.827393472200000000
        TabOrder = 1
        Visible = False
      end
      object DateTimePicker5: TDateTimePicker
        Left = 232
        Top = 64
        Width = 186
        Height = 21
        Date = 39570.000000000000000000
        Format = 'HH:mm'
        Time = 39570.000000000000000000
        Kind = dtkTime
        TabOrder = 2
      end
      object Edit1: TEdit
        Left = 232
        Top = 112
        Width = 289
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
      object Button11: TButton
        Left = 16
        Top = 352
        Width = 521
        Height = 25
        Hint = 
          'Determine data, hora, local e candidatos que compareceram antes ' +
          'de gerar a ata'
        Caption = 'Criar ata da sess'#227'o de leitura da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = Button11Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Crit'#233'rios'
      ImageIndex = 2
      object Label13: TLabel
        Left = 8
        Top = 16
        Width = 224
        Height = 13
        Caption = 'Crit'#233'rios de avalia'#231#227'o da prova escrita:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 8
        Top = 344
        Width = 488
        Height = 13
        Caption = 
          'Obs.: o somat'#243'rio dos pesos dos crit'#233'rios de avalia'#231#227'o deve ser ' +
          '10. Isto n'#227'o '#233' conferido pelo programa.'
      end
      object Label27: TLabel
        Left = 8
        Top = 360
        Width = 351
        Height = 13
        Caption = 
          'Pressione a tecla "seta para baixo" do teclado para incluir uma ' +
          'nova linha.'
      end
      object ValueListEditor1: TValueListEditor
        Left = 8
        Top = 32
        Width = 585
        Height = 300
        Hint = 
          'Ap'#243's digitar o primeiro crit'#233'rio, pressione a seta para baixo pa' +
          'ra incluir uma nova linha'
        KeyOptions = [keyEdit, keyAdd, keyDelete]
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
        ParentShowHint = False
        ShowHint = True
        Strings.Strings = (
          '=')
        TabOrder = 0
        TitleCaptions.Strings = (
          'Crit'#233'rio'
          'Peso')
        ColWidths = (
          509
          70)
      end
      object Button14: TButton
        Left = 8
        Top = 392
        Width = 441
        Height = 25
        Hint = 
          'Gera planilha demonstrativa dos crit'#233'rios de avalia'#231#227'o informado' +
          's no box acima'
        Caption = 'Criar modelo da planilha de avalia'#231#227'o da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        Visible = False
        OnClick = Button14Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Julgamento'
      ImageIndex = 3
      object Label18: TLabel
        Left = 32
        Top = 360
        Width = 61
        Height = 13
        Caption = 'Pode apagar'
        Visible = False
      end
      object Label19: TLabel
        Left = 8
        Top = 24
        Width = 272
        Height = 13
        Caption = 'Hor'#225'rio do in'#237'co do julgamento da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label20: TLabel
        Left = 8
        Top = 80
        Width = 119
        Height = 13
        Caption = 'Local do julgamento:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object DateTimePicker7: TDateTimePicker
        Left = 32
        Top = 376
        Width = 186
        Height = 21
        Date = 39615.827393472200000000
        Time = 39615.827393472200000000
        TabOrder = 0
        Visible = False
      end
      object DateTimePicker8: TDateTimePicker
        Left = 8
        Top = 40
        Width = 186
        Height = 21
        Date = 39570.000000000000000000
        Format = 'HH:mm'
        Time = 39570.000000000000000000
        Kind = dtkTime
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 8
        Top = 96
        Width = 281
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
      end
      object Button16: TButton
        Left = 16
        Top = 176
        Width = 393
        Height = 25
        Hint = 
          'Gera a ata conforme as informa'#231#245'es de data, hor'#225'rio e local acim' +
          'a'
        Caption = 'Criar ata de julgamento da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = Button16Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Configura'#231#227'o'
      ImageIndex = 4
      object Label22: TLabel
        Left = 16
        Top = 16
        Width = 193
        Height = 13
        Caption = 'Candidatos inscritos no concurso:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 272
        Top = 16
        Width = 206
        Height = 13
        Caption = 'Candidatos aptos a realizar a prova:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label11: TLabel
        Left = 272
        Top = 32
        Width = 167
        Height = 13
        Caption = 'S'#227'o aptos aqueles candidatos que '
      end
      object Label25: TLabel
        Left = 272
        Top = 48
        Width = 175
        Height = 13
        Caption = 'compareceram '#224' sess'#227'o de abertura.'
      end
      object ListBox4: TListBox
        Left = 16
        Top = 72
        Width = 209
        Height = 273
        ItemHeight = 13
        TabOrder = 0
      end
      object CheckListBox1: TCheckListBox
        Left = 272
        Top = 72
        Width = 217
        Height = 273
        Hint = 
          'A marca'#231#227'o dos candidatos que compareceram '#233' importante para a g' +
          'era'#231#227'o da ata de realiza'#231#227'o da prova escrita.'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object Button6: TButton
        Left = 232
        Top = 88
        Width = 25
        Height = 25
        Caption = '-->'
        TabOrder = 2
        OnClick = Button6Click
      end
      object Button17: TButton
        Left = 232
        Top = 120
        Width = 25
        Height = 25
        Caption = '<--'
        TabOrder = 3
        OnClick = Button17Click
      end
      object Button3: TButton
        Left = 16
        Top = 368
        Width = 473
        Height = 25
        Caption = 'OK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button3Click
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Pontos'
      ImageIndex = 5
      object Label4: TLabel
        Left = 8
        Top = 336
        Width = 31
        Height = 13
        Caption = 'Ponto:'
      end
      object Label23: TLabel
        Left = 8
        Top = 16
        Width = 199
        Height = 13
        Caption = 'Lista de pontos para prova escrita:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ListBox1: TCheckListBox
        Left = 8
        Top = 32
        Width = 441
        Height = 249
        Hint = 'Insira os pontos na ordem de numera'#231#227'o'
        OnClickCheck = ListBox1ClickCheck
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object Button8: TButton
        Left = 8
        Top = 296
        Width = 81
        Height = 25
        Hint = 'Adiciona o ponto com o texto abaixo'
        Caption = 'Adicionar ponto'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 96
        Top = 296
        Width = 81
        Height = 25
        Hint = 'Remove o ponto selecionado'
        Caption = 'Remover ponto'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 184
        Top = 296
        Width = 97
        Height = 25
        Hint = 'Substitui o ponto selecionado pelo texto abaixo'
        Caption = 'Editar ponto'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = Button10Click
      end
      object Edit4: TEdit
        Left = 56
        Top = 328
        Width = 385
        Height = 21
        TabOrder = 4
        Text = 'Texto do ponto'
      end
      object Button15: TButton
        Left = 8
        Top = 384
        Width = 441
        Height = 25
        Hint = 'Demonstrativo dos pontos da prova escrita'
        Caption = 'Gerar rela'#231#227'o de pontos da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = Button15Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Planilhas'
      ImageIndex = 6
      object Label14: TLabel
        Left = 8
        Top = 8
        Width = 62
        Height = 13
        Caption = 'Candidato:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 240
        Top = 8
        Width = 70
        Height = 13
        Caption = 'Examinador:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ListBox2: TListBox
        Left = 8
        Top = 24
        Width = 225
        Height = 241
        ItemHeight = 13
        TabOrder = 0
      end
      object ListBox3: TListBox
        Left = 240
        Top = 24
        Width = 249
        Height = 145
        ItemHeight = 13
        TabOrder = 1
      end
      object Button4: TButton
        Left = 3
        Top = 287
        Width = 481
        Height = 25
        Hint = 'Selecione o candidato e o examinador nos boxes acima'
        Caption = 
          'Gerar planilha de avalia'#231#227'o para o candidato e o examinador sele' +
          'cionados acima'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = Button4Click
      end
      object StaticText1: TStaticText
        Left = 16
        Top = 383
        Width = 489
        Height = 50
        AutoSize = False
        Caption = 
          'Gere uma planilha individual para cada candidato e cada examinad' +
          'or. As planilhas devem ser preenchidas a m'#227'o pelo examinador e a' +
          'rmazenadas em envelopes lacrados para abertura somente na sess'#227'o' +
          ' de divulga'#231#227'o do resultado da prova escrita.'
        TabOrder = 3
      end
      object Button1: TButton
        Left = 3
        Top = 327
        Width = 481
        Height = 25
        Caption = 'Gerar todas as planilhas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button1Click2
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'Resultado'
      ImageIndex = 7
      object Label21: TLabel
        Left = 16
        Top = 32
        Width = 290
        Height = 13
        Caption = 'Local da divulga'#231#227'o do resultado da prova escrita:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label26: TLabel
        Left = 16
        Top = 88
        Width = 100
        Height = 13
        Caption = 'Hor'#225'rio de in'#237'cio:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Button72: TButton
        Left = 32
        Top = 168
        Width = 409
        Height = 25
        Caption = 'Criar ata da sess'#227'o de divulga'#231#227'o do resultado da prova escrita'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button72Click
      end
      object Edit5: TEdit
        Left = 16
        Top = 48
        Width = 249
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object DateTimePicker9: TDateTimePicker
        Left = 16
        Top = 104
        Width = 129
        Height = 21
        Date = 39578.000000000000000000
        Format = 'HH:mm'
        Time = 39578.000000000000000000
        Kind = dtkTime
        TabOrder = 2
      end
    end
  end
  object Button5: TButton
    Left = 496
    Top = 560
    Width = 75
    Height = 25
    Caption = 'Fechar'
    ModalResult = 1
    TabOrder = 1
    OnClick = Button5Click
  end
end
