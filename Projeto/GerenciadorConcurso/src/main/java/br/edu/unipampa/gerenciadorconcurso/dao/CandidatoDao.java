/*
 * Classe responsável pela manutenção da entidade Candidato
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import java.util.ArrayList;

/**
 * @author Douglas
 * @since 11/01/2015
 */
public class CandidatoDao {

    private DAO DAO;

    public CandidatoDao() {
        DAO = new DAO();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Candidato candidato) {
        return DAO.salvar(candidato);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Candidato> buscar() {
        return (ArrayList<Candidato>) DAO.buscarObjetos(Candidato.class);
    }

    public Candidato buscar(int codigo) {
        return (Candidato) DAO.buscarObjeto(codigo, Candidato.class);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Candidato.class);
    }
//</editor-fold>

}
