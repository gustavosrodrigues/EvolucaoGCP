package br.edu.unipampa.gerenciadorconcurso.view;

import br.edu.unipampa.gerenciadorconcurso.dao.HibernateUtil;
import br.edu.unipampa.gerenciadorconcurso.view.interno.AtaComissao;
import br.edu.unipampa.gerenciadorconcurso.view.interno.AtaListaPresencaNovo;
import br.edu.unipampa.gerenciadorconcurso.view.interno.AtaRealizacaoProvaEscrita2;
import br.edu.unipampa.gerenciadorconcurso.view.interno.CadastroCandidato;
import br.edu.unipampa.gerenciadorconcurso.view.interno.DefinirCronograma;
import br.edu.unipampa.gerenciadorconcurso.view.interno.CadastroExaminador;
import br.edu.unipampa.gerenciadorconcurso.view.interno.DefinirPesoProvasConcurso;
import br.edu.unipampa.gerenciadorconcurso.view.interno.ParecerFinalBancaExaminadora;
import br.edu.unipampa.gerenciadorconcurso.view.interno.ReciboDocumentacaoPorCandidato;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelAtaJulgamentoProvaTitulo;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelAtaSessaoRealizacaoProvaDidatica;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelAvaliacaoIndividualProvaEscrita;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelDeclaracaoNaoImpedimentoPorMembroBanca;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelPEAtaSessaoDivulgacaoResultado;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelPlanilhaCriteriosAvaliacaoProvaEscrita;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelProvaEscritaAtaJulgamento;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelReciboDevolucaoDocumentacaoProvaTitulo;
import br.edu.unipampa.gerenciadorconcurso.view.interno.RelTermoDesistenciaProvaEscrita;
import br.edu.unipampa.gerenciadorconcurso.view.interno.SelecaoConcurso;
import java.beans.PropertyVetoException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JInternalFrame;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;
import org.hibernate.Session;

/**
 * @author Douglas
 * @since 10/01/2015
 */
public class AreaTrabalho extends javax.swing.JFrame {

    /**
     * Creates new form AreaTrabalho
     */
    public AreaTrabalho() {
        initComponents();
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);//deixa maximizado
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        areaTrabalho = new javax.swing.JDesktopPane();
        jToolBar1 = new javax.swing.JToolBar();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTree1 = new javax.swing.JTree();
        jMenuBar1 = new javax.swing.JMenuBar();
        menuAbrirConcurso = new javax.swing.JMenu();
        itemMenuCadastro = new javax.swing.JMenu();
        itemMenuCandidato = new javax.swing.JMenuItem();
        itemMenuExaminadores = new javax.swing.JMenuItem();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();
        jMenu1 = new javax.swing.JMenu();
        reciboDocumentacaoPorCandidato = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenu3 = new javax.swing.JMenu();
        itemMenuAtaInstalacaoComissao = new javax.swing.JMenuItem();
        menuAtaLista = new javax.swing.JMenuItem();
        menuProvaEscrita1 = new javax.swing.JMenu();
        menuProvaEscritaRelatorios1 = new javax.swing.JMenu();
        menuProvaEscritaRelatoriosAtas1 = new javax.swing.JMenu();
        menuProvaEscritaRelatoriosAtasAtaJulgamento1 = new javax.swing.JMenuItem();
        ataRealizacaoProvaEscrita = new javax.swing.JMenuItem();
        menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultado1 = new javax.swing.JMenuItem();
        itemMenuAtaInstalacaoComissao1 = new javax.swing.JMenuItem();
        parecerFinal = new javax.swing.JMenuItem();
        listaPresencaProvaEscrita = new javax.swing.JMenuItem();
        itemMenuTermosProvaEscrita1 = new javax.swing.JMenu();
        itemMenuTermosDesistenciaProvaEscrita1 = new javax.swing.JMenuItem();
        jMenu6 = new javax.swing.JMenu();
        reciboDocumentacaoPorCandidato1 = new javax.swing.JMenuItem();
        itemMenuAvaliacaoIndividualProvaEscrita = new javax.swing.JMenuItem();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenu4 = new javax.swing.JMenu();
        jMenu5 = new javax.swing.JMenu();
        jMenu7 = new javax.swing.JMenu();
        itemMenuAtaJulgamentoProvaTitulo = new javax.swing.JMenuItem();
        itemMenuReciboDevolucaoDocumentacao = new javax.swing.JMenuItem();
        menuProvaDidatica = new javax.swing.JMenu();
        menuProvaDidaticaRelatorios = new javax.swing.JMenu();
        menuProvaDidaticaRelatoriosAtas = new javax.swing.JMenu();
        menuProvaDidaticaRelatoriosAtaSessaoRealizacao = new javax.swing.JMenuItem();
        menuProvaDidaticaRelatoriosAtaDivulgacaoResutlado = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Área de Trabalho");

