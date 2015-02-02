
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Titulo;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author Pedro
 */
public class TitulosDao {
    private DAO DAO;
    
    public TitulosDao(){
        DAO = new DAO();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Titulo titulo) {
        DAO.salvar(titulo);
        return DAO.salvar(titulo);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Titulo> buscar() {
        return (ArrayList<Titulo>) DAO.buscarObjetos(Titulo.class);
    }

    public ArrayList<Titulo> buscar(Candidato candidato) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("candidato.codigo", candidato.getCodigo());
        return (ArrayList<Titulo>) DAO.buscarObjetos(filtros,Titulo.class);
    }

    public Titulo buscar(int codigo) {
        return (Titulo) DAO.buscarObjeto(codigo, Titulo.class);
    }
    
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Titulo.class);
    }
//</editor-fold>
}
