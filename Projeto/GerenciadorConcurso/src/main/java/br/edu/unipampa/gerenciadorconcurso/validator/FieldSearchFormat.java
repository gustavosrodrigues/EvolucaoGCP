/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.border.LineBorder;

/**
 * @author Douglas Giordano
 * 
 */
public class FieldSearchFormat extends FieldFormat {
    private JLabel text;
    private JButton button;

    public FieldSearchFormat(JTextField field, JLabel textAlert, boolean obligatory, JLabel text, JButton button) {
        super(field, textAlert, obligatory);
        this.text = text;
        this.button = button;
        
    }

    @Override
    public void desableEditting() {
        super.desableEditting();
        button.setEnabled(false);
                field.setBackground(desableEdit);
    }

    @Override
    public void enableEditting() {
        super.enableEditting();
        button.setEnabled(true);
        cleanFormatting();
    }

    @Override
    public void clean() {
        super.clean();
        text.setText("");
    }

    @Override
    public void cleanFormatting() {
        super.cleanFormatting();
        text.setBorder(null);
                        field.setBackground(Color.WHITE);
    }

    @Override
    public boolean validateField(boolean valido) {
        if (obligatory) {
            if (text.getText().equals("") || field.getText().equals("")) {
                valido = false;
                text.setBorder(new LineBorder(Color.RED));
                field.setBackground(Color.RED);
                textAlert.setVisible(true);
            }
        }
        return valido;
    }
}