        javax.swing.GroupLayout areaTrabalhoLayout = new javax.swing.GroupLayout(areaTrabalho);
        areaTrabalho.setLayout(areaTrabalhoLayout);
        areaTrabalhoLayout.setHorizontalGroup(
            areaTrabalhoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        areaTrabalhoLayout.setVerticalGroup(
            areaTrabalhoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        jToolBar1.setRollover(true);

        javax.swing.tree.DefaultMutableTreeNode treeNode1 = new javax.swing.tree.DefaultMutableTreeNode("Concurso");
        javax.swing.tree.DefaultMutableTreeNode treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Prova Escrita");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Prova Didática");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Prova Titulo");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Prova Memorial");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Configurações");
        javax.swing.tree.DefaultMutableTreeNode treeNode3 = new javax.swing.tree.DefaultMutableTreeNode("Examinador");
        treeNode2.add(treeNode3);
        treeNode3 = new javax.swing.tree.DefaultMutableTreeNode("Candidato");
        treeNode2.add(treeNode3);
        treeNode3 = new javax.swing.tree.DefaultMutableTreeNode("Definir Pesos");
        treeNode2.add(treeNode3);
        treeNode3 = new javax.swing.tree.DefaultMutableTreeNode("Definir Cronograma");
        treeNode2.add(treeNode3);
        treeNode1.add(treeNode2);
        jTree1.setModel(new javax.swing.tree.DefaultTreeModel(treeNode1));
        jTree1.addTreeSelectionListener(new javax.swing.event.TreeSelectionListener() {
            public void valueChanged(javax.swing.event.TreeSelectionEvent evt) {
                jTree1ValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(jTree1);

        menuAbrirConcurso.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/abrir.png")));
        menuAbrirConcurso.setText("Abrir Concurso");

        itemMenuCadastro.setText("Cadastro");

        itemMenuCandidato.setText("Candidatos");
        itemMenuCandidato.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuCandidatoActionPerformed(evt);
            }
        });
        itemMenuCadastro.add(itemMenuCandidato);

