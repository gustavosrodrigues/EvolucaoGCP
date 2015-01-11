/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.service;

import br.edu.unipampa.gerenciadorconcurso.dao.CandidatoDao;
import br.edu.unipampa.gerenciadorconcurso.dao.DAO;
import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
import java.util.ArrayList;

/**
 * @author Douglas
 * @since 11/01/2015
 */
public class CandidatoService {
    private CandidatoDao candidatoDao;
    
    public CandidatoService(){
        candidatoDao = new CandidatoDao();
    }
    
//<editor-fold defaultstate="collapsed" desc="Salvar">
    public boolean salvar(Candidato candidato){
        return candidatoDao.salvar(candidato);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Buscar">
    public ArrayList<Candidato> buscar(){
        return candidatoDao.buscar();
    }
    
    public Candidato buscar(int codigo){
        return candidatoDao.buscar(codigo);
    }
//</editor-fold>
    
//<editor-fold defaultstate="collapsed" desc="Deletar">
    public boolean deletar(int codigo){
        return candidatoDao.deletar(codigo);
    }
//</editor-fold>

}
