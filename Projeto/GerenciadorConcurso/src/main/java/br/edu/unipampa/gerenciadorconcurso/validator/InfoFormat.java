/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

/**
 * @author Douglas Giordano
 */
public abstract class InfoFormat {

    public abstract void desableEditting();

    public abstract void enableEditting();

    public abstract void clean();

    public abstract void cleanFormatting();

    public abstract boolean validateField(boolean valid);
    
    public abstract Object getObject();
    
    public abstract boolean isObligatory();
    
    public abstract void setObligatory(boolean obligatory);
}
