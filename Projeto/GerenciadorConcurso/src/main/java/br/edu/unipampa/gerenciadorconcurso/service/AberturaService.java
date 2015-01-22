
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.AberturaDao;
import br.edu.unipampa.gerenciadorconcurso.model.Abertura;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import java.util.ArrayList;

/**
 *
 * @author Pedro
 */
public class AberturaService {
    
    private AberturaDao aberturaDao;
    
    public AberturaService(){
        aberturaDao = new AberturaDao();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Abertura abertura) {
        return aberturaDao.salvar(abertura);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    /**
     * Busca por todos os conogramas presentes no banco
     * @return Lista de Conogramas encontrados
     */
    public ArrayList<Abertura> buscar() {
        return aberturaDao.buscar();
    }
    
    public Abertura buscarAberturaPorConcurso(Concurso concurso){
        return aberturaDao.buscarAberturaPorConcurso(concurso);//Temp
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return aberturaDao.deletar(codigo);
    }
//</editor-fold>
}
