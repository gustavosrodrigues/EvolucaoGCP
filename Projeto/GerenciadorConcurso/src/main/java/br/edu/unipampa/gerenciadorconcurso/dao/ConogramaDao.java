package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Abertura;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Registrocronograma;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;

/**
 *
 * @author Pedro
 */
public class ConogramaDao {

    private DAO DAO;

    public ConogramaDao() {
        DAO = new DAO();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Registrocronograma conograma) {
        DAO.salvar(conograma);
        return DAO.salvar(conograma);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Registrocronograma> buscar() {
        return (ArrayList<Registrocronograma>) DAO.buscarObjetos(Registrocronograma.class);
    }
    public ArrayList<Registrocronograma> buscarConogramaPorConcurso(Collection<Abertura> aberturas){
        HashMap<String, Object> filtro = new HashMap<>();
        for (Abertura abertura : aberturas) {//Temp
            filtro.put("abertura.codigo", abertura.getCodigo());
            return (ArrayList<Registrocronograma>) DAO.buscarObjetos(filtro, Registrocronograma.class);
        }
        return new ArrayList<>();
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Registrocronograma.class);
    }
//</editor-fold>
    
}