        itemMenuExaminadores.setText("Examinadores");
        itemMenuExaminadores.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuExaminadoresActionPerformed(evt);
            }
        });
        itemMenuCadastro.add(itemMenuExaminadores);

        jMenuItem1.setText("Definir Pesos");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        itemMenuCadastro.add(jMenuItem1);

        jMenuItem3.setText("DefinirConograma");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        itemMenuCadastro.add(jMenuItem3);

        menuAbrirConcurso.add(itemMenuCadastro);

        jMenu1.setText("Relatorio");

        reciboDocumentacaoPorCandidato.setText("Recibo de documentação - por candidato");
        reciboDocumentacaoPorCandidato.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reciboDocumentacaoPorCandidatoActionPerformed(evt);
            }
        });
        jMenu1.add(reciboDocumentacaoPorCandidato);

        jMenuItem2.setText("Declaração de não impedimento - por membro de banca");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);

        jMenu3.setText("Atas");

        itemMenuAtaInstalacaoComissao.setText("Ata de Instalação da Comissão");
        itemMenuAtaInstalacaoComissao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuAtaInstalacaoComissaoActionPerformed(evt);
            }
        });
        jMenu3.add(itemMenuAtaInstalacaoComissao);

        menuAtaLista.setText("Ata Lista de Presença");
        menuAtaLista.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuAtaListaActionPerformed(evt);
            }
        });
        jMenu3.add(menuAtaLista);

        jMenu1.add(jMenu3);

        menuAbrirConcurso.add(jMenu1);

        jMenuBar1.add(menuAbrirConcurso);

        menuProvaEscrita1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/report.png")));
        menuProvaEscrita1.setText("Prova Escrita");

        menuProvaEscritaRelatorios1.setText("Relatórios");

        menuProvaEscritaRelatoriosAtas1.setText("Atas");

        menuProvaEscritaRelatoriosAtasAtaJulgamento1.setText("Ata Julgamento");
        menuProvaEscritaRelatoriosAtasAtaJulgamento1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuProvaEscritaRelatoriosAtasAtaJulgamentoActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(menuProvaEscritaRelatoriosAtasAtaJulgamento1);

        ataRealizacaoProvaEscrita.setText("Ata de Realização da Prova Escrita");
        ataRealizacaoProvaEscrita.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ataRealizacaoProvaEscritaActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(ataRealizacaoProvaEscrita);

        menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultado1.setText("Ata da Sessão de Divulgação do Resultado");
        menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultado1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultadoActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultado1);

        itemMenuAtaInstalacaoComissao1.setText("Ata de Instalação da Comissão");
        itemMenuAtaInstalacaoComissao1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuAtaInstalacaoComissaoActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(itemMenuAtaInstalacaoComissao1);

        parecerFinal.setText("Parecer Final da Banca Examinadora");
        parecerFinal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                parecerFinalActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(parecerFinal);
        listaPresencaProvaEscrita.setText("Lista de Presença na Prova de Defesa de Memorial de Trajetória Acadêmica");
        listaPresencaProvaEscrita.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                listaPresencaProvaEscritaActionPerformed(evt);
            }
        });
        menuProvaEscritaRelatoriosAtas1.add(listaPresencaProvaEscrita);

        menuProvaEscritaRelatorios1.add(menuProvaEscritaRelatoriosAtas1);

        itemMenuTermosProvaEscrita1.setText("Termos");

        itemMenuTermosDesistenciaProvaEscrita1.setText("Termo de Desistência do Prazo Recursal da Nota Final");
        itemMenuTermosDesistenciaProvaEscrita1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuTermosDesistenciaProvaEscritaActionPerformed(evt);
            }
        });
        itemMenuTermosProvaEscrita1.add(itemMenuTermosDesistenciaProvaEscrita1);

        menuProvaEscritaRelatorios1.add(itemMenuTermosProvaEscrita1);

        jMenu6.setText("Relatórios");

        reciboDocumentacaoPorCandidato1.setText("Recibo de documentação - por candidato");
        reciboDocumentacaoPorCandidato1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reciboDocumentacaoPorCandidatoActionPerformed(evt);
            }
        });
        jMenu6.add(reciboDocumentacaoPorCandidato1);

        itemMenuAvaliacaoIndividualProvaEscrita.setText("Avaliação Individual Prova Escrita");
        itemMenuAvaliacaoIndividualProvaEscrita.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuAvaliacaoIndividualProvaEscritaActionPerformed(evt);
            }
        });
        jMenu6.add(itemMenuAvaliacaoIndividualProvaEscrita);

        jMenuItem4.setText("Planilha de Critérios de Avaliação da Prova Escrita");
        jMenuItem4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem4ActionPerformed(evt);
            }
        });
        jMenu6.add(jMenuItem4);

        menuProvaEscritaRelatorios1.add(jMenu6);

        menuProvaEscrita1.add(menuProvaEscritaRelatorios1);

        jMenuBar1.add(menuProvaEscrita1);

        jMenu4.setText("Prova Titulo");

        jMenu5.setText("Relatórios");

        jMenu7.setText("Atas");

        itemMenuAtaJulgamentoProvaTitulo.setText("Ata de Julgamento da Prova de Títulos");
        itemMenuAtaJulgamentoProvaTitulo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuAtaJulgamentoProvaTituloActionPerformed(evt);
            }
        });
        jMenu7.add(itemMenuAtaJulgamentoProvaTitulo);

        jMenu5.add(jMenu7);

        itemMenuReciboDevolucaoDocumentacao.setText("Recibo Devolução de Documentação");
        itemMenuReciboDevolucaoDocumentacao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                itemMenuReciboDevolucaoDocumentacaoActionPerformed(evt);
            }
        });
        jMenu5.add(itemMenuReciboDevolucaoDocumentacao);

        jMenu4.add(jMenu5);

        jMenuBar1.add(jMenu4);

        menuProvaDidatica.setText("Prova Didática");

        menuProvaDidaticaRelatorios.setText("Relatórios");

        menuProvaDidaticaRelatoriosAtas.setText("Atas");

        menuProvaDidaticaRelatoriosAtaSessaoRealizacao.setText("Sessão de Realização");
        menuProvaDidaticaRelatoriosAtaSessaoRealizacao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuProvaDidaticaRelatoriosAtaSessaoRealizacaoActionPerformed(evt);
            }
        });
        menuProvaDidaticaRelatoriosAtas.add(menuProvaDidaticaRelatoriosAtaSessaoRealizacao);

        menuProvaDidaticaRelatoriosAtaDivulgacaoResutlado.setText("Sessão de Divulgação do Resultado");
        menuProvaDidaticaRelatoriosAtaDivulgacaoResutlado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menuProvaDidaticaRelatoriosAtaDivulgacaoResutladoActionPerformed(evt);
            }
        });
        menuProvaDidaticaRelatoriosAtas.add(menuProvaDidaticaRelatoriosAtaDivulgacaoResutlado);

        menuProvaDidaticaRelatorios.add(menuProvaDidaticaRelatoriosAtas);

        menuProvaDidatica.add(menuProvaDidaticaRelatorios);

        jMenuBar1.add(menuProvaDidatica);

        jMenu2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/sobre.png")));
        jMenu2.setText("Sobre");
        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jToolBar1, javax.swing.GroupLayout.DEFAULT_SIZE, 782, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 188, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(areaTrabalho))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(jToolBar1, javax.swing.GroupLayout.PREFERRED_SIZE, 15, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 479, Short.MAX_VALUE)
                    .addComponent(areaTrabalho)))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void itemMenuCandidatoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuCandidatoActionPerformed
        criarCadastroCandidato();
    }//GEN-LAST:event_itemMenuCandidatoActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        criarDefinirPesos();
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
        criarDefinirConograma();
    }//GEN-LAST:event_jMenuItem3ActionPerformed

    private void itemMenuExaminadoresActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuExaminadoresActionPerformed
        criarCadastroExaminador();
    }//GEN-LAST:event_itemMenuExaminadoresActionPerformed

