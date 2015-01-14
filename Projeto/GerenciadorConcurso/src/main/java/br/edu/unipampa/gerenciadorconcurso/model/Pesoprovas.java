package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
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
import javax.xml.bind.annotation.XmlRootElement;

/**
 * Pesoprovas
 *
 * @version v 1.0 13/01/2015
 * @author Alex Becker
 *
 */
@Entity
@Table(name = "pesoprovas")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Pesoprovas.findAll", query = "SELECT p FROM Pesoprovas p"),
    @NamedQuery(name = "Pesoprovas.findByCodigo", query = "SELECT p FROM Pesoprovas p WHERE p.codigo = :codigo"),
    @NamedQuery(name = "Pesoprovas.findByPesoProvaEscrita", query = "SELECT p FROM Pesoprovas p WHERE p.pesoProvaEscrita = :pesoProvaEscrita"),
    @NamedQuery(name = "Pesoprovas.findByPesoProvaDidatica", query = "SELECT p FROM Pesoprovas p WHERE p.pesoProvaDidatica = :pesoProvaDidatica"),
    @NamedQuery(name = "Pesoprovas.findByPesoProvaMemorial", query = "SELECT p FROM Pesoprovas p WHERE p.pesoProvaMemorial = :pesoProvaMemorial"),
    @NamedQuery(name = "Pesoprovas.findByPesoProvaTitulo", query = "SELECT p FROM Pesoprovas p WHERE p.pesoProvaTitulo = :pesoProvaTitulo")})
public class Pesoprovas implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;

    @Basic(optional = false)
    @Column(name = "pesoProvaEscrita")
    private float pesoProvaEscrita;

    @Basic(optional = false)
    @Column(name = "pesoProvaDidatica")
    private float pesoProvaDidatica;

    @Basic(optional = false)
    @Column(name = "pesoProvaMemorial")
    private float pesoProvaMemorial;

    @Basic(optional = false)
    @Column(name = "pesoProvaTitulo")
    private float pesoProvaTitulo;

    @JoinColumn(name = "concurso", referencedColumnName = "codigo")
    @ManyToOne(optional = false)
    private Concurso concurso;

    public Pesoprovas() {
    }

    public Pesoprovas(Integer codigo) {
        this.codigo = codigo;
    }

    public Pesoprovas(Integer codigo, float pesoProvaEscrita, float pesoProvaDidatica, float pesoProvaMemorial, float pesoProvaTitulo) {
        this.codigo = codigo;
        this.pesoProvaEscrita = pesoProvaEscrita;
        this.pesoProvaDidatica = pesoProvaDidatica;
        this.pesoProvaMemorial = pesoProvaMemorial;
        this.pesoProvaTitulo = pesoProvaTitulo;
    }

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public float getPesoProvaEscrita() {
        return pesoProvaEscrita;
    }

    public void setPesoProvaEscrita(float pesoProvaEscrita) {
        this.pesoProvaEscrita = pesoProvaEscrita;
    }

    public float getPesoProvaDidatica() {
        return pesoProvaDidatica;
    }

    public void setPesoProvaDidatica(float pesoProvaDidatica) {
        this.pesoProvaDidatica = pesoProvaDidatica;
    }

    public float getPesoProvaMemorial() {
        return pesoProvaMemorial;
    }

    public void setPesoProvaMemorial(float pesoProvaMemorial) {
        this.pesoProvaMemorial = pesoProvaMemorial;
    }

    public float getPesoProvaTitulo() {
        return pesoProvaTitulo;
    }

    public void setPesoProvaTitulo(float pesoProvaTitulo) {
        this.pesoProvaTitulo = pesoProvaTitulo;
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
        if (!(object instanceof Pesoprovas)) {
            return false;
        }
        Pesoprovas other = (Pesoprovas) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.model.Pesoprovas[ codigo=" + codigo + " ]";
    }

    public float totalPesos() {
        return this.pesoProvaEscrita + this.pesoProvaDidatica + this.pesoProvaMemorial + this.pesoProvaTitulo;
    }

}
