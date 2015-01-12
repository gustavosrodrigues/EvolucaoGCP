/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import javax.swing.JButton;
import javax.swing.JTextField;

/**
 *
 * @author Douglas
 */
public class StatusCadastros {

    private JButton btNovo;
    private JButton btAlterar;
    private JButton btExcluir;
    private JButton btSalvar;
    private JTextField campoCodigo;
    private JTextField campoMensagem;
    private Campos tratamento;

    public StatusCadastros(JButton btNovo, JButton btAlterar, JButton btExcluir, JButton btSalvar,
            JTextField campoCodigo, JTextField campoMensagem, Campos tratamento) {
        this.btNovo = btNovo;
        this.btAlterar = btAlterar;
        this.btExcluir = btExcluir;
        this.btSalvar = btSalvar;
        this.campoCodigo = campoCodigo;
        this.campoMensagem = campoMensagem;
        this.tratamento = tratamento;
    }

    public void estadoNovo() {
        campoCodigo.setText("0");
        campoMensagem.setText("");
        btNovo.setEnabled(false);
        btAlterar.setEnabled(false);
        btExcluir.setEnabled(false);
        btSalvar.setEnabled(true);
        tratamento.habilitaEdição();
        tratamento.limpar();
    }

    public void estadoAlterando() {
        if(btNovo != null){
        btNovo.setEnabled(true);
        }
        btAlterar.setEnabled(false);
        if(btExcluir != null){
        btExcluir.setEnabled(true);
        }
        btSalvar.setEnabled(true);
        tratamento.habilitaEdição();
        tratamento.limparFormatação();
    }

    public void estadoSalvo() {
        if(btNovo != null){
        btNovo.setEnabled(true);
        }
        btAlterar.setEnabled(true);
        if(btExcluir != null){
        btExcluir.setEnabled(false);
        }
        btSalvar.setEnabled(false);
        tratamento.limparFormatação();
        tratamento.desabilitaEdição();
    }
}