//</editor-fold>
    private void itemMenuAtaInstalacaoComissaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuAtaInstalacaoComissaoActionPerformed
        criarRelatorioAtaInstalacaoComissao();
    }//GEN-LAST:event_itemMenuAtaInstalacaoComissaoActionPerformed

    private void menuProvaEscritaRelatoriosAtasAtaJulgamentoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuProvaEscritaRelatoriosAtasAtaJulgamentoActionPerformed
        criarRelatorioAtaJulgamentoProvaEscrita();
    }//GEN-LAST:event_menuProvaEscritaRelatoriosAtasAtaJulgamentoActionPerformed

    private void reciboDocumentacaoPorCandidatoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reciboDocumentacaoPorCandidatoActionPerformed
        criarReciboDocCandidatos();
    }//GEN-LAST:event_reciboDocumentacaoPorCandidatoActionPerformed

    private void menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultadoActionPerformed
        criarRelatorioAtaSessaoDivulgacaoResultadoProvaEscrita();
    }//GEN-LAST:event_menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultadoActionPerformed

    private void itemMenuTermosDesistenciaProvaEscritaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuTermosDesistenciaProvaEscritaActionPerformed
        criarRelatorioTermoDesistenciaPrazoRecursalNotaFinalProvaEscrita();
    }//GEN-LAST:event_itemMenuTermosDesistenciaProvaEscritaActionPerformed

    private void itemMenuAvaliacaoIndividualProvaEscritaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuAvaliacaoIndividualProvaEscritaActionPerformed
        criarRelatorioAvaliacaoIndividualProvaEscrita();
    }//GEN-LAST:event_itemMenuAvaliacaoIndividualProvaEscritaActionPerformed

    private void itemMenuAtaJulgamentoProvaTituloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuAtaJulgamentoProvaTituloActionPerformed
        criarRelatorioAtaJulgamentoProvaTitulo();
    }//GEN-LAST:event_itemMenuAtaJulgamentoProvaTituloActionPerformed

    private void itemMenuReciboDevolucaoDocumentacaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_itemMenuReciboDevolucaoDocumentacaoActionPerformed
        criarRelatorioReciboDevolucaoDocumentacaoProvaTitulo();
    }//GEN-LAST:event_itemMenuReciboDevolucaoDocumentacaoActionPerformed

    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
        criarDeclaracaoNaoImpedimentoMembros();
    }//GEN-LAST:event_jMenuItem2ActionPerformed

    private void jTree1ValueChanged(javax.swing.event.TreeSelectionEvent evt) {//GEN-FIRST:event_jTree1ValueChanged
        switch (evt.getPath().getLastPathComponent() + "") {
            case "Candidato":
                criarCadastroCandidato();
                break;
            case "Examinador":
                criarCadastroExaminador();
                break;
            case "Definir Pesos":
                criarDefinirPesos();
                break;
            case "Definir Cronograma":
                criarDefinirConograma();
                break;
        }
    }//GEN-LAST:event_jTree1ValueChanged

    private void menuProvaDidaticaRelatoriosAtaDivulgacaoResutladoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuProvaDidaticaRelatoriosAtaDivulgacaoResutladoActionPerformed
        criarAtaSessaoDivulgacaoResultadoProvaDidatica();
    }//GEN-LAST:event_menuProvaDidaticaRelatoriosAtaDivulgacaoResutladoActionPerformed

    private void menuProvaDidaticaRelatoriosAtaSessaoRealizacaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuProvaDidaticaRelatoriosAtaSessaoRealizacaoActionPerformed
        criarAtaSessaoRealizacaoProvaDidatica();
    }//GEN-LAST:event_menuProvaDidaticaRelatoriosAtaSessaoRealizacaoActionPerformed

    private void menuAtaListaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menuAtaListaActionPerformed
        // TODO add your handling code here:
        criarAtaListaPresenca();

    }//GEN-LAST:event_menuAtaListaActionPerformed
    private void jMenuItem4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem4ActionPerformed
        criarPlanilhaCriterioAvaliacaoProvaEscrita();
    }//GEN-LAST:event_jMenuItem4ActionPerformed

    private void ataRealizacaoProvaEscritaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ataRealizacaoProvaEscritaActionPerformed
        //criarAtaRealizacaoProvaEscrita();
    }//GEN-LAST:event_ataRealizacaoProvaEscritaActionPerformed

    private void parecerFinalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_parecerFinalActionPerformed
        criarParecerFinalDaBancaExaminadora();
    }//GEN-LAST:event_parecerFinalActionPerformed

    private void listaPresencaProvaEscritaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_listaPresencaProvaEscritaActionPerformed
        //criarListaPresencaProvaDeDefesaMemorialTrajetoriaAcademica();
    }//GEN-LAST:event_listaPresencaProvaEscritaActionPerformed

