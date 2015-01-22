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
    private String status;

    public StatusCadastros(JButton btNovo, JButton btAlterar, JButton btExcluir, JButton btSalvar,
            JTextField campoCodigo, JTextField campoMensagem, Campos tratamento) {
        this.btNovo = btNovo;
        this.btAlterar = btAlterar;
        this.btExcluir = btExcluir;
        this.btSalvar = btSalvar;
        this.campoCodigo = campoCodigo;
        this.campoMensagem = campoMensagem;
        this.tratamento = tratamento;
        this.status = "indefinido";
    }

    public void estadoNovo() {
        campoCodigo.setText("0");
        campoMensagem.setText("");

        if (btNovo != null) {
            btNovo.setEnabled(false);
            btNovo.setVisible(false);
        }

        if (btAlterar != null) {
            btAlterar.setEnabled(false);
            btAlterar.setVisible(false);
        }

        if (btExcluir != null) {
            btExcluir.setEnabled(false);
            btExcluir.setVisible(false);
        }

        if (btSalvar != null) {
            btSalvar.setEnabled(true);
            btSalvar.setVisible(true);
        }

        tratamento.habilitaEdição();
        tratamento.limpar();
    }

    public void estadoAlterando() {
        if (btNovo != null) {
            btNovo.setEnabled(true);
            btNovo.setVisible(true);
        }

        if (btAlterar != null) {
            btAlterar.setEnabled(false);
            btAlterar.setVisible(false);
        }

        if (btExcluir != null) {
            btExcluir.setEnabled(true);
            btExcluir.setVisible(true);
        }

        if (btSalvar != null) {
            btSalvar.setEnabled(true);
            btSalvar.setVisible(true);
        }

        tratamento.habilitaEdição();
        tratamento.limparFormatação();
    }

    public void estadoSalvo() {
        if (btNovo != null) {
            btNovo.setEnabled(true);
            btNovo.setVisible(true);
        }

        if (btAlterar != null) {
            btAlterar.setEnabled(true);
            btAlterar.setVisible(true);
        }

        if (btExcluir != null) {
            btExcluir.setEnabled(true);
            btExcluir.setVisible(true);
        }

        if (btSalvar != null) {
            btSalvar.setEnabled(false);
            btSalvar.setVisible(false);
        }

        tratamento.limparFormatação();
        tratamento.desabilitaEdição();
    }

    /**
     * @return the status
     */
    public String getStatus() {
        return status;
    }

    /**
     * @param status the status to set
     */
    public void setStatus(String status) {
        this.status = status;

        switch (status) {
            case "incluir":
                estadoNovo();
                break;
            case "editar":
                estadoAlterando();
                break;
            case "salvar":
                estadoSalvo();
                break;
            default:
                this.status = "indefinido";
                break;
        }
    }
}
