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
import javax.persistence.ManyToMany;
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
@Table(name = "memorial")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Memorial.findAll", query = "SELECT m FROM Memorial m"),
    @NamedQuery(name = "Memorial.findByCodigo", query = "SELECT m FROM Memorial m WHERE m.codigo = :codigo"),
    @NamedQuery(name = "Memorial.findByLocalMemorial", query = "SELECT m FROM Memorial m WHERE m.localMemorial = :localMemorial")})
public class Memorial implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "localMemorial")
    private String localMemorial;
    @ManyToMany(mappedBy = "memorialCollection")
    private Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "memorial")
    private Collection<Candidato> candidatoCollection;

    public Memorial() {
    }

    public Memorial(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getLocalMemorial() {
        return localMemorial;
    }

    public void setLocalMemorial(String localMemorial) {
        this.localMemorial = localMemorial;
    }

    @XmlTransient
    public Collection<Configuracaoavaliacaoprova> getConfiguracaoavaliacaoprovaCollection() {
        return configuracaoavaliacaoprovaCollection;
    }

    public void setConfiguracaoavaliacaoprovaCollection(Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection) {
        this.configuracaoavaliacaoprovaCollection = configuracaoavaliacaoprovaCollection;
    }

    @XmlTransient
    public Collection<Candidato> getCandidatoCollection() {
        return candidatoCollection;
    }

    public void setCandidatoCollection(Collection<Candidato> candidatoCollection) {
        this.candidatoCollection = candidatoCollection;
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
        if (!(object instanceof Memorial)) {
            return false;
        }
        Memorial other = (Memorial) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Memorial[ codigo=" + codigo + " ]";
    }
    
}
