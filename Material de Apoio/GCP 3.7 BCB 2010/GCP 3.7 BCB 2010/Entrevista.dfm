object FormEntrevista: TFormEntrevista
  Left = 187
  Top = 96
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Prova de Entrevista'
  ClientHeight = 530
  ClientWidth = 638
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
  object Button1: TButton
    Left = 848
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Gerar'
    TabOrder = 0
    Visible = False
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 680
    Top = 136
    Width = 241
    Height = 25
    Caption = 'Configurar candidatos aptos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 272
    Top = 496
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
    OnClick = Button5Click
  end
  object Button7: TButton
    Left = 872
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Dicas'
    TabOrder = 3
    OnClick = Button7Click
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 16
    Width = 609
    Height = 465
    ActivePage = TabSheet1
    Style = tsButtons
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = 'Planilhas'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label14: TLabel
        Left = 8
        Top = 8
        Width = 230
        Height = 13
        Caption = 'Candidatos aptos '#224' realiza'#231#227'o da prova:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 248
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
        Top = 23
        Width = 233
        Height = 306
        Hint = 
          'Selecione o candidato e o examinador para a gera'#231#227'o da planilha ' +
          'de avalia'#231#227'o'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object ListBox3: TListBox
        Left = 248
        Top = 24
        Width = 249
        Height = 145
        Hint = 
          'Selecione o candidato e o examinador para a gera'#231#227'o da planilha ' +
          'de avalia'#231#227'o'
        ItemHeight = 13
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object Button6: TButton
        Left = 88
        Top = 352
        Width = 417
        Height = 25
        Caption = 
          'Gerar planilha de avalia'#231#227'o do candidato e examinador selecionad' +
          'os'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = Button6Click
      end
      object Button2: TButton
        Left = 88
        Top = 383
        Width = 417
        Height = 25
        Caption = 'Gerar todas as planilhas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button2Click2
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Realiza'#231#227'o'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label2: TLabel
        Left = 8
        Top = 16
        Width = 242
        Height = 13
        Caption = 'Informe a data e o hor'#225'rio das entrevistas:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ScrollBox1: TScrollBox
        Left = 7
        Top = 32
        Width = 570
        Height = 385
        Hint = 
          'Clique no bot'#227'o "Configurar candidatos aptos" para inserir o nom' +
          'e dos candidatos'
        TabOrder = 0
        object Label3: TLabel
          Left = 16
          Top = 8
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
        object Shape1: TShape
          Left = 16
          Top = 32
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape2: TShape
          Left = 192
          Top = 32
          Width = 49
          Height = 33
          Visible = False
        end
        object Label4: TLabel
          Left = 216
          Top = 8
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
        object Label5: TLabel
          Left = 336
          Top = 8
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
        object Shape3: TShape
          Left = 312
          Top = 32
          Width = 49
          Height = 33
          Visible = False
        end
        object Shape4: TShape
          Left = 424
          Top = 32
          Width = 49
          Height = 33
          Visible = False
        end
        object Label10: TLabel
          Left = 424
          Top = 8
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
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Crit'#233'rios'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label17: TLabel
        Left = 8
        Top = 352
        Width = 488
        Height = 13
        Caption = 
          'Obs.: o somat'#243'rio dos pesos dos crit'#233'rios de avalia'#231#227'o deve ser ' +
          '10. Isto n'#227'o '#233' conferido pelo programa.'
      end
      object Label16: TLabel
        Left = 8
        Top = 8
        Width = 260
        Height = 13
        Caption = 'Crit'#233'rios de avalia'#231#227'o da prova de entrevista:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ValueListEditor1: TValueListEditor
        Left = 8
        Top = 24
        Width = 577
        Height = 321
        Hint = 
          'Ap'#243's a digita'#231#227'o de um crit'#233'rio, pressione a seta para baixo par' +
          'a inserir outro crit'#233'rio'
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
          487
          84)
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Ata'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label1: TLabel
        Left = 18
        Top = 32
        Width = 254
        Height = 13
        Caption = 'Local de realiza'#231#227'o da provas de entrevista:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 16
        Top = 56
        Width = 377
        Height = 21
        Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object Button4: TButton
        Left = 16
        Top = 120
        Width = 505
        Height = 25
        Caption = 'Criar ata de realiza'#231#227'o da prova de entrevista'
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
  end
end
