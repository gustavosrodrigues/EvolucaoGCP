/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.interno;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Pessoa;
import br.edu.unipampa.gerenciadorconcurso.service.CandidatoService;
import br.edu.unipampa.gerenciadorconcurso.validator.Campos;
import br.edu.unipampa.gerenciadorconcurso.validator.ComboBoxFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.Data;
import br.edu.unipampa.gerenciadorconcurso.validator.FieldFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.FormattedFieldFormat;
import br.edu.unipampa.gerenciadorconcurso.validator.StatusCadastros;
import javax.swing.JFormattedTextField;

/**
 *
 * @author Douglas
 */
public class CadastroCandidato extends javax.swing.JInternalFrame {
    private Campos tratamentoCampos;
    private StatusCadastros status;
    private CandidatoService candidatoService;
    private Candidato candidato;
    
    /**
     * Creates new form CadastroCandidato
     */
    public CadastroCandidato() {
        initComponents();
        tratamentoCampos = new Campos();
        candidatoService = new CandidatoService();
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
        btBuscar = new javax.swing.JButton();
        textCodigo = new javax.swing.JLabel();
        campoCodigo = new javax.swing.JTextField();
        textNome = new javax.swing.JLabel();
        campoNome = new javax.swing.JTextField();
        boxSexo = new javax.swing.JComboBox();
        textSexo = new javax.swing.JLabel();
        textNascimento = new javax.swing.JLabel();
        campoNascimento = new JFormattedTextField(Campos.createFormatter("##-##-####"));
        ;
        txtAlertNome = new javax.swing.JLabel();
        txtAlertNascimento = new javax.swing.JLabel();
        campoMensagem = new javax.swing.JTextField();

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

        btBuscar.setText("Buscar");
        btBuscar.setFocusable(false);
        btBuscar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btBuscar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btBuscarActionPerformed(evt);
            }
        });
        jToolBar1.add(btBuscar);

        textCodigo.setText("Código");

        campoCodigo.setEditable(false);
        campoCodigo.setText("0");

        textNome.setText("Nome");

        boxSexo.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Masculino", "Feminino" }));

        textSexo.setText("Sexo");

        textNascimento.setText("Nascimento");

        txtAlertNome.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertNome.setText("!!!!");
        txtAlertNome.setToolTipText("Campo nome é obrigatorio.");

        txtAlertNascimento.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertNascimento.setText("!!!!");
        txtAlertNascimento.setToolTipText("Campo nome é obrigatorio.");

        campoMensagem.setEditable(false);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jToolBar1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addGap(17, 17, 17)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(textNascimento)
                    .addComponent(textNome)
                    .addComponent(textCodigo)
                    .addComponent(textSexo))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(campoCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, 90, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(campoNome, javax.swing.GroupLayout.PREFERRED_SIZE, 345, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtAlertNome))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(boxSexo, javax.swing.GroupLayout.Alignment.LEADING, 0, 120, Short.MAX_VALUE)
                            .addComponent(campoNascimento, javax.swing.GroupLayout.Alignment.LEADING))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(txtAlertNascimento)))
                .addContainerGap(90, Short.MAX_VALUE))
            .addComponent(campoMensagem)
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
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(txtAlertNome, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(textNome)
                        .addComponent(campoNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(boxSexo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(textSexo))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(campoNascimento, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(txtAlertNascimento, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(textNascimento)))
        );

        txtAlertNome.setVisible(false);
        txtAlertNome.setVisible(false);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btNovoActionPerformed
        status.estadoNovo();
    }//GEN-LAST:event_btNovoActionPerformed

    private void btSalvarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btSalvarActionPerformed
        if(tratamentoCampos.validaObrigatorios()){
            candidato = new Candidato();
            Pessoa pessoa = new Pessoa();
            pessoa.setNome(campoNome.getText());
            if(boxSexo.getSelectedIndex() == 0){
                pessoa.setSexo(true);
            }
            candidato.setDataNacimento(Data.converteData(campoNascimento.getText()));
            candidato.setCodigo(Integer.parseInt(campoCodigo.getText()));
            Concurso concurso = new Concurso();
            concurso.setCodigo(1);
            candidato.setConcurso(concurso);
            if(candidatoService.salvar(candidato)){
                status.estadoSalvo();
                campoMensagem.setText("Candidato salvo com sucesso!");
            } else {
                campoMensagem.setText("Ocorreu um erro ao salvar o candidato!");
            }
        }
    }//GEN-LAST:event_btSalvarActionPerformed

    private void btDeletarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btDeletarActionPerformed
        status.estadoNovo();
    }//GEN-LAST:event_btDeletarActionPerformed

    private void btBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btBuscarActionPerformed
        status.estadoSalvo();
    }//GEN-LAST:event_btBuscarActionPerformed

    private void btEditarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btEditarActionPerformed
        status.estadoAlterando();
    }//GEN-LAST:event_btEditarActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox boxSexo;
    private javax.swing.JButton btBuscar;
    private javax.swing.JButton btDeletar;
    private javax.swing.JButton btEditar;
    private javax.swing.JButton btNovo;
    private javax.swing.JButton btSalvar;
    private javax.swing.JTextField campoCodigo;
    private javax.swing.JTextField campoMensagem;
    private javax.swing.JFormattedTextField campoNascimento;
    private javax.swing.JTextField campoNome;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JLabel textCodigo;
    private javax.swing.JLabel textNascimento;
    private javax.swing.JLabel textNome;
    private javax.swing.JLabel textSexo;
    private javax.swing.JLabel txtAlertNascimento;
    private javax.swing.JLabel txtAlertNome;
    // End of variables declaration//GEN-END:variables

    private void repassarCampos(){
        tratamentoCampos.setCampo(new FormattedFieldFormat(campoNascimento, txtAlertNascimento, true));
        tratamentoCampos.setCampo(new ComboBoxFormat(boxSexo));
        tratamentoCampos.setCampo(new FieldFormat(campoNome, txtAlertNome, true));
        
        status = new StatusCadastros(btNovo, btDeletar, btSalvar, btSalvar, campoCodigo, campoMensagem, tratamentoCampos);
    }
}
