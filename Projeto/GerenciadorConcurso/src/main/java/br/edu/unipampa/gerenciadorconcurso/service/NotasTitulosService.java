/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.FormacaoAcademicaDao;
import br.edu.unipampa.gerenciadorconcurso.dao.TitulosDao;
import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Formacaoacademica;
import br.edu.unipampa.gerenciadorconcurso.model.Titulo;
import java.util.ArrayList;
import javax.swing.JTextField;

/**
 *
 * @author Pedro
 */
public class NotasTitulosService {
    
    private TitulosDao tituloDao;
    private FormacaoAcademicaDao formacaoAcademicaDao;
    
    public NotasTitulosService(){
        tituloDao = new TitulosDao();
        formacaoAcademicaDao = new FormacaoAcademicaDao();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Titulo titulo) {
        return tituloDao.salvar(titulo);
    }
    
    public boolean salvar(Formacaoacademica formacaoacademica) {
        return formacaoAcademicaDao.salvar(formacaoacademica);
    }
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Buscar">
    /**
     * Busca por todos os conogramas presentes no banco
     * @return Lista de Conogramas encontrados
     */
    public ArrayList<Titulo> buscar() {
        return tituloDao.buscar();
    }
    
    public ArrayList<Titulo> buscar(Candidato candidato){
        return tituloDao.buscar(candidato);
    }
    
    public ArrayList<Formacaoacademica> buscarNotaFormacaoAcademica() {
        return formacaoAcademicaDao.buscar();
    }
    
    public ArrayList<Formacaoacademica> buscarNotaFormacaoAcademica(Candidato candidato){
        return formacaoAcademicaDao.buscar(candidato);
    }
    
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo) {
        return tituloDao.deletar(codigo);
    }
//</editor-fold>
    
    public static float calculaNota(int quantidade, float valorNota){
        return quantidade*valorNota;
    }
}
