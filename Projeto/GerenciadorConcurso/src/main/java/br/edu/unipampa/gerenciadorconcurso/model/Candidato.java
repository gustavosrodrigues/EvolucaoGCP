/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "candidato")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Candidato.findAll", query = "SELECT c FROM Candidato c"),
    @NamedQuery(name = "Candidato.findByDataNacimento", query = "SELECT c FROM Candidato c WHERE c.dataNacimento = :dataNacimento"),
    @NamedQuery(name = "Candidato.findByPessoa", query = "SELECT c FROM Candidato c WHERE c.pessoa = :pessoa"),
    @NamedQuery(name = "Candidato.findByAprovado", query = "SELECT c FROM Candidato c WHERE c.aprovado = :aprovado"),
    @NamedQuery(name = "Candidato.findByCompareceuDidatica", query = "SELECT c FROM Candidato c WHERE c.compareceuDidatica = :compareceuDidatica")})
public class Candidato implements Serializable {
    private static final long serialVersionUID = 1L;
    @Column(name = "dataNacimento")
    @Temporal(TemporalType.DATE)
    private Date dataNacimento;
    @Id
    @Basic(optional = false)
    @Column(name = "pessoa")
    private Integer pessoa;
    @Column(name = "aprovado")
    private Boolean aprovado;
    @Column(name = "compareceuDidatica")
    private Boolean compareceuDidatica;
    @JoinColumn(name = "concurso", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Concurso concurso;
    @JoinColumn(name = "provaDidatica", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Didatica provaDidatica;
    @JoinColumn(name = "provaEscrita", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Escrita provaEscrita;
    @JoinColumn(name = "memorial", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Memorial memorial;
    @JoinColumn(name = "pessoa", referencedColumnName = "codigo", insertable = false, updatable = false)
    @OneToOne(optional = false)
    private Pessoa pessoa1;
    @JoinColumn(name = "titulo", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Titulo titulo;

    public Candidato() {
    }

    public Candidato(Integer pessoa) {
        this.pessoa = pessoa;
    }

    public Date getDataNacimento() {
        return dataNacimento;
    }

    public void setDataNacimento(Date dataNacimento) {
        this.dataNacimento = dataNacimento;
    }

    public Integer getPessoa() {
        return pessoa;
    }

    public void setPessoa(Integer pessoa) {
        this.pessoa = pessoa;
    }

    public Boolean getAprovado() {
        return aprovado;
    }

    public void setAprovado(Boolean aprovado) {
        this.aprovado = aprovado;
    }

    public Boolean getCompareceuDidatica() {
        return compareceuDidatica;
    }

    public void setCompareceuDidatica(Boolean compareceuDidatica) {
        this.compareceuDidatica = compareceuDidatica;
    }

    public Concurso getConcurso() {
        return concurso;
    }

    public void setConcurso(Concurso concurso) {
        this.concurso = concurso;
    }

    public Didatica getProvaDidatica() {
        return provaDidatica;
    }

    public void setProvaDidatica(Didatica provaDidatica) {
        this.provaDidatica = provaDidatica;
    }

    public Escrita getProvaEscrita() {
        return provaEscrita;
    }

    public void setProvaEscrita(Escrita provaEscrita) {
        this.provaEscrita = provaEscrita;
    }

    public Memorial getMemorial() {
        return memorial;
    }

    public void setMemorial(Memorial memorial) {
        this.memorial = memorial;
    }

    public Pessoa getPessoa1() {
        return pessoa1;
    }

    public void setPessoa1(Pessoa pessoa1) {
        this.pessoa1 = pessoa1;
    }

    public Titulo getTitulo() {
        return titulo;
    }

    public void setTitulo(Titulo titulo) {
        this.titulo = titulo;
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
        if (!(object instanceof Candidato)) {
            return false;
        }
        Candidato other = (Candidato) object;
        if ((this.pessoa == null && other.pessoa != null) || (this.pessoa != null && !this.pessoa.equals(other.pessoa))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Candidato[ pessoa=" + pessoa + " ]";
    }
    
}
