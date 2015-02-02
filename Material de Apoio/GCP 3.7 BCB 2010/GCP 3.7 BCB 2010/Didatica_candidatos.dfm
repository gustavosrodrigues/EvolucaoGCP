object FormDidaticaCandidatos: TFormDidaticaCandidatos
  Left = 422
  Top = 181
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Prova Did'#225'tica - Configura'#231#227'o dos candidatos'
  ClientHeight = 390
  ClientWidth = 562
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
  object Label1: TLabel
    Left = 24
    Top = 48
    Width = 159
    Height = 13
    Caption = 'Candidatos inscritos no concurso:'
  end
  object Label2: TLabel
    Left = 312
    Top = 40
    Width = 209
    Height = 13
    Caption = 'Candidatos aptos a realizar a prova did'#225'tica:'
  end
  object Label3: TLabel
    Left = 312
    Top = 56
    Width = 96
    Height = 13
    Caption = '(em ordem sorteada)'
  end
  object Label4: TLabel
    Left = 24
    Top = 8
    Width = 501
    Height = 13
    Caption = 
      'Ap'#243's o sorteio da ordem dos candidatos para a realiza'#231#227'o da prov' +
      'a did'#225'tica, preencha os quadros abaixo.'
  end
  object ListBox1: TListBox
    Left = 24
    Top = 80
    Width = 241
    Height = 273
    ItemHeight = 13
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 312
    Top = 80
    Width = 225
    Height = 273
    ItemHeight = 13
    TabOrder = 1
  end
  object Button6: TButton
    Left = 279
    Top = 96
    Width = 25
    Height = 25
    Caption = '-->'
    TabOrder = 2
    OnClick = Button6Click
  end
  object Button17: TButton
    Left = 279
    Top = 128
    Width = 25
    Height = 25
    Caption = '<--'
    TabOrder = 3
    OnClick = Button17Click
  end
  object Button1: TButton
    Left = 464
    Top = 360
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 376
    Top = 360
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 5
    OnClick = Button2Click
  end
end
