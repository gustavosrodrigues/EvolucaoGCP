object SelData: TSelData
  Left = 451
  Top = 198
  AlphaBlend = True
  AlphaBlendValue = 220
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Data do documento'
  ClientHeight = 171
  ClientWidth = 290
  Color = clGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object MonthCalendar1: TMonthCalendar
    Left = 8
    Top = 8
    Width = 191
    Height = 154
    CalColors.BackColor = clGreen
    Date = 39808.436926655090000000
    TabOrder = 0
  end
  object Button1: TButton
    Left = 200
    Top = 136
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
end
