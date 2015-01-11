/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.PlainDocument;

/**
 *
 * @author Douglas
 */
public class LimitField extends PlainDocument {

    private int iMaxLength;
    private boolean toUpperCase;

    public LimitField(int maxlen, boolean toUpperCase) {
        super();
        this.iMaxLength = maxlen;
        this.toUpperCase = toUpperCase;
    }

    public void insertString(int offset, String str, AttributeSet attr)
            throws BadLocationException {
        if(toUpperCase){
        str = str.toUpperCase();
        }
        if (iMaxLength <= 0) // aceitara qualquer no. de caracteres  
        {
            for (char c : str.toCharArray()) {
                char m = ' ';
                if (c != '\'' && c != '"'); {
                    super.insertString(offset, str, attr);
                    return;
                }
            }
        }

        int ilen = (getLength() + str.length());
        if (ilen <= iMaxLength) // se o comprimento final for menor...  
        {
            for (char c : str.toCharArray()) {
                if (c != '\'' && c != '"') {
                    super.insertString(offset, str, attr);
                    return;
                }
            }   // ...aceita str  
        } else {
            for (char c : str.toCharArray()) {
                if (getLength() == iMaxLength) {
                    return; // nada a fazer  
                }
            }

            String newStr = str.substring(0, (iMaxLength - getLength()));

            super.insertString(offset, newStr, attr);
        }
    }
}
