
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Abertura;
import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author Pedro
 */
public class AberturaDao {
    private DAO DAO;
    
    public AberturaDao(){
        DAO = new DAO();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Abertura abertura) {
        DAO.salvar(abertura);
        return DAO.salvar(abertura);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Abertura> buscar() {
        return (ArrayList<Abertura>) DAO.buscarObjetos(Candidato.class);
    }

    public ArrayList<Abertura> buscar(Concurso concurso) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        return (ArrayList<Abertura>) DAO.buscarObjetos(filtros,Abertura.class);
    }

    public Abertura buscar(int codigo) {
        return (Abertura) DAO.buscarObjeto(codigo, Abertura.class);
    }
    
    public Abertura buscarAberturaPorConcurso(Concurso concurso) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        ArrayList<Abertura> listaAberturas
                = (ArrayList<Abertura>) DAO.buscarObjetos(filtros,Abertura.class);
        for (Abertura abertura : listaAberturas) {
            return abertura;
        }
        return null;
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Abertura.class);
    }
//</editor-fold>

}
