/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import javax.persistence.Basic;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "examinador")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Examinador.findAll", query = "SELECT e FROM Examinador e"),
    @NamedQuery(name = "Examinador.findByCodigo", query = "SELECT e FROM Examinador e WHERE e.codigo = :codigo"),
    @NamedQuery(name = "Examinador.findByCategoria", query = "SELECT e FROM Examinador e WHERE e.categoria = :categoria")})
public class Examinador implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Basic(optional = false)
    @Column(name = "codigo")
    private int codigo;
    @Basic(optional = false)
    @Column(name = "categoria")
    private String categoria;
    @JoinColumn(name = "pessoa", referencedColumnName = "codigo", insertable = true, updatable = true)
    @ManyToOne(optional = false, cascade = CascadeType.ALL)
    private Pessoa pessoa;
    @JoinColumn(name = "concurso", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Concurso concurso;

    public Examinador() {
    }

    public Examinador(Integer codigo) {
        this.codigo = codigo;
    }

    public Examinador(Integer codigo, String categoria) {
        this.codigo = codigo;
        this.categoria = categoria;
    }
    
    /*
     * 8.4 Criar Parecer Final da Banca Examinadora
     */
    public void criarPareceFinal(String parecerFinal){
        String parecer = parecerFinal;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Pessoa getPessoa() {
        return pessoa;
    }

    public void setPessoa(Pessoa pessoa) {
        this.pessoa = pessoa;
    }

    public Concurso getConcurso() {
        return concurso;
    }

    public void setConcurso(Concurso concurso) {
        this.concurso = concurso;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.model.Examinador[ codigo=" + codigo + " ]";
    }
    
}
