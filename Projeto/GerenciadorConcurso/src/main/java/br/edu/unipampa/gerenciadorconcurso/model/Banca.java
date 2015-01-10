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
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "banca")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Banca.findAll", query = "SELECT b FROM Banca b"),
    @NamedQuery(name = "Banca.findByCodigo", query = "SELECT b FROM Banca b WHERE b.codigo = :codigo")})
public class Banca implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "banca")
    private Collection<Concurso> concursoCollection;
    @JoinColumn(name = "examinadorChefe", referencedColumnName = "pessoa")
    @ManyToOne(optional = false)
    private Examinador examinadorChefe;
    @JoinColumn(name = "examinador1", referencedColumnName = "pessoa")
    @ManyToOne(optional = false)
    private Examinador examinador1;
    @JoinColumn(name = "examinador2", referencedColumnName = "pessoa")
    @ManyToOne(optional = false)
    private Examinador examinador2;

    public Banca() {
    }

    public Banca(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    @XmlTransient
    public Collection<Concurso> getConcursoCollection() {
        return concursoCollection;
    }

    public void setConcursoCollection(Collection<Concurso> concursoCollection) {
        this.concursoCollection = concursoCollection;
    }

    public Examinador getExaminadorChefe() {
        return examinadorChefe;
    }

    public void setExaminadorChefe(Examinador examinadorChefe) {
        this.examinadorChefe = examinadorChefe;
    }

    public Examinador getExaminador1() {
        return examinador1;
    }

    public void setExaminador1(Examinador examinador1) {
        this.examinador1 = examinador1;
    }

    public Examinador getExaminador2() {
        return examinador2;
    }

    public void setExaminador2(Examinador examinador2) {
        this.examinador2 = examinador2;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (codigo != null ? codigo.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Banca)) {
            return false;
        }
        Banca other = (Banca) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Banca[ codigo=" + codigo + " ]";
    }
    
}
