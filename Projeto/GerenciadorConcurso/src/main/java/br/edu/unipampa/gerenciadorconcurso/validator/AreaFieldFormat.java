/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import java.awt.Color;
import javax.swing.JTextArea;

/**
 *
 * @author Douglas
 */
public class AreaFieldFormat extends InfoFormat {

    JTextArea txtArea;

    public AreaFieldFormat(JTextArea txtArea) {
        this.txtArea = txtArea;
        
    }

    @Override
    public void desableEditting() {
        txtArea.setEditable(false);
        txtArea.setBackground(new Color(204,204,204));
    }

    @Override
    public void enableEditting() {
        txtArea.setEditable(true);
        cleanFormatting();
    }

    @Override
    public void clean() {
        txtArea.setText("");
        cleanFormatting();
    }

    @Override
    public void cleanFormatting() {
        txtArea.setBackground(Color.WHITE);
    }

    @Override
    public boolean validateField(boolean valido) {
        return valido;
    }

    @Override
    public Object getObject() {
        return txtArea;
    }

    @Override
    public boolean isObligatory() {
        return false;
    }

    @Override
    public void setObligatory(boolean obligatory) {
        
    }
}
