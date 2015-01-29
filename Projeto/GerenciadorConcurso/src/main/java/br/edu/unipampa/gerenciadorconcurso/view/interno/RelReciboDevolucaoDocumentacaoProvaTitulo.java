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
import java.util.ArrayList;
import javax.swing.JFormattedTextField;
/**
 * Tela de geração do recibo de devolução de documentação da prova titulo.
 *
 * @author Douglas Giordano
 * @since 29/01/2015
 */
public class RelReciboDevolucaoDocumentacaoProvaTitulo extends javax.swing.JInternalFrame {

    private final Campos tratamentoCampos;
    
    /**
     * Creates new form CadastroCandidato
     */
    public RelReciboDevolucaoDocumentacaoProvaTitulo() {
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
        btGerar = new javax.swing.JButton();
        textNascimento = new javax.swing.JLabel();
        campoMensagem = new javax.swing.JTextField();
        txtAlertData = new javax.swing.JLabel();
        campoData = new JFormattedTextField(Campos.createFormatter("##-##-####"));
        ;

        setTitle("Recibo de devolução de documentação (opcional)");

        jToolBar1.setRollover(true);

        btGerar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/executar.png")));
        btGerar.setText("Gerar Relatório");
        btGerar.setFocusable(false);
        btGerar.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btGerar.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        btGerar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btGerarActionPerformed(evt);
            }
        });
        jToolBar1.add(btGerar);

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
                .addGap(28, 28, 28)
                .addComponent(textNascimento)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(campoData, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(txtAlertData)
                .addGap(0, 359, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jToolBar1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(campoMensagem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(textNascimento)
                    .addComponent(txtAlertData)
                    .addComponent(campoData, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(172, Short.MAX_VALUE))
        );

        txtAlertData.setVisible(false);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btGerarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btGerarActionPerformed
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

                ArrayList<Parametro> parametros = new ArrayList<Parametro>();
                parametros.add(new Parametro("dataRelatorio", campoData.getText()));
                parametros.add(new Parametro("concurso", Concurso.getInstance().getCodigo()+""));
                parametros.add(new Parametro("logo", file.getAbsolutePath()));

                GeradorRelatorios.gerar(System.getProperty("user.dir") + "\\src\\relatorios\\RelReciboDevolucaoDocumentacao.jasper", parametros);
                campoMensagem.setText("Relatório gerado com sucesso.");
            } catch (Exception e) {
                campoMensagem.setText("Erro ao gerar o relatório. ERRO: " + e.getMessage());
            }

        }
    }//GEN-LAST:event_btGerarActionPerformed

    //<editor-fold defaultstate="collapsed" desc="variaveis">
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btGerar;
    private javax.swing.JFormattedTextField campoData;
    private javax.swing.JTextField campoMensagem;
    private javax.swing.JToolBar jToolBar1;
    private javax.swing.JLabel textNascimento;
    private javax.swing.JLabel txtAlertData;
    // End of variables declaration//GEN-END:variables
    
//</editor-fold>
}
