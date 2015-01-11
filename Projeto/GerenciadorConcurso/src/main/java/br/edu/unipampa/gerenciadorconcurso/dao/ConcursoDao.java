/*
* Classe responsável pela manutenção da entidade Candidato
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import java.util.ArrayList;

/**
 * @author Douglas
 * @since 11/01/2015
 */
public class ConcursoDao {
    private DAO DAO;
    
    public ConcursoDao(){
        DAO = new DAO();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Concurso concurso){
        return DAO.salvar(concurso);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Concurso> buscar(){
        return (ArrayList<Concurso>) DAO.buscarObjetos(Concurso.class);
    }
    
    public Concurso buscar(int codigo){
        return (Concurso) DAO.buscarObjeto(codigo, Concurso.class);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo){
        return DAO.excluir(codigo, Concurso.class);
    }
//</editor-fold>

}
