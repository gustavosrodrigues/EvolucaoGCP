package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.PesoProvasConcursoDao;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Pesoprovas;
import br.edu.unipampa.gerenciadorconcurso.validator.Tabela;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 * Peso Provas Concurso Service
 *
 * @version v 1.0 13/01/2015
 * @author Alex Becker
 *
 */
public class PesoProvasConcursoService {

    private final PesoProvasConcursoDao pesoProvasConcursoDaoDao;

    public PesoProvasConcursoService() {
        pesoProvasConcursoDaoDao = new PesoProvasConcursoDao();
    }

//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Pesoprovas pesoprovas) {
        return pesoProvasConcursoDaoDao.salvar(pesoprovas);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Pesoprovas> buscar() {
        return pesoProvasConcursoDaoDao.buscar();
    }

    public Pesoprovas buscar(int codigo) {
        return pesoProvasConcursoDaoDao.buscar(codigo);
    }

    public Pesoprovas buscarPesoProvasConcurso(Concurso concurso) {
        return pesoProvasConcursoDaoDao.buscarPesoProvasConcurso(concurso);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return pesoProvasConcursoDaoDao.deletar(codigo);
    }
//</editor-fold>

    public static void listaCandidatos(ArrayList<Pesoprovas> pesoprovas, DefaultTableModel modelo) {
        Tabela.limparTabela(modelo);
        String pesos[] = new String[4];
        for (int i = 0; i < pesoprovas.size(); i++) {
            pesos[0] = pesoprovas.get(i).getCodigo() + "";
            pesos[1] = pesoprovas.get(i).getPesoProvaTitulo() + "";
            pesos[2] = pesoprovas.get(i).getPesoProvaDidatica() + "";
            pesos[3] = pesoprovas.get(i).getPesoProvaEscrita() + "";
            pesos[4] = pesoprovas.get(i).getPesoProvaMemorial() + "";

            modelo.addRow(pesos);
        }
    }

    public boolean totalPesosCorreto(Pesoprovas pesoprovas) {
        boolean retorno = false;
        System.out.println("T: " + pesoprovas.totalPesos());
        if (pesoprovas.totalPesos() == 10.0) {
            retorno = true;
        }
        return retorno;
    }
}
