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
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;
import org.hibernate.annotations.Generated;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "pessoa")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Pessoa.findAll", query = "SELECT p FROM Pessoa p"),
    @NamedQuery(name = "Pessoa.findByCodigo", query = "SELECT p FROM Pessoa p WHERE p.codigo = :codigo"),
    @NamedQuery(name = "Pessoa.findByNome", query = "SELECT p FROM Pessoa p WHERE p.nome = :nome"),
    @NamedQuery(name = "Pessoa.findBySexo", query = "SELECT p FROM Pessoa p WHERE p.sexo = :sexo")})
public class Pessoa implements Serializable {
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "pessoa")
    private Collection<Examinador> examinadorCollection;

    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer codigo;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "pessoa")
    private Collection<Candidato> candidatoCollection;
    private static final long serialVersionUID = 1L;
    @Column(name = "nome")
    private String nome;
    @Column(name = "sexo")
    private Boolean sexo;
    @OneToOne(cascade = CascadeType.ALL, mappedBy = "pessoa")
    private Examinador examinador;
    @OneToOne(cascade = CascadeType.ALL, mappedBy = "pessoa")
    private Candidato candidato;

    public Pessoa() {
    }

    public Pessoa(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Boolean getSexo() {
        return sexo;
    }

    public void setSexo(Boolean sexo) {
        this.sexo = sexo;
    }

    public Examinador getExaminador() {
        return examinador;
    }

    public void setExaminador(Examinador examinador) {
        this.examinador = examinador;
    }

    public Candidato getCandidato() {
        return candidato;
    }

    public void setCandidato(Candidato candidato) {
        this.candidato = candidato;
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
        if (!(object instanceof Pessoa)) {
            return false;
        }
        Pessoa other = (Pessoa) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Pessoa[ codigo=" + codigo + " ]";
    }

    @XmlTransient
    public Collection<Candidato> getCandidatoCollection() {
        return candidatoCollection;
    }

    public void setCandidatoCollection(Collection<Candidato> candidatoCollection) {
        this.candidatoCollection = candidatoCollection;
    }

    @XmlTransient
    public Collection<Examinador> getExaminadorCollection() {
        return examinadorCollection;
    }

    public void setExaminadorCollection(Collection<Examinador> examinadorCollection) {
        this.examinadorCollection = examinadorCollection;
    }

}
