/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.pesq;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.service.CandidatoService;
import java.util.ArrayList;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Douglas
 */
public class PesqCandidato extends javax.swing.JDialog {

    private JTextField campoCodigo;
    private JLabel campoNome;
    private ArrayList<Candidato> candidatos;
    private CandidatoService candidatoService;
    private DefaultTableModel modelo;

    /**
     * Creates new form PesqCandidato
     */
    public PesqCandidato(java.awt.Frame parent, boolean modal, JTextField campoCodigo, JLabel campoNome) {
        super(parent, modal);
        candidatoService = new CandidatoService();
        candidatos = candidatoService.buscar(Concurso.getInstance());
        initComponents();
        this.campoCodigo = campoCodigo;
        this.campoNome = campoNome;
    }

    /**
     * Creates new form PesqCandidato
     */
    public PesqCandidato(java.awt.Frame parent, boolean modal, JTextField campoCodigo) {
        super(parent, modal);
        candidatoService = new CandidatoService();
        candidatos = candidatoService.buscar(Concurso.getInstance());
        initComponents();
        this.campoCodigo = campoCodigo;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        barraTarefas = new javax.swing.JToolBar();
        jScrollPane1 = new javax.swing.JScrollPane();
        tabelaCandidatos = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        barraTarefas.setRollover(true);

        tabelaCandidatos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Código", "Nome", "Sexo", "Nascimento"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tabelaCandidatos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tabelaCandidatosMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tabelaCandidatos);
        modelo = (DefaultTableModel) tabelaCandidatos.getModel();
        CandidatoService.listaCandidatos(candidatos, modelo);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(barraTarefas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 600, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(barraTarefas, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 369, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void tabelaCandidatosMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tabelaCandidatosMouseClicked
        if (evt.getClickCount() > 1) {
            int codigoLinha = tabelaCandidatos.getSelectedRow();
            int codigo = Integer.parseInt(tabelaCandidatos.getValueAt(codigoLinha, 0) + "");
            campoCodigo.setText(codigo+"");
            if(campoNome != null){
                Candidato candidato = candidatoService.buscar(codigo);
                campoNome.setText(candidato.getPessoa().getNome());
            }
            
            dispose();
        }
    }//GEN-LAST:event_tabelaCandidatosMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToolBar barraTarefas;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tabelaCandidatos;
    // End of variables declaration//GEN-END:variables
}
