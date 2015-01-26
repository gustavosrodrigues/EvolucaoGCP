object FormListagem: TFormListagem
  Left = 511
  Top = 42
  Width = 954
  Height = 718
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Listagem de documentos a serem gerados'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 682
    Height = 13
    Caption = 
      'Obs.: Cronograma aconselhado. Os documentos a serem gerados e as' +
      ' datas podem mudar de acordo com as caracter'#237'sticas de cada conc' +
      'urso.'
  end
  object Label2: TLabel
    Left = 24
    Top = 56
    Width = 38
    Height = 13
    Caption = '1'#186' dia:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 80
    Width = 189
    Height = 13
    Caption = 'Sess'#227'o de abertura do concurso:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 24
    Top = 232
    Width = 182
    Height = 13
    Caption = 'Realiza'#231#227'o da prova de escrita:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 456
    Width = 38
    Height = 13
    Caption = '2'#186' dia:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 24
    Top = 480
    Width = 296
    Height = 13
    Caption = 'Sess'#227'o de divulga'#231#227'o do resultado da prova escrita'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 24
    Top = 560
    Width = 198
    Height = 13
    Caption = 'Sorteio do ponto da prova did'#225'tica'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 488
    Top = 56
    Width = 38
    Height = 13
    Caption = '3'#186' dia:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label9: TLabel
    Left = 488
    Top = 80
    Width = 171
    Height = 13
    Caption = 'Realiza'#231#227'o da prova did'#225'tica:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label10: TLabel
    Left = 488
    Top = 184
    Width = 38
    Height = 13
    Caption = '4'#186' dia:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 488
    Top = 208
    Width = 292
    Height = 13
    Caption = 'Sess'#227'o de divulga'#231#227'o das notas da prova did'#225'tica:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 488
    Top = 296
    Width = 376
    Height = 13
    Caption = 'Sess'#227'o de realiza'#231#227'o da prova de defesa de memorial acad'#234'mico:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label13: TLabel
    Left = 488
    Top = 432
    Width = 306
    Height = 13
    Caption = 'Sess'#227'o de divulga'#231#227'o do resultado final do concurso:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 104
    Width = 305
    Height = 17
    Caption = 'Gerar ata de instala'#231#227'o da comiss'#227'o examinadora'
    TabOrder = 0
  end
  object CheckBox2: TCheckBox
    Left = 24
    Top = 152
    Width = 265
    Height = 17
    Caption = 'Gerar lista de presen'#231'a dos candidatos'
    TabOrder = 1
  end
  object CheckBox3: TCheckBox
    Left = 24
    Top = 176
    Width = 433
    Height = 17
    Caption = 
      'Gerar ata de recep'#231#227'o dos candidatos e do material da prova de t' +
      #237'tulos e memorial'
    TabOrder = 2
  end
  object CheckBox4: TCheckBox
    Left = 24
    Top = 200
    Width = 313
    Height = 17
    Caption = 'Gerar recibos de documenta'#231#227'o - por candidadto'
    TabOrder = 3
  end
  object CheckBox5: TCheckBox
    Left = 24
    Top = 128
    Width = 249
    Height = 17
    Caption = 'Gerar cronograma do concurso'
    TabOrder = 4
  end
  object CheckBox6: TCheckBox
    Left = 24
    Top = 256
    Width = 233
    Height = 17
    Caption = 'Gerar lista de presen'#231'a na realiza'#231#227'o da prova escrita'
    TabOrder = 5
  end
  object CheckBox7: TCheckBox
    Left = 24
    Top = 280
    Width = 257
    Height = 17
    Caption = 'Gerar a lista de pontos para a prova escrita'
    TabOrder = 6
  end
  object CheckBox8: TCheckBox
    Left = 24
    Top = 304
    Width = 313
    Height = 17
    Caption = 'Gerar modelo da planilha de avalia'#231#227'o da prova escrita'
    TabOrder = 7
  end
  object CheckBox9: TCheckBox
    Left = 24
    Top = 328
    Width = 329
    Height = 17
    Caption = 'Gerar ata de realiza'#231#227'o da prova escrita'
    TabOrder = 8
  end
  object CheckBox10: TCheckBox
    Left = 24
    Top = 424
    Width = 265
    Height = 17
    Caption = 'Gerar ata de julgamento da prova escrita'
    TabOrder = 9
  end
  object CheckBox11: TCheckBox
    Left = 24
    Top = 504
    Width = 361
    Height = 17
    Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o das notas da prova escrita'
    TabOrder = 10
  end
  object CheckBox12: TCheckBox
    Left = 24
    Top = 528
    Width = 289
    Height = 17
    Caption = 'Gerar listagem das notas da prova escrita'
    TabOrder = 11
  end
  object CheckBox13: TCheckBox
    Left = 24
    Top = 608
    Width = 337
    Height = 17
    Caption = 'Gerar lista de presen'#231'a no sorteio do ponto da prova did'#225'tica'
    TabOrder = 12
  end
  object CheckBox14: TCheckBox
    Left = 24
    Top = 632
    Width = 313
    Height = 17
    Caption = 'Gerar ata do sorteio do ponto da prova did'#225'tica'
    TabOrder = 13
  end
  object CheckBox15: TCheckBox
    Left = 24
    Top = 584
    Width = 329
    Height = 17
    Caption = 'Gerar modelo de planilha de avalia'#231#227'o da prova did'#225'tica'
    TabOrder = 14
  end
  object CheckBox16: TCheckBox
    Left = 24
    Top = 400
    Width = 385
    Height = 17
    Caption = 
      'Gerar planilha de notas da prova escrita (por candidato e por ex' +
      'aminador)'
    TabOrder = 15
  end
  object CheckBox17: TCheckBox
    Left = 24
    Top = 656
    Width = 393
    Height = 17
    Caption = 
      'Gerar planilha de notas da prova did'#225'tica (por candidato e por e' +
      'xaminador)'
    TabOrder = 16
  end
  object CheckBox18: TCheckBox
    Left = 488
    Top = 104
    Width = 305
    Height = 17
    Caption = 'Gerar lista de presen'#231'a na realiza'#231#227'o da prova did'#225'tica'
    TabOrder = 17
  end
  object CheckBox19: TCheckBox
    Left = 488
    Top = 128
    Width = 265
    Height = 17
    Caption = 'Gerar ata da realiza'#231#227'o da prova did'#225'tica'
    TabOrder = 18
  end
  object CheckBox20: TCheckBox
    Left = 488
    Top = 232
    Width = 305
    Height = 17
    Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o das notas da prova did'#225'tica'
    TabOrder = 19
  end
  object CheckBox21: TCheckBox
    Left = 488
    Top = 256
    Width = 265
    Height = 17
    Caption = 'Gerar planilha com a lista de notas da prova did'#225'tica'
    TabOrder = 20
  end
  object CheckBox22: TCheckBox
    Left = 488
    Top = 320
    Width = 361
    Height = 17
    Caption = 'Gerar lista de presen'#231'a na prova de defesa de memorial acad'#234'mico'
    TabOrder = 21
  end
  object CheckBox23: TCheckBox
    Left = 488
    Top = 392
    Width = 353
    Height = 17
    Caption = 'Gerar ata de realiza'#231#227'o da prova de defesa de memorial acad'#234'mico'
    TabOrder = 22
  end
  object CheckBox24: TCheckBox
    Left = 488
    Top = 344
    Width = 409
    Height = 17
    Caption = 
      'Gerar modelo da planilha de avalia'#231#227'o da prova de defesa de memo' +
      'rial acad'#234'mico'
    TabOrder = 23
  end
  object CheckBox25: TCheckBox
    Left = 488
    Top = 368
    Width = 409
    Height = 17
    Caption = 
      'Gerar planilha de notas da prova de defesa de mem. acad. (por ca' +
      'nd. e por exam.)'
    TabOrder = 24
  end
  object CheckBox26: TCheckBox
    Left = 488
    Top = 456
    Width = 353
    Height = 17
    Caption = 'Gerar ata da sess'#227'o de divulga'#231#227'o do resultado final'
    TabOrder = 25
  end
  object CheckBox27: TCheckBox
    Left = 488
    Top = 480
    Width = 313
    Height = 17
    Caption = 'Gerar planilha demonstrativa de notas finais por candidato'
    TabOrder = 26
  end
  object CheckBox28: TCheckBox
    Left = 488
    Top = 504
    Width = 313
    Height = 17
    Caption = 'Gerar parecer final da banca examinadora'
    TabOrder = 27
  end
  object Button1: TButton
    Left = 824
    Top = 616
    Width = 75
    Height = 25
    Caption = 'Fechar'
    TabOrder = 28
    OnClick = Button1Click
  end
  object CheckBox29: TCheckBox
    Left = 24
    Top = 352
    Width = 353
    Height = 17
    Caption = 'Gerar lista de presen'#231'a na leitura da prova escrita'
    TabOrder = 29
  end
  object CheckBox30: TCheckBox
    Left = 24
    Top = 376
    Width = 329
    Height = 17
    Caption = 'Gerar ata de realiza'#231#227'o da sess'#227'o de leitura da prova escrita'
    TabOrder = 30
  end
end