
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.ConogramaDao;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Registrocronograma;
import java.util.ArrayList;

/**
 *
 * @author Pedro
 */
public class ConogramaService {
    private final ConogramaDao conogramaDao;
    
    public ConogramaService(){
        conogramaDao = new ConogramaDao();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Registrocronograma conograma) {
        return conogramaDao.salvar(conograma);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    /**
     * Busca por todos os conogramas presentes no banco
     * @return Lista de Conogramas encontrados
     */
    public ArrayList<Registrocronograma> buscar() {
        return conogramaDao.buscar();
    }
    
    public ArrayList<Registrocronograma> buscarConogramaPorConcurso(Concurso concurso){
        return conogramaDao.buscarConogramaPorConcurso(concurso);//Temp
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return conogramaDao.deletar(codigo);
    }
//</editor-fold>
}
