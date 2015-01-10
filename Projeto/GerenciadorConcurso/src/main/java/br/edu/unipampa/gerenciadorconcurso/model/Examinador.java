/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Collection;
import javax.persistence.Basic;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "examinador")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Examinador.findAll", query = "SELECT e FROM Examinador e"),
    @NamedQuery(name = "Examinador.findByCategoria", query = "SELECT e FROM Examinador e WHERE e.categoria = :categoria"),
    @NamedQuery(name = "Examinador.findByPessoa", query = "SELECT e FROM Examinador e WHERE e.pessoa = :pessoa")})
public class Examinador implements Serializable {
    private static final long serialVersionUID = 1L;
    @Column(name = "categoria")
    private String categoria;
    @Id
    @Basic(optional = false)
    @Column(name = "pessoa")
    private Integer pessoa;
    @JoinColumn(name = "pessoa", referencedColumnName = "codigo", insertable = false, updatable = false)
    @OneToOne(optional = false)
    private Pessoa pessoa1;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "examinadorChefe")
    private Collection<Banca> bancaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "examinador1")
    private Collection<Banca> bancaCollection1;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "examinador2")
    private Collection<Banca> bancaCollection2;

    public Examinador() {
    }

    public Examinador(Integer pessoa) {
        this.pessoa = pessoa;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Integer getPessoa() {
        return pessoa;
    }

    public void setPessoa(Integer pessoa) {
        this.pessoa = pessoa;
    }

    public Pessoa getPessoa1() {
        return pessoa1;
    }

    public void setPessoa1(Pessoa pessoa1) {
        this.pessoa1 = pessoa1;
    }

    @XmlTransient
    public Collection<Banca> getBancaCollection() {
        return bancaCollection;
    }

    public void setBancaCollection(Collection<Banca> bancaCollection) {
        this.bancaCollection = bancaCollection;
    }

    @XmlTransient
    public Collection<Banca> getBancaCollection1() {
        return bancaCollection1;
    }

    public void setBancaCollection1(Collection<Banca> bancaCollection1) {
        this.bancaCollection1 = bancaCollection1;
    }

    @XmlTransient
    public Collection<Banca> getBancaCollection2() {
        return bancaCollection2;
    }

    public void setBancaCollection2(Collection<Banca> bancaCollection2) {
        this.bancaCollection2 = bancaCollection2;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (pessoa != null ? pessoa.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Examinador)) {
            return false;
        }
        Examinador other = (Examinador) object;
        if ((this.pessoa == null && other.pessoa != null) || (this.pessoa != null && !this.pessoa.equals(other.pessoa))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Examinador[ pessoa=" + pessoa + " ]";
    }
    
}
