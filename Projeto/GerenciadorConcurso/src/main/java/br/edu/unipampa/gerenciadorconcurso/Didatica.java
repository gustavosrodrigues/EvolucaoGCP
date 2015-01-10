/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso;

import java.io.Serializable;
import java.util.Collection;
import java.util.Date;
import javax.persistence.Basic;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
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
@Table(name = "didatica")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Didatica.findAll", query = "SELECT d FROM Didatica d"),
    @NamedQuery(name = "Didatica.findByCodigo", query = "SELECT d FROM Didatica d WHERE d.codigo = :codigo"),
    @NamedQuery(name = "Didatica.findByLocalSorteio", query = "SELECT d FROM Didatica d WHERE d.localSorteio = :localSorteio"),
    @NamedQuery(name = "Didatica.findByLocalProva", query = "SELECT d FROM Didatica d WHERE d.localProva = :localProva"),
    @NamedQuery(name = "Didatica.findByLocalResultado", query = "SELECT d FROM Didatica d WHERE d.localResultado = :localResultado"),
    @NamedQuery(name = "Didatica.findByHoraResultado", query = "SELECT d FROM Didatica d WHERE d.horaResultado = :horaResultado"),
    @NamedQuery(name = "Didatica.findByDataRealizacao", query = "SELECT d FROM Didatica d WHERE d.dataRealizacao = :dataRealizacao")})
public class Didatica implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "localSorteio")
    private String localSorteio;
    @Column(name = "localProva")
    private String localProva;
    @Column(name = "localResultado")
    private String localResultado;
    @Column(name = "horaResultado")
    @Temporal(TemporalType.TIME)
    private Date horaResultado;
    @Column(name = "dataRealizacao")
    @Temporal(TemporalType.DATE)
    private Date dataRealizacao;
    @ManyToMany(mappedBy = "didaticaCollection")
    private Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection;
    @JoinColumn(name = "tema", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Tema tema;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "provaDidatica")
    private Collection<Candidato> candidatoCollection;

    public Didatica() {
    }

    public Didatica(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getLocalSorteio() {
        return localSorteio;
    }

    public void setLocalSorteio(String localSorteio) {
        this.localSorteio = localSorteio;
    }

    public String getLocalProva() {
        return localProva;
    }

    public void setLocalProva(String localProva) {
        this.localProva = localProva;
    }

    public String getLocalResultado() {
        return localResultado;
    }

    public void setLocalResultado(String localResultado) {
        this.localResultado = localResultado;
    }

    public Date getHoraResultado() {
        return horaResultado;
    }

    public void setHoraResultado(Date horaResultado) {
        this.horaResultado = horaResultado;
    }

    public Date getDataRealizacao() {
        return dataRealizacao;
    }

    public void setDataRealizacao(Date dataRealizacao) {
        this.dataRealizacao = dataRealizacao;
    }

    @XmlTransient
    public Collection<Configuracaoavaliacaoprova> getConfiguracaoavaliacaoprovaCollection() {
        return configuracaoavaliacaoprovaCollection;
    }

    public void setConfiguracaoavaliacaoprovaCollection(Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection) {
        this.configuracaoavaliacaoprovaCollection = configuracaoavaliacaoprovaCollection;
    }

    public Tema getTema() {
        return tema;
    }

    public void setTema(Tema tema) {
        this.tema = tema;
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
        if (!(object instanceof Didatica)) {
            return false;
        }
        Didatica other = (Didatica) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Didatica[ codigo=" + codigo + " ]";
    }
    
}
