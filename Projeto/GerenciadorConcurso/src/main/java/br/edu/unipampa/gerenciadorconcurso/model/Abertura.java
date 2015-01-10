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
@Table(name = "abertura")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Abertura.findAll", query = "SELECT a FROM Abertura a"),
    @NamedQuery(name = "Abertura.findByCodigo", query = "SELECT a FROM Abertura a WHERE a.codigo = :codigo"),
    @NamedQuery(name = "Abertura.findByEmissorPortaria", query = "SELECT a FROM Abertura a WHERE a.emissorPortaria = :emissorPortaria"),
    @NamedQuery(name = "Abertura.findByPortaria", query = "SELECT a FROM Abertura a WHERE a.portaria = :portaria"),
    @NamedQuery(name = "Abertura.findByLocal", query = "SELECT a FROM Abertura a WHERE a.local = :local"),
    @NamedQuery(name = "Abertura.findByHoraInicio", query = "SELECT a FROM Abertura a WHERE a.horaInicio = :horaInicio"),
    @NamedQuery(name = "Abertura.findByHoraAberturaConcurso", query = "SELECT a FROM Abertura a WHERE a.horaAberturaConcurso = :horaAberturaConcurso")})
public class Abertura implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "emissorPortaria")
    private String emissorPortaria;
    @Column(name = "portaria")
    private String portaria;
    @Column(name = "local")
    private String local;
    @Column(name = "horaInicio")
    private String horaInicio;
    @Column(name = "horaAberturaConcurso")
    private String horaAberturaConcurso;
    @JoinColumn(name = "concurso", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Concurso concurso;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "abertura")
    private Collection<Registrocronograma> registrocronogramaCollection;

    public Abertura() {
    }

    public Abertura(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getEmissorPortaria() {
        return emissorPortaria;
    }

    public void setEmissorPortaria(String emissorPortaria) {
        this.emissorPortaria = emissorPortaria;
    }

    public String getPortaria() {
        return portaria;
    }

    public void setPortaria(String portaria) {
        this.portaria = portaria;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public String getHoraInicio() {
        return horaInicio;
    }

    public void setHoraInicio(String horaInicio) {
        this.horaInicio = horaInicio;
    }

    public String getHoraAberturaConcurso() {
        return horaAberturaConcurso;
    }

    public void setHoraAberturaConcurso(String horaAberturaConcurso) {
        this.horaAberturaConcurso = horaAberturaConcurso;
    }

    public Concurso getConcurso() {
        return concurso;
    }

    public void setConcurso(Concurso concurso) {
        this.concurso = concurso;
    }

    @XmlTransient
    public Collection<Registrocronograma> getRegistrocronogramaCollection() {
        return registrocronogramaCollection;
    }

    public void setRegistrocronogramaCollection(Collection<Registrocronograma> registrocronogramaCollection) {
        this.registrocronogramaCollection = registrocronogramaCollection;
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
        if (!(object instanceof Abertura)) {
            return false;
        }
        Abertura other = (Abertura) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Abertura[ codigo=" + codigo + " ]";
    }
    
}
