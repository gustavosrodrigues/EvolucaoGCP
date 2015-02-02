/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import jdk.nashorn.internal.runtime.JSType;

/**
 *
 * @author Pedro
 */
public class CampoNumericoQuebrado extends CampoNumericoDocument{

    public CampoNumericoQuebrado(boolean isNumber) {
        super(isNumber);
    }
    
    @Override
    public void insertString(int offs, String str, AttributeSet attribute)
            throws BadLocationException {
        //Falta testar direito.
        if (isNumero() == true) {
            if(vericaPonto()){
                return;
            }
            //verifica se o caracter inserido é um numero, caso não seja o mesmo não é inserido no campo  
            for (char c : str.toCharArray()) {
                if(c == '.' || c == ','){
                    break;
                }
                if (!Character.isDigit(c)) {
                    return;
                }
            }
        }

        //caso ele chegue até aqui significa que o caracteres é um digito (0-9), então o mesmo é inserido no campo.  
        super.insertString(offs, str.toUpperCase(), attribute);
    }
    
    /**
     * Verifica se o número do campo já contém um ponto ou uma vírgula
     * @return true se a palavra contém o ponto
     * @throws BadLocationException 
     */
    public boolean vericaPonto() throws BadLocationException{
        String textoCampo = this.getText(0, getLength());
        
        for (char c :textoCampo.toCharArray()) {
            if(c == '.' || c == ','){
                return true;
            }
        }
        
        return false;
    }
}
