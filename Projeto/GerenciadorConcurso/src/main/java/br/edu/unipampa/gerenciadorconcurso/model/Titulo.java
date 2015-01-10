/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Collection;
import java.util.Date;
import javax.persistence.Basic;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "titulo")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Titulo.findAll", query = "SELECT t FROM Titulo t"),
    @NamedQuery(name = "Titulo.findByCodigo", query = "SELECT t FROM Titulo t WHERE t.codigo = :codigo"),
    @NamedQuery(name = "Titulo.findByLocalJulgalmento", query = "SELECT t FROM Titulo t WHERE t.localJulgalmento = :localJulgalmento"),
    @NamedQuery(name = "Titulo.findByHorarioJulgamento", query = "SELECT t FROM Titulo t WHERE t.horarioJulgamento = :horarioJulgamento")})
public class Titulo implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "localJulgalmento")
    private String localJulgalmento;
    @Column(name = "horarioJulgamento")
    @Temporal(TemporalType.TIME)
    private Date horarioJulgamento;
    @ManyToMany(mappedBy = "tituloCollection")
    private Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection;
    @OneToOne(cascade = CascadeType.ALL, mappedBy = "titulo1")
    private Formacaoacademica formacaoacademica;
    @OneToOne(cascade = CascadeType.ALL, mappedBy = "titulo1")
    private Producaoartistica producaoartistica;
    @OneToOne(cascade = CascadeType.ALL, mappedBy = "titulo1")
    private Pesquisaensinoextensao pesquisaensinoextensao;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "titulo")
    private Collection<Candidato> candidatoCollection;

    public Titulo() {
    }

    public Titulo(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getLocalJulgalmento() {
        return localJulgalmento;
    }

    public void setLocalJulgalmento(String localJulgalmento) {
        this.localJulgalmento = localJulgalmento;
    }

    public Date getHorarioJulgamento() {
        return horarioJulgamento;
    }

    public void setHorarioJulgamento(Date horarioJulgamento) {
        this.horarioJulgamento = horarioJulgamento;
    }

    @XmlTransient
    public Collection<Configuracaoavaliacaoprova> getConfiguracaoavaliacaoprovaCollection() {
        return configuracaoavaliacaoprovaCollection;
    }

    public void setConfiguracaoavaliacaoprovaCollection(Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection) {
        this.configuracaoavaliacaoprovaCollection = configuracaoavaliacaoprovaCollection;
    }

    public Formacaoacademica getFormacaoacademica() {
        return formacaoacademica;
    }

    public void setFormacaoacademica(Formacaoacademica formacaoacademica) {
        this.formacaoacademica = formacaoacademica;
    }

    public Producaoartistica getProducaoartistica() {
        return producaoartistica;
    }

    public void setProducaoartistica(Producaoartistica producaoartistica) {
        this.producaoartistica = producaoartistica;
    }

    public Pesquisaensinoextensao getPesquisaensinoextensao() {
        return pesquisaensinoextensao;
    }

    public void setPesquisaensinoextensao(Pesquisaensinoextensao pesquisaensinoextensao) {
        this.pesquisaensinoextensao = pesquisaensinoextensao;
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
        if (!(object instanceof Titulo)) {
            return false;
        }
        Titulo other = (Titulo) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Titulo[ codigo=" + codigo + " ]";
    }
    
}
