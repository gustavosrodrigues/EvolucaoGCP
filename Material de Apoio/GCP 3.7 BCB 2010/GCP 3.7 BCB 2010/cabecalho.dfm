object FormCabecalho: TFormCabecalho
  Left = 160
  Top = 29
  Width = 381
  Height = 299
  BorderIcons = []
  Caption = 'Cabe'#231'alho'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox4: TGroupBox
    Left = 8
    Top = 8
    Width = 353
    Height = 249
    Caption = 'Cabe'#231'alho'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 309
      Height = 13
      Caption = 
        'Este '#233' o texto do cabe'#231'alho que ir'#225' aparecer nas atas, listas, e' +
        'tc.'
    end
    object Label2: TLabel
      Left = 16
      Top = 32
      Width = 110
      Height = 13
      Caption = 'Edite se for necess'#225'rio.'
    end
    object RichEdit1: TRichEdit
      Left = 8
      Top = 56
      Width = 337
      Height = 153
      TabOrder = 0
    end
    object Button1: TButton
      Left = 264
      Top = 216
      Width = 75
      Height = 25
      Caption = 'Cancelar'
      ModalResult = 2
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 184
      Top = 216
      Width = 75
      Height = 25
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 2
    end
  end
  object lines_temp: TRichEdit
    Left = 352
    Top = 24
    Width = 337
    Height = 153
    Lines.Strings = (
      'lines_temp')
    TabOrder = 1
    Visible = False
  end
end
