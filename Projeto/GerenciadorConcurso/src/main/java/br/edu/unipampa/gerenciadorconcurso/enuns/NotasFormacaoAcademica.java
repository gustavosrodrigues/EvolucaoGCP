/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.enuns;

/**
 *
 * @author Pedro
 */
public enum NotasFormacaoAcademica {

    DOUTORADO_OBJETO_CONCURSO(6),
    DOUTORADO_AREA_AFIM_CONCURSO(5),
    MESTRADO_AREA_CONCURSO(4),
    MESTRADO_AREA_AFIM_CONCURSO(2.5F),
    ESPECIALIZACAO_AREA_CONCURSO(0.50F),
    RESIDENCIA_ESPECIALIDADE_CONCURSO(0.50F),
    CONCLUSAO_CREDITOS_DOUTORADO_AREA_CONCURSO(0.50F),
    POS_DOUTORADO_AREA_CONCURSO(1F),
    POS_DOUTORADO_AREA_AFIM_CONCURSO(1F);
    
    private float nota;
    
    NotasFormacaoAcademica(float nota){
        this.nota = nota;
    }
    
    public float getNota(){
        return this.nota;
    }
    
}