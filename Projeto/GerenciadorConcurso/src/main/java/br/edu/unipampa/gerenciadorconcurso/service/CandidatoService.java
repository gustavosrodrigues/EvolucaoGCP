/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.CandidatoDao;
import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.validator.Data;
import br.edu.unipampa.gerenciadorconcurso.validator.Tabela;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 * @author Douglas
 * @since 11/01/2015
 */
public class CandidatoService {

    private CandidatoDao candidatoDao;

    public CandidatoService() {
        candidatoDao = new CandidatoDao();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Candidato candidato) {
        return candidatoDao.salvar(candidato);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Candidato> buscar() {
        return candidatoDao.buscar();
    }

    public ArrayList<Candidato> buscar(Concurso concurso) {
        return candidatoDao.buscar(concurso);
    }

    public Candidato buscar(int codigo) {
        return candidatoDao.buscar(codigo);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return candidatoDao.deletar(codigo);
    }
//</editor-fold>

    public static void listaCandidatos(ArrayList<Candidato> candidatos, DefaultTableModel modelo) {
        Tabela.limparTabela(modelo);
        String infoConcurso[] = new String[4];
        for (int i = 0; i < candidatos.size(); i++) {
            infoConcurso[0] = candidatos.get(i).getCodigo() + "";
            infoConcurso[1] = candidatos.get(i).getPessoa().getNome() + "";
            if (candidatos.get(i).getPessoa().getSexo()) {
                infoConcurso[2] = "Masculino";
            } else {
                infoConcurso[2] = "Feminino";
            }
            infoConcurso[3] = Data.formatDate(candidatos.get(i).getDataNacimento());
            modelo.addRow(infoConcurso);
        }
    }
}
