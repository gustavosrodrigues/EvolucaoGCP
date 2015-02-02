
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Formacaoacademica;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author Pedro
 */
public class FormacaoAcademicaDao {
    private DAO DAO;
    
    public FormacaoAcademicaDao(){
        DAO = new DAO();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Formacaoacademica formacaoAcademica) {
        DAO.salvar(formacaoAcademica);
        return DAO.salvar(formacaoAcademica);
    }

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Formacaoacademica> buscar() {
        return (ArrayList<Formacaoacademica>) DAO.buscarObjetos(Formacaoacademica.class);
    }

    public ArrayList<Formacaoacademica> buscar(Candidato candidato) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("candidato.codigo", candidato.getCodigo());
        return (ArrayList<Formacaoacademica>) DAO.buscarObjetos(filtros,Formacaoacademica.class);
    }

    public Formacaoacademica buscar(int codigo) {
        return (Formacaoacademica) DAO.buscarObjeto(codigo, Formacaoacademica.class);
    }
    
    public Formacaoacademica buscarAberturaPorConcurso(Concurso concurso) {
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        ArrayList<Formacaoacademica> listaAberturas
                = (ArrayList<Formacaoacademica>) DAO.buscarObjetos(filtros,Formacaoacademica.class);
        for (Formacaoacademica abertura : listaAberturas) {
            return abertura;
        }
        return null;
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Formacaoacademica.class);
    }
//</editor-fold>
}