//</editor-fold>
    //<editor-fold defaultstate="collapsed" desc="Inicio">
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Session session = HibernateUtil.openSession();
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            UIManager.setLookAndFeel(new NimbusLookAndFeel());

        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AreaTrabalho.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                AreaTrabalho areaTrabalho = new AreaTrabalho();
                areaTrabalho.setVisible(true);
                SelecaoConcurso selecaoConcurso = new SelecaoConcurso(areaTrabalho, true);
                selecaoConcurso.setVisible(true);
                selecaoConcurso.setLocationRelativeTo(null);
            }
        });
    }
//</editor-fold>

    //<editor-fold defaultstate="collapsed" desc="Adicionar Janelas">
    private void adicionarJanela(final JInternalFrame frame) {
        areaTrabalho.add(frame);
        frame.setVisible(true);
        try {
            frame.setMaximum(true);
        } catch (PropertyVetoException ex) {
            Logger.getLogger(AreaTrabalho.class.getName()).log(Level.SEVERE, null, ex);
        }
        frame.setIconifiable(true);
        frame.setClosable(true);
        frame.setMaximizable(true);
        frame.setResizable(true);
    }

    private void criarCadastroCandidato() {
        CadastroCandidato cadastroCandidato = new CadastroCandidato();
        adicionarJanela(cadastroCandidato);
    }

    private void criarDefinirPesos() {
        DefinirPesoProvasConcurso definirPesoProvasConcurso = new DefinirPesoProvasConcurso();
        adicionarJanela(definirPesoProvasConcurso);
    }

    private void criarDefinirConograma() {
        DefinirCronograma definirConograma = new DefinirCronograma();
        adicionarJanela(definirConograma);
    }

    private void criarCadastroExaminador() {
        CadastroExaminador cadastroExaminadores = new CadastroExaminador();
        adicionarJanela(cadastroExaminadores);
    }

    private void criarRelatorioAtaInstalacaoComissao() {
        AtaComissao ataComissao = new AtaComissao();
        ataComissao.setVisible(true);
    }

    private void criarRelatorioAtaJulgamentoProvaEscrita() {
        RelProvaEscritaAtaJulgamento relProvaEscritaAtaJulgamento = new RelProvaEscritaAtaJulgamento();
        adicionarJanela(relProvaEscritaAtaJulgamento);
    }

    private void criarRelatorioAtaSessaoDivulgacaoResultadoProvaEscrita() {
        RelPEAtaSessaoDivulgacaoResultado relPEAtaSessaoDivulgacaoResultado = new RelPEAtaSessaoDivulgacaoResultado();
        adicionarJanela(relPEAtaSessaoDivulgacaoResultado);
    }

    private void criarReciboDocCandidatos() {
        ReciboDocumentacaoPorCandidato reciboDocumentacaoPorCandidato = new ReciboDocumentacaoPorCandidato();
        adicionarJanela(reciboDocumentacaoPorCandidato);
    }

    private void criarDeclaracaoNaoImpedimentoMembros() {
        RelDeclaracaoNaoImpedimentoPorMembroBanca declaracao = new RelDeclaracaoNaoImpedimentoPorMembroBanca();
        adicionarJanela(declaracao);
    }

    private void criarAtaSessaoDivulgacaoResultadoProvaDidatica() {
//        RelAtaSessaoDivulgacaoResultadoProvaDidatica divulgacaoResultado = new RelAtaSessaoDivulgacaoResultadoProvaDidatica();
//        adicionarJanela(divulgacaoResultado);
    }

    private void criarAtaSessaoRealizacaoProvaDidatica() {
        RelAtaSessaoRealizacaoProvaDidatica relAtaSessaoRealizacaoProvaDidatica = new RelAtaSessaoRealizacaoProvaDidatica();
        adicionarJanela(relAtaSessaoRealizacaoProvaDidatica);
    }

    private void criarRelatorioTermoDesistenciaPrazoRecursalNotaFinalProvaEscrita() {
        RelTermoDesistenciaProvaEscrita termoDesistenciaProvaEscrita = new RelTermoDesistenciaProvaEscrita();
        adicionarJanela(termoDesistenciaProvaEscrita);
    }

    private void criarRelatorioAvaliacaoIndividualProvaEscrita() {
        RelAvaliacaoIndividualProvaEscrita relAvaliacaoIndividualProvaEscrita = new RelAvaliacaoIndividualProvaEscrita();
        adicionarJanela(relAvaliacaoIndividualProvaEscrita);
    }
	
    private void criarPlanilhaCriterioAvaliacaoProvaEscrita() {
        RelPlanilhaCriteriosAvaliacaoProvaEscrita relatorio = new RelPlanilhaCriteriosAvaliacaoProvaEscrita();
        adicionarJanela(relatorio);
    }

    private void criarRelatorioAtaJulgamentoProvaTitulo() {
        RelAtaJulgamentoProvaTitulo relAtaJulgamentoProvaTitulo = new RelAtaJulgamentoProvaTitulo();
        adicionarJanela(relAtaJulgamentoProvaTitulo);
    }

    private void criarAtaListaPresenca() {
        AtaListaPresencaNovo ata = new AtaListaPresencaNovo();
        adicionarJanela(ata);
    }

    private void criarRelatorioReciboDevolucaoDocumentacaoProvaTitulo() {
        RelReciboDevolucaoDocumentacaoProvaTitulo relReciboDevolucaoDocumentacaoProvaTitulo = new RelReciboDevolucaoDocumentacaoProvaTitulo();
        adicionarJanela(relReciboDevolucaoDocumentacaoProvaTitulo);
    }

    private void criarParecerFinalDaBancaExaminadora() {
        ParecerFinalBancaExaminadora parecerFinal = new ParecerFinalBancaExaminadora();
        adicionarJanela(parecerFinal);
    }
