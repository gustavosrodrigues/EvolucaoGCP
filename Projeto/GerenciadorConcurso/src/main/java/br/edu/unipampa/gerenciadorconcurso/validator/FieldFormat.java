package br.edu.unipampa.gerenciadorconcurso.validator;

import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 * @author Douglas Giordano
 */
public class FieldFormat extends InfoFormat {

    protected JTextField field;
    protected JLabel textAlert;
    protected boolean obligatory;
    protected Color desableEdit;

    public FieldFormat(JTextField field, JLabel textAlert, boolean obligatory) {
        this.field = field;
        this.textAlert = textAlert;
        this.obligatory = obligatory;
        desableEdit = new Color(204, 204, 204);
    }

    @Override
    public boolean isObligatory() {
        return obligatory;
    }

    public JLabel getTextAlert() {
        return textAlert;
    }

    @Override
    public void desableEditting() {
        field.setEditable(false);
        field.setBackground(desableEdit);
    }

    @Override
    public void enableEditting() {
        field.setEditable(true);
        field.setBackground(Color.WHITE);
    }

    @Override
    public void clean() {
        field.setText("");
        cleanFormatting();
    }

    @Override
    public void cleanFormatting() {
        if (obligatory) {
            if (textAlert != null) {
                textAlert.setVisible(false);
            }
            field.setBackground(Color.WHITE);
        }
    }

    @Override
    public boolean validateField(boolean valido) {
        if (isObligatory()) {
            if (field.getText().equals("")) {
                field.setBackground(Color.red);
                textAlert.setVisible(true);
                valido = false;
            }
        }
        return valido;
    }

    @Override
    public Object getObject() {
        return field;
    }

    @Override
    public void setObligatory(boolean obligatory) {
        this.obligatory = obligatory;
    }
}
