/*
 * Classe responsável pela manutenção da entidade Candidato
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import java.util.ArrayList;
import java.util.HashMap;

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
        DAO.salvar(candidato.getPessoa());
        return DAO.salvar(candidato);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Candidato> buscar() {
        return (ArrayList<Candidato>) DAO.buscarObjetos(Candidato.class);
    }

    public ArrayList<Candidato> buscar(Concurso concurso) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        return (ArrayList<Candidato>) DAO.buscarObjetos(filtros,Candidato.class);
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
