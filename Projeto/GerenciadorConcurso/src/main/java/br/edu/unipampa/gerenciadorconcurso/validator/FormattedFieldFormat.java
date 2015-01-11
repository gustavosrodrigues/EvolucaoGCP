/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import java.awt.Color;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;

/**
 *
 * @author Douglas
 */
public class FormattedFieldFormat extends FieldFormat {

    JFormattedTextField formattedField;

    public FormattedFieldFormat(JFormattedTextField field, JLabel textAlert, boolean obligatory) {
        super(field, textAlert, obligatory);
        formattedField = (JFormattedTextField) field;
    }

    @Override
    public boolean validateField(boolean valido) {
        if (obligatory) {
            JFormattedTextField fieldTemp = (JFormattedTextField) field;
            if (!fieldTemp.isEditValid()) {
                textAlert.setVisible(true);
                field.setBackground(Color.red);
                valido = false;
            } else {
                if (Data.isDateValid(field.getText())) {
                    return valido;
                } else if (FormattedFieldFormat.isValidCNPJ(field.getText())) {
                    return valido;
                } else {
                    textAlert.setVisible(true);
                    field.setBackground(Color.red);
                    valido = false;
                }
            }
        }


        return valido;
    }

    @Override
    public void desableEditting() {
        formattedField.setEditable(false);
        formattedField.setBackground(desableEdit);
        if (obligatory) {
            textAlert.setVisible(false);
        }
    }

    @Override
    public void enableEditting() {
        formattedField.setEditable(true);
        cleanFormatting();
    }

    @Override
    public void clean() {
        field.setText("");
        cleanFormatting();
    }

    @Override
    public void cleanFormatting() {
        if (obligatory) {
            textAlert.setVisible(false);
        }
            formattedField.setBackground(Color.WHITE);
        
    }

    public static boolean isValidCNPJ(String str_cnpj) {

        str_cnpj = str_cnpj.replaceAll("/", "");
        str_cnpj = str_cnpj.replaceAll("\\.", "");
        str_cnpj = str_cnpj.replaceAll("\\-", "");
        int soma = 0, aux, dig;
        String cnpj_calc;
        try {
            cnpj_calc = str_cnpj.substring(0, 12);
        } catch (IndexOutOfBoundsException erro) {
            return false;
        }
        if (str_cnpj.length() != 14) {
            return false;
        }

        char[] chr_cnpj = str_cnpj.toCharArray();

        /* Primeira parte */
        for (int i = 0; i < 4; i++) {
            if (chr_cnpj[i] - 48 >= 0 && chr_cnpj[i] - 48 <= 9) {
                soma += (chr_cnpj[i] - 48) * (6 - (i + 1));
            }
        }
        for (int i = 0; i < 8; i++) {
            if (chr_cnpj[i + 4] - 48 >= 0 && chr_cnpj[i + 4] - 48 <= 9) {
                soma += (chr_cnpj[i + 4] - 48) * (10 - (i + 1));
            }
        }
        dig = 11 - (soma % 11);

        cnpj_calc += (dig == 10 || dig == 11)
                ? "0" : Integer.toString(dig);

        /* Segunda parte */
        soma = 0;
        for (int i = 0; i < 5; i++) {
            if (chr_cnpj[i] - 48 >= 0 && chr_cnpj[i] - 48 <= 9) {
                soma += (chr_cnpj[i] - 48) * (7 - (i + 1));
            }
        }
        for (int i = 0; i < 8; i++) {
            if (chr_cnpj[i + 5] - 48 >= 0 && chr_cnpj[i + 5] - 48 <= 9) {
                soma += (chr_cnpj[i + 5] - 48) * (10 - (i + 1));
            }
        }
        dig = 11 - (soma % 11);
        cnpj_calc += (dig == 10 || dig == 11)
                ? "0" : Integer.toString(dig);

        return str_cnpj.equals(cnpj_calc);

    }

    @Override
    public Object getObject() {
        return field;
    }

    @Override
    public boolean isObligatory() {
        return obligatory;
    }

    @Override
    public void setObligatory(boolean obligatory) {
        this.obligatory = obligatory;
    }
}
