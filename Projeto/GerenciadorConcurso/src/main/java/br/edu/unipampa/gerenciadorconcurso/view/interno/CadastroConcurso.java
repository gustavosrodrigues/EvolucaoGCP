/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.interno;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.service.ConcursoService;
import br.edu.unipampa.gerenciadorconcurso.validator.Campos;
import br.edu.unipampa.gerenciadorconcurso.validator.ComboBoxFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.Data;
import br.edu.unipampa.gerenciadorconcurso.validator.FieldFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.FormattedFieldFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.StatusCadastros;
import javax.swing.JFormattedTextField;
import javax.swing.JOptionPane;

/**
 *
 * @author Douglas
 */
public class CadastroConcurso extends javax.swing.JDialog {

    private Campos tratamentoCampos;
    private StatusCadastros status;
    private ConcursoService concursoService;
    private Concurso concurso;

    public CadastroConcurso(javax.swing.JDialog parent, boolean modal) {
        super(parent, modal);
        initComponents();
        tratamentoCampos = new Campos();
        concursoService = new ConcursoService();
        repassarCampos();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jToolBar1 = new javax.swing.JToolBar();
        btNovo = new javax.swing.JButton();
        btEditar = new javax.swing.JButton();
        btSalvar = new javax.swing.JButton();
        btDeletar = new javax.swing.JButton();
        textCodigo = new javax.swing.JLabel();
        campoCodigo = new javax.swing.JTextField();
        textMinisterio = new javax.swing.JLabel();
        campoMinisterio = new javax.swing.JTextField();
        boxClasse = new javax.swing.JComboBox();
        textClasseConcurso = new javax.swing.JLabel();
        textDataInicio = new javax.swing.JLabel();
        campoDataInicio = new JFormattedTextField(Campos.createFormatter("##-##-####"));
        ;
        campoMensagem = new javax.swing.JTextField();
        textUniversidade = new javax.swing.JLabel();
        campoUniversidade = new javax.swing.JTextField();
        textCampus = new javax.swing.JLabel();
        campoCampus = new javax.swing.JTextField();
        textArea = new javax.swing.JLabel();
        campoArea = new javax.swing.JTextField();
        textEdital = new javax.swing.JLabel();
        campoEdital = new javax.swing.JTextField();
        txtAlertUniversidade = new javax.swing.JLabel();
        txtAlertMinisterio = new javax.swing.JLabel();
        txtAlertCampus = new javax.swing.JLabel();
        txtAlertArea = new javax.swing.JLabel();
        txtAlertEdital = new javax.swing.JLabel();
        txtAlertDataInicio = new javax.swing.JLabel();

        setTitle("Cadastro Candidato");

        jToolBar1.setRollover(true);

        btNovo.setText("Novo");
        btNovo.setFocusable(false);
        btNovo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btNovo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btNovo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btNovoActionPerformed(evt);
            }
        });
        jToolBar1.add(btNovo);
        btNovo.setVisible(false);

        btEditar.setText("Editar");
        btEditar.setFocusable(false);
        btEditar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btEditar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btEditar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btEditarActionPerformed(evt);
            }
        });
        jToolBar1.add(btEditar);
        btEditar.setVisible(false);

        btSalvar.setText("Salvar");
        btSalvar.setFocusable(false);
        btSalvar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btSalvar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btSalvar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btSalvarActionPerformed(evt);
            }
        });
        jToolBar1.add(btSalvar);

        btDeletar.setText("Deletar");
        btDeletar.setFocusable(false);
        btDeletar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btDeletar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btDeletar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btDeletarActionPerformed(evt);
            }
        });
        jToolBar1.add(btDeletar);
        btDeletar.setVisible(false);

        textCodigo.setText("Código");

        campoCodigo.setEditable(false);
        campoCodigo.setText("0");
        campoCodigo.setEnabled(false);
        campoCodigo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoCodigoActionPerformed(evt);
            }
        });

        textMinisterio.setText("Ministério");

        campoMinisterio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoMinisterioActionPerformed(evt);
            }
        });

        boxClasse.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Adjunto", "Assistente", "Magistério", "Auxiliar", "Substituto", "Temporário" }));
        boxClasse.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                boxClasseActionPerformed(evt);
            }
        });

        textClasseConcurso.setText("Classe do Concurso");

        textDataInicio.setText("Data de Início");

        campoDataInicio.setRequestFocusEnabled(false);
        campoDataInicio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoDataInicioActionPerformed(evt);
            }
        });

        campoMensagem.setEditable(false);

        textUniversidade.setText("Universidade");

        campoUniversidade.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoUniversidadeActionPerformed(evt);
            }
        });

        textCampus.setText("Campus");

        textArea.setText("Area");

        textEdital.setText("Edital");

        txtAlertUniversidade.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertUniversidade.setText("!!!!");
        txtAlertUniversidade.setToolTipText("Campo nome é obrigatorio.");

        txtAlertMinisterio.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertMinisterio.setText("!!!!");
        txtAlertMinisterio.setToolTipText("Campo nome é obrigatorio.");

        txtAlertCampus.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertCampus.setText("!!!!");
        txtAlertCampus.setToolTipText("Campo nome é obrigatorio.");

        txtAlertArea.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertArea.setText("!!!!");
        txtAlertArea.setToolTipText("Campo nome é obrigatorio.");

        txtAlertEdital.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertEdital.setText("!!!!");
        txtAlertEdital.setToolTipText("Campo nome é obrigatorio.");

        txtAlertDataInicio.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertDataInicio.setText("!!!!");
        txtAlertDataInicio.setToolTipText("Campo nome é obrigatorio.");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jToolBar1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(campoMensagem)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(textCodigo)
                            .addComponent(textMinisterio)
                            .addComponent(textUniversidade)
                            .addComponent(textArea)
                            .addComponent(textCampus)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(87, 87, 87)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(campoCampus, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(txtAlertCampus))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(campoArea, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(txtAlertArea))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(campoUniversidade, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(txtAlertUniversidade))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(campoMinisterio, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(txtAlertMinisterio))
                            .addComponent(campoCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(textEdital)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(textDataInicio)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(11, 11, 11)
                                        .addComponent(campoEdital, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(campoDataInicio, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(txtAlertDataInicio)))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtAlertEdital))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(textClasseConcurso)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(boxClasse, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(79, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jToolBar1, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(1, 1, 1)
                .addComponent(campoMensagem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textCodigo)
                    .addComponent(campoCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textMinisterio)
                    .addComponent(campoMinisterio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtAlertMinisterio))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textUniversidade)
                    .addComponent(campoUniversidade, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtAlertUniversidade))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textCampus)
                    .addComponent(campoCampus, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtAlertCampus))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textArea)
                    .addComponent(campoArea, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtAlertArea))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textEdital)
                    .addComponent(campoEdital, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(txtAlertEdital))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(campoDataInicio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(textDataInicio)
                    .addComponent(txtAlertDataInicio))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textClasseConcurso)
                    .addComponent(boxClasse, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(44, Short.MAX_VALUE))
        );

        txtAlertUniversidade.setVisible(false);
        txtAlertMinisterio.setVisible(false);
        txtAlertCampus.setVisible(false);
        txtAlertArea.setVisible(false);
        txtAlertEdital.setVisible(false);
        txtAlertDataInicio.setVisible(false);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSalvarActionPerformed
        if (tratamentoCampos.validaObrigatorios()) {
            Concurso novoConcurso = new Concurso();
            if (status.getStatus().equals("editar")) {
                novoConcurso.setCodigo(Integer.parseInt(campoCodigo.getText()));
            }
            novoConcurso.setMinisterio(campoMinisterio.getText());
            novoConcurso.setUniversidade(campoUniversidade.getText());
            novoConcurso.setCampus(campoCampus.getText());
            novoConcurso.setArea(campoArea.getText());
            novoConcurso.setEdital(campoEdital.getText());
            novoConcurso.setDataInicio(Data.converteData(campoDataInicio.getText()));
            novoConcurso.setClasse(boxClasse.getSelectedItem().toString());

            if (concursoService.salvar(novoConcurso)) {
                status.setStatus("salvar");
                campoCodigo.setText(novoConcurso.getCodigo() + "");
                campoMensagem.setText("Concurso salvo com sucesso!");
                btNovo.setVisible(true);
                btEditar.setVisible(true);
                btDeletar.setVisible(true);
                btSalvar.setVisible(false);
            } else {
                campoMensagem.setText("Ocorreu um erro ao salvar o concurso!");
            }
        }
    }//GEN-LAST:event_btSalvarActionPerformed

    private void btDeletarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btDeletarActionPerformed
        if (JOptionPane.showConfirmDialog(null, "Você deseja realmente deletar o registro?") == JOptionPane.OK_OPTION) {
            if (concursoService.deletar(Campos.converteNumero(campoCodigo.getText()))) {
                campoMensagem.setText("O registro foi deletado com sucesso!");
                status.setStatus("incluir");
            } else {
                campoMensagem.setText("Ocorreu um problema ao deletar o registro!");
            }
        }
    }//GEN-LAST:event_btDeletarActionPerformed

    private void campoDataInicioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoDataInicioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoDataInicioActionPerformed

    private void campoCodigoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoCodigoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoCodigoActionPerformed

    private void campoMinisterioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoMinisterioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoMinisterioActionPerformed

    private void campoUniversidadeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoUniversidadeActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoUniversidadeActionPerformed

    private void boxClasseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_boxClasseActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_boxClasseActionPerformed

    private void btEditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEditarActionPerformed
        status.setStatus("editar");
    }//GEN-LAST:event_btEditarActionPerformed

    private void btNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btNovoActionPerformed
        status.setStatus("incluir");
    }//GEN-LAST:event_btNovoActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox boxClasse;
    private javax.swing.JButton btDeletar;
    private javax.swing.JButton btEditar;
    private javax.swing.JButton btNovo;
    private javax.swing.JButton btSalvar;
    private javax.swing.JTextField campoArea;
    private javax.swing.JTextField campoCampus;
    private javax.swing.JTextField campoCodigo;
    private javax.swing.JFormattedTextField campoDataInicio;
    private javax.swing.JTextField campoEdital;
    private javax.swing.JTextField campoMensagem;
    private javax.swing.JTextField campoMinisterio;
    private javax.swing.JTextField campoUniversidade;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JLabel textArea;
    private javax.swing.JLabel textCampus;
    private javax.swing.JLabel textClasseConcurso;
    private javax.swing.JLabel textCodigo;
    private javax.swing.JLabel textDataInicio;
    private javax.swing.JLabel textEdital;
    private javax.swing.JLabel textMinisterio;
    private javax.swing.JLabel textUniversidade;
    private javax.swing.JLabel txtAlertArea;
    private javax.swing.JLabel txtAlertCampus;
    private javax.swing.JLabel txtAlertDataInicio;
    private javax.swing.JLabel txtAlertEdital;
    private javax.swing.JLabel txtAlertMinisterio;
    private javax.swing.JLabel txtAlertUniversidade;
    // End of variables declaration//GEN-END:variables

    private void repassarCampos() {
        tratamentoCampos.setCampo(new FieldFormat(campoMinisterio, txtAlertMinisterio, true));
        tratamentoCampos.setCampo(new FieldFormat(campoUniversidade, txtAlertUniversidade, true));
        tratamentoCampos.setCampo(new FieldFormat(campoCampus, txtAlertCampus, true));
        tratamentoCampos.setCampo(new FieldFormat(campoArea, txtAlertArea, true));
        tratamentoCampos.setCampo(new FieldFormat(campoEdital, txtAlertEdital, true));
        tratamentoCampos.setCampo(new FormattedFieldFormat(campoDataInicio, txtAlertDataInicio, true));
        tratamentoCampos.setCampo(new ComboBoxFormat(boxClasse));

        status = new StatusCadastros(btNovo, btEditar, btDeletar, btSalvar, campoCodigo, campoMensagem, tratamentoCampos);
    }
}
