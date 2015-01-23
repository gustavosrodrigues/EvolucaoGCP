object FormDicas: TFormDicas
  Left = 349
  Top = 209
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Dicas'
  ClientHeight = 390
  ClientWidth = 564
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
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 537
    Height = 361
    ActivePage = TabResultado
    TabOrder = 0
    object TabResultado: TTabSheet
      Caption = 'Divulga'#231#227'o do resultado'
      object Label1: TLabel
        Left = 24
        Top = 312
        Width = 189
        Height = 13
        Caption = 'Suporte: gcp.suporte@unipampa.edu.br'
      end
      object Memo1: TMemo
        Left = 8
        Top = 8
        Width = 377
        Height = 297
        Lines.Strings = (
          
            '- Na sess'#227'o de divulga'#231#227'o dos resultados, utilize um projetor mu' +
            'ltim'#237'dia'
          
            'conectado ao computador para que todos possam visualizar as nota' +
            's.'
          ''
          
            '- No projetor, mostre a pr'#243'pria tela do Gerenciador de Concursos' +
            ' da'
          
            'UNIPAMPA, pois o c'#225'lculo das m'#233'dias '#233' feito de maneira autom'#225'tic' +
            'a.'
          ''
          '- Insira as notas com duas casas decimais. Ex.: 8,50'
          ''
          '- Utilize a v'#237'rgula como separador decimal'
          '')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabDidatica: TTabSheet
      Caption = 'Prova did'#225'tica'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 3
        Top = 17
        Width = 377
        Height = 313
        Lines.Strings = (
          
            '- Ap'#243's o sorteio da ordem dos candidatos para a realiza'#231#227'o da pr' +
            'ova'
          'did'#225'tica, clique em "Configurar candidatos" na janela da prova'
          'did'#225'tica e ordene o nome dos candidatos pela ordem sorteada.'
          ''
          
            '- Na janela da prova did'#225'tica, marque a data e o hor'#225'rio agendad' +
            'os'
          'para o sorteio do ponto e para a realiza'#231#227'o da prova did'#225'tica de'
          'cada candidato.'
          ''
          '- Gere a lista de presen'#231'a do sorteio do ponto para a prova'
          'did'#225'tica ap'#243's a ordena'#231#227'o indicada e a configura'#231#227'o das datas'
          'e hor'#225'rios no item anterior.'
          ''
          
            '- Durante o sorteio do ponto para a prova did'#225'tica, escreva '#224' m'#227 +
            'o o '
          
            'n'#250'mero do ponto sorteado na lista de presen'#231'a j'#225' impressa e indi' +
            'que'
          
            'ao software, na janela da prova did'#225'tica, o n'#250'mero sorteado. Ist' +
            'o '#233
          'importante para a gera'#231#227'o autom'#225'tica da ata do sorteio.'
          ''
          
            '- Informe ao software, na janela da prova did'#225'tica, se o candida' +
            'to '
          
            'compareceu ou n'#227'o ao sorteio do ponto e '#224' realiza'#231#227'o da prova di' +
            'd'#225'tica. '
          'Isto '#233
          
            'importante para a gera'#231#227'o autom'#225'tica das atas de sorteio e de re' +
            'aliza'#231#227'o '
          'da prova..'
          ''
          ''
          '')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabTitulos: TTabSheet
      Caption = 'Prova de t'#237'tulos'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 8
        Top = 8
        Width = 377
        Height = 313
        Lines.Strings = (
          '- Para manter a coer'#234'ncia, as notas da prova de t'#237'tulos de cada '
          'candidato '#233' a mesma para todos os examinadores. Assim, basta '
          'digitar as notas uma vez s'#243'.'
          ''
          
            '- Para imprimir a planilha de notas do candidato, selecione o no' +
            'me'
          'do candidato e o nome do examinador.'
          ''
          '- Entre somente com as quantidades de cada item, os c'#225'lculos s'#227'o'
          'feitos de maneira autom'#225'tica. '
          ''
          '- As quantidades podem ser quaisquer n'#250'meros reais (ex.: 1,5).'
          '')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabMemorial: TTabSheet
      Caption = 'Prova de Defesa de Memorial Acad'#234'mico'
      ImageIndex = 3
      object Memo4: TMemo
        Left = 8
        Top = 8
        Width = 377
        Height = 313
        Lines.Strings = (
          
            '- Ap'#243's o sorteio da ordem dos candidatos para a realiza'#231#227'o da pr' +
            'ova'
          
            'de defesa de Memorial Acad'#234'mico, clique em "Configurar candidato' +
            's" na '
          
            'janela da prova de defesa de memorial e ordene o nome dos candid' +
            'atos '
          'pela ordem sorteada.'
          ''
          
            '- Na janela da prova de memorial acad'#234'mico, marque a data e o ho' +
            'r'#225'rio '
          'agendados para realiza'#231#227'o da prova de cada candidato.'
          ''
          
            '- Gere a lista de presen'#231'a na realiza'#231#227'o da prova de defesa de m' +
            'emorial'
          'acad'#234'mico ap'#243's a ordena'#231#227'o indicada e a configura'#231#227'o das datas'
          'e hor'#225'rios no item anterior.'
          ''
          
            '- Informe ao software, na janela da prova de memorial acad'#234'mico,' +
            ' se o'
          'candidato compareceu ou n'#227'o '#224' realiza'#231#227'o da prova. Isto '#233
          
            'importante para a gera'#231#227'o autom'#225'tica da ata de realiza'#231#227'o da pro' +
            'va.'
          ''
          ''
          '')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabEntrevista: TTabSheet
      Caption = 'Prova Entrevista'
      ImageIndex = 5
      object Memo6: TMemo
        Left = 8
        Top = 8
        Width = 377
        Height = 313
        Lines.Strings = (
          
            '- Ap'#243's o sorteio da ordem dos candidatos para a realiza'#231#227'o da pr' +
            'ova'
          'de Entrevista, clique em "Configurar candidatos" na '
          'janela da prova de Entrevista e ordene o nome dos candidatos '
          'pela ordem sorteada.'
          ''
          '- Na janela da prova de Entrevista, marque a data e o hor'#225'rio '
          'agendados para realiza'#231#227'o da prova de cada candidato.'
          ''
          
            '- Gere a lista de presen'#231'a na realiza'#231#227'o da prova de Entrevista ' +
            'ap'#243's a '
          'ordena'#231#227'o indicada e a configura'#231#227'o das datas'
          'e hor'#225'rios no item anterior.'
          ''
          '- Informe ao aplicativo, na janela da prova de Entrevista, se o'
          'candidato compareceu ou n'#227'o '#224' realiza'#231#227'o da prova. Isto '#233
          
            'importante para a gera'#231#227'o autom'#225'tica da ata de realiza'#231#227'o da pro' +
            'va.'
          ''
          ''
          '')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'O que h'#225' de novo'
      ImageIndex = 4
      object Memo5: TMemo
        Left = 8
        Top = 8
        Width = 377
        Height = 313
        Lines.Strings = (
          'Hist'#243'rico de atualiza'#231#245'es:'
          ''
          'GCP vers'#227'o 3.7'
          ''
          'Release: fevereiro de 2014'
          'Principais modifica'#231#245'es:'
          
            '- Atualiza'#231#227'o autom'#225'tica para a vers'#227'o mais recente do aplicativ' +
            'o atrav'#233's '
          'da Interne.'
          '- Suporte '#224' prova de Entrevista'
          '- Melhorias no arquivo de regras do concurso'
          '- Melhorias na interface'
          '- Inclus'#227'o da gera'#231#227'o do"Recibo de devolu'#231#227'o de documentos"'
          '- Altera'#231#227'o do local da pasta dos arquivos de regras'
          ''
          '--------------------------------------'
          'GCP vers'#227'o 3.6'
          ''
          'Release: setembro de 2013'
          'Principais modifica'#231#245'es:'
          '- Melhorias no arquivo de regras do concurso'
          ''
          '--------------------------------------'
          'GCP  vers'#227'o 3.5'
          ''
          'Release: maio de 2013'
          'Principais modifica'#231#245'es:'
          '- Suporte a arquivo de regras do concurso'
          ''
          '--------------------------------------'
          'GCP vers'#227'o 3.4'
          ''
          'Release: fevereiro de 2012'
          'Principais modifica'#231#245'es:'
          '- Melhoria no texto das atas;'
          '- Corre'#231#227'o de bugs;'
          
            '- Inser'#231#227'o do quadro de confer'#234'ncia pela Comiss'#227'o de Concursos n' +
            'os '
          'cabe'#231'alhos dos documentos gerados;'
          
            '- Inser'#231#227'o da op'#231#227'o de imprimir as planilhas de avalia'#231#227'o de tod' +
            'os os '
          'candidatos de uma vez s'#243';'
          
            '- Altera'#231#227'o na planilha da prova de t'#237'tulos: agora somente uma p' +
            'lanilha '#233' '
          'impressa, com a assinatura de todos os examinadores. '
          ''
          '--------------------------------------'
          'GCP vers'#227'o 3.3'
          ''
          
            '- Adapta'#231#227'o das regras do concurso '#224' Resolu'#231#227'o 01/2010 do CONSUN' +
            'I;'
          '- Atualiza'#231#227'o dos textos das atas;'
          '- Inser'#231#227'o dos termos de desist'#234'ncia de prazo recursal.'
          ''
          '--------------------------------------'
          'GCP vers'#227'o 3.2'
          ''
          
            '- Adapta'#231#227'o do c'#225'lculo da m'#233'dia final '#224' Instru'#231#227'o Normativa 08/2' +
            '009;'
          
            '- Adapta'#231#227'o do texto das atas de realiza'#231#227'o das provas did'#225'tica ' +
            'e de '
          'defesa do memorial de trajet'#243'ria acad'#234'mica;'
          
            '- Autaliza'#231#227'o do texto da ata de abertura para "Instru'#231#227'o Normat' +
            'iva '
          '08/2009";'
          ''
          '--------------------------------------'
          'GCP vers'#227'o 3.1'
          ''
          'O que h'#225' de novo em rela'#231#227'o '#224' vers'#227'o 3.0:'
          ''
          
            '- Adapta'#231#227'o do c'#225'lculo das m'#233'dias da prova de t'#237'tulos '#224' Instru'#231#227 +
            'o '
          'Normativa 04/2009.')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
