/*
 * Classe responsável pela manutenção da entidade Candidato
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Examinador;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * @author Douglas
 * @since 15/01/2015
 */
public class ExaminadorDao {

    private DAO DAO;

    public ExaminadorDao() {
        DAO = new DAO();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Examinador examinador) {
        DAO.salvar(examinador.getPessoa());
        return DAO.salvar(examinador);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Examinador> buscar() {
        return (ArrayList<Examinador>) DAO.buscarObjetos(Examinador.class);
    }

    public ArrayList<Examinador> buscar(Concurso concurso) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        return (ArrayList<Examinador>) DAO.buscarObjetos(filtros,Examinador.class);
    }

    public Examinador buscar(int codigo) {
        return (Examinador) DAO.buscarObjeto(codigo, Examinador.class);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Examinador.class);
    }
//</editor-fold>

}
