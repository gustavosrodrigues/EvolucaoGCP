/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.ExaminadorDao;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Examinador;
import br.edu.unipampa.gerenciadorconcurso.validator.Tabela;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 * @author Douglas
 * @since 15/01/2015
 */
public class ExaminadorService {

    private ExaminadorDao examinadorDao;

    public ExaminadorService() {
        examinadorDao = new ExaminadorDao();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Examinador examinador) {
        return examinadorDao.salvar(examinador);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Examinador> buscar() {
        return examinadorDao.buscar();
    }

    public ArrayList<Examinador> buscar(Concurso concurso) {
        return examinadorDao.buscar(concurso);
    }

    public Examinador buscar(int codigo) {
        return examinadorDao.buscar(codigo);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return examinadorDao.deletar(codigo);
    }
//</editor-fold>

    public static void listaExaminadores(ArrayList<Examinador> examinadores, DefaultTableModel modelo) {
        Tabela.limparTabela(modelo);
        String infoExaminadores[] = new String[4];
        for (int i = 0; i < examinadores.size(); i++) {
            infoExaminadores[0] = examinadores.get(i).getCodigo() + "";
            infoExaminadores[1] = examinadores.get(i).getPessoa().getNome() + "";
            if (examinadores.get(i).getPessoa().getSexo()) {
                infoExaminadores[2] = "Masculino";
            } else {
                infoExaminadores[2] = "Feminino";
            }
            infoExaminadores[3] = examinadores.get(i).getCategoria();
            modelo.addRow(infoExaminadores);
        }
    }
}
