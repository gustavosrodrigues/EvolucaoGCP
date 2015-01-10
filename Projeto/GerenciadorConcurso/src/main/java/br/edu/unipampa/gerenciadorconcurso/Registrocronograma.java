/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "registrocronograma")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Registrocronograma.findAll", query = "SELECT r FROM Registrocronograma r"),
    @NamedQuery(name = "Registrocronograma.findByCodigo", query = "SELECT r FROM Registrocronograma r WHERE r.codigo = :codigo"),
    @NamedQuery(name = "Registrocronograma.findByAtividade", query = "SELECT r FROM Registrocronograma r WHERE r.atividade = :atividade"),
    @NamedQuery(name = "Registrocronograma.findByData", query = "SELECT r FROM Registrocronograma r WHERE r.data = :data"),
    @NamedQuery(name = "Registrocronograma.findByHorario", query = "SELECT r FROM Registrocronograma r WHERE r.horario = :horario"),
    @NamedQuery(name = "Registrocronograma.findByLocal", query = "SELECT r FROM Registrocronograma r WHERE r.local = :local")})
public class Registrocronograma implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Basic(optional = false)
    @Column(name = "atividade")
    private String atividade;
    @Basic(optional = false)
    @Column(name = "data")
    @Temporal(TemporalType.DATE)
    private Date data;
    @Basic(optional = false)
    @Column(name = "horario")
    @Temporal(TemporalType.TIME)
    private Date horario;
    @Column(name = "local")
    private String local;
    @JoinColumn(name = "abertura", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Abertura abertura;

    public Registrocronograma() {
    }

    public Registrocronograma(Integer codigo) {
        this.codigo = codigo;
    }

    public Registrocronograma(Integer codigo, String atividade, Date data, Date horario) {
        this.codigo = codigo;
        this.atividade = atividade;
        this.data = data;
        this.horario = horario;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getAtividade() {
        return atividade;
    }

    public void setAtividade(String atividade) {
        this.atividade = atividade;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public Date getHorario() {
        return horario;
    }

    public void setHorario(Date horario) {
        this.horario = horario;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public Abertura getAbertura() {
        return abertura;
    }

    public void setAbertura(Abertura abertura) {
        this.abertura = abertura;
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
        if (!(object instanceof Registrocronograma)) {
            return false;
        }
        Registrocronograma other = (Registrocronograma) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Registrocronograma[ codigo=" + codigo + " ]";
    }
    
}
