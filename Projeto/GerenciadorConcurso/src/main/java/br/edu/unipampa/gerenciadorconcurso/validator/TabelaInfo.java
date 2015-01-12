/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Douglas
 */
public class TabelaInfo extends InfoFormat{

    JTable tabela;

    public TabelaInfo(JTable tabela) {
        this.tabela = tabela;
    }

    @Override
    public void desableEditting() {
        tabela.setEnabled(false);
    }

    @Override
    public void enableEditting() {
        tabela.setEnabled(true);
    }

    @Override
    public void clean() {
        Tabela.limparTabela((DefaultTableModel) tabela.getModel());
    }

    @Override
    public void cleanFormatting() {
    }

    @Override
    public boolean validateField(boolean valido) {
        return valido;
    }

    @Override
    public Object getObject() {
        return tabela;
    }

    @Override
    public boolean isObligatory() {
        return false;
    }

    @Override
    public void setObligatory(boolean obligatory) {
        
    }
}
