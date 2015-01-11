/*
 * Classe contendo funções para a manipulação de tabelas
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Douglas
 */
public abstract class Tabela {

    public static void limparTabela(DefaultTableModel modelo) {
        //limpa tabela do formulário
        while (modelo.getRowCount() > 0) {
            modelo.removeRow(0);
        }
    }
}
