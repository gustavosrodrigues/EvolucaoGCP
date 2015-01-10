/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Collection;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "configuracaoavaliacaoprova")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Configuracaoavaliacaoprova.findAll", query = "SELECT c FROM Configuracaoavaliacaoprova c"),
    @NamedQuery(name = "Configuracaoavaliacaoprova.findByCodigo", query = "SELECT c FROM Configuracaoavaliacaoprova c WHERE c.codigo = :codigo"),
    @NamedQuery(name = "Configuracaoavaliacaoprova.findByCriterio", query = "SELECT c FROM Configuracaoavaliacaoprova c WHERE c.criterio = :criterio"),
    @NamedQuery(name = "Configuracaoavaliacaoprova.findByPeso", query = "SELECT c FROM Configuracaoavaliacaoprova c WHERE c.peso = :peso")})
public class Configuracaoavaliacaoprova implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "criterio")
    private String criterio;
    // @Max(value=?)  @Min(value=?)//if you know range of your decimal fields consider using these annotations to enforce field validation
    @Column(name = "peso")
    private Float peso;
    @JoinTable(name = "configuracaoavaliacaoprovadidatica", joinColumns = {
        @JoinColumn(name = "condiguracaoAvaliacaoProva", referencedColumnName = "codigo")}, inverseJoinColumns = {
        @JoinColumn(name = "provaDidatica", referencedColumnName = "codigo")})
    @ManyToMany
    private Collection<Didatica> didaticaCollection;
    @JoinTable(name = "configuracaoavaliacaoprovatitulo", joinColumns = {
        @JoinColumn(name = "configuracaoAvaliacaoProva", referencedColumnName = "codigo")}, inverseJoinColumns = {
        @JoinColumn(name = "titulo", referencedColumnName = "codigo")})
    @ManyToMany
    private Collection<Titulo> tituloCollection;
    @JoinTable(name = "configuracaoavaliacaoprovaescrita", joinColumns = {
        @JoinColumn(name = "configuracaoAvaliacaoProva", referencedColumnName = "codigo")}, inverseJoinColumns = {
        @JoinColumn(name = "provaEscrita", referencedColumnName = "codigo")})
    @ManyToMany
    private Collection<Escrita> escritaCollection;
    @JoinTable(name = "configuracaoavaliacaoprovamemorial", joinColumns = {
        @JoinColumn(name = "configuracaoAvaliacaoProva", referencedColumnName = "codigo")}, inverseJoinColumns = {
        @JoinColumn(name = "provaMemorial", referencedColumnName = "codigo")})
    @ManyToMany
    private Collection<Memorial> memorialCollection;

    public Configuracaoavaliacaoprova() {
    }

    public Configuracaoavaliacaoprova(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getCriterio() {
        return criterio;
    }

    public void setCriterio(String criterio) {
        this.criterio = criterio;
    }

    public Float getPeso() {
        return peso;
    }

    public void setPeso(Float peso) {
        this.peso = peso;
    }

    @XmlTransient
    public Collection<Didatica> getDidaticaCollection() {
        return didaticaCollection;
    }

    public void setDidaticaCollection(Collection<Didatica> didaticaCollection) {
        this.didaticaCollection = didaticaCollection;
    }

    @XmlTransient
    public Collection<Titulo> getTituloCollection() {
        return tituloCollection;
    }

    public void setTituloCollection(Collection<Titulo> tituloCollection) {
        this.tituloCollection = tituloCollection;
    }

    @XmlTransient
    public Collection<Escrita> getEscritaCollection() {
        return escritaCollection;
    }

    public void setEscritaCollection(Collection<Escrita> escritaCollection) {
        this.escritaCollection = escritaCollection;
    }

    @XmlTransient
    public Collection<Memorial> getMemorialCollection() {
        return memorialCollection;
    }

    public void setMemorialCollection(Collection<Memorial> memorialCollection) {
        this.memorialCollection = memorialCollection;
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
        if (!(object instanceof Configuracaoavaliacaoprova)) {
            return false;
        }
        Configuracaoavaliacaoprova other = (Configuracaoavaliacaoprova) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Configuracaoavaliacaoprova[ codigo=" + codigo + " ]";
    }
    
}
