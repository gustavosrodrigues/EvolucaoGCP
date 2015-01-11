/*
 */
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.ConcursoDao;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.validator.Tabela;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 * @author Douglas
 * @since 11/01/2015
 */
public class ConcursoService {
    private ConcursoDao concursoDao;
    
    public ConcursoService(){
        concursoDao = new ConcursoDao();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Concurso concurso){
        return concursoDao.salvar(concurso);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Concurso> buscar(){
        return concursoDao.buscar();
    }
    
    public Concurso buscar(int codigo){
        return concursoDao.buscar(codigo);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo){
        return concursoDao.deletar(codigo);
    }
//</editor-fold>

    
    public static void listaConcursos(ArrayList<Concurso> concursos, DefaultTableModel modelo) {
        Tabela.limparTabela(modelo);
        String infoConcurso[] = new String[3];
        for (int i = 0; i < concursos.size(); i++) {
            infoConcurso[0] = concursos.get(i).getCodigo() + "";
            infoConcurso[1] = concursos.get(i).getUniversidade()+"";
            infoConcurso[2] = concursos.get(i).getCampus();
            infoConcurso[3] = concursos.get(i).getArea();
            infoConcurso[4] = concursos.get(i).getClasse();
            modelo.addRow(infoConcurso);
        }
    }
}
