/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.interno;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.service.ConcursoService;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Douglas
 */
public class SelecaoConcurso extends javax.swing.JDialog {
    private DefaultTableModel modelo;
    private ArrayList<Concurso> concursos;
    private ConcursoService concursoService;
    
    
    /**
     * Creates new form SelecaoConcurso
     */
    public SelecaoConcurso(java.awt.Frame parent, boolean modal) {
        super(parent, modal);
        concursoService = new ConcursoService();
        concursoService.buscar(1);
        concursos = concursoService.buscar();
        initComponents();
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
        btNovoConcurso = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        tabelaConcursos = new javax.swing.JTable();
        modelo = (DefaultTableModel) tabelaConcursos.getModel();
        ConcursoService.listaConcursos(concursos, modelo);

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        barraTarefas.setRollover(true);

        btNovoConcurso.setText("Novo Concurso");
        btNovoConcurso.setFocusable(false);
        btNovoConcurso.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        btNovoConcurso.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        barraTarefas.add(btNovoConcurso);

        tabelaConcursos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null}
            },
            new String [] {
                "Código", "Universidade", "Campus", "Área", "Classe"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tabelaConcursos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tabelaConcursosMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tabelaConcursos);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(barraTarefas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 707, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(barraTarefas, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void tabelaConcursosMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tabelaConcursosMouseClicked
        if (evt.getClickCount() > 1) {
            int codigoLinha = tabelaConcursos.getSelectedRow();
            int codigo = Integer.parseInt(tabelaConcursos.getValueAt(codigoLinha, 0)+"");
            dispose();
        }
    }//GEN-LAST:event_tabelaConcursosMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToolBar barraTarefas;
    private javax.swing.JButton btNovoConcurso;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tabelaConcursos;
    // End of variables declaration//GEN-END:variables
}