//</editor-fold>
    //<editor-fold defaultstate="collapsed" desc="Variaveis">
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JDesktopPane areaTrabalho;
    private javax.swing.JMenuItem ataRealizacaoProvaEscrita;
    private javax.swing.JMenuItem itemMenuAtaInstalacaoComissao;
    private javax.swing.JMenuItem itemMenuAtaInstalacaoComissao1;
    private javax.swing.JMenuItem itemMenuAtaJulgamentoProvaTitulo;
    private javax.swing.JMenuItem itemMenuAvaliacaoIndividualProvaEscrita;
    private javax.swing.JMenu itemMenuCadastro;
    private javax.swing.JMenuItem itemMenuCandidato;
    private javax.swing.JMenuItem itemMenuExaminadores;
    private javax.swing.JMenuItem itemMenuReciboDevolucaoDocumentacao;
    private javax.swing.JMenuItem itemMenuTermosDesistenciaProvaEscrita1;
    private javax.swing.JMenu itemMenuTermosProvaEscrita1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenu jMenu4;
    private javax.swing.JMenu jMenu5;
    private javax.swing.JMenu jMenu6;
    private javax.swing.JMenu jMenu7;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;

    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JTree jTree1;
    private javax.swing.JMenuItem listaPresencaProvaEscrita;
    private javax.swing.JMenu menuAbrirConcurso;

    private javax.swing.JMenu menuProvaDidatica;
    private javax.swing.JMenu menuProvaDidaticaRelatorios;
    private javax.swing.JMenuItem menuProvaDidaticaRelatoriosAtaDivulgacaoResutlado;
    private javax.swing.JMenuItem menuProvaDidaticaRelatoriosAtaSessaoRealizacao;
    private javax.swing.JMenu menuProvaDidaticaRelatoriosAtas;

    private javax.swing.JMenuItem menuAtaLista;

    private javax.swing.JMenu menuProvaEscrita1;
    private javax.swing.JMenu menuProvaEscritaRelatorios1;
    private javax.swing.JMenu menuProvaEscritaRelatoriosAtas1;
    private javax.swing.JMenuItem menuProvaEscritaRelatoriosAtasAtaJulgamento1;
    private javax.swing.JMenuItem menuProvaEscritaRelatoriosAtasAtaSessaoDivulgacaoResultado1;
    private javax.swing.JMenuItem parecerFinal;
    private javax.swing.JMenuItem reciboDocumentacaoPorCandidato;
    private javax.swing.JMenuItem reciboDocumentacaoPorCandidato1;
    // End of variables declaration//GEN-END:variables
//</editor-fold>
}
