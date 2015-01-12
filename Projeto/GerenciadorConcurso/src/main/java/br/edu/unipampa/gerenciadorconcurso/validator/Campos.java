/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import br.edu.unipampa.gerenciadorconcurso.validator.InfoFormat;
import java.awt.Color;
import java.util.ArrayList;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.text.MaskFormatter;

/**
 *
 * @author Douglas Giordano
 */
public class Campos {

    ArrayList<InfoFormat> campos;

    public Campos() {
        campos = new ArrayList<InfoFormat>();
    }

    public void setCampo(InfoFormat estrutura) {
        campos.add(estrutura);
    }

    public void deleteCampo(InfoFormat estrutura) {
        campos.remove(estrutura);
    }

    public Object getCampo(Object o) {
        Object procurado = null;
        for (int i = 0; i < campos.size(); i++) {
            if (campos.get(i).getObject() == o) {
                procurado = campos.get(i);
                break;
            }
        }
        return procurado;
    }

    public void desabilitaEdição() {
        for (int i = 0; i < campos.size(); i++) {
            campos.get(i).desableEditting();
        }
    }

    public void habilitaEdição() {
        for (int i = 0; i < campos.size(); i++) {
            campos.get(i).enableEditting();
        }
    }

    public void limpar() {
        for (int i = 0; i < campos.size(); i++) {
            campos.get(i).clean();
        }
    }

    public void limparFormatação() {
        for (int i = 0; i < campos.size(); i++) {
            campos.get(i).cleanFormatting();
        }
    }

    public boolean validaObrigatorios() {
        boolean valido = true;
        limparFormatação();
        for (int i = 0; i < campos.size(); i++) {
            if (campos.get(i).isObligatory()) {
                valido = campos.get(i).validateField(valido);
            }
        }

        return valido;
    }

    /**
     * Cria uma mascara para formatar o campo.
     *
     * @param s
     * @return formatação
     */
    public static MaskFormatter createFormatter(String s) {
        MaskFormatter formatter = null;
        try {
            formatter = new MaskFormatter(s);
        } catch (java.text.ParseException exc) {
            System.out.println("formatador é ruim:" + exc.getMessage());
            System.exit(-1);
        }
        return formatter;
    }

    public static int converteNumero(String string) {
        try {
            return Integer.parseInt(string);
        } catch (NumberFormatException erro) {
            return 0;
        }
    }

    /**
     * Limapa a formatação dos campos de pesquisa
     *
     * @param codigo
     * @param nome
     */
    public static void cleanFormattingSearch(JTextField codigo, JLabel nome) {
        if (nome != null) {
            nome.setText("");
        }
        codigo.setBackground(Color.WHITE);
    }
}
