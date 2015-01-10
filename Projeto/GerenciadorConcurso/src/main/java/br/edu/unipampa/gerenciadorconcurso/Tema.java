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
@Table(name = "tema")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Tema.findAll", query = "SELECT t FROM Tema t"),
    @NamedQuery(name = "Tema.findByCodigo", query = "SELECT t FROM Tema t WHERE t.codigo = :codigo"),
    @NamedQuery(name = "Tema.findByDescricao", query = "SELECT t FROM Tema t WHERE t.descricao = :descricao"),
    @NamedQuery(name = "Tema.findByDataSorteio", query = "SELECT t FROM Tema t WHERE t.dataSorteio = :dataSorteio"),
    @NamedQuery(name = "Tema.findByHoraSorteio", query = "SELECT t FROM Tema t WHERE t.horaSorteio = :horaSorteio")})
public class Tema implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "descricao")
    private String descricao;
    @Column(name = "dataSorteio")
    @Temporal(TemporalType.DATE)
    private Date dataSorteio;
    @Column(name = "horaSorteio")
    @Temporal(TemporalType.TIME)
    private Date horaSorteio;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "tema")
    private Collection<Didatica> didaticaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "tema")
    private Collection<Escrita> escritaCollection;
    @JoinColumn(name = "concurso", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Concurso concurso;

    public Tema() {
    }

    public Tema(Integer codigo) {
        this.codigo = codigo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public Date getDataSorteio() {
        return dataSorteio;
    }

    public void setDataSorteio(Date dataSorteio) {
        this.dataSorteio = dataSorteio;
    }

    public Date getHoraSorteio() {
        return horaSorteio;
    }

    public void setHoraSorteio(Date horaSorteio) {
        this.horaSorteio = horaSorteio;
    }

    @XmlTransient
    public Collection<Didatica> getDidaticaCollection() {
        return didaticaCollection;
    }

    public void setDidaticaCollection(Collection<Didatica> didaticaCollection) {
        this.didaticaCollection = didaticaCollection;
    }

    @XmlTransient
    public Collection<Escrita> getEscritaCollection() {
        return escritaCollection;
    }

    public void setEscritaCollection(Collection<Escrita> escritaCollection) {
        this.escritaCollection = escritaCollection;
    }

    public Concurso getConcurso() {
        return concurso;
    }

    public void setConcurso(Concurso concurso) {
        this.concurso = concurso;
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
        if (!(object instanceof Tema)) {
            return false;
        }
        Tema other = (Tema) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Tema[ codigo=" + codigo + " ]";
    }
    
}
