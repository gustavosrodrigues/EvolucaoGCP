/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.interno;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.validator.Campos;
import br.edu.unipampa.gerenciadorconcurso.validator.FormattedFieldFormat;
import br.edu.unipampa.gerenciadorconcurso.view.reports.GeradorRelatorios;
import br.edu.unipampa.gerenciadorconcurso.view.reports.Parametro;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import javax.swing.JFormattedTextField;

/**
 *
 * @author Douglas
 */
public class ReciboDocumentacaoPorCandidato extends javax.swing.JInternalFrame {

    private Campos tratamentoCampos;

    /**
     * Creates new form CadastroCandidato
     */
    public ReciboDocumentacaoPorCandidato() {
        initComponents();
        tratamentoCampos = new Campos();
        tratamentoCampos.setCampo(new FormattedFieldFormat(campoData, txtAlertData, true));
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
        textNascimento = new javax.swing.JLabel();
        campoMensagem = new javax.swing.JTextField();
        txtAlertData = new javax.swing.JLabel();
        campoData = new JFormattedTextField(Campos.createFormatter("##-##-####"));
        ;

        setTitle("Recibos de documentação - por candidato");

        jToolBar1.setRollover(true);

        btNovo.setText("Gerar Recibo");
        btNovo.setFocusable(false);
        btNovo.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btNovo.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btNovo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btNovoActionPerformed(evt);
            }
        });
        jToolBar1.add(btNovo);

        textNascimento.setText("Data");

        campoMensagem.setEditable(false);

        txtAlertData.setBackground(new java.awt.Color(102, 0, 0));
        txtAlertData.setText("!!!!");
        txtAlertData.setToolTipText("Campo nome é obrigatorio.");

        campoData.setToolTipText("");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jToolBar1, javax.swing.GroupLayout.DEFAULT_SIZE, 531, Short.MAX_VALUE)
            .addComponent(campoMensagem)
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addComponent(textNascimento)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(campoData, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(txtAlertData)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jToolBar1, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(1, 1, 1)
                .addComponent(campoMensagem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textNascimento)
                    .addComponent(txtAlertData)
                    .addComponent(campoData, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(160, Short.MAX_VALUE))
        );

        txtAlertData.setVisible(false);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btNovoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btNovoActionPerformed
        if (tratamentoCampos.validaObrigatorios()) {
            InputStream inputStreamDaImagem = null;
            try {
                String caminhoImagem = System.getProperty("user.dir") + "\\img\\logo_unipampa.png";
                File file = null;
                try {
                    file = new File(caminhoImagem);

                    if (file.exists()) {
                        inputStreamDaImagem = new FileInputStream(file);
                    }
                } catch (FileNotFoundException e) {
                    campoMensagem.setText("Erro ao gerar o relatório. ERRO: " + e.getMessage());
                }

                DateFormat dfmt = new SimpleDateFormat(" d 'de' MMMM 'de' yyyy");
                SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
                String dataRelatorio = campoData.getText().substring(6, 10) + "-" + campoData.getText().substring(3, 5) + "-" + campoData.getText().substring(0, 2);
                java.sql.Time dataRelatorioFormat = new java.sql.Time(format.parse(dataRelatorio).getTime());

                ArrayList<Parametro> parametros = new ArrayList<Parametro>();
                parametros.add(new Parametro("codigoConcurso", "" + Concurso.getInstance().getCodigo()));
                parametros.add(new Parametro("dataRelatorio", dfmt.format(dataRelatorioFormat)));
                parametros.add(new Parametro("logo", file.getAbsolutePath()));

                GeradorRelatorios.gerar(System.getProperty("user.dir") + "\\src\\relatorios\\ReciboDocCandidatos.jasper", parametros);
                campoMensagem.setText("Relatório gerado com sucesso.");
            } catch (Exception e) {
                campoMensagem.setText("Erro ao gerar o relatório. ERRO: " + e.getMessage());
            }

        } else {
            campoMensagem.setText("Informe a data para gerar o relatório.");
        }
    }//GEN-LAST:event_btNovoActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btNovo;
    private javax.swing.JFormattedTextField campoData;
    private javax.swing.JTextField campoMensagem;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JLabel textNascimento;
    private javax.swing.JLabel txtAlertData;
    // End of variables declaration//GEN-END:variables

}
