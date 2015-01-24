object FormConfiguracao: TFormConfiguracao
  Left = 389
  Top = 141
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Configura'#231#227'o'
  ClientHeight = 514
  ClientWidth = 605
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label13: TLabel
    Left = 463
    Top = 255
    Width = 35
    Height = 13
    Caption = 'Escrita:'
  end
  object Label14: TLabel
    Left = 359
    Top = 277
    Width = 35
    Height = 13
    Caption = 'Escrita:'
  end
  object PageControl1: TPageControl
    Left = 16
    Top = 16
    Width = 577
    Height = 489
    ActivePage = Pag4
    TabOrder = 0
    object Pag1: TTabSheet
      Caption = 'Pag1'
      TabVisible = False
      object GroupBox5: TGroupBox
        Left = 3
        Top = 3
        Width = 563
        Height = 405
        Caption = 'Etapa 1 de 4 - DADOS GERAIS'
        TabOrder = 0
        object Label6: TLabel
          Left = 336
          Top = 24
          Width = 70
          Height = 13
          Caption = 'Data de in'#237'cio:'
        end
        object Label8: TLabel
          Left = 16
          Top = 269
          Width = 99
          Height = 13
          Caption = 'Regras do concurso:'
        end
        object LabeledEdit1: TLabeledEdit
          Left = 16
          Top = 40
          Width = 281
          Height = 21
          EditLabel.Width = 222
          EditLabel.Height = 13
          EditLabel.Caption = 'Minist'#233'rio: (exemplo: "Minist'#233'rio da Educa'#231#227'o")'
          TabOrder = 0
          Text = 'Minist'#233'rio da Educa'#231#227'o'
        end
        object LabeledEdit2: TLabeledEdit
          Left = 16
          Top = 184
          Width = 281
          Height = 21
          EditLabel.Width = 307
          EditLabel.Height = 13
          EditLabel.Caption = #193'rea: (exemplo: "Ci'#234'ncia da Computa'#231#227'o - Estruturas de Dados")'
          TabOrder = 5
        end
        object LabeledEdit5: TLabeledEdit
          Left = 16
          Top = 88
          Width = 281
          Height = 21
          EditLabel.Width = 277
          EditLabel.Height = 13
          EditLabel.Caption = 'Universidade (exemplo: "Universidade Federal do Pampa")'
          TabOrder = 1
          Text = 'Funda'#231#227'o Universidade Federal do Pampa'
        end
        object LabeledEdit6: TLabeledEdit
          Left = 256
          Top = 328
          Width = 281
          Height = 21
          EditLabel.Width = 254
          EditLabel.Height = 13
          EditLabel.Caption = 'Centro (exemplo: "Centro de Tecnologia de Alegrete")'
          TabOrder = 2
          Visible = False
        end
        object LabeledEdit7: TLabeledEdit
          Left = 16
          Top = 136
          Width = 281
          Height = 21
          EditLabel.Width = 141
          EditLabel.Height = 13
          EditLabel.Caption = 'Campus (exemplo: "Alegrete")'
          TabOrder = 3
        end
        object LabeledEdit8: TLabeledEdit
          Left = 256
          Top = 360
          Width = 281
          Height = 21
          EditLabel.Width = 234
          EditLabel.Height = 13
          EditLabel.Caption = 'Departamento (caso n'#227'o exista, deixe em branco)'
          TabOrder = 4
          Visible = False
        end
        object DateTimePicker1: TDateTimePicker
          Left = 336
          Top = 43
          Width = 201
          Height = 21
          Date = 39568.612130706000000000
          Time = 39568.612130706000000000
          TabOrder = 7
        end
        object RadioGroup4: TRadioGroup
          Left = 336
          Top = 80
          Width = 174
          Height = 125
          Caption = 'Classe do concurso - Professor:'
          ItemIndex = 2
          Items.Strings = (
            'Adjunto'
            'Assistente'
            'do Magist'#233'rio Superior'
            'Auxiliar'
            'Substituto'
            'Tempor'#225'rio')
          TabOrder = 8
        end
        object LabeledEdit3: TLabeledEdit
          Left = 16
          Top = 235
          Width = 281
          Height = 21
          EditLabel.Width = 140
          EditLabel.Height = 13
          EditLabel.Caption = 'Edital: (exemplo: "041/2010")'
          TabOrder = 6
        end
        object ListBox1: TListBox
          Left = 16
          Top = 288
          Width = 513
          Height = 106
          ItemHeight = 13
          TabOrder = 9
        end
        object FileListBox1: TFileListBox
          Left = 121
          Top = 262
          Width = 191
          Height = 153
          ItemHeight = 13
          Mask = '*.gcr'
          TabOrder = 10
          Visible = False
        end
      end
      object Button9: TButton
        Left = 480
        Top = 424
        Width = 75
        Height = 25
        Caption = 'Pr'#243'ximo ->'
        TabOrder = 1
        OnClick = Button9Click
      end
    end
    object Pag2: TTabSheet
      Caption = 'Pag2'
      ImageIndex = 3
      TabVisible = False
      OnShow = Pag2Show
      object Button3: TButton
        Left = 760
        Top = 352
        Width = 105
        Height = 33
        Caption = 'Fechar'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button8: TButton
        Left = 670
        Top = 348
        Width = 75
        Height = 25
        Caption = 'OK'
        TabOrder = 1
        OnClick = Button8Click
      end
      object GroupBox3: TGroupBox
        Left = 16
        Top = 8
        Width = 353
        Height = 409
        Caption = 'Etapa 2 de 4 - DIRET'#211'RIO'
        TabOrder = 2
        object Label5: TLabel
          Left = 16
          Top = 384
          Width = 174
          Height = 13
          Caption = 'Nome curto do concurso a ser salvo:'
        end
        object DirectoryListBox1: TDirectoryListBox
          Left = 16
          Top = 48
          Width = 329
          Height = 289
          Hint = 'Diret'#243'rio onde ser'#227'o gravados todos os documentos gerados'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnChange = DirectoryListBox1Change
          OnClick = DirectoryListBox1Click
        end
        object Edit4: TEdit
          Left = 16
          Top = 344
          Width = 329
          Height = 21
          TabOrder = 1
        end
        object Edit5: TEdit
          Left = 200
          Top = 376
          Width = 145
          Height = 21
          TabOrder = 2
        end
        object DriveComboBox1: TDriveComboBox
          Left = 16
          Top = 24
          Width = 329
          Height = 19
          TabOrder = 3
          OnChange = DriveComboBox1Change
        end
      end
      object Button11: TButton
        Left = 488
        Top = 424
        Width = 75
        Height = 25
        Caption = 'Pr'#243'ximo ->'
        TabOrder = 3
        OnClick = Button8Click
      end
      object Button12: TButton
        Left = 408
        Top = 424
        Width = 75
        Height = 25
        Caption = '<- Anterior'
        TabOrder = 4
        OnClick = Button12Click
      end
      object Memo1: TMemo
        Left = 376
        Top = 16
        Width = 177
        Height = 265
        Lines.Strings = (
          'Aten'#231#227'o:'
          ''
          'O diret'#243'rio selecionado '#233' o local '
          'onde ser'#227'o gravados todos os '
          'arquivos gerados pelo GCP para '
          'este concurso.'
          'Selecione um diret'#243'rio vazio ou que '
          'n'#227'o contenha arquivos gerados por '
          'outros concursos.'
          ''
          'Voc'#234' pode tamb'#233'm criar um novo '
          'diret'#243'rio exclusivo para armazenar '
          'os arquivos deste concurso. Para '
          'isto, basta digitar o nome do '
          'diret'#243'rio no espa'#231'o ao lado, '
          'incluindo o nome da unidade.'
          ''
          'Exemplo:'
          'c:\concurso1')
        TabOrder = 5
      end
    end
    object Pag3: TTabSheet
      Caption = 'Pag3'
      ImageIndex = 1
      TabVisible = False
      object GroupBox1: TGroupBox
        Left = 16
        Top = 4
        Width = 529
        Height = 417
        Caption = 'Etapa 3 de 4 - BANCA'
        TabOrder = 0
        object GroupBox4: TGroupBox
          Left = 8
          Top = 16
          Width = 505
          Height = 129
          Caption = 'Examinador 1 - Presidente da banca'
          TabOrder = 0
          object Label1: TLabel
            Left = 8
            Top = 24
            Width = 31
            Height = 13
            Caption = 'Nome:'
          end
          object Edit1: TEdit
            Left = 64
            Top = 24
            Width = 225
            Height = 21
            TabOrder = 0
          end
          object RadioGroup1: TRadioGroup
            Left = 304
            Top = 8
            Width = 185
            Height = 113
            Caption = 'Categoria'
            ItemIndex = 0
            Items.Strings = (
              'Professor Doutor'
              'Professor Mestre'
              'Professor Especialista'
              'Professor Graduado'
              'Outro:')
            TabOrder = 1
          end
          object RadioGroup2: TRadioGroup
            Left = 200
            Top = 64
            Width = 89
            Height = 57
            Caption = 'Sexo'
            ItemIndex = 0
            Items.Strings = (
              'Masculino'
              'Feminino')
            TabOrder = 2
          end
          object Edit7: TEdit
            Left = 368
            Top = 96
            Width = 113
            Height = 21
            TabOrder = 3
          end
        end
        object GroupBox6: TGroupBox
          Left = 8
          Top = 152
          Width = 505
          Height = 129
          Caption = 'Examinador 2'
          TabOrder = 1
          object Label2: TLabel
            Left = 8
            Top = 24
            Width = 31
            Height = 13
            Caption = 'Nome:'
          end
          object Edit2: TEdit
            Left = 64
            Top = 24
            Width = 225
            Height = 21
            TabOrder = 0
          end
          object RadioGroup5: TRadioGroup
            Left = 304
            Top = 8
            Width = 185
            Height = 113
            Caption = 'Categoria'
            ItemIndex = 0
            Items.Strings = (
              'Professor Doutor'
              'Professor Mestre'
              'Professor Especialista'
              'Professor Graduado'
              'Outro:')
            TabOrder = 1
          end
          object RadioGroup6: TRadioGroup
            Left = 200
            Top = 64
            Width = 89
            Height = 57
            Caption = 'Sexo'
            ItemIndex = 0
            Items.Strings = (
              'Masculino'
              'Feminino')
            TabOrder = 2
          end
          object Edit8: TEdit
            Left = 368
            Top = 96
            Width = 113
            Height = 21
            TabOrder = 3
          end
        end
        object GroupBox7: TGroupBox
          Left = 8
          Top = 288
          Width = 505
          Height = 129
          Caption = 'Examinador 3'
          TabOrder = 2
          object Label7: TLabel
            Left = 8
            Top = 24
            Width = 31
            Height = 13
            Caption = 'Nome:'
          end
          object Edit6: TEdit
            Left = 64
            Top = 24
            Width = 225
            Height = 21
            TabOrder = 0
          end
          object RadioGroup7: TRadioGroup
            Left = 304
            Top = 8
            Width = 185
            Height = 113
            Caption = 'Categoria'
            ItemIndex = 0
            Items.Strings = (
              'Professor Doutor'
              'Professor Mestre'
              'Professor Especialista'
              'Professor Graduado'
              'Outro:')
            TabOrder = 1
          end
          object RadioGroup8: TRadioGroup
            Left = 200
            Top = 64
            Width = 89
            Height = 57
            Caption = 'Sexo'
            ItemIndex = 0
            Items.Strings = (
              'Masculino'
              'Feminino')
            TabOrder = 2
          end
          object Edit9: TEdit
            Left = 368
            Top = 96
            Width = 113
            Height = 21
            TabOrder = 3
          end
        end
        object List_Banca: TCheckListBox
          Left = 503
          Top = 192
          Width = 121
          Height = 97
          ItemHeight = 13
          TabOrder = 3
          Visible = False
        end
      end
      object Button13: TButton
        Left = 488
        Top = 424
        Width = 75
        Height = 25
        Caption = 'Pr'#243'ximo ->'
        TabOrder = 1
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 408
        Top = 424
        Width = 75
        Height = 25
        Caption = '<- Anterior'
        TabOrder = 2
        OnClick = Button14Click
      end
    end
    object Pag4: TTabSheet
      Caption = 'Pag4'
      ImageIndex = 2
      TabVisible = False
      OnShow = Pag4Show
      object GroupBox2: TGroupBox
        Left = 16
        Top = 4
        Width = 529
        Height = 417
        Caption = 'Etapa 4 de 4 - CANDIDATOS INSCRITOS'
        TabOrder = 0
        object List_Candidatos: TCheckListBox
          Left = 8
          Top = 32
          Width = 337
          Height = 145
          ItemHeight = 13
          TabOrder = 0
          OnClick = List_CandidatosClick
        end
        object Button6: TButton
          Left = 120
          Top = 192
          Width = 113
          Height = 25
          Caption = 'Remover candidato'
          TabOrder = 1
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 240
          Top = 192
          Width = 105
          Height = 25
          Caption = 'Editar candidato'
          TabOrder = 2
          OnClick = Button7Click
        end
        object Button1: TButton
          Left = 8
          Top = 192
          Width = 105
          Height = 25
          Caption = 'Adicionar candidato'
          TabOrder = 3
          OnClick = Button1Click
        end
        object Panel1: TPanel
          Left = 8
          Top = 224
          Width = 337
          Height = 185
          TabOrder = 4
          object Label3: TLabel
            Left = 8
            Top = 12
            Width = 31
            Height = 13
            Caption = 'Nome:'
          end
          object Label4: TLabel
            Left = 8
            Top = 108
            Width = 98
            Height = 13
            Caption = 'Data de nascimento:'
          end
          object Edit3: TEdit
            Left = 48
            Top = 12
            Width = 281
            Height = 21
            TabOrder = 0
          end
          object RadioGroup3: TRadioGroup
            Left = 8
            Top = 40
            Width = 129
            Height = 57
            Caption = 'Sexo'
            ItemIndex = 0
            Items.Strings = (
              'Masculino'
              'Feminino')
            TabOrder = 1
          end
          object DateTimePicker2: TDateTimePicker
            Left = 112
            Top = 108
            Width = 186
            Height = 21
            Hint = 
              'A data de nascimento serve apenas como crit'#233'rio de desempate na ' +
              'nota final. Caso n'#227'o souber, informe qualquer uma.'
            Date = 27395.800182291700000000
            Time = 27395.800182291700000000
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
          end
          object Button2: TButton
            Left = 136
            Top = 144
            Width = 81
            Height = 25
            Caption = 'OK'
            TabOrder = 3
            OnClick = Button2Click
          end
          object Button4: TButton
            Left = 232
            Top = 144
            Width = 73
            Height = 25
            Caption = 'Cancelar'
            TabOrder = 4
            OnClick = Button4Click
          end
        end
        object Memo2: TMemo
          Left = 360
          Top = 32
          Width = 153
          Height = 249
          Lines.Strings = (
            'Cadastre aqui todos os '
            'candidatos inscritos no '
            'concurso.'
            ''
            'Voc'#234' pode adicionar, remover '
            'ou editar as informa'#231#245'es '
            'clicando nos bot'#245'es '#224' '
            'esquerda.'
            ''
            'O cadastro da data de '
            'nascimento dos candidatos '#233' '
            'opcional. Esta informa'#231#227'o s'#243' '
            'ser'#225' utilizada como crit'#233'rio de '
            'desempate, de acordo com a '
            'Instru'#231#227'o Normativa, e n'#227'o '
            'aparecer'#225' em nenhuma ata ou '
            'lista.')
          TabOrder = 5
        end
      end
      object Button15: TButton
        Left = 488
        Top = 424
        Width = 75
        Height = 25
        Caption = 'Fim'
        TabOrder = 1
        OnClick = Button3Click
      end
      object Button16: TButton
        Left = 408
        Top = 424
        Width = 75
        Height = 25
        Caption = '<- Anterior'
        TabOrder = 2
        OnClick = Button16Click
      end
    end
  end
  object Button10: TButton
    Left = 32
    Top = 464
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 1
    OnClick = Button10Click
  end
end
