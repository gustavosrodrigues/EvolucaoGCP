/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.JComboBox;

/**
 * @author Douglas Giordano
 */
public class ComboBoxFormat extends InfoFormat{

    JComboBox comboBox;

    public ComboBoxFormat(JComboBox comboBox) {
        this.comboBox = comboBox;
    }

    @Override
    public void desableEditting() {
                comboBox.setEnabled(false);
    }

    @Override
    public void enableEditting() {
        comboBox.setEnabled(true);
    }

    @Override
    public void clean() {
        comboBox.setSelectedIndex(0);
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
        return comboBox;
    }

    @Override
    public boolean isObligatory() {
        return false;
    }

    @Override
    public void setObligatory(boolean obligatory) {
        
    }
}
