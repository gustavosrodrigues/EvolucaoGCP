object FormEntrevista_candidatos: TFormEntrevista_candidatos
  Left = 335
  Top = 124
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Prova de Entrevista - candidatos'
  ClientHeight = 395
  ClientWidth = 568
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 159
    Height = 13
    Caption = 'Candidatos inscritos no concurso:'
  end
  object Label2: TLabel
    Left = 312
    Top = 8
    Width = 181
    Height = 13
    Caption = 'Candidatos aptos a realizar a prova de'
  end
  object Label3: TLabel
    Left = 312
    Top = 40
    Width = 94
    Height = 13
    Caption = '(na ordem sorteada)'
  end
  object Label4: TLabel
    Left = 312
    Top = 21
    Width = 50
    Height = 13
    Caption = 'Entrevista:'
  end
  object ListBox1: TListBox
    Left = 24
    Top = 64
    Width = 241
    Height = 273
    ItemHeight = 13
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 312
    Top = 64
    Width = 225
    Height = 273
    ItemHeight = 13
    TabOrder = 1
  end
  object Button6: TButton
    Left = 279
    Top = 80
    Width = 25
    Height = 25
    Caption = '-->'
    TabOrder = 2
    OnClick = Button6Click
  end
  object Button17: TButton
    Left = 279
    Top = 112
    Width = 25
    Height = 25
    Caption = '<--'
    TabOrder = 3
    OnClick = Button17Click
  end
  object Button1: TButton
    Left = 464
    Top = 352
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 368
    Top = 352
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 5
    OnClick = Button2Click
  end
end
