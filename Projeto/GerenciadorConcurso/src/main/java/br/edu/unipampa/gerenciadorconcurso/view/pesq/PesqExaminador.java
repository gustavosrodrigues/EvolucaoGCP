/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.pesq;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Examinador;
import br.edu.unipampa.gerenciadorconcurso.service.CandidatoService;
import br.edu.unipampa.gerenciadorconcurso.service.ExaminadorService;
import java.util.ArrayList;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Douglas
 */
public class PesqExaminador extends javax.swing.JDialog {

    private JTextField campoCodigo;
    private JTextField campoNome;
    private ArrayList<Examinador> examinadores;
    private ExaminadorService examinadorService;
    private DefaultTableModel modelo;

    /**
     * Creates new form PesqCandidato
     */
    public PesqExaminador(java.awt.Frame parent, boolean modal, JTextField campoCodigo, JTextField campoNome) {
        super(parent, modal);
        examinadorService = new ExaminadorService();
        examinadores = examinadorService.buscar(Concurso.getInstance());
        initComponents();
        this.campoCodigo = campoCodigo;
        this.campoNome = campoNome;
    }

    /**
     * Creates new form PesqCandidato
     */
    public PesqExaminador(java.awt.Frame parent, boolean modal, JTextField campoCodigo) {
        super(parent, modal);
        examinadorService = new ExaminadorService();
        examinadores = examinadorService.buscar(Concurso.getInstance());
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
        tabelaExaminadores = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        barraTarefas.setRollover(true);

        tabelaExaminadores.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Código", "Nome", "Sexo", "Categoria"
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
        tabelaExaminadores.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tabelaExaminadoresMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tabelaExaminadores);
        modelo = (DefaultTableModel) tabelaExaminadores.getModel();
        ExaminadorService.listaExaminadores(examinadores, modelo);

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

    private void tabelaExaminadoresMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tabelaExaminadoresMouseClicked
        if (evt.getClickCount() > 1) {
            int codigoLinha = tabelaExaminadores.getSelectedRow();
            int codigo = Integer.parseInt(tabelaExaminadores.getValueAt(codigoLinha, 0) + "");
            campoCodigo.setText(codigo+"");
            dispose();
        }
    }//GEN-LAST:event_tabelaExaminadoresMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToolBar barraTarefas;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tabelaExaminadores;
    // End of variables declaration//GEN-END:variables
}