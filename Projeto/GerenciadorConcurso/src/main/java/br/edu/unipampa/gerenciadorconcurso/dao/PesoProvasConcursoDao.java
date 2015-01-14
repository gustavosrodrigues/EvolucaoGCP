package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Pesoprovas;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Peso Provas Concurso Dao
 *
 * @version v 1.0 13/01/2015
 * @author Alex Becker
 *
 */
public class PesoProvasConcursoDao {

    private final DAO DAO;

    public PesoProvasConcursoDao() {
        DAO = new DAO();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Pesoprovas pesoprovas) {
        DAO.salvar(pesoprovas);
        return DAO.salvar(pesoprovas);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Pesoprovas> buscar() {
        return (ArrayList<Pesoprovas>) DAO.buscarObjetos(Pesoprovas.class);
    }

    public Pesoprovas buscar(int codigo) {
        return (Pesoprovas) DAO.buscarObjeto(codigo, Pesoprovas.class);
    }
    
    public Pesoprovas buscarPesoProvasConcurso(Concurso concurso) {
        HashMap<String, Object> filtro = new HashMap<>();
        filtro.put("concurso.codigo", concurso.getCodigo());
        return (Pesoprovas) DAO.buscarObjeto(filtro, Pesoprovas.class);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return DAO.excluir(codigo, Pesoprovas.class);
    }
//</editor-fold>

}
