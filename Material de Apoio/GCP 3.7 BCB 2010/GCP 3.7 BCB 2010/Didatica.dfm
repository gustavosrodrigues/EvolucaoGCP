object FormDidatica: TFormDidatica
  Left = 132
  Top = 59
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Prova did'#225'tica'
  ClientHeight = 458
  ClientWidth = 1056
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Button7: TButton
    Left = 216
    Top = 496
    Width = 217
    Height = 25
    Caption = 'Configurar candidatos aptos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Visible = False
    OnClick = Button7Click
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 1040
    Height = 409
    ActivePage = TabSheet2
    Style = tsButtons
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Candidatos'
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 0
        Width = 1033
        Height = 375
        Hint = 
          'Clique no bot'#227'o "Configurar candidatos aptos" para inserir o nom' +
          'e dos candidatos'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        object Shape1: TShape
          Left = 8
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape2: TShape
          Left = 184
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape3: TShape
          Left = 304
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape4: TShape
          Left = 680
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape5: TShape
          Left = 800
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Label2: TLabel
          Left = 8
          Top = 32
          Width = 128
          Height = 16
          Caption = 'Nome do candidato:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 208
          Top = 32
          Width = 29
          Height = 16
          Caption = 'Data'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label4: TLabel
          Left = 328
          Top = 32
          Width = 47
          Height = 16
          Caption = 'Hor'#225'rio'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 248
          Top = 16
          Width = 106
          Height = 16
          Caption = 'Sorteio do ponto'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label7: TLabel
          Left = 704
          Top = 32
          Width = 29
          Height = 16
          Caption = 'Data'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 824
          Top = 32
          Width = 47
          Height = 16
          Caption = 'Hor'#225'rio'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 744
          Top = 16
          Width = 71
          Height = 16
          Caption = 'Realiza'#231#227'o'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 416
          Top = 32
          Width = 81
          Height = 16
          Caption = 'Compareceu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Shape6: TShape
          Left = 416
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape7: TShape
          Left = 512
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Label11: TLabel
          Left = 528
          Top = 32
          Width = 100
          Height = 16
          Caption = 'Ponto sorteado:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label12: TLabel
          Left = 912
          Top = 32
          Width = 81
          Height = 16
          Caption = 'Compareceu'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Shape8: TShape
          Left = 912
          Top = 56
          Width = 49
          Height = 33
          Visible = False
        end
        object Button1: TButton
          Left = 928
          Top = 176
          Width = 75
          Height = 25
          Caption = 'Gerar'
          TabOrder = 0
          Visible = False
          OnClick = Button1Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Pontos'
      ImageIndex = 1
      object Label5: TLabel
        Left = 24
        Top = 308
        Width = 38
        Height = 13
        Caption = 'Ponto:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 24
        Top = 32
        Width = 92
        Height = 13
        Caption = 'Lista de pontos:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit4: TEdit
        Left = 64
        Top = 308
        Width = 233
        Height = 21
        TabOrder = 0
        Text = 'Texto do ponto'
      end
      object Button13: TButton
        Left = 24
        Top = 280
        Width = 89
        Height = 17
        Caption = 'Adicionar ponto'
        TabOrder = 1
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 120
        Top = 280
        Width = 89
        Height = 17
        Caption = 'Remover ponto'
        TabOrder = 2
        OnClick = Button14Click
      end
      object Button15: TButton
        Left = 224
        Top = 280
        Width = 89
        Height = 17
        Caption = 'Editar ponto'
        TabOrder = 3
        OnClick = Button15Click
      end
      object ListBox1: TCheckListBox
        Left = 24
        Top = 48
        Width = 289
        Height = 225
        Hint = 'Lista de pontos para a prova did'#225'tica, em ordem de numera'#231#227'o'
        OnClickCheck = ListBox1ClickCheck
        ItemHeight = 13
        TabOrder = 4
        OnClick = ListBox1Click
      end
      object Button2: TButton
        Left = 160
        Top = 25
        Width = 153
        Height = 17
        Caption = 'Importar da prova escrita'
        TabOrder = 5
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 16
        Top = 336
        Width = 417
        Height = 25
        Caption = 'Criar planilha de pontos para a prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button5Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Crit'#233'rios'
      ImageIndex = 2
      object Label20: TLabel
        Left = 8
        Top = 16
        Width = 227
        Height = 13
        Caption = 'Crit'#233'rios de avalia'#231#227'o da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 8
        Top = 320
        Width = 321
        Height = 13
        Caption = 
          'Obs.: o somat'#243'rio dos pesos dos crit'#233'rios de avalia'#231#227'o deve ser ' +
          '10. '
      end
      object Label22: TLabel
        Left = 40
        Top = 333
        Width = 167
        Height = 13
        Caption = 'Isto n'#227'o '#233' conferido pelo programa.'
      end
      object Label27: TLabel
        Left = 8
        Top = 360
        Width = 561
        Height = 13
        Caption = 
          'Para inserir uma nova linha, basta posicionar o cursor na '#250'ltima' +
          ' linha e pressionar o bot'#227'o "seta para baixo" do teclado.'
      end
      object ValueListEditor1: TValueListEditor
        Left = 8
        Top = 32
        Width = 409
        Height = 272
        Hint = 
          'Ap'#243's inserir o primeiro crit'#233'rio, clique na seta para baixo para' +
          ' inserir o pr'#243'ximo'
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
          326
          77)
      end
      object Button4123: TButton
        Left = 344
        Top = 320
        Width = 75
        Height = 25
        Caption = 'OK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button4123Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Ata sorteio'
      ImageIndex = 3
      object Label18: TLabel
        Left = 8
        Top = 21
        Width = 345
        Height = 13
        Caption = 'Local de realiza'#231#227'o do sorteio dos pontos da prova did'#225'tica:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 8
        Top = 37
        Width = 401
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object Button4: TButton
        Left = 8
        Top = 80
        Width = 401
        Height = 25
        Caption = 'Criar ata do sorteio dos pontos da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button3Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Planilhas'
      ImageIndex = 4
      object Label14: TLabel
        Left = 0
        Top = 13
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
        Left = 288
        Top = 13
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
        Left = 0
        Top = 33
        Width = 273
        Height = 328
        Hint = 
          'Selecione o candidato e o examinador para os quais ser'#227'o geradas' +
          ' as planilhas de avalia'#231#227'o'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object ListBox3: TListBox
        Left = 288
        Top = 33
        Width = 281
        Height = 145
        Hint = 
          'Selecione o candidato e o examinador para os quais ser'#227'o geradas' +
          ' as planilhas de avalia'#231#227'o'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object Button5: TButton
        Left = 288
        Top = 201
        Width = 449
        Height = 25
        Caption = 
          'Criar planilha de notas para o candidato e o examinador selecion' +
          'ados'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button6Click
      end
      object Button8: TButton
        Left = 288
        Top = 232
        Width = 449
        Height = 25
        Caption = 'Criar todas as planilhas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button8Click2
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Ata realiza'#231#227'o'
      ImageIndex = 5
      object Label19: TLabel
        Left = 8
        Top = 21
        Width = 219
        Height = 13
        Caption = 'Local de realiza'#231#227'o da prova did'#225'tica:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit2: TEdit
        Left = 8
        Top = 45
        Width = 305
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object Button6: TButton
        Left = 8
        Top = 96
        Width = 385
        Height = 25
        Caption = 'Criar ata da sess'#227'o de realiza'#231#227'o da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button4Click
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Ata resultado'
      ImageIndex = 6
      object Label13: TLabel
        Left = 16
        Top = 24
        Width = 191
        Height = 13
        Caption = 'Loca de divulga'#231#227'o do resultado:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label16: TLabel
        Left = 16
        Top = 80
        Width = 46
        Height = 13
        Caption = 'Hor'#225'rio:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Button8776: TButton
        Left = 16
        Top = 144
        Width = 401
        Height = 25
        Caption = 'Criar ata da sess'#227'o de divulga'#231#227'o do resultado da prova did'#225'tica'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button8776Click
      end
      object Edit3: TEdit
        Left = 16
        Top = 40
        Width = 249
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object DateTimePicker2: TDateTimePicker
        Left = 16
        Top = 96
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
  object Button4221: TButton
    Left = 488
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Fechar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button4221Click
  end
  object MainMenu1: TMainMenu
    Left = 784
    Top = 424
    object Configurao1: TMenuItem
      Caption = 'Configura'#231#227'o'
      object Configurarcandidatosaptosaestaetapadoconcurso1: TMenuItem
        Caption = 'Configurar candidatos aptos a esta etapa do concurso'
        OnClick = Button7Click
      end
    end
    object Atas1: TMenuItem
      Caption = 'Gera'#231#227'o de atas'
      object Atadesorteiodopontodaprovadidtica1: TMenuItem
        Caption = 'Ata de sorteio do ponto da prova did'#225'tica'
        OnClick = Button3Click
      end
      object Ataderealizaodaprovadidtica1: TMenuItem
        Caption = 'Ata de realiza'#231#227'o da prova did'#225'tica'
        OnClick = Button4Click
      end
    end
    object Listas1: TMenuItem
      Caption = 'Gera'#231#227'o de listas'
      object Listadepontosparaprovadidtica1: TMenuItem
        Caption = 'Lista de pontos para prova did'#225'tica'
        OnClick = Button5Click
      end
      object Listadepresenanosorteiodopontoparaprovadidtica1: TMenuItem
        Caption = 'Lista de presen'#231'a no sorteio do ponto para prova did'#225'tica'
        OnClick = Button9Click
      end
      object Listadepresenanaapresentaodaprovadidtica1: TMenuItem
        Caption = 'Lista de presen'#231'a na apresenta'#231#227'o da prova did'#225'tica'
        OnClick = Button8Click
      end
      object Listadecritriosdeavaliaodaprovadidtica1: TMenuItem
        Caption = 'Lista de crit'#233'rios de avalia'#231#227'o da prova did'#225'tica'
        OnClick = Button10Click
      end
    end
    object Geraodeplanilhas1: TMenuItem
      Caption = 'Gera'#231#227'o de planilhas'
      object Planilhadenotas1: TMenuItem
        Caption = 'Planilha de notas por candidato e por examinador'
        Hint = 
          'Gera a planilha de avalia'#231#227'o do candidato selecionado no box "Ca' +
          'ndidato" e do examinador selecionado no box "Examinador"'
        OnClick = Button6Click
      end
    end
    object Ajuda1: TMenuItem
      Caption = 'Ajuda'
      object Dicas1: TMenuItem
        Caption = 'Dicas'
        OnClick = Dicas1Click
      end
    end
  end
end
