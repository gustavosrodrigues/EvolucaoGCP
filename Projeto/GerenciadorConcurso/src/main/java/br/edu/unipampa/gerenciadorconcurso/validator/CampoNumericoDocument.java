/**
 * Classe para validar o campo, não deixando que o mesmo receba algo
 * diferente de um numero
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.PlainDocument;

/**
 * @author Douglas Giordano
 * @since 28/04/2013
 */
public class CampoNumericoDocument extends PlainDocument {

    private boolean numero;

    public CampoNumericoDocument(boolean isNumber) {
        super();
        numero = isNumber;
    }

    public void insertString(int offs, String str, AttributeSet attribute)
            throws BadLocationException {
        if (numero == true) {
        //verifica se o caracter inserido é um numero, caso não seja o mesmo não é inserido no campo  
            for (char c : str.toCharArray()) {
                if (!Character.isDigit(c)) {
                    return;
                }
            }
        }

        //caso ele chegue até aqui significa que o caracteres é um digito (0-9), então o mesmo é inserido no campo.  
        super.insertString(offs, str.toUpperCase(), attribute);
    }
}