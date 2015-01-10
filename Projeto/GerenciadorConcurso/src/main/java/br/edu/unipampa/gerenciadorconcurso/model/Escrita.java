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
@Table(name = "escrita")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Escrita.findAll", query = "SELECT e FROM Escrita e"),
    @NamedQuery(name = "Escrita.findByCodigo", query = "SELECT e FROM Escrita e WHERE e.codigo = :codigo"),
    @NamedQuery(name = "Escrita.findByPontoSorteado", query = "SELECT e FROM Escrita e WHERE e.pontoSorteado = :pontoSorteado"),
    @NamedQuery(name = "Escrita.findByHoraSorteio", query = "SELECT e FROM Escrita e WHERE e.horaSorteio = :horaSorteio"),
    @NamedQuery(name = "Escrita.findByHoraInicio", query = "SELECT e FROM Escrita e WHERE e.horaInicio = :horaInicio"),
    @NamedQuery(name = "Escrita.findByHoraFinalizacao", query = "SELECT e FROM Escrita e WHERE e.horaFinalizacao = :horaFinalizacao"),
    @NamedQuery(name = "Escrita.findByLocal", query = "SELECT e FROM Escrita e WHERE e.local = :local"),
    @NamedQuery(name = "Escrita.findByHoraInicioJugamento", query = "SELECT e FROM Escrita e WHERE e.horaInicioJugamento = :horaInicioJugamento"),
    @NamedQuery(name = "Escrita.findByLocalJulgamento", query = "SELECT e FROM Escrita e WHERE e.localJulgamento = :localJulgamento"),
    @NamedQuery(name = "Escrita.findByLocalDivulgacaoResultado", query = "SELECT e FROM Escrita e WHERE e.localDivulgacaoResultado = :localDivulgacaoResultado"),
    @NamedQuery(name = "Escrita.findByHoraInicioResultado", query = "SELECT e FROM Escrita e WHERE e.horaInicioResultado = :horaInicioResultado")})
public class Escrita implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "pontoSorteado")
    private Integer pontoSorteado;
    @Column(name = "horaSorteio")
    @Temporal(TemporalType.TIME)
    private Date horaSorteio;
    @Column(name = "horaInicio")
    @Temporal(TemporalType.TIME)
    private Date horaInicio;
    @Column(name = "horaFinalizacao")
    @Temporal(TemporalType.TIME)
    private Date horaFinalizacao;
    @Column(name = "local")
    private String local;
    @Column(name = "horaInicioJugamento")
    @Temporal(TemporalType.TIME)
    private Date horaInicioJugamento;
    @Column(name = "localJulgamento")
    private String localJulgamento;
    @Column(name = "localDivulgacaoResultado")
    private String localDivulgacaoResultado;
    @Column(name = "horaInicioResultado")
    @Temporal(TemporalType.TIME)
    private Date horaInicioResultado;
    @ManyToMany(mappedBy = "escritaCollection")
    private Collection<Configuracaoavaliacaoprova> configuracaoavaliacaoprovaCollection;
    @JoinColumn(name = "tema", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Tema tema;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "provaEscrita")
    private Collection<Candidato> candidatoCollection;

    public Escrita() {
    }

    public Escrita(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getPontoSorteado() {
        return pontoSorteado;
    }

    public void setPontoSorteado(Integer pontoSorteado) {
        this.pontoSorteado = pontoSorteado;
    }

    public Date getHoraSorteio() {
        return horaSorteio;
    }

    public void setHoraSorteio(Date horaSorteio) {
        this.horaSorteio = horaSorteio;
    }

    public Date getHoraInicio() {
        return horaInicio;
    }

    public void setHoraInicio(Date horaInicio) {
        this.horaInicio = horaInicio;
    }

    public Date getHoraFinalizacao() {
        return horaFinalizacao;
    }

    public void setHoraFinalizacao(Date horaFinalizacao) {
        this.horaFinalizacao = horaFinalizacao;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public Date getHoraInicioJugamento() {
        return horaInicioJugamento;
    }

    public void setHoraInicioJugamento(Date horaInicioJugamento) {
        this.horaInicioJugamento = horaInicioJugamento;
    }

    public String getLocalJulgamento() {
        return localJulgamento;
    }

    public void setLocalJulgamento(String localJulgamento) {
        this.localJulgamento = localJulgamento;
    }

    public String getLocalDivulgacaoResultado() {
        return localDivulgacaoResultado;
    }

    public void setLocalDivulgacaoResultado(String localDivulgacaoResultado) {
        this.localDivulgacaoResultado = localDivulgacaoResultado;
    }

    public Date getHoraInicioResultado() {
        return horaInicioResultado;
    }

    public void setHoraInicioResultado(Date horaInicioResultado) {
        this.horaInicioResultado = horaInicioResultado;
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
        if (!(object instanceof Escrita)) {
            return false;
        }
        Escrita other = (Escrita) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Escrita[ codigo=" + codigo + " ]";
    }
    
}
