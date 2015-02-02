object FormResultado: TFormResultado
  Left = 27
  Top = 92
  Width = 1192
  Height = 755
  AutoScroll = True
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Divulga'#231#227'o do resultado'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 184
    Top = 8
    Width = 668
    Height = 24
    Caption = 'SESS'#195'O P'#218'BLICA DE DIVULGA'#199#195'O DO RESULTADO DO CONCURSO'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 872
    Top = 24
    Width = 61
    Height = 13
    Caption = 'Pode apagar'
    Visible = False
  end
  object Label5: TLabel
    Left = 280
    Top = 48
    Width = 37
    Height = 13
    Caption = 'Hor'#225'rio:'
  end
  object Label6: TLabel
    Left = 16
    Top = 48
    Width = 29
    Height = 13
    Caption = 'Local:'
  end
  object Label2: TLabel
    Left = 1032
    Top = 104
    Width = 56
    Height = 13
    Caption = 'Candidatos:'
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 104
    Width = 1017
    Height = 569
    ActivePage = TabSheet1
    TabOrder = 0
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = 'Resumo'
      DesignSize = (
        1009
        541)
      object ScrollBox1: TScrollBox
        Left = 40
        Top = 16
        Width = 609
        Height = 513
        Anchors = []
        TabOrder = 0
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 600
          Height = 509
          Align = alLeft
          ColCount = 3
          FixedCols = 0
          RowCount = 1
          FixedRows = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnExit = StringGrid1Exit
          OnGetEditText = StringGrid1GetEditText
          OnSelectCell = StringGrid1SelectCell
          ColWidths = (
            340
            135
            85)
        end
      end
    end
  end
  object Button1: TButton
    Left = 744
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Gerar'
    TabOrder = 1
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 824
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Calcular'
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object DateTimePicker1: TDateTimePicker
    Left = 872
    Top = 40
    Width = 129
    Height = 21
    Date = 39615.856077835600000000
    Time = 39615.856077835600000000
    TabOrder = 3
    Visible = False
  end
  object DateTimePicker2: TDateTimePicker
    Left = 280
    Top = 64
    Width = 129
    Height = 21
    Date = 39578.000000000000000000
    Format = 'HH:mm'
    Time = 39578.000000000000000000
    Kind = dtkTime
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 16
    Top = 64
    Width = 249
    Height = 21
    Hint = 'Exemplo: sala cento e doze do Centro de Tecnologia de Alegrete'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
  end
  object Button6: TButton
    Left = 936
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Fechar'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button3: TButton
    Left = 936
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Ajuda'
    TabOrder = 7
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    Left = 1032
    Top = 128
    Width = 145
    Height = 545
    ItemHeight = 13
    TabOrder = 8
    OnClick = ListBox1Click
  end
  object MainMenu1: TMainMenu
    Left = 848
    Top = 40
    object Ats1: TMenuItem
      Caption = 'Atas'
      object Geraratadasessodedivulgaodoresultadodaprovaescrita1: TMenuItem
        Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o do resultado da prova escrita'
        OnClick = Button7Click
      end
      object Geraratadasessodedivulgaodoresultadodaprovadidtica1: TMenuItem
        Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o do resultado da prova did'#225'tica'
        OnClick = Button8Click
      end
      object Geraratadasessodedivulgaodoresultadofinaldoconcurso1: TMenuItem
        Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o do resultado final do concurso'
        OnClick = Button4Click
      end
    end
    object Planilhas1: TMenuItem
      Caption = 'Planilhas'
      object Gerarlistagemdenotasdaprovaescrita1: TMenuItem
        Caption = 'Gerar listagem de notas da prova escrita'
        OnClick = Button9Click
      end
      object Gerarlistagemdenotasdaprovadidtica1: TMenuItem
        Caption = 'Gerar listagem de notas da prova did'#225'tica'
        OnClick = Button10Click
      end
      object Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1: TMenuItem
        Caption = 
          'Gerar planilha demonstrativa das notas finais (do candidato que ' +
          'est'#225' aparecendo na tela)'
        OnClick = Gerarplanilhademonstrativadocandidatoqueestaparecendonatela1Click
      end
      object Gerarplanilhademonstrativadasnotasfinaisdetodososcandidatos1: TMenuItem
        Caption = 
          'Gerar planilha demonstrativa das notas finais de todos os candid' +
          'atos'
        OnClick = Gerarplanilhademonstrativadasnotasfinaisdetodososcandidatos1Click
      end
    end
    object Parecerfinal1: TMenuItem
      Caption = 'Parecer final'
      object Gerarparecerfinaldabanca1: TMenuItem
        Caption = 'Gerar parecer final da banca'
        OnClick = Button5Click
      end
    end
    object Ajuda1: TMenuItem
      Caption = 'Ajuda'
      object Dicas1: TMenuItem
        Caption = 'Dicas'
        OnClick = Button3Click
      end
    end
  end
end
