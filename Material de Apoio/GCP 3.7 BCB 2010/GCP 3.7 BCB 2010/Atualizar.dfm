object FormAtualizar: TFormAtualizar
  Left = 0
  Top = 0
  Caption = 'Atualiza'#231#227'o autom'#225'tica'
  ClientHeight = 376
  ClientWidth = 874
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 13
    Width = 257
    Height = 19
    Caption = 'Atualiza'#231#227'o autom'#225'tica do GCP'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 790
    Top = 18
    Width = 329
    Height = 21
    TabOrder = 0
    Text = 'http://gcp.bugs3.com/gcp/lastversion.txt'
    Visible = False
  end
  object Button1: TButton
    Left = 687
    Top = 14
    Width = 90
    Height = 25
    Caption = 'Download GCP'
    TabOrder = 1
    Visible = False
    OnClick = Button1Click
  end
  object ProgressBar1: TProgressBar
    Left = 8
    Top = 45
    Width = 857
    Height = 25
    TabOrder = 2
  end
  object Button2: TButton
    Left = 632
    Top = 343
    Width = 97
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 76
    Width = 857
    Height = 261
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Button3: TButton
    Left = 759
    Top = 343
    Width = 107
    Height = 25
    Caption = 'Fechar'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 584
    Top = 14
    Width = 97
    Height = 25
    Caption = 'Download regras'
    TabOrder = 6
    Visible = False
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 408
    Top = 14
    Width = 155
    Height = 25
    Caption = 'Verifica se h'#225' nova vers'#227'o'
    TabOrder = 7
    Visible = False
    OnClick = Button5Click
  end
  object IdHTTP1: TIdHTTP
    OnWork = IdHTTP1Work
    OnWorkBegin = IdHTTP1WorkBegin
    OnWorkEnd = IdHTTP1WorkEnd
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    HTTPOptions = [hoForceEncodeParams]
    Left = 840
    Top = 16
  end
end
