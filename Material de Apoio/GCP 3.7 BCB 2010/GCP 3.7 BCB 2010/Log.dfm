object FormLog: TFormLog
  Left = 0
  Top = 0
  Caption = 'FormLog'
  ClientHeight = 312
  ClientWidth = 1114
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 48
    Width = 1089
    Height = 241
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Button1: TButton
    Left = 8
    Top = 17
    Width = 75
    Height = 25
    Caption = 'Limpar'
    TabOrder = 1
    OnClick = Button1Click
  end
end
